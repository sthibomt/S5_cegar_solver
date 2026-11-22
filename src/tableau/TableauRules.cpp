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

        case FormulaType::IMPLIES:// Implications should have been eliminated by NNF.            
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
    
    left->AddFormula(worldId, binary->left); // Left branch: A    
    right->AddFormula(worldId, binary->right); // Right branch: B

    // Attach the new branches to the current node.
    node.children.push_back(left);
    node.children.push_back(right);
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandBox(TableauNode& node, const FormulaPtr& formula)
{
    if (!formula || formula->type != FormulaType::BOX)
        return;

    auto modal = std::dynamic_pointer_cast<ModalFormula>(formula);

    if (!modal || !modal->child)
        return;
    
    for (auto& world : node.worlds)// In single-agent S5, every world in this branch is accessible from every other world.
    {
        world.AddFormula(modal->child);
    }
}

//---------------------------------------------------------------------------------
void TableauRules::ExpandDiamond(TableauNode& node, const FormulaPtr& formula, int& nextWorldId)
{
    if (!formula || formula->type != FormulaType::DIAMOND)
        return;

    auto modal = std::dynamic_pointer_cast<ModalFormula>(formula);

    if (!modal || !modal->child)
        return;
    
    for (const auto& world : node.worlds)// S5 is reflexive: check whether an existing world already satisfies the diamond's inner formula.
    {
        if (world.ContainsFormula(modal->child))
            return;
    }
    
    node.AddWorld(nextWorldId);// No existing world satisfies the formula, Create a new accessible witness world.

    TableauWorld* witnessWorld = node.FindWorld(nextWorldId);
    if (witnessWorld == nullptr)
        return;

    witnessWorld->AddFormula(modal->child);
    
    for (const auto& world : node.worlds)// Every existing box formula must also hold in the newly created world.
    {
        for (const auto& entry : world.formulaEntries)
        {
            if (!entry.formula || entry.formula->type != FormulaType::BOX)
            {
                continue;
            }

            auto box = std::dynamic_pointer_cast<ModalFormula>(entry.formula);

            if (box && box->child)
                witnessWorld->AddFormula(box->child);
        }
    }
    ++nextWorldId;
}
