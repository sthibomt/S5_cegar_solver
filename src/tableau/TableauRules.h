#pragma once

#include <vector>
#include "TableauNode.h"

//---------------------------------------------------------------------------------
enum class FormulaClass
{
    LITERAL,
    ALPHA,
    BETA,
    MODAL,
    UNKNOWN
};

//---------------------------------------------------------------------------------
class TableauRules
{
public:
    static FormulaClass Classify(const FormulaPtr& formula);
    static void ExpandAlpha(TableauNode& node, const FormulaPtr& formula);
    static void ExpandBeta(TableauNode& node,const FormulaPtr& formula, int& nextId);   
    
};