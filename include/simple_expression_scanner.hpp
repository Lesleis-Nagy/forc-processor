//
// Created by Lesleis Nagy on 14/07/2023.
//

#pragma once

#if ! defined(yyFlexLexerOnce)
#include <FlexLexer.h>
#endif

#include "simple_expression.tab.hh"
#include "location.hh"

namespace mimg {

    class SimpleExpressionScanner : public yyFlexLexer {
    public:

       explicit SimpleExpressionScanner(std::istream *in) : yyFlexLexer(in) {}

       ~SimpleExpressionScanner() override = default;

       // Get rid of override virtual function warning.
       using FlexLexer::yylex;

       virtual int yylex(mimg::SimpleExpressionParser::semantic_type *lval,
                         mimg::SimpleExpressionParser::location_type *location);

    private:

        mimg::SimpleExpressionParser::semantic_type *yylval = nullptr;

    };

} // namespace mimg