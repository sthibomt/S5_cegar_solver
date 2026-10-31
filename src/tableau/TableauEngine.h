#pragma once

#include "TableauNode.h"

//---------------------------------------------------------------------------------
enum class TableauStatus
{
    OPEN, CLOSED, INCOMPLETE 
};

//---------------------------------------------------------------------------------
class TableauEngine
{
    public:       
    static TableauStatus ExpandBranch(TableauNode& node, int& nextId);
};