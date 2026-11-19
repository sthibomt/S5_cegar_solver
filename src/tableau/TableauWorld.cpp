#include "TableauWorld.h"

#include "../logic/FormulaUtils.h"

//---------------------------------------------------------------------------------
TableauWorld::TableauWorld(int worldId) : id(worldId)
{
}

//---------------------------------------------------------------------------------
void TableauWorld::AddFormula(const FormulaPtr& formula)
{
    if (!formula)
        return;
    
    if (ContainsFormula(formula))// Avoid adding duplicate formulas.
        return;
    formulaEntries.push_back({formula, false});
}

//---------------------------------------------------------------------------------
bool TableauWorld::ContainsFormula(const FormulaPtr& formula) const
{
    if (!formula)
        return false;

    for (const auto& entry : formulaEntries)
    {
        if (FormulaEquals(entry.formula, formula))
            return true;
    }

    return false;
}

//---------------------------------------------------------------------------------
FormulaPtr TableauWorld::GetNextUnexpandedFormula()
{
    for (auto& entry : formulaEntries)
    {
        if (!entry.expanded)
            return entry.formula;
    }

    return nullptr;
}

//---------------------------------------------------------------------------------
void TableauWorld::MarkExpanded(const FormulaPtr& formula)
{
    if (!formula)
        return;

    for (auto& entry : formulaEntries)
    {
        if (FormulaEquals(entry.formula, formula))
        {
            entry.expanded = true;
            return;
        }
    }
}
