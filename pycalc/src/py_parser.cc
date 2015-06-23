// A Bison parser, made by GNU Bison 3.0.4.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.

// As a special exception, you may create a larger work that contains
// part or all of the Bison parser skeleton and distribute that work
// under terms of your choice, so long as that work isn't itself a
// parser generator using the skeleton or a modified version thereof
// as a parser skeleton.  Alternatively, if you modify or redistribute
// the parser skeleton itself, you may (at your option) remove this
// special exception, which will cause the skeleton and the resulting
// Bison output files to be licensed under the GNU General Public
// License without this special exception.

// This special exception was added by the Free Software Foundation in
// version 2.2 of Bison.


// First part of user declarations.



# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "py_parser.hh"

// User implementation prologue.


// Unqualified %code blocks.


    #include "ParserContext.h"




#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> // FIXME: INFRINGES ON USER NAME SPACE.
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K].location)
/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

# ifndef YYLLOC_DEFAULT
#  define YYLLOC_DEFAULT(Current, Rhs, N)                               \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).begin  = YYRHSLOC (Rhs, 1).begin;                   \
          (Current).end    = YYRHSLOC (Rhs, N).end;                     \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).begin = (Current).end = YYRHSLOC (Rhs, 0).end;      \
        }                                                               \
    while (/*CONSTCOND*/ false)
# endif


// Suppress unused-variable warnings by "using" E.
#define YYUSE(E) ((void) (E))

// Enable debugging if requested.
#if YYDEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << std::endl;                  \
    }                                           \
  } while (false)

# define YY_REDUCE_PRINT(Rule)          \
  do {                                  \
    if (yydebug_)                       \
      yy_reduce_print_ (Rule);          \
  } while (false)

# define YY_STACK_PRINT()               \
  do {                                  \
    if (yydebug_)                       \
      yystack_print_ ();                \
  } while (false)

#else // !YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YYUSE(Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void>(0)
# define YY_STACK_PRINT()                static_cast<void>(0)

#endif // !YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)


namespace py {


  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  py_parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr = "";
        char const *yyp = yystr;

        for (;;)
          switch (*++yyp)
            {
            case '\'':
            case ',':
              goto do_not_strip_quotes;

            case '\\':
              if (*++yyp != '\\')
                goto do_not_strip_quotes;
              // Fall through.
            default:
              yyr += *yyp;
              break;

            case '"':
              return yyr;
            }
      do_not_strip_quotes: ;
      }

    return yystr;
  }


  /// Build a parser object.
  py_parser::py_parser (ParserContext& ctx_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      ctx (ctx_yyarg)
  {}

  py_parser::~py_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/

  inline
  py_parser::syntax_error::syntax_error (const location_type& l, const std::string& m)
    : std::runtime_error (m)
    , location (l)
  {}

  // basic_symbol.
  template <typename Base>
  inline
  py_parser::basic_symbol<Base>::basic_symbol ()
    : value ()
  {}

  template <typename Base>
  inline
  py_parser::basic_symbol<Base>::basic_symbol (const basic_symbol& other)
    : Base (other)
    , value ()
    , location (other.location)
  {
    value = other.value;
  }


  template <typename Base>
  inline
  py_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const semantic_type& v, const location_type& l)
    : Base (t)
    , value (v)
    , location (l)
  {}


  /// Constructor for valueless symbols.
  template <typename Base>
  inline
  py_parser::basic_symbol<Base>::basic_symbol (typename Base::kind_type t, const location_type& l)
    : Base (t)
    , value ()
    , location (l)
  {}

  template <typename Base>
  inline
  py_parser::basic_symbol<Base>::~basic_symbol ()
  {
    clear ();
  }

  template <typename Base>
  inline
  void
  py_parser::basic_symbol<Base>::clear ()
  {
    Base::clear ();
  }

  template <typename Base>
  inline
  bool
  py_parser::basic_symbol<Base>::empty () const
  {
    return Base::type_get () == empty_symbol;
  }

  template <typename Base>
  inline
  void
  py_parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move(s);
    value = s.value;
    location = s.location;
  }

  // by_type.
  inline
  py_parser::by_type::by_type ()
    : type (empty_symbol)
  {}

  inline
  py_parser::by_type::by_type (const by_type& other)
    : type (other.type)
  {}

  inline
  py_parser::by_type::by_type (token_type t)
    : type (yytranslate_ (t))
  {}

  inline
  void
  py_parser::by_type::clear ()
  {
    type = empty_symbol;
  }

  inline
  void
  py_parser::by_type::move (by_type& that)
  {
    type = that.type;
    that.clear ();
  }

  inline
  int
  py_parser::by_type::type_get () const
  {
    return type;
  }


  // by_state.
  inline
  py_parser::by_state::by_state ()
    : state (empty_state)
  {}

  inline
  py_parser::by_state::by_state (const by_state& other)
    : state (other.state)
  {}

  inline
  void
  py_parser::by_state::clear ()
  {
    state = empty_state;
  }

  inline
  void
  py_parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  inline
  py_parser::by_state::by_state (state_type s)
    : state (s)
  {}

  inline
  py_parser::symbol_number_type
  py_parser::by_state::type_get () const
  {
    if (state == empty_state)
      return empty_symbol;
    else
      return yystos_[state];
  }

  inline
  py_parser::stack_symbol_type::stack_symbol_type ()
  {}


  inline
  py_parser::stack_symbol_type::stack_symbol_type (state_type s, symbol_type& that)
    : super_type (s, that.location)
  {
    value = that.value;
    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  py_parser::stack_symbol_type&
  py_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    value = that.value;
    location = that.location;
    return *this;
  }


  template <typename Base>
  inline
  void
  py_parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);

    // User destructor.
    YYUSE (yysym.type_get ());
  }

