#pragma once

#include "../ast/Formula.h"

#include <vector>

//---------------------------------------------------------------------------------
struct FormulaEntry
{
    FormulaPtr formula;
    bool expanded = false;
};

//---------------------------------------------------------------------------------
class TableauWorld
{
public:    
    int id;    
    std::vector<FormulaEntry> formulaEntries;

    explicit TableauWorld(int worldId);    
    
    void AddFormula(const FormulaPtr& formula);   
    bool ContainsFormula(const FormulaPtr& formula) const;// Check whether this world contains a formula.    
    FormulaPtr GetNextUnexpandedFormula();// Find the next formula that has not been expanded.    
    void MarkExpanded(const FormulaPtr& formula);// Mark a formula as expanded.
};
