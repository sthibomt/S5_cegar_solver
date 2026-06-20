#include "FormulaHasher.h"
#include "FormulaUtils.h"
#include <functional>

using namespace std;

//---------------------------------------------------------------------------------
static void HashCombine(size_t& seed, size_t value)
{
    seed ^= value
            + 0x9e3779b9
            + (seed << 6)
            + (seed >> 2);
}

//---------------------------------------------------------------------------------
size_t FormulaHash(const shared_ptr<Formula>& formula)
{
    if (!formula)
        return 0;

    size_t seed = hash<int>{}(static_cast<int>(formula->type));

    switch (formula->type)
    {
        case FormulaType::ATOM:
        {
            auto atom = dynamic_pointer_cast<AtomFormula>(formula);
            HashCombine(seed, hash<string>{}(atom->name));
            break;
        }

        case FormulaType::NOT:
        {
            auto unary = dynamic_pointer_cast<UnaryFormula>(formula);
            HashCombine(seed, FormulaHash(unary->child));
            break;
        }

        case FormulaType::AND:
        case FormulaType::OR:
        case FormulaType::IMPLIES:
        {
            auto binary = dynamic_pointer_cast<BinaryFormula>(formula);
            HashCombine(seed, FormulaHash(binary->left));
            HashCombine(seed, FormulaHash(binary->right));
            break;
        }

        case FormulaType::BOX:
        case FormulaType::DIAMOND:
        {
            auto modal = dynamic_pointer_cast<ModalFormula>(formula);
            HashCombine(seed, hash<int>{}(modal->agent));
            HashCombine(seed, FormulaHash(modal->child));
            break;
        }
    }

    return seed;
}

//---------------------------------------------------------------------------------
size_t FormulaHasher::operator()(const shared_ptr<Formula>& formula) const
{
    return FormulaHash(formula);
}

//---------------------------------------------------------------------------------
bool FormulaEqual::operator()(const shared_ptr<Formula>& lhs, const shared_ptr<Formula>& rhs) const
{
    return FormulaEquals(lhs, rhs);
}