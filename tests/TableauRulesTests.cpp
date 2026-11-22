#include <gtest/gtest.h>

#include "../src/ast/Formula.h"
#include "../src/tableau/TableauNode.h"
#include "../src/tableau/TableauWorld.h"
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
    return std::make_shared<BinaryFormula>(FormulaType::OR, left, right);
}

//---------------------------------------------------------------------------------
static bool ContainsFormula(const TableauWorld& world, const FormulaPtr& formula)
{
    for (const auto& entry : world.formulaEntries)
    {
        if (FormulaEquals(entry.formula, formula))
            return true;
    }

    return false;
}

//---------------------------------------------------------------------------------
// Formula classification tests
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

    EXPECT_EQ(TableauRules::Classify(formula), FormulaClass::ALPHA);
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, DisjunctionIsClassifiedAsBeta)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr formula = MakeOr(p, q);

    EXPECT_EQ(TableauRules::Classify(formula), FormulaClass::BETA);
}

//---------------------------------------------------------------------------------
// Alpha expansion tests
TEST(TableauRulesTests, AlphaExpansionAddsBothConjunctsToSameWorld)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr conjunction = MakeAnd(p, q);

    TableauWorld world(0);
    world.AddFormula(conjunction);

    TableauRules::ExpandAlpha(world, conjunction);

    EXPECT_TRUE(ContainsFormula(world, p));
    EXPECT_TRUE(ContainsFormula(world, q));
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, AlphaExpansionDoesNotCreateBranches)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr conjunction = MakeAnd(p, q);

    TableauNode node(0);
    node.AddWorld(0);
    node.AddFormula(0, conjunction);

    TableauWorld* world = node.FindWorld(0);
    ASSERT_NE(world, nullptr);

    TableauRules::ExpandAlpha(*world, conjunction);

    EXPECT_TRUE(node.children.empty());
}

//---------------------------------------------------------------------------------
// Beta expansion tests
TEST(TableauRulesTests, BetaExpansionCreatesTwoBranches)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr disjunction = MakeOr(p, q);

    TableauNode node(0);
    node.AddWorld(0);
    node.AddFormula(0, disjunction);

    int nextId = 1;

    TableauRules::ExpandBeta(node, 0, disjunction, nextId);

    ASSERT_EQ(node.children.size(), 2);

    EXPECT_NE(node.children[0], nullptr);
    EXPECT_NE(node.children[1], nullptr);
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, BetaExpansionAddsLeftDisjunctToFirstBranch)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr disjunction = MakeOr(p, q);

    TableauNode node(0);
    node.AddWorld(0);
    node.AddFormula(0, disjunction);

    int nextId = 1;

    TableauRules::ExpandBeta(node, 0, disjunction, nextId);

    ASSERT_EQ(node.children.size(), 2);

    TableauWorld* leftWorld = node.children[0]->FindWorld(0);

    ASSERT_NE(leftWorld, nullptr);
    EXPECT_TRUE(ContainsFormula(*leftWorld, p));
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, BetaExpansionAddsRightDisjunctToSecondBranch)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr disjunction = MakeOr(p, q);

    TableauNode node(0);
    node.AddWorld(0);
    node.AddFormula(0, disjunction);

    int nextId = 1;

    TableauRules::ExpandBeta(node, 0, disjunction, nextId);

    ASSERT_EQ(node.children.size(), 2);

    TableauWorld* rightWorld = node.children[1]->FindWorld(0);

    ASSERT_NE(rightWorld, nullptr);
    EXPECT_TRUE(ContainsFormula(*rightWorld, q));
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, BetaExpansionPreservesExistingWorldFormulas)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr r = MakeAtom("r");
    FormulaPtr disjunction = MakeOr(p, q);

    TableauNode node(0);
    node.AddWorld(0);
    node.AddFormula(0, r);
    node.AddFormula(0, disjunction);

    int nextId = 1;

    TableauRules::ExpandBeta(node, 0, disjunction, nextId);

    ASSERT_EQ(node.children.size(), 2);

    TableauWorld* leftWorld = node.children[0]->FindWorld(0);
    TableauWorld* rightWorld = node.children[1]->FindWorld(0);

    ASSERT_NE(leftWorld, nullptr);
    ASSERT_NE(rightWorld, nullptr);

    EXPECT_TRUE(ContainsFormula(*leftWorld, r));
    EXPECT_TRUE(ContainsFormula(*rightWorld, r));
}

//---------------------------------------------------------------------------------
TEST(TableauRulesTests, BetaExpansionAssignsParentAndChildIds)
{
    FormulaPtr p = MakeAtom("p");
    FormulaPtr q = MakeAtom("q");
    FormulaPtr disjunction = MakeOr(p, q);

    TableauNode node(0);
    node.AddWorld(0);
    node.AddFormula(0, disjunction);

    int nextId = 1;

    TableauRules::ExpandBeta(node, 0, disjunction, nextId);

    ASSERT_EQ(node.children.size(), 2);

    EXPECT_EQ(node.children[0]->id, 1);
    EXPECT_EQ(node.children[1]->id, 2);

    EXPECT_EQ(node.children[0]->parent, &node);
    EXPECT_EQ(node.children[1]->parent, &node);

    EXPECT_EQ(nextId, 3);
}
