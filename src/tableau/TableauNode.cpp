#include "TableauNode.h"

//---------------------------------------------------------------------------------
TableauNode::TableauNode(int nodeId) : id(nodeId)
{
}

//---------------------------------------------------------------------------------
void TableauNode::AddFormula(const FormulaPtr& formula)
{
    formulas.insert(formula);
}