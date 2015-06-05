%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define parser_class_name {calcxx_parser}
%define api.token.constructor
%define api.value.type variant
%define parse.assert
%code requires
{
# include <string>
class calcxx_driver;
}
// The parsing context.
%param { calcxx_driver& driver }
%locations
%initial-action
{
  // Initialize the initial location.
  @$.begin.filename = @$.end.filename = &driver.file;
};
%define parse.trace
%define parse.error verbose
%code
{
# include "calc++-driver.hh"
}
%define api.token.prefix {TOK_}
%token
  END  0  "end of file"
  ASSIGN  ":="
 //  MINUS   "-"
 // PLUS    "+"
 // STAR    "*"
 // SLASH   "/"
 // LPAREN  "("
 // RPAREN  ")"
 // NEWLINE
  DEF // need to add DEF token
  PASS
 // SEMI   ";"
 // COMMA  ","
 // EQUAL  "="
   IF "if"
ELSE "else"
OR "or"
NOT "not"
AND "and"
IN "in"
IS "is"

  ENDMARKER
  NEWLINE
  INDENT
  DEDENT
  LPAR ")"
  RPAR "("
  LSQB
  RSQB
  COLON ":"
  COMMA ","
  SEMI ";"
  PLUS "+"
  MINUS "-"
  STAR "*"
  SLASH "/"
  VBAR
  AMPER "&"
  LESS "<"
  GREATER ">"
  EQUAL "="
  DOT "."
  PERCENT "%"
  BACKQUOTE "`"
  LBRACE 
  RBRACE
  EQEQUAL "=="
  NOTEQUAL "!="
  LESSEQUAL "<="
  GREATEREQUAL ">="
  TILDE "~"
  CIRCUMFLEX "^"
LEFTSHIFT "<<"
RIGHTSHIFT ">>"
  DOUBLESTAR "**"
  PLUSEQUAL "+="
  MINEQUAL "-="
  STAREQUAL "*="
  SLASHEQUAL "/="
  PERCENTEQUAL "%="
  AMPEREQUAL "&="
  VBAREQUAL "|="
  CIRCUMFLEXEQUAL "^="
LEFTSHIFTEQUAL "<<="
RIGHTSHIFTEQUAL ">>="
  DOUBLESTAREQUAL "**+"
  DOUBLESLASH "//"
  DOUBLESLASHEQUAL "//="
  AT "@"
AWAIT "await"
ASYNC "async"
;

%token <std::string> NAME "name"
%token <int> NUMBER "number"
%token <std::string> STRING "string"
%type <ASTNode*> atom


// left associativity
%left "(" ")"
%left "-" "+"
%left "*" "/"  "%" "//"
 //Primary	  left to right	 ()  [ ]  .  -> dynamic_cast typeid

%left "<<"  ">>"
%left "<"  ">"  "<="  ">="
%left "=="  "!="
%left "&" "^" "|"
%left "and" "or"
%left ","
%left "**"

%right "="  "+="  "-="  "*="   "/="  "<<="  ">>="  "%="   "&="  "^="  "|="

 // ++  --  +  -  !  ~  &  *  (type_name)  sizeof new delete

 //   C++ Pointer to Member	left to right	.*->*
 //Conditional	 right to left	 ? :
 //Assignment	 right to left	 =  +=  -=  *=   /=  <<=  >>=  %=   &=  ^=  |=
 //Comma	 left to right	 ,

%printer { yyoutput << $$; } <*>;
%%



// # Start symbols for the grammar:
// #       single_input is a single interactive statement;
// #       file_input is a module or sequence of commands read from an input file;
// #       eval_input is the input for the eval() functions.
// # NB: compound_stmt in single_input is followed by extra NEWLINE!
// single_input: NEWLINE | simple_stmt | compound_stmt NEWLINE
// file_input: (NEWLINE | stmt)* ENDMARKER
// eval_input: testlist NEWLINE* ENDMARKER



%start arith_expr;




// *python3
// star_expr: '*' expr
// A standard expression preceeded by a star,
// see https://www.python.org/dev/peps/pep-3132/
star_expr:
    "*" expr
    ;

// (test|star_expr)
test_or_star:
    test | star_expr
    ;



//comma_opt:
//    %empty
//    | COMMA
//;

// *python3 test:
// test: or_test ['if' or_test 'else' test] | lambdef
test:
    or_test
    | or_test IF or_test ELSE test
;

// *python3 or_test:
// or_test: and_test ('or' and_test)*
or_test:
    and_test
    | or_test OR and_test
;

// *python3 and_test: 
// and_test: not_test ('and' not_test)*
and_test:
    not_test
    | and_test AND not_test
;

