//
// Created by L. Nagy on 07/07/2023.
//

#include "simple_expression.hpp"

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

    std::vector<std::string> SimpleScalarScanner::scan(const char *source) {

        init_scanner(source);

        for (;;) {
            Token token = scan_token(source);
            if (token.line != line) {
                std::cout << token.line;
                line = token.line;
            } else {
                std::cout << "     |";
            }

            std::cout << token.type << token.length << token.start << std::endl;

            if (token.type == TOKEN_EOF) break;
        }

    }

    void SimpleScalarScanner::init_scanner(const char *source) {

        start = source;
        current = source;
        line = 1;

    }

    void SimpleScalarScanner::skip_whitespace() {

        for (;;) {
            char c = peek();
            switch (c) {
                case ' ':
                case '\r':
                case '\t':
                    advance();
                    break;
                case '\n':
                    line++;
                    advance();
                    break;
                default:
                    return;
            }
        }

    }

    Token SimpleScalarScanner::scan_token(const char *source) {

        skip_whitespace();

        start = current;

        if (is_at_end()) {
            return make_token(TOKEN_EOF);
        }

        char c = advance();

        if (is_alpha(c)) return identifier();
        if (is_digit(c)) return number();

        switch (c) {
            // Single character tokens.
            case 'x': return make_token(TOKEN_X);
            case 'y': return make_token(TOKEN_Y);
            case 'z': return make_token(TOKEN_Z);
            case '(': return make_token(TOKEN_LEFT_PAREN);
            case ')': return make_token(TOKEN_RIGHT_PAREN);
            case '+': return make_token(TOKEN_PLUS);
            case '-': return make_token(TOKEN_MINUS);
            case '*': return make_token(TOKEN_MULTIPLY);
            case '/': return make_token(TOKEN_DIVIDE);
            case '^': return make_token(TOKEN_POWER);
            case ',': return make_token(TOKEN_COMMA);
            case '<': return make_token(TOKEN_LEFT_ANGLE);
            case '>': return make_token(TOKEN_RIGHT_ANGLE);
            default: return make_error_token("Unexpected character.");

        }

        return make_error_token("Unexpected character.");

    }

    Token SimpleScalarScanner::identifier() {
        while (is_alpha(peek()) || is_digit(peek())) advance();
        return make_token(identifier_type());
    }

    TokenType SimpleScalarScanner::identifier_type() {
        return TOKEN_IDENTIFIER;
    }

    Token SimpleScalarScanner::number() {
        while (is_digit(peek())) advance ();

        // Look for a fractional part.
        if (peek() ==  '.' && is_digit(peek_next())) {
            // Consume the '.'.
            advance();
            while (is_digit(peek())) advance();
        }

        return make_token(TOKEN_NUMBER);
    }

    char SimpleScalarScanner::advance() {
        current++;
        return current[-1];
    }

    char SimpleScalarScanner::peek() {
        return *current;
    }

    char SimpleScalarScanner::peek_next() {
        if (is_at_end()) return '\0';
        return current[1];
    }

    bool SimpleScalarScanner::is_at_end() {
        return *current == '\0';
    }

    bool SimpleScalarScanner::is_alpha(char c) {
        return (c >= 'a' && c <= 'z') ||
               (c >= 'A' && c <= 'Z');
    }

    bool SimpleScalarScanner::is_digit(char c) {
        return c >= '0' && c <= '9';
    }

    Token SimpleScalarScanner::make_token(TokenType type) {
        return {type, start, (size_t)(current - start), line};
    }

    Token SimpleScalarScanner::make_error_token(const char *message) {
        return {TOKEN_ERROR, message, (size_t)strlen(message), line};
    }

} // namespace ming.