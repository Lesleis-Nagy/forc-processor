grammar SimpleExpression;

/*-------------------------------------------------------------------------------------------------------------------*/
/* Parser                                                                                                            */
/*-------------------------------------------------------------------------------------------------------------------*/

expression
    : scalarExpression
    | vectorExpression2D
    | vectorExpression3D
    ;

vectorExpression2D
    : OANGLE scalarExpression COMMA scalarExpression CANGLE
    ;

vectorExpression3D
    : OANGLE scalarExpression COMMA scalarExpression COMMA scalarExpression CANGLE
    ;

scalarExpression
    : SIN OPAREN scalarExpression CPAREN
    | COS OPAREN scalarExpression CPAREN
    | TAN OPAREN scalarExpression CPAREN
    | ASIN OPAREN scalarExpression CPAREN
    | ACOS OPAREN scalarExpression CPAREN
    | ATAN OPAREN scalarExpression CPAREN
    | SINH OPAREN scalarExpression CPAREN
    | COSH OPAREN scalarExpression CPAREN
    | TANH OPAREN scalarExpression CPAREN
    | ASINH OPAREN scalarExpression CPAREN
    | ACOSH OPAREN scalarExpression CPAREN
    | ATANH OPAREN scalarExpression CPAREN
    | EXP OPAREN scalarExpression CPAREN
    | LOG OPAREN scalarExpression CPAREN
    | LN OPAREN scalarExpression CPAREN
    | scalarExpression POWER scalarExpression
    | scalarExpression mult_div=(MULTIPLY | DIVIDE) scalarExpression
    | scalarExpression plus_minus=(PLUS | MINUS) scalarExpression
    | OPAREN scalarExpression CPAREN
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
COMMA:    ','  ;
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
SINH:  'sinh'  ;
COSH:  'cosh'  ;
TANH:  'tanh'  ;
ASINH: 'asinh' ;
ACOSH: 'acosh' ;
ATANH: 'atanh' ;
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
