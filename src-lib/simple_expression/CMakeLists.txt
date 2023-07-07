set(ANTLR4_GEN_INCLUDES ${CMAKE_BINARY_DIR}/antr4/grammar)

file(MAKE_DIRECTORY ${ANTLR4_GEN_INCLUDES})

add_custom_target(mimg_simple_expression_antlr4
        COMMAND           ${ANTLR4_EXE} -listener -visitor -Dlanguage=Cpp ${MIMG_GRAMMAR_DIR}/SimpleExpression.g4 -o .
        WORKING_DIRECTORY ${ANTLR4_GEN_INCLUDES}
        SOURCES           ${MIMG_GRAMMAR_DIR}/SimpleExpression.g4
        BYPRODUCTS        ${ANTLR4_GEN_INCLUDES}/SimpleExpressionBaseVisitor.cpp
                          ${ANTLR4_GEN_INCLUDES}/SimpleExpressionLexer.cpp
                          ${ANTLR4_GEN_INCLUDES}/SimpleExpressionParser.cpp
                          ${ANTLR4_GEN_INCLUDES}/SimpleExpressionVisitor.cpp)

add_library(mimg_simple_expression
        simple_expression.cpp
        ${ANTLR4_GEN_INCLUDES}/SimpleExpressionBaseVisitor.cpp
        ${ANTLR4_GEN_INCLUDES}/SimpleExpressionLexer.cpp
        ${ANTLR4_GEN_INCLUDES}/SimpleExpressionParser.cpp
        ${ANTLR4_GEN_INCLUDES}/SimpleExpressionVisitor.cpp)

target_include_directories(mimg_simple_expression
        PUBLIC ${MIMG_INCLUDE_DIR}
               ${ANTLR4_INCLUDES}
               ${ANTLR4_GEN_INCLUDES})

target_link_libraries(mimg_simple_expression
        ${ANTLR4_LIBRARIES})

add_dependencies(mimg_simple_expression mimg_simple_expression_antlr4)
