%skeleton "lalr1.cc"
%require  "3.0"
%debug
%defines
%expect 16
%define api.namespace {mimg}
/**
 * bison 3.3.2 change
 * %define parser_class_name to this, updated
 * should work for previous bison versions as
 * well. -jcb 24 Jan 2020
 */
%define api.parser.class {SimpleExpressionParser}

%code requires{
   namespace mimg {
      class SimpleExpressionDriver;
      class SimpleExpressionScanner;
   }

// The following definitions is missing when %locations isn't used
# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

}

%parse-param { SimpleExpressionScanner  &scanner  }
%parse-param { SimpleExpressionDriver  &driver  }

%code{
   #include <iostream>
   #include <cstdlib>
   #include <fstream>

   /* include for all driver functions */
   #include "simple_expression_driver.hpp"

#undef yylex
#define yylex scanner.yylex
}

%define api.value.type variant
%define parse.assert

%token               END        0     "end of file"
%token               OANGLE
%token               CANGLE
%token               COMMA
%token               OPAREN
%token               CPAREN
%token               XVAR
%token               YVAR
%token               ZVAR
%token               PLUS
%token               MINUS
%token               MULTIPLY
%token               DIVIDE
%token <double>      FLOAT
%token               SIN
%token               COS
%token               TAN

%locations

%%

expression
    : scalar_expression { driver.push_expression(); } END
    | OANGLE vector_field CANGLE END
    ;

vector_field
    : three_field
    | two_field
    ;

two_field
    : scalar_expression { driver.push_expression(); }
      COMMA
      scalar_expression { driver.push_expression(); }
    ;

three_field
    : two_field
      COMMA
      scalar_expression { driver.push_expression(); }
    ;

scalar_expression
    : SIN OPAREN scalar_expression CPAREN { driver.push_sin(); }
    | COS OPAREN scalar_expression CPAREN { driver.push_cos(); }
    | TAN OPAREN scalar_expression CPAREN { driver.push_tan(); }
    | scalar_expression MULTIPLY scalar_expression { driver.push_multiply(); }
    | scalar_expression DIVIDE scalar_expression { driver.push_divide(); }
    | scalar_expression PLUS scalar_expression { driver.push_plus(); }
    | scalar_expression MINUS scalar_expression { driver.push_minus(); }
    | OPAREN scalar_expression CPAREN
    | variable
    | FLOAT { driver.push_float($1); }

    ;

variable
    : XVAR { driver.push_xvar(); }
    | YVAR { driver.push_yvar(); }
    | ZVAR { driver.push_zvar(); }
    ;

%%

void
mimg::SimpleExpressionParser::error( const location_type &l, const std::string &err_message )
{
   std::cerr << "Error: " << err_message << " at " << l << "\n";
}
