grammar SimpleExpression;

/*-------------------------------------------------------------------------------------------------------------------*/
/* Lexer                                                                                                             */
/*-------------------------------------------------------------------------------------------------------------------*/

// TOKENS
OPAREN:   '(' ;
CPAREN:   ')' ;
DECIMAL:  '.' ;
NEGATIVE: '-' ;
POSITIVE: '+' ;

X:    'x'     ;
Y:    'y'     ;
Z:    'z'     ;

SIN:  'sin'   ;
COS:  'cos'   ;
TAN:  'tan'   ;
ASIN: 'asin'  ;
ACOS: 'acos'  ;
ATAN: 'atan'  ;
HSIN: 'hsin'  ;
HCOS: 'hcos'  ;
HTAN: 'htan'  ;
EXP:  'exp'   ;
LOG:  'log'   ;
LG:   'lg'    ;

SET:  'set'   ;
MIN:  'min'   ;
MAX:  'max'   ;
TO:   'to'    ;

Float
  : NEGATIVE? [0-9]+ DECIMAL [0-9]+ 'E' (NEGATIVE | POSITIVE) [0-9]+
  ;

# Creates a 2d scalar function
myfunc(x,y) = sin(x)cos(y)

# Creates a 3d scalar function
myfunc2(x,y,z) = sin(x)cos(y)tan(z)

# Creates a 2d vector function
myfunc3(x,y) = <sin(x)cos(y), sin(y)cos(x)>

# Creates a 3d vector function
myfunc4(x,y,z) = <sin(x)cos(y), sin(y)cos(x), sin(z)cos(z)>

# Creates a set of random points
points myname are random with x::min=-1 x::max=2 y::min-1 y::max=2 n=100 seed=1337

# Creates a set of uniform points
points myothername are uniform with x::min=-1 x::max=2 y::min=-1 y::max=2 x::n=100 y::n=200

# Creates an interpolation of func
interpolation myinterpolation using myfunc with rbf::gaussian::3
