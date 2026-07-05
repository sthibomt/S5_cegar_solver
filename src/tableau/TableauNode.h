#pragma once

#include <memory>
#include <vector>
#include <unordered_set>

#include "../ast/Formula.h"
#include "../logic/FormulaHasher.h"
#include "../logic/FormulaUtils.h"

//---------------------------------------------------------------------------------
class TableauNode
{
public:
    int id;
    bool closed = false;
    TableauNode* parent = nullptr;
    std::vector<std::shared_ptr<TableauNode>> children;
    std::unordered_set<FormulaPtr, FormulaHasher, FormulaEqual> formulas;

    explicit TableauNode(int nodeId);
    void AddFormula(const FormulaPtr& formula);
};