//
// Created by L. Nagy on 05/07/2023.
//

#pragma once

#include <cmath>

#include <iostream>
#include <ranges>
#include <vector>
#include <stack>

#include <antlr4-runtime.h>

#include <SimpleExpressionLexer.h>
#include <SimpleExpressionParser.h>
#include <SimpleExpressionBaseListener.h>





class SimpleVector2DCalculator {
public:

};

class SimpleScalarCalculator {

public:

    double operator()(double x, double y, double z) const {

        using std::ranges::views::reverse;
        using std::stack;
        using std::sin, std::cos, std::tan;
        using std::asin, std::acos, std::atan;
        using std::sinh, std::cosh, std::tanh;
        using std::asinh, std::acosh, std::atanh;
        using std::exp, std::log10, std::log;

        stack<double> compute_stack;

        for (const auto &token: reverse(_expression_queue)) {
            switch (token.type) {
                case X:
                    compute_stack.push(x);
                    break;
                case Y:
                    compute_stack.push(y);
                    break;
                case Z:
                    compute_stack.push(z);
                    break;
                case CONST:
                    compute_stack.push(token.constant);
                    break;
                case PLUS:
                    if (compute_stack.size() < 2) {
                        throw std::runtime_error("Computation error: stack size cannot feed '+' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        double b = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(a + b);
                    }
                    break;
                case MINUS:
                    if (compute_stack.size() < 2) {
                        throw std::runtime_error("Computation error: stack size cannot feed '-' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        double b = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(a - b);
                    }
                    break;
                case MULTIPLY:
                    if (compute_stack.size() < 2) {
                        throw std::runtime_error("Computation error: stack size cannot feed '*' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        double b = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(a * b);
                    }
                    break;
                case DIVIDE:
                    if (compute_stack.size() < 2) {
                        throw std::runtime_error("Computation error: stack size cannot feed '/' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        double b = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(a / b);
                    }
                    break;
                case POWER:
                    if (compute_stack.size() < 2) {
                        throw std::runtime_error("Computation error: stack size cannot feed '^' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        double b = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(pow(a, b));
                    }
                    break;
                case SIN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'sin' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(sin(a));
                    }
                    break;
                case COS:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'cos' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(cos(a));
                    }
                    break;
                case TAN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'tan' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(tan(a));
                    }
                    break;
                case ASIN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'asin' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(asin(a));
                    }
                    break;
                case ACOS:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'acos' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(acos(a));
                    }
                    break;
                case ATAN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'atan' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(atan(a));
                    }
                    break;
                case SINH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'sinh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(sinh(a));
                    }
                    break;
                case COSH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'cosh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(cosh(a));
                    }
                    break;
                case TANH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'tanh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(tanh(a));
                    }
                    break;
                case ASINH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'asinh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(asinh(a));
                    }
                    break;
                case ACOSH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'acosh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(acosh(a));
                    }
                    break;
                case ATANH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'atanh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(atanh(a));
                    }
                    break;
                case EXP:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'exp' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(exp(a));
                    }
                    break;
                case LOG:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'log' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(log10(a));
                    }
                    break;
                case LN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'ln' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(log(a));
                    }
                    break;
                default:
                    throw std::runtime_error("Computation error: unknown token type.");
            }
        }

        if (compute_stack.size() != 1) {
            throw std::runtime_error("Computation error: compute stack didn't evaluate to a single value.");
        }

        return compute_stack.top();

    }

private:

    enum TokenType {
        X, Y, Z, CONST,
        PLUS, MINUS,
        MULTIPLY, DIVIDE,
        POWER,
        SIN, COS, TAN,
        ASIN, ACOS, ATAN,
        SINH, COSH, TANH,
        ASINH, ACOSH, ATANH,
        EXP, LOG, LN
    };

    struct Token {
        TokenType type;
        double constant;
    };

    std::vector<Token> _expression_queue;

    friend class SimpleExpressionListenerImpl;

};

class SimpleExpressionListenerImpl : public SimpleExpressionBaseListener {
public:

    explicit SimpleExpressionListenerImpl(SimpleScalarCalculator &calculator) :
    _calculator(calculator)
    {}

    void enterScalarExpression(SimpleExpressionParser::ScalarExpressionContext *) override;

private:

    SimpleScalarCalculator &_calculator;

};

class SimpleExpression {
public:

    SimpleExpression() = default;

    SimpleScalarCalculator parse(const std::string &expression) {

        std::stringstream ss(expression);

        antlr4::ANTLRInputStream input(ss);
        SimpleExpressionLexer lexer(&input);

        antlr4::CommonTokenStream tokens(&lexer);
        SimpleExpressionParser parser(&tokens);

        SimpleScalarCalculator calculator;
        SimpleExpressionListenerImpl listener(calculator);

        antlr4::tree::ParseTree *tree = parser.scalarExpression();

        antlr4::tree::ParseTreeWalker::DEFAULT.walk(&listener, tree);

        return calculator;

    }

    void say_hello();

};