#if YYDEBUG
  template <typename Base>
  void
  py_parser::yy_print_ (std::ostream& yyo,
                                     const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YYUSE (yyoutput);
    symbol_number_type yytype = yysym.type_get ();
    // Avoid a (spurious) G++ 4.8 warning about "array subscript is
    // below array bounds".
    if (yysym.empty ())
      std::abort ();
    yyo << (yytype < yyntokens_ ? "token" : "nterm")
        << ' ' << yytname_[yytype] << " ("
        << yysym.location << ": ";
    switch (yytype)
    {
            case 3: // "def"


        { yyoutput << (yysym.value); }

        break;

      case 4: // "pass"


        { yyoutput << (yysym.value); }

        break;

      case 5: // "if"


        { yyoutput << (yysym.value); }

        break;

      case 6: // "else"


        { yyoutput << (yysym.value); }

        break;

      case 7: // "elif"


        { yyoutput << (yysym.value); }

        break;

      case 8: // "or"


        { yyoutput << (yysym.value); }

        break;

      case 9: // "not"


        { yyoutput << (yysym.value); }

        break;

      case 10: // "and"


        { yyoutput << (yysym.value); }

        break;

      case 11: // "in"


        { yyoutput << (yysym.value); }

        break;

      case 12: // "is"


        { yyoutput << (yysym.value); }

        break;

      case 13: // "for"


        { yyoutput << (yysym.value); }

        break;

      case 14: // "del"


        { yyoutput << (yysym.value); }

        break;

      case 15: // ENDMARKER


        { yyoutput << (yysym.value); }

        break;

      case 16: // NEWLINE


        { yyoutput << (yysym.value); }

        break;

      case 17: // INDENT


        { yyoutput << (yysym.value); }

        break;

      case 18: // DEDENT


        { yyoutput << (yysym.value); }

        break;

      case 19: // "("


        { yyoutput << (yysym.value); }

        break;

      case 20: // ")"


        { yyoutput << (yysym.value); }

        break;

      case 21: // "["


        { yyoutput << (yysym.value); }

        break;

      case 22: // "]"


        { yyoutput << (yysym.value); }

        break;

      case 23: // ":"


        { yyoutput << (yysym.value); }

        break;

      case 24: // ","


        { yyoutput << (yysym.value); }

        break;

      case 25: // ";"


        { yyoutput << (yysym.value); }

        break;

      case 26: // "+"


        { yyoutput << (yysym.value); }

        break;

      case 27: // "-"


        { yyoutput << (yysym.value); }

        break;

      case 28: // "*"


        { yyoutput << (yysym.value); }

        break;

      case 29: // "/"


        { yyoutput << (yysym.value); }

        break;

      case 30: // "|"


        { yyoutput << (yysym.value); }

        break;

      case 31: // "&"


        { yyoutput << (yysym.value); }

        break;

      case 32: // "<"


        { yyoutput << (yysym.value); }

        break;

      case 33: // ">"


        { yyoutput << (yysym.value); }

        break;

      case 34: // "="


        { yyoutput << (yysym.value); }

        break;

      case 35: // "."


        { yyoutput << (yysym.value); }

        break;

      case 36: // "%"


        { yyoutput << (yysym.value); }

        break;

      case 37: // "`"


        { yyoutput << (yysym.value); }

        break;

      case 38: // "{"


        { yyoutput << (yysym.value); }

        break;

      case 39: // "}"


        { yyoutput << (yysym.value); }

        break;

      case 40: // "=="


        { yyoutput << (yysym.value); }

        break;

      case 41: // "!="


        { yyoutput << (yysym.value); }

        break;

      case 42: // "<="


        { yyoutput << (yysym.value); }

        break;

      case 43: // ">="


        { yyoutput << (yysym.value); }

        break;

      case 44: // "~"


        { yyoutput << (yysym.value); }

        break;

      case 45: // "^"


        { yyoutput << (yysym.value); }

        break;

      case 46: // "<<"


        { yyoutput << (yysym.value); }

        break;

      case 47: // ">>"


        { yyoutput << (yysym.value); }

        break;

      case 48: // "**"


        { yyoutput << (yysym.value); }

        break;

      case 49: // "+="


        { yyoutput << (yysym.value); }

        break;

      case 50: // "-="


        { yyoutput << (yysym.value); }

        break;

      case 51: // "*="


        { yyoutput << (yysym.value); }

        break;

      case 52: // "/="


        { yyoutput << (yysym.value); }

        break;

      case 53: // "%="


        { yyoutput << (yysym.value); }

        break;

      case 54: // "&="


        { yyoutput << (yysym.value); }

        break;

      case 55: // "|="


        { yyoutput << (yysym.value); }

        break;

      case 56: // "^="


        { yyoutput << (yysym.value); }

        break;

      case 57: // "<<="


        { yyoutput << (yysym.value); }

        break;

      case 58: // ">>="


        { yyoutput << (yysym.value); }

        break;

      case 59: // "**="


        { yyoutput << (yysym.value); }

        break;

      case 60: // "//"


        { yyoutput << (yysym.value); }

        break;

      case 61: // "//="


        { yyoutput << (yysym.value); }

        break;

      case 62: // "<-"


        { yyoutput << (yysym.value); }

        break;

      case 63: // "->"


        { yyoutput << (yysym.value); }

        break;

      case 64: // "..."


        { yyoutput << (yysym.value); }

        break;

      case 65: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 66: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 67: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 68: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 69: // "import"


        { yyoutput << (yysym.value); }

        break;

      case 70: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 71: // "break"


        { yyoutput << (yysym.value); }

        break;

      case 72: // "continue"


        { yyoutput << (yysym.value); }

        break;

      case 73: // "raise"


        { yyoutput << (yysym.value); }

        break;

      case 74: // "return"


        { yyoutput << (yysym.value); }

        break;

      case 75: // "as"


        { yyoutput << (yysym.value); }

        break;

      case 76: // "global"


        { yyoutput << (yysym.value); }

        break;

      case 77: // "nonlocal"


        { yyoutput << (yysym.value); }

        break;

      case 78: // "assert"


        { yyoutput << (yysym.value); }

        break;

      case 79: // "while"


        { yyoutput << (yysym.value); }

        break;

      case 80: // "False"


        { yyoutput << (yysym.value); }

        break;

      case 81: // "None"


        { yyoutput << (yysym.value); }

        break;

      case 82: // "True"


        { yyoutput << (yysym.value); }

        break;

      case 83: // "class"


        { yyoutput << (yysym.value); }

        break;

      case 84: // "except"


        { yyoutput << (yysym.value); }

        break;

      case 85: // "finally"


        { yyoutput << (yysym.value); }

        break;

      case 86: // "lambda"


        { yyoutput << (yysym.value); }

        break;

      case 87: // "try"


        { yyoutput << (yysym.value); }

        break;

      case 88: // "with"


        { yyoutput << (yysym.value); }

        break;

      case 89: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 90: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 91: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 92: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 94: // module


        { yyoutput << (yysym.value); }

        break;

      case 95: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 96: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 97: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 98: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 99: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 100: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 101: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 102: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 103: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 104: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 105: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 106: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 107: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 108: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 109: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 110: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 111: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 112: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 113: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 114: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 115: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 116: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 117: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 118: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 119: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 120: // test


        { yyoutput << (yysym.value); }

        break;

      case 121: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 122: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 123: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 124: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 125: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 126: // expr


        { yyoutput << (yysym.value); }

        break;

      case 127: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 128: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 129: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 130: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 131: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 132: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 133: // term


        { yyoutput << (yysym.value); }

        break;

      case 134: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 135: // factor


        { yyoutput << (yysym.value); }

        break;

      case 136: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 137: // power


        { yyoutput << (yysym.value); }

        break;

      case 138: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 139: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 140: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 141: // classdef


        { yyoutput << (yysym.value); }

        break;

      case 142: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 143: // argument_seq


        { yyoutput << (yysym.value); }

        break;

      case 144: // argument


        { yyoutput << (yysym.value); }

        break;

      case 145: // comp_iter


        { yyoutput << (yysym.value); }

        break;

      case 146: // comp_for


        { yyoutput << (yysym.value); }

        break;

      case 147: // atom


        { yyoutput << (yysym.value); }

        break;

      case 148: // dictorsetmaker


        { yyoutput << (yysym.value); }

        break;

      case 149: // dict


        { yyoutput << (yysym.value); }

        break;

      case 150: // dict_seq


        { yyoutput << (yysym.value); }

        break;

      case 151: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 152: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 153: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 154: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 155: // while_stmt


        { yyoutput << (yysym.value); }

        break;

      case 156: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 157: // suite


        { yyoutput << (yysym.value); }

        break;

      case 158: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 159: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 160: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 161: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 162: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 163: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 164: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 165: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 166: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 167: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 168: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 169: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 170: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 171: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 172: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 173: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 174: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 175: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 176: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 177: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 178: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 179: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 180: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 181: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 182: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 183: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 184: // assert_stmt


        { yyoutput << (yysym.value); }

        break;


      default:
        break;
    }
    yyo << ')';
  }
