#include "TableauEngine.h"
#include "TableauRules.h"
#include "BranchUtils.h"
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
TableauStatus TableauEngine::ExpandBranch(TableauNode& node, int& nextNodeId, int& nextWorldId)
{
    while (true)
    {
        // Check whether the current branch contains a contradiction.
        if (BranchUtils::IsClosed(node))
        {
            node.closed = true;
            return TableauStatus::CLOSED;
        }

        TableauWorld* currentWorld = nullptr;
        FormulaPtr formula = nullptr;

        // Find the next unexpanded formula across all worlds.
        for (auto& world : node.worlds)
        {
            formula = world.GetNextUnexpandedFormula();

            if (formula)
            {
                currentWorld = &world;
                break;
            }
        }
        
        if (formula == nullptr)// No unexpanded formulas remain.
            return TableauStatus::OPEN;

        // Mark the formula before applying its rule.This prevents it from being expanded repeatedly.
        currentWorld->MarkExpanded(formula);

        FormulaClass classification = TableauRules::Classify(formula);

        switch (classification)
        {
            // -------------------------------------------------------------
            case FormulaClass::LITERAL:
            {
                // Nothing further needs to be added.
                // Contradictions are detected at the beginning
                // of the next iteration.
                break;
            }

            // -------------------------------------------------------------
            case FormulaClass::ALPHA:
            {
                TableauRules::ExpandAlpha(*currentWorld, formula);
                break;
            }

            // -------------------------------------------------------------
            case FormulaClass::BETA:
            {                
                TableauRules::ExpandBeta(node, currentWorld->id, formula, nextNodeId);// Split the current branch into two alternatives.
                
                if (node.children.size() < 2)// A successful beta expansion must create two children.
                    return TableauStatus::INCOMPLETE;

                // Expand the left child recursively.
                TableauStatus leftStatus = ExpandBranch(*node.children[node.children.size() - 2], nextNodeId, nextWorldId);

                // Expand the right child recursively.
                TableauStatus rightStatus = ExpandBranch(*node.children[node.children.size() - 1], nextNodeId, nextWorldId);

                // The parent branch closes only when both
                // alternative branches are closed.
                if (leftStatus == TableauStatus::CLOSED && rightStatus == TableauStatus::CLOSED)
                {
                    node.closed = true;
                    return TableauStatus::CLOSED;
                }

                // At least one open child means the tableau
                // has an open alternative.
                if (leftStatus == TableauStatus::OPEN || rightStatus == TableauStatus::OPEN)
                {
                    return TableauStatus::OPEN;
                }

                // Neither child is open, but at least one could not be fully evaluated.
                return TableauStatus::INCOMPLETE;
            }

            // -------------------------------------------------------------
            case FormulaClass::MODAL:
            {
                if (formula->type == FormulaType::BOX)
                {
                    TableauRules::ExpandBox(node, formula);
                }
                else if (formula->type == FormulaType::DIAMOND)
                {
                    TableauRules::ExpandDiamond(node, formula, nextWorldId);
                }
                else
                {
                    return TableauStatus::INCOMPLETE;
                }

                break;
            }

            // -------------------------------------------------------------
            case FormulaClass::UNKNOWN:
            default:
            {
                return TableauStatus::INCOMPLETE;
            }
        }

        // Start another iteration.
        // This is important because alpha and modal expansion
        // may have added formulas or new worlds to the branch.
    }
}
