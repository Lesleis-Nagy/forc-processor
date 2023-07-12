//
// Created by L. Nagy on 05/07/2023.
//

#pragma once

#include <cmath>
#include <cstring>

#include <iostream>
#include <ranges>
#include <vector>
#include <stack>

namespace mimg {

    typedef enum {
        TOKEN_COMMA, TOKEN_LEFT_ANGLE, TOKEN_RIGHT_ANGLE,
        TOKEN_X, TOKEN_Y, TOKEN_Z, TOKEN_NUMBER,
        TOKEN_PLUS, TOKEN_MINUS,
        TOKEN_MULTIPLY, TOKEN_DIVIDE,
        TOKEN_POWER,
        TOKEN_SIN, TOKEN_COS, TOKEN_TAN,
        TOKEN_ASIN, TOKEN_ACOS, TOKEN_ATAN,
        TOKEN_SINH, TOKEN_COSH, TOKEN_TANH,
        TOKEN_ASINH, TOKEN_ACOSH, TOKEN_ATANH,
        TOKEN_EXP, TOKEN_LOG, TOKEN_LN,
        TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
        TOKEN_ERROR, TOKEN_EOF
    } TokenType;

    struct Token {
        TokenType type;
        const char *start;
        size_t length;
        size_t line;
    };

    class SimpleScalarCalculator {

    public:

        double operator()(double x, double y, double z) const;

    private:


        std::vector<Token> _expression_queue;

        friend class SimpleExpressionListenerImpl;

    };

    class SimpleScalarScanner {
    public:

        std::vector<std::string> scan(const char *source);

    private:

        const char *start;
        const char *current;
        size_t line;

        void init_scanner(const char *source);

        Token scan_token(const char *source);

        Token identifier();

        TokenType identifier_type();

        Token number();

        void skip_whitespace();

        char advance();

        char peek();

        char peek_next();

        bool is_at_end();

        bool is_alpha(char c);

        bool is_digit(char c);

        Token make_token(TokenType type);

        Token make_error_token(const char *message);

    };

} // namespace mimg.
