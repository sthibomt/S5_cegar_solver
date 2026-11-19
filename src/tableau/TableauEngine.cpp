#include "TableauEngine.h"

#include "BranchUtils.h"
#include "TableauRules.h"

//---------------------------------------------------------------------------------
TableauStatus TableauEngine::ExpandBranch(TableauNode& node, int& nextId)
{
    while (true)
    {
        // Check whether the branch contains a contradiction.
        if (BranchUtils::IsClosed(node))
        {
            node.closed = true;
            return TableauStatus::CLOSED;
        }

        // Process formulas belonging to each world.
        for (auto& world : node.worlds)
        {            
            FormulaPtr formula = world.GetNextUnexpandedFormula();// Find the next formula that needs expansion.

            if (!formula)
                continue;

            FormulaClass classification = TableauRules::Classify(formula);

            // Modal rules have not been implemented yet.
            if (classification == FormulaClass::MODAL || classification == FormulaClass::UNKNOWN)
            {
                return TableauStatus::INCOMPLETE;
            }

            // Mark the formula before expansion.
            // This ensures child branches inherit its expanded state.
            world.MarkExpanded(formula);

            switch (classification)
            {
                case FormulaClass::LITERAL:
                    break;

                case FormulaClass::ALPHA:
                {
                    // Expand the formula within the current world.
                    TableauRules::ExpandAlpha(world, formula);
                    break;
                }

                case FormulaClass::BETA:
                {
                    // Create two child branches.
                    TableauRules::ExpandBeta(node, world.id, formula, nextId);
                    
                    if (node.children.size() != 2)// A beta rule must create two child branches.
                        return TableauStatus::INCOMPLETE;

                    bool allClosed = true;
                    bool anyIncomplete = false;

                    // Recursively expand both child branches.
                    for (const auto& child : node.children)
                    {
                        if (!child)
                        {
                            anyIncomplete = true;
                            allClosed = false;
                            continue;
                        }

                        TableauStatus childStatus = ExpandBranch(*child, nextId);
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

            // A formula was processed. Restart the search because
            // expansion may have added new formulas to this world.
            break;
        }

        // Check whether any world still has unexpanded formulas.
        bool hasUnexpandedFormula = false;
        for (auto& world : node.worlds)
        {
            if (world.TableauWorld::GetNextUnexpandedFormula())
            {
                hasUnexpandedFormula = true;
                break;
            }
        }

        // All formulas in all worlds have been processed.
        if (!hasUnexpandedFormula)
            return TableauStatus::OPEN;
    }
}
