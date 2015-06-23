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

      case 162: // with_stmt


        { yyoutput << (yysym.value); }

        break;

      case 163: // with_item_seq


        { yyoutput << (yysym.value); }

        break;

      case 164: // with_item


        { yyoutput << (yysym.value); }

        break;

      case 165: // suite


        { yyoutput << (yysym.value); }

        break;

      case 166: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 167: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 168: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 169: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 170: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 171: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 172: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 173: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 174: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 175: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 176: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 177: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 178: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 179: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 180: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 181: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 182: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 183: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 184: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 185: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 186: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 187: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 188: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 189: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 190: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 191: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 192: // assert_stmt


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

  case 189:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 190:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 191:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 192:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 193:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 194:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 195:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 196:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 202:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 203:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 204:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 205:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 207:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 208:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 209:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 212:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 213:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 214:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 215:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 216:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 217:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 218:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 219:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 220:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 221:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 222:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 223:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 224:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 225:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 226:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 227:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 228:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 229:

    {
        // tfpdef_test : tfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 230:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 231:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 232:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 233:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 234:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 236:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 237:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 238:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 241:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 242:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 243:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 244:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 245:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 246:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 247:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 248:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 249:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 250:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 251:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 252:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 253:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 254:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 257:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 258:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 259:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 260:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 263:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 264:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 265:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 266:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 268:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 269:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 271:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 272:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 273:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 274:

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


  const short int py_parser::yypact_ninf_ = -259;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -259,    36,  -259,   346,  -259,   -31,  -259,   963,   963,   976,
     976,  -259,  -259,   314,   793,  -259,  -259,   989,   797,  -259,
     -13,    18,    47,   -13,   871,  -259,  -259,   963,   963,     7,
       7,   963,   963,  -259,  -259,  -259,    26,   963,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,    77,  -259,  -259,  -259,    92,  -259,  -259,   203,  -259,
     109,  -259,   153,   130,  -259,    22,   139,   105,   145,   126,
     148,    99,  -259,   989,  -259,   133,  -259,   120,    94,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,    20,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,   168,   165,  -259,  -259,   139,   179,
     174,  -259,  -259,  -259,   187,   183,   185,   139,  -259,   182,
     172,  -259,   196,  -259,   129,   120,  -259,  -259,    55,     6,
    -259,   201,     5,   963,  -259,   210,  -259,   167,  -259,  -259,
     212,   212,   214,   216,   144,   166,   154,  -259,  -259,   518,
     689,   689,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -259,   963,   793,   963,   963,   963,   229,
    -259,   233,  -259,  -259,  -259,  -259,  -259,  -259,  -259,   989,
     989,   989,   989,  -259,  -259,   989,  -259,  -259,   989,  -259,
    -259,  -259,  -259,   989,  -259,   989,    40,   709,   157,   120,
    -259,  -259,  -259,  -259,  -259,    53,     9,   597,   963,   976,
     976,  -259,  -259,  -259,   963,  -259,   963,  -259,   610,   158,
     120,  -259,  -259,    16,    48,    23,   -13,   159,  -259,   963,
     963,   161,   963,   597,   676,   597,   989,   597,   963,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,   162,   130,  -259,
    -259,  -259,   139,   105,   145,   126,   148,    99,  -259,  -259,
    -259,   963,   963,    57,   243,   241,  -259,  -259,   884,   244,
     247,   242,  -259,  -259,  -259,  -259,   191,   191,   249,   269,
    -259,   266,  -259,   257,   597,   963,   275,  -259,  -259,   274,
    -259,   139,   287,  -259,   276,   284,   281,  -259,   213,  -259,
     230,  -259,   280,    24,   213,  -259,  -259,    12,  -259,  -259,
    -259,  -259,  -259,   301,   285,   291,  -259,   139,  -259,  -259,
     963,  -259,  -259,   963,  -259,  -259,   767,   963,   289,  -259,
     884,  -259,   897,   290,  -259,  -259,   963,  -259,    29,   963,
    -259,   293,   435,   177,   597,   963,   963,  -259,   302,   297,
     231,   232,   213,  -259,  -259,   304,   236,   303,   597,   305,
    -259,  -259,   963,   963,  -259,  -259,  -259,   289,  -259,  -259,
     -10,   307,  -259,  -259,  -259,  -259,   597,  -259,   205,   309,
     963,   321,   138,  -259,  -259,  -259,  -259,   261,   317,  -259,
    -259,   597,  -259,   597,   315,  -259,  -259,   191,  -259,    -3,
    -259,  -259,  -259,   597,   320,   324,  -259,  -259,   255,  -259,
    -259,  -259,   300,  -259,   191,  -259,   597,   597,  -259,   963,
    -259,  -259,  -259,  -259
  };

  const unsigned short int
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,     0,   113,   114,     0,     0,   115,
       0,     0,     0,     0,    44,    25,    26,    29,    27,     0,
       0,     0,     0,   171,   172,   170,     0,     0,   167,   168,
     173,     7,     5,     8,    33,    15,    20,    21,    22,    23,
      24,     0,    13,    14,    12,    38,    32,    51,    39,    52,
      48,    50,    70,    72,    74,    77,    78,    91,    93,    95,
      97,   101,   105,     0,   111,   116,   187,   118,   169,     9,
     182,   183,   185,   184,   186,   235,     0,   188,    16,   239,
     240,    17,    18,    19,     0,     0,    76,   211,   210,     0,
     206,    35,   162,   180,    52,     0,     0,    47,   165,     0,
       0,   175,   176,   267,     0,   120,   251,   252,     0,     0,
     241,   255,   257,     0,    45,    66,    68,    30,    28,   270,
     269,   272,   273,     0,     0,   200,     0,   198,    10,     0,
       0,     0,    54,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,     0,    49,     0,     0,     0,     0,
      89,    90,    82,    83,    84,    88,    86,    85,    87,     0,
       0,     0,     0,    99,   100,     0,   103,   104,     0,   107,
     108,   109,   110,     0,   112,     0,     0,     0,     0,   119,
     122,   174,   238,   237,   236,     0,     0,     0,     0,   207,
       0,   181,   163,   164,     0,   166,   177,   232,     0,     0,
     121,   253,   254,     0,     0,     0,   256,     0,    46,    67,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    11,
      34,    42,    43,    40,    41,    37,    53,     0,    73,    75,
      80,    81,    79,    92,    94,    96,    98,   102,   106,   117,
     125,     0,     0,   156,     0,   147,   154,   127,   134,   133,
       0,   129,   131,   124,   123,   214,   224,     0,   230,     0,
     218,   216,   226,   228,     0,     0,     0,   202,   191,     0,
     209,   208,     0,   178,     0,     0,     0,   268,     0,   248,
     263,   250,   261,     0,     0,   242,   244,   259,   258,    69,
      31,   271,   274,   193,     0,     0,   144,   201,   197,   199,
       0,   149,   151,     0,   157,   126,   148,   142,   136,   135,
     138,   128,   130,   222,   224,   221,     0,   215,     0,     0,
     212,     0,     0,   189,     0,     0,     0,   233,     0,     0,
       0,   262,     0,   245,   247,     0,     0,     0,     0,     0,
      71,   158,     0,     0,   155,   143,   137,   140,   139,   132,
       0,   219,   231,   217,   227,   229,     0,   195,     0,     0,
       0,   204,   160,   179,   234,   249,   264,   265,     0,   243,
     260,     0,   145,     0,   150,   152,   141,     0,   225,     0,
     213,   203,   196,     0,     0,     0,   161,   159,     0,   246,
     194,   146,     0,   223,     0,   190,     0,     0,   266,     0,
     220,   192,   205,   153
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -259,  -259,  -259,  -259,  -259,  -258,    -2,   199,  -259,  -259,
    -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,  -259,    87,
      -6,    13,     1,  -259,  -259,   -16,  -259,    -7,  -149,   197,
       2,  -259,  -259,    -4,   186,   193,   181,  -259,   194,  -259,
     190,  -259,   -51,  -259,  -259,  -259,   256,  -118,  -259,  -259,
      35,  -195,   292,  -155,  -259,    54,  -259,  -235,   354,  -259,
    -259,  -259,  -259,   362,  -259,  -259,  -259,  -259,  -259,  -259,
    -259,   149,  -177,  -259,    -8,  -259,   295,  -259,  -259,    51,
      58,  -259,  -176,  -238,   299,  -259,  -259,  -259,  -259,  -259,
    -259,  -259,  -259,  -199,  -259,   -14,  -259,   353,  -259,  -259
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    41,     3,    42,   277,    44,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    60,   154,   124,   125,    61,    62,    63,
      64,    65,   169,    66,    67,    68,    69,   175,    70,   178,
      71,   183,    72,    73,    74,    75,   189,   190,   260,   261,
     262,   319,    76,   254,   255,   256,   396,   201,    77,    78,
     110,   111,   112,   105,    79,    80,   333,    81,   368,    82,
     136,   137,   278,    83,    99,   100,    84,   196,   269,   270,
     323,   271,   388,   273,    85,    86,    87,    88,    89,    90,
     118,   120,   121,   291,   292,   114,    91,   130,    92,    93
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      95,    43,   101,    97,    97,    98,    98,   237,   119,   122,
      96,   109,   128,   107,   104,   104,   296,   126,   314,   272,
     127,   126,   184,     5,   132,   133,   103,   103,   324,   325,
     135,   159,   274,   160,   161,   288,     4,    13,   387,    14,
     209,   209,   294,   342,   289,   404,   303,   209,   306,     8,
     308,   295,   343,   286,   162,   163,    18,   266,    94,    13,
     250,    14,   164,   165,   166,   167,    15,    16,   251,   305,
     200,   264,   275,   265,   367,   215,   113,   267,    18,   268,
     217,   266,   116,   209,    19,    20,   268,   346,   252,   339,
     211,   313,   264,   138,   344,   345,   129,   330,    33,    34,
      35,   267,   139,    36,   214,   290,    21,    38,    39,    40,
     392,   117,   290,   290,   168,   134,   218,   293,   268,   212,
      33,    34,    35,   356,   213,   358,   140,   179,   180,    38,
      39,    40,   248,   155,   249,   181,   113,   397,   235,   186,
     158,   187,   268,   378,   113,   207,   157,   126,   208,   403,
     171,   200,   364,   232,   234,   188,   236,   371,   156,   182,
     239,   157,   386,   224,   209,   242,   410,   225,   310,   170,
     157,   382,   173,   174,   176,   177,   172,   227,   228,   253,
     259,   185,   279,   369,   370,   191,   372,   195,   197,   390,
     198,   126,   282,   280,    97,   281,    98,   283,   199,   284,
     200,   253,   297,   202,   400,   204,   401,   203,     5,     6,
       7,   205,   299,   300,     8,   302,   405,   253,     9,    10,
     206,   135,   307,   391,    13,   216,    14,   231,   233,   411,
     412,    15,    16,    17,   219,   220,   221,   141,   222,   223,
     240,   226,   241,    18,   311,   312,   263,   287,   298,    19,
     301,   318,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   315,   153,   316,   322,   320,   331,   321,
      20,    21,   326,    22,    23,    24,    25,    26,    27,    28,
     268,    29,    30,    31,    32,    33,    34,    35,    36,   327,
     328,   329,   332,    37,    38,    39,    40,   334,   335,   336,
     337,   338,   290,   350,   341,   340,   351,   347,   348,   253,
     355,   349,   317,   357,   360,   259,   366,   375,   374,   362,
     376,   377,   365,     8,   379,   380,   381,   395,   383,   373,
      43,   389,   393,    13,   102,    14,   398,   399,   230,   402,
      15,    16,    17,   406,   408,   384,   385,   407,   409,     5,
       6,     7,    18,   245,   238,     8,   243,   359,    19,     9,
      10,    11,    12,   394,   244,    13,    43,    14,   247,   246,
     354,   210,    15,    16,    17,   115,   106,   309,   192,   363,
      21,   193,   361,   131,    18,   194,     0,     0,     0,     0,
      19,     0,     0,     0,    33,    34,    35,     0,     0,     0,
       0,     0,   413,    38,    39,    40,     0,     0,     0,     0,
       0,    20,    21,     0,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    32,    33,    34,    35,    36,
       0,     0,     0,     0,    37,    38,    39,    40,     5,     6,
       7,     0,     0,     0,     8,     0,     0,     0,     9,    10,
       0,     0,     0,     0,    13,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      20,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,    32,    33,    34,    35,    36,     0,
       0,     0,     6,    37,    38,    39,    40,     8,     0,     0,
       0,     0,    10,     0,   229,     0,     0,    13,     0,    14,
       0,     0,     0,     0,    15,    16,    17,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,     0,    22,    23,    24,    25,
      26,    27,    28,     0,    29,    30,    31,     0,    33,    34,
      35,     6,     0,     0,     0,     0,     8,    38,    39,    40,
       0,    10,     0,   276,     0,     0,    13,     0,    14,     8,
       0,     0,     0,    15,    16,    17,     0,     0,     0,    13,
     285,    14,     0,     0,     0,    18,    15,    16,   251,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,   252,     0,
       0,     0,     0,    21,     0,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    21,    33,    34,    35,
       0,     0,     0,     0,     0,     8,    38,    39,    40,     0,
      33,    34,    35,     0,     0,    13,   304,    14,     8,    38,
      39,    40,    15,    16,   251,     0,     0,     0,    13,     0,
      14,     0,     0,     0,    18,    15,    16,    17,     8,     0,
      19,     0,     0,     0,   252,     0,     0,    18,    13,     0,
      14,   257,   258,    19,     0,    15,    16,     0,     0,     0,
       0,     0,    21,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    19,     0,    21,    33,    34,    35,    24,
       0,     0,     0,     0,     0,    38,    39,    40,     0,    33,
      34,    35,     0,     0,     0,    21,     8,     0,    38,    39,
      40,     0,     0,     0,     0,     0,    13,     0,    14,    33,
      34,    35,     0,    15,    16,   352,     0,     0,    38,    39,
      40,     0,     8,     0,     0,    18,     8,     0,     0,     0,
       0,    19,    13,     0,    14,   353,    13,     0,    14,    15,
      16,    17,     0,    15,    16,     0,     0,     0,     0,     0,
       0,    18,     0,    21,     0,    18,   108,    19,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    33,    34,    35,
       0,     0,     0,     0,     0,     0,    38,    39,    40,    21,
       0,     0,     0,    21,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    33,    34,    35,     0,    33,    34,    35,
       8,     0,    38,    39,    40,     0,    38,    39,    40,     0,
      13,     0,    14,     8,     0,     0,     0,    15,    16,     0,
       0,     0,     0,    13,     0,    14,     8,   317,     0,    18,
      15,    16,     0,     0,     0,    19,    13,     0,    14,     0,
     258,     0,    18,    15,    16,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    18,     0,    21,     0,   123,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
      21,    33,    34,    35,     0,     0,     0,     0,     0,     0,
      38,    39,    40,    21,    33,    34,    35,     0,     0,     0,
       0,     0,     8,    38,    39,    40,     0,    33,    34,    35,
       0,     0,    13,     0,    14,     0,    38,    39,    40,    15,
      16,     0,     0,     0,     0,    13,     0,    14,     0,     0,
       0,    18,    15,    16,    17,     0,     0,    19,    13,     0,
      14,     0,     0,     0,    18,    15,    16,     0,     0,     0,
      19,     0,     0,     0,     0,     0,     0,    18,     0,    21,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,    21,    33,    34,    35,     0,     0,     0,     0,
       0,     0,    38,    39,    40,    21,    33,    34,    35,     0,
       0,     0,     0,     0,     0,    38,    39,    40,     0,    33,
      34,    35,     0,     0,     0,     0,     0,     0,    38,    39,
      40
  };

  const short int
  py_parser::yycheck_[] =
  {
       7,     3,    10,     9,    10,     9,    10,   156,    22,    23,
       8,    18,    28,    17,    13,    14,   215,    24,   253,   195,
      27,    28,    73,     3,    31,    32,    13,    14,   266,   267,
      37,     9,    23,    11,    12,    19,     0,    19,    48,    21,
      35,    35,    19,    19,    28,    48,   223,    35,   225,     9,
     227,    28,    28,   208,    32,    33,    38,    28,    89,    19,
      20,    21,    40,    41,    42,    43,    26,    27,    28,   224,
      13,   189,    63,    20,   332,    69,    89,    48,    38,    89,
      75,    28,    35,    35,    44,    65,    89,    75,    48,   288,
      35,    34,   210,    16,   293,   294,    89,   274,    80,    81,
      82,    48,    25,    83,   118,    89,    66,    89,    90,    91,
     368,    64,    89,    89,    92,    89,   123,    69,    89,    64,
      80,    81,    82,   318,    69,   320,    34,    28,    29,    89,
      90,    91,   183,    24,   185,    36,    89,   372,   154,    19,
      10,    21,    89,   342,    89,    16,     8,   154,    19,   387,
      45,    13,   328,   140,   141,    35,   155,   334,     5,    60,
     158,     8,   357,    19,    35,   169,   404,    23,     6,    30,
       8,   348,    46,    47,    26,    27,    31,    23,    24,   186,
     187,    48,   198,     6,     7,    91,   335,    19,    23,   366,
      11,   198,   200,   199,   200,   199,   200,   204,    24,   206,
      13,   208,   216,    20,   381,    23,   383,    22,     3,     4,
       5,    39,   219,   220,     9,   222,   393,   224,    13,    14,
      24,   228,   226,    18,    19,    24,    21,   140,   141,   406,
     407,    26,    27,    28,    24,    68,    24,    34,    24,    23,
      11,    75,     9,    38,   251,   252,    89,    89,    89,    44,
      89,   258,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    20,    61,    24,    24,    23,   275,    22,
      65,    66,    23,    68,    69,    70,    71,    72,    73,    74,
      89,    76,    77,    78,    79,    80,    81,    82,    83,    20,
      24,    34,    17,    88,    89,    90,    91,    23,    11,    23,
      16,    20,    89,   310,    24,    75,   313,     6,    23,   316,
     317,    20,    23,   320,    24,   322,    23,    20,    16,   326,
      89,    89,   329,     9,    20,    89,    23,     6,    23,   336,
     332,    24,    23,    19,    20,    21,    75,    20,   139,    24,
      26,    27,    28,    23,    89,   352,   353,    23,    48,     3,
       4,     5,    38,   172,   157,     9,   170,   322,    44,    13,
      14,    15,    16,   370,   171,    19,   368,    21,   178,   175,
     316,   115,    26,    27,    28,    21,    14,   228,    86,   328,
      66,    86,   324,    30,    38,    86,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,   409,    89,    90,    91,    -1,    -1,    -1,    -1,
      -1,    65,    66,    -1,    68,    69,    70,    71,    72,    73,
      74,    -1,    76,    77,    78,    79,    80,    81,    82,    83,
      -1,    -1,    -1,    -1,    88,    89,    90,    91,     3,     4,
       5,    -1,    -1,    -1,     9,    -1,    -1,    -1,    13,    14,
      -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      65,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    79,    80,    81,    82,    83,    -1,
      -1,    -1,     4,    88,    89,    90,    91,     9,    -1,    -1,
      -1,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    76,    77,    78,    -1,    80,    81,
      82,     4,    -1,    -1,    -1,    -1,     9,    89,    90,    91,
      -1,    14,    -1,    16,    -1,    -1,    19,    -1,    21,     9,
      -1,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    19,
      20,    21,    -1,    -1,    -1,    38,    26,    27,    28,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    48,    -1,
      -1,    -1,    -1,    66,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    76,    77,    78,    66,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,     9,    89,    90,    91,    -1,
      80,    81,    82,    -1,    -1,    19,    20,    21,     9,    89,
      90,    91,    26,    27,    28,    -1,    -1,    -1,    19,    -1,
      21,    -1,    -1,    -1,    38,    26,    27,    28,     9,    -1,
      44,    -1,    -1,    -1,    48,    -1,    -1,    38,    19,    -1,
      21,    22,    23,    44,    -1,    26,    27,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    66,    80,    81,    82,    70,
      -1,    -1,    -1,    -1,    -1,    89,    90,    91,    -1,    80,
      81,    82,    -1,    -1,    -1,    66,     9,    -1,    89,    90,
      91,    -1,    -1,    -1,    -1,    -1,    19,    -1,    21,    80,
      81,    82,    -1,    26,    27,    28,    -1,    -1,    89,    90,
      91,    -1,     9,    -1,    -1,    38,     9,    -1,    -1,    -1,
      -1,    44,    19,    -1,    21,    48,    19,    -1,    21,    26,
      27,    28,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,    66,    -1,    38,    39,    44,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    80,    81,    82,
      -1,    -1,    -1,    -1,    -1,    -1,    89,    90,    91,    66,
      -1,    -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    80,    81,    82,    -1,    80,    81,    82,
       9,    -1,    89,    90,    91,    -1,    89,    90,    91,    -1,
      19,    -1,    21,     9,    -1,    -1,    -1,    26,    27,    -1,
      -1,    -1,    -1,    19,    -1,    21,     9,    23,    -1,    38,
      26,    27,    -1,    -1,    -1,    44,    19,    -1,    21,    -1,
      23,    -1,    38,    26,    27,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    66,    -1,    68,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      66,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      89,    90,    91,    66,    80,    81,    82,    -1,    -1,    -1,
      -1,    -1,     9,    89,    90,    91,    -1,    80,    81,    82,
      -1,    -1,    19,    -1,    21,    -1,    89,    90,    91,    26,
      27,    -1,    -1,    -1,    -1,    19,    -1,    21,    -1,    -1,
      -1,    38,    26,    27,    28,    -1,    -1,    44,    19,    -1,
      21,    -1,    -1,    -1,    38,    26,    27,    -1,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    66,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
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
      77,    78,    79,    80,    81,    82,    83,    88,    89,    90,
      91,    96,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   120,   121,   122,   123,   124,   126,   127,   128,   129,
     131,   133,   135,   136,   137,   138,   145,   151,   152,   157,
     158,   160,   162,   166,   169,   177,   178,   179,   180,   181,
     182,   189,   191,   192,    89,   120,   123,   113,   126,   167,
     168,   167,    20,   114,   115,   156,   156,   126,    39,   120,
     153,   154,   155,    89,   188,   151,    35,    64,   183,   188,
     184,   185,   188,    68,   118,   119,   120,   120,   118,    89,
     190,   190,   120,   120,    89,   120,   163,   164,    16,    25,
      34,    34,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    61,   117,    24,     5,     8,    10,     9,
      11,    12,    32,    33,    40,    41,    42,    43,    92,   125,
      30,    45,    31,    46,    47,   130,    26,    27,   132,    28,
      29,    36,    60,   134,   135,    48,    19,    21,    35,   139,
     140,    91,   145,   169,   177,    19,   170,    23,    11,    24,
      13,   150,    20,    22,    23,    39,    24,    16,    19,    35,
     139,    35,    64,    69,   188,    69,    24,    75,   120,    24,
      68,    24,    24,    23,    19,    23,    75,    23,    24,    16,
     100,   112,   114,   112,   114,   118,   115,   121,   122,   123,
      11,     9,   126,   127,   128,   129,   131,   133,   135,   135,
      20,    28,    48,   120,   146,   147,   148,    22,    23,   120,
     141,   142,   143,    89,   140,    20,    28,    48,    89,   171,
     172,   174,   175,   176,    23,    63,    16,    99,   165,   118,
     113,   126,   167,   120,   120,    20,   146,    89,    19,    28,
      89,   186,   187,    69,    19,    28,   186,   188,    89,   120,
     120,    89,   120,   165,    20,   146,   165,   126,   165,   164,
       6,   120,   120,    34,   150,    20,    24,    23,   120,   144,
      23,    22,    24,   173,   176,   176,    23,    20,    24,    34,
     165,   120,    17,   159,    23,    11,    23,    16,    20,   186,
      75,    24,    19,    28,   186,   186,    75,     6,    23,    20,
     120,   120,    28,    48,   148,   120,   144,   120,   144,   143,
      24,   173,   120,   172,   175,   120,    23,    98,   161,     6,
       7,   165,   121,   120,    16,    20,    89,    89,   186,    20,
      89,    23,   165,    23,   120,   120,   144,    48,   175,    24,
     165,    18,    98,    23,   120,     6,   149,   150,    75,    20,
     165,   165,    24,   176,    48,   165,    23,    23,    89,    48,
     176,   165,   165,   120
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
     156,   156,   157,   157,   157,   157,   157,   157,   157,   158,
     158,   159,   159,   160,   160,   161,   161,   162,   163,   163,
     164,   164,   165,   165,   166,   166,   167,   167,   168,   168,
     168,   168,   169,   169,   170,   170,   171,   171,   171,   172,
     172,   172,   172,   172,   173,   173,   174,   174,   175,   175,
     176,   176,   177,   177,   177,   178,   178,   179,   179,   180,
     180,   181,   182,   182,   182,   182,   182,   182,   182,   182,
     182,   183,   183,   183,   183,   184,   184,   185,   185,   185,
     185,   186,   186,   187,   187,   187,   187,   188,   188,   189,
     190,   190,   191,   192,   192
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
       1,     2,     1,     1,     1,     1,     1,     1,     1,     5,
       8,     0,     5,     4,     7,     1,     2,     4,     1,     3,
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
  "with_stmt", "with_item_seq", "with_item", "suite", "for_stmt",
  "exprlist", "exprlist_seq", "funcdef", "parameters", "typedargslist",
  "var_args", "var_arglist_trailer", "named_args", "tfpdef_test", "tfpdef",
  "decorator", "decorators", "decorated", "import_stmt", "import_name",
  "import_from", "import_dots", "dotted_as_names", "dotted_as_names_seq",
  "import_as_names", "import_as_names_seq", "dotted_name", "global_stmt",
  "name_seq", "nonlocal_stmt", "assert_stmt", YY_NULLPTR
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
     773,   777,   786,   787,   801,   808,   814,   820,   827,   838,
     839,   844,   845,   851,   852,   853,   854,   855,   856,   857,
     858,   859,   864,   865,   872,   876,   880,   901,   907,   915,
     922,   930,   937,   943,   958,   964,   976,   977,   978,   988,
     994,   995,  1023,  1029,  1036,  1044,  1048,  1053,  1054,  1055,
    1056,  1060,  1064,  1071,  1072,  1099,  1107,  1108,  1115,  1119,
    1146,  1147,  1155,  1156,  1157,  1158,  1159,  1160,  1161,  1169,
    1174,  1183,  1188,  1199,  1203,  1229,  1233,  1242,  1246,  1247,
    1253,  1254,  1260,  1264,  1273,  1277,  1286,  1287,  1297,  1303,
    1308,  1309,  1315,  1320,  1330,  1334,  1374,  1381,  1388,  1397,
    1404,  1412,  1418,  1426,  1439,  1443,  1454,  1458,  1466,  1470,
    1484,  1491,  1505,  1509,  1513,  1522,  1523,  1532,  1536,  1544,
    1544,  1549,  1569,  1573,  1577,  1581,  1585,  1589,  1593,  1597,
    1601,  1612,  1617,  1622,  1627,  1639,  1640,  1645,  1649,  1653,
    1657,  1670,  1671,  1675,  1679,  1683,  1687,  1699,  1700,  1713,
    1721,  1722,  1732,  1741,  1745
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

