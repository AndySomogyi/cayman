%skeleton "lalr1.cc" /* -*- C++ -*- */
%require "3.0.4"
%defines
%define api.namespace {py}
%define parser_class_name {py_parser}
%define api.token.constructor {false}
%define api.value.type {AstNode*}
%define parse.assert
%define api.token.prefix {}

%code requires
{
# include <string>

    namespace py {
    class ParserContext;
    class AstNode;
    }
}
// The parsing context.
%param { ParserContext& ctx }
%locations
%initial-action
{
  // Initialize the initial location.
    @$.begin.filename = @$.end.filename = &ctx.fileName;
};
%define parse.trace
%define parse.error verbose
%code
{
    #include "ParserContext.h"
}


%token
  DEF // need to add DEF token
  PASS
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
NAME
NUMBER
STRING
;

//%token <std::string> NAME "name"
//%token <int> NUMBER "number"
//%token <std::string> STRING "string"
//%type <AstNode*> atom


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

%right "="  "+="  "-="  "*="   "/="  "<<="  ">>="  "%="   "&="  "^="  "|="

 // ++  --  +  -  !  ~  &  *  (type_name)  sizeof new delete

 //   C++ Pointer to Member	left to right	.*->*
 //Conditional	 right to left	 ? :
 //Assignment	 right to left	 =  +=  -=  *=   /=  <<=  >>=  %=   &=  ^=  |=
 //Comma	 left to right	 ,

%printer { yyoutput << $$; } <>

%%



// # Start symbols for the grammar:
// #       single_input is a single interactive statement;
// #       file_input is a module or sequence of commands read from an input file;
// #       eval_input is the input for the eval() functions.
// # NB: compound_stmt in single_input is followed by extra NEWLINE!
// single_input: NEWLINE | simple_stmt | compound_stmt NEWLINE
// file_input: (NEWLINE | stmt)* ENDMARKER
// eval_input: testlist NEWLINE* ENDMARKER



%start unit;

unit:
    file_input
;


// *python3
// single_input: NEWLINE | simple_stmt | compound_stmt NEWLINE
//single_input:
//    NEWLINE
//    | simple_stmt
//    | compound_stmt NEWLINE
//;

// *python3
// file_input: (NEWLINE | stmt)* ENDMARKER
file_input:
     newline_stmt_seq ENDMARKER
;

// (NEWLINE | stmt)
newline_or_stmt:
    NEWLINE
    | stmt
    ;

// a sequence of zero or more newline_stmt
// (NEWLINE | stmt)*
newline_stmt_seq:
    %empty
    | newline_stmt_seq newline_or_stmt
;


// NEWLINE*
// If components in a rule is empty, it means that result can match the empty string.
// For example, here is how to define a comma-separated sequence of zero or more exp groupings:
// To define a sequence of zero or more NEWLINES, we need two rules:

// newline_seq:
//    %empty
//    | newline_seq NEWLINE
//;


// *python3
// stmt: simple_stmt | compound_stmt
stmt:
    simple_stmt | compound_stmt
    ;

// *python simple_stmt
// simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE
simple_stmt:
    small_stmt_seq  NEWLINE
    | small_stmt_seq  ";" NEWLINE
;


// *python3 small_stmt
// small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt |
//              import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
small_stmt:
    pass_stmt
    | expr_stmt
;

// sequence of small statments, a single small_stmt, followed by
// an optional sequence of (';' small_stmt)
// small_stmt (';' small_stmt)*
small_stmt_seq:
    small_stmt
    | small_stmt_seq ";" small_stmt
;


// *python pass_stmt
// pass_stmt: 'pass'
pass_stmt:
    PASS
;

// *python3 expr_stmt
// expr_stmt: testlist_star_expr (augassign (yield_expr|testlist) |
//                      ('=' (yield_expr|testlist_star_expr))*)
// valid examples:
// a = 1
// a,b = 1,2
// a,b = c,d = 1,2
// result of expr_stmt can be either an Expr or Assign or ???
expr_stmt:
    testlist_star_expr augassign testlist
    | testlist_star_expr assign_rhs_seq
;


// ('=' (yield_expr|testlist_star_expr))*
assign_rhs_seq:
    %empty
    | assign_rhs_seq "=" yeild_expr_or_testlist_star_expr
    ;
    
// yield_expr|testlist_star_expr
// placeholder for yeild expressions
yeild_expr_or_testlist_star_expr:
    testlist_star_expr
;

// *python3
// star_expr: '*' expr
// A standard expression preceeded by a star,
// see https://www.python.org/dev/peps/pep-3132/
star_expr:
    "*" expr
    ;

// *python3
// testlist_star_expr: (test|star_expr) (',' (test|star_expr))* [',']
// the first part, "(test|star_expr) (',' (test|star_expr))*" is
// the test_or_star_seq, and followed by an optional ","
testlist_star_expr:
    test_or_star_seq
    | test_or_star_seq ","
    ;

// (test|star_expr)
test_or_star:
    test | star_expr
    ;

// (test|star_expr) (',' (test|star_expr))* 
test_or_star_seq:
    test_or_star
    | test_or_star_seq "," test_or_star
    ;

// *python3
// augassign: ('+=' | '-=' | '*=' | '@=' | '/=' | '%=' | '&=' | '|=' | '^=' |
//             '<<=' | '>>=' | '**=' | '//=')
augassign:
    "+=" | "-=" | "*=" | "@=" | "/=" | "%=" | "&=" | "|=" | "^=" |
             "<<=" | ">>=" | "**=" | "//="
    ;


// *python3 testlist
// testlist: test (',' test)* [',']
testlist:
    test_seq 
    | test_seq ","
;

// test_seq comma_opt

// sequence of one or more test statments
test_seq:
    test
    | test_seq "," test
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
    | arith_expr arith_op term
    ;

arith_op:
    "+" | "-"
    ;

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
    | "await" atom trailer_seq
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


// *python3 arglist
// arglist: argument (',' argument)*  [',']
arglist:
    arglist_seq
    | arglist_seq ","
    ;


// sequence of one or more 'argument', comma separated.
// argument (',' argument)*  
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




//comp_iter: comp_for | comp_if
//comp_for: 'for' exprlist 'in' or_test [comp_iter]
//comp_if: 'if' test_nocond [comp_iter]




// comp_iter: comp_for | comp_if

// comp_for: 'for' exprlist 'in' or_test [comp_iter]

// comp_if: 'if' old_test [comp_iter]




// *python3 atom
// atom: ('(' [yield_expr|testlist_comp] ')' |
//        '[' [testlist_comp] ']' |
//        '{' [dictorsetmaker] '}' |
//        NAME | NUMBER | STRING+ | '...' | 'None' | 'True' | 'False')



atom:
"(" test_or_star ")" {$$ = 0;}
| NAME       { $$ = 0; }
| NUMBER { $$ = 0; } 
| STRING { $$ = 0; }
;


// *python3
// testlist_comp: (test|star_expr) ( comp_for | (',' (test|star_expr))* [','] )




// * python compound_stmt
// compound_stmt: if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef
//     | classdef | decorated
compound_stmt:
    funcdef
;

// * python funcdef
// funcdef: 'def' NAME parameters ':' suite
funcdef:
    DEF NAME 
;
    





%%
void py::py_parser::error (const location_type& l,
                          const std::string& m)
{
    ctx.Error(l, m);
}
