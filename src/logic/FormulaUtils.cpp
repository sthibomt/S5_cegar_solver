#include "FormulaUtils.h"

using namespace std;

//---------------------------------------------------------------------------------
string FormulaToString(const shared_ptr<Formula>& formula)
{
    if (!formula)
    {
        return "null";
    }

    switch (formula->type)
    {
        case FormulaType::ATOM:
        {
            auto atom = dynamic_pointer_cast<AtomFormula>(formula);
            return atom->name;
        }

        case FormulaType::NOT:
        {
            auto unary = dynamic_pointer_cast<UnaryFormula>(formula);
            return "!" + FormulaToString(unary->child);
        }

        case FormulaType::AND:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            return "(" + FormulaToString(binary->left) + " & " + FormulaToString(binary->right) + ")";
        }

        case FormulaType::OR:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            return "(" + FormulaToString(binary->left) + " | " + FormulaToString(binary->right) +")";
        }

        case FormulaType::IMPLIES:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            return "(" + FormulaToString(binary->left) + " -> " + FormulaToString(binary->right) + ")";
        }

        case FormulaType::BOX:
        {
            auto modal = dynamic_pointer_cast<ModalFormula>(formula);

            if (modal->agent >= 0)
            {
                return "[" + to_string(modal->agent) + "]" + FormulaToString(modal->child);
            }
            return "[]" + FormulaToString(modal->child);
        }

        case FormulaType::DIAMOND:
        {
            auto modal = dynamic_pointer_cast<ModalFormula>(formula);

            if (modal->agent >= 0)
            {
                return "<" + to_string(modal->agent) + ">" + FormulaToString(modal->child);
            }
            return "<>" + FormulaToString(modal->child);
        }
    }

    return "?";
}

//---------------------------------------------------------------------------------
bool FormulaEquals(const shared_ptr<Formula>& left, const shared_ptr<Formula>& right)
{
    if (!left && !right)
    {
        return true;
    }
    if (!left || !right)
    {
        return false;
    }
    if (left->type != right->type)
    {
        return false;
    }

    switch (left->type)
    {
        case FormulaType::ATOM:
        {
            auto l = dynamic_pointer_cast<AtomFormula>(left);
            auto r = dynamic_pointer_cast<AtomFormula>(right);
            return l->name == r->name;
        }

        case FormulaType::NOT:
        {
            auto l = dynamic_pointer_cast<UnaryFormula>(left);
            auto r = dynamic_pointer_cast<UnaryFormula>(right);
            return FormulaEquals(l->child,r->child);
        }

        case FormulaType::AND:
        case FormulaType::OR:
        case FormulaType::IMPLIES:
        {
            auto l = dynamic_pointer_cast<BinaryFormula>(left);
            auto r = dynamic_pointer_cast<BinaryFormula>(right);
            return FormulaEquals(l->left, r->left) && FormulaEquals(l->right, r->right);
        }

        case FormulaType::BOX:
        case FormulaType::DIAMOND:
        {
            auto l = dynamic_pointer_cast<ModalFormula>(left);
            auto r = dynamic_pointer_cast<ModalFormula>(right);
            return l->agent == r->agent && FormulaEquals(l->child, r->child);
        }
    }

    return false;
}