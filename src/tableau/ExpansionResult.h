#pragma once

#include <memory>
#include <vector>
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
struct ExpansionResult
{
    bool branching = false;
    std::vector<std::shared_ptr<Formula>> leftBranch;
    std::vector<std::shared_ptr<Formula>> rightBranch;
};