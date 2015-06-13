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


%code provides
{
// A way to make syntax exceptions
// The body of the parser::syntax_error is defined as inline
// in the .cc file, so define a function here to create one of these
// exception types so that it may be used outside of the py_parser.cc
// file. 
namespace py
{
    py_parser::syntax_error syntax_error(const py_parser::location_type& l, const std::string& m);
}
   
}

%code
{
    #include "ParserContext.h"
}


%token
DEF "def"
PASS
IF "if"
ELSE "else"
OR "or"
NOT "not"
AND "and"
IN "in"
IS "is"
FOR "for"
ENDMARKER
NEWLINE
INDENT
DEDENT
LPAR "("
RPAR ")"
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
FROM "from"
YIELD "yield"
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



%start module;

module:
    file_input
    {
        AstNodeSeq *seq = dynamic_cast<AstNodeSeq*>($1);
        assert(seq);
        ctx.ast->module = ctx.ast->CreateModule(@$, seq->seq);
        delete seq;
    }
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
     {
         $$ = $1;
     }
;

// (NEWLINE | stmt)
newline_or_stmt:
    NEWLINE
    {
        $$ = NULL; // newline_or_stmt NEWLINE
    }
    | stmt
    {
        $$ = $1; // newline_or_stmt stmt
    }
    ;

// a sequence of zero or more newline_stmt
// (NEWLINE | stmt)*
newline_stmt_seq:
    %empty
    {
        $$ = NULL;
    }
    | newline_stmt_seq newline_or_stmt
    {
        $$ = AstNodeSeq::Add(@$, $1, $2);
    }
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
    simple_stmt
    {
        $$ = $1; // stmt: simple_stmt
    }
    | compound_stmt
    {
        $$ = $1; // stmt: compound_stmt
    }
    ;

// *python simple_stmt
// simple_stmt: small_stmt (';' small_stmt)* [';'] NEWLINE

simple_stmt:
    small_stmt_seq  NEWLINE
    {
        $$ = $1;  // simple_stmt: small_stmt_seq  NEWLINE
    }
    | small_stmt_seq  ";" NEWLINE
    {
        $$ = $1; // simple_stmt:  small_stmt_seq  ";" NEWLINE
    }
;


// *python3 small_stmt
// small_stmt: (expr_stmt | del_stmt | pass_stmt | flow_stmt |
//              import_stmt | global_stmt | nonlocal_stmt | assert_stmt)
small_stmt:
    pass_stmt
    {
        $$ = $1; /* pass_stmt */
    }
    | expr_stmt
    {
        $$ = $1; /* expr_stmt */
    }
;

// sequence of small statments, a single small_stmt, followed by
// an optional sequence of (';' small_stmt)
// small_stmt (';' small_stmt)*
small_stmt_seq:
    small_stmt
    {
        $$ = $1; // small_stmt_seq: small_stmt
    }
    | small_stmt_seq ";" small_stmt
    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        $$ = ctx.ast->CreateTuple(@$, UnknownCtx, $1, $3); 
    }
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
// note, there can be zero or more rhs to an assignment statement,
// in the case of zero rhs, it reduces to a single testlist_star_expr
expr_stmt:
    testlist_star_expr augassign testlist
    {
        throw syntax_error(@$, "not implemented");
    }
    | assign_expr_seq
    {
        $$ = $1;  /*foo*/
    }
    | testlist_star_expr
    {
        $$ = $1; // expr_stmt: testlist_star_expr
    }
;


// assign_expr_seq: testlist_star_expr '=' (yield_expr|testlist_star_expr))*
//
// In this recursive rule, bison scans a sequence from left to right, so
// a = b = c = 1
// first scans 'a = b', this yields the (testlist_star_expr "=" testlist_star_expr) rule,
// next the ' = c' term is scanned yielding the
// (assign_expr_seq "=" testlist_star_expr) rule.
// So, in this case, the 'Assign' node is first created in the first match,
// and for each additional term that is added, the value (what is assigned to the target)
// is shifted, and the previous value is added to the target of the Assign statement. 
assign_expr_seq:
    testlist_star_expr "=" yield_expr
    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }
    | testlist_star_expr "=" testlist_star_expr
    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        $$ = ctx.ast->CreateAssign(@$, $1, $3);
    }
    | assign_expr_seq "=" yield_expr
    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }
    | assign_expr_seq "=" testlist_star_expr
    {
        Assign *a = dynamic_cast<Assign*>($1);
        assert(a);
        a->AddValue($3);
        $$ = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }
    ;


// ('=' (yield_expr|testlist_star_expr))*
//assign_rhs_seq:
//    %empty
//    | assign_rhs_seq "=" yeild_expr_or_testlist_star_expr
//    ;
    
// yield_expr|testlist_star_expr
// placeholder for yeild expressions
//yeild_or_testlist_star_expr:
//    yield_expr
//    | testlist_star_expr
//;

// *python3
// yield_expr: 'yield' [yield_arg]
yield_expr:
    "yield"
    | "yield" yield_arg
    ;

