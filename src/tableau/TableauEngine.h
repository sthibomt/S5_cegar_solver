#pragma once

#include "TableauNode.h"

//---------------------------------------------------------------------------------
enum class TableauStatus
{
    OPEN,       // A completed open tableau
    CLOSED,     // Every branch is closed
    INCOMPLETE  // Some required expansion is unsupported
};

//---------------------------------------------------------------------------------
class TableauEngine
{
    public:       
    static TableauStatus ExpandBranch(TableauNode& node, int& nextId);
};