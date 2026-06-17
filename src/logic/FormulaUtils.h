#pragma once

#include <memory>
#include <string>
#include "../ast/Formula.h"

std::string FormulaToString(const std::shared_ptr<Formula>& formula);
bool FormulaEquals(const std::shared_ptr<Formula>& left, const std::shared_ptr<Formula>& right);