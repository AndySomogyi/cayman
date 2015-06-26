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

      case 66: // "@="


        { yyoutput << (yysym.value); }

        break;

      case 67: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 68: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 69: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 70: // "import"


        { yyoutput << (yysym.value); }

        break;

      case 71: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 72: // "break"


        { yyoutput << (yysym.value); }

        break;

      case 73: // "continue"


        { yyoutput << (yysym.value); }

        break;

      case 74: // "raise"


        { yyoutput << (yysym.value); }

        break;

      case 75: // "return"


        { yyoutput << (yysym.value); }

        break;

      case 76: // "as"


        { yyoutput << (yysym.value); }

        break;

      case 77: // "global"


        { yyoutput << (yysym.value); }

        break;

      case 78: // "nonlocal"


        { yyoutput << (yysym.value); }

        break;

      case 79: // "assert"


        { yyoutput << (yysym.value); }

        break;

      case 80: // "while"


        { yyoutput << (yysym.value); }

        break;

      case 81: // "False"


        { yyoutput << (yysym.value); }

        break;

      case 82: // "None"


        { yyoutput << (yysym.value); }

        break;

      case 83: // "True"


        { yyoutput << (yysym.value); }

        break;

      case 84: // "class"


        { yyoutput << (yysym.value); }

        break;

      case 85: // "except"


        { yyoutput << (yysym.value); }

        break;

      case 86: // "finally"


        { yyoutput << (yysym.value); }

        break;

      case 87: // "lambda"


        { yyoutput << (yysym.value); }

        break;

      case 88: // "try"


        { yyoutput << (yysym.value); }

        break;

      case 89: // "with"


        { yyoutput << (yysym.value); }

        break;

      case 90: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 91: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 92: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 93: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 95: // module


        { yyoutput << (yysym.value); }

        break;

      case 96: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 97: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 98: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 99: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 100: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 101: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 102: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 103: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 104: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 105: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 106: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 107: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 108: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 109: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 110: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 111: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 112: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 113: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 114: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 115: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 116: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 117: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 118: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 119: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 120: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 121: // test


        { yyoutput << (yysym.value); }

        break;

      case 122: // test_nocond


        { yyoutput << (yysym.value); }

        break;

      case 123: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 124: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 125: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 126: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 127: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 128: // expr


        { yyoutput << (yysym.value); }

        break;

      case 129: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 130: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 131: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 132: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 133: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 134: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 135: // term


        { yyoutput << (yysym.value); }

        break;

      case 136: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 137: // factor


        { yyoutput << (yysym.value); }

        break;

      case 138: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 139: // power


        { yyoutput << (yysym.value); }

        break;

      case 140: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 141: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 142: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 143: // subscriptlist


        { yyoutput << (yysym.value); }

        break;

      case 144: // subscript_seq


        { yyoutput << (yysym.value); }

        break;

      case 145: // subscript


        { yyoutput << (yysym.value); }

        break;

      case 146: // sliceop


        { yyoutput << (yysym.value); }

        break;

      case 147: // classdef


        { yyoutput << (yysym.value); }

        break;

      case 148: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 149: // argument_seq


        { yyoutput << (yysym.value); }

        break;

      case 150: // argument


        { yyoutput << (yysym.value); }

        break;

      case 151: // comp_iter


        { yyoutput << (yysym.value); }

        break;

      case 152: // comp_for


        { yyoutput << (yysym.value); }

        break;

      case 153: // comp_if


        { yyoutput << (yysym.value); }

        break;

      case 154: // atom


        { yyoutput << (yysym.value); }

        break;

      case 155: // str


        { yyoutput << (yysym.value); }

        break;

      case 156: // dictorsetmaker


        { yyoutput << (yysym.value); }

        break;

      case 157: // dict


        { yyoutput << (yysym.value); }

        break;

      case 158: // dict_seq


        { yyoutput << (yysym.value); }

        break;

      case 159: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 160: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 161: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 162: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 163: // while_stmt


        { yyoutput << (yysym.value); }

        break;

      case 164: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 165: // try_stmt


        { yyoutput << (yysym.value); }

        break;

      case 166: // except_clause_seq


        { yyoutput << (yysym.value); }

        break;

      case 167: // except_clause


        { yyoutput << (yysym.value); }

        break;

      case 168: // with_stmt


        { yyoutput << (yysym.value); }

        break;

      case 169: // with_item_seq


        { yyoutput << (yysym.value); }

        break;

      case 170: // with_item


        { yyoutput << (yysym.value); }

        break;

      case 171: // suite


        { yyoutput << (yysym.value); }

        break;

      case 172: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 173: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 174: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 175: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 176: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 177: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 178: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 179: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 180: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 181: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 182: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 183: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 184: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 185: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 186: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 187: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 188: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 189: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 190: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 191: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 192: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 193: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 194: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 195: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 196: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 197: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 198: // assert_stmt


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

  case 70:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 75:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 77:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 78:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 81:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 82:

    {
        (yylhs.value) = AstToken::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 83:

    {
        (yylhs.value) = AstToken::GetAstNodeForOperatorType(py::IsNot);
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

  case 100:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 104:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 108:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 115:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 120:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 122:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 123:

    {
        assert(0);
    }

    break;

  case 124:

    {
        assert(0);
    }

    break;

  case 126:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 127:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 128:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 129:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, NULL, (yystack_[1].value));
    }

    break;

  case 130:

    {
        // trailer: []
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateSubscript(yylhs.location);

    }

    break;

  case 131:

    {
        // trailer: [ subscriptlist ]
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateSubscript(yylhs.location);
    }

    break;

  case 147:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 148:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[4].value), NULL, (yystack_[0].value));
    }

    break;

  case 149:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 150:

    {
        // arglist: argument_seq:
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 151:

    {
        // arglist: argument_seq ","
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 152:

    {
        // arglist:  "*" test
        // AstNode *args1 = NULL, 
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, (yystack_[0].value), NULL); 
    }

    break;

  case 153:

    {
        // arglist: argument_seq "," "*" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), (yystack_[0].value), NULL);
    }

    break;

  case 154:

    {
        // arglist: "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, NULL, (yystack_[0].value));
    }

    break;

  case 155:

    {
        // arglist: argument_seq "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), NULL, (yystack_[0].value));
    }

    break;

  case 156:

    {
        // arglist: argument_seq "," "*" test "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[6].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 157:

    {
        // argument_seq : argument ","
        // create a length 1 tuple containing the arg.
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 158:

    {
        // argument_seq: argument_seq argument
        // add argument to the seq
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 161:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 168:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 169:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 170:

    {
        (yylhs.value) = ctx.ast->CreateList(yylhs.location);
    }

    break;

  case 171:

    {
        // atom: |"[" testlist_comp "]"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location);
    }

    break;

  case 173:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 177:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::True);
    }

    break;

  case 178:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::False);
    }

    break;

  case 179:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::None);
    }

    break;

  case 181:

    {
        Str *s1 = dynamic_cast<Str*>((yystack_[1].value));
        assert(s1);
        Str *s2 = dynamic_cast<Str*>((yystack_[0].value));
        assert(s2);
        s1->s += s2->s;
        (yylhs.value) = s1;
    }

    break;

  case 184:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 185:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 186:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 197:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 198:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 199:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 200:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 201:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 202:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 203:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 204:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 220:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 221:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 222:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 223:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 225:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 226:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 227:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 230:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 231:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 232:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 233:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 234:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 235:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 236:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 237:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 238:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 239:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 240:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 241:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 242:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 243:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 244:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 245:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 246:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 247:

    {
        // tfpdef_test : tfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 248:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 249:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 250:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 251:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 252:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 254:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 255:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 256:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 259:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 260:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 261:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 262:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 263:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 264:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 265:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 266:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 267:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 268:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 269:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 270:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 271:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 272:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 275:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 276:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 277:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 278:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 281:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 282:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 283:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 284:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 286:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 287:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 289:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 290:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 291:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 292:

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


  const short int py_parser::yypact_ninf_ = -289;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -289,    75,  -289,    51,  -289,    48,  -289,  1012,  1012,   265,
     265,  -289,  -289,   694,   714,  -289,  -289,  1079,   860,  -289,
      55,   175,    63,    55,   891,  -289,  -289,  1012,  1012,    74,
      74,  1012,  1012,  -289,  -289,  -289,    85,    76,  1012,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,
    -289,  -289,   144,  -289,  -289,  -289,   145,  -289,  -289,   336,
    -289,   160,  -289,   169,   177,  -289,    72,   165,   154,   181,
     110,   164,   213,  -289,  1079,  -289,   158,  -289,    24,   125,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,    27,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,   203,   202,  -289,  -289,
     165,   218,   212,  -289,  -289,  -289,   230,   211,  -289,   226,
     165,  -289,   236,   225,  -289,   244,  -289,   135,    24,  -289,
    -289,    16,    15,  -289,   245,    -3,  1012,  -289,   246,  -289,
     206,  -289,  -289,   247,   247,   248,   253,    34,   521,   205,
     214,  -289,  -289,   601,   773,   773,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  1012,
     911,  1012,  1012,  1012,   268,  -289,   271,  -289,  -289,  -289,
    -289,  -289,  -289,  -289,  1079,  1079,  1079,  1079,  -289,  -289,
    1079,  -289,  -289,  1079,  -289,  -289,  -289,  -289,  -289,  1079,
    -289,  1079,   207,   793,   192,    24,  -289,  -289,  -289,  -289,
    -289,   204,    13,   521,  1012,   265,   265,  -289,  -289,  -289,
    1012,  -289,  1012,  -289,   614,   193,    24,  -289,  -289,    18,
      26,    19,    55,   195,  -289,  1012,  1012,   197,  1012,   521,
     681,   521,   278,  -289,   107,  1079,   521,  1012,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,   172,   177,  -289,  -289,
    -289,   165,   154,   181,   110,   164,   213,  -289,  -289,  -289,
    1012,  1012,    28,   276,   277,  -289,  -289,   986,   279,   282,
     281,  -289,  -289,  -289,  -289,   210,   210,   283,   287,  -289,
     286,  -289,   280,   521,  1012,  -289,   288,  -289,   165,   302,
    -289,   293,   301,   299,  -289,   233,  -289,   250,  -289,   296,
      20,   233,  -289,  -289,    17,  -289,  -289,  -289,  -289,  -289,
     318,   305,   309,  -289,   432,  1012,   307,    62,   310,   165,
    -289,  -289,  1012,  -289,  -289,  1012,  -289,  -289,   824,  1012,
     312,  -289,   986,  -289,   999,   313,  -289,  -289,  1012,  -289,
      46,  1012,  -289,   315,   240,   521,  1012,  1012,  -289,   320,
     319,   251,   252,   233,  -289,  -289,   330,   261,   329,   521,
     339,  -289,   340,   295,   521,   346,   349,   350,   521,  -289,
    -289,  1012,  1012,  -289,  -289,  -289,   312,  -289,  -289,     1,
     351,  -289,  -289,  -289,  -289,   521,   353,  1012,   357,   168,
    -289,  -289,  -289,  -289,   298,   359,  -289,  -289,   521,  -289,
     521,  -289,  -289,   291,  -289,   521,   521,   521,  -289,   358,
    -289,  -289,   210,  -289,    10,  -289,   521,   354,   360,  1012,
    -289,  -289,  -289,   306,  -289,  -289,  -289,  -289,   314,  -289,
    -289,   355,  -289,   210,  -289,   521,   521,    58,   390,  -289,
     376,  1012,  -289,  -289,  -289,  -289,   521,  -289,  -289
  };

  const unsigned short int
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,     0,   116,   117,     0,     0,   118,
       0,     0,     0,     0,    44,    25,    26,    29,    27,     0,
       0,     0,     0,   178,   179,   177,     0,     0,     0,   174,
     175,   180,     7,     5,     8,    33,    15,    20,    21,    22,
      23,    24,     0,    13,    14,    12,    38,    32,    51,    39,
      52,    48,    50,    71,    74,    76,    79,    80,    93,    95,
      97,    99,   103,   107,     0,   114,   119,   195,   121,   176,
       9,   189,   190,   192,   193,   191,   194,   253,     0,   196,
      16,   257,   258,    17,    18,    19,     0,     0,    78,   229,
     228,     0,   224,    35,   168,   187,    52,     0,   170,     0,
      47,   172,     0,     0,   182,   183,   285,     0,   123,   269,
     270,     0,     0,   259,   273,   275,     0,    45,    67,    69,
      30,    28,   288,   287,   290,   291,     0,     0,     0,   218,
       0,   216,    10,     0,     0,     0,    54,    55,    56,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    57,     0,
      49,     0,     0,     0,     0,    91,    92,    84,    85,    86,
      90,    88,    87,    89,     0,     0,     0,     0,   101,   102,
       0,   105,   106,     0,   109,   111,   112,   113,   110,     0,
     115,     0,     0,     0,     0,   122,   125,   181,   256,   255,
     254,     0,     0,     0,     0,   225,     0,   188,   169,   171,
       0,   173,   184,   250,     0,     0,   124,   271,   272,     0,
       0,     0,   274,     0,    46,    68,     0,     0,     0,     0,
       0,     0,     0,   220,     0,     0,     0,     0,    11,    34,
      42,    43,    40,    41,    37,    53,     0,    75,    77,    82,
      83,    81,    94,    96,    98,   100,   104,   108,   120,   128,
       0,     0,   159,     0,   150,   157,   130,   137,   136,     0,
     132,   134,   127,   126,   232,   242,     0,   248,     0,   236,
     234,   244,   246,     0,     0,   199,     0,   227,   226,     0,
     185,     0,     0,     0,   286,     0,   266,   281,   268,   279,
       0,     0,   260,   262,   277,   276,    70,    31,   289,   292,
     201,     0,     0,   147,     0,   212,     0,   205,     0,   219,
     215,   217,     0,   152,   154,     0,   160,   129,   151,   145,
     139,   138,   141,   131,   133,   240,   242,   239,     0,   233,
       0,     0,   230,     0,   197,     0,     0,     0,   251,     0,
       0,     0,   280,     0,   263,   265,     0,     0,     0,     0,
       0,   203,     0,   213,     0,     0,     0,     0,     0,    72,
     161,     0,     0,   158,   146,   140,   143,   142,   135,     0,
     237,   249,   235,   245,   247,     0,     0,     0,   222,   164,
     186,   252,   267,   282,   283,     0,   261,   278,     0,   148,
       0,   221,   204,     0,   209,     0,     0,     0,   210,   153,
     155,   144,     0,   243,     0,   231,     0,     0,     0,     0,
     165,   162,   163,     0,   264,   202,   149,   214,   206,   208,
     211,     0,   241,     0,   198,     0,     0,   166,    73,   284,
       0,     0,   238,   200,   223,   167,     0,   156,   207
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -289,  -289,  -289,  -289,  -289,  -280,    -2,   258,  -289,  -289,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,   118,
      -5,    14,     2,  -289,  -289,   -22,  -289,    -7,  -289,  -158,
     242,     4,  -289,  -289,     9,   231,   232,   239,  -289,   259,
    -289,   243,  -289,   -45,  -289,  -289,  -289,   322,  -126,  -289,
    -289,    91,  -288,   345,  -113,  -289,    99,     5,   -96,  -289,
     417,  -289,  -289,  -289,  -289,   429,  -289,  -289,  -289,  -289,
    -289,  -289,  -289,   127,  -289,  -289,   215,  -196,  -289,    -8,
    -289,   361,  -289,  -289,   108,   111,  -289,  -179,  -262,   362,
    -289,  -289,  -289,  -289,  -289,  -289,  -289,  -289,  -198,  -289,
     -14,  -289,   424,  -289,  -289
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    42,     3,    43,   233,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,   159,   127,   128,    62,   437,    63,
      64,    65,    66,   174,    67,    68,    69,    70,   180,    71,
     183,    72,   189,    73,    74,    75,    76,   195,   196,   269,
     270,   271,   331,    77,   263,   264,   265,   420,   421,   422,
      78,    79,   113,   114,   115,   107,    80,    81,   344,    82,
     362,    83,   317,   318,    84,   140,   141,   234,    85,   101,
     102,    86,   202,   278,   279,   335,   280,   413,   282,    87,
      88,    89,    90,    91,    92,   121,   123,   124,   298,   299,
     117,    93,   133,    94,    95
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      97,    44,   103,   246,    99,    99,   131,   285,   122,   125,
     207,   112,    98,   336,   337,   106,   106,   129,   100,   100,
     130,   129,   281,   303,   135,   136,   110,   105,   105,   190,
       5,   139,   215,   310,   361,   313,   283,   295,   301,   353,
     320,   206,   375,   192,   377,   193,   296,   302,   354,   412,
     215,   217,   215,   230,     5,     6,     7,   231,   433,   194,
       8,   215,   325,   419,     9,    10,    11,    12,   365,   273,
      13,   206,    14,   223,   275,     4,   284,    15,    16,    17,
     218,   164,   402,   165,   166,   221,   219,   342,   411,    18,
     273,   277,    20,   357,   276,    19,   300,   350,   119,   138,
     277,   293,   355,   356,   167,   168,   116,   220,   297,   297,
     297,    36,   169,   170,   171,   172,    20,   312,    21,   224,
      22,    23,    24,    25,    26,    27,    28,   120,    29,    30,
      31,    32,    33,    34,    35,    36,   277,   244,    96,    37,
      38,    39,    40,    41,   257,   116,   258,   315,   366,   388,
     432,   213,   129,   116,   214,   395,   178,   179,   241,   243,
     142,   383,   245,   399,   132,   173,   326,   248,   404,   143,
     215,   442,   408,   419,   161,   137,   162,   162,   322,   144,
     162,   206,   286,   251,   160,   262,   268,   163,   389,   415,
     181,   182,   315,   316,    13,   175,    14,   129,   289,   176,
     287,    99,   425,   290,   426,   291,   191,   262,   304,   428,
     429,   430,   177,    18,   288,   100,     8,   197,   306,   307,
     434,   309,   201,   262,   274,   203,    13,   259,    14,   204,
     139,   208,   275,    15,    16,   260,   205,   236,   237,   443,
     444,   184,   185,   206,   319,    18,   386,   387,   209,   186,
     448,    19,   276,   323,   324,   261,    33,    34,    35,   210,
     330,   438,   240,   242,   211,    39,    40,    41,   212,   222,
     225,   227,   228,   187,    21,   226,   229,   343,   188,   249,
     250,   235,   272,   294,    13,   305,    14,   308,    33,    34,
      35,    15,    16,    17,   277,   314,   327,    39,    40,    41,
     277,   328,   332,    18,   333,   334,   338,   339,   363,    19,
     340,   345,    44,   346,   341,   369,   347,   348,   370,   349,
     352,   262,   374,   297,   358,   376,   351,   268,   359,   360,
     364,   381,    21,   368,   384,   329,   391,   379,   385,   392,
     390,   393,   394,     5,     6,     7,    33,    34,    35,     8,
     396,   397,   398,     9,    10,    39,    40,    41,   401,    13,
      44,    14,   400,   418,   409,   410,    15,    16,    17,   405,
     145,   403,   406,   407,   423,   414,   416,   435,    18,   424,
     417,   427,   431,   436,    19,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   439,   157,   162,   446,
     440,   239,   158,   441,   247,    20,   252,    21,   253,    22,
      23,    24,    25,    26,    27,    28,   254,    29,    30,    31,
      32,    33,    34,    35,    36,   378,   256,   373,    37,    38,
      39,    40,    41,   198,   447,     5,     6,     7,   118,   255,
     216,     8,   445,   109,   367,     9,    10,   380,   382,   199,
     200,    13,   321,    14,   134,     0,     0,     0,    15,    16,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      18,     0,     0,     0,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    20,     0,    21,
       0,    22,    23,    24,    25,    26,    27,    28,     0,    29,
      30,    31,    32,    33,    34,    35,    36,     0,     0,     0,
      37,    38,    39,    40,    41,     6,     0,     0,     0,     0,
       8,     0,     0,     0,     0,    10,     0,   232,     0,     0,
      13,     0,    14,     0,     0,     0,     0,    15,    16,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    18,
       0,     0,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,     0,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,     0,    33,    34,    35,     6,     0,     0,     0,     0,
       8,    39,    40,    41,     0,    10,     0,   238,     0,     0,
      13,     0,    14,     8,     0,     0,     0,    15,    16,    17,
       0,     0,     0,    13,   292,    14,     0,     0,     0,    18,
      15,    16,   260,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,     0,   261,     0,     0,     0,     0,     0,    21,     0,
      22,    23,    24,    25,    26,    27,    28,     0,    29,    30,
      31,    21,    33,    34,    35,     0,     0,     0,     0,     0,
       8,    39,    40,    41,     0,    33,    34,    35,     0,     0,
      13,   311,    14,     8,    39,    40,    41,    15,    16,   260,
       0,     0,     0,    13,   104,    14,     0,     0,     0,    18,
      15,    16,    17,     8,     0,    19,     0,     0,     0,   261,
       0,     0,    18,    13,     0,    14,   108,     0,    19,     0,
      15,    16,    17,     0,     0,     0,     0,     0,    21,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,    21,    33,    34,    35,     0,     0,     0,     0,     0,
       0,    39,    40,    41,     0,    33,    34,    35,     0,     0,
       0,    21,     8,     0,    39,    40,    41,     0,     0,     0,
       0,     0,    13,     0,    14,    33,    34,    35,     0,    15,
      16,    17,     8,     0,    39,    40,    41,     0,     0,     0,
       0,    18,    13,     0,    14,   266,   267,    19,     0,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     8,     0,     0,     0,    19,     0,     0,
      21,     0,     0,    13,    24,    14,     0,     0,     0,     0,
      15,    16,   371,     0,    33,    34,    35,     0,     0,     0,
      21,     0,    18,    39,    40,    41,     0,     0,    19,     8,
       0,     0,   372,     0,    33,    34,    35,     0,     0,    13,
       0,    14,     0,    39,    40,    41,    15,    16,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,    18,   111,
       8,     0,     0,     0,    19,    33,    34,    35,     0,     0,
      13,     0,    14,     0,    39,    40,    41,    15,    16,     0,
       8,     0,     0,     0,     0,     0,     0,    21,     0,    18,
      13,     0,    14,     0,     0,    19,     0,    15,    16,    17,
       0,    33,    34,    35,     0,     0,     0,     0,     0,    18,
      39,    40,    41,     0,     0,    19,     0,     0,    21,     0,
     126,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,     0,     0,     0,    21,     0,
       0,    39,    40,    41,     0,     0,     0,     0,     0,     0,
       0,     0,    33,    34,    35,     8,     0,     0,     0,     0,
       0,    39,    40,    41,     0,    13,     0,    14,     8,   329,
       0,     0,    15,    16,     0,     0,     0,     0,    13,     0,
      14,     8,   267,     0,    18,    15,    16,     0,     0,     0,
      19,    13,     0,    14,     0,     0,     0,    18,    15,    16,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
      18,     0,     0,    21,     0,     0,    19,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,    33,    34,    35,
       0,     0,     0,     0,     0,     0,    39,    40,    41,    21,
      33,    34,    35,     0,     0,     0,     0,     0,     0,    39,
      40,    41,     0,    33,    34,    35,     0,     0,    13,     0,
      14,     0,    39,    40,    41,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    18,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    21,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      33,    34,    35,     0,     0,     0,     0,     0,     0,    39,
      40,    41
  };

  const short int
  py_parser::yycheck_[] =
  {
       7,     3,    10,   161,     9,    10,    28,   203,    22,    23,
     106,    18,     8,   275,   276,    13,    14,    24,     9,    10,
      27,    28,   201,   221,    31,    32,    17,    13,    14,    74,
       3,    38,    35,   229,   314,   231,    23,    19,    19,    19,
     236,    13,   330,    19,   332,    21,    28,    28,    28,    48,
      35,    35,    35,    19,     3,     4,     5,    23,    48,    35,
       9,    35,    34,     5,    13,    14,    15,    16,     6,   195,
      19,    13,    21,    76,    28,     0,    63,    26,    27,    28,
      64,     9,   362,    11,    12,    70,    70,   283,   376,    38,
     216,    90,    65,    76,    48,    44,    70,   295,    35,    23,
      90,   214,   300,   301,    32,    33,    90,   121,    90,    90,
      90,    84,    40,    41,    42,    43,    65,   230,    67,   126,
      69,    70,    71,    72,    73,    74,    75,    64,    77,    78,
      79,    80,    81,    82,    83,    84,    90,   159,    90,    88,
      89,    90,    91,    92,   189,    90,   191,    85,    86,   345,
     412,    16,   159,    90,    19,   353,    46,    47,   144,   145,
      16,   340,   160,   359,    90,    93,   262,   163,   364,    25,
      35,   433,   368,     5,     5,    90,     8,     8,     6,    34,
       8,    13,   204,   174,    24,   192,   193,    10,   346,   385,
      26,    27,    85,    86,    19,    30,    21,   204,   206,    45,
     205,   206,   398,   210,   400,   212,    48,   214,   222,   405,
     406,   407,    31,    38,   205,   206,     9,    92,   225,   226,
     416,   228,    19,   230,    20,    23,    19,    20,    21,    11,
     237,    20,    28,    26,    27,    28,    24,    23,    24,   435,
     436,    28,    29,    13,   235,    38,     6,     7,    22,    36,
     446,    44,    48,   260,   261,    48,    81,    82,    83,    23,
     267,   419,   144,   145,    39,    90,    91,    92,    24,    24,
      24,    24,    24,    60,    67,    69,    23,   284,    65,    11,
       9,    76,    90,    90,    19,    90,    21,    90,    81,    82,
      83,    26,    27,    28,    90,    17,    20,    90,    91,    92,
      90,    24,    23,    38,    22,    24,    23,    20,   315,    44,
      24,    23,   314,    11,    34,   322,    23,    16,   325,    20,
      24,   328,   329,    90,     6,   332,    76,   334,    23,    20,
      23,   338,    67,    23,   341,    23,    16,    24,    23,    20,
     347,    90,    90,     3,     4,     5,    81,    82,    83,     9,
      20,    90,    23,    13,    14,    90,    91,    92,    18,    19,
     362,    21,    23,     6,   371,   372,    26,    27,    28,    23,
      34,    76,    23,    23,    76,    24,    23,    23,    38,    20,
     387,    90,    24,    23,    44,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    90,    61,     8,    23,
      86,   143,    66,    48,   162,    65,   175,    67,   176,    69,
      70,    71,    72,    73,    74,    75,   177,    77,    78,    79,
      80,    81,    82,    83,    84,   334,   183,   328,    88,    89,
      90,    91,    92,    88,   441,     3,     4,     5,    21,   180,
     118,     9,   437,    14,   317,    13,    14,   336,   340,    88,
      88,    19,   237,    21,    30,    -1,    -1,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    65,    -1,    67,
      -1,    69,    70,    71,    72,    73,    74,    75,    -1,    77,
      78,    79,    80,    81,    82,    83,    84,    -1,    -1,    -1,
      88,    89,    90,    91,    92,     4,    -1,    -1,    -1,    -1,
       9,    -1,    -1,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    -1,    81,    82,    83,     4,    -1,    -1,    -1,    -1,
       9,    90,    91,    92,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    21,     9,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    38,
      26,    27,    28,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      69,    70,    71,    72,    73,    74,    75,    -1,    77,    78,
      79,    67,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
       9,    90,    91,    92,    -1,    81,    82,    83,    -1,    -1,
      19,    20,    21,     9,    90,    91,    92,    26,    27,    28,
      -1,    -1,    -1,    19,    20,    21,    -1,    -1,    -1,    38,
      26,    27,    28,     9,    -1,    44,    -1,    -1,    -1,    48,
      -1,    -1,    38,    19,    -1,    21,    22,    -1,    44,    -1,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    67,    -1,
      -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,    -1,
      -1,    67,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    -1,    81,    82,    83,    -1,    -1,
      -1,    67,     9,    -1,    90,    91,    92,    -1,    -1,    -1,
      -1,    -1,    19,    -1,    21,    81,    82,    83,    -1,    26,
      27,    28,     9,    -1,    90,    91,    92,    -1,    -1,    -1,
      -1,    38,    19,    -1,    21,    22,    23,    44,    -1,    26,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    38,    -1,     9,    -1,    -1,    -1,    44,    -1,    -1,
      67,    -1,    -1,    19,    71,    21,    -1,    -1,    -1,    -1,
      26,    27,    28,    -1,    81,    82,    83,    -1,    -1,    -1,
      67,    -1,    38,    90,    91,    92,    -1,    -1,    44,     9,
      -1,    -1,    48,    -1,    81,    82,    83,    -1,    -1,    19,
      -1,    21,    -1,    90,    91,    92,    26,    27,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    38,    39,
       9,    -1,    -1,    -1,    44,    81,    82,    83,    -1,    -1,
      19,    -1,    21,    -1,    90,    91,    92,    26,    27,    -1,
       9,    -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    38,
      19,    -1,    21,    -1,    -1,    44,    -1,    26,    27,    28,
      -1,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,    38,
      90,    91,    92,    -1,    -1,    44,    -1,    -1,    67,    -1,
      69,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,    -1,    -1,    -1,    67,    -1,
      -1,    90,    91,    92,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    81,    82,    83,     9,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    -1,    19,    -1,    21,     9,    23,
      -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    19,    -1,
      21,     9,    23,    -1,    38,    26,    27,    -1,    -1,    -1,
      44,    19,    -1,    21,    -1,    -1,    -1,    38,    26,    27,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      38,    -1,    -1,    67,    -1,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    81,    82,    83,
      -1,    -1,    -1,    -1,    -1,    -1,    90,    91,    92,    67,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92,    -1,    81,    82,    83,    -1,    -1,    19,    -1,
      21,    -1,    90,    91,    92,    26,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      81,    82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,
      91,    92
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    95,    96,    98,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    21,    26,    27,    28,    38,    44,
      65,    67,    69,    70,    71,    72,    73,    74,    75,    77,
      78,    79,    80,    81,    82,    83,    84,    88,    89,    90,
      91,    92,    97,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   121,   123,   124,   125,   126,   128,   129,   130,
     131,   133,   135,   137,   138,   139,   140,   147,   154,   155,
     160,   161,   163,   165,   168,   172,   175,   183,   184,   185,
     186,   187,   188,   195,   197,   198,    90,   121,   125,   114,
     128,   173,   174,   173,    20,   115,   116,   159,    22,   159,
     128,    39,   121,   156,   157,   158,    90,   194,   154,    35,
      64,   189,   194,   190,   191,   194,    69,   119,   120,   121,
     121,   119,    90,   196,   196,   121,   121,    90,    23,   121,
     169,   170,    16,    25,    34,    34,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,    66,   118,
      24,     5,     8,    10,     9,    11,    12,    32,    33,    40,
      41,    42,    43,    93,   127,    30,    45,    31,    46,    47,
     132,    26,    27,   134,    28,    29,    36,    60,    65,   136,
     137,    48,    19,    21,    35,   141,   142,    92,   147,   175,
     183,    19,   176,    23,    11,    24,    13,   152,    20,    22,
      23,    39,    24,    16,    19,    35,   141,    35,    64,    70,
     194,    70,    24,    76,   121,    24,    69,    24,    24,    23,
      19,    23,    16,   100,   171,    76,    23,    24,    16,   101,
     113,   115,   113,   115,   119,   116,   123,   124,   125,    11,
       9,   128,   129,   130,   131,   133,   135,   137,   137,    20,
      28,    48,   121,   148,   149,   150,    22,    23,   121,   143,
     144,   145,    90,   142,    20,    28,    48,    90,   177,   178,
     180,   181,   182,    23,    63,   171,   119,   114,   128,   173,
     121,   121,    20,   148,    90,    19,    28,    90,   192,   193,
      70,    19,    28,   192,   194,    90,   121,   121,    90,   121,
     171,    20,   148,   171,    17,    85,    86,   166,   167,   128,
     171,   170,     6,   121,   121,    34,   152,    20,    24,    23,
     121,   146,    23,    22,    24,   179,   182,   182,    23,    20,
      24,    34,   171,   121,   162,    23,    11,    23,    16,    20,
     192,    76,    24,    19,    28,   192,   192,    76,     6,    23,
      20,    99,   164,   121,    23,     6,    86,   167,    23,   121,
     121,    28,    48,   150,   121,   146,   121,   146,   145,    24,
     179,   121,   178,   181,   121,    23,     6,     7,   171,   123,
     121,    16,    20,    90,    90,   192,    20,    90,    23,   171,
      23,    18,    99,    76,   171,    23,    23,    23,   171,   121,
     121,   146,    48,   181,    24,   171,    23,   121,     6,     5,
     151,   152,   153,    76,    20,   171,   171,    90,   171,   171,
     171,    24,   182,    48,   171,    23,    23,   122,   123,    90,
      86,    48,   182,   171,   171,   151,    23,   121,   171
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    94,    95,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   101,   101,   101,   101,   101,   101,   101,   101,
     102,   102,   102,   102,   102,   103,   104,   105,   105,   106,
     106,   106,   107,   108,   108,   109,   110,   111,   111,   111,
     112,   112,   112,   112,   113,   113,   113,   114,   115,   115,
     116,   116,   117,   117,   118,   118,   118,   118,   118,   118,
     118,   118,   118,   118,   118,   118,   118,   119,   119,   120,
     120,   121,   121,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   136,   136,   136,   137,   137,   138,   138,   138,   139,
     139,   140,   140,   140,   140,   141,   141,   142,   142,   142,
     142,   142,   143,   143,   144,   144,   145,   145,   145,   145,
     145,   145,   145,   145,   145,   146,   146,   147,   147,   147,
     148,   148,   148,   148,   148,   148,   148,   149,   149,   150,
     150,   150,   151,   151,   152,   152,   153,   153,   154,   154,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     155,   155,   156,   157,   157,   158,   158,   159,   159,   160,
     160,   160,   160,   160,   160,   160,   160,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   165,   165,   165,
     166,   166,   167,   167,   167,   168,   169,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   174,   174,
     175,   175,   176,   176,   177,   177,   177,   178,   178,   178,
     178,   178,   179,   179,   180,   180,   181,   181,   182,   182,
     183,   183,   183,   184,   184,   185,   185,   186,   186,   187,
     188,   188,   188,   188,   188,   188,   188,   188,   188,   189,
     189,   189,   189,   190,   190,   191,   191,   191,   191,   192,
     192,   193,   193,   193,   193,   194,   194,   195,   196,   196,
     197,   198,   198
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
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     5,     1,     1,     3,     1,     3,     2,     1,
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       3,     1,     2,     2,     3,     1,     2,     2,     2,     3,
       2,     3,     1,     2,     1,     3,     1,     1,     2,     2,
       3,     2,     3,     3,     4,     1,     2,     4,     6,     7,
       1,     2,     2,     4,     2,     4,     7,     1,     3,     1,
       2,     3,     1,     1,     4,     5,     2,     3,     2,     3,
       2,     3,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     2,     1,     1,     2,     3,     5,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     5,     8,     0,
       5,     4,     7,     1,     2,     4,     7,    10,     7,     6,
       3,     4,     1,     2,     4,     4,     1,     3,     1,     3,
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
  "\"->\"", "\"...\"", "\"@\"", "\"@=\"", "\"await\"", "\"async\"",
  "\"from\"", "\"import\"", "\"yield\"", "\"break\"", "\"continue\"",
  "\"raise\"", "\"return\"", "\"as\"", "\"global\"", "\"nonlocal\"",
  "\"assert\"", "\"while\"", "\"False\"", "\"None\"", "\"True\"",
  "\"class\"", "\"except\"", "\"finally\"", "\"lambda\"", "\"try\"",
  "\"with\"", "NAME", "NUMBER", "STRING", "\"<>\"", "$accept", "module",
  "file_input", "newline_or_stmt", "newline_stmt_seq", "stmt",
  "simple_stmt", "small_stmt", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "raise_stmt", "yield_stmt", "small_stmt_seq", "del_stmt",
  "pass_stmt", "expr_stmt", "assign_expr_seq", "yield_expr", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "test_nocond", "or_test",
  "and_test", "not_test", "comparison", "comp_op", "expr", "xor_expr",
  "and_expr", "shift_expr", "shift_op", "arith_expr", "arith_op", "term",
  "term_op", "factor", "factor_op", "power", "atom_expr", "trailer_seq",
  "trailer", "subscriptlist", "subscript_seq", "subscript", "sliceop",
  "classdef", "arglist", "argument_seq", "argument", "comp_iter",
  "comp_for", "comp_if", "atom", "str", "dictorsetmaker", "dict",
  "dict_seq", "testlist_comp", "compound_stmt", "if_stmt", "elif_seq",
  "while_stmt", "stmt_seq", "try_stmt", "except_clause_seq",
  "except_clause", "with_stmt", "with_item_seq", "with_item", "suite",
  "for_stmt", "exprlist", "exprlist_seq", "funcdef", "parameters",
  "typedargslist", "var_args", "var_arglist_trailer", "named_args",
  "tfpdef_test", "tfpdef", "decorator", "decorators", "decorated",
  "import_stmt", "import_name", "import_from", "import_dots",
  "dotted_as_names", "dotted_as_names_seq", "import_as_names",
  "import_as_names_seq", "dotted_name", "global_stmt", "name_seq",
  "nonlocal_stmt", "assert_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   199,   199,   223,   231,   235,   244,   248,   269,   273,
     282,   286,   297,   298,   299,   300,   301,   302,   303,   304,
     309,   309,   309,   309,   309,   314,   322,   331,   335,   344,
     348,   352,   359,   367,   371,   382,   391,   408,   412,   416,
     434,   438,   443,   447,   463,   467,   471,   482,   499,   504,
     515,   515,   520,   525,   538,   538,   538,   538,   538,   538,
     538,   538,   538,   539,   539,   539,   539,   546,   547,   554,
     555,   570,   571,   577,   583,   584,   594,   595,   605,   609,
     616,   617,   630,   634,   638,   639,   640,   641,   642,   643,
     644,   645,   646,   653,   654,   663,   664,   673,   674,   683,
     684,   691,   691,   697,   698,   705,   705,   711,   712,   719,
     719,   719,   719,   719,   725,   726,   733,   733,   733,   739,
     740,   749,   750,   759,   763,   772,   773,   787,   794,   800,
     806,   813,   824,   825,   830,   831,   837,   838,   839,   840,
     841,   842,   843,   844,   845,   850,   851,   858,   862,   866,
     887,   893,   901,   908,   916,   923,   929,   944,   950,   962,
     963,   964,   974,   975,   981,   982,   990,   991,  1005,  1011,
    1018,  1022,  1030,  1034,  1039,  1040,  1041,  1042,  1046,  1050,
    1057,  1058,  1085,  1093,  1094,  1101,  1105,  1132,  1133,  1141,
    1142,  1143,  1144,  1145,  1146,  1147,  1148,  1156,  1161,  1170,
    1175,  1186,  1190,  1199,  1203,  1228,  1229,  1230,  1231,  1232,
    1237,  1238,  1244,  1245,  1246,  1252,  1256,  1257,  1263,  1264,
    1270,  1274,  1283,  1287,  1296,  1297,  1307,  1313,  1318,  1319,
    1325,  1330,  1340,  1344,  1384,  1391,  1398,  1407,  1414,  1422,
    1428,  1436,  1449,  1453,  1464,  1468,  1476,  1480,  1494,  1501,
    1515,  1519,  1523,  1532,  1533,  1542,  1546,  1554,  1554,  1559,
    1579,  1583,  1587,  1591,  1595,  1599,  1603,  1607,  1611,  1622,
    1627,  1632,  1637,  1649,  1650,  1655,  1659,  1663,  1667,  1680,
    1681,  1685,  1689,  1693,  1697,  1709,  1710,  1723,  1731,  1732,
    1742,  1751,  1755
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
      85,    86,    87,    88,    89,    90,    91,    92,    93
    };
    const unsigned int user_token_number_max_ = 348;
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

