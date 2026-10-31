#pragma once

#include <memory>
#include <string>
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
std::string FormulaToString(const FormulaPtr& formula);
bool FormulaEquals(const FormulaPtr& left, const FormulaPtr& right);