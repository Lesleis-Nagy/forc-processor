//
// Created by L. Nagy on 05/07/2023.
//

#pragma once

#include <cmath>
#include <cstring>

#include <iostream>
#include <ranges>
#include <stack>
#include <string>
#include <vector>

namespace mimg {


    typedef enum {
        TOKEN_COMMA,
        TOKEN_LEFT_ANGLE, TOKEN_RIGHT_ANGLE,
        TOKEN_LEFT_PAREN, TOKEN_RIGHT_PAREN,
        TOKEN_X, TOKEN_Y, TOKEN_Z,
        TOKEN_NUMBER,
        TOKEN_PLUS, TOKEN_MINUS,
        TOKEN_MULTIPLY, TOKEN_DIVIDE,
        TOKEN_POWER,
        TOKEN_SIN, TOKEN_COS, TOKEN_TAN,
        TOKEN_ASIN, TOKEN_ACOS, TOKEN_ATAN,
        TOKEN_SINH, TOKEN_COSH, TOKEN_TANH,
        TOKEN_ASINH, TOKEN_ACOSH, TOKEN_ATANH,
        TOKEN_EXP, TOKEN_LOG, TOKEN_LN,
        TOKEN_SQRT,
        TOKEN_NOMATCH, TOKEN_ERROR, TOKEN_END
    } TokenType;

    inline const char * token_type_to_string(TokenType token_type) {

        switch (token_type) {
            case (TOKEN_COMMA): return "TOKEN_COMMA";
            case (TOKEN_LEFT_ANGLE): return "TOKEN_LEFT_ANGLE";
            case (TOKEN_RIGHT_ANGLE): return "TOKEN_RIGHT_ANGLE";
            case (TOKEN_LEFT_PAREN): return "TOKEN_LEFT_PAREN";
            case (TOKEN_RIGHT_PAREN): return "TOKEN_RIGHT_PAREN";
            case (TOKEN_X): return "TOKEN_X";
            case (TOKEN_Y): return "TOKEN_Y";
            case (TOKEN_Z): return "TOKEN_Z";
            case (TOKEN_NUMBER): return "TOKEN_NUMBER";
            case (TOKEN_PLUS): return "TOKEN_PLUS";
            case (TOKEN_MINUS): return "TOKEN_MINUS";
            case (TOKEN_MULTIPLY): return "TOKEN_MULTIPLY";
            case (TOKEN_DIVIDE): return "TOKEN_DIVIDE";
            case (TOKEN_POWER): return "TOKEN_POWER";
            case (TOKEN_SIN): return "TOKEN_SIN";
            case (TOKEN_COS): return "TOKEN_COS";
            case (TOKEN_TAN): return "TOKEN_TAN";
            case (TOKEN_ASIN): return "TOKEN_ASIN";
            case (TOKEN_ACOS): return "TOKEN_ACOS";
            case (TOKEN_ATAN): return "TOKEN_ATAN";
            case (TOKEN_SINH): return "TOKEN_SINH";
            case (TOKEN_COSH): return "TOKEN_COSH";
            case (TOKEN_TANH): return "TOKEN_TANH";
            case (TOKEN_ASINH): return "TOKEN_ASINH";
            case (TOKEN_ACOSH): return "TOKEN_ACOSH";
            case (TOKEN_ATANH): return "TOKEN_ATANH";
            case (TOKEN_EXP): return "TOKEN_EXP";
            case (TOKEN_LOG): return "TOKEN_LOG";
            case (TOKEN_LN): return "TOKEN_LN";
            case (TOKEN_SQRT): return "TOKEN_SQRT";
            case (TOKEN_NOMATCH): return "TOKEN_NOMATCH";
            case (TOKEN_ERROR): return "TOKEN_ERROR";
            case (TOKEN_END): return "TOKEN_END";
        }

    }

    struct Token {
        TokenType type;
        std::string match;
        const char *message;
    };


    /**
     * A simple scanner implementation for the tokens of our expression language - scanner generators SUCK because they
     * require a bunch of dependencies that do nothing break builds on multiple systems.
     */
    class SimpleScalarScanner {

    public:

        SimpleScalarScanner() = default;

        std::vector<Token> scan(const std::string &source);

    private:

        std::string source;
        size_t start;
        size_t current;
        size_t line;

        void init_scanner(const std::string &source);

        Token scan_token();

        void scan_whitespace();

        Token scan_operator();

        Token scan_identifier();

        Token scan_number();

        void advance(size_t length=1);

        void retreat(size_t length=1);

        std::string peek(size_t length=1);

        bool peek_digit();

        bool is_at_end();

        Token make_token(TokenType type);

        Token make_error_token(const char *message);

    };













    class SimpleScalarCalculator {

    public:

        double operator()(double x, double y, double z) const;

    private:

        std::vector<Token> _expression_queue;

        friend class SimpleExpressionListenerImpl;

    };

} // namespace mimg.
