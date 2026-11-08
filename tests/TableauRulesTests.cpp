#include <gtest/gtest.h>

#include "../src/ast/Formula.h"
#include "../src/tableau/TableauNode.h"
#include "../src/tableau/TableauRules.h"
#include "../src/logic/FormulaUtils.h"

//---------------------------------------------------------------------------------
static FormulaPtr MakeAtom(const std::string& name)
{
    return std::make_shared<AtomFormula>(name);
}

//---------------------------------------------------------------------------------
static FormulaPtr MakeNot(const FormulaPtr& formula)
{
    return std::make_shared<UnaryFormula>(FormulaType::NOT, formula);
}

//---------------------------------------------------------------------------------
static FormulaPtr MakeAnd(const FormulaPtr& left, const FormulaPtr& right)
{
    return std::make_shared<BinaryFormula>(FormulaType::AND, left, right);
}

//---------------------------------------------------------------------------------
static FormulaPtr MakeOr(const FormulaPtr& left, const FormulaPtr& right)
{
    return std::make_shared<BinaryFormula>(FormulaType::OR, left, right );
}

//---------------------------------------------------------------------------------
static bool ContainsFormula(const TableauNode& node, const FormulaPtr& formula)
{
    for (const auto& entry : node.formulaEntries)
    {
        if (FormulaEquals(entry.formula, formula))
            return true;
    }

    return false;
}

//---------------------------------------------------------------------------------
// Formula classification tests
//---------------------------------------------------------------------------------
TEST(TableauRulesTests, AtomIsClassifiedAsLiteral)
{
    FormulaPtr p = MakeAtom("p");
    EXPECT_EQ(TableauRules::Classify(p), FormulaClass::LITERAL);
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, NegatedAtomIsClassifiedAsLiteral)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr notP = MakeNot(p);

    EXPECT_EQ(TableauRules::Classify(notP), FormulaClass::LITERAL);
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, ConjunctionIsClassifiedAsAlpha)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr formula = MakeAnd(p, q);
    EXPECT_EQ( TableauRules::Classify(formula), FormulaClass::ALPHA);
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, DisjunctionIsClassifiedAsBeta)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");

    FormulaPtr formula = MakeOr(p, q);
    EXPECT_EQ(TableauRules::Classify(formula), FormulaClass::BETA );
}

//---------------------------------------------------------------------------------
// Alpha expansion tests
//---------------------------------------------------------------------------------
TEST(TableauRulesTests, AlphaExpansionAddsBothConjunctsToSameBranch)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr conjunction = MakeAnd(p, q);
    TableauNode node(0);

    node.AddFormula(conjunction);

    TableauRules::ExpandAlpha(node, conjunction);

    EXPECT_TRUE(ContainsFormula(node, p));
    EXPECT_TRUE(ContainsFormula(node, q));

    // Alpha expansion must not create additional branches.
    EXPECT_TRUE(node.children.empty());
}

//---------------------------------------------------------------------------------
// Beta expansion tests
//---------------------------------------------------------------------------------
TEST(TableauRulesTests, BetaExpansionCreatesTwoBranches)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr disjunction = MakeOr(p, q);

    TableauNode node(0);

    node.AddFormula(disjunction);

    int nextId = 1;

    TableauRules::ExpandBeta(node, disjunction, nextId);

    ASSERT_EQ(node.children.size(), 2);

    EXPECT_TRUE(node.children[0] != nullptr);
    EXPECT_TRUE(node.children[1] != nullptr);
}
