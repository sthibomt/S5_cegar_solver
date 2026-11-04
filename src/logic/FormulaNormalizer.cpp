#include "FormulaNormalizer.h"

#include <stdexcept>

//---------------------------------------------------------------------------------
FormulaPtr FormulaNormalizer::Convert(const FormulaPtr& formula)
{
    if (!formula)
        throw std::invalid_argument("Cannot convert a null formula to NNF.");

    return ConvertToNNF(formula, false);
}

//---------------------------------------------------------------------------------
FormulaPtr FormulaNormalizer::ConvertToNNF(const FormulaPtr& formula, bool negate)
{
    if (!formula)
        throw std::invalid_argument("Invalid null child in formula.");

    switch (formula->type)
    {
        case FormulaType::ATOM:
        {
            auto atom = std::dynamic_pointer_cast<AtomFormula>(formula);

            if (!atom)
                throw std::runtime_error("Invalid ATOM formula.");

            FormulaPtr result = std::make_shared<AtomFormula>(atom->name);

            if (negate)
            {
                return std::make_shared<UnaryFormula>(FormulaType::NOT, result);
            }

            return result;
        }

        case FormulaType::NOT:
        {
            auto unary = std::dynamic_pointer_cast<UnaryFormula>(formula);

            if (!unary)
                throw std::runtime_error("Invalid NOT formula.");

            // Negating a negation cancels the two negations.
            return ConvertToNNF(unary->child, !negate);
        }

        case FormulaType::AND:
        case FormulaType::OR:
        {
            auto binary =std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                throw std::runtime_error("Invalid binary formula.");

            FormulaType resultType = formula->type;

            if (negate)
            {
                resultType = (formula->type == FormulaType::AND)? FormulaType::OR: FormulaType::AND;
            }

            FormulaPtr left = ConvertToNNF(binary->left, negate);
            FormulaPtr right = ConvertToNNF(binary->right, negate); 
            return std::make_shared<BinaryFormula>(resultType, left, right);
        }

        case FormulaType::IMPLIES:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                throw std::runtime_error("Invalid IMPLIES formula.");

            if (!negate)
            {
                // A -> B is  !A | B.
                FormulaPtr left = ConvertToNNF(binary->left, true);
                FormulaPtr right = ConvertToNNF(binary->right, false);
                return std::make_shared<BinaryFormula>( FormulaType::OR, left, right);
            }
            else
            {
                // !(A -> B) is  A & !B.
                FormulaPtr left = ConvertToNNF(binary->left, false);
                FormulaPtr right = ConvertToNNF(binary->right, true);
                return std::make_shared<BinaryFormula>(FormulaType::AND, left, right);
            }
        }

        case FormulaType::BOX:
        case FormulaType::DIAMOND:
        {
            auto modal = std::dynamic_pointer_cast<ModalFormula>(formula);
            if (!modal)
                throw std::runtime_error("Invalid modal formula.");

            FormulaType resultType = formula->type;

            if (negate)
            {                
                // ![]A = <>!A and !<>A = []!A
                resultType = (formula->type == FormulaType::BOX)? FormulaType::DIAMOND : FormulaType::BOX;
            }

            FormulaPtr child = ConvertToNNF(modal->child, negate);
            return std::make_shared<ModalFormula>(resultType, modal->agent, child);
        } 
    }

    throw std::runtime_error("Unknown formula type during NNF conversion.");    
}