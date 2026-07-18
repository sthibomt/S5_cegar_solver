#pragma once

#include <memory>
#include <vector>
#include "../ast/Formula.h"

//------------------------------------------------------------
struct FormulaEntry
{
    FormulaPtr formula;
    bool expanded = false;
};

//------------------------------------------------------------
class TableauNode;

using NodePtr = std::shared_ptr<TableauNode>;

//------------------------------------------------------------
class TableauNode
{
public:
    int id;
    bool closed = false;
    TableauNode* parent = nullptr;
    std::vector<NodePtr> children;
    std::vector<FormulaEntry> formulas;

    explicit TableauNode(int nodeId);
    void AddFormula(const FormulaPtr& formula);
    FormulaEntry* NextUnexpandedFormula();
    void MarkExpanded(const FormulaPtr& formula);
    bool Contains(const FormulaPtr& formula) const;
};