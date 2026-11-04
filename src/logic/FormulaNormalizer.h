#pragma once

#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
class FormulaNormalizer
{
public:
    static FormulaPtr Convert(const FormulaPtr& formula);

private:
    static FormulaPtr ConvertToNNF(const FormulaPtr& formula, bool negate);
};