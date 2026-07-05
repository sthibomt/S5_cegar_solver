#pragma once

#include "../ast/Formula.h"

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
class FormulaClassifier
{
public:
    static FormulaClass Classify(const FormulaPtr& formula);
};