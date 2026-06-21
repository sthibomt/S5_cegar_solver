#pragma once

#include "TableauNode.h"

//---------------------------------------------------------------------------------
class BranchUtils
{
public:
    static bool IsClosed(const TableauNode& node);

private:
    static bool ContainsNegation(const TableauNode& node, const std::string& atomName);
};