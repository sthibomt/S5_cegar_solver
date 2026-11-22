#include <gtest/gtest.h>

#include "../src/ast/Formula.h"

#include "../src/tableau/TableauEngine.h"
#include "../src/tableau/TableauNode.h"
#include "../src/tableau/TableauWorld.h"

#include <memory>

//---------------------------------------------------------------------------------
// Helper functions for constructing formulas.

// Create an atomic formula.
static FormulaPtr MakeAtom(const std::string& name)
{
    return std::make_shared<AtomFormula>(name);
}

// Create a negated formula.
static FormulaPtr MakeNot(const FormulaPtr& child)
{
    return std::make_shared<UnaryFormula>(FormulaType::NOT, child);
}

// Create a conjunction.
static FormulaPtr MakeAnd(const FormulaPtr& left, const FormulaPtr& right)
{
    return std::make_shared<BinaryFormula>(FormulaType::AND, left, right);
}

// Create a disjunction.
static FormulaPtr MakeOr(const FormulaPtr& left, const FormulaPtr& right)
{
    return std::make_shared<BinaryFormula>(FormulaType::OR, left, right);
}

// Create a box formula.
static FormulaPtr MakeBox(const FormulaPtr& child)
{
    return std::make_shared<ModalFormula>(FormulaType::BOX, 0, child);
}

// Create a diamond formula.
static FormulaPtr MakeDiamond(const FormulaPtr& child)
{
    return std::make_shared<ModalFormula>(FormulaType::DIAMOND, 0, child );
}

//---------------------------------------------------------------------------------
// Helper function to create and initialise a root tableau node.

static TableauNode CreateRoot(const FormulaPtr& formula)
{
    TableauNode root(0);
    root.AddWorld(0);
    root.AddFormula(0, formula);

    return root;
}

//---------------------------------------------------------------------------------
// Helper function to expand a tableau.

static TableauStatus RunTableau(TableauNode& root)
{
    int nextNodeId = 1;
    int nextWorldId = 1;
    return TableauEngine::ExpandBranch(root, nextNodeId, nextWorldId);
}

//---------------------------------------------------------------------------------
// BASIC TABLEAU TESTS
TEST(TableauEngineTests, AtomicFormulaProducesOpenBranch)
{
    auto formula = MakeAtom("p");
    TableauNode root = CreateRoot(formula);
    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);
    EXPECT_FALSE(root.closed);
}

//---------------------------------------------------------------------------------
TEST(TableauEngineTests, ContradictoryFormulaProducesClosedBranch)
{
    auto p = MakeAtom("p");
    auto notP = MakeNot(p);
    auto formula = MakeAnd(p, notP);

    TableauNode root = CreateRoot(formula);
    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::CLOSED);
    EXPECT_TRUE(root.closed);
}

//---------------------------------------------------------------------------------
// ALPHA RULE TESTS
TEST(TableauEngineTests, ConjunctionExpandsInSameWorld)
{
    auto p = MakeAtom("p");
    auto q = MakeAtom("q");

    auto formula = MakeAnd(p, q);

    TableauNode root = CreateRoot(formula);
    TableauStatus status = RunTableau(root);

    ASSERT_EQ(status, TableauStatus::OPEN);

    const TableauWorld* world = root.FindWorld(0);

    ASSERT_NE(world, nullptr);

    EXPECT_TRUE(world->ContainsFormula(p));
    EXPECT_TRUE(world->ContainsFormula(q));

    // Alpha expansion should not create additional worlds.
    EXPECT_EQ(root.worlds.size(), 1);
}

//---------------------------------------------------------------------------------
// BETA RULE TESTS
TEST(TableauEngineTests, DisjunctionCreatesTwoBranches)
{
    auto p = MakeAtom("p");
    auto q = MakeAtom("q");

    auto formula = MakeOr(p, q);

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);

    ASSERT_EQ(root.children.size(), 2);

    // Left branch receives the left disjunct.
    const TableauWorld* leftWorld = root.children[0]->FindWorld(0);

    ASSERT_NE(leftWorld, nullptr);
    EXPECT_TRUE(leftWorld->ContainsFormula(p));

    // Right branch receives the right disjunct.
    const TableauWorld* rightWorld = root.children[1]->FindWorld(0);

    ASSERT_NE(rightWorld, nullptr);
    EXPECT_TRUE(rightWorld->ContainsFormula(q));
}

