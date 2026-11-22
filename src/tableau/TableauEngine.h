#pragma once

#include "TableauNode.h"
// #include "TableauRules.h"

//---------------------------------------------------------------------------------
enum class TableauStatus
{
    OPEN, CLOSED, INCOMPLETE 
};

//---------------------------------------------------------------------------------
class TableauEngine
{
    public:       
        static TableauStatus ExpandBranch(TableauNode& node, int& nextNodeId, int& nextWorldId);
};