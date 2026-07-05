#include "FormulaClassifier.h"

//---------------------------------------------------------------------------------
FormulaClass FormulaClassifier::Classify(const FormulaPtr& formula)
{
    switch (formula->type)
    {
        case FormulaType::ATOM:
            return FormulaClass::LITERAL;

        case FormulaType::NOT:
            return FormulaClass::LITERAL;

        case FormulaType::AND:
            return FormulaClass::ALPHA;

        case FormulaType::OR:
        case FormulaType::IMPLIES:
            return FormulaClass::BETA;

        case FormulaType::BOX:
        case FormulaType::DIAMOND:
            return FormulaClass::MODAL;

        default:
            return FormulaClass::UNKNOWN;
    }
}