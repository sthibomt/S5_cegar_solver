#include "TableauNode.h"

#include "../logic/FormulaUtils.h"

//------------------------------------------------------------
TableauNode::TableauNode(int nodeId) : id(nodeId)
{
}

//------------------------------------------------------------
void TableauNode::AddFormula(const FormulaPtr& formula)
{
    if (Contains(formula))
        return;

    formulas.push_back({formula, false});
}

//------------------------------------------------------------
bool TableauNode::Contains(const FormulaPtr& formula) const
{
    for (const auto& entry : formulas)
    {
        if (FormulaEquals(entry.formula, formula))
            return true;
    }

    return false;
}

//------------------------------------------------------------
FormulaEntry* TableauNode::NextUnexpandedFormula()
{
    for (auto& entry : formulas)
    {
        if (!entry.expanded)
            return &entry;
    }

    return nullptr;
}

//------------------------------------------------------------
void TableauNode::MarkExpanded(const FormulaPtr& formula)
{
    for (auto& entry : formulas)
    {
        if (FormulaEquals(entry.formula, formula))
        {
            entry.expanded = true;
            return;
        }
    }
}