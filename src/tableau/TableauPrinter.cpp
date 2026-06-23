#include "TableauPrinter.h"
#include <iostream>

using namespace std;

//---------------------------------------------------------------------------------
void PrintBranch(const TableauNode& node)
{
    cout << "Branch:" << endl;
    for (const auto& formula : node.formulas)
    {
        cout << "  " << formula << endl;
    }
    cout << endl;
}