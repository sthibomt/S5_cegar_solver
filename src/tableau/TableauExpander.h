#pragma once

#include "ExpansionResult.h"

//---------------------------------------------------------------------------------
class TableauExpander
{
public:
    static ExpansionResult Expand(const std::shared_ptr<Formula>& formula);
};