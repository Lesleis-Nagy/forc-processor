//
// Created by Lesleis Nagy on 14/07/2023.
//

#include "simple_expression_driver.hpp"

namespace mimg {

    SimpleExpressionDriver::~SimpleExpressionDriver() {
        delete (scanner);
        scanner = nullptr;
        delete (parser);
        parser = nullptr;
    }

    void SimpleExpressionDriver::parse(const char *const file_name) {

        using std::ifstream;

        ifstream fin(file_name);

        if (!fin.good()) {
            throw SimpleExpressionDriverInputFileException(file_name);
        }

        parse_helper(fin);
        return;

    }

    void SimpleExpressionDriver::parse(std::istream &stream) {

        if (!stream.good() && stream.eof()) {
            return;
        }

        parse_helper(stream);
        return;
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

    void SimpleExpressionDriver::add_upper() {
        upper_case++;
        chars++;
        words++;
    }

    void SimpleExpressionDriver::add_lower() {
        lower_case++;
        chars++;
        words++;
    }

    void SimpleExpressionDriver::add_word(const std::string &word) {
        words++;
        chars += word.length();
        for (const char &c: word) {
            if (islower(c)) {
                lower_case++;
            } else if (isupper(c)) {
                upper_case++;
            }
        }
    }

    void SimpleExpressionDriver::add_newline() {
        lines++;
        chars++;
    }

    void SimpleExpressionDriver::add_char() {
        chars++;
    }

    std::ostream &operator<<(std::ostream &out, const SimpleExpressionDriver &driver) {

        out << driver.get_red() << "Results: " << driver.get_norm() << "\n";
        out << driver.get_blue() << "Uppercase: " << driver.get_norm() << driver.get_upper_case() << "\n";
        out << driver.get_blue() << "Lowercase: " << driver.get_norm() << driver.get_lower_case() << "\n";
        out << driver.get_blue() << "Lines: " << driver.get_norm() << driver.get_lines() << "\n";
        out << driver.get_blue() << "Words: " << driver.get_norm() << driver.get_words() << "\n";
        out << driver.get_blue() << "Characters: " << driver.get_norm() << driver.get_chars() << "\n";

        return (out);

    }

} // namespace mimg