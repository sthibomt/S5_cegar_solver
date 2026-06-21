#include "TableauNode.h"

//---------------------------------------------------------------------------------
TableauNode::TableauNode(int nodeId) : id(nodeId)
{
}

//---------------------------------------------------------------------------------
void TableauNode::AddFormula(const std::shared_ptr<Formula>& formula)
{
    formulas.insert(formula);
}