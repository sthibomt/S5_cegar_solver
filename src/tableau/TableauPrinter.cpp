#include "TableauPrinter.h"

#include "../logic/FormulaUtils.h"

#include <iostream>
#include <ostream>

//---------------------------------------------------------------------------------
void TableauPrinter::PrintIndent(std::ostream& output, int depth)
{
    for (int i = 0; i < depth; ++i)
        output << "    ";
}

//---------------------------------------------------------------------------------
// Print a tableau node and all its descendants.
void TableauPrinter::PrintNode(const TableauNode& node, int depth)
{
    PrintNode(node, std::cout, depth);
}

//---------------------------------------------------------------------------------
// Stream-based overloads, useful for testing and file output.
void TableauPrinter::PrintNode(const TableauNode& node, std::ostream& output, int depth)
{
    PrintIndent(output, depth);
    output << "Tableau Node " << node.id;

    if (node.closed)
        output << " [CLOSED]";
    else
        output << " [NOT CLOSED]";

    output << '\n';
    
    PrintBranch(node, output); // Print the worlds belonging to this node.    
    for (const auto& child : node.children) // Recursively print child nodes.
    {
        if (child)
        {
            output << '\n';
            PrintNode(*child, output, depth + 1);
        }
    }
}

//---------------------------------------------------------------------------------
// Print the worlds and formulas belonging to one branch.
void TableauPrinter::PrintBranch(const TableauNode& node)
{
    PrintBranch(node, std::cout);
}

//---------------------------------------------------------------------------------
void TableauPrinter::PrintBranch(const TableauNode& node, std::ostream& output)
{
    if (node.worlds.empty())
    {
        output << "    No worlds in this branch.\n";
        return;
    }

    for (const auto& world : node.worlds)
    {
        output << "    World " << world.id << ":\n";
        if (world.formulaEntries.empty())
        {
            output << "        No formulas.\n";
            continue;
        }

        for (const auto& entry : world.formulaEntries)
        {
            output << "        ";

            if (entry.formula)
                output << FormulaToString(entry.formula);
            else
                output << "<null formula>";

            output << (entry.expanded
                ? " [expanded]"
                : " [not expanded]");

            output << '\n';
        }
    }
}
