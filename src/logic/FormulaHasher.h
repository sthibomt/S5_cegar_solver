#pragma once

#include <memory>
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
size_t FormulaHash(const std::shared_ptr<Formula>& formula);

//---------------------------------------------------------------------------------
struct FormulaHasher
{
    size_t operator()(const std::shared_ptr<Formula>& formula) const;
};

//---------------------------------------------------------------------------------
struct FormulaEqual
{
    bool operator()(const std::shared_ptr<Formula>& lhs, const std::shared_ptr<Formula>& rhs) const;
};