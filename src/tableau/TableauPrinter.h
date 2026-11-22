#pragma once

#include "TableauNode.h"

#include <iosfwd>

//---------------------------------------------------------------------------------
class TableauPrinter
{
public:    
    static void PrintNode(const TableauNode& node, int depth = 0);     
    static void PrintBranch(const TableauNode& node);     
    static void PrintNode(const TableauNode& node, std::ostream& output, int depth = 0); 
    static void PrintBranch(const TableauNode& node, std::ostream& output);

private:
    static void PrintIndent(std::ostream& output, int depth);
};
