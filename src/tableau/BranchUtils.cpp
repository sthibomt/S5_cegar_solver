#include "BranchUtils.h"

#include "../ast/Formula.h"
#include "../logic/FormulaUtils.h"

//---------------------------------------------------------------------------------
// Check whether a world contains a contradiction.
bool BranchUtils::IsWorldClosed(const TableauWorld& world)
{
    for (const auto& entry : world.formulaEntries)
    {
        FormulaPtr formula = entry.formula;

        if (!formula)
            continue;
        
        if (formula->type != FormulaType::ATOM)// We only need to check positive atomic formulas.
            continue;

        auto atom = std::dynamic_pointer_cast<AtomFormula>(formula);

        if (!atom)
            continue;

        if (ContainsNegation(world, atom->name))
            return true;
    }

    return false;
}

//---------------------------------------------------------------------------------
// Check whether a tableau branch is closed.
bool BranchUtils::IsClosed(const TableauNode& node)
{
    for (const auto& world : node.worlds)
    {
        if (IsWorldClosed(world))
            return true;
    }

    return false;
}

//---------------------------------------------------------------------------------
// Check whether the entire tableau is closed.
bool BranchUtils::IsTableauClosed(const TableauNode& node)
{
    // A leaf branch is closed if it contains a closed world.
    if (node.children.empty())
        return IsClosed(node);

    // Every child branch must be closed.
    for (const auto& child : node.children)
    {
        if (!child || !IsTableauClosed(*child))
            return false;
    }

    return true;
}

//---------------------------------------------------------------------------------
// Check whether a world contains the negation of an atom
bool BranchUtils::ContainsNegation(const TableauWorld& world, const std::string& atomName)
{
    for (const auto& entry : world.formulaEntries)
    {
        FormulaPtr formula = entry.formula;

        if (!formula || formula->type != FormulaType::NOT)
            continue;

        auto notFormula = std::dynamic_pointer_cast<UnaryFormula>(formula);

        if (!notFormula || !notFormula->child)
            continue;

        if (notFormula->child->type != FormulaType::ATOM)
            continue;

        auto atom =
            std::dynamic_pointer_cast<AtomFormula>(notFormula->child);

        if (atom && atom->name == atomName)
            return true;
    }

    return false;
}
