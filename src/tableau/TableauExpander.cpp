#include "TableauExpander.h"
#include "../ast/Formula.h"

//---------------------------------------------------------------------------------
ExpansionResult TableauExpander::Expand(const std::shared_ptr<Formula>& formula)
{
    ExpansionResult result;
    auto binary = std::dynamic_pointer_cast<BinaryFormula>(formula);

    if (!binary)
    {
        return result;
    }

    switch (formula->type)
    {        
        case FormulaType::AND:
        {
            result.branching = false;
            result.leftBranch.push_back(binary->left);
            result.leftBranch.push_back(binary->right);
            break;
        }
        
        case FormulaType::OR:
        {
            result.branching = true;
            result.leftBranch.push_back(binary->left);
            result.rightBranch.push_back(binary->right);
            break;
        }
        
        case FormulaType::IMPLIES:
        {
            result.branching = true;
            auto notLeft = std::make_shared<UnaryFormula>(FormulaType::NOT, binary->left);
            result.leftBranch.push_back(notLeft);
            result.rightBranch.push_back(binary->right);
            break;
        }
        default:
            break;
    }
    return result;
}