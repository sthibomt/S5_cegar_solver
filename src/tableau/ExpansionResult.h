#pragma once

#include <memory>
#include <vector>
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
struct ExpansionResult
{
    bool branching = false;
    std::vector<FormulaPtr> leftBranch;
    std::vector<FormulaPtr> rightBranch;
};