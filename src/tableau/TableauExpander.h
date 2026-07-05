#pragma once

#include "ExpansionResult.h"

//---------------------------------------------------------------------------------
class TableauExpander
{
public:
    static ExpansionResult Expand(const FormulaPtr& formula);
};