// *python3
// yield_arg: 'from' test | testlist
yield_arg:
    "from" test
    | testlist
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
//
// if the trailing sequence, is empty, and it evaluates to
// the first rule, than the result is just whatever the first
// expression was. However, if there is a trailing commaa,
// and there is only one elment in the sequence, a length 1 tuple
// is returned. 
testlist_star_expr:
//    test_star_expr test_star_expr_seq
//    | test_star_expr test_star_expr_seq ","
//    ;


    test_star_expr_seq
    {
        AstNode *a1 = $1;
        $$ = $1; // testlist_star_expr:  test_star_expr_seq
    }
    | test_star_expr_seq ","
    {
        AstNode *a1 = $1;
        $$ = $1; // testlist_star_expr: test_star_expr_seq ","
    }
    ;



// (test|star_expr)
test_star_expr:
    test | star_expr
    ;

// testlist_star_expr_seq: (test|star_expr) (',' (test|star_expr))* 
test_star_expr_seq:
    test_star_expr
    {
        // test_star_expr_seq: test_star_expr
        $$ = $1;
    }
    | test_star_expr_seq "," test_star_expr
    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        $$ = ctx.ast->CreateTuple(@$, UnknownCtx, $1, $3);
    }
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
    | or_test IF or_test "else" test
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
    "(" ")"
    {
        // atom: "(" ")"
        $$ = ctx.ast->CreateTuple(@$, Load);
    }

    |"(" testlist_comp ")"
    {
        // atom: |"(" testlist_comp ")"
        $$ = $2;
    }
    | NAME       { $$ = $1; /*name*/}
    | NUMBER { $$ = $1; /*num*/} 
    | STRING { $$ = $1; /*str*/}
;


// *python3
// testlist_comp: (test|star_expr) ( comp_for | (',' (test|star_expr))* [','] )
//
// compare with testlist_star_expr;
//
// testlist_star_expr: (test|star_expr) (',' (test|star_expr))* [',']
// if the comp_for is not found, and "(',' (test|star_expr))*" branch is taken,
// it would likely result in a reduce-reduce conflict and the same sequence
// of tokens could be interpreted as either rule.
//
// solution, re-write the rule by spliting out the comp_for branch as follows
//
// testlist_comp:  (test|star_expr) ( comp_for | (',' (test|star_expr))* [','] )
// testlist_comp:  (test|star_expr) (',' (test|star_expr))* [',']
//                |(test|star_expr) (comp_for)
testlist_comp:
    testlist_star_expr
    ;






// * python compound_stmt
// compound_stmt: if_stmt | while_stmt | for_stmt | try_stmt | with_stmt | funcdef
//     | classdef | decorated
compound_stmt:
    funcdef
    | decorated
    | for_stmt
;



// stmt+
stmt_seq:
    stmt
    {
        $$ = ctx.ast->CreateTuple(@$, $1);
    }
    | stmt_seq stmt
    {
        $$ = ctx.ast->CreateTuple(@$, $1, $2);
    }
    ;

// *python3
// suite: simple_stmt | NEWLINE INDENT stmt+ DEDENT
suite:
    simple_stmt
    {
        $$ = ctx.ast->CreateTuple(@$, $1);
    }
    | NEWLINE INDENT stmt_seq DEDENT
    {
        $$ = $3;
    }
    ;

// *python3
// for_stmt: 'for' exprlist 'in' testlist ':' suite ['else' ':' suite]
for_stmt:
    "for" exprlist "in" testlist ":" suite
    | "for" exprlist "in" testlist ":" suite "else" ":" suite
    ;

// *python3
// exprlist: (expr|star_expr) (',' (expr|star_expr))* [',']
exprlist:
    exprlist_seq
    | exprlist_seq ","
    ;


// exprlist_seq: (expr|star_expr) (',' (expr|star_expr))*
exprlist_seq:
    expr
    | star_expr
    | exprlist_seq "," expr
    | exprlist_seq "," star_expr
    ;
    

// *python3    
funcdef: 
    "def" NAME parameters ":" suite
    {
        $$ = ctx.ast->CreateFunctionDef(@$, $2, $3, $5);
    }
    | "def" NAME parameters "->" test ":" suite
    {
        $$ = ctx.ast->CreateFunctionDef(@$, $2, $3, $7);
    }
    ;


// *python3
parameters: 
    "("  ")"
    {
        $$ = ctx.ast->CreateTmpArguments(@$);
    }
    | "(" typedargslist ")"
    {
        $$ = $2;
    }
    ;