#endif

  inline
  void
  py_parser::yypush_ (const char* m, state_type s, symbol_type& sym)
  {
    stack_symbol_type t (s, sym);
    yypush_ (m, t);
  }

  inline
  void
  py_parser::yypush_ (const char* m, stack_symbol_type& s)
  {
    if (m)
      YY_SYMBOL_PRINT (m, s);
    yystack_.push (s);
  }

  inline
  void
  py_parser::yypop_ (unsigned int n)
  {
    yystack_.pop (n);
  }

#if YYDEBUG
  std::ostream&
  py_parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  py_parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  py_parser::debug_level_type
  py_parser::debug_level () const
  {
    return yydebug_;
  }

  void
  py_parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // YYDEBUG

  inline py_parser::state_type
  py_parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - yyntokens_] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - yyntokens_];
  }

  inline bool
  py_parser::yy_pact_value_is_default_ (int yyvalue)
  {
    return yyvalue == yypact_ninf_;
  }

  inline bool
  py_parser::yy_table_value_is_error_ (int yyvalue)
  {
    return yyvalue == yytable_ninf_;
  }

  int
  py_parser::parse ()
  {
    // State.
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The locations where the error started and ended.
    stack_symbol_type yyerror_range[3];

    /// The return value of parse ().
    int yyresult;

    // FIXME: This shoud be completely indented.  It is not yet to
    // avoid gratuitous conflicts when merging into the master branch.
    try
      {
    YYCDEBUG << "Starting parse" << std::endl;


    // User initialization code.
    
{
  // Initialize the initial location.
    yyla.location.begin.filename = yyla.location.end.filename = &ctx.fileName;
}



    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, yyla);

    // A new symbol was pushed on the stack.
  yynewstate:
    YYCDEBUG << "Entering state " << yystack_[0].state << std::endl;

    // Accept?
    if (yystack_[0].state == yyfinal_)
      goto yyacceptlab;

    goto yybackup;

    // Backup.
  yybackup:

    // Try to take a decision without lookahead.
    yyn = yypact_[yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token: ";
        try
          {
            yyla.type = yytranslate_ (yylex (&yyla.value, &yyla.location, ctx));
          }
        catch (const syntax_error& yyexc)
          {
            error (yyexc);
            goto yyerrlab1;
          }
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.type_get ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.type_get ())
      goto yydefault;

    // Reduce or error.
    yyn = yytable_[yyn];
    if (yyn <= 0)
      {
        if (yy_table_value_is_error_ (yyn))
          goto yyerrlab;
        yyn = -yyn;
        goto yyreduce;
      }

    // Count tokens shifted since error; after three, turn off error status.
    if (yyerrstatus_)
      --yyerrstatus_;

    // Shift the lookahead token.
    yypush_ ("Shifting", yyn, yyla);
    goto yynewstate;

  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;

  /*-----------------------------.
  | yyreduce -- Do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_(yystack_[yylen].state, yyr1_[yyn]);
      /* If YYLEN is nonzero, implement the default value of the
         action: '$$ = $1'.  Otherwise, use the top of the stack.

         Otherwise, the following line sets YYLHS.VALUE to garbage.
         This behavior is undocumented and Bison users should not rely
         upon it.  */
      if (yylen)
        yylhs.value = yystack_[yylen - 1].value;
      else
        yylhs.value = yystack_[0].value;

      // Compute the default @$.
      {
        slice<stack_symbol_type, stack_type> slice (yystack_, yylen);
        YYLLOC_DEFAULT (yylhs.location, slice, yylen);
      }

      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
      try
        {
          switch (yyn)
            {
  case 2:

    {
        AstNodeSeq *seq = dynamic_cast<AstNodeSeq*>((yystack_[0].value));
        assert(seq);
        ctx.ast->module = ctx.ast->CreateModule(yylhs.location, seq->seq);

        // make the parser printer happy, it expects a valid node
        (yylhs.value) = ctx.ast->module;
        delete seq;
    }

    break;

  case 3:

    {
         (yylhs.value) = (yystack_[1].value);
     }

    break;

  case 4:

    {
        (yylhs.value) = NULL; // newline_or_stmt NEWLINE
    }

    break;

  case 5:

    {
        (yylhs.value) = (yystack_[0].value); // newline_or_stmt stmt
    }

    break;

  case 6:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 7:

    {
        (yylhs.value) = AstNodeSeq::Add(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 8:

    {
        (yylhs.value) = (yystack_[0].value); // stmt: simple_stmt
    }

    break;

  case 9:

    {
        (yylhs.value) = (yystack_[0].value); // stmt: compound_stmt
    }

    break;

  case 10:

    {
        (yylhs.value) = (yystack_[1].value);  // simple_stmt: small_stmt_seq  NEWLINE
    }

    break;

  case 11:

    {
        (yylhs.value) = (yystack_[2].value); // simple_stmt:  small_stmt_seq  ";" NEWLINE
    }

    break;

  case 25:

    {
        (yylhs.value) = ctx.ast->CreateBreak(yylhs.location);
    }

    break;

  case 26:

    {
        (yylhs.value) = ctx.ast->CreateContinue(yylhs.location);
    }

    break;

  case 27:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location);
    }

    break;

  case 28:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location, (yystack_[0].value));
    }

    break;

  case 29:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location);
    }

    break;

  case 30:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[0].value));
    }

    break;

  case 31:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 33:

    {
        (yylhs.value) = (yystack_[0].value); // small_stmt_seq: small_stmt
    }

    break;

  case 34:

    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value)); 
    }

    break;

  case 35:

    {
        (yylhs.value) = ctx.ast->CreateDelete(yylhs.location, (yystack_[0].value));
    }

    break;

  case 36:

    {
        (yylhs.value) = ctx.ast->CreatePass(yylhs.location);
    }

    break;

  case 37:

    {
        (yylhs.value) = ctx.ast->CreateAugAssign(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 38:

    {
        (yylhs.value) = (yystack_[0].value);  /*foo*/
    }

    break;

  case 39:

    {
        (yylhs.value) = (yystack_[0].value); // expr_stmt: testlist_star_expr
    }

    break;

  case 40:

    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 41:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 42:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 43:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 44:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location);
    }

    break;

  case 45:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location, (yystack_[0].value));
    }

    break;

  case 46:

    {
        (yylhs.value) = ctx.ast->CreateYieldFrom(yylhs.location, (yystack_[0].value));
    }

    break;

  case 47:

    {
        (yylhs.value) = ctx.ast->CreateStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 48:

    {
        AstNode *a1 = (yystack_[0].value);
        (yylhs.value) = (yystack_[0].value); // testlist_star_expr:  test_star_expr_seq
    }

    break;

  case 49:

    {
        AstNode *a1 = (yystack_[1].value);
        (yylhs.value) = (yystack_[1].value); // testlist_star_expr: test_star_expr_seq ","
    }

    break;

  case 52:

    {
        // test_star_expr_seq: test_star_expr
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 53:

    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 69:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 73:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 75:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 76:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 79:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 80:

    {
        (yylhs.value) = AstToken::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 81:

    {
        (yylhs.value) = AstToken::GetAstNodeForOperatorType(py::IsNot);
    }

    break;

  case 92:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 94:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 96:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 98:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 102:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 106:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 112:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 117:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 119:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 120:

    {
        assert(0);
    }

    break;

  case 121:

    {
        assert(0);
    }

    break;

  case 123:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 124:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 125:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 126:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, NULL, (yystack_[1].value));
    }

    break;

  case 127:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 128:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[4].value), NULL, (yystack_[0].value));
    }

    break;

  case 129:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 130:

    {
        // arglist: argument_seq:
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 131:

    {
        // arglist: argument_seq ","
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 132:

    {
        // arglist:  "*" test
        // AstNode *args1 = NULL, 
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, (yystack_[0].value), NULL); 
    }

    break;

  case 133:

    {
        // arglist: argument_seq "," "*" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), (yystack_[0].value), NULL);
    }

    break;

  case 134:

    {
        // arglist: "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, NULL, (yystack_[0].value));
    }

    break;

  case 135:

    {
        // arglist: argument_seq "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), NULL, (yystack_[0].value));
    }

    break;

  case 136:

    {
        // arglist: argument_seq "," "*" test "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[6].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 137:

    {
        // argument_seq : argument ","
        // create a length 1 tuple containing the arg.
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 138:

    {
        // argument_seq: argument_seq argument
        // add argument to the seq
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 141:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 145:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 146:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 147:

    {
        // atom: |"[" testlist_comp "]"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 148:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location);
    }

    break;

  case 149:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 150:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 151:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 152:

    {
        //str
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 153:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::True);
    }

    break;

  case 154:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::False);
    }

    break;

  case 155:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::None);
    }

    break;

  case 158:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 159:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 160:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 169:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 170:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 171:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 172:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 173:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 174:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 175:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 176:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 177:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 178:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 179:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 180:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 182:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 183:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 184:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 187:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 188:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 189:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 190:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 191:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 192:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 193:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 194:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 195:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 196:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 197:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 198:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 199:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 200:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 201:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 202:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 203:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 204:

    {
        // tfpdef_test : tfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 205:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 206:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 207:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 208:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 209:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 211:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 212:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 213:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 216:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 217:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 218:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 219:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 220:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 221:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 222:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 223:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 224:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 225:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 226:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 227:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 228:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 229:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 232:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 233:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 234:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 235:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 238:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 239:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 240:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 241:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 243:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 244:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 246:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 247:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 248:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 249:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;



            default:
              break;
            }
        }
      catch (const syntax_error& yyexc)
        {
          error (yyexc);
          YYERROR;
        }
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;
      YY_STACK_PRINT ();

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, yylhs);
    }
    goto yynewstate;

  /*--------------------------------------.
  | yyerrlab -- here on detecting error.  |
  `--------------------------------------*/
  yyerrlab:
    // If not already recovering from an error, report this error.
    if (!yyerrstatus_)
      {
        ++yynerrs_;
        error (yyla.location, yysyntax_error_ (yystack_[0].state, yyla));
      }


    yyerror_range[1].location = yyla.location;
    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.type_get () == yyeof_)
          YYABORT;
        else if (!yyla.empty ())
          {
            yy_destroy_ ("Error: discarding", yyla);
            yyla.clear ();
          }
      }

    // Else will try to reuse lookahead token after shifting the error token.
    goto yyerrlab1;


  /*---------------------------------------------------.
  | yyerrorlab -- error raised explicitly by YYERROR.  |
  `---------------------------------------------------*/
  yyerrorlab:

    /* Pacify compilers like GCC when the user code never invokes
       YYERROR and the label yyerrorlab therefore never appears in user
       code.  */
    if (false)
      goto yyerrorlab;
    yyerror_range[1].location = yystack_[yylen - 1].location;
    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    goto yyerrlab1;

  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    {
      stack_symbol_type error_token;
      for (;;)
        {
          yyn = yypact_[yystack_[0].state];
          if (!yy_pact_value_is_default_ (yyn))
            {
              yyn += yyterror_;
              if (0 <= yyn && yyn <= yylast_ && yycheck_[yyn] == yyterror_)
                {
                  yyn = yytable_[yyn];
                  if (0 < yyn)
                    break;
                }
            }

          // Pop the current state because it cannot handle the error token.
          if (yystack_.size () == 1)
            YYABORT;

          yyerror_range[1].location = yystack_[0].location;
          yy_destroy_ ("Error: popping", yystack_[0]);
          yypop_ ();
          YY_STACK_PRINT ();
        }

      yyerror_range[2].location = yyla.location;
      YYLLOC_DEFAULT (error_token.location, yyerror_range, 2);

      // Shift the error token.
      error_token.state = yyn;
      yypush_ ("Shifting", error_token);
    }
    goto yynewstate;

    // Accept.
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;

    // Abort.
  yyabortlab:
    yyresult = 1;
    goto yyreturn;

  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack"
                 << std::endl;
        // Do not try to display the values of the reclaimed symbols,
        // as their printer might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
  }

  void
  py_parser::error (const syntax_error& yyexc)
  {
    error (yyexc.location, yyexc.what());
  }

  // Generate an error message.
  std::string
  py_parser::yysyntax_error_ (state_type yystate, const symbol_type& yyla) const
  {
    // Number of reported tokens (one for the "unexpected", one per
    // "expected").
    size_t yycount = 0;
    // Its maximum.
    enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
    // Arguments of yyformat.
    char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];

    /* There are many possibilities here to consider:
       - If this state is a consistent state with a default action, then
         the only way this function was invoked is if the default action
         is an error action.  In that case, don't check for expected
         tokens because there are none.
       - The only way there can be no lookahead present (in yyla) is
         if this state is a consistent state with a default action.
         Thus, detecting the absence of a lookahead is sufficient to
         determine that there is no unexpected or expected token to
         report.  In that case, just report a simple "syntax error".
       - Don't assume there isn't a lookahead just because this state is
         a consistent state with a default action.  There might have
         been a previous inconsistent state, consistent state with a
         non-default action, or user semantic action that manipulated
         yyla.  (However, yyla is currently not documented for users.)
       - Of course, the expected token list depends on states to have
         correct lookahead information, and it depends on the parser not
         to perform extra reductions after fetching a lookahead from the
         scanner and before detecting a syntax error.  Thus, state
         merging (from LALR or IELR) and default reductions corrupt the
         expected token list.  However, the list is correct for
         canonical LR with one exception: it will still contain any
         token that will not be accepted due to an error action in a
         later state.
    */
    if (!yyla.empty ())
      {
        int yytoken = yyla.type_get ();
        yyarg[yycount++] = yytname_[yytoken];
        int yyn = yypact_[yystate];
        if (!yy_pact_value_is_default_ (yyn))
          {
            /* Start YYX at -YYN if negative to avoid negative indexes in
               YYCHECK.  In other words, skip the first -YYN actions for
               this state because they are default actions.  */
            int yyxbegin = yyn < 0 ? -yyn : 0;
            // Stay within bounds of both yycheck and yytname.
            int yychecklim = yylast_ - yyn + 1;
            int yyxend = yychecklim < yyntokens_ ? yychecklim : yyntokens_;
            for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
              if (yycheck_[yyx + yyn] == yyx && yyx != yyterror_
                  && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
                {
                  if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                    {
                      yycount = 1;
                      break;
                    }
                  else
                    yyarg[yycount++] = yytname_[yyx];
                }
          }
      }

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
        YYCASE_(0, YY_("syntax error"));
        YYCASE_(1, YY_("syntax error, unexpected %s"));
        YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    size_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += yytnamerr_ (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const short int py_parser::yypact_ninf_ = -269;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -269,    53,  -269,   312,  -269,   -15,  -269,   916,   916,   187,
     187,  -269,  -269,   732,   824,  -269,  -269,   929,   837,  -269,
       1,   156,    19,     1,   903,  -269,  -269,   916,   916,     7,
       7,   916,   916,  -269,  -269,  -269,    22,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,
      55,  -269,  -269,  -269,    71,  -269,  -269,   308,  -269,    96,
    -269,    67,   114,  -269,    23,   102,    94,   103,    75,   104,
      89,  -269,   929,  -269,    92,  -269,    24,  -269,  -269,  -269,
    -269,  -269,  -269,    36,  -269,  -269,  -269,  -269,  -269,  -269,
    -269,   124,   123,  -269,  -269,   102,   141,   131,  -269,  -269,
    -269,   143,   137,   139,   102,  -269,   136,   125,  -269,   138,
    -269,    51,    24,  -269,  -269,    15,    25,  -269,   145,     6,
     916,  -269,   146,  -269,    95,  -269,  -269,   147,   147,   148,
     142,    93,  -269,   561,   745,   745,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,   916,   824,
     916,   916,   916,   165,  -269,   169,  -269,  -269,  -269,  -269,
    -269,  -269,  -269,   929,   929,   929,   929,  -269,  -269,   929,
    -269,  -269,   929,  -269,  -269,  -269,  -269,   929,  -269,   929,
     191,    90,    24,  -269,  -269,  -269,  -269,    20,    34,   640,
     916,   187,   187,  -269,  -269,  -269,   916,  -269,   916,  -269,
     653,    91,    24,  -269,  -269,    14,    41,    17,     1,   101,
    -269,   916,   916,   108,   916,   640,   719,   640,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,    83,   114,  -269,  -269,
    -269,   102,    94,   103,    75,   104,    89,  -269,  -269,  -269,
     916,   916,    39,   161,   158,  -269,  -269,  -269,  -269,   109,
     109,   162,   164,  -269,   175,  -269,   167,   640,   916,   185,
    -269,  -269,   180,  -269,   102,   205,  -269,   197,   206,   201,
    -269,   134,  -269,   149,  -269,   202,    18,   134,  -269,  -269,
      27,  -269,  -269,  -269,  -269,  -269,   221,   207,   208,  -269,
     916,  -269,  -269,   916,  -269,  -269,   811,   216,  -269,  -269,
     916,  -269,     3,   916,  -269,   209,   478,   130,   640,   916,
     916,  -269,   225,   222,   154,   155,   134,  -269,  -269,   228,
     160,   227,   640,   229,  -269,  -269,   916,   916,  -269,    -4,
     230,  -269,  -269,  -269,  -269,   640,  -269,   395,   232,   916,
     250,    74,  -269,  -269,  -269,  -269,   183,   239,  -269,  -269,
     640,  -269,   640,   236,  -269,   109,  -269,    -1,  -269,  -269,
    -269,   640,   238,   240,  -269,  -269,   173,  -269,  -269,  -269,
     217,  -269,   109,  -269,   640,   640,  -269,   916,  -269,  -269,
    -269,  -269
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,     0,   113,   114,     0,     0,   115,
       0,     0,     0,     0,    44,    25,    26,    29,    27,     0,
       0,     0,     0,   154,   155,   153,     0,   150,   151,   152,
       7,     5,     8,    33,    15,    20,    21,    22,    23,    24,
       0,    13,    14,    12,    38,    32,    51,    39,    52,    48,
      50,    70,    72,    74,    77,    78,    91,    93,    95,    97,
     101,   105,     0,   111,   116,   167,   118,     9,   163,   164,
     165,   166,   210,     0,   168,    16,   214,   215,    17,    18,
      19,     0,     0,    76,   186,   185,     0,   181,    35,   145,
     161,    52,     0,     0,    47,   148,     0,     0,   156,   157,
     242,     0,   120,   226,   227,     0,     0,   216,   230,   232,
       0,    45,    66,    68,    30,    28,   245,   244,   247,   248,
       0,     0,    10,     0,     0,     0,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,     0,    49,
       0,     0,     0,     0,    89,    90,    82,    83,    84,    88,
      86,    85,    87,     0,     0,     0,     0,    99,   100,     0,
     103,   104,     0,   107,   108,   109,   110,     0,   112,     0,
       0,     0,   119,   122,   213,   212,   211,     0,     0,     0,
       0,   182,     0,   162,   146,   147,     0,   149,   158,   207,
       0,     0,   121,   228,   229,     0,     0,     0,   231,     0,
      46,    67,     0,     0,     0,     0,     0,     0,    11,    34,
      42,    43,    40,    41,    37,    53,     0,    73,    75,    80,
      81,    79,    92,    94,    96,    98,   102,   106,   117,   125,
       0,     0,   139,     0,   130,   137,   124,   123,   189,   199,
       0,   205,     0,   193,   191,   201,   203,     0,     0,     0,
     177,   171,     0,   184,   183,     0,   159,     0,     0,     0,
     243,     0,   223,   238,   225,   236,     0,     0,   217,   219,
     234,   233,    69,    31,   246,   249,   173,     0,     0,   127,
       0,   132,   134,     0,   140,   126,   131,   197,   199,   196,
       0,   190,     0,     0,   187,     0,     0,   169,     0,     0,
       0,   208,     0,     0,     0,   237,     0,   220,   222,     0,
       0,     0,     0,     0,    71,   141,     0,     0,   138,     0,
     194,   206,   192,   202,   204,     0,   175,     0,     0,     0,
     179,   143,   160,   209,   224,   239,   240,     0,   218,   235,
       0,   128,     0,   133,   135,     0,   200,     0,   188,   178,
     176,     0,     0,     0,   144,   142,     0,   221,   174,   129,
       0,   198,     0,   170,     0,     0,   241,     0,   195,   172,
     180,   136
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -269,  -269,  -269,  -269,  -269,  -268,    -2,   133,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,  -269,    16,
       4,    13,     5,  -269,  -269,   -22,  -269,    -7,  -135,   113,
       8,  -269,  -269,    -5,   106,   110,   118,  -269,   105,  -269,
     107,  -269,   -44,  -269,  -269,  -269,   176,  -124,   204,  -139,
    -269,   -11,  -269,  -212,   269,  -269,  -269,  -269,   277,  -269,
    -269,  -269,  -269,  -269,  -208,  -269,     0,  -269,   211,  -269,
    -269,   -10,    -3,  -269,  -179,  -227,   214,  -269,  -269,  -269,
    -269,  -269,  -269,  -269,  -269,  -178,  -269,   -20,  -269,   268,
    -269,  -269
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    40,     3,    41,   260,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,   148,   121,   122,    60,    61,    62,
      63,    64,   163,    65,    66,    67,    68,   169,    69,   172,
      70,   177,    71,    72,    73,    74,   182,   183,    75,   243,
     244,   245,   364,   193,    76,   107,   108,   109,   102,    77,
      78,   307,    79,   337,   261,    80,    96,    97,    81,   188,
     252,   253,   297,   254,   356,   256,    82,    83,    84,    85,
      86,    87,   115,   117,   118,   274,   275,   111,    88,   127,
      89,    90
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      92,    42,   116,   119,    95,    95,   125,   286,   255,   289,
      98,   106,   104,    94,    94,   226,    93,   123,   101,   101,
     124,   123,   298,   299,   129,   130,   100,   100,   178,   279,
     294,   249,   153,   271,   154,   155,   277,   316,   336,     5,
     248,   201,   272,   180,   355,   278,   317,   372,   249,   304,
     203,   250,   192,     4,   113,   156,   157,   257,   247,   181,
     201,   269,   201,   158,   159,   160,   161,   199,   250,   360,
     200,   132,   150,   293,    91,   151,   201,   288,   247,   204,
     133,   209,   151,   114,   205,   251,   201,   192,   251,   290,
     110,   151,   251,   313,   207,   206,   126,   258,   318,   319,
     340,    20,   320,   273,   110,   134,   273,   273,   110,   251,
     276,   131,   216,   210,   351,   162,   217,   173,   174,    36,
     149,   167,   168,   333,   152,   175,   224,   358,   371,   365,
     170,   171,   164,   237,   166,   238,   338,   339,   347,   165,
     179,   123,   368,   187,   369,   378,   189,   221,   223,   176,
     220,   222,   190,   373,   225,   191,   192,   194,   231,   196,
     228,   195,   198,   212,   197,   215,   379,   380,   262,   208,
     211,   213,   214,   242,   341,    13,   229,    14,   230,   246,
     270,   295,   296,   123,   301,   300,   264,    95,   280,   266,
     281,   267,   265,   242,    18,   263,    94,   284,   251,   302,
       8,   303,   306,   308,   282,   283,    13,   285,    14,   242,
      13,   239,    14,    15,    16,    17,   309,    15,    16,   240,
     310,   312,   311,   273,   314,    18,   315,   321,   323,    18,
     322,    19,   335,   291,   292,    19,    33,    34,    35,   241,
     329,   343,   344,   345,   346,    37,    38,    39,   348,   349,
     350,   305,   352,    21,   357,   361,   363,    21,   366,   367,
     370,   374,   376,   375,   227,   377,   219,    33,    34,    35,
     232,    33,    34,    35,   235,   233,    37,    38,    39,   236,
      37,    38,    39,   324,   234,   328,   325,   184,   202,   242,
     112,   103,   332,   331,   185,   330,   334,   186,   128,     0,
       0,     0,     0,   342,    42,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,   353,
     354,     8,     0,     0,     0,     9,    10,    11,    12,     0,
       0,    13,   362,    14,     0,    42,     0,     0,    15,    16,
      17,     0,   135,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    19,   136,   137,   138,
     139,   140,   141,   142,   143,   144,   145,   146,     0,   147,
     381,     0,     0,     0,     0,     0,     0,    20,    21,     0,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    32,    33,    34,    35,    36,     0,     0,     5,     6,
       7,    37,    38,    39,     8,     0,     0,     0,     9,    10,
       0,     0,     0,   359,    13,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,     5,     6,     7,    37,    38,    39,     8,     0,     0,
       0,     9,    10,     0,     0,     0,     0,    13,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    20,    21,     0,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,    32,    33,    34,
      35,    36,     0,     0,     0,     6,     0,    37,    38,    39,
       8,     0,     0,     0,     0,    10,     0,   218,     0,     0,
      13,     0,    14,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    21,     0,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
       0,    33,    34,    35,     6,     0,     0,     0,     0,     8,
      37,    38,    39,     0,    10,     0,   259,     0,     0,    13,
       0,    14,     8,     0,     0,     0,    15,    16,    17,     0,
       0,     0,    13,   268,    14,     0,     0,     0,    18,    15,
      16,   240,     0,     0,    19,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,    19,     0,     0,
       0,   241,     0,     0,     0,     0,    21,     0,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    21,
      33,    34,    35,     0,     0,     0,     0,     0,     8,    37,
      38,    39,     0,    33,    34,    35,     0,     0,    13,   287,
      14,     8,    37,    38,    39,    15,    16,   240,     0,     0,
       0,    13,    99,    14,     8,     0,     0,    18,    15,    16,
      17,     0,     0,    19,    13,     0,    14,   241,     0,     0,
      18,    15,    16,    17,     0,     0,    19,     0,     0,     0,
       0,     0,     0,    18,     0,    21,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    33,
      34,    35,     0,     0,     0,     0,     0,     0,    37,    38,
      39,    21,    33,    34,    35,    24,     0,     0,     0,     0,
       8,    37,    38,    39,     0,    33,    34,    35,     0,     0,
      13,     0,    14,     8,    37,    38,    39,    15,    16,   326,
       0,     0,     0,    13,     0,    14,     8,     0,     0,    18,
      15,    16,    17,     0,     0,    19,    13,     0,    14,   327,
       0,     0,    18,    15,    16,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    18,   105,    21,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    33,    34,    35,     0,     0,     0,     0,     0,     0,
      37,    38,    39,    21,    33,    34,    35,     0,     0,     0,
       0,     0,     8,    37,    38,    39,     0,    33,    34,    35,
       0,     0,    13,     0,    14,     8,    37,    38,    39,    15,
      16,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,    18,    15,    16,     0,     0,     0,    19,    13,     0,
      14,     0,     0,     0,    18,    15,    16,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    18,     0,    21,
       0,   120,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    33,    34,    35,     0,     0,     0,     0,
       0,     0,    37,    38,    39,    21,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    37,    38,    39,     0,    33,
      34,    35,     0,     0,     0,     0,     0,     0,    37,    38,
      39
  };

  const short int
  py_parser::yycheck_[] =
  {
       7,     3,    22,    23,     9,    10,    28,   215,   187,   217,
      10,    18,    17,     9,    10,   150,     8,    24,    13,    14,
      27,    28,   249,   250,    31,    32,    13,    14,    72,   207,
     242,    28,     9,    19,    11,    12,    19,    19,   306,     3,
      20,    35,    28,    19,    48,    28,    28,    48,    28,   257,
      35,    48,    13,     0,    35,    32,    33,    23,   182,    35,
      35,   200,    35,    40,    41,    42,    43,    16,    48,   337,
      19,    16,     5,    34,    89,     8,    35,   216,   202,    64,
      25,    75,     8,    64,    69,    89,    35,    13,    89,     6,
      89,     8,    89,   271,    69,   115,    89,    63,   276,   277,
     308,    65,    75,    89,    89,    34,    89,    89,    89,    89,
      69,    89,    19,   120,   322,    92,    23,    28,    29,    83,
      24,    46,    47,   302,    10,    36,   148,   335,   355,   341,
      26,    27,    30,   177,    31,   179,     6,     7,   316,    45,
      48,   148,   350,    19,   352,   372,    23,   134,   135,    60,
     134,   135,    11,   361,   149,    24,    13,    20,   163,    23,
     152,    22,    24,    68,    39,    23,   374,   375,   190,    24,
      24,    24,    24,   180,   309,    19,    11,    21,     9,    89,
      89,    20,    24,   190,    20,    23,   191,   192,   208,   196,
      89,   198,   192,   200,    38,   191,   192,    89,    89,    24,
       9,    34,    17,    23,   211,   212,    19,   214,    21,   216,
      19,    20,    21,    26,    27,    28,    11,    26,    27,    28,
      23,    20,    16,    89,    75,    38,    24,     6,    20,    38,
      23,    44,    23,   240,   241,    44,    80,    81,    82,    48,
      24,    16,    20,    89,    89,    89,    90,    91,    20,    89,
      23,   258,    23,    66,    24,    23,     6,    66,    75,    20,
      24,    23,    89,    23,   151,    48,   133,    80,    81,    82,
     164,    80,    81,    82,   169,   165,    89,    90,    91,   172,
      89,    90,    91,   290,   166,   296,   293,    83,   112,   296,
      21,    14,   302,   300,    83,   298,   303,    83,    30,    -1,
      -1,    -1,    -1,   310,   306,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,   326,
     327,     9,    -1,    -1,    -1,    13,    14,    15,    16,    -1,
      -1,    19,   339,    21,    -1,   337,    -1,    -1,    26,    27,
      28,    -1,    34,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    -1,    61,
     377,    -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,
      68,    69,    70,    71,    72,    73,    74,    -1,    76,    77,
      78,    79,    80,    81,    82,    83,    -1,    -1,     3,     4,
       5,    89,    90,    91,     9,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    18,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,     3,     4,     5,    89,    90,    91,     9,    -1,    -1,
      -1,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    79,    80,    81,
      82,    83,    -1,    -1,    -1,     4,    -1,    89,    90,    91,
       9,    -1,    -1,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      -1,    80,    81,    82,     4,    -1,    -1,    -1,    -1,     9,
      89,    90,    91,    -1,    14,    -1,    16,    -1,    -1,    19,
      -1,    21,     9,    -1,    -1,    -1,    26,    27,    28,    -1,
      -1,    -1,    19,    20,    21,    -1,    -1,    -1,    38,    26,
      27,    28,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    -1,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    66,
      80,    81,    82,    -1,    -1,    -1,    -1,    -1,     9,    89,
      90,    91,    -1,    80,    81,    82,    -1,    -1,    19,    20,
      21,     9,    89,    90,    91,    26,    27,    28,    -1,    -1,
      -1,    19,    20,    21,     9,    -1,    -1,    38,    26,    27,
      28,    -1,    -1,    44,    19,    -1,    21,    48,    -1,    -1,
      38,    26,    27,    28,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    66,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91,    66,    80,    81,    82,    70,    -1,    -1,    -1,    -1,
       9,    89,    90,    91,    -1,    80,    81,    82,    -1,    -1,
      19,    -1,    21,     9,    89,    90,    91,    26,    27,    28,
      -1,    -1,    -1,    19,    -1,    21,     9,    -1,    -1,    38,
      26,    27,    28,    -1,    -1,    44,    19,    -1,    21,    48,
      -1,    -1,    38,    26,    27,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    39,    66,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    66,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,     9,    89,    90,    91,    -1,    80,    81,    82,
      -1,    -1,    19,    -1,    21,     9,    89,    90,    91,    26,
      27,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,
      -1,    38,    26,    27,    -1,    -1,    -1,    44,    19,    -1,
      21,    -1,    -1,    -1,    38,    26,    27,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    66,
      -1,    68,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    80,    81,    82,    -1,    -1,    -1,    -1,
      -1,    -1,    89,    90,    91,    66,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,
      91
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    94,    95,    97,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    21,    26,    27,    28,    38,    44,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    89,    90,    91,
      96,    98,    99,   100,   101,   102,   103,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     120,   121,   122,   123,   124,   126,   127,   128,   129,   131,
     133,   135,   136,   137,   138,   141,   147,   152,   153,   155,
     158,   161,   169,   170,   171,   172,   173,   174,   181,   183,
     184,    89,   120,   123,   113,   126,   159,   160,   159,    20,
     114,   115,   151,   151,   126,    39,   120,   148,   149,   150,
      89,   180,   147,    35,    64,   175,   180,   176,   177,   180,
      68,   118,   119,   120,   120,   118,    89,   182,   182,   120,
     120,    89,    16,    25,    34,    34,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,   117,    24,
       5,     8,    10,     9,    11,    12,    32,    33,    40,    41,
      42,    43,    92,   125,    30,    45,    31,    46,    47,   130,
      26,    27,   132,    28,    29,    36,    60,   134,   135,    48,
      19,    35,   139,   140,   141,   161,   169,    19,   162,    23,
      11,    24,    13,   146,    20,    22,    23,    39,    24,    16,
      19,    35,   139,    35,    64,    69,   180,    69,    24,    75,
     120,    24,    68,    24,    24,    23,    19,    23,    16,   100,
     112,   114,   112,   114,   118,   115,   121,   122,   123,    11,
       9,   126,   127,   128,   129,   131,   133,   135,   135,    20,
      28,    48,   120,   142,   143,   144,    89,   140,    20,    28,
      48,    89,   163,   164,   166,   167,   168,    23,    63,    16,
      99,   157,   118,   113,   126,   159,   120,   120,    20,   142,
      89,    19,    28,    89,   178,   179,    69,    19,    28,   178,
     180,    89,   120,   120,    89,   120,   157,    20,   142,   157,
       6,   120,   120,    34,   146,    20,    24,   165,   168,   168,
      23,    20,    24,    34,   157,   120,    17,   154,    23,    11,
      23,    16,    20,   178,    75,    24,    19,    28,   178,   178,
      75,     6,    23,    20,   120,   120,    28,    48,   144,    24,
     165,   120,   164,   167,   120,    23,    98,   156,     6,     7,
     157,   121,   120,    16,    20,    89,    89,   178,    20,    89,
      23,   157,    23,   120,   120,    48,   167,    24,   157,    18,
      98,    23,   120,     6,   145,   146,    75,    20,   157,   157,
      24,   168,    48,   157,    23,    23,    89,    48,   168,   157,
     157,   120
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    93,    94,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     101,   101,   101,   101,   101,   102,   103,   104,   104,   105,
     105,   105,   106,   107,   107,   108,   109,   110,   110,   110,
     111,   111,   111,   111,   112,   112,   112,   113,   114,   114,
     115,   115,   116,   116,   117,   117,   117,   117,   117,   117,
     117,   117,   117,   117,   117,   117,   118,   118,   119,   119,
     120,   120,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   125,   125,   125,   125,   125,   125,   125,   125,
     125,   126,   126,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   134,
     134,   135,   135,   136,   136,   136,   137,   137,   138,   138,
     138,   138,   139,   139,   140,   140,   140,   141,   141,   141,
     142,   142,   142,   142,   142,   142,   142,   143,   143,   144,
     144,   144,   145,   146,   146,   147,   147,   147,   147,   147,
     147,   147,   147,   147,   147,   147,   148,   149,   149,   150,
     150,   151,   151,   152,   152,   152,   152,   152,   152,   153,
     153,   154,   154,   155,   155,   156,   156,   157,   157,   158,
     158,   159,   159,   160,   160,   160,   160,   161,   161,   162,
     162,   163,   163,   163,   164,   164,   164,   164,   164,   165,
     165,   166,   166,   167,   167,   168,   168,   169,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   174,   174,   174,
     174,   174,   174,   174,   174,   174,   175,   175,   175,   175,
     176,   176,   177,   177,   177,   177,   178,   178,   179,   179,
     179,   179,   180,   180,   181,   182,   182,   183,   184,   184
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       2,     4,     1,     1,     3,     2,     1,     3,     1,     1,
       3,     3,     3,     3,     1,     2,     3,     2,     1,     2,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     3,
       1,     5,     1,     3,     1,     3,     2,     1,     1,     3,
       2,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     3,     1,     2,
       2,     3,     1,     2,     2,     2,     3,     4,     6,     7,
       1,     2,     2,     4,     2,     4,     7,     1,     3,     1,
       2,     3,     1,     4,     5,     2,     3,     3,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     3,
       5,     1,     2,     1,     1,     1,     1,     1,     1,     5,
       8,     0,     5,     4,     7,     1,     2,     1,     4,     6,
       9,     1,     2,     3,     3,     1,     1,     5,     7,     2,
       3,     1,     3,     1,     3,     6,     2,     2,     5,     0,
       3,     1,     3,     1,     3,     1,     3,     3,     5,     6,
       1,     2,     2,     2,     1,     1,     2,     4,     6,     4,
       5,     7,     5,     4,     6,     4,     1,     1,     2,     2,
       1,     2,     1,     3,     3,     5,     1,     2,     1,     3,
       3,     5,     1,     3,     2,     1,     3,     2,     2,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"def\"", "\"pass\"", "\"if\"",
  "\"else\"", "\"elif\"", "\"or\"", "\"not\"", "\"and\"", "\"in\"",
  "\"is\"", "\"for\"", "\"del\"", "ENDMARKER", "NEWLINE", "INDENT",
  "DEDENT", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\":\"", "\",\"", "\";\"",
  "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"|\"", "\"&\"", "\"<\"", "\">\"",
  "\"=\"", "\".\"", "\"%\"", "\"`\"", "\"{\"", "\"}\"", "\"==\"", "\"!=\"",
  "\"<=\"", "\">=\"", "\"~\"", "\"^\"", "\"<<\"", "\">>\"", "\"**\"",
  "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"",
  "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"", "\"//\"", "\"//=\"", "\"<-\"",
  "\"->\"", "\"...\"", "\"@\"", "\"await\"", "\"async\"", "\"from\"",
  "\"import\"", "\"yield\"", "\"break\"", "\"continue\"", "\"raise\"",
  "\"return\"", "\"as\"", "\"global\"", "\"nonlocal\"", "\"assert\"",
  "\"while\"", "\"False\"", "\"None\"", "\"True\"", "\"class\"",
  "\"except\"", "\"finally\"", "\"lambda\"", "\"try\"", "\"with\"", "NAME",
  "NUMBER", "STRING", "\"<>\"", "$accept", "module", "file_input",
  "newline_or_stmt", "newline_stmt_seq", "stmt", "simple_stmt",
  "small_stmt", "flow_stmt", "break_stmt", "continue_stmt", "return_stmt",
  "raise_stmt", "yield_stmt", "small_stmt_seq", "del_stmt", "pass_stmt",
  "expr_stmt", "assign_expr_seq", "yield_expr", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "shift_op", "arith_expr", "arith_op", "term", "term_op",
  "factor", "factor_op", "power", "atom_expr", "trailer_seq", "trailer",
  "classdef", "arglist", "argument_seq", "argument", "comp_iter",
  "comp_for", "atom", "dictorsetmaker", "dict", "dict_seq",
  "testlist_comp", "compound_stmt", "if_stmt", "elif_seq", "while_stmt",
  "stmt_seq", "suite", "for_stmt", "exprlist", "exprlist_seq", "funcdef",
  "parameters", "typedargslist", "var_args", "var_arglist_trailer",
  "named_args", "tfpdef_test", "tfpdef", "decorator", "decorators",
  "decorated", "import_stmt", "import_name", "import_from", "import_dots",
  "dotted_as_names", "dotted_as_names_seq", "import_as_names",
  "import_as_names_seq", "dotted_name", "global_stmt", "name_seq",
  "nonlocal_stmt", "assert_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   196,   196,   220,   228,   232,   241,   245,   266,   270,
     280,   284,   295,   296,   297,   298,   299,   300,   301,   302,
     307,   307,   307,   307,   307,   312,   320,   329,   333,   342,
     346,   350,   357,   367,   371,   382,   391,   408,   412,   416,
     434,   438,   443,   447,   474,   478,   482,   503,   520,   525,
     536,   536,   541,   546,   558,   558,   558,   558,   558,   558,
     558,   558,   559,   559,   559,   559,   566,   567,   574,   575,
     590,   591,   597,   598,   608,   609,   619,   623,   630,   631,
     644,   648,   652,   653,   654,   655,   656,   657,   658,   659,
     660,   667,   668,   677,   678,   687,   688,   697,   698,   705,
     705,   711,   712,   719,   719,   725,   726,   733,   733,   733,
     733,   739,   740,   747,   747,   747,   753,   754,   763,   764,
     773,   777,   786,   787,   801,   808,   814,   825,   829,   833,
     854,   860,   868,   875,   883,   890,   896,   911,   917,   929,
     930,   931,   941,   947,   948,   976,   982,   989,   997,  1001,
    1006,  1007,  1008,  1013,  1017,  1021,  1043,  1051,  1052,  1059,
    1063,  1090,  1091,  1099,  1100,  1101,  1102,  1103,  1104,  1112,
    1117,  1126,  1131,  1142,  1146,  1172,  1176,  1185,  1189,  1198,
    1202,  1211,  1212,  1222,  1228,  1233,  1234,  1240,  1245,  1255,
    1259,  1299,  1306,  1313,  1322,  1329,  1337,  1343,  1351,  1364,
    1368,  1379,  1383,  1391,  1395,  1409,  1416,  1430,  1434,  1438,
    1447,  1448,  1457,  1461,  1469,  1469,  1474,  1494,  1498,  1502,
    1506,  1510,  1514,  1518,  1522,  1526,  1537,  1542,  1547,  1552,
    1564,  1565,  1570,  1574,  1578,  1582,  1595,  1596,  1600,  1604,
    1608,  1612,  1624,  1625,  1638,  1646,  1647,  1657,  1666,  1670
  };

  // Print the state stack on the debug stream.
  void
  py_parser::yystack_print_ ()
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << i->state;
    *yycdebug_ << std::endl;
  }

  // Report on the debug stream that the rule \a yyrule is going to be reduced.
  void
  py_parser::yy_reduce_print_ (int yyrule)
  {
    unsigned int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):" << std::endl;
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // YYDEBUG

  // Symbol number corresponding to token number t.
  inline
  py_parser::token_number_type
  py_parser::yytranslate_ (int t)
  {
    static
    const token_number_type
    translate_table[] =
    {
     0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92
    };
    const unsigned int user_token_number_max_ = 347;
    const token_number_type undef_token_ = 2;

    if (static_cast<int>(t) <= yyeof_)
      return yyeof_;
    else if (static_cast<unsigned int> (t) <= user_token_number_max_)
      return translate_table[t];
    else
      return undef_token_;
  }


} // py





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

