%{
/* C++ string header, for string ops below */
#include <string>

/* Implementation of yyFlexScanner */
#include "simple_expression_scanner.hpp"
#undef  YY_DECL
#define YY_DECL int mimg::SimpleExpressionScanner::yylex(mimg::SimpleExpressionParser::semantic_type * const lval, mimg::SimpleExpressionParser::location_type *loc)

/* typedef to make the returns for the tokens shorter */
using token = mimg::SimpleExpressionParser::token;

/* define yyterminate as this instead of NULL */
#define yyterminate() return( token::END )

/* msvc2010 requires that we exclude this header file. */
#define YY_NO_UNISTD_H

/* update location on matching */
#define YY_USER_ACTION loc->step(); loc->columns(yyleng);

%}

%option debug
%option nodefault
%option yyclass="mimg::SimpleExpressionScanner"
%option noyywrap
%option c++

%%
%{          /** Code executed at the beginning of yylex **/
    yylval = lval;
%}

"<"                                             {
                                                    return(token::OANGLE);
                                                }

">"                                             {
                                                    return(token::CANGLE);
                                                }

","                                             {
                                                    return(token::COMMA);
                                                }

"("                                             {
                                                    return(token::OPAREN);
                                                }

")"                                             {
                                                    return(token::CPAREN);
                                                }

"x"                                             {
                                                    return(token::XVAR);
                                                }

"y"                                             {
                                                    return(token::YVAR);
                                                }

"z"                                             {
                                                    return(token::ZVAR);
                                                }

"+"                                             {
                                                    return(token::PLUS);
                                                }

"-"                                             {
                                                    return(token::MINUS);
                                                }

"*"                                             {
                                                    return(token::MULTIPLY);
                                                }

"/"                                             {
                                                    return(token::DIVIDE);
                                                }

[0-9]*([0-9]\.?|\.[0-9])[0-9]*([Ee][-+]?[0-9]+) {
                                                    yylval->build<double>(atof(yytext));
                                                    return(token::FLOAT);
                                                }

"sin"                                           {
                                                    return(token::SIN);
                                                }

"cos"                                           {
                                                    return(token::COS);
                                                }

"tan"                                           {
                                                    return(token::TAN);
                                                }

[ \n\t]                                         {;}

.                                               {;}

%%
