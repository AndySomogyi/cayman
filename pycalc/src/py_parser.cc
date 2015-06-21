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

      case 143: // arglist_seq


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
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 81:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
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

  case 131:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 132:

    {
       // arglist_seq: argument
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 133:

    {
       // arglists_seq: arglist_seq "," argument
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 136:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 137:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 141:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 142:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 143:

    {
        // atom: |"[" testlist_comp "]"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 144:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location);
    }

    break;

  case 145:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 146:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 147:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 148:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 151:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 152:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 153:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 162:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 163:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 164:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 165:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 166:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 167:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 168:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 169:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 170:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 171:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 173:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 175:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 176:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 177:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 180:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 181:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 182:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 183:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 184:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 185:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 186:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 187:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 188:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 189:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 190:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 191:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 192:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 193:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 194:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 195:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 196:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 197:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 198:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 199:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 200:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 201:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 202:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 204:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 205:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 206:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 209:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 210:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 211:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 212:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 213:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 214:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 215:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 216:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 217:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 218:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 219:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 220:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 221:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 222:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 225:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 226:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 227:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 228:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 231:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 232:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 233:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 234:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 236:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 237:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 239:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 240:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 241:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 242:

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


  const short int py_parser::yypact_ninf_ = -237;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -237,    37,  -237,   291,  -237,   -32,  -237,   494,   494,   708,
     708,  -237,  -237,    47,   675,  -237,  -237,   711,   390,  -237,
      13,    51,    43,    13,   695,  -237,  -237,   494,   494,    45,
      45,   494,   494,    97,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,   157,  -237,  -237,
    -237,    54,  -237,  -237,   162,  -237,   176,  -237,   148,   191,
    -237,   135,   179,   165,   194,    16,    88,   170,  -237,   711,
    -237,   178,  -237,   126,  -237,  -237,  -237,  -237,  -237,  -237,
      29,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   209,   206,
    -237,  -237,   179,   221,   210,  -237,  -237,  -237,   222,   217,
     214,   179,  -237,   215,   200,  -237,   218,  -237,    26,   126,
    -237,  -237,    17,    89,  -237,   223,     5,   494,  -237,   229,
    -237,   172,  -237,  -237,   230,   230,   231,   225,   174,  -237,
      27,   621,   621,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,   494,   675,   494,   494,   494,
     235,  -237,   232,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
     711,   711,   711,   711,  -237,  -237,   711,  -237,  -237,   711,
    -237,  -237,  -237,  -237,   711,  -237,   711,   224,   167,   126,
    -237,  -237,  -237,  -237,   115,    24,   535,   494,   708,   708,
    -237,  -237,  -237,   494,  -237,   494,  -237,   548,   168,   126,
    -237,  -237,     1,    93,    30,    13,   169,  -237,   494,   494,
     171,   494,   535,   608,   535,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,   216,   191,  -237,  -237,  -237,   179,   165,
     194,    16,    88,   170,  -237,  -237,  -237,   494,  -237,   227,
     239,   240,  -237,  -237,  -237,  -237,   177,   177,   242,   243,
    -237,   245,  -237,   233,   535,   494,   253,  -237,  -237,   248,
    -237,   179,   262,  -237,   251,   259,   256,  -237,   188,  -237,
     203,  -237,   255,    32,   188,  -237,  -237,    34,  -237,  -237,
    -237,  -237,  -237,   274,   261,   267,  -237,   494,  -237,   494,
    -237,   634,   258,  -237,  -237,   494,  -237,    36,   494,  -237,
     265,   457,   173,   535,   494,   494,  -237,   275,   273,   208,
     212,   188,  -237,  -237,   282,   219,   280,   535,   286,  -237,
    -237,  -237,   -13,   287,  -237,  -237,  -237,  -237,   535,  -237,
     374,   293,   494,   314,    31,  -237,  -237,  -237,  -237,   246,
     302,  -237,  -237,   535,  -237,   535,   177,  -237,   -10,  -237,
    -237,  -237,   535,   300,   301,  -237,  -237,   236,  -237,  -237,
    -237,  -237,   177,  -237,   535,   535,  -237,  -237,  -237,  -237
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,     0,   113,   114,     0,     0,   115,
       0,     0,     0,     0,    44,    25,    26,    29,    27,     0,
       0,     0,     0,     0,   146,   147,   148,     7,     5,     8,
      33,    15,    20,    21,    22,    23,    24,     0,    13,    14,
      12,    38,    32,    51,    39,    52,    48,    50,    70,    72,
      74,    77,    78,    91,    93,    95,    97,   101,   105,     0,
     111,   116,   160,   118,     9,   156,   157,   158,   159,   203,
       0,   161,    16,   207,   208,    17,    18,    19,     0,     0,
      76,   179,   178,     0,   174,    35,   141,   154,    52,     0,
       0,    47,   144,     0,     0,   149,   150,   235,     0,   120,
     219,   220,     0,     0,   209,   223,   225,     0,    45,    66,
      68,    30,    28,   238,   237,   240,   241,     0,     0,    10,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,     0,    49,     0,     0,     0,
       0,    89,    90,    82,    83,    84,    88,    86,    85,    87,
       0,     0,     0,     0,    99,   100,     0,   103,   104,     0,
     107,   108,   109,   110,     0,   112,     0,     0,     0,   119,
     122,   206,   205,   204,     0,     0,     0,     0,   175,     0,
     155,   142,   143,     0,   145,   151,   200,     0,     0,   121,
     221,   222,     0,     0,     0,   224,     0,    46,    67,     0,
       0,     0,     0,     0,     0,    11,    34,    42,    43,    40,
      41,    37,    53,     0,    73,    75,    80,    81,    79,    92,
      94,    96,    98,   102,   106,   117,   125,     0,   135,   134,
       0,   130,   132,   124,   123,   182,   192,     0,   198,     0,
     186,   184,   194,   196,     0,     0,     0,   170,   164,     0,
     177,   176,     0,   152,     0,     0,     0,   236,     0,   216,
     231,   218,   229,     0,     0,   210,   212,   227,   226,    69,
      31,   239,   242,   166,     0,     0,   127,     0,   137,     0,
     126,   131,   190,   192,   189,     0,   183,     0,     0,   180,
       0,     0,   162,     0,     0,     0,   201,     0,     0,     0,
     230,     0,   213,   215,     0,     0,     0,     0,     0,    71,
     136,   133,     0,   187,   199,   185,   195,   197,     0,   168,
       0,     0,     0,   172,   139,   153,   202,   217,   232,   233,
       0,   211,   228,     0,   128,     0,     0,   193,     0,   181,
     171,   169,     0,     0,     0,   140,   138,     0,   214,   167,
     129,   191,     0,   163,     0,     0,   234,   188,   165,   173
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -237,  -237,  -237,  -237,  -237,  -171,    -3,   198,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    23,
      -5,    20,    14,  -237,  -237,   -22,  -237,    -6,  -140,   182,
       0,  -237,  -237,     6,   175,   180,   181,  -237,   166,  -237,
     164,  -237,   -45,  -237,  -237,  -237,   228,  -149,   254,   -23,
    -237,    40,  -237,     4,   318,  -237,  -237,  -237,   326,  -237,
    -237,  -237,  -237,  -237,  -195,  -237,    -1,  -237,   263,  -237,
    -237,    44,    52,  -237,  -170,  -236,   266,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -191,  -237,   -20,  -237,   317,
    -237,  -237
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    37,     3,    38,   257,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,   145,   118,   119,    57,    58,    59,
      60,    61,   160,    62,    63,    64,    65,   166,    66,   169,
      67,   174,    68,    69,    70,    71,   179,   180,    72,   240,
     241,   242,   355,   190,    73,   104,   105,   106,    99,    74,
      75,   302,    76,   330,   258,    77,    93,    94,    78,   185,
     249,   250,   292,   251,   347,   253,    79,    80,    81,    82,
      83,    84,   112,   114,   115,   271,   272,   108,    85,   124,
      86,    87
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      39,    89,   113,   116,    91,    91,   122,   223,    90,    95,
     293,   294,   103,   276,   252,    92,    92,   283,   120,   286,
     268,   121,   120,   101,   175,   126,   127,    98,    98,   269,
     244,     6,     5,    97,    97,   346,     8,     4,   362,   148,
     198,    10,   196,   215,   189,   197,    13,   254,    14,   274,
     244,   311,   200,    15,    16,    17,     8,    88,   275,   299,
     312,   198,   164,   165,   246,    18,    13,    96,    14,   198,
      13,    19,    14,    15,    16,    17,   248,   308,   110,   248,
     206,   201,   313,   314,   247,    18,   202,   255,   131,    18,
     270,    19,   203,    21,    20,    22,    23,    24,    25,    26,
      27,    28,   107,    29,    30,    31,   107,   111,   333,   315,
     361,   207,    33,    21,   167,   168,    34,    35,    36,   270,
     340,   270,   344,   221,   198,   248,   367,   326,   198,   234,
     329,   235,   107,   349,   123,   245,    34,    35,    36,   120,
      34,    35,    36,   246,   150,   177,   151,   152,   359,   225,
     360,   218,   220,   147,   217,   219,   148,   363,   204,   351,
     222,   178,   273,   247,   334,   259,   228,   153,   154,   368,
     369,   239,   238,   129,   266,   155,   156,   157,   158,   331,
     332,   120,   130,   260,    91,   277,   128,   263,   262,   264,
     285,   239,   238,   213,   261,    92,   132,   214,   170,   171,
     146,   149,   279,   280,   248,   282,   172,   239,   238,   161,
     162,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   287,   144,   148,   163,   176,   159,   184,   186,
     173,   288,   187,     8,   188,   189,   192,   191,   193,   194,
     209,   227,   195,    13,   236,    14,   226,   205,   212,   300,
      15,    16,    17,   208,   210,   211,   243,   267,   278,   290,
     281,   289,    18,   296,   291,   295,   248,   298,    19,   297,
     301,   303,   237,   304,   305,   306,   307,   270,   309,   310,
     316,   319,   322,   320,   317,   239,   238,   318,   328,   324,
      21,   336,   327,   337,     5,     6,     7,   338,    39,   335,
       8,   339,   341,   343,     9,    10,    11,    12,   342,   345,
      13,   348,    14,    34,    35,    36,   352,    15,    16,    17,
     354,   357,   358,   364,   365,   366,   353,    39,   216,    18,
     224,   321,   232,   233,   181,    19,   229,   199,   356,   109,
     100,   325,   230,   182,   231,   323,   183,   125,     0,     0,
       0,     0,     0,     0,     0,     0,    20,    21,     0,    22,
      23,    24,    25,    26,    27,    28,     0,    29,    30,    31,
      32,     0,     0,     0,    33,     0,     0,     5,     6,     7,
      34,    35,    36,     8,     0,     0,     0,     9,    10,     0,
       0,     0,   350,    13,     0,    14,     0,     0,     0,     8,
      15,    16,    17,     0,     0,     0,     0,     0,     0,    13,
       0,    14,    18,     0,     0,     0,    15,    16,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    18,   102,
       0,     0,     0,     0,    19,     0,     0,     0,     0,    20,
      21,     0,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,     0,     0,    21,    33,     0,     0,
       5,     6,     7,    34,    35,    36,     8,     0,     0,     0,
       9,    10,     0,     0,     0,     0,    13,     0,    14,    34,
      35,    36,     0,    15,    16,    17,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     8,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,     0,    14,     0,     0,     0,     0,
      15,    16,    20,    21,     0,    22,    23,    24,    25,    26,
      27,    28,    18,    29,    30,    31,    32,     0,    19,     6,
      33,     0,     0,     0,     8,     0,    34,    35,    36,    10,
       0,   256,     0,     0,    13,     0,    14,     8,     0,     0,
      21,    15,    16,    17,     0,     0,     0,    13,   265,    14,
       0,     0,     0,    18,    15,    16,    17,     0,     0,    19,
       0,     0,     0,    34,    35,    36,    18,     0,     0,     0,
       0,     0,    19,     0,     0,     0,   237,     0,     0,     0,
       0,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    21,     0,     0,     8,     0,     0,
       0,     0,     0,     0,    34,    35,    36,    13,   284,    14,
       8,     0,     0,     0,    15,    16,    17,    34,    35,    36,
      13,     0,    14,     8,     0,     0,    18,    15,    16,    17,
       0,     0,    19,    13,     0,    14,   237,     0,     0,    18,
      15,    16,    17,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    18,     0,    21,     0,     0,     0,    19,     0,
       0,     0,   237,     0,     8,     0,     0,    21,     0,     0,
       0,    24,     0,     0,    13,     0,    14,    34,    35,    36,
      21,    15,    16,    17,     8,     0,     0,     0,     0,     0,
      34,    35,    36,    18,    13,     0,    14,     0,     0,    19,
       0,    15,    16,    34,    35,    36,     0,    13,     0,    14,
      13,     0,    14,    18,    15,    16,    17,    15,    16,    19,
       0,    21,     0,     0,     0,     0,    18,     0,     0,    18,
       0,     0,    19,     0,     0,    19,     0,     0,     0,     0,
       0,    21,     0,   117,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,    21,     0,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
      34,    35,    36
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,    22,    23,     9,    10,    28,   147,     8,    10,
     246,   247,    18,   204,   184,     9,    10,   212,    24,   214,
      19,    27,    28,    17,    69,    31,    32,    13,    14,    28,
     179,     4,     3,    13,    14,    48,     9,     0,    48,     8,
      35,    14,    16,    16,    13,    19,    19,    23,    21,    19,
     199,    19,    35,    26,    27,    28,     9,    89,    28,   254,
      28,    35,    46,    47,    28,    38,    19,    20,    21,    35,
      19,    44,    21,    26,    27,    28,    89,   268,    35,    89,
      75,    64,   273,   274,    48,    38,    69,    63,    34,    38,
      89,    44,   112,    66,    65,    68,    69,    70,    71,    72,
      73,    74,    89,    76,    77,    78,    89,    64,   303,    75,
     346,   117,    83,    66,    26,    27,    89,    90,    91,    89,
     311,    89,   317,   145,    35,    89,   362,   297,    35,   174,
     301,   176,    89,   328,    89,    20,    89,    90,    91,   145,
      89,    90,    91,    28,     9,    19,    11,    12,   343,   149,
     345,   131,   132,     5,   131,   132,     8,   352,    69,   330,
     146,    35,    69,    48,   304,   187,   160,    32,    33,   364,
     365,   177,   177,    16,   197,    40,    41,    42,    43,     6,
       7,   187,    25,   188,   189,   205,    89,   193,   189,   195,
     213,   197,   197,    19,   188,   189,    34,    23,    28,    29,
      24,    10,   208,   209,    89,   211,    36,   213,   213,    30,
      45,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,     6,    61,     8,    31,    48,    92,    19,    23,
      60,   237,    11,     9,    24,    13,    22,    20,    23,    39,
      68,     9,    24,    19,    20,    21,    11,    24,    23,   255,
      26,    27,    28,    24,    24,    24,    89,    89,    89,    20,
      89,    34,    38,    20,    24,    23,    89,    34,    44,    24,
      17,    23,    48,    11,    23,    16,    20,    89,    75,    24,
       6,   287,    24,   289,    23,   291,   291,    20,    23,   295,
      66,    16,   298,    20,     3,     4,     5,    89,   301,   305,
       9,    89,    20,    23,    13,    14,    15,    16,    89,    23,
      19,    24,    21,    89,    90,    91,    23,    26,    27,    28,
       6,    75,    20,    23,    23,    89,   332,   330,   130,    38,
     148,   291,   166,   169,    80,    44,   161,   109,   334,    21,
      14,   297,   162,    80,   163,   293,    80,    30,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    -1,    -1,    -1,    83,    -1,    -1,     3,     4,     5,
      89,    90,    91,     9,    -1,    -1,    -1,    13,    14,    -1,
      -1,    -1,    18,    19,    -1,    21,    -1,    -1,    -1,     9,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    21,    38,    -1,    -1,    -1,    26,    27,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    -1,    -1,    66,    83,    -1,    -1,
       3,     4,     5,    89,    90,    91,     9,    -1,    -1,    -1,
      13,    14,    -1,    -1,    -1,    -1,    19,    -1,    21,    89,
      90,    91,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    65,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    38,    76,    77,    78,    79,    -1,    44,     4,
      83,    -1,    -1,    -1,     9,    -1,    89,    90,    91,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,     9,    -1,    -1,
      66,    26,    27,    28,    -1,    -1,    -1,    19,    20,    21,
      -1,    -1,    -1,    38,    26,    27,    28,    -1,    -1,    44,
      -1,    -1,    -1,    89,    90,    91,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    66,    -1,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    19,    20,    21,
       9,    -1,    -1,    -1,    26,    27,    28,    89,    90,    91,
      19,    -1,    21,     9,    -1,    -1,    38,    26,    27,    28,
      -1,    -1,    44,    19,    -1,    21,    48,    -1,    -1,    38,
      26,    27,    28,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    66,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,     9,    -1,    -1,    66,    -1,    -1,
      -1,    70,    -1,    -1,    19,    -1,    21,    89,    90,    91,
      66,    26,    27,    28,     9,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    38,    19,    -1,    21,    -1,    -1,    44,
      -1,    26,    27,    89,    90,    91,    -1,    19,    -1,    21,
      19,    -1,    21,    38,    26,    27,    28,    26,    27,    44,
      -1,    66,    -1,    -1,    -1,    -1,    38,    -1,    -1,    38,
      -1,    -1,    44,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,    89,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    66,    -1,    -1,
      -1,    -1,    -1,    -1,    89,    90,    91,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      89,    90,    91
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    94,    95,    97,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    21,    26,    27,    28,    38,    44,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    76,
      77,    78,    79,    83,    89,    90,    91,    96,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,   116,   120,   121,   122,
     123,   124,   126,   127,   128,   129,   131,   133,   135,   136,
     137,   138,   141,   147,   152,   153,   155,   158,   161,   169,
     170,   171,   172,   173,   174,   181,   183,   184,    89,   120,
     123,   113,   126,   159,   160,   159,    20,   114,   115,   151,
     151,   126,    39,   120,   148,   149,   150,    89,   180,   147,
      35,    64,   175,   180,   176,   177,   180,    68,   118,   119,
     120,   120,   118,    89,   182,   182,   120,   120,    89,    16,
      25,    34,    34,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    61,   117,    24,     5,     8,    10,
       9,    11,    12,    32,    33,    40,    41,    42,    43,    92,
     125,    30,    45,    31,    46,    47,   130,    26,    27,   132,
      28,    29,    36,    60,   134,   135,    48,    19,    35,   139,
     140,   141,   161,   169,    19,   162,    23,    11,    24,    13,
     146,    20,    22,    23,    39,    24,    16,    19,    35,   139,
      35,    64,    69,   180,    69,    24,    75,   120,    24,    68,
      24,    24,    23,    19,    23,    16,   100,   112,   114,   112,
     114,   118,   115,   121,   122,   123,    11,     9,   126,   127,
     128,   129,   131,   133,   135,   135,    20,    48,   113,   120,
     142,   143,   144,    89,   140,    20,    28,    48,    89,   163,
     164,   166,   167,   168,    23,    63,    16,    99,   157,   118,
     113,   126,   159,   120,   120,    20,   142,    89,    19,    28,
      89,   178,   179,    69,    19,    28,   178,   180,    89,   120,
     120,    89,   120,   157,    20,   142,   157,     6,   120,    34,
      20,    24,   165,   168,   168,    23,    20,    24,    34,   157,
     120,    17,   154,    23,    11,    23,    16,    20,   178,    75,
      24,    19,    28,   178,   178,    75,     6,    23,    20,   120,
     120,   144,    24,   165,   120,   164,   167,   120,    23,    98,
     156,     6,     7,   157,   121,   120,    16,    20,    89,    89,
     178,    20,    89,    23,   157,    23,    48,   167,    24,   157,
      18,    98,    23,   120,     6,   145,   146,    75,    20,   157,
     157,   168,    48,   157,    23,    23,    89,   168,   157,   157
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
     142,   142,   143,   143,   144,   144,   144,   144,   145,   146,
     146,   147,   147,   147,   147,   147,   147,   147,   147,   148,
     149,   149,   150,   150,   151,   151,   152,   152,   152,   152,
     152,   152,   153,   153,   154,   154,   155,   155,   156,   156,
     157,   157,   158,   158,   159,   159,   160,   160,   160,   160,
     161,   161,   162,   162,   163,   163,   163,   164,   164,   164,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     169,   169,   169,   170,   170,   171,   171,   172,   172,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   175,   176,   176,   177,   177,   177,   177,   178,
     178,   179,   179,   179,   179,   180,   180,   181,   182,   182,
     183,   184,   184
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
       1,     2,     1,     3,     1,     1,     3,     2,     1,     4,
       5,     2,     3,     3,     2,     3,     1,     1,     1,     1,
       1,     2,     3,     5,     1,     2,     1,     1,     1,     1,
       1,     1,     5,     8,     0,     5,     4,     7,     1,     2,
       1,     4,     6,     9,     1,     2,     3,     3,     1,     1,
       5,     7,     2,     3,     1,     3,     1,     3,     6,     2,
       2,     5,     0,     3,     1,     3,     1,     3,     1,     3,
       3,     5,     6,     1,     2,     2,     2,     1,     1,     2,
       4,     6,     4,     5,     7,     5,     4,     6,     4,     1,
       1,     2,     2,     1,     2,     1,     3,     3,     5,     1,
       2,     1,     3,     3,     5,     1,     3,     2,     1,     3,
       2,     2,     4
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
  "classdef", "arglist", "arglist_seq", "argument", "comp_iter",
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
     846,   847,   857,   862,   884,   885,   886,   890,   910,   916,
     917,   945,   951,   958,   966,   970,   975,   976,   977,   996,
    1004,  1005,  1012,  1016,  1043,  1044,  1052,  1053,  1054,  1055,
    1056,  1057,  1065,  1070,  1079,  1084,  1095,  1099,  1125,  1129,
    1138,  1142,  1151,  1155,  1164,  1165,  1175,  1181,  1186,  1187,
    1193,  1198,  1208,  1212,  1252,  1259,  1266,  1275,  1282,  1290,
    1296,  1304,  1317,  1321,  1332,  1336,  1344,  1348,  1361,  1368,
    1382,  1386,  1390,  1399,  1400,  1409,  1413,  1421,  1421,  1426,
    1446,  1450,  1454,  1458,  1462,  1466,  1470,  1474,  1478,  1489,
    1494,  1499,  1504,  1516,  1517,  1522,  1526,  1530,  1534,  1547,
    1548,  1552,  1556,  1560,  1564,  1576,  1577,  1590,  1598,  1599,
    1609,  1618,  1622
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

