grammar SimpleExpression;

/*-------------------------------------------------------------------------------------------------------------------*/
/* Parser                                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

scalar_expression
    : SIN OPAREN scalar_expression CPAREN
    | COS OPAREN scalar_expression CPAREN
    | TAN OPAREN scalar_expression CPAREN
    | ASIN OPAREN scalar_expression CPAREN
    | ACOS OPAREN scalar_expression CPAREN
    | ATAN OPAREN scalar_expression CPAREN
    | HSIN OPAREN scalar_expression CPAREN
    | HCOS OPAREN scalar_expression CPAREN
    | HTAN OPAREN scalar_expression CPAREN
    | AHSIN OPAREN scalar_expression CPAREN
    | AHCOS OPAREN scalar_expression CPAREN
    | AHTAN OPAREN scalar_expression CPAREN
    | EXP OPAREN scalar_expression CPAREN
    | LOG OPAREN scalar_expression CPAREN
    | LN OPAREN scalar_expression CPAREN
    | scalar_expression POWER scalar_expression
    | scalar_expression mult_div=(MULTIPLY | DIVIDE) scalar_expression
    | scalar_expression plus_minus=(PLUS | MINUS) scalar_expression
    | OPAREN scalar_expression CPAREN
    | variable
    | number
    ;

number
    : Integer
    | Float
    ;

variable
    : X
    | Y
    | Z
    ;


/*-------------------------------------------------------------------------------------------------------------------*/
/* Lexer                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

// TOKENS
OANGLE:   '<'  ;
CANGLE:   '>'  ;
OPAREN:   '('  ;
CPAREN:   ')'  ;
DECIMAL:  '.'  ;
MINUS:    '-'  ;
PLUS:     '+'  ;
MULTIPLY: '*'  ;
DIVIDE:   '/'  ;
POWER:    '^'  ;

X:    'x'      ;
Y:    'y'      ;
Z:    'z'      ;

SIN:   'sin'   ;
COS:   'cos'   ;
TAN:   'tan'   ;
ASIN:  'asin'  ;
ACOS:  'acos'  ;
ATAN:  'atan'  ;
HSIN:  'hsin'  ;
HCOS:  'hcos'  ;
HTAN:  'htan'  ;
AHSIN: 'ahsin' ;
AHCOS: 'ahcos' ;
AHTAN: 'ahtan' ;
EXP:   'exp'   ;
LOG:   'log'   ;
LN:    'ln'    ;

Integer
  : [0-9]+
  ;

Float
  : MINUS? [0-9]+ DECIMAL [0-9]+ ('E' (MINUS | PLUS) [0-9]+)?
  ;

WhiteSpace
  : [ \n\t\r]+ -> skip
  ;
