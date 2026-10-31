#include "ASTPrinter.h"

#include <iostream>
#include <string>

using namespace std;

//---------------------------------------------------------------------------------
static string Indent(int level)
{
    return string(level * 2, ' ');
}

//---------------------------------------------------------------------------------
void PrintFormula(const shared_ptr<Formula>& formula, int indent)
{
    if (!formula)
    {
        cout << Indent(indent) << "null\n";
        return;
    }

    switch (formula->type)
    {
        case FormulaType::ATOM:
        {
            auto atom = dynamic_pointer_cast<AtomFormula>(formula);
            cout << Indent(indent) << "ATOM(" << atom->name << ")\n";
            break;
        }

        case FormulaType::NOT:
        {
            auto unary = dynamic_pointer_cast<UnaryFormula>(formula);
            cout << Indent(indent) << "NOT\n";
            PrintFormula(unary->child, indent + 1);
            break;
        }

        case FormulaType::AND:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            cout << Indent(indent) << "AND\n";
            PrintFormula(binary->left, indent + 1);
            PrintFormula(binary->right, indent + 1);
            break;
        }

        case FormulaType::OR:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            cout << Indent(indent) << "OR\n";
            PrintFormula(binary->left, indent + 1);
            PrintFormula(binary->right, indent + 1);
            break;
        }

        case FormulaType::IMPLIES:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            cout << Indent(indent) << "IMPLIES\n";
            PrintFormula(binary->left, indent + 1);
            PrintFormula(binary->right, indent + 1);
            break;
        }

        case FormulaType::BOX:
        {
            auto modal = dynamic_pointer_cast<ModalFormula>(formula);
            cout << Indent(indent) << "BOX";
            if (modal->agent >= 0)
            {
                cout << "[" << modal->agent << "]";
            }
            cout << "\n";
            PrintFormula(modal->child, indent + 1);
            break;
        }

        case FormulaType::DIAMOND:
        {
            auto modal = dynamic_pointer_cast<ModalFormula>(formula);
            cout << Indent(indent) << "DIAMOND";
            if (modal->agent >= 0)
            {
                cout << "<" << modal->agent << ">";
            }
            cout << "\n";
            PrintFormula(modal->child, indent + 1);
            break;
        }
    }
}