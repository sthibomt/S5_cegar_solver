#pragma once

#include <memory>
#include "../ast/Formula.h"

void PrintFormula(const std::shared_ptr<Formula>& formula, int indent = 0);