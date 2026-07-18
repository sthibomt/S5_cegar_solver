#include "TableauEngine.h"

#include "BranchUtils.h"
#include "TableauRules.h"

//---------------------------------------------------------------------------------
void TableauEngine::ExpandBranch(TableauNode& node, int& nextId)
{
    // Stop if branch is already closed.
    if (BranchUtils::IsClosed(node))
    {
        node.closed = true;
        return;
    }

    // Expand formulas until there are no more left.
    while (true)
    {
        FormulaEntry* entry = node.NextUnexpandedFormula();

        if (entry == nullptr)
        {
            // Nothing left to expand.
            return;
        }

        entry->expanded = true;

        FormulaPtr formula = entry->formula;

        switch (TableauRules::Classify(formula))
        {
            //--------------------------------------------------------
            case FormulaClass::LITERAL:
            {
                // Literals require no expansion.
                break;
            }

            //--------------------------------------------------------
            case FormulaClass::ALPHA:
            {
                TableauRules::ExpandAlpha(node, formula);

                // Continue expanding this same branch.
                break;
            }

            //--------------------------------------------------------
            case FormulaClass::BETA:
            {
                TableauRules::ExpandBeta(node, formula, nextId);

                // Expand each child recursively.
                for (auto& child : node.children)
                {
                    ExpandBranch(*child, nextId);
                }

                return;
            }

            //--------------------------------------------------------
            case FormulaClass::MODAL:
            {
                // Modal rules will be added later.
                break;
            }

            //--------------------------------------------------------
            default:
                break;
        }

        // Check whether this branch has become closed.
        if (BranchUtils::IsClosed(node))
        {
            node.closed = true;
            return;
        }
    }
}