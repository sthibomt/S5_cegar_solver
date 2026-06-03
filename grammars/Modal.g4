grammar Modal;

formula
    : implication EOF
    ;

implication
    : disjunction (IMPLIES implication)?
    ;

disjunction
    : conjunction (OR conjunction)*
    ;

conjunction
    : unary (AND unary)*
    ;

unary
    : NOT unary
    | modal
    | atom
    | LPAREN implication RPAREN
    ;

modal
    : BOX unary
    | DIAMOND unary
    | agentBox unary
    | agentDiamond unary
    ;

agentBox
    : LBRACK INT RBRACK
    ;

agentDiamond
    : LANG INT RANG
    ;

atom
    : IDENTIFIER
    ;

BOX        : '[]';
DIAMOND    : '<>';

NOT        : '!';
AND        : '&';
OR         : '|';
IMPLIES    : '->';

LPAREN     : '(';
RPAREN     : ')';

LBRACK     : '[';
RBRACK     : ']';

LANG       : '<';
RANG       : '>';

INT : [0-9]+;

IDENTIFIER
    : [a-zA-Z][a-zA-Z0-9_]*
    ;

WS : [ \t\r\n]+ -> skip;