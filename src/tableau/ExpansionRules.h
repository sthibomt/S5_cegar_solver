#pragma once

#include <vector>
#include "TableauNode.h"

//---------------------------------------------------------------------------------
class ExpansionRules
{
public:
    static void ExpandAlpha(TableauNode& node);
    static void ExpandBeta(TableauNode& node, int& nextId);
};