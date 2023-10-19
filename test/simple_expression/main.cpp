//
// Created by L. Nagy on 05/07/2023.
//

#define CATCH_CONFIG_MAIN
#include <catch/catch.hpp>

#include <sstream>

#include "simple_expression_driver.hpp"

using namespace mimg;

const double eps = 1E-18;

TEST_CASE("Test sin() with constant") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_CONSTANT, 1.0 / 3.0});
    stack.push_back({TK_SIN, 0.0});

    double result = evaluate_expression_stack(stack, 0.0, 0.0, 0.0);
    double expected = sin(1.0/3.0);

    std::cout << "Result sin(1/3): " << result - expected << "\n";

}

TEST_CASE("Test sin() with x variable") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_X, 0.0});
    stack.push_back({TK_SIN, 0.0});

    double result1 = evaluate_expression_stack(stack, 1.0/3.0, 0.0, 0.0);
    double expected1 = sin(1.0/3.0);

    double result2 = evaluate_expression_stack(stack, 1.0/2.0, 0.0, 0.0);
    double expected2 = sin(1.0/2.0);

    std::cout << "Result sin(x) 1: " << result1 - expected1 << "\n";
    std::cout << "Result sin(x) 2: " << result2 - expected2 << "\n";

}

TEST_CASE("Test sin() with y variable") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_Y, 0.0});
    stack.push_back({TK_SIN, 0.0});

    double result1 = evaluate_expression_stack(stack, 0.0, 1.0/3.0, 0.0);
    double expected1 = sin(1.0/3.0);

    double result2 = evaluate_expression_stack(stack, 0.0, 1.0/2.0, 0.0);
    double expected2 = sin(1.0/2.0);

    std::cout << "Result sin(y) 1: " << result1 - expected1 << "\n";
    std::cout << "Result sin(y) 2: " << result2 - expected2 << "\n";

}

TEST_CASE("Test sin() with z variable") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_Z, 0.0});
    stack.push_back({TK_SIN, 0.0});

    double result1 = evaluate_expression_stack(stack, 0.0, 0.0, 1.0/3.0);
    double expected1 = sin(1.0/3.0);

    double result2 = evaluate_expression_stack(stack, 0.0, 0.0, 1.0/2.0);
    double expected2 = sin(1.0/2.0);

    std::cout << "Result sin(z) 1: " << result1 - expected1 << "\n";
    std::cout << "Result sin(z) 2: " << result2 - expected2 << "\n";

}

TEST_CASE("Test plus expression: 1.0 + 2.0") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_CONSTANT, 1.0});
    stack.push_back({TK_CONSTANT, 2.0});
    stack.push_back({TK_PLUS, 0.0});

    double result = evaluate_expression_stack(stack, 0.0, 0.0, 0.0);
    double expected = 3.0;

    std::cout << "Result 1.0 + 2.0: " << result << "\n";

}

TEST_CASE("Test plus expression: x + y + z") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_X, 0.0});
    stack.push_back({TK_Y, 0.0});
    stack.push_back({TK_PLUS, 0.0});
    stack.push_back({TK_Z, 0.0});
    stack.push_back({TK_PLUS, 0.0});

    double result = evaluate_expression_stack(stack, 1.0, 2.0, 3.0);
    double expected = 6.0;

    std::cout << "Result 1.0 + 2.0 + 3.0: " << result << "\n";

}

TEST_CASE("Test minus expression: 1.0 - 2.0") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_CONSTANT, 1.0});
    stack.push_back({TK_CONSTANT, 2.0});
    stack.push_back({TK_MINUS, 0.0});

    double result = evaluate_expression_stack(stack, 0.0, 0.0, 0.0);
    double expected = -1.0;

    std::cout << "Result 1.0 - 2.0: " << result << "\n";

}

TEST_CASE("Test minus expression: x - y - z") {

    using std::vector;

    using mimg::Token;
    using mimg::TokenType;
    using mimg::SimpleExpressionDriver;
    using mimg::evaluate_expression_stack;

    vector<Token> stack;

    stack.push_back({TK_X, 0.0});
    stack.push_back({TK_Y, 0.0});
    stack.push_back({TK_MINUS, 0.0});
    stack.push_back({TK_Z, 0.0});
    stack.push_back({TK_MINUS, 0.0});

    double result = evaluate_expression_stack(stack, 1.0, 2.0, 3.0);
    double expected = -4.0;

    std::cout << "Result 1.0 - 2.0 - 3.0: " << result << "\n";

}