// *python3 not_test: 
// not_test: 'not' not_test | comparison
not_test:
    NOT not_test
   |  comparison
;


// *python3 comparison: 
// comparison: expr (comp_op expr)*
comparison:
    expr
    | comparison comp_op expr
;


//"*python3 comp_op"
// # <> isn't actually a valid comparison operator in Python. It's here for the
// # sake of a __future__ import described in PEP 401 (which really works :-)
// comp_op: '<'|'>'|'=='|'>='|'<='|'<>'|'!='|'in'|'not' 'in'|'is'|'is' 'not'
comp_op:
    "<"
    | ">"
    | "=="
    | ">="
    | "<="
    | "<>"
    | "!="
    | "in"
    | "not" "in"
    | "is"
    | "is" "not"
;


// *python3 expr
// expr: xor_expr ('|' xor_expr)*
expr:
    xor_expr
    | expr "|" xor_expr
    ;

// *python3 xor_expr
// xor_expr: and_expr ('^' and_expr)*
xor_expr:
    and_expr
    | xor_expr "^" and_expr
    ;

// *python3 and_expr
// and_expr: shift_expr ('&' shift_expr)*
and_expr:
    shift_expr
    | and_expr "&" shift_expr
    ;

// *python3 shift_expr
// shift_expr: arith_expr (('<<'|'>>') arith_expr)*
shift_expr:
    arith_expr shift_expr_seq
    ;

//     | shift_expr "<<" arith_expr
//    | shift_expr ">>" arith_expr


// (('<<'|'>>') arith_expr)*
shift_expr_seq:
    %empty
    | shift_expr_seq "<<" arith_expr
    | shift_expr_seq ">>" arith_expr
;


//shift_op:
//    "<<" | ">>"
//;

// *python3 arith_expr
// arith_expr: term (('+'|'-') term)*
arith_expr:
    term
    | arith_expr "+" term
    | arith_expr "-" term
    ;

//arith_op:
//    "+" | "-"
//    ;

// *python3 term
// term: factor (('*'|'/'|'%'|'//') factor)*
term:
    factor
    | term term_op factor
    ;

term_op:
    "*" | "/" | "%" | "//"
    ;


// factor: ('+'|'-'|'~') factor | power
factor:
    factor_op factor
    | power
    ;

factor_op:
    "+" | "-" | "~"
    ;

// power 		: atom trailer* ( options {greedy=true;}:DOUBLESTAR factor )? ;
// *python3 power:
// power: atom_expr ['**' factor]
power:
    atom_expr 
    | atom_expr "**" factor
    ;


// *python3 atom_expr
// atom_expr: [AWAIT] atom trailer*
atom_expr:
    atom trailer_seq
    ;

// trailer*
trailer_seq:
    %empty
    | trailer_seq trailer
    ;

// *python3 trailer:
// trailer: '(' [arglist] ')' | '[' subscriptlist ']' | '.' NAME
trailer:
"." NAME
| "(" ")"
| "(" arglist ")"
    ;



// arglist: argument (',' argument)*  [',']

// *python3 arglist
// arglist: argument (',' argument)*  [',']
arglist:
    arglist_seq
    | arglist_seq ","
    ;


// arglist: argument (',' argument)*  [',']    
arglist_seq:
   argument
   | arglist_seq "," argument
   ;

// 
// # The reason that keywords are test nodes instead of NAME is that using NAME
// # results in an ambiguity. ast.c makes sure it's a NAME.
// # "test '=' test" is really "keyword '=' test", but we have no such token.
// # These need to be in a single rule to avoid grammar that is ambiguous
// # to our LL(1) parser. Even though 'test' includes '*expr' in star_expr,
// # we explicitly match '*' here, too, to give it proper precedence.
// # Illegal combinations and orderings are blocked in ast.c:
// # multiple (test comp_for) arguements are blocked; keyword unpackings
// # that precede iterable unpackings are blocked; etc.
// argument: ( test [comp_for] |
//             test '=' test |
//             '**' test |
//             star_expr )
argument:
    test
    | test "=" test
    | "**" test
    ;
//    | test "=" test
//    | "**" test
//    ;


// *python3 atom
// atom: ('(' [yield_expr|testlist_comp] ')' |
//        '[' [testlist_comp] ']' |
//        '{' [dictorsetmaker] '}' |
//        NAME | NUMBER | STRING+ | '...' | 'None' | 'True' | 'False')
atom:
"(" test_or_star ")" {$$ = 0}
    | NAME       { $$ = 0 }
    | NUMBER { $$ = 0 } 
    | STRING { $$ = 0 }
;





%%
void
yy::calcxx_parser::error (const location_type& l,
                          const std::string& m)
{
  driver.error (l, m);
}
