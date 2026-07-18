#include "TableauPrinter.h"

#include <iostream>

#include "../logic/FormulaUtils.h"

//---------------------------------------------------------------------------------
void PrintNode(const TableauNode& node, int depth)
{
    // Indentation
    std::string indent(depth * 4, ' ');

    std::cout << indent << "Node " << node.id;

    if (node.closed)
    {
        std::cout << " (closed)";
    }

    std::cout << '\n';

    std::cout << indent << "--------------------\n";

    for (const auto& entry : node.formulas)
    {
        std::cout << indent;

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

    for (const auto& child : node.children)
    {
        PrintNode(*child, depth + 1);
    }
}

//---------------------------------------------------------------------------------
void PrintBranch(const TableauNode& node)
{
    PrintNode(node, 0);
}