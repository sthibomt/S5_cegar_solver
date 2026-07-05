#include "ExpansionRules.h"

#include <memory>
using namespace std;

//---------------------------------------------------------------------------------
void ExpansionRules::ExpandAlpha(TableauNode& node)
{
    for (const auto& formula : node.formulas)
    {
        auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);
        // if (!binary)
        // {
            // continue;
        // }

        if (binary->type == FormulaType::AND)
        {
            node.formulas.erase(formula);
            node.AddFormula(binary->left);
            node.AddFormula(binary->right);
            return;
        }
    }
}
//---------------------------------------------------------------------------------
void ExpansionRules::ExpandBeta(TableauNode& node, int& nextId)
{
    for (const auto& formula : node.formulas)
    {
        auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

        if (!binary)
            continue;

        if (binary->type != FormulaType::OR)
            continue;

        auto left = std::make_shared<TableauNode>( nextId++);
        auto right = std::make_shared<TableauNode>(nextId++);

        left->parent = &node;
        right->parent = &node;

        left->formulas = node.formulas;
        right->formulas = node.formulas;

        left->formulas.erase(formula);
        right->formulas.erase(formula);

        left->AddFormula(binary->left);
        right->AddFormula(binary->right);

        node.children.push_back(left);
        node.children.push_back(right);

        return;
    }
}