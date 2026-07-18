#include "BranchUtils.h"

#include "../ast/Formula.h"

//------------------------------------------------------------
bool BranchUtils::IsClosed(const TableauNode& node)
{
    for (const auto& entry : node.formulas)
    {
        FormulaPtr formula = entry.formula;
        if (formula->type != FormulaType::ATOM)
            continue;
        auto atom = std::dynamic_pointer_cast<AtomFormula>(formula);
        if (ContainsNegation(node, atom->name))
            return true;
    }

    return false;
}

//------------------------------------------------------------
bool BranchUtils::ContainsNegation(const TableauNode& node, const std::string& atomName)
{
    for (const auto& entry : node.formulas)
    {
        FormulaPtr formula = entry.formula;
        if (formula->type != FormulaType::NOT)
            continue;

        auto notFormula = std::dynamic_pointer_cast<UnaryFormula>(formula);

        if (!notFormula)
            continue;

        if (notFormula->child->type != FormulaType::ATOM)
            continue;

        auto atom = std::dynamic_pointer_cast<AtomFormula>(notFormula->child);

        if (atom && atom->name == atomName)
            return true;
    }

    return false;
}