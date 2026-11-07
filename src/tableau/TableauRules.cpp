#include "TableauRules.h"
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------                    
FormulaClass TableauRules::Classify(const FormulaPtr& formula)
{
    if (!formula)
        return FormulaClass::UNKNOWN;

    switch (formula->type)
    {
        case FormulaType::ATOM:
            return FormulaClass::LITERAL;

        case FormulaType::NOT:
        {
            auto unary = std::dynamic_pointer_cast<UnaryFormula>(formula);

            if (unary && unary->child && unary->child->type == FormulaType::ATOM)
            {
                return FormulaClass::LITERAL;
            }

            return FormulaClass::UNKNOWN;
        }

        case FormulaType::AND:
            return FormulaClass::ALPHA;

        case FormulaType::OR:
            return FormulaClass::BETA;

        case FormulaType::BOX:
        case FormulaType::DIAMOND:
            return FormulaClass::MODAL;

        case FormulaType::IMPLIES:
            // Implications should have been eliminated by NNF.
            return FormulaClass::UNKNOWN;
    }

    return FormulaClass::UNKNOWN;
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandAlpha(TableauNode& node, const FormulaPtr& formula)
{
    if (!formula)
        return;

    switch (formula->type)
    {
        // A & B
        case FormulaType::AND:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                return;

            node.AddFormula(binary->left);
            node.AddFormula(binary->right);

            break;
        }

        default:
            break;
    }
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandBeta(TableauNode& node, const FormulaPtr& formula, int& nextId)
{
    if (!formula)
        return;

    // Create two new branches.
    auto left = std::make_shared<TableauNode>(nextId++);
    auto right = std::make_shared<TableauNode>(nextId++);

    left->parent = &node;
    right->parent = &node;

    // Copy the existing formulas into both branches.
    left->formulaEntries = node.formulaEntries;
    right->formulaEntries = node.formulaEntries;

    switch (formula->type)
    {
        // A | B
        case FormulaType::OR:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                return;

            // Left branch: A
            left->AddFormula(binary->left);

            // Right branch: B
            right->AddFormula(binary->right);

            break;
        }

        default:
            return;
    }

    // Attach the new branches to the current node.
    node.children.push_back(left);
    node.children.push_back(right);
}