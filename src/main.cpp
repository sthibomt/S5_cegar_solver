#include <iostream>

#include <antlr4-runtime/antlr4-runtime.h>

#include "parser/generated/ModalLexer.h"
#include "parser/generated/ModalParser.h"

#include "ast/ASTBuilder.h"
#include "ast/ASTPrinter.h"

#include "logic/FormulaUtils.h"
#include "logic/FormulaHasher.h"
#include "logic/FormulaNormalizer.h"

#include "tableau/TableauNode.h"
#include "tableau/TableauRules.h"
#include "tableau/TableauEngine.h"
#include "tableau/TableauPrinter.h"
#include "tableau/BranchUtils.h"

using namespace antlr4;

//------------------------------------------------------------
int main(int argc, const char* argv[])
{
    std::string input;

    if (argc > 1)
        input = argv[1];
    else
        input = "[]q";
    
    // Parse    
    ANTLRInputStream stream(input);
    ModalLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    ModalParser parser(&tokens);

    auto tree = parser.formula();

    ASTBuilder builder;

    auto result = builder.visit(tree);

    std::cout << "Has value : " << result.has_value() << '\n';
    std::cout << "Type      : " << result.type().name() << "\n\n";

    FormulaPtr ast = std::any_cast<FormulaPtr>(result);

    // Convert the original formula to NNF.
    FormulaPtr nnf = FormulaNormalizer::Convert(ast);
    
    // Formula utilities    
    std::cout << "Original Formula : "<< FormulaToString(ast) << '\n';
    std::cout << "NNF Formula      : "<< FormulaToString(nnf) << "\n\n";
    std::cout << "Hash          : " << FormulaHash(ast) << '\n';
    std::cout << "Equal to self : " << FormulaEquals(ast, ast) << "\n\n";
    
    // AST    
    std::cout << "AST\n";
    std::cout << "---------------------------\n";
    PrintFormula(ast);
    
    // Tableau
    TableauNode root(0);
    root.AddFormula(nnf);
    int nextId = 1;
    TableauStatus status = TableauEngine::ExpandBranch(root, nextId);

    std::cout << "\nTableau\n";
    std::cout << "---------------------------\n";
    PrintBranch(root);
    
    // Branch status        
     switch (status)
      {
        case TableauStatus::CLOSED:
            std::cout << "Tableau CLOSED (UNSATISFIABLE)";
            break;

        case TableauStatus::OPEN:
            std::cout << "Tableau OPEN (SATISFIABLE)";
            break;

        case TableauStatus::INCOMPLETE:
            std::cout << "Tableau INCOMPLETE (RESULT UNKNOWN)";
            break;
    }
    std::cout << '\n';
    
    return 0;
}