#include <iostream>
#include <antlr4-runtime/antlr4-runtime.h>
#include "parser/generated/ModalLexer.h"
#include "parser/generated/ModalParser.h"
#include "ast/ASTBuilder.h"

using namespace antlr4;

int main() 
{

    std::string input = "p & q";    

    ANTLRInputStream stream(input);
    ModalLexer lexer(&stream);
    CommonTokenStream tokens(&lexer);
    ModalParser parser(&tokens);

    auto tree = parser.formula();

    ASTBuilder builder;

    auto result = builder.visit(tree);

    std::cout << "Has value: " << result.has_value() << std::endl;
    std::cout << "Type: " << result.type().name() << std::endl; 

    auto ast = std::any_cast<std::shared_ptr<Formula>>(builder.visit(tree));

    std::cout << "Parsing successful!" << input << std::endl;

    return 0;
}