//  *python3
//  typedargslist: (tfpdef ['=' test] (',' tfpdef ['=' test])* [','
//     ['*' [tfpdef] (',' tfpdef ['=' test])* [',' '**' tfpdef] | '**' tfpdef]]
//     |  '*' [tfpdef] (',' tfpdef ['=' test])* [',' '**' tfpdef] | '**' tfpdef)
//
//  re-indent and newline to line things up better
//  typedargslist:
//  (tfpdef ['=' test] (',' tfpdef ['=' test])* 
//  [',' ['*' [tfpdef] (',' tfpdef ['=' test])* [',' '**' tfpdef] | '**' tfpdef]]
//     |  '*' [tfpdef] (',' tfpdef ['=' test])* [',' '**' tfpdef] | '**' tfpdef)
//
//  the last two lines are essentially the same, these are the python list and dictionary 
//  args, define a varargs rule for them: 
//
//  varargs: '*' [tfpdef] (',' tfpdef ['=' test])* [',' '**' tfpdef] | '**' tfpdef
//
//  note the first tfpdef is optional in the grammar, I don't think it should be, 
//  leave it for now, and catch it when the AST is built. 
// 
//  with the var_args rule, can re-write the grammar as 
//  tfpdef ['=' test] (',' tfpdef ['=' test])* 
//  [',' varargs]
//     |  varargs
// 
//  and re-align the rows:
// 
//  tfpdef ['=' test] (',' tfpdef ['=' test])*  [',' var_args]
//  |  var_args
//
//  define the first part as named_args:
//  named_args: tfpdef ['=' test] (',' tfpdef ['=' test])*  


typedargslist:
    named_args
    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(@$);
        args->SetArgs($1);
        $$ = args;
    }
    | named_args "," var_args
    {
        TmpArguments *args = dynamic_cast<TmpArguments*>($3);
        assert(args);
        args->SetArgs($1);
        $$ = args;
    }
    | var_args
    {
        // var_args is already an TmpArguments type
        $$ = $1;
    }
    
// can define varargs rule for list and kw args
// '*' [tfpdef] (',' tfpdef ['=' test])* [',' '**' tfpdef] | '**' tfpdef
var_args:
    "*" tfpdef var_arglist_trailer
    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(@$);
        args->SetVararg($2);
        args->SetKwOnlyArgs($3);
        $$ = args;
    }
    | "*" tfpdef var_arglist_trailer "," "**" tfpdef   
    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(@$);
        args->SetVararg($2);
        args->SetKwOnlyArgs($3);
        args->SetVararg($6);
        $$ = args;
    }
    | "**" tfpdef
    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(@$);
        args->SetVararg($2);
        $$ = args;
    };
    | "*" var_arglist_trailer      
    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(@$);
        args->SetKwOnlyArgs($2);
        $$ = args;
    }
    | "*" var_arglist_trailer "," "**" tfpdef
    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(@$);
        args->SetKwOnlyArgs($2);
        args->SetKwArg($5);
        $$ = args;
    }
    ;


// trailer of a list of named args
// (',' tfpdef ['=' test])* 
var_arglist_trailer:
    %empty
    | var_arglist_trailer "," tfpdef_test
    {
        $$ = ctx.ast->CreateTuple(@$, UnknownCtx, $1, $3);
    }

    ;

//  define the first part as named_args:
//  named_args: tfpdef ['=' test] (',' tfpdef ['=' test])*  
//  named_args: tfpdef ['=' test] (',' tfpdef ['=' test])*  
named_args:
    tfpdef_test
    {
        $$ = ctx.ast->CreateTuple(@$, UnknownCtx, $1);
    }
    | named_args "," tfpdef_test
    {
        $$ = ctx.ast->CreateTuple(@$, UnknownCtx, $1, $3);
    }
    ;

// tfpdef ['=' test]
tfpdef_test:
    tfpdef
    {
        $$ = $1;
    }
    | tfpdef "=" test
    {
        Arg *arg = dynamic_cast<Arg*>($1);
        assert(arg);
        arg->def = dynamic_cast<Expr*>($3);
        assert(arg->def);
        $$ = arg;
    }
    ;

// *python3
// tfpdef: NAME [':' test]
tfpdef: 
    NAME 
    {
        AstNode *name = $1;
        Arg* result = ctx.ast->CreateArg(@$, name);
        ctx.ast->Free(name);
        $$ = result;
    }
    | NAME ":" test
    {
        AstNode *name = $1;
        AstNode *type = $3;
        Arg* result = ctx.ast->CreateArg(@$, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        $$ = result;
    }
    ;

// *python3
//decorator: '@' dotted_name [ '(' [arglist] ')' ] NEWLINE
decorator:
    "@" dotted_name NEWLINE
    | "@" dotted_name "(" ")" NEWLINE
    | "@" dotted_name "(" arglist ")" NEWLINE
    ;

// *python3
//decorators: decorator+
decorators:
    decorator
    | decorators decorator
    ;

// *python3
//decorated: decorators (classdef | funcdef | async_funcdef)
decorated:
    decorators funcdef
    ;

// *python3
// dotted_name: NAME ('.' NAME)*
dotted_name:
    NAME
    | dotted_name "." NAME
    ;



%%


namespace py
{

void py::py_parser::error (const location_type& l,
                          const std::string& m)
{
    ctx.Error(l, m);
}


py_parser::syntax_error syntax_error(const py_parser::location_type& l,
                                     const std::string& m)
{
    return py_parser::syntax_error(l, m);
}


}

