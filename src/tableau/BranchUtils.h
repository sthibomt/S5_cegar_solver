#pragma once

#include "TableauNode.h"

#include <string>

//---------------------------------------------------------------------------------

class BranchUtils
{
public:
    static bool IsWorldClosed(const TableauWorld& world);    
    static bool IsClosed(const TableauNode& node); // Checks whether the tableau branch is closed.    
    static bool IsTableauClosed(const TableauNode& node);

private:
    // Checks whether the world contains both an atom and its negation.
    static bool ContainsNegation(const TableauWorld& world, const std::string& atomName);
};
