//
// Created by Lesleis Nagy on 14/07/2023.
//

#include "simple_expression_driver.hpp"

namespace mimg {

    double evaluate_expression_stack(const std::vector<Token> &stack, double x, double y, double z) {

        std::vector<double> result;

        for (const auto &token : stack) {
            switch (token.type) {
                case TK_CONSTANT:
                    result.push_back(token.value);
                    break;
                case TK_X:
                    result.push_back(x);
                    break;
                case TK_Y:
                    result.push_back(y);
                    break;
                case TK_Z:
                    result.push_back(z);
                    break;
                case TK_PLUS:
                    if (result.size() < 2) {
                        throw EvaluateExpressionStackBinaryOperatorArityException();
                    } else {
                        double v1 = result.back();
                        result.pop_back();
                        double v2 = result.back();
                        result.pop_back();
                        result.push_back(v1 + v2);
                    }
                    break;
                case TK_MINUS:
                    if (result.size() < 2) {
                        throw EvaluateExpressionStackBinaryOperatorArityException();
                    } else {
                        double v1 = result.back();
                        result.pop_back();
                        double v2 = result.back();
                        result.pop_back();
                        result.push_back(v2 - v1);
                    }
                    break;
                case TK_MULTIPLY:
                    if (result.size() < 2) {
                        throw EvaluateExpressionStackBinaryOperatorArityException();
                    } else {
                        double v1 = result.back();
                        result.pop_back();
                        double v2 = result.back();
                        result.pop_back();
                        result.push_back(v1 * v2);
                    }
                    break;
                case TK_DIVIDE:
                    if (result.size() < 2) {
                        throw EvaluateExpressionStackBinaryOperatorArityException();
                    } else {
                        double v1 = result.back();
                        result.pop_back();
                        double v2 = result.back();
                        result.pop_back();
                        result.push_back(v1 / v2);
                    }
                    break;
                case TK_SIN:
                    if (result.empty()) {
                        throw EvaluateExpressionStackUnaryOperatorArityException();
                    } else {
                        double v = result.back();
                        result.pop_back();
                        result.push_back(sin(v));
                    }
                    break;
                case TK_COS:
                    if (result.empty()) {
                        throw EvaluateExpressionStackUnaryOperatorArityException();
                    } else {
                        double v = result.back();
                        result.pop_back();
                        result.push_back(cos(v));
                    }
                    break;
                case TK_TAN:
                    if (result.empty()) {
                        throw EvaluateExpressionStackUnaryOperatorArityException();
                    } else {
                        double v = result.back();
                        result.pop_back();
                        result.push_back(tan(v));
                    }
                    break;
                default:
                    throw EvaluateExpressionStackUnknownOperationException();
            }
        }

        if (result.size() != 1) {
            throw EvaluateExpressionStackFinalSingleValueException();
        }

        return result[0];
    }

    //////////////////////////////
    // SimpleExpressionDriver member func impl.
    //////////////////////////////

    SimpleExpressionDriver::~SimpleExpressionDriver() {
        delete (scanner);
        scanner = nullptr;
        delete (parser);
        parser = nullptr;
    }

    SimpleCalculator SimpleExpressionDriver::parse(const char *const file_name) {

        using std::ifstream;

        ifstream fin(file_name);

        if (!fin.good()) {
            throw SimpleExpressionDriverInputFileException(file_name);
        }

        parse_helper(fin);

        return calculator;

    }

    SimpleCalculator SimpleExpressionDriver::parse(std::istream &stream) {

        if (!stream.good() && stream.eof()) {
            throw SimpleExpressionDriverInputFileException("");
        }

        parse_helper(stream);

        return calculator;

    }

    void SimpleExpressionDriver::parse_helper(std::istream &stream) {

        delete (scanner);
        try {
            scanner = new SimpleExpressionScanner(&stream);
        } catch (std::bad_alloc &e) {
            throw SimpleExpressionDriverFailedToAllocateScannerException();
        }

        delete (parser);
        try {
            parser = new SimpleExpressionParser(*scanner, *this);
        } catch (std::bad_alloc &e) {
            throw SimpleExpressionDriverFailedToAllocateParserException();
        }

        const int accept = 0;
        if (parser->parse() != accept) {
            throw SimpleExpressionDriverParseFailedException();
        }

    }

    void SimpleExpressionDriver::push_oparen() {
        // std::cout << "OPAREN" << "\n";
    }

    void SimpleExpressionDriver::push_cparen() {
        // std::cout << "CPAREN" << "\n";
    }

    void SimpleExpressionDriver::push_xvar() {
        stack.push_back({TK_X, 0.0});
    }

    void SimpleExpressionDriver::push_yvar() {
        stack.push_back({TK_Y, 0.0});
    }

    void SimpleExpressionDriver::push_zvar() {
        stack.push_back({TK_Z, 0.0});
    }

    void SimpleExpressionDriver::push_plus() {
        stack.push_back({TK_PLUS, 0.0});
    }

    void SimpleExpressionDriver::push_minus() {
        stack.push_back({TK_MINUS, 0.0});
    }

    void SimpleExpressionDriver::push_multiply() {
        stack.push_back({TK_MULTIPLY, 0.0});
    }

    void SimpleExpressionDriver::push_divide() {
        stack.push_back({TK_DIVIDE, 0.0});
    }

    void SimpleExpressionDriver::push_float(double value) {
        stack.push_back({TK_CONSTANT, value});
    }

    void SimpleExpressionDriver::push_sin() {
        stack.push_back({TK_SIN, 0.0});
    }

    void SimpleExpressionDriver::push_cos() {
        stack.push_back({TK_COS, 0.0});
    }

    void SimpleExpressionDriver::push_tan() {
        stack.push_back({TK_TAN, 0.0});
    }

    void SimpleExpressionDriver::push_expression() {
        std::vector<Token> new_stack;
        std::copy(stack.begin(), stack.end(), std::back_inserter(new_stack));
        calculator._expressions.push_back(std::move(new_stack));
        stack.clear();
    }

} // namespace mimg