//---------------------------------------------------------------------------------
TEST(TableauEngineTests, BothClosedBetaBranchesCloseParent)
{
    auto p = MakeAtom("p");
    auto notP = MakeNot(p);

    // (p AND !p) OR (p AND !p)
    auto left = MakeAnd(p, notP);
    auto right = MakeAnd(p, notP);

    auto formula = MakeOr(left, right);

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::CLOSED);
    EXPECT_TRUE(root.closed);

    ASSERT_EQ(root.children.size(), 2);

    EXPECT_TRUE(root.children[0]->closed);
    EXPECT_TRUE(root.children[1]->closed);
}

//---------------------------------------------------------------------------------
// BOX RULE TESTS
TEST(TableauEngineTests, BoxFormulaExpandsInCurrentWorld)
{
    auto p = MakeAtom("p");

    auto formula = MakeBox(p);

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);

    const TableauWorld* world = root.FindWorld(0);

    ASSERT_NE(world, nullptr);
    EXPECT_TRUE(world->ContainsFormula(p));
}

//---------------------------------------------------------------------------------
TEST(TableauEngineTests, BoxFormulaDetectsContradiction)
{
    auto p = MakeAtom("p");
    auto notP = MakeNot(p);
    
    auto formula = MakeAnd(MakeBox(p), notP); // □p AND !p

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::CLOSED);
    EXPECT_TRUE(root.closed);
}

//---------------------------------------------------------------------------------
// DIAMOND RULE TESTS
TEST(TableauEngineTests, DiamondCreatesWitnessWorld)
{
    auto p = MakeAtom("p");

    auto formula = MakeDiamond(p);

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);

    // The original world and the witness world.
    ASSERT_EQ(root.worlds.size(), 2);

    const TableauWorld* witnessWorld = root.FindWorld(1);

    ASSERT_NE(witnessWorld, nullptr);
    EXPECT_TRUE(witnessWorld->ContainsFormula(p));
}

//---------------------------------------------------------------------------------
TEST(TableauEngineTests, DiamondReusesExistingSatisfyingWorld)
{
    auto p = MakeAtom("p");
    
    auto formula = MakeAnd(p, MakeDiamond(p));// p AND ◇p

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);

    // The original world already satisfies p.
    // No witness world should be necessary.
    EXPECT_EQ(root.worlds.size(), 1);
}

//---------------------------------------------------------------------------------
// S5 MODAL INTERACTION TESTS
TEST(TableauEngineTests, NewDiamondWorldReceivesExistingBoxFormula)
{
    auto p = MakeAtom("p");
    auto q = MakeAtom("q");
    
    auto formula = MakeAnd(MakeBox(p), MakeDiamond(q));// □p AND ◇q

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);

    ASSERT_EQ(root.worlds.size(), 2);

    const TableauWorld* witnessWorld = root.FindWorld(1);

    ASSERT_NE(witnessWorld, nullptr);

    // The witness world must satisfy q.
    EXPECT_TRUE(witnessWorld->ContainsFormula(q));

    // The witness world must also satisfy p because □p holds.
    EXPECT_TRUE(witnessWorld->ContainsFormula(p));
}

//---------------------------------------------------------------------------------
TEST(TableauEngineTests, BoxAndDiamondContradictionClosesBranch)
{
    auto p = MakeAtom("p");
    auto notP = MakeNot(p);
    
    auto formula = MakeAnd(MakeBox(p), MakeDiamond(notP));// □p AND ◇!p

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::CLOSED);
    EXPECT_TRUE(root.closed);

    // A witness world was created for !p.
    ASSERT_EQ(root.worlds.size(), 2);

    const TableauWorld* witnessWorld = root.FindWorld(1);

    ASSERT_NE(witnessWorld, nullptr);

    // The witness receives both p and !p.
    EXPECT_TRUE(witnessWorld->ContainsFormula(p));
    EXPECT_TRUE(witnessWorld->ContainsFormula(notP));
}

//---------------------------------------------------------------------------------
TEST(TableauEngineTests, BoxDiamondInteractionCanReuseExistingWorld)
{
    auto p = MakeAtom("p");

    // □◇p AND p
    auto formula = MakeAnd(
        MakeBox(MakeDiamond(p)),
        p
    );

    TableauNode root = CreateRoot(formula);

    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::OPEN);

    // The existing world satisfies p, so it can witness ◇p.
    EXPECT_EQ(root.worlds.size(), 1);
}

//---------------------------------------------------------------------------------
// INCOMPLETE FORMULA TESTS
TEST(TableauEngineTests, ImplicationReturnsIncomplete)
{
    auto p = MakeAtom("p");
    auto q = MakeAtom("q");

    auto formula = std::make_shared<BinaryFormula>(FormulaType::IMPLIES, p, q);

    TableauNode root = CreateRoot(formula);
    TableauStatus status = RunTableau(root);

    EXPECT_EQ(status, TableauStatus::INCOMPLETE);
}
