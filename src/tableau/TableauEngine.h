#pragma once

#include "TableauNode.h"

//---------------------------------------------------------------------------------
class TableauEngine
{
    public:
    static void ExpandBranch(TableauNode& node, int& nextId);

    private:
    static FormulaPtr SelectNextFormula(const TableauNode& node);

};