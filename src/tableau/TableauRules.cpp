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

            if (unary && unary->child &&
                unary->child->type == FormulaType::ATOM)
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
void TableauRules::ExpandAlpha(TableauWorld& world, const FormulaPtr& formula)
{
    if (!formula)
        return;

    switch (formula->type)
    {        
        case FormulaType::AND:
        {
            auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

            if (!binary)
                return;

            world.AddFormula(binary->left);
            world.AddFormula(binary->right);

            break;
        }

        default:
            break;
    }
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandBeta(TableauNode& node, int worldId, const FormulaPtr& formula, int& nextId)
{
    if (!formula || formula->type != FormulaType::OR)
        return;

    auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

    if (!binary || !binary->left || !binary->right)
        return;

    // Find the world in which the beta formula occurs.
    const TableauWorld* sourceWorld = nullptr;

    for (const auto& world : node.worlds)
    {
        if (world.id == worldId)
        {
            sourceWorld = &world;
            break;
        }
    }

    if (!sourceWorld)
        return;

    // Create two new branches.
    auto left = std::make_shared<TableauNode>(nextId++);
    auto right = std::make_shared<TableauNode>(nextId++);

    left->parent = &node;
    right->parent = &node;

    // Copy all existing worlds and their formulas into both branches.
    left->worlds = node.worlds;
    right->worlds = node.worlds;

    // Left branch: A
    left->AddFormula(worldId, binary->left);

    // Right branch: B
    right->AddFormula(worldId, binary->right);

    // Attach the new branches to the current node.
    node.children.push_back(left);
    node.children.push_back(right);
}
