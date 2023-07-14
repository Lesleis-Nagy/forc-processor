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

#include "simple_expression_scanner.hpp"
#include "simple_expression.tab.hh"

////////////////
// Exceptions
////////////////

namespace mimg {

    class SimpleExpressionDriverInputFileException : public std::exception {
    public:

        SimpleExpressionDriverInputFileException() : _file_name("") {}

        SimpleExpressionDriverInputFileException(const std::string &file_name) : _file_name(file_name) {}

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

////////////////
// SimpleExpressionDriver
////////////////


    class SimpleExpressionDriver {

    public:
        SimpleExpressionDriver() = default;

        virtual ~SimpleExpressionDriver();

        /**
         * Parse from a file.
         * @param file_name the full path to a file.
         */
        void parse(const char *const file_name);

        /**
         * Parse from a C++ input stream.
         * @param iss the input stream.
         */
        void parse(std::istream &iss);

        void add_upper();

        void add_lower();

        void add_word(const std::string &word);

        void add_newline();

        void add_char();

        size_t get_chars() const { return chars; }
        size_t get_words() const { return words; }
        size_t get_lines() const { return lines; }
        size_t get_upper_case() const { return upper_case; }
        size_t get_lower_case() const { return lower_case; }
        std::string get_red() const { return red; }
        std::string get_blue() const { return blue; }
        std::string get_norm() const { return  norm; }

    private:

        void parse_helper(std::istream &stream);

        std::size_t chars = 0;
        std::size_t words = 0;
        std::size_t lines = 0;
        std::size_t upper_case = 0;
        std::size_t lower_case = 0;

        SimpleExpressionParser *parser = nullptr;
        SimpleExpressionScanner *scanner = nullptr;

        const std::string red = "\033[1;31m";
        const std::string blue = "\033[1;36m";
        const std::string norm = "\033[0m";

    };

    std::ostream &operator << (std::ostream &out, const SimpleExpressionDriver &driver);

} // namespace mimg