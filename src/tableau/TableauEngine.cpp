#include "TableauEngine.h"
#include "BranchUtils.h"
#include "TableauRules.h"

TableauStatus TableauEngine::ExpandBranch(TableauNode& node, int& nextId)
{
    while (true)
    {
        // A contradictory branch is closed.
        if (BranchUtils::IsClosed(node))
        {
            node.closed = true;
            return TableauStatus::CLOSED;
        }

        // Find the next formula that needs expansion.
        FormulaEntry* entry = node.NextUnexpandedFormula();

        // No remaining formulas means this branch is open
        // and fully expanded under the supported rules.
        if (entry == nullptr)
            return TableauStatus::OPEN;

        FormulaPtr formula = entry->formula;

        FormulaClass classification = TableauRules::Classify(formula);

        // These rules are not implemented yet.
        if (classification == FormulaClass::MODAL || classification == FormulaClass::UNKNOWN)
        {
            return TableauStatus::INCOMPLETE;
        }

        // Mark before expansion so child nodes inherit the
        // correct expanded state when formulas are copied.
        entry->expanded = true;

        switch (classification)
        {
            case FormulaClass::LITERAL:                
                break;

            case FormulaClass::ALPHA:
                TableauRules::ExpandAlpha(node, formula);
                break;

            case FormulaClass::BETA:
            {
                TableauRules::ExpandBeta(node, formula, nextId);

                // A beta rule must create two child branches.
                if (node.children.size() < 2)
                    return TableauStatus::INCOMPLETE;

                bool allClosed = true;
                bool anyIncomplete = false;

                for (const auto& child : node.children)
                {
                    if (!child)
                    {
                        anyIncomplete = true;
                        allClosed = false;
                        continue;
                    }

                    TableauStatus childStatus =
                        ExpandBranch(*child, nextId);

                    if (childStatus != TableauStatus::CLOSED)
                        allClosed = false;

                    if (childStatus == TableauStatus::INCOMPLETE)
                        anyIncomplete = true;
                }

                if (allClosed)
                    return TableauStatus::CLOSED;

                if (anyIncomplete)
                    return TableauStatus::INCOMPLETE;

                // At least one branch remains open.
                return TableauStatus::OPEN;
            }

            case FormulaClass::MODAL:
            case FormulaClass::UNKNOWN:
                return TableauStatus::INCOMPLETE;
        }
    }
}
