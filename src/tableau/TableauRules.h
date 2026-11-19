#pragma once

#include "TableauNode.h"
#include "TableauWorld.h"

//---------------------------------------------------------------------------------
enum class FormulaClass
{
    LITERAL, ALPHA, BETA, MODAL, UNKNOWN
};

//---------------------------------------------------------------------------------
class TableauRules
{
public:
    static FormulaClass Classify(const FormulaPtr& formula);
    static void ExpandAlpha(TableauWorld& world, const FormulaPtr& formula);
    static void ExpandBeta(TableauNode& node, int worldId, const FormulaPtr& formula, int& nextId);
};