#include <gtest/gtest.h>

#include "ast/Formula.h"
#include "logic/FormulaNormalizer.h"

//---------------------------------------------------------------------------------
class NNFConverterTest : public ::testing::Test
{
protected:
    FormulaPtr MakeAtom(const std::string& name)
    {
        return std::make_shared<AtomFormula>(name);
    }
};

//---------------------------------------------------------------------------------
TEST_F(NNFConverterTest, AtomRemainsUnchanged)
{
    FormulaPtr formula = MakeAtom("p");
    FormulaPtr result = FormulaNormalizer::Convert(formula);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->type, FormulaType::ATOM);
}

//---------------------------------------------------------------------------------
TEST_F(NNFConverterTest, DoubleNegationIsEliminated)
{
    FormulaPtr atom = MakeAtom("p");

    FormulaPtr formula = std::make_shared<UnaryFormula>(FormulaType::NOT, std::make_shared<UnaryFormula>(FormulaType::NOT, atom ));

    FormulaPtr result = FormulaNormalizer::Convert(formula);

    ASSERT_NE(result, nullptr);
    EXPECT_EQ(result->type, FormulaType::ATOM);
}