//
// Created by Lesleis Nagy on 14/07/2023.
//

#pragma once

#include <cstring>

#include <exception>
#include <fstream>
#include <istream>
#include <string>
#include <sstream>
#include <utility>

#include "point.hpp"

#include "simple_expression_scanner.hpp"
#include "simple_expression.tab.hh"

////////////////
// Exceptions
////////////////

namespace mimg {

    class EvaluateExpressionStackUnaryOperatorArityException : public std::exception {
    public:

        EvaluateExpressionStackUnaryOperatorArityException() = default;

        std::string what() {
            return "When executing a unary operation, no values were on the stack.";
        }

    };

    class EvaluateExpressionStackBinaryOperatorArityException : public std::exception {
    public:

        EvaluateExpressionStackBinaryOperatorArityException() = default;

        std::string what() {
            return "When executing a binary operation, fewer than two values were on the stack.";
        }

    };

    class EvaluateExpressionStackUnknownOperationException : public std::exception {
    public:

        EvaluateExpressionStackUnknownOperationException() = default;

        std::string what() {
            return "Unknown operation on the stack.";
        }

    };

    class EvaluateExpressionStackFinalSingleValueException : public std::exception {
    public:

        EvaluateExpressionStackFinalSingleValueException() = default;

        std::string what() {
            return "When terminating, the stack doesn't contain a single final value.";
        }

    };

    enum TokenType {
        TK_CONSTANT,
        TK_X, TK_Y, TK_Z,
        TK_PLUS, TK_MINUS,
        TK_MULTIPLY, TK_DIVIDE,
        TK_SIN, TK_COS, TK_TAN
    };

    struct Token {
        TokenType type;
        double value;
    };

    double evaluate_expression_stack(const std::vector<Token> &stack, double x, double y, double z);

////////////////
// SimpleExpressionDriver
////////////////

    class SimpleScalarCalculator {

    public:

        SimpleScalarCalculator() = default;

        double operator () (double x) const;

        double operator () (double x, double y) const;

        double operator () (double x, double y, double z) const;

        friend class SimpleExpressionDriver;

    private:

        std::vector<std::vector<Token>> _expressions;

    };

    class SimpleExpressionDriver {

    public:

        class SimpleExpressionDriverInputFileException : public std::exception {
        public:

            SimpleExpressionDriverInputFileException() = default;

            explicit SimpleExpressionDriverInputFileException(std::string file_name) : _file_name(std::move(file_name)) {}

            std::string what() {
                using std::stringstream;

                stringstream ss;
                ss << "Could not find file: '" << _file_name << "'.";
                return ss.str();
            }

        private:

            std::string _file_name;

        };

        class SimpleExpressionDriverFailedToAllocateScannerException : public std::exception {
        public:

            SimpleExpressionDriverFailedToAllocateScannerException() = default;

            std::string what() {
                return "Failed to allocate scanner.";
            }

        };

        class SimpleExpressionDriverFailedToAllocateParserException : public std::exception {
        public:

            SimpleExpressionDriverFailedToAllocateParserException() = default;

            std::string what() {
                return "Failed to allocate parser.";
            }

        };

        class SimpleExpressionDriverParseFailedException : public std::exception {
        public:

            SimpleExpressionDriverParseFailedException() = default;

            std::string what() {
                return "Failed to allocate parser.";
            }

        };

        SimpleExpressionDriver() = default;

        virtual ~SimpleExpressionDriver();

        /**
         * Parse from a file.
         * @param file_name the full path to a file.
         */
        SimpleCalculator parse(const char *const file_name);

        /**
         * Parse from a C++ input stream.
         * @param iss the input stream.
         */
        SimpleCalculator parse(std::istream &iss);

        void push_oparen();

        void push_cparen();

        void push_xvar();

        void push_yvar();

        void push_zvar();

        void push_plus();

        void push_minus();

        void push_multiply();

        void push_divide();

        void push_float(double value);

        void push_sin();

        void push_cos();

        void push_tan();

        void push_expression();

    private:

        void parse_helper(std::istream &stream);

        SimpleExpressionParser *parser = nullptr;

        SimpleExpressionScanner *scanner = nullptr;

        SimpleCalculator calculator;

        std::vector<Token> stack;

    };

} // namespace mimg