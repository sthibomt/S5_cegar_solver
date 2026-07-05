#pragma once

#include <memory>
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
size_t FormulaHash(const FormulaPtr& formula);

//---------------------------------------------------------------------------------
struct FormulaHasher
{
    size_t operator()(const FormulaPtr& formula) const;
};

//---------------------------------------------------------------------------------
struct FormulaEqual
{
    bool operator()(const FormulaPtr& lhs, const FormulaPtr& rhs) const;
};