cmake_minimum_required(VERSION 3.16)

project(S5Solver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

FetchContent_Declare(
  antlr4_runtime
  GIT_REPOSITORY https://github.com/antlr/antlr4.git
  GIT_TAG 4.13.2
)

FetchContent_MakeAvailable(antlr4_runtime)

add_executable(s5solver
    src/main.cpp

    src/ast/Formula.cpp
    src/ast/ASTBuilder.cpp
    src/ast/ASTPrinter.cpp
    
    src/logic/FormulaHasher.cpp
    src/logic/FormulaUtils.cpp  

    src/parser/generated/ModalLexer.cpp
    src/parser/generated/ModalParser.cpp
    src/parser/generated/ModalBaseVisitor.cpp
    src/parser/generated/ModalVisitor.cpp

    src/tableau/FormulaClassifier.cpp
    src/tableau/BranchUtils.cpp 
    src/tableau/TableauNode.cpp
    src/tableau/TableauExpander.cpp
    src/tableau/TableauPrinter.cpp
    src/tableau/ExpansionRules.cpp
)

target_include_directories(s5solver PRIVATE 
    /usr/local/include/antlr4-runtime   
    ${CMAKE_SOURCE_DIR}/src
    ${CMAKE_SOURCE_DIR}/src/parser/generated
    ${CMAKE_SOURCE_DIR}/src/ast    
)

target_link_libraries(s5solver antlr4-runtime)
