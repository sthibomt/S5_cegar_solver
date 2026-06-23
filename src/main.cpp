#include <iostream>
#include <antlr4-runtime/antlr4-runtime.h>

#include "parser/generated/ModalLexer.h"
#include "parser/generated/ModalParser.h"
#include "ast/ASTBuilder.h"
#include "ast/ASTPrinter.h"

#include "logic/FormulaUtils.h"
#include "logic/FormulaHasher.h"

#include "tableau/BranchUtils.h"
#include "tableau/TableauNode.h"
#include "tableau/FormulaClassifier.h"
#include "tableau/TableauExpander.h"
#include "tableau/ExpansionResult.h"

using namespace antlr4;

//---------------------------------------------------------------------------------
int main(int argc, const char* argv[]) 
{   
    std::string input;
    if (argc > 1)
    {
        input = argv[1];
    }
    else
    {
        input = "!p";
    }    

    ANTLRInputStream stream(input);
    ModalLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    ModalParser parser(&tokens);

    auto tree = parser.formula();

    ASTBuilder builder;

    auto result = builder.visit(tree);
    
    std::cout << "Has value: " << result.has_value() << std::endl;
    std::cout << "Type: " << result.type().name() << std::endl; 

    auto ast = std::any_cast<std::shared_ptr<Formula>>(result);

    // Expand the formula
    auto expander = TableauExpander::Expand(ast);
    std::cout << "Branching: " << expander.branching << std::endl;

    // TableauNode test
    TableauNode node(0);
    node.AddFormula(ast);
    std::cout << "\nTableau Closed: " << BranchUtils::IsClosed(node) << std::endl;

    // Test Formula Utilities/helper functionality
    std::cout << "\nInput Formula: " << FormulaToString(ast) << std::endl;
    std::cout << "Hash: " << FormulaHash(ast) << std::endl;
    std::cout << "Equal to self: " << FormulaEquals(ast, ast) << std::endl;
    std::unordered_set<std::shared_ptr<Formula>, FormulaHasher, FormulaEqual> formulas;
    formulas.insert(ast);
    formulas.insert(ast);
    std::cout << "Set size: " << formulas.size() << std::endl;

    // Print the AST
    std::cout << "\nAST Structure:\n";
    PrintFormula(ast);  

    return 0;
}