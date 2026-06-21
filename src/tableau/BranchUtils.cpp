#include "BranchUtils.h"
#include <memory>
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
bool BranchUtils::IsClosed(const TableauNode& node)
{
    for (const auto& formula : node.formulas)
    {
        if (formula->type != FormulaType::ATOM)
        {
            continue;
        }

        auto atom = std::dynamic_pointer_cast<AtomFormula>(formula);

        if (ContainsNegation(node, atom->name))
        {
            return true;
        }
    }
    return false;
}

//---------------------------------------------------------------------------------
bool BranchUtils::ContainsNegation(const TableauNode& node, const std::string& atomName)
{
    for (const auto& formula : node.formulas)
    {
        if (formula->type != FormulaType::NOT)
        {
            continue;
        }

        auto notFormula = std::dynamic_pointer_cast<UnaryFormula>(formula);
        if (!notFormula)
        {
            continue;
        }

        auto atom = std::dynamic_pointer_cast<AtomFormula>(notFormula->child);
        if (!atom)
        {
            continue;
        }

        if (atom->name == atomName)
        {
            return true;
        }
    }
    return false;
}