#include <iostream>

#include "TableauPrinter.h"
#include "../logic/FormulaUtils.h"

//---------------------------------------------------------------------------------
// Print a tableau node and its worlds.
void PrintNode(const TableauNode& node, int depth)
{    
    std::string indent(depth * 4, ' '); // Indentation
    std::cout << indent << "Node " << node.id;

    if (node.closed)
    {
        std::cout << " (closed)";
    }

    std::cout << '\n';
    std::cout << indent << "---------------------------\n";

    // Print all worlds belonging to this node.
    for (const auto& world : node.worlds)
    {
        std::cout << indent << "  World " << world.id << '\n';

        std::cout << indent << "---------------------------\n";

        // Print formulas belonging to this world.
        for (const auto& entry : world.formulaEntries)
        {
            std::cout << indent << "    ";

            if (entry.expanded)
            {
                std::cout << "[x] ";
            }
            else
            {
                std::cout << "[ ] ";
            }

            std::cout << FormulaToString(entry.formula) << '\n';
        }

        std::cout << '\n';
    }

    // Recursively print child branches.
    for (const auto& child : node.children)
    {
        if (child)
        {
            PrintNode(*child, depth + 1);
        }
    }
}

//---------------------------------------------------------------------------------
// Print the entire tableau.
void PrintBranch(const TableauNode& node)
{
    PrintNode(node, 0);
}
