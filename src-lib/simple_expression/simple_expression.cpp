//
// Created by L. Nagy on 07/07/2023.
//

#include "simple_expression.hpp"

void SimpleExpressionListenerImpl::enterScalarExpression(SimpleExpressionParser::ScalarExpressionContext *ctx) {

    if (ctx->variable()) {
        if (ctx->variable()->X()) {
            std::cout << ctx->variable()->X()->getText() << std::endl;
            _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::X, 0.0});
        }
        if (ctx->variable()->Y()) {
            std::cout << ctx->variable()->Y()->getText() << std::endl;
            _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::Y, 0.0});
        }
        if (ctx->variable()->Z()) {
            std::cout << ctx->variable()->Z()->getText() << std::endl;
            _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::Z, 0.0});
        }
    }

    if (ctx->number()) {
        std::cout << ctx->number()->getText() << std::endl;
        _calculator._expression_queue.push_back(
                {SimpleScalarCalculator::TokenType::CONST, std::stod(ctx->number()->getText())});
    }

    if (ctx->PLUS()) {
        std::cout << ctx->PLUS()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::PLUS, 0.0});
    }

    if (ctx->MINUS()) {
        std::cout << ctx->MINUS()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::MINUS, 0.0});
    }

    if (ctx->MULTIPLY()) {
        std::cout << ctx->MULTIPLY()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::MULTIPLY, 0.0});
    }

    if (ctx->DIVIDE()) {
        std::cout << ctx->DIVIDE()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::DIVIDE, 0.0});
    }

    if (ctx->POWER()) {
        std::cout << ctx->POWER()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::POWER, 0.0});
    }

    if (ctx->SIN()) {
        std::cout << ctx->SIN()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::SIN, 0.0});
    }

    if (ctx->COS()) {
        std::cout << ctx->COS()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::COS, 0.0});
    }

    if (ctx->TAN()) {
        std::cout << ctx->TAN()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::TAN, 0.0});
    }

    if (ctx->ASIN()) {
        std::cout << ctx->ASIN()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::ASIN, 0.0});
    }

    if (ctx->ACOS()) {
        std::cout << ctx->ACOS()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::ACOS, 0.0});
    }

    if (ctx->ATAN()) {
        std::cout << ctx->ATAN()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::ATAN, 0.0});
    }

    if (ctx->SINH()) {
        std::cout << ctx->SINH()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::SINH, 0.0});
    }

    if (ctx->COSH()) {
        std::cout << ctx->COSH()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::COSH, 0.0});
    }

    if (ctx->TANH()) {
        std::cout << ctx->TANH()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::TANH, 0.0});
    }

    if (ctx->ASINH()) {
        std::cout << ctx->ASINH()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::ASINH, 0.0});
    }

    if (ctx->ACOSH()) {
        std::cout << ctx->ACOSH()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::ACOSH, 0.0});
    }

    if (ctx->ATANH()) {
        std::cout << ctx->ATANH()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::ATANH, 0.0});
    }


    if (ctx->EXP()) {
        std::cout << ctx->EXP()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::EXP, 0.0});
    }

    if (ctx->LOG()) {
        std::cout << ctx->LOG()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::LOG, 0.0});
    }

    if (ctx->LN()) {
        std::cout << ctx->LN()->getText() << std::endl;
        _calculator._expression_queue.push_back({SimpleScalarCalculator::TokenType::LN, 0.0});
    }

}

void SimpleExpression::say_hello() {
    std::cout << "Hello!" << std::endl;
}
