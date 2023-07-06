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
FUNCTION myfunc(x,y) = sin(x)cos(y)

# Creates a 3d scalar function
FUNCTION myfunc2(x,y,z) = sin(x)cos(y)tan(z)

# Creates a 2d vector function
FUNCTION myfunc3(x,y) = <sin(x)cos(y), sin(y)cos(x)>

# Creates a 3d vector function
FUNCTION myfunc4(x,y,z) = <sin(x)cos(y), sin(y)cos(x), sin(z)cos(z)>

# Creates a set of random 2D points
POINTS myname ARE RANDOM WITH x:minimum=-1 x:maximum=2 y:minimum-1 y:maximum=2 n=100 seed=1337

# Creates a set of uniform 3D points
POINTS myothername ARE UNIFORM WITH x:minimum=-1 x:maximum=2 y:minimum=-1 y:maximum=2 x:n=100 y:n=200

# Creates an interpolation of func (dimensionalities are checked)
INTERPOLATION myinterp USING function=myfunc points=mypoints gaussian(1.2)

# Evaluate interpolations/functions
RESULT myresult = EVALUATE function=myfunc points=mypoints
RESULT myresult2 = EVALUATE interpolation=myinterp points=mypoints

SAVE myresult TO myfile.csv
SAVE myresult2 TO myfile2.csv
