#include "TableauRules.h"
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
FormulaClass TableauRules::Classify(const FormulaPtr& formula)
{
    switch (formula->type)
    {
        case FormulaType::ATOM:
            return FormulaClass::LITERAL;

        case FormulaType::BOX:
        case FormulaType::DIAMOND:
            return FormulaClass::MODAL;

        case FormulaType::AND:
            return FormulaClass::ALPHA;

        case FormulaType::OR:
        case FormulaType::IMPLIES:
            return FormulaClass::BETA;

        case FormulaType::NOT:
        {
            auto unary = std::dynamic_pointer_cast<UnaryFormula>(formula);

            if (!unary)
                return FormulaClass::UNKNOWN;

            switch (unary->child->type)
            {
                case FormulaType::ATOM:
                    return FormulaClass::LITERAL;

                case FormulaType::AND:
                    return FormulaClass::BETA;

                case FormulaType::OR:
                case FormulaType::IMPLIES:
                case FormulaType::NOT:
                    return FormulaClass::ALPHA;

                default:
                    return FormulaClass::UNKNOWN;
            }
        }

        default:
            return FormulaClass::UNKNOWN;
    }
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandAlpha(TableauNode& node, const FormulaPtr& formula)
{
    switch (formula->type)
    {
        //---------------------------------
        // A & B
        //---------------------------------
        case FormulaType::AND:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                return;

            node.AddFormula(binary->left);
            node.AddFormula(binary->right);
            break;
        }

        //---------------------------------
        // !(...)
        //---------------------------------
        case FormulaType::NOT:
        {
            auto unary = std::dynamic_pointer_cast<UnaryFormula>(formula);

            if (!unary)
                return;

            //---------------------------------
            // !!A
            //---------------------------------
            if (unary->child->type == FormulaType::NOT)
            {
                auto inner = std::dynamic_pointer_cast<UnaryFormula>(unary->child);

                node.AddFormula(inner->child);
                return;
            }

            //---------------------------------
            // !(A | B)
            //---------------------------------
            if (unary->child->type == FormulaType::OR)
            {
                auto binary =
                    std::dynamic_pointer_cast<BinaryFormula>(unary->child);

                node.AddFormula(std::make_shared<UnaryFormula>(FormulaType::NOT, binary->left));

                node.AddFormula(std::make_shared<UnaryFormula>(FormulaType::NOT, binary->right));

                return;
            }

            //---------------------------------
            // !(A -> B)
            //---------------------------------
            if (unary->child->type == FormulaType::IMPLIES)
            {
                auto binary = std::dynamic_pointer_cast<BinaryFormula>(unary->child);
                node.AddFormula(binary->left);
                node.AddFormula(std::make_shared<UnaryFormula>(FormulaType::NOT, binary->right));
                return;
            }

            break;
        }

        default:
            break;
    }
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandBeta(TableauNode& node, const FormulaPtr& formula, int& nextId)
{
    auto left = std::make_shared<TableauNode>(nextId++);
    auto right = std::make_shared<TableauNode>(nextId++);

    left->parent = &node;
    right->parent = &node;

    left->formulas = node.formulas;
    right->formulas = node.formulas;

    switch (formula->type)
    {
        //---------------------------------
        // A | B
        //---------------------------------
        case FormulaType::OR:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);
            if (!binary)
                return;

            left->AddFormula(binary->left);
            right->AddFormula(binary->right);
            break;
        }

        //---------------------------------
        // A -> B
        //---------------------------------
        case FormulaType::IMPLIES:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                return;

            left->AddFormula(std::make_shared<UnaryFormula>(FormulaType::NOT, binary->left));

            right->AddFormula(binary->right);
            break;
        }

        //---------------------------------
        // !(A & B)
        //---------------------------------
        case FormulaType::NOT:
        {
            auto unary = std::dynamic_pointer_cast<UnaryFormula>(formula);

            if (!unary)
                return;

            auto binary = std::dynamic_pointer_cast<BinaryFormula>(unary->child);

            if (!binary)
                return;

            left->AddFormula(std::make_shared<UnaryFormula>(FormulaType::NOT, binary->left));
            right->AddFormula(std::make_shared<UnaryFormula>(FormulaType::NOT, binary->right));
            break;
        }

        default:
            return;
    }

    node.children.push_back(left);
    node.children.push_back(right);
}