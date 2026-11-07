#pragma once

#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
static constexpr std::size_t GOLDEN_RATIO = 0x9e3779b9;
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