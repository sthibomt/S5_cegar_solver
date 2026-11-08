
include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.17.0.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

# ------------------------------------------------------------
# NNF Converter Tests
# ------------------------------------------------------------

add_executable(NNFConverterTests
    NNFConverterTests.cpp
    ../src/logic/FormulaNormalizer.cpp
)

target_include_directories(NNFConverterTests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(NNFConverterTests PRIVATE
    GTest::gtest_main
)

# ------------------------------------------------------------
# Tableau Rules Tests
# ------------------------------------------------------------

add_executable(TableauRulesTests
    TableauRulesTests.cpp
    ../src/tableau/TableauRules.cpp
    ../src/tableau/TableauNode.cpp
    ../src/logic/FormulaUtils.cpp
    ../src/ast/Formula.cpp
)

target_include_directories(TableauRulesTests PRIVATE
    ${CMAKE_SOURCE_DIR}/src
)

target_link_libraries(TableauRulesTests PRIVATE
    GTest::gtest_main
)

# ------------------------------------------------------------
# Add the next test below
# ------------------------------------------------------------

include(GoogleTest)

gtest_discover_tests(NNFConverterTests)
gtest_discover_tests(TableauRulesTests)
