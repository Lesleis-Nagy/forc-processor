//
// Created by L. Nagy on 07/07/2023.
// @file simple_expression.cpp
// @author L. Nagy
// A simple expression parser to parse and evaluate mathematical expressions with up to three variables - x, y & z.
//

#include "__simple_expression__.hpp"

namespace mimg {

    double SimpleScalarCalculator::operator()(double x, double y, double z) const {

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
                case TOKEN_X:
                    compute_stack.push(x);
                    break;
                case TOKEN_Y:
                    compute_stack.push(y);
                    break;
                case TOKEN_Z:
                    compute_stack.push(z);
                    break;
                case TOKEN_NUMBER:
                    //compute_stack.push(token.constant);
                    break;
                case TOKEN_PLUS:
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
                case TOKEN_MINUS:
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
                case TOKEN_MULTIPLY:
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
                case TOKEN_DIVIDE:
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
                case TOKEN_POWER:
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
                case TOKEN_SIN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'sin' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(sin(a));
                    }
                    break;
                case TOKEN_COS:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'cos' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(cos(a));
                    }
                    break;
                case TOKEN_TAN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'tan' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(tan(a));
                    }
                    break;
                case TOKEN_ASIN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'asin' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(asin(a));
                    }
                    break;
                case TOKEN_ACOS:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'acos' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(acos(a));
                    }
                    break;
                case TOKEN_ATAN:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'atan' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(atan(a));
                    }
                    break;
                case TOKEN_SINH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'sinh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(sinh(a));
                    }
                    break;
                case TOKEN_COSH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'cosh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(cosh(a));
                    }
                    break;
                case TOKEN_TANH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'tanh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(tanh(a));
                    }
                    break;
                case TOKEN_ASINH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'asinh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(asinh(a));
                    }
                    break;
                case TOKEN_ACOSH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'acosh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(acosh(a));
                    }
                    break;
                case TOKEN_ATANH:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'atanh' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(atanh(a));
                    }
                    break;
                case TOKEN_EXP:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'exp' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(exp(a));
                    }
                    break;
                case TOKEN_LOG:
                    if (compute_stack.empty()) {
                        throw std::runtime_error("Computation error: stack size cannot feed 'log' operator.");
                    } else {
                        double a = compute_stack.top();
                        compute_stack.pop();
                        compute_stack.push(log10(a));
                    }
                    break;
                case TOKEN_LN:
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

    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    // Scanner                                                                                                       //
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::vector<Token> SimpleScalarScanner::scan(const std::string &new_source) {

        using std::vector;

        vector<Token> tokens;

        init_scanner(new_source);

        for (;;) {
            Token token = scan_token();

            tokens.push_back(token);

            if (token.type == TOKEN_END) break;

            if (token.type == TOKEN_ERROR) break;

        }

        return tokens;

    }

    void SimpleScalarScanner::init_scanner(const std::string &new_source) {

        source = new_source;
        start = 0;
        current = 0;
        line = 1;

    }

    Token SimpleScalarScanner::scan_token() {

        start = current;

        scan_whitespace();

        if (is_at_end()) {
            return make_token(TOKEN_END);
        }

        Token tok_identifier = scan_identifier();
        if (tok_identifier.type == TOKEN_ERROR) {
            return tok_identifier;
        }
        if (tok_identifier.type != TOKEN_NOMATCH) {
            return tok_identifier;
        }

        Token tok_number = scan_number();
        if (tok_number.type == TOKEN_ERROR) {
            return tok_number;
        }
        if (tok_number.type != TOKEN_NOMATCH) {
            return tok_number;
        }

        Token tok_operator = scan_operator();
        if (tok_operator.type == TOKEN_ERROR) {
            return tok_operator;
        }
        if (tok_operator.type != TOKEN_NOMATCH) {
            return tok_operator;
        }

        return make_error_token("Token scanning error.");

    }

    void SimpleScalarScanner::scan_whitespace() {

        for (;;) {
            std::string c = peek();

            if (c == " " || peek() == "\r" ||  peek() == "\t" || peek() == "\n") {
                advance();
            } else {
                return;
            }
        }

    }

    Token SimpleScalarScanner::scan_operator() {

        if (peek() == "x") {
            advance();
            return make_token(TOKEN_X);
        }

        if (peek() == "y") {
            advance();
            return make_token(TOKEN_Y);
        }

        if (peek() == "z") {
            advance();
            return make_token(TOKEN_Z);
        }

        if (peek() == "(") {
            advance();
            return make_token(TOKEN_LEFT_PAREN);
        }

        if (peek() == ")") {
            advance();
            return make_token(TOKEN_RIGHT_PAREN);
        }

        if (peek() == "+") {
            advance();
            return make_token(TOKEN_PLUS);
        }

        if (peek() == "-") {
            advance();
            return make_token(TOKEN_MINUS);
        }

        if (peek() == "*") {
            advance();
            return make_token(TOKEN_MULTIPLY);
        }

        if (peek() == "/") {
            advance();
            return make_token(TOKEN_DIVIDE);
        }

        if (peek() == "^") {
            advance();
            return make_token(TOKEN_POWER);
        }

        if (peek() == ",") {
            advance();
            return make_token(TOKEN_COMMA);
        }

        if (peek() == "<") {
            advance();
            return make_token(TOKEN_LEFT_ANGLE);
        }

        if (peek() == ">") {
            advance();
            return make_token(TOKEN_RIGHT_ANGLE);
        }

        return make_token(TOKEN_NOMATCH);

    }

    Token SimpleScalarScanner::scan_identifier() {

        if (peek(5) == "asinh") {
            advance(5);
            return make_token(TOKEN_ASINH);
        }

        if (peek(5) == "acosh") {
            advance(5);
            return make_token(TOKEN_ACOSH);
        }

        if (peek(5) == "atanh") {
            advance(5);
            return make_token(TOKEN_ATANH);
        }

        if (peek(4) == "sinh") {
            advance(4);
            return make_token(TOKEN_SINH);
        }

        if (peek(4) == "cosh") {
            advance(4);
            return make_token(TOKEN_COSH);
        }

        if (peek(4) == "tanh") {
            advance(4);
            return make_token(TOKEN_TANH);
        }

        if (peek(4) == "asin") {
            advance(4);
            return make_token(TOKEN_ASIN);
        }

        if (peek(4) == "acos") {
            advance(4);
            return make_token(TOKEN_ACOS);
        }

        if (peek(4) == "atan") {
            advance(4);
            return make_token(TOKEN_ATAN);
        }

        if (peek(4) == "sqrt") {
            advance(4);
            return make_token(TOKEN_SQRT);
        }

        if (peek(3) == "exp") {
            advance(3);
            return make_token(TOKEN_EXP);
        }

        if (peek(3) == "log") {
            advance(3);
            return make_token(TOKEN_LOG);
        }

        if (peek(3) == "sin") {
            advance(3);
            return make_token(TOKEN_SIN);
        }

        if (peek(3) == "cos") {
            advance(3);
            return make_token(TOKEN_COS);
        }

        if (peek(3) == "tan") {
            advance(3);
            return make_token(TOKEN_TAN);
        }

        if (peek(2) == "ln") {
            advance(2);
            return make_token(TOKEN_LN);
        }

        return make_token(TOKEN_NOMATCH);

    }

    Token SimpleScalarScanner::scan_number() {

        typedef enum {
            START_INTEGER_PART,
            INTEGER_MINUS_PART,
            INTEGER_PART,
            START_FRACTION_PART,
            FRACTION_PART,
            START_EXPONENT_PART,
            EXPONENT_MINUS_PART,
            EXPONENT_INTEGER_PART

        } NumberParseState;

        std::string str_number;

        NumberParseState state = START_INTEGER_PART;

        for (;;) {

            if (state == START_INTEGER_PART && peek() == "-") {
                str_number += peek();
                advance();
                state = INTEGER_MINUS_PART;
                continue;
            }

            if (state == START_INTEGER_PART && peek_digit()) {
                str_number += peek();
                advance();
                state = INTEGER_PART;
                continue;
            }

            if (state == START_INTEGER_PART) {
                return make_token(TOKEN_NOMATCH);
            }

            if (state == INTEGER_MINUS_PART && peek_digit()) {
                str_number += peek();
                advance();
                state = INTEGER_PART;
                continue;
            }

            if (state == INTEGER_MINUS_PART) {
                retreat();
                return make_token(TOKEN_NOMATCH);
            }

            if (state == INTEGER_PART && peek_digit()) {
                str_number += peek();
                advance();
                continue;
            }

            if (state == INTEGER_PART && (peek() == ".")) {
               str_number += peek();
               advance();
               state = START_FRACTION_PART;
               continue;
            }

            if (state == INTEGER_PART) {
                return make_token(TOKEN_NUMBER);
            }

            if (state == START_FRACTION_PART && peek_digit()) {
                str_number += peek();
                advance();
                state = FRACTION_PART;
                continue;
            }

            if (state == START_FRACTION_PART) {
                return make_error_token("Unknown character.");
            }

            if (state == FRACTION_PART && peek_digit()) {
                str_number += peek();
                advance();
                continue;
            }

            if (state == FRACTION_PART && (peek() == "e" || peek() == "E")) {
                str_number += peek();
                advance();
                state = START_EXPONENT_PART;
                continue;
            }

            if (state == FRACTION_PART) {
                return make_token(TOKEN_NUMBER);
            }

            if (state == START_EXPONENT_PART && peek() == "-") {
                str_number += peek();
                advance();
                state = EXPONENT_MINUS_PART;
                continue;
            }

            if (state == START_EXPONENT_PART && peek_digit()) {
                str_number += peek();
                advance();
                state = EXPONENT_INTEGER_PART;
                continue;
            }

            if (state == START_EXPONENT_PART) {
                return make_error_token("Unknown character.");
            }

            if (state == EXPONENT_MINUS_PART && peek_digit()) {
                str_number += peek();
                advance();
                state = EXPONENT_INTEGER_PART;
                continue;
            }

            if (state == EXPONENT_MINUS_PART) {
                return make_error_token("Unknown character.");
            }

            if (state == EXPONENT_INTEGER_PART && peek_digit()) {
                str_number += peek();
                advance();
                continue;
            }

            return make_token(TOKEN_NUMBER);

        }

    }

    void SimpleScalarScanner::advance(size_t length) {

        // Increment current by 1.
        current += length;

    }

    void SimpleScalarScanner::retreat(size_t length) {

        // Decrement current by 1.
        current -= length;

    }

    std::string SimpleScalarScanner::peek(size_t length) {

        // Look at the current character, but do not advance.
        return source.substr(current, length);

    }

    bool SimpleScalarScanner::peek_digit() {

        // Check if the current character is a digit.
        if (peek() == "0") return true;
        if (peek() == "1") return true;
        if (peek() == "2") return true;
        if (peek() == "3") return true;
        if (peek() == "4") return true;
        if (peek() == "5") return true;
        if (peek() == "6") return true;
        if (peek() == "7") return true;
        if (peek() == "8") return true;
        if (peek() == "9") return true;
        return false;

    }

    bool SimpleScalarScanner::is_at_end() {

        // Check if the current character is at the end.
        return source[current] == '\0';

    }

    Token SimpleScalarScanner::make_token(TokenType type) {

        return {type, source.substr(start, current - start), ""};

    }

    Token SimpleScalarScanner::make_error_token(const char *message) {

        return {TOKEN_ERROR, source.substr(start, current - start), message};

    }

} // namespace ming.