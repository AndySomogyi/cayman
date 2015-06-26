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

      case 178: // tfp_args


        { yyoutput << (yysym.value); }

        break;

      case 179: // tfp_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 180: // tfpnamed_args


        { yyoutput << (yysym.value); }

        break;

      case 181: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 182: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 183: // lambdef


        { yyoutput << (yysym.value); }

        break;

      case 184: // lambdef_nocond


        { yyoutput << (yysym.value); }

        break;

      case 185: // varargslist


        { yyoutput << (yysym.value); }

        break;

      case 186: // vfp_args


        { yyoutput << (yysym.value); }

        break;

      case 187: // vfp_argslist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 188: // vfpnamed_args


        { yyoutput << (yysym.value); }

        break;

      case 189: // vfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 190: // vfpdef


        { yyoutput << (yysym.value); }

        break;

      case 191: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 192: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 193: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 194: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 195: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 196: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 197: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 198: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 199: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 200: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 201: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 202: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 203: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 204: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 205: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 206: // assert_stmt


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

  case 77:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 79:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 80:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 83:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 84:

    {
        (yylhs.value) = AstToken::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 85:

    {
        (yylhs.value) = AstToken::GetAstNodeForOperatorType(py::IsNot);
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

  case 110:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 117:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 122:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 124:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 125:

    {
        assert(0);
    }

    break;

  case 126:

    {
        assert(0);
    }

    break;

  case 128:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 129:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 130:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 131:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, NULL, (yystack_[1].value));
    }

    break;

  case 132:

    {
        // trailer: []
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateSubscript(yylhs.location);

    }

    break;

  case 133:

    {
        // trailer: [ subscriptlist ]
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateSubscript(yylhs.location);
    }

    break;

  case 149:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 150:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[4].value), NULL, (yystack_[0].value));
    }

    break;

  case 151:

    {
        (yylhs.value) = ctx.ast->CreateClassDef(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 152:

    {
        // arglist: argument_seq:
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 153:

    {
        // arglist: argument_seq ","
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 154:

    {
        // arglist:  "*" test
        // AstNode *args1 = NULL, 
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, (yystack_[0].value), NULL); 
    }

    break;

  case 155:

    {
        // arglist: argument_seq "," "*" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), (yystack_[0].value), NULL);
    }

    break;

  case 156:

    {
        // arglist: "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, NULL, NULL, (yystack_[0].value));
    }

    break;

  case 157:

    {
        // arglist: argument_seq "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[3].value), NULL, (yystack_[0].value));
    }

    break;

  case 158:

    {
        // arglist: argument_seq "," "*" test "," "**" test
        // args, starredArg,  dblStarredArgs
        (yylhs.value) = ctx.ast->CreateArgList(yylhs.location, (yystack_[6].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 159:

    {
        // argument_seq : argument ","
        // create a length 1 tuple containing the arg.
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 160:

    {
        // argument_seq: argument_seq argument
        // add argument to the seq
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 163:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 170:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 171:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateList(yylhs.location);
    }

    break;

  case 173:

    {
        // atom: |"[" testlist_comp "]"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 174:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location);
    }

    break;

  case 175:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 179:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::True);
    }

    break;

  case 180:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::False);
    }

    break;

  case 181:

    {
        (yylhs.value) = ctx.ast->CreateNameConstant(yylhs.location, NameConstant::None);
    }

    break;

  case 183:

    {
        Str *s1 = dynamic_cast<Str*>((yystack_[1].value));
        assert(s1);
        Str *s2 = dynamic_cast<Str*>((yystack_[0].value));
        assert(s2);
        s1->s += s2->s;
        (yylhs.value) = s1;
    }

    break;

  case 186:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 187:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 188:

    {
        (yylhs.value) = ctx.ast->CreateDict(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 199:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 200:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 201:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 202:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 203:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 204:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 205:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 206:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 222:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 223:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 224:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 225:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 227:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 228:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 229:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 232:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 233:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 234:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 235:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 236:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 237:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 238:

    {
        // tfp_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 239:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 240:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 241:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 242:

    {
        // tfp_args: "*" tfp_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 243:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 244:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 245:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 246:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 247:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 248:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 249:

    {
        // tfpdef_test : tfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 250:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 251:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 256:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 257:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 258:

    {
        // vfp_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 259:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 260:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 261:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 262:

    {
        // vfp_args: "*" vfp_argslist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 263:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 264:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 265:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 266:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 267:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 268:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 269:

    {
        // vfpdef_test : vfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 270:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 271:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 272:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 273:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 275:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 276:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 277:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 280:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 281:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 282:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 283:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 284:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 285:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 286:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 287:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 288:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 289:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 290:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 291:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 292:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 293:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 296:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 297:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 298:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 299:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 302:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 303:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 304:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 305:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 307:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 308:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 310:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 311:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 312:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 313:

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


  const short int py_parser::yypact_ninf_ = -410;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -410,    55,  -410,    57,  -410,    -4,  -410,  1078,  1158,  1171,
    1171,  -410,  -410,   716,   737,  -410,  -410,  1184,   897,  -410,
       2,   314,    15,     2,   964,  -410,  -410,  1078,  1078,    74,
      74,  1078,  1078,  -410,  -410,  -410,    79,    17,    76,  1078,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,    38,  -410,  -410,  -410,    78,  -410,  -410,
     442,  -410,   101,  -410,   247,   188,  -410,   195,   187,   194,
     200,   129,   159,   124,  -410,  1184,  -410,   212,  -410,   153,
     174,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
      26,  -410,  -410,  -410,  -410,  -410,  -410,  -410,   226,   254,
    -410,  -410,   187,   265,   256,  -410,  -410,  -410,   269,   264,
    -410,   261,   187,  -410,   266,   248,  -410,   262,  -410,    32,
     153,  -410,  -410,   177,    34,  -410,   267,     6,  1078,  -410,
     268,  -410,   221,  -410,  -410,   270,   270,   272,   274,   186,
    1078,   208,   208,  -410,   276,  -410,   277,  -410,   271,   535,
     224,   220,  -410,  -410,   615,   804,   804,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    1078,   977,  1158,  1158,  1158,   291,  -410,   294,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  1184,  1184,  1184,  1184,  -410,
    -410,  1184,  -410,  -410,  1184,  -410,  -410,  -410,  -410,  -410,
    1184,  -410,  1184,   237,   817,   216,   153,  -410,  -410,  -410,
    -410,  -410,    29,    35,   535,  1078,  1171,  1171,  -410,  -410,
    -410,  1078,  -410,  1078,  -410,   628,   217,   153,  -410,  -410,
      24,   133,    25,     2,   219,  -410,  1078,  1078,   222,  1078,
     535,   703,   535,  -410,   286,  -410,  -410,  1078,    60,  1078,
     296,  -410,   165,  1184,   535,  1078,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,  -410,   253,   188,  -410,  -410,  -410,   187,
     194,   200,   129,   159,   124,  -410,  -410,  -410,  1078,  1078,
     146,   295,   287,  -410,  -410,   990,   293,   299,   298,  -410,
    -410,  -410,  -410,   227,   227,   300,   305,  -410,   302,  -410,
     297,   535,  1078,  -410,   307,  -410,   187,   323,  -410,   315,
     321,   320,  -410,   251,  -410,   278,  -410,   319,    28,   251,
    -410,  -410,    11,  -410,  -410,  -410,  -410,  -410,   338,   324,
     328,  -410,    16,   326,  -410,  -410,  -410,  -410,   446,  1078,
     330,    31,   333,   187,  -410,  -410,  1078,  -410,  -410,  1078,
    -410,  -410,   884,  1078,   334,  -410,   990,  -410,  1065,   339,
    -410,  -410,  1078,  -410,    65,  1078,  -410,   343,   263,   535,
    1158,  1078,  -410,   346,   347,   281,   282,   251,  -410,  -410,
     348,   283,   353,   535,   355,   208,  -410,    33,  -410,   356,
     303,   535,   357,   358,   362,   535,  -410,  -410,  1078,  1078,
    -410,  -410,  -410,   334,  -410,  -410,    72,   364,  -410,  -410,
    -410,  -410,   535,   363,  1078,   383,   182,  -410,  -410,  -410,
    -410,   317,   370,  -410,  -410,   535,  -410,   535,  -410,   208,
    -410,  -410,   308,  -410,   535,   535,   535,  -410,   375,  -410,
    -410,   227,  -410,   103,  -410,   535,   378,   379,  1091,  -410,
    -410,  -410,   313,  -410,  -410,  -410,  -410,  -410,   322,  -410,
    -410,   361,  -410,   227,  -410,   535,   535,    52,   197,   402,
    -410,  -410,   388,  1078,  -410,  -410,  -410,  1091,   389,  -410,
     535,  -410,  -410,  1091,  -410,  -410
  };

  const unsigned short int
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,     0,   118,   119,     0,     0,   120,
       0,     0,     0,     0,    44,    25,    26,    29,    27,     0,
       0,     0,     0,   180,   181,   179,     0,     0,     0,     0,
     176,   177,   182,     7,     5,     8,    33,    15,    20,    21,
      22,    23,    24,     0,    13,    14,    12,    38,    32,    51,
      39,    52,    48,    50,    71,    76,    78,    81,    82,    95,
      97,    99,   101,   105,   109,     0,   116,   121,   197,   123,
     178,     9,   191,   192,   194,   195,   193,   196,    73,   274,
       0,   198,    16,   278,   279,    17,    18,    19,     0,     0,
      80,   231,   230,     0,   226,    35,   170,   189,    52,     0,
     172,     0,    47,   174,     0,     0,   184,   185,   306,     0,
     125,   290,   291,     0,     0,   280,   294,   296,     0,    45,
      67,    69,    30,    28,   309,   308,   311,   312,     0,     0,
       0,   264,     0,   270,     0,   258,   256,   266,   268,     0,
     220,     0,   218,    10,     0,     0,     0,    54,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    57,
       0,    49,     0,     0,     0,     0,    93,    94,    86,    87,
      88,    92,    90,    89,    91,     0,     0,     0,     0,   103,
     104,     0,   107,   108,     0,   111,   113,   114,   115,   112,
       0,   117,     0,     0,     0,     0,   124,   127,   183,   277,
     276,   275,     0,     0,     0,     0,   227,     0,   190,   171,
     173,     0,   175,   186,   271,     0,     0,   126,   292,   293,
       0,     0,     0,   295,     0,    46,    68,     0,     0,     0,
       0,     0,     0,   252,   262,   264,   261,     0,     0,     0,
       0,   222,     0,     0,     0,     0,    11,    34,    42,    43,
      40,    41,    37,    53,     0,    77,    79,    84,    85,    83,
      96,    98,   100,   102,   106,   110,   122,   130,     0,     0,
     161,     0,   152,   159,   132,   139,   138,     0,   134,   136,
     129,   128,   234,   244,     0,   250,     0,   238,   236,   246,
     248,     0,     0,   201,     0,   229,   228,     0,   187,     0,
       0,     0,   307,     0,   287,   302,   289,   300,     0,     0,
     281,   283,   298,   297,    70,    31,   310,   313,   203,     0,
       0,   149,     0,   259,   253,   257,   267,   269,     0,   214,
       0,   207,     0,   221,   217,   219,     0,   154,   156,     0,
     162,   131,   153,   147,   141,   140,   143,   133,   135,   242,
     244,   241,     0,   235,     0,     0,   232,     0,   199,     0,
       0,     0,   272,     0,     0,     0,   301,     0,   284,   286,
       0,     0,     0,     0,     0,     0,   265,     0,   205,     0,
     215,     0,     0,     0,     0,     0,    72,   163,     0,     0,
     160,   148,   142,   145,   144,   137,     0,   239,   251,   237,
     247,   249,     0,     0,     0,   224,   166,   188,   273,   288,
     303,   304,     0,   282,   299,     0,   150,     0,   263,     0,
     223,   206,     0,   211,     0,     0,     0,   212,   155,   157,
     146,     0,   245,     0,   233,     0,     0,     0,     0,   167,
     164,   165,     0,   285,   204,   151,   260,   216,   208,   210,
     213,     0,   243,     0,   200,     0,     0,     0,   168,    74,
      75,   305,     0,     0,   240,   202,   225,     0,     0,   169,
       0,   158,   254,     0,   209,   255
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -410,  -410,  -410,  -410,  -410,  -299,    -2,   259,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,   118,
       4,    22,    20,  -410,  -410,   -16,  -410,    -7,  -409,  -169,
     241,    -1,  -410,  -410,     9,   229,   230,   228,  -410,   231,
    -410,   225,  -410,   -44,  -410,  -410,  -410,   304,  -168,  -410,
    -410,    62,  -260,   342,   -60,  -410,    66,   -27,   -98,  -410,
     421,  -410,  -410,  -410,  -410,   438,  -410,  -410,  -410,  -410,
    -410,  -410,  -410,   112,  -410,  -410,   199,  -212,  -410,    -6,
    -410,   366,  -410,  -410,    93,    98,  -410,  -197,  -271,  -410,
    -410,    -5,   213,   218,  -410,  -221,  -136,   374,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -216,  -410,   -14,  -410,
     439,  -410,  -410
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    43,     3,    44,   251,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   170,   129,   130,    63,   468,    64,
      65,    66,    67,   185,    68,    69,    70,    71,   191,    72,
     194,    73,   200,    74,    75,    76,    77,   206,   207,   287,
     288,   289,   355,    78,   281,   282,   283,   449,   450,   451,
      79,    80,   115,   116,   117,   109,    81,    82,   368,    83,
     389,    84,   341,   342,    85,   151,   152,   252,    86,   103,
     104,    87,   213,   296,   297,   359,   298,   442,   300,    88,
     470,   144,   145,   244,   146,   147,   148,    89,    90,    91,
      92,    93,    94,   123,   125,   126,   316,   317,   119,    95,
     135,    96,    97
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      99,    45,   303,   264,   105,   245,   246,   100,   124,   127,
     218,   114,   133,   101,   101,   299,   321,   131,   102,   102,
     132,   131,   360,   361,   137,   138,   112,   336,   328,     5,
     331,   201,   150,   108,   108,   107,   107,   392,   291,   388,
     140,   226,   344,   313,   319,   141,   226,   377,   224,   292,
     121,   225,   314,   320,   153,     4,   378,   293,   301,   291,
       5,     6,     7,   154,   385,   142,     8,   226,   482,   226,
       9,    10,    11,    12,   485,   477,    13,   294,    14,   122,
     141,   429,   234,    15,    16,    17,    98,   381,   141,   366,
     431,    20,   118,   293,   402,    18,   404,   374,   302,   149,
     142,    19,   379,   380,   232,   118,   143,   143,   142,   231,
      36,   386,   155,   294,   315,   315,   339,   393,   315,   295,
     441,   235,    20,   143,    21,   171,    22,    23,    24,    25,
      26,    27,    28,   243,    29,    30,    31,    32,    33,    34,
      35,    36,   143,   440,    37,    38,    39,    40,    41,    42,
     143,   463,   195,   196,   262,   295,   275,   415,   276,   217,
     197,   422,   295,   131,   134,   311,   386,   410,   226,   139,
     462,   426,   203,   266,   204,   189,   190,   259,   261,   433,
     349,   330,   350,   437,   198,   192,   193,   448,   205,   199,
     173,   263,   474,   295,   269,   217,   280,   286,   174,   304,
     444,   416,   448,   318,   175,   241,   176,   177,   131,   242,
     217,   307,   228,   454,   308,   455,   309,   186,   280,   322,
     305,   101,   458,   459,   460,   306,   102,   178,   179,   324,
     325,   188,   327,   464,   280,   180,   181,   182,   183,   187,
     334,   229,   337,   254,   255,   212,     8,   230,   150,   428,
     339,   340,   172,   475,   476,   173,    13,   277,    14,   346,
     202,   173,   343,    15,    16,   278,   208,   118,   484,   413,
     414,   347,   348,   258,   260,    18,   215,   214,   354,   469,
     216,    19,   217,   220,   219,   279,   223,   222,   184,   221,
     237,   233,   236,   456,   238,   367,   239,   240,   143,   247,
     253,   248,   267,   268,    21,   249,   290,   312,   469,   323,
     332,   352,   326,   338,   469,   351,   356,   295,    33,    34,
      35,   357,   358,   362,    37,   363,   364,    40,    41,    42,
     369,   365,   390,    13,   370,    14,    45,   372,   371,   396,
     373,   315,   397,   376,   382,   280,   401,   383,   384,   403,
     387,   286,    18,   391,   375,   408,   395,   353,   411,     5,
       6,     7,   418,   406,   417,     8,   412,   419,   423,     9,
      10,   420,   421,   424,   430,    13,   425,    14,   427,   432,
     434,   435,    15,    16,    17,   436,   445,    45,   443,   447,
     453,   438,   439,   452,    18,    33,    34,    35,   457,   461,
      19,   465,   466,   471,    40,    41,    42,   446,   472,   473,
     173,   480,   483,   257,   265,   270,   272,   271,   400,   274,
     405,    20,   273,    21,   227,    22,    23,    24,    25,    26,
      27,    28,   209,    29,    30,    31,    32,    33,    34,    35,
      36,   479,   120,    37,    38,    39,    40,    41,    42,     5,
       6,     7,   111,   394,   345,     8,   210,   409,   407,     9,
      10,   335,   478,   333,   211,    13,   481,    14,     0,   136,
       0,     0,    15,    16,    17,     0,   156,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     0,     0,     0,     0,
      19,   157,   158,   159,   160,   161,   162,   163,   164,   165,
     166,   167,     0,   168,     0,     0,     0,     0,   169,     0,
       0,    20,     0,    21,     0,    22,    23,    24,    25,    26,
      27,    28,     0,    29,    30,    31,    32,    33,    34,    35,
      36,     0,     0,    37,    38,    39,    40,    41,    42,     6,
       0,     0,     0,     0,     8,     0,     0,     0,     0,    10,
       0,   250,     0,     0,    13,     0,    14,     0,     0,     0,
       0,    15,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    18,     0,     0,     0,     0,     0,    19,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    21,     0,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,     0,    33,    34,    35,     6,
       0,     0,    37,     0,     8,    40,    41,    42,     0,    10,
       0,   256,     0,     0,    13,     0,    14,     8,     0,     0,
       0,    15,    16,    17,     0,     0,     0,    13,   310,    14,
       0,     0,     0,    18,    15,    16,   278,     0,     0,    19,
       0,     0,     0,     0,     0,     0,    18,     0,     0,     0,
       0,     0,    19,     0,     0,     0,   279,     0,     0,     0,
       0,     0,    21,     0,    22,    23,    24,    25,    26,    27,
      28,     0,    29,    30,    31,    21,    33,    34,    35,     0,
       0,     0,    37,     0,     0,    40,    41,    42,     0,    33,
      34,    35,     8,     0,     0,    37,     0,     0,    40,    41,
      42,     0,    13,   329,    14,     8,     0,     0,     0,    15,
      16,   278,     0,     0,     0,    13,   106,    14,     0,     0,
       0,    18,    15,    16,    17,     0,     8,    19,     0,     0,
       0,   279,     0,     0,    18,     0,    13,     0,    14,   110,
      19,     0,     0,    15,    16,    17,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,    21,    33,    34,    35,     0,     0,     0,
      37,     0,     0,    40,    41,    42,     0,    33,    34,    35,
       0,     0,     0,    37,    21,     0,    40,    41,    42,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    33,    34,
      35,     0,     0,    13,    37,    14,     8,    40,    41,    42,
      15,    16,    17,     0,     0,     0,    13,     0,    14,   284,
     285,     0,    18,    15,    16,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    24,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    33,    34,    35,     0,     0,
       0,    37,     0,     8,    40,    41,    42,     0,    33,    34,
      35,     0,     0,    13,    37,    14,     8,    40,    41,    42,
      15,    16,   398,     0,     0,     0,    13,     0,    14,     0,
       0,     0,    18,    15,    16,     0,     0,     0,    19,     0,
       0,     0,   399,     0,     0,    18,   113,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    33,    34,    35,     0,     0,
       0,    37,     0,     8,    40,    41,    42,     0,    33,    34,
      35,     0,     0,    13,    37,    14,     8,    40,    41,    42,
      15,    16,     0,     0,     0,     0,    13,     0,    14,     8,
       0,     0,    18,    15,    16,    17,     0,     0,    19,    13,
       0,    14,     0,   353,     0,    18,    15,    16,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    18,     0,
       0,    21,     0,   128,    19,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    33,    34,    35,     0,     0,
       0,    37,     0,     0,    40,    41,    42,    21,    33,    34,
      35,     0,     0,     0,    37,     0,     0,    40,    41,    42,
       0,    33,    34,    35,     8,     0,     0,    37,     0,     0,
      40,    41,    42,     0,    13,     0,    14,     8,   285,     0,
       0,    15,    16,     0,     0,     0,     0,    13,     0,    14,
       8,     0,     0,    18,    15,    16,     0,     0,     0,    19,
      13,     0,    14,     0,     0,     0,    18,    15,    16,     0,
       0,     0,    19,     0,     0,     0,     0,     0,     0,    18,
       0,     0,    21,     0,     0,    19,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    21,    33,    34,    35,     0,
       0,     0,    37,     0,     0,    40,    41,    42,    21,    33,
      34,    35,     0,     0,     0,    37,     0,     8,    40,    41,
      42,     0,    33,    34,    35,     0,     0,    13,   467,    14,
       0,    40,    41,    42,    15,    16,     0,     0,     0,     0,
      13,     0,    14,     0,     0,     0,    18,    15,    16,    17,
       0,     0,    19,    13,     0,    14,     0,     0,     0,    18,
      15,    16,     0,     0,     0,    19,     0,     0,     0,     0,
       0,     0,    18,     0,     0,    21,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    21,    33,
      34,    35,     0,     0,     0,     0,     0,     0,    40,    41,
      42,    21,    33,    34,    35,     0,     0,     0,     0,     0,
       0,    40,    41,    42,     0,    33,    34,    35,     0,     0,
       0,     0,     0,     0,    40,    41,    42
  };

  const short int
  py_parser::yycheck_[] =
  {
       7,     3,   214,   172,    10,   141,   142,     8,    22,    23,
     108,    18,    28,     9,    10,   212,   232,    24,     9,    10,
      27,    28,   293,   294,    31,    32,    17,   248,   240,     3,
     242,    75,    39,    13,    14,    13,    14,     6,   206,   338,
      23,    35,   254,    19,    19,    28,    35,    19,    16,    20,
      35,    19,    28,    28,    16,     0,    28,    28,    23,   227,
       3,     4,     5,    25,    48,    48,     9,    35,   477,    35,
      13,    14,    15,    16,   483,    23,    19,    48,    21,    64,
      28,    48,    76,    26,    27,    28,    90,    76,    28,   301,
     389,    65,    90,    28,   354,    38,   356,   313,    63,    23,
      48,    44,   318,   319,    70,    90,    90,    90,    48,   123,
      84,   332,    34,    48,    90,    90,    85,    86,    90,    90,
      48,   128,    65,    90,    67,    24,    69,    70,    71,    72,
      73,    74,    75,   140,    77,    78,    79,    80,    81,    82,
      83,    84,    90,   403,    87,    88,    89,    90,    91,    92,
      90,    48,    28,    29,   170,    90,   200,   369,   202,    13,
      36,   377,    90,   170,    90,   225,   387,   364,    35,    90,
     441,   383,    19,   174,    21,    46,    47,   155,   156,   391,
      34,   241,   280,   395,    60,    26,    27,     5,    35,    65,
       8,   171,   463,    90,   185,    13,   203,   204,    10,   215,
     412,   370,     5,    70,     9,    19,    11,    12,   215,    23,
      13,   217,    35,   425,   221,   427,   223,    30,   225,   233,
     216,   217,   434,   435,   436,   216,   217,    32,    33,   236,
     237,    31,   239,   445,   241,    40,    41,    42,    43,    45,
     247,    64,   249,    23,    24,    19,     9,    70,   255,   385,
      85,    86,     5,   465,   466,     8,    19,    20,    21,     6,
      48,     8,   253,    26,    27,    28,    92,    90,   480,     6,
       7,   278,   279,   155,   156,    38,    11,    23,   285,   448,
      24,    44,    13,    22,    20,    48,    24,    39,    93,    23,
      69,    24,    24,   429,    24,   302,    24,    23,    90,    23,
      76,    24,    11,     9,    67,    34,    90,    90,   477,    90,
      24,    24,    90,    17,   483,    20,    23,    90,    81,    82,
      83,    22,    24,    23,    87,    20,    24,    90,    91,    92,
      23,    34,   339,    19,    11,    21,   338,    16,    23,   346,
      20,    90,   349,    24,     6,   352,   353,    23,    20,   356,
      24,   358,    38,    23,    76,   362,    23,    23,   365,     3,
       4,     5,    16,    24,   371,     9,    23,    20,    20,    13,
      14,    90,    90,    90,    18,    19,    23,    21,    23,    76,
      23,    23,    26,    27,    28,    23,    23,   389,    24,     6,
      20,   398,   399,    76,    38,    81,    82,    83,    90,    24,
      44,    23,    23,    90,    90,    91,    92,   414,    86,    48,
       8,    23,    23,   154,   173,   186,   188,   187,   352,   194,
     358,    65,   191,    67,   120,    69,    70,    71,    72,    73,
      74,    75,    90,    77,    78,    79,    80,    81,    82,    83,
      84,   468,    21,    87,    88,    89,    90,    91,    92,     3,
       4,     5,    14,   341,   255,     9,    90,   364,   360,    13,
      14,   248,   467,   245,    90,    19,   473,    21,    -1,    30,
      -1,    -1,    26,    27,    28,    -1,    34,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,
      44,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    -1,    61,    -1,    -1,    -1,    -1,    66,    -1,
      -1,    65,    -1,    67,    -1,    69,    70,    71,    72,    73,
      74,    75,    -1,    77,    78,    79,    80,    81,    82,    83,
      84,    -1,    -1,    87,    88,    89,    90,    91,    92,     4,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    -1,    81,    82,    83,     4,
      -1,    -1,    87,    -1,     9,    90,    91,    92,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    21,     9,    -1,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    19,    20,    21,
      -1,    -1,    -1,    38,    26,    27,    28,    -1,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    -1,    -1,    -1,
      -1,    -1,    67,    -1,    69,    70,    71,    72,    73,    74,
      75,    -1,    77,    78,    79,    67,    81,    82,    83,    -1,
      -1,    -1,    87,    -1,    -1,    90,    91,    92,    -1,    81,
      82,    83,     9,    -1,    -1,    87,    -1,    -1,    90,    91,
      92,    -1,    19,    20,    21,     9,    -1,    -1,    -1,    26,
      27,    28,    -1,    -1,    -1,    19,    20,    21,    -1,    -1,
      -1,    38,    26,    27,    28,    -1,     9,    44,    -1,    -1,
      -1,    48,    -1,    -1,    38,    -1,    19,    -1,    21,    22,
      44,    -1,    -1,    26,    27,    28,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    67,    81,    82,    83,    -1,    -1,    -1,
      87,    -1,    -1,    90,    91,    92,    -1,    81,    82,    83,
      -1,    -1,    -1,    87,    67,    -1,    90,    91,    92,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    81,    82,
      83,    -1,    -1,    19,    87,    21,     9,    90,    91,    92,
      26,    27,    28,    -1,    -1,    -1,    19,    -1,    21,    22,
      23,    -1,    38,    26,    27,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    38,    -1,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    71,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,     9,    90,    91,    92,    -1,    81,    82,
      83,    -1,    -1,    19,    87,    21,     9,    90,    91,    92,
      26,    27,    28,    -1,    -1,    -1,    19,    -1,    21,    -1,
      -1,    -1,    38,    26,    27,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    48,    -1,    -1,    38,    39,    -1,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,     9,    90,    91,    92,    -1,    81,    82,
      83,    -1,    -1,    19,    87,    21,     9,    90,    91,    92,
      26,    27,    -1,    -1,    -1,    -1,    19,    -1,    21,     9,
      -1,    -1,    38,    26,    27,    28,    -1,    -1,    44,    19,
      -1,    21,    -1,    23,    -1,    38,    26,    27,    -1,    -1,
      -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    38,    -1,
      -1,    67,    -1,    69,    44,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    67,    81,    82,    83,    -1,    -1,
      -1,    87,    -1,    -1,    90,    91,    92,    67,    81,    82,
      83,    -1,    -1,    -1,    87,    -1,    -1,    90,    91,    92,
      -1,    81,    82,    83,     9,    -1,    -1,    87,    -1,    -1,
      90,    91,    92,    -1,    19,    -1,    21,     9,    23,    -1,
      -1,    26,    27,    -1,    -1,    -1,    -1,    19,    -1,    21,
       9,    -1,    -1,    38,    26,    27,    -1,    -1,    -1,    44,
      19,    -1,    21,    -1,    -1,    -1,    38,    26,    27,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,    -1,    38,
      -1,    -1,    67,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    81,    82,    83,    -1,
      -1,    -1,    87,    -1,    -1,    90,    91,    92,    67,    81,
      82,    83,    -1,    -1,    -1,    87,    -1,     9,    90,    91,
      92,    -1,    81,    82,    83,    -1,    -1,    19,    87,    21,
      -1,    90,    91,    92,    26,    27,    -1,    -1,    -1,    -1,
      19,    -1,    21,    -1,    -1,    -1,    38,    26,    27,    28,
      -1,    -1,    44,    19,    -1,    21,    -1,    -1,    -1,    38,
      26,    27,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,
      -1,    -1,    38,    -1,    -1,    67,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    67,    81,
      82,    83,    -1,    -1,    -1,    -1,    -1,    -1,    90,    91,
      92,    67,    81,    82,    83,    -1,    -1,    -1,    -1,    -1,
      -1,    90,    91,    92,    -1,    81,    82,    83,    -1,    -1,
      -1,    -1,    -1,    -1,    90,    91,    92
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    95,    96,    98,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    21,    26,    27,    28,    38,    44,
      65,    67,    69,    70,    71,    72,    73,    74,    75,    77,
      78,    79,    80,    81,    82,    83,    84,    87,    88,    89,
      90,    91,    92,    97,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   121,   123,   124,   125,   126,   128,   129,
     130,   131,   133,   135,   137,   138,   139,   140,   147,   154,
     155,   160,   161,   163,   165,   168,   172,   175,   183,   191,
     192,   193,   194,   195,   196,   203,   205,   206,    90,   121,
     125,   114,   128,   173,   174,   173,    20,   115,   116,   159,
      22,   159,   128,    39,   121,   156,   157,   158,    90,   202,
     154,    35,    64,   197,   202,   198,   199,   202,    69,   119,
     120,   121,   121,   119,    90,   204,   204,   121,   121,    90,
      23,    28,    48,    90,   185,   186,   188,   189,   190,    23,
     121,   169,   170,    16,    25,    34,    34,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    61,    66,
     118,    24,     5,     8,    10,     9,    11,    12,    32,    33,
      40,    41,    42,    43,    93,   127,    30,    45,    31,    46,
      47,   132,    26,    27,   134,    28,    29,    36,    60,    65,
     136,   137,    48,    19,    21,    35,   141,   142,    92,   147,
     175,   191,    19,   176,    23,    11,    24,    13,   152,    20,
      22,    23,    39,    24,    16,    19,    35,   141,    35,    64,
      70,   202,    70,    24,    76,   121,    24,    69,    24,    24,
      23,    19,    23,   121,   187,   190,   190,    23,    24,    34,
      16,   100,   171,    76,    23,    24,    16,   101,   113,   115,
     113,   115,   119,   116,   123,   124,   125,    11,     9,   128,
     129,   130,   131,   133,   135,   137,   137,    20,    28,    48,
     121,   148,   149,   150,    22,    23,   121,   143,   144,   145,
      90,   142,    20,    28,    48,    90,   177,   178,   180,   181,
     182,    23,    63,   171,   119,   114,   128,   173,   121,   121,
      20,   148,    90,    19,    28,    90,   200,   201,    70,    19,
      28,   200,   202,    90,   121,   121,    90,   121,   171,    20,
     148,   171,    24,   187,   121,   186,   189,   121,    17,    85,
      86,   166,   167,   128,   171,   170,     6,   121,   121,    34,
     152,    20,    24,    23,   121,   146,    23,    22,    24,   179,
     182,   182,    23,    20,    24,    34,   171,   121,   162,    23,
      11,    23,    16,    20,   200,    76,    24,    19,    28,   200,
     200,    76,     6,    23,    20,    48,   189,    24,    99,   164,
     121,    23,     6,    86,   167,    23,   121,   121,    28,    48,
     150,   121,   146,   121,   146,   145,    24,   179,   121,   178,
     181,   121,    23,     6,     7,   171,   123,   121,    16,    20,
      90,    90,   200,    20,    90,    23,   171,    23,   190,    48,
      18,    99,    76,   171,    23,    23,    23,   171,   121,   121,
     146,    48,   181,    24,   171,    23,   121,     6,     5,   151,
     152,   153,    76,    20,   171,   171,   190,    90,   171,   171,
     171,    24,   182,    48,   171,    23,    23,    87,   122,   123,
     184,    90,    86,    48,   182,   171,   171,    23,   185,   151,
      23,   121,   122,    23,   171,   122
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
     120,   121,   121,   121,   122,   122,   123,   123,   124,   124,
     125,   125,   126,   126,   127,   127,   127,   127,   127,   127,
     127,   127,   127,   127,   127,   128,   128,   129,   129,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   136,   136,   136,   137,   137,   138,   138,
     138,   139,   139,   140,   140,   140,   140,   141,   141,   142,
     142,   142,   142,   142,   143,   143,   144,   144,   145,   145,
     145,   145,   145,   145,   145,   145,   145,   146,   146,   147,
     147,   147,   148,   148,   148,   148,   148,   148,   148,   149,
     149,   150,   150,   150,   151,   151,   152,   152,   153,   153,
     154,   154,   154,   154,   154,   154,   154,   154,   154,   154,
     154,   154,   155,   155,   156,   157,   157,   158,   158,   159,
     159,   160,   160,   160,   160,   160,   160,   160,   160,   161,
     161,   162,   162,   163,   163,   164,   164,   165,   165,   165,
     165,   165,   166,   166,   167,   167,   167,   168,   169,   169,
     170,   170,   171,   171,   172,   172,   173,   173,   174,   174,
     174,   174,   175,   175,   176,   176,   177,   177,   177,   178,
     178,   178,   178,   178,   179,   179,   180,   180,   181,   181,
     182,   182,   183,   183,   184,   184,   185,   185,   185,   186,
     186,   186,   186,   186,   187,   187,   188,   188,   189,   189,
     190,   191,   191,   191,   192,   192,   193,   193,   194,   194,
     195,   196,   196,   196,   196,   196,   196,   196,   196,   196,
     197,   197,   197,   197,   198,   198,   199,   199,   199,   199,
     200,   200,   201,   201,   201,   201,   202,   202,   203,   204,
     204,   205,   206,   206
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
       3,     1,     5,     1,     1,     1,     1,     3,     1,     3,
       2,     1,     1,     3,     2,     2,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     3,     1,     3,     1,
       3,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     2,     1,     1,
       1,     1,     3,     1,     2,     2,     3,     1,     2,     2,
       2,     3,     2,     3,     1,     2,     1,     3,     1,     1,
       2,     2,     3,     2,     3,     3,     4,     1,     2,     4,
       6,     7,     1,     2,     2,     4,     2,     4,     7,     1,
       3,     1,     2,     3,     1,     1,     4,     5,     2,     3,
       2,     3,     2,     3,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     2,     3,     5,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     5,
       8,     0,     5,     4,     7,     1,     2,     4,     7,    10,
       7,     6,     3,     4,     1,     2,     4,     4,     1,     3,
       1,     3,     1,     4,     6,     9,     1,     2,     3,     3,
       1,     1,     5,     7,     2,     3,     1,     3,     1,     3,
       6,     2,     2,     5,     0,     3,     1,     3,     1,     3,
       1,     3,     3,     4,     3,     4,     1,     3,     1,     3,
       6,     2,     2,     5,     0,     3,     1,     3,     1,     3,
       1,     3,     5,     6,     1,     2,     2,     2,     1,     1,
       2,     4,     6,     4,     5,     7,     5,     4,     6,     4,
       1,     1,     2,     2,     1,     2,     1,     3,     3,     5,
       1,     2,     1,     3,     3,     5,     1,     3,     2,     1,
       3,     2,     2,     4
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
  "typedargslist", "tfp_args", "tfp_arglist_trailer", "tfpnamed_args",
  "tfpdef_test", "tfpdef", "lambdef", "lambdef_nocond", "varargslist",
  "vfp_args", "vfp_argslist_trailer", "vfpnamed_args", "vfpdef_test",
  "vfpdef", "decorator", "decorators", "decorated", "import_stmt",
  "import_name", "import_from", "import_dots", "dotted_as_names",
  "dotted_as_names_seq", "import_as_names", "import_as_names_seq",
  "dotted_name", "global_stmt", "name_seq", "nonlocal_stmt", "assert_stmt", YY_NULLPTR
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
     555,   570,   571,   572,   578,   579,   585,   586,   596,   597,
     607,   611,   618,   619,   632,   636,   640,   641,   642,   643,
     644,   645,   646,   647,   648,   655,   656,   665,   666,   675,
     676,   685,   686,   693,   693,   699,   700,   707,   707,   713,
     714,   721,   721,   721,   721,   721,   727,   728,   735,   735,
     735,   741,   742,   751,   752,   761,   765,   774,   775,   789,
     796,   802,   808,   815,   826,   827,   832,   833,   839,   840,
     841,   842,   843,   844,   845,   846,   847,   852,   853,   860,
     864,   868,   889,   895,   903,   910,   918,   925,   931,   946,
     952,   964,   965,   966,   976,   977,   983,   984,   992,   993,
    1007,  1013,  1020,  1024,  1032,  1036,  1041,  1042,  1043,  1044,
    1048,  1052,  1059,  1060,  1087,  1095,  1096,  1103,  1107,  1134,
    1135,  1143,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1158,
    1163,  1172,  1177,  1188,  1192,  1201,  1205,  1230,  1231,  1232,
    1233,  1234,  1239,  1240,  1246,  1247,  1248,  1254,  1258,  1259,
    1265,  1266,  1272,  1276,  1285,  1289,  1298,  1299,  1309,  1315,
    1320,  1321,  1327,  1332,  1342,  1346,  1386,  1393,  1400,  1409,
    1416,  1424,  1430,  1438,  1451,  1455,  1466,  1470,  1478,  1482,
    1496,  1503,  1518,  1519,  1525,  1526,  1563,  1570,  1577,  1586,
    1593,  1601,  1607,  1615,  1628,  1632,  1643,  1647,  1655,  1659,
    1673,  1688,  1692,  1696,  1705,  1706,  1715,  1719,  1727,  1727,
    1732,  1752,  1756,  1760,  1764,  1768,  1772,  1776,  1780,  1784,
    1795,  1800,  1805,  1810,  1822,  1823,  1828,  1832,  1836,  1840,
    1853,  1854,  1858,  1862,  1866,  1870,  1882,  1883,  1896,  1904,
    1905,  1915,  1924,  1928
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

