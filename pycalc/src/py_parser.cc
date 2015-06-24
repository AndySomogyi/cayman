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

      case 141: // subscriptlist


        { yyoutput << (yysym.value); }

        break;

      case 142: // subscript_seq


        { yyoutput << (yysym.value); }

        break;

      case 143: // subscript


        { yyoutput << (yysym.value); }

        break;

      case 144: // sliceop


        { yyoutput << (yysym.value); }

        break;

      case 145: // classdef


        { yyoutput << (yysym.value); }

        break;

      case 146: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 147: // argument_seq


        { yyoutput << (yysym.value); }

        break;

      case 148: // argument


        { yyoutput << (yysym.value); }

        break;

      case 149: // comp_iter


        { yyoutput << (yysym.value); }

        break;

      case 150: // comp_for


        { yyoutput << (yysym.value); }

        break;

      case 151: // atom


        { yyoutput << (yysym.value); }

        break;

      case 152: // str


        { yyoutput << (yysym.value); }

        break;

      case 153: // dictorsetmaker


        { yyoutput << (yysym.value); }

        break;

      case 154: // dict


        { yyoutput << (yysym.value); }

        break;

      case 155: // dict_seq


        { yyoutput << (yysym.value); }

        break;

      case 156: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 157: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 158: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 159: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 160: // while_stmt


        { yyoutput << (yysym.value); }

        break;

      case 161: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 162: // try_stmt


        { yyoutput << (yysym.value); }

        break;

      case 163: // except_clause_seq


        { yyoutput << (yysym.value); }

        break;

      case 164: // except_clause


        { yyoutput << (yysym.value); }

        break;

      case 165: // with_stmt


        { yyoutput << (yysym.value); }

        break;

      case 166: // with_item_seq


        { yyoutput << (yysym.value); }

        break;

      case 167: // with_item


        { yyoutput << (yysym.value); }

        break;

      case 168: // suite


        { yyoutput << (yysym.value); }

        break;

      case 169: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 170: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 171: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 172: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 173: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 174: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 175: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 176: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 177: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 178: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 179: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 180: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 181: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 182: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 183: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 184: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 185: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 186: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 187: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 188: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 189: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 190: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 191: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 192: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 193: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 194: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 195: // assert_stmt


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
        // trailer: []
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateSubscript(yylhs.location);

    }

    break;

  case 128:

    {
        // trailer: [ subscriptlist ]
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateSubscript(yylhs.location);
    }

    break;

  case 144:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 145:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[4].value), NULL, (yystack_[0].value));
    }

    break;

  case 146:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 147:

    {
        // arglist: argument_seq:
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 148:

    {
        // arglist: argument_seq ","
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 149:

    {
        // arglist:  "*" test
        // AstNode *args1 = NULL, 
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, (yystack_[0].value), NULL); 
    }

    break;

  case 150:

    {
        // arglist: argument_seq "," "*" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), (yystack_[0].value), NULL);
    }

    break;

  case 151:

    {
        // arglist: "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, NULL, (yystack_[0].value));
    }

    break;

  case 152:

    {
        // arglist: argument_seq "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), NULL, (yystack_[0].value));
    }

    break;

  case 153:

    {
        // arglist: argument_seq "," "*" test "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[6].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 154:

    {
        // argument_seq : argument ","
        // create a length 1 tuple containing the arg.
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 155:

    {
        // argument_seq: argument_seq argument
        // add argument to the seq
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 158:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 162:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 163:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 164:

    {
        // atom: |"[" testlist_comp "]"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 165:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location);
    }

    break;

  case 166:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 170:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::True);
    }

    break;

  case 171:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::False);
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::None);
    }

    break;

  case 174:

    {
        Str *s1 = dynamic_cast<Str*>((yystack_[1].value));
        assert(s1);
        Str *s2 = dynamic_cast<Str*>((yystack_[0].value));
        assert(s2);
        s1->s += s2->s;
        (yylhs.value) = s1;
    }

    break;

  case 177:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 178:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 179:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 190:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 191:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 192:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 193:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 194:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 195:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 196:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 197:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 212:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 213:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 214:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 215:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 217:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 218:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 219:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 222:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 223:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 224:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 225:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 226:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 227:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 228:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 229:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 230:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 231:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 232:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 233:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 234:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 235:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 236:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 237:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 238:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 239:

    {
        // tfpdef_test : tfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 240:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 241:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 242:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 243:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 244:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 246:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 247:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 248:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 251:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 252:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 253:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 254:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 255:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 256:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 257:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 258:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 259:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 260:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 261:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 262:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 263:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 264:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 267:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 268:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 269:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 270:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 273:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 274:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 275:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 276:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 278:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 279:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 281:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 282:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 283:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 284:

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


  const short int py_parser::yypact_ninf_ = -283;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -283,    41,  -283,    43,  -283,   -29,  -283,   958,   958,   971,
     971,  -283,  -283,   642,   787,  -283,  -283,   984,   800,  -283,
     -10,   251,    -3,   -10,   866,  -283,  -283,   958,   958,     9,
       9,   958,   958,  -283,  -283,  -283,    21,    67,   958,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,    58,  -283,  -283,  -283,   124,  -283,  -283,   445,
    -283,   137,  -283,   143,   155,  -283,   223,   140,   135,   160,
     132,   147,   148,  -283,   984,  -283,   141,  -283,   128,   102,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,    62,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,   182,   180,  -283,  -283,
     140,   206,   197,  -283,  -283,  -283,   212,   203,   208,   140,
    -283,   218,   194,  -283,   219,  -283,   127,   128,  -283,  -283,
       4,    19,  -283,   220,     7,   958,  -283,   221,  -283,   174,
    -283,  -283,   222,   222,   225,   229,   116,   210,   178,   162,
    -283,  -283,   537,   708,   708,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,   958,   787,   958,
     958,   958,   247,  -283,   250,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,   984,   984,   984,   984,  -283,  -283,   984,  -283,
    -283,   984,  -283,  -283,  -283,  -283,   984,  -283,   984,   550,
     328,   171,   128,  -283,  -283,  -283,  -283,  -283,    52,    26,
     210,   958,   971,   971,  -283,  -283,  -283,   958,  -283,   958,
    -283,   616,   172,   128,  -283,  -283,    15,   103,    16,   -10,
     173,  -283,   958,   958,   179,   958,   210,   629,   210,   252,
    -283,   183,   984,   210,   958,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,   158,   155,  -283,  -283,  -283,   140,   135,
     160,   132,   147,   148,  -283,  -283,  -283,   958,   958,    50,
     253,   261,  -283,  -283,   879,   248,   255,   269,  -283,  -283,
    -283,  -283,   186,   186,   271,   275,  -283,   272,  -283,   263,
     210,   958,  -283,   279,  -283,   140,   287,  -283,   280,   288,
     286,  -283,   224,  -283,   232,  -283,   284,    47,   224,  -283,
    -283,    20,  -283,  -283,  -283,  -283,  -283,   304,   289,   296,
    -283,   449,   958,    44,   297,   140,  -283,  -283,   958,  -283,
    -283,   958,  -283,  -283,   721,   958,   299,  -283,   879,  -283,
     892,   295,  -283,  -283,   958,  -283,     5,   958,  -283,   301,
     181,   210,   958,   958,  -283,   309,   306,   239,   240,   224,
    -283,  -283,   314,   246,   315,   210,   316,  -283,   360,   268,
     321,   322,   323,   210,  -283,  -283,   958,   958,  -283,  -283,
    -283,   299,  -283,  -283,   -12,   324,  -283,  -283,  -283,  -283,
     210,   329,   958,   347,    83,  -283,  -283,  -283,  -283,   282,
     338,  -283,  -283,   210,  -283,   210,  -283,  -283,   273,   210,
     210,   210,  -283,   337,  -283,  -283,   186,  -283,   -11,  -283,
     210,   344,   345,  -283,  -283,   281,  -283,  -283,  -283,  -283,
     291,  -283,  -283,   332,  -283,   186,  -283,   210,   210,  -283,
     348,   958,  -283,  -283,  -283,   210,  -283,  -283
  };

  const unsigned short int
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,     0,   113,   114,     0,     0,   115,
       0,     0,     0,     0,    44,    25,    26,    29,    27,     0,
       0,     0,     0,   171,   172,   170,     0,     0,     0,   167,
     168,   173,     7,     5,     8,    33,    15,    20,    21,    22,
      23,    24,     0,    13,    14,    12,    38,    32,    51,    39,
      52,    48,    50,    70,    72,    74,    77,    78,    91,    93,
      95,    97,   101,   105,     0,   111,   116,   188,   118,   169,
       9,   182,   183,   185,   186,   184,   187,   245,     0,   189,
      16,   249,   250,    17,    18,    19,     0,     0,    76,   221,
     220,     0,   216,    35,   162,   180,    52,     0,     0,    47,
     165,     0,     0,   175,   176,   277,     0,   120,   261,   262,
       0,     0,   251,   265,   267,     0,    45,    66,    68,    30,
      28,   280,   279,   282,   283,     0,     0,     0,   210,     0,
     208,    10,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,     0,    49,     0,
       0,     0,     0,    89,    90,    82,    83,    84,    88,    86,
      85,    87,     0,     0,     0,     0,    99,   100,     0,   103,
     104,     0,   107,   108,   109,   110,     0,   112,     0,     0,
       0,     0,   119,   122,   174,   248,   247,   246,     0,     0,
       0,     0,   217,     0,   181,   163,   164,     0,   166,   177,
     242,     0,     0,   121,   263,   264,     0,     0,     0,   266,
       0,    46,    67,     0,     0,     0,     0,     0,     0,     0,
     212,     0,     0,     0,     0,    11,    34,    42,    43,    40,
      41,    37,    53,     0,    73,    75,    80,    81,    79,    92,
      94,    96,    98,   102,   106,   117,   125,     0,     0,   156,
       0,   147,   154,   127,   134,   133,     0,   129,   131,   124,
     123,   224,   234,     0,   240,     0,   228,   226,   236,   238,
       0,     0,   192,     0,   219,   218,     0,   178,     0,     0,
       0,   278,     0,   258,   273,   260,   271,     0,     0,   252,
     254,   269,   268,    69,    31,   281,   284,   194,     0,     0,
     144,     0,   204,   198,     0,   211,   207,   209,     0,   149,
     151,     0,   157,   126,   148,   142,   136,   135,   138,   128,
     130,   232,   234,   231,     0,   225,     0,     0,   222,     0,
     190,     0,     0,     0,   243,     0,     0,     0,   272,     0,
     255,   257,     0,     0,     0,     0,     0,   196,     0,   205,
       0,     0,     0,     0,    71,   158,     0,     0,   155,   143,
     137,   140,   139,   132,     0,   229,   241,   227,   237,   239,
       0,     0,     0,   214,   160,   179,   244,   259,   274,   275,
       0,   253,   270,     0,   145,     0,   213,   197,     0,     0,
       0,     0,   202,   150,   152,   141,     0,   235,     0,   223,
       0,     0,     0,   161,   159,     0,   256,   195,   146,   206,
     199,   201,   203,     0,   233,     0,   191,     0,     0,   276,
       0,     0,   230,   193,   215,     0,   153,   200
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -283,  -283,  -283,  -283,  -283,  -282,    -2,   235,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,    66,
      -6,    13,     1,  -283,  -283,   -20,  -283,    -7,  -152,   230,
       8,  -283,  -283,    -4,   209,   211,   214,  -283,   205,  -283,
     215,  -283,   -46,  -283,  -283,  -283,   267,  -107,  -283,  -283,
      61,  -227,   305,  -160,  -283,    68,  -283,  -229,   374,  -283,
    -283,  -283,  -283,   383,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,    86,  -283,  -283,   166,  -188,  -283,    -8,  -283,   313,
    -283,  -283,    69,    70,  -283,  -176,  -254,   318,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -195,  -283,   -13,  -283,
     373,  -283,  -283
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    42,     3,    43,   230,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   157,   126,   127,    62,    63,    64,
      65,    66,   172,    67,    68,    69,    70,   178,    71,   181,
      72,   186,    73,    74,    75,    76,   192,   193,   266,   267,
     268,   327,    77,   260,   261,   262,   413,   204,    78,    79,
     112,   113,   114,   107,    80,    81,   340,    82,   358,    83,
     313,   314,    84,   139,   140,   231,    85,   101,   102,    86,
     199,   275,   276,   331,   277,   407,   279,    87,    88,    89,
      90,    91,    92,   120,   122,   123,   295,   296,   116,    93,
     132,    94,    95
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      97,    44,   103,    99,    99,   100,   100,   243,   130,   121,
     124,   111,   282,   109,   106,   106,    98,   128,   332,   333,
     129,   128,   278,   300,   134,   135,   105,   105,   187,   357,
     322,   138,   118,   272,   292,   298,   406,   425,   307,   214,
     310,     4,   212,   293,   299,   316,     5,     6,     7,   280,
     360,   290,     8,   273,   212,   212,     9,    10,    11,    12,
      96,   119,    13,   203,    14,     5,   349,   309,   215,    15,
      16,    17,   271,   216,   141,   350,   397,   274,   274,   115,
     272,    18,   220,   142,   321,   270,   115,    19,   218,   281,
     137,   160,   338,   115,   274,   353,   203,   346,   131,   370,
     273,   372,   351,   352,   294,   294,   270,   217,    20,    21,
     136,    22,    23,    24,    25,    26,    27,    28,   221,    29,
      30,    31,    32,    33,    34,    35,    36,    20,   312,   361,
      37,    38,    39,    40,    41,   227,   294,   241,   212,   228,
     254,   274,   255,   210,   405,    36,   211,   189,   159,   190,
     128,   160,   424,   383,   390,   414,   238,   240,   143,   242,
     378,   158,   212,   191,   318,   161,   160,   394,   248,   245,
     173,   432,   297,   179,   180,   402,   182,   183,   176,   177,
     174,   283,   259,   265,   184,   233,   234,   381,   382,   188,
     384,   175,   409,   194,   128,   286,   284,    99,   285,   100,
     287,   198,   288,   200,   259,   417,   301,   418,   185,   237,
     239,   420,   421,   422,     6,   303,   304,   201,   306,     8,
     259,   202,   426,   205,    10,   203,   229,   138,   315,    13,
     206,    14,   162,   208,   163,   164,    15,    16,    17,   433,
     434,   207,   223,   209,   219,   222,   224,   437,    18,   225,
     319,   320,   226,   232,    19,   165,   166,   326,   246,   247,
     269,   291,   302,   167,   168,   169,   170,   312,   305,   311,
      13,   328,    14,   323,   339,   274,    21,   329,    22,    23,
      24,    25,    26,    27,    28,   324,    29,    30,    31,    18,
      33,    34,    35,   330,   334,   335,   336,   337,   342,    39,
      40,    41,   341,   343,   344,   359,   345,   347,   348,    44,
     354,   364,   355,   294,   365,   171,   356,   259,   369,   374,
     363,   371,   325,   265,   380,   386,   387,   376,   388,   389,
     379,    33,    34,    35,   391,   392,   385,     8,   393,   395,
      39,    40,    41,   398,   399,   400,   401,    13,   408,    14,
     263,   264,   410,   412,    15,    16,    44,   415,   416,   403,
     404,   423,   419,     5,     6,     7,    18,   427,   428,     8,
     429,   435,    19,     9,    10,   411,   430,   236,   396,    13,
     431,    14,   249,   252,   213,   250,    15,    16,    17,   251,
     244,   373,   368,   195,    21,   117,   253,   108,    18,   362,
     317,   196,   375,   133,    19,   377,   197,     0,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    39,    40,    41,
       0,     0,     0,     0,   436,    20,    21,     0,    22,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,    32,
      33,    34,    35,    36,     0,     0,     0,    37,    38,    39,
      40,    41,     5,     6,     7,     0,     0,     0,     8,     0,
       0,     0,     9,    10,     0,     0,     0,     0,    13,     0,
      14,     0,     0,     0,     0,    15,    16,    17,     0,   144,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    19,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,     0,   156,     0,     0,     0,
       0,     0,     0,     0,    20,    21,     0,    22,    23,    24,
      25,    26,    27,    28,     0,    29,    30,    31,    32,    33,
      34,    35,    36,     0,     0,     0,    37,    38,    39,    40,
      41,     6,     0,     0,     0,     0,     8,     0,     0,     0,
       0,    10,     0,   235,     0,     0,    13,     0,    14,     8,
       0,     0,     0,    15,    16,    17,     0,     0,     0,    13,
     256,    14,     0,     0,     0,    18,    15,    16,   257,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,   258,     0,
       0,     0,     0,    21,     0,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    21,    33,    34,    35,
       0,     0,     0,     0,     0,     8,    39,    40,    41,     0,
      33,    34,    35,     0,     0,    13,   289,    14,     8,    39,
      40,    41,    15,    16,   257,     0,     0,     0,    13,   308,
      14,     8,     0,     0,    18,    15,    16,   257,     0,     0,
      19,    13,   104,    14,   258,     0,     0,    18,    15,    16,
      17,     0,     0,    19,     0,     0,     0,   258,     0,     0,
      18,     0,    21,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    21,    33,
      34,    35,     0,     0,     0,     0,     0,     8,    39,    40,
      41,     0,    33,    34,    35,     0,     0,    13,     0,    14,
       8,    39,    40,    41,    15,    16,    17,     0,     0,     0,
      13,     0,    14,     0,     0,     0,    18,    15,    16,   366,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,   367,
       0,     0,     0,     0,    21,     0,     0,     0,    24,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    33,    34,
      35,     0,     0,     0,     0,     0,     8,    39,    40,    41,
       0,    33,    34,    35,     0,     0,    13,     0,    14,     8,
      39,    40,    41,    15,    16,    17,     0,     0,     0,    13,
       0,    14,     0,     0,     0,    18,    15,    16,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    18,   110,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    33,    34,    35,
       0,     0,     0,     0,     0,     8,    39,    40,    41,     0,
      33,    34,    35,     0,     0,    13,     0,    14,     8,    39,
      40,    41,    15,    16,     0,     0,     0,     0,    13,     0,
      14,     8,   325,     0,    18,    15,    16,     0,     0,     0,
      19,    13,     0,    14,     0,   264,     0,    18,    15,    16,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      18,     0,    21,     0,   125,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    39,    40,    41,    21,    33,
      34,    35,     0,     0,     0,     0,     0,     8,    39,    40,
      41,     0,    33,    34,    35,     0,     0,    13,     0,    14,
       0,    39,    40,    41,    15,    16,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,    18,    15,    16,    17,
       0,     0,    19,    13,     0,    14,     0,     0,     0,    18,
      15,    16,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    18,     0,    21,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,    21,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    39,    40,    41,
      21,    33,    34,    35,     0,     0,     0,     0,     0,     0,
      39,    40,    41,     0,    33,    34,    35,     0,     0,     0,
       0,     0,     0,    39,    40,    41
  };

  const short int
  py_parser::yycheck_[] =
  {
       7,     3,    10,     9,    10,     9,    10,   159,    28,    22,
      23,    18,   200,    17,    13,    14,     8,    24,   272,   273,
      27,    28,   198,   218,    31,    32,    13,    14,    74,   311,
     259,    38,    35,    28,    19,    19,    48,    48,   226,    35,
     228,     0,    35,    28,    28,   233,     3,     4,     5,    23,
       6,   211,     9,    48,    35,    35,    13,    14,    15,    16,
      89,    64,    19,    13,    21,     3,    19,   227,    64,    26,
      27,    28,    20,    69,    16,    28,   358,    89,    89,    89,
      28,    38,    75,    25,    34,   192,    89,    44,    69,    63,
      23,     8,   280,    89,    89,    75,    13,   292,    89,   326,
      48,   328,   297,   298,    89,    89,   213,   120,    65,    66,
      89,    68,    69,    70,    71,    72,    73,    74,   125,    76,
      77,    78,    79,    80,    81,    82,    83,    65,    84,    85,
      87,    88,    89,    90,    91,    19,    89,   157,    35,    23,
     186,    89,   188,    16,   371,    83,    19,    19,     5,    21,
     157,     8,   406,   341,   349,   384,   143,   144,    34,   158,
     336,    24,    35,    35,     6,    10,     8,   355,   172,   161,
      30,   425,    69,    26,    27,   363,    28,    29,    46,    47,
      45,   201,   189,   190,    36,    23,    24,     6,     7,    48,
     342,    31,   380,    91,   201,   203,   202,   203,   202,   203,
     207,    19,   209,    23,   211,   393,   219,   395,    60,   143,
     144,   399,   400,   401,     4,   222,   223,    11,   225,     9,
     227,    24,   410,    20,    14,    13,    16,   234,   232,    19,
      22,    21,     9,    39,    11,    12,    26,    27,    28,   427,
     428,    23,    68,    24,    24,    24,    24,   435,    38,    24,
     257,   258,    23,    75,    44,    32,    33,   264,    11,     9,
      89,    89,    89,    40,    41,    42,    43,    84,    89,    17,
      19,    23,    21,    20,   281,    89,    66,    22,    68,    69,
      70,    71,    72,    73,    74,    24,    76,    77,    78,    38,
      80,    81,    82,    24,    23,    20,    24,    34,    11,    89,
      90,    91,    23,    23,    16,   312,    20,    75,    24,   311,
       6,   318,    23,    89,   321,    92,    20,   324,   325,    24,
      23,   328,    23,   330,    23,    16,    20,   334,    89,    89,
     337,    80,    81,    82,    20,    89,   343,     9,    23,    23,
      89,    90,    91,    75,    23,    23,    23,    19,    24,    21,
      22,    23,    23,     6,    26,    27,   358,    75,    20,   366,
     367,    24,    89,     3,     4,     5,    38,    23,    23,     9,
      89,    23,    44,    13,    14,   382,    85,   142,    18,    19,
      48,    21,   173,   178,   117,   174,    26,    27,    28,   175,
     160,   330,   324,    88,    66,    21,   181,    14,    38,   313,
     234,    88,   332,    30,    44,   336,    88,    -1,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      -1,    -1,    -1,    -1,   431,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      80,    81,    82,    83,    -1,    -1,    -1,    87,    88,    89,
      90,    91,     3,     4,     5,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    13,    14,    -1,    -1,    -1,    -1,    19,    -1,
      21,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    34,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,    70,
      71,    72,    73,    74,    -1,    76,    77,    78,    79,    80,
      81,    82,    83,    -1,    -1,    -1,    87,    88,    89,    90,
      91,     4,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,     9,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    38,    26,    27,    28,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    66,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,     9,    89,    90,    91,    -1,
      80,    81,    82,    -1,    -1,    19,    20,    21,     9,    89,
      90,    91,    26,    27,    28,    -1,    -1,    -1,    19,    20,
      21,     9,    -1,    -1,    38,    26,    27,    28,    -1,    -1,
      44,    19,    20,    21,    48,    -1,    -1,    38,    26,    27,
      28,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,
      38,    -1,    66,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    66,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,     9,    89,    90,
      91,    -1,    80,    81,    82,    -1,    -1,    19,    -1,    21,
       9,    89,    90,    91,    26,    27,    28,    -1,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    38,    26,    27,    28,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    70,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,     9,    89,    90,    91,
      -1,    80,    81,    82,    -1,    -1,    19,    -1,    21,     9,
      89,    90,    91,    26,    27,    28,    -1,    -1,    -1,    19,
      -1,    21,    -1,    -1,    -1,    38,    26,    27,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,     9,    89,    90,    91,    -1,
      80,    81,    82,    -1,    -1,    19,    -1,    21,     9,    89,
      90,    91,    26,    27,    -1,    -1,    -1,    -1,    19,    -1,
      21,     9,    23,    -1,    38,    26,    27,    -1,    -1,    -1,
      44,    19,    -1,    21,    -1,    23,    -1,    38,    26,    27,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    66,    -1,    68,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    80,    81,    82,    -1,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    66,    80,
      81,    82,    -1,    -1,    -1,    -1,    -1,     9,    89,    90,
      91,    -1,    80,    81,    82,    -1,    -1,    19,    -1,    21,
      -1,    89,    90,    91,    26,    27,    -1,    -1,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    38,    26,    27,    28,
      -1,    -1,    44,    19,    -1,    21,    -1,    -1,    -1,    38,
      26,    27,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    66,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    80,    81,
      82,    -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,
      66,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,    -1,    89,    90,    91
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    94,    95,    97,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    21,    26,    27,    28,    38,    44,
      65,    66,    68,    69,    70,    71,    72,    73,    74,    76,
      77,    78,    79,    80,    81,    82,    83,    87,    88,    89,
      90,    91,    96,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   120,   121,   122,   123,   124,   126,   127,   128,
     129,   131,   133,   135,   136,   137,   138,   145,   151,   152,
     157,   158,   160,   162,   165,   169,   172,   180,   181,   182,
     183,   184,   185,   192,   194,   195,    89,   120,   123,   113,
     126,   170,   171,   170,    20,   114,   115,   156,   156,   126,
      39,   120,   153,   154,   155,    89,   191,   151,    35,    64,
     186,   191,   187,   188,   191,    68,   118,   119,   120,   120,
     118,    89,   193,   193,   120,   120,    89,    23,   120,   166,
     167,    16,    25,    34,    34,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    61,   117,    24,     5,
       8,    10,     9,    11,    12,    32,    33,    40,    41,    42,
      43,    92,   125,    30,    45,    31,    46,    47,   130,    26,
      27,   132,    28,    29,    36,    60,   134,   135,    48,    19,
      21,    35,   139,   140,    91,   145,   172,   180,    19,   173,
      23,    11,    24,    13,   150,    20,    22,    23,    39,    24,
      16,    19,    35,   139,    35,    64,    69,   191,    69,    24,
      75,   120,    24,    68,    24,    24,    23,    19,    23,    16,
      99,   168,    75,    23,    24,    16,   100,   112,   114,   112,
     114,   118,   115,   121,   122,   123,    11,     9,   126,   127,
     128,   129,   131,   133,   135,   135,    20,    28,    48,   120,
     146,   147,   148,    22,    23,   120,   141,   142,   143,    89,
     140,    20,    28,    48,    89,   174,   175,   177,   178,   179,
      23,    63,   168,   118,   113,   126,   170,   120,   120,    20,
     146,    89,    19,    28,    89,   189,   190,    69,    19,    28,
     189,   191,    89,   120,   120,    89,   120,   168,    20,   146,
     168,    17,    84,   163,   164,   126,   168,   167,     6,   120,
     120,    34,   150,    20,    24,    23,   120,   144,    23,    22,
      24,   176,   179,   179,    23,    20,    24,    34,   168,   120,
     159,    23,    11,    23,    16,    20,   189,    75,    24,    19,
      28,   189,   189,    75,     6,    23,    20,    98,   161,   120,
       6,    85,   164,    23,   120,   120,    28,    48,   148,   120,
     144,   120,   144,   143,    24,   176,   120,   175,   178,   120,
      23,     6,     7,   168,   121,   120,    16,    20,    89,    89,
     189,    20,    89,    23,   168,    23,    18,    98,    75,    23,
      23,    23,   168,   120,   120,   144,    48,   178,    24,   168,
      23,   120,     6,   149,   150,    75,    20,   168,   168,    89,
     168,   168,   168,    24,   179,    48,   168,    23,    23,    89,
      85,    48,   179,   168,   168,    23,   120,   168
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
     138,   138,   139,   139,   140,   140,   140,   140,   140,   141,
     141,   142,   142,   143,   143,   143,   143,   143,   143,   143,
     143,   143,   144,   144,   145,   145,   145,   146,   146,   146,
     146,   146,   146,   146,   147,   147,   148,   148,   148,   149,
     150,   150,   151,   151,   151,   151,   151,   151,   151,   151,
     151,   151,   151,   152,   152,   153,   154,   154,   155,   155,
     156,   156,   157,   157,   157,   157,   157,   157,   157,   157,
     158,   158,   159,   159,   160,   160,   161,   161,   162,   162,
     162,   162,   163,   163,   164,   164,   164,   165,   166,   166,
     167,   167,   168,   168,   169,   169,   170,   170,   171,   171,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   175,
     175,   175,   175,   175,   176,   176,   177,   177,   178,   178,
     179,   179,   180,   180,   180,   181,   181,   182,   182,   183,
     183,   184,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   186,   186,   186,   186,   187,   187,   188,   188,   188,
     188,   189,   189,   190,   190,   190,   190,   191,   191,   192,
     193,   193,   194,   195,   195
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
       2,     3,     1,     2,     2,     2,     3,     2,     3,     1,
       2,     1,     3,     1,     1,     2,     2,     3,     2,     3,
       3,     4,     1,     2,     4,     6,     7,     1,     2,     2,
       4,     2,     4,     7,     1,     3,     1,     2,     3,     1,
       4,     5,     2,     3,     3,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     1,     2,     3,     5,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     8,     0,     5,     4,     7,     1,     2,     4,     7,
      10,     7,     3,     4,     1,     2,     4,     4,     1,     3,
       1,     3,     1,     4,     6,     9,     1,     2,     3,     3,
       1,     1,     5,     7,     2,     3,     1,     3,     1,     3,
       6,     2,     2,     5,     0,     3,     1,     3,     1,     3,
       1,     3,     3,     5,     6,     1,     2,     2,     2,     1,
       1,     2,     4,     6,     4,     5,     7,     5,     4,     6,
       4,     1,     1,     2,     2,     1,     2,     1,     3,     3,
       5,     1,     2,     1,     3,     3,     5,     1,     3,     2,
       1,     3,     2,     2,     4
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
  "subscriptlist", "subscript_seq", "subscript", "sliceop", "classdef",
  "arglist", "argument_seq", "argument", "comp_iter", "comp_for", "atom",
  "str", "dictorsetmaker", "dict", "dict_seq", "testlist_comp",
  "compound_stmt", "if_stmt", "elif_seq", "while_stmt", "stmt_seq",
  "try_stmt", "except_clause_seq", "except_clause", "with_stmt",
  "with_item_seq", "with_item", "suite", "for_stmt", "exprlist",
  "exprlist_seq", "funcdef", "parameters", "typedargslist", "var_args",
  "var_arglist_trailer", "named_args", "tfpdef_test", "tfpdef",
  "decorator", "decorators", "decorated", "import_stmt", "import_name",
  "import_from", "import_dots", "dotted_as_names", "dotted_as_names_seq",
  "import_as_names", "import_as_names_seq", "dotted_name", "global_stmt",
  "name_seq", "nonlocal_stmt", "assert_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   198,   198,   222,   230,   234,   243,   247,   268,   272,
     281,   285,   296,   297,   298,   299,   300,   301,   302,   303,
     308,   308,   308,   308,   308,   313,   321,   330,   334,   343,
     347,   351,   358,   366,   370,   381,   390,   407,   411,   415,
     433,   437,   442,   446,   462,   466,   470,   481,   498,   503,
     514,   514,   519,   524,   536,   536,   536,   536,   536,   536,
     536,   536,   537,   537,   537,   537,   544,   545,   552,   553,
     568,   569,   575,   576,   586,   587,   597,   601,   608,   609,
     622,   626,   630,   631,   632,   633,   634,   635,   636,   637,
     638,   645,   646,   655,   656,   665,   666,   675,   676,   683,
     683,   689,   690,   697,   697,   703,   704,   711,   711,   711,
     711,   717,   718,   725,   725,   725,   731,   732,   741,   742,
     751,   755,   764,   765,   779,   786,   792,   798,   805,   816,
     817,   822,   823,   829,   830,   831,   832,   833,   834,   835,
     836,   837,   842,   843,   850,   854,   858,   879,   885,   893,
     900,   908,   915,   921,   936,   942,   954,   955,   956,   966,
     972,   973,  1001,  1007,  1014,  1022,  1026,  1031,  1032,  1033,
    1034,  1038,  1042,  1049,  1050,  1077,  1085,  1086,  1093,  1097,
    1124,  1125,  1133,  1134,  1135,  1136,  1137,  1138,  1139,  1140,
    1148,  1153,  1162,  1167,  1178,  1182,  1191,  1195,  1212,  1213,
    1214,  1215,  1220,  1221,  1227,  1228,  1229,  1235,  1239,  1240,
    1246,  1247,  1253,  1257,  1266,  1270,  1279,  1280,  1290,  1296,
    1301,  1302,  1308,  1313,  1323,  1327,  1367,  1374,  1381,  1390,
    1397,  1405,  1411,  1419,  1432,  1436,  1447,  1451,  1459,  1463,
    1477,  1484,  1498,  1502,  1506,  1515,  1516,  1525,  1529,  1537,
    1537,  1542,  1562,  1566,  1570,  1574,  1578,  1582,  1586,  1590,
    1594,  1605,  1610,  1615,  1620,  1632,  1633,  1638,  1642,  1646,
    1650,  1663,  1664,  1668,  1672,  1676,  1680,  1692,  1693,  1706,
    1714,  1715,  1725,  1734,  1738
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

