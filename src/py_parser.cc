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

      case 15: // "extern"


        { yyoutput << (yysym.value); }

        break;

      case 16: // ENDMARKER


        { yyoutput << (yysym.value); }

        break;

      case 17: // NEWLINE


        { yyoutput << (yysym.value); }

        break;

      case 18: // INDENT


        { yyoutput << (yysym.value); }

        break;

      case 19: // DEDENT


        { yyoutput << (yysym.value); }

        break;

      case 20: // "("


        { yyoutput << (yysym.value); }

        break;

      case 21: // ")"


        { yyoutput << (yysym.value); }

        break;

      case 22: // "["


        { yyoutput << (yysym.value); }

        break;

      case 23: // "]"


        { yyoutput << (yysym.value); }

        break;

      case 24: // ":"


        { yyoutput << (yysym.value); }

        break;

      case 25: // ","


        { yyoutput << (yysym.value); }

        break;

      case 26: // ";"


        { yyoutput << (yysym.value); }

        break;

      case 27: // "+"


        { yyoutput << (yysym.value); }

        break;

      case 28: // "-"


        { yyoutput << (yysym.value); }

        break;

      case 29: // "*"


        { yyoutput << (yysym.value); }

        break;

      case 30: // "/"


        { yyoutput << (yysym.value); }

        break;

      case 31: // "|"


        { yyoutput << (yysym.value); }

        break;

      case 32: // "&"


        { yyoutput << (yysym.value); }

        break;

      case 33: // "<"


        { yyoutput << (yysym.value); }

        break;

      case 34: // ">"


        { yyoutput << (yysym.value); }

        break;

      case 35: // "="


        { yyoutput << (yysym.value); }

        break;

      case 36: // "."


        { yyoutput << (yysym.value); }

        break;

      case 37: // "%"


        { yyoutput << (yysym.value); }

        break;

      case 38: // "`"


        { yyoutput << (yysym.value); }

        break;

      case 39: // "{"


        { yyoutput << (yysym.value); }

        break;

      case 40: // "}"


        { yyoutput << (yysym.value); }

        break;

      case 41: // "=="


        { yyoutput << (yysym.value); }

        break;

      case 42: // "!="


        { yyoutput << (yysym.value); }

        break;

      case 43: // "<="


        { yyoutput << (yysym.value); }

        break;

      case 44: // ">="


        { yyoutput << (yysym.value); }

        break;

      case 45: // "~"


        { yyoutput << (yysym.value); }

        break;

      case 46: // "^"


        { yyoutput << (yysym.value); }

        break;

      case 47: // "<<"


        { yyoutput << (yysym.value); }

        break;

      case 48: // ">>"


        { yyoutput << (yysym.value); }

        break;

      case 49: // "**"


        { yyoutput << (yysym.value); }

        break;

      case 50: // "+="


        { yyoutput << (yysym.value); }

        break;

      case 51: // "-="


        { yyoutput << (yysym.value); }

        break;

      case 52: // "*="


        { yyoutput << (yysym.value); }

        break;

      case 53: // "/="


        { yyoutput << (yysym.value); }

        break;

      case 54: // "%="


        { yyoutput << (yysym.value); }

        break;

      case 55: // "&="


        { yyoutput << (yysym.value); }

        break;

      case 56: // "|="


        { yyoutput << (yysym.value); }

        break;

      case 57: // "^="


        { yyoutput << (yysym.value); }

        break;

      case 58: // "<<="


        { yyoutput << (yysym.value); }

        break;

      case 59: // ">>="


        { yyoutput << (yysym.value); }

        break;

      case 60: // "**="


        { yyoutput << (yysym.value); }

        break;

      case 61: // "//"


        { yyoutput << (yysym.value); }

        break;

      case 62: // "//="


        { yyoutput << (yysym.value); }

        break;

      case 63: // "<-"


        { yyoutput << (yysym.value); }

        break;

      case 64: // "->"


        { yyoutput << (yysym.value); }

        break;

      case 65: // "..."


        { yyoutput << (yysym.value); }

        break;

      case 66: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 67: // "@="


        { yyoutput << (yysym.value); }

        break;

      case 68: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 69: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 70: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 71: // "import"


        { yyoutput << (yysym.value); }

        break;

      case 72: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 73: // "break"


        { yyoutput << (yysym.value); }

        break;

      case 74: // "continue"


        { yyoutput << (yysym.value); }

        break;

      case 75: // "raise"


        { yyoutput << (yysym.value); }

        break;

      case 76: // "return"


        { yyoutput << (yysym.value); }

        break;

      case 77: // "as"


        { yyoutput << (yysym.value); }

        break;

      case 78: // "global"


        { yyoutput << (yysym.value); }

        break;

      case 79: // "nonlocal"


        { yyoutput << (yysym.value); }

        break;

      case 80: // "assert"


        { yyoutput << (yysym.value); }

        break;

      case 81: // "while"


        { yyoutput << (yysym.value); }

        break;

      case 82: // "False"


        { yyoutput << (yysym.value); }

        break;

      case 83: // "None"


        { yyoutput << (yysym.value); }

        break;

      case 84: // "True"


        { yyoutput << (yysym.value); }

        break;

      case 85: // "class"


        { yyoutput << (yysym.value); }

        break;

      case 86: // "except"


        { yyoutput << (yysym.value); }

        break;

      case 87: // "finally"


        { yyoutput << (yysym.value); }

        break;

      case 88: // "lambda"


        { yyoutput << (yysym.value); }

        break;

      case 89: // "try"


        { yyoutput << (yysym.value); }

        break;

      case 90: // "with"


        { yyoutput << (yysym.value); }

        break;

      case 91: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 92: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 93: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 94: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 96: // module


        { yyoutput << (yysym.value); }

        break;

      case 97: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 98: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 99: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 100: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 101: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 102: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 103: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 104: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 105: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 106: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 107: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 108: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 109: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 110: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 111: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 112: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 113: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 114: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 115: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 116: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 117: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 118: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 119: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 120: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 121: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 122: // test


        { yyoutput << (yysym.value); }

        break;

      case 123: // test_nocond


        { yyoutput << (yysym.value); }

        break;

      case 124: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 125: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 126: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 127: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 128: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 129: // expr


        { yyoutput << (yysym.value); }

        break;

      case 130: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 131: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 132: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 133: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 134: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 135: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 136: // term


        { yyoutput << (yysym.value); }

        break;

      case 137: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 138: // factor


        { yyoutput << (yysym.value); }

        break;

      case 139: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 140: // power


        { yyoutput << (yysym.value); }

        break;

      case 141: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 142: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 143: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 144: // subscriptlist


        { yyoutput << (yysym.value); }

        break;

      case 145: // subscript_seq


        { yyoutput << (yysym.value); }

        break;

      case 146: // subscript


        { yyoutput << (yysym.value); }

        break;

      case 147: // sliceop


        { yyoutput << (yysym.value); }

        break;

      case 148: // classdef


        { yyoutput << (yysym.value); }

        break;

      case 149: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 150: // argument_seq


        { yyoutput << (yysym.value); }

        break;

      case 151: // argument


        { yyoutput << (yysym.value); }

        break;

      case 152: // comp_iter


        { yyoutput << (yysym.value); }

        break;

      case 153: // comp_for


        { yyoutput << (yysym.value); }

        break;

      case 154: // comp_if


        { yyoutput << (yysym.value); }

        break;

      case 155: // atom


        { yyoutput << (yysym.value); }

        break;

      case 156: // str


        { yyoutput << (yysym.value); }

        break;

      case 157: // dictorsetmaker


        { yyoutput << (yysym.value); }

        break;

      case 158: // dict


        { yyoutput << (yysym.value); }

        break;

      case 159: // dict_seq


        { yyoutput << (yysym.value); }

        break;

      case 160: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 161: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 162: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 163: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 164: // while_stmt


        { yyoutput << (yysym.value); }

        break;

      case 165: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 166: // try_stmt


        { yyoutput << (yysym.value); }

        break;

      case 167: // except_clause_seq


        { yyoutput << (yysym.value); }

        break;

      case 168: // except_clause


        { yyoutput << (yysym.value); }

        break;

      case 169: // with_stmt


        { yyoutput << (yysym.value); }

        break;

      case 170: // with_item_seq


        { yyoutput << (yysym.value); }

        break;

      case 171: // with_item


        { yyoutput << (yysym.value); }

        break;

      case 172: // suite


        { yyoutput << (yysym.value); }

        break;

      case 173: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 174: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 175: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 176: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 177: // @1


        { yyoutput << (yysym.value); }

        break;

      case 178: // @2


        { yyoutput << (yysym.value); }

        break;

      case 179: // @3


        { yyoutput << (yysym.value); }

        break;

      case 180: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 181: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 182: // tfp_args


        { yyoutput << (yysym.value); }

        break;

      case 183: // tfp_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 184: // tfpnamed_args


        { yyoutput << (yysym.value); }

        break;

      case 185: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 186: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 187: // lambdef


        { yyoutput << (yysym.value); }

        break;

      case 188: // lambdef_nocond


        { yyoutput << (yysym.value); }

        break;

      case 189: // varargslist


        { yyoutput << (yysym.value); }

        break;

      case 190: // vfp_args


        { yyoutput << (yysym.value); }

        break;

      case 191: // vfp_argslist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 192: // vfpnamed_args


        { yyoutput << (yysym.value); }

        break;

      case 193: // vfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 194: // vfpdef


        { yyoutput << (yysym.value); }

        break;

      case 195: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 196: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 197: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 198: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 199: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 200: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 201: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 202: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 203: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 204: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 205: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 206: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 207: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 208: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 209: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 210: // assert_stmt


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
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, ExprContext::Load, (yystack_[2].value), (yystack_[0].value));
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
        a->addValue((yystack_[0].value));
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
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, ExprContext::Load, (yystack_[2].value), (yystack_[0].value));
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
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, ExprContext::Load, NULL, (yystack_[0].value));
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
        s1->value += s2->value;
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
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateExternFunctionDef(yylhs.location, (yystack_[9].value), (yystack_[8].value), NULL, NULL);
    }

    break;

  case 235:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateExternFunctionDef(yylhs.location, (yystack_[17].value), (yystack_[16].value), (yystack_[14].value), NULL);
    }

    break;

  case 236:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateExternFunctionDef(yylhs.location, (yystack_[26].value), (yystack_[25].value), (yystack_[23].value), (yystack_[21].value));
    }

    break;

  case 237:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 238:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 239:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 240:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 241:

    {
        // tfp_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 242:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 243:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 244:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 245:

    {
        // tfp_args: "*" tfp_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 246:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 247:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 248:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, ExprContext::Load, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 249:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 250:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 251:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 252:

    {
        // tfpdef_test : tfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 253:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 254:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 259:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 260:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 261:

    {
        // vfp_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 262:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 263:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 264:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 265:

    {
        // vfp_args: "*" vfp_argslist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 266:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 267:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 268:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, ExprContext::Load, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 269:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 270:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 271:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 272:

    {
        // vfpdef_test : vfpdef "=" test
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 273:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 274:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 275:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 276:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 278:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 279:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 280:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 283:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 284:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 285:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 286:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 287:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 288:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 289:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 290:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 291:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 292:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 293:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 294:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 295:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 296:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 299:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 300:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 301:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 302:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 305:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 306:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 307:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 308:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 310:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 311:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 313:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 314:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 315:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 316:

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


  const short int py_parser::yypact_ninf_ = -390;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -390,    48,  -390,    59,  -390,    -7,  -390,  1112,  1179,  1213,
    1213,  -390,  -390,   767,   802,  -390,  -390,  1246,   936,  -390,
      55,   273,    63,    55,   968,  -390,  -390,  1112,  1112,    89,
      89,  1112,  1112,  -390,  -390,  -390,    97,    28,    83,  1112,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,   175,  -390,  -390,  -390,    43,  -390,  -390,
     366,  -390,   179,  -390,   207,   104,  -390,   219,   198,   167,
     210,   120,   237,   148,  -390,  1246,  -390,   190,  -390,   174,
     154,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
      35,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   229,   230,
    -390,  -390,   198,   245,   247,  -390,  -390,  -390,   265,   258,
    -390,   259,   198,  -390,   260,   243,  -390,   261,  -390,   170,
     174,  -390,  -390,    90,    23,  -390,   262,    25,  1112,  -390,
     263,  -390,   215,  -390,  -390,   266,   266,   267,   272,   235,
    1112,   199,   199,  -390,   275,  -390,   276,  -390,   254,   552,
     223,   242,  -390,  -390,   633,   834,   834,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,
    1112,  1003,  1179,  1179,  1179,   291,  -390,   295,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  1246,  1246,  1246,  1246,  -390,
    -390,  1246,  -390,  -390,  1246,  -390,  -390,  -390,  -390,  -390,
    1246,  -390,  1246,   294,   910,   214,   174,  -390,  -390,  -390,
    -390,  -390,    18,    32,   552,  1112,  1213,  1213,  -390,  -390,
    -390,  1112,  -390,  1112,  -390,   709,   216,   174,  -390,  -390,
      17,   126,    20,    55,   217,  -390,  1112,  1112,   218,  1112,
     552,   735,   552,  -390,   281,  -390,  -390,  1112,    22,  1112,
     292,  -390,   182,  1246,   552,  1112,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,  -390,   187,   104,  -390,  -390,  -390,   198,
     167,   210,   120,   237,   148,  -390,  -390,  -390,  1112,  1112,
      56,   296,   299,  -390,  -390,  1045,   301,   297,   302,  -390,
    -390,  -390,  -390,   228,   228,   304,   305,  -390,   306,  -390,
     303,   552,  1112,  -390,   308,  -390,   198,   318,  -390,   310,
     313,   315,  -390,   249,  -390,   269,  -390,   316,    21,   249,
    -390,  -390,    38,  -390,  -390,  -390,  -390,  -390,   338,   323,
     329,  -390,    -6,   326,  -390,  -390,  -390,  -390,   462,  1112,
     335,    30,   336,   198,  -390,  -390,  1112,  -390,  -390,  1112,
    -390,  -390,   860,  1112,   339,  -390,  1045,  -390,  1079,   328,
    -390,  -390,  1112,  -390,    54,  1112,  -390,   344,   264,   552,
    1179,  1112,  -390,   352,   349,   280,   289,   249,  -390,  -390,
     351,   290,   367,   552,   369,   199,  -390,     4,  -390,   370,
     319,   552,   376,   378,   379,   552,  -390,  -390,  1112,  1112,
    -390,  -390,  -390,   339,  -390,  -390,    72,   380,  -390,  -390,
    -390,  -390,   552,   382,  1112,   398,   233,  -390,  -390,  -390,
    -390,   330,   387,  -390,  -390,   552,  -390,   552,  -390,   199,
    -390,  -390,   320,  -390,   552,   552,   552,  -390,   388,  -390,
    -390,   228,  -390,    74,  -390,   552,   390,   403,  1146,  -390,
    -390,  -390,   321,  -390,  -390,  -390,  -390,  -390,   342,  -390,
    -390,   381,  -390,   228,   416,  -390,   552,   552,    31,    53,
     424,  -390,  -390,   410,  1112,  -390,   432,  -390,  -390,  1146,
     413,  -390,   552,  -390,   348,  -390,  1146,  -390,   229,  -390,
    -390,   441,   444,   373,   229,   393,  1246,   158,  -390,   453,
     466,   383,   229,   408,  1246,    58,   552,  -390
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
     178,     9,   191,   192,   194,   195,   193,   196,    73,   277,
       0,   198,    16,   281,   282,    17,    18,    19,     0,     0,
      80,   231,   230,     0,   226,    35,   170,   189,    52,     0,
     172,     0,    47,   174,     0,     0,   184,   185,   309,     0,
     125,   293,   294,     0,     0,   283,   297,   299,     0,    45,
      67,    69,    30,    28,   312,   311,   314,   315,     0,     0,
       0,   267,     0,   273,     0,   261,   259,   269,   271,     0,
     220,     0,   218,    10,     0,     0,     0,    54,    55,    56,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    57,
       0,    49,     0,     0,     0,     0,    93,    94,    86,    87,
      88,    92,    90,    89,    91,     0,     0,     0,     0,   103,
     104,     0,   107,   108,     0,   111,   113,   114,   115,   112,
       0,   117,     0,     0,     0,     0,   124,   127,   183,   280,
     279,   278,     0,     0,     0,     0,   227,     0,   190,   171,
     173,     0,   175,   186,   274,     0,     0,   126,   295,   296,
       0,     0,     0,   298,     0,    46,    68,     0,     0,     0,
       0,     0,     0,   255,   265,   267,   264,     0,     0,     0,
       0,   222,     0,     0,     0,     0,    11,    34,    42,    43,
      40,    41,    37,    53,     0,    77,    79,    84,    85,    83,
      96,    98,   100,   102,   106,   110,   122,   130,     0,     0,
     161,     0,   152,   159,   132,   139,   138,     0,   134,   136,
     129,   128,   237,   247,     0,   253,     0,   241,   239,   249,
     251,     0,     0,   201,     0,   229,   228,     0,   187,     0,
       0,     0,   310,     0,   290,   305,   292,   303,     0,     0,
     284,   286,   301,   300,    70,    31,   313,   316,   203,     0,
       0,   149,     0,   262,   256,   260,   270,   272,     0,   214,
       0,   207,     0,   221,   217,   219,     0,   154,   156,     0,
     162,   131,   153,   147,   141,   140,   143,   133,   135,   245,
     247,   244,     0,   238,     0,     0,   232,     0,   199,     0,
       0,     0,   275,     0,     0,     0,   304,     0,   287,   289,
       0,     0,     0,     0,     0,     0,   268,     0,   205,     0,
     215,     0,     0,     0,     0,     0,    72,   163,     0,     0,
     160,   148,   142,   145,   144,   137,     0,   242,   254,   240,
     250,   252,     0,     0,     0,   224,   166,   188,   276,   291,
     306,   307,     0,   285,   302,     0,   150,     0,   266,     0,
     223,   206,     0,   211,     0,     0,     0,   212,   155,   157,
     146,     0,   248,     0,   233,     0,     0,     0,     0,   167,
     164,   165,     0,   288,   204,   151,   263,   216,   208,   210,
     213,     0,   246,     0,     0,   200,     0,     0,     0,   168,
      74,    75,   308,     0,     0,   243,     0,   202,   225,     0,
       0,   169,     0,   158,     0,   257,     0,   209,     0,   258,
     234,     0,     0,     0,     0,     0,     0,     0,   235,     0,
       0,     0,     0,     0,     0,     0,     0,   236
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -390,  -390,  -390,  -390,  -390,  -296,    -1,   324,  -390,  -390,
    -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,   121,
       6,    16,    12,  -390,  -390,   -17,  -390,    -4,  -389,  -168,
     300,     5,  -390,  -390,    -9,   293,   298,   309,  -390,   286,
    -390,   287,  -390,   -43,  -390,  -390,  -390,   360,  -162,  -390,
    -390,   125,  -198,   396,  -171,  -390,   136,    24,   -96,  -390,
     471,  -390,  -390,  -390,  -390,   480,  -390,  -390,  -390,  -390,
    -390,  -390,  -390,   155,  -390,  -390,   244,  -209,  -390,     7,
    -390,   412,  -390,  -390,  -390,  -254,  -390,   134,   140,  -390,
    -194,  -272,  -390,  -390,    36,   255,   268,  -390,  -214,  -135,
     415,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -390,  -213,
    -390,   -13,  -390,   476,  -390,  -390
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    43,     3,    44,   251,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    60,    61,    62,   170,   129,   130,    63,   469,    64,
      65,    66,    67,   185,    68,    69,    70,    71,   191,    72,
     194,    73,   200,    74,    75,    76,    77,   206,   207,   287,
     288,   289,   355,    78,   281,   282,   283,   449,   450,   451,
      79,    80,   115,   116,   117,   109,    81,    82,   368,    83,
     389,    84,   341,   342,    85,   151,   152,   252,    86,   103,
     104,    87,   464,   491,   499,   213,   296,   297,   359,   298,
     442,   300,    88,   471,   144,   145,   244,   146,   147,   148,
      89,    90,    91,    92,    93,    94,   123,   125,   126,   316,
     317,   119,    95,   135,    96,    97
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
     102,   102,    45,    99,   264,   303,   245,   246,   112,   124,
     127,   133,   218,   100,   114,   101,   101,   105,   299,   321,
     131,   360,   361,   132,   131,   108,   108,   137,   138,   107,
     107,   328,   201,   331,   336,   150,   392,   313,     5,   292,
     319,   377,   388,   385,   291,   344,   314,   293,     4,   320,
     378,   141,   140,   429,   311,   479,   301,   141,   448,   226,
     141,   226,     5,     6,     7,   291,   217,   294,     8,   217,
     330,   142,     9,    10,   226,    11,    12,   142,   155,    13,
     142,    14,   506,   293,    98,   143,    15,    16,    17,   186,
     485,   349,   366,   431,   232,   143,   302,   489,    18,   121,
     374,    20,   234,   294,    19,   379,   380,   149,   315,   295,
     231,   315,   315,   143,   174,   381,   339,   393,   386,   143,
      36,   441,   143,   463,   235,    20,   228,    21,   122,    22,
      23,    24,    25,    26,    27,    28,   243,    29,    30,    31,
      32,    33,    34,    35,    36,   295,   118,    37,    38,    39,
      40,    41,    42,   262,   118,   229,   402,   275,   404,   276,
     415,   230,   226,   295,   422,   295,   131,   189,   190,   462,
     410,   259,   261,   386,   426,   498,   269,   195,   196,   266,
     134,   118,   433,   263,   350,   197,   437,   224,   139,   186,
     225,   475,   153,   346,   203,   173,   204,   318,   304,   280,
     286,   154,   416,   444,   171,   440,   226,   306,   102,   198,
     205,   131,   172,   187,   199,   173,   454,   308,   455,   309,
     322,   280,   305,   101,   307,   458,   459,   460,   175,   186,
     176,   177,   324,   325,   490,   327,   465,   280,   448,   202,
     495,   173,   188,   334,   343,   337,   217,   208,   503,   212,
     428,   150,   178,   179,   214,   241,   215,   477,   478,   242,
     180,   181,   182,   183,   192,   193,   254,   255,   339,   340,
     413,   414,   216,   487,   347,   348,   258,   260,   217,   219,
     470,   354,   220,   222,   221,   237,   223,   233,   236,   249,
     143,   238,   239,    13,   456,    14,   240,   507,   367,   247,
     253,   248,   267,     8,   268,   290,   332,   312,   323,   326,
     338,   470,    18,   184,    13,   277,    14,   351,   470,   295,
     357,    15,    16,   278,   352,   356,   363,   358,   362,   370,
     372,   364,   369,    18,   371,   390,   373,    45,   365,    19,
     315,   376,   396,   279,   382,   397,   375,   383,   280,   401,
     384,   387,   403,   406,   286,    33,    34,    35,   408,   391,
     395,   411,    21,   353,    40,    41,    42,   417,   412,   418,
     419,   420,   423,     5,     6,     7,    33,    34,    35,     8,
     421,   424,    37,     9,    10,    40,    41,    42,    45,   430,
      13,   425,    14,   427,   438,   439,   432,    15,    16,    17,
     434,   156,   435,   436,   447,   443,   445,   452,   453,    18,
     446,   457,   472,   461,   466,    19,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   467,   168,   473,
     474,   476,   173,   169,   482,   484,    20,   486,    21,   488,
      22,    23,    24,    25,    26,    27,    28,   493,    29,    30,
      31,    32,    33,    34,    35,    36,   492,   496,    37,    38,
      39,    40,    41,    42,   494,     5,     6,     7,   500,   501,
     483,     8,   504,   265,   502,     9,    10,   273,   257,   270,
     227,   274,    13,   405,    14,   271,   209,   497,   400,    15,
      16,    17,   120,   481,   111,   505,   394,   272,   409,   345,
     407,    18,   210,   335,   480,   211,   136,    19,     0,     0,
       0,     0,     0,   333,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    20,     0,
      21,     0,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,    32,    33,    34,    35,    36,     0,     0,
      37,    38,    39,    40,    41,    42,     6,     0,     0,     0,
       0,     8,     0,     0,     0,     0,    10,     0,     0,   250,
       0,     0,    13,     0,    14,     0,     0,     0,     0,    15,
      16,    17,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    18,     0,     0,     0,     0,     0,    19,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      21,     0,    22,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,     0,    33,    34,    35,     6,     0,     0,
      37,     0,     8,    40,    41,    42,     0,    10,     0,     0,
     256,     0,     0,    13,     0,    14,     0,     0,     0,     0,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    21,     0,    22,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,     0,    33,    34,    35,     8,     0,
       0,    37,     0,     0,    40,    41,    42,     0,     0,    13,
     310,    14,     0,     0,     0,     0,    15,    16,   278,     0,
       0,     0,     0,     0,     8,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,    13,   329,    14,   279,     0,
       0,     0,    15,    16,   278,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,     0,     8,    21,     0,     0,
      19,     0,     0,     0,   279,     0,     0,    13,   106,    14,
       0,    33,    34,    35,    15,    16,    17,    37,     0,     0,
      40,    41,    42,    21,     0,     0,    18,     0,     0,     0,
       0,     8,    19,     0,     0,     0,     0,    33,    34,    35,
       0,     0,    13,    37,    14,   110,    40,    41,    42,    15,
      16,    17,     0,     0,     0,    21,     0,     0,     0,     0,
       0,    18,     0,     8,     0,     0,     0,    19,     0,    33,
      34,    35,     0,     0,    13,    37,    14,     0,    40,    41,
      42,    15,    16,    17,     0,     0,     0,     0,     0,     8,
      21,     0,     0,    18,     0,     0,     0,     0,     0,    19,
      13,     0,    14,     0,    33,    34,    35,    15,    16,   398,
      37,     0,     0,    40,    41,    42,     0,     0,     0,    18,
       0,     0,    21,     0,     0,    19,    24,     0,     0,   399,
       0,     0,     0,     0,     0,     0,    33,    34,    35,     8,
       0,     0,    37,     0,     0,    40,    41,    42,    21,     0,
      13,     0,    14,   284,   285,     0,     0,    15,    16,     0,
       0,     0,    33,    34,    35,     8,     0,     0,    37,    18,
       0,    40,    41,    42,     0,    19,    13,     0,    14,     0,
       0,     0,     0,    15,    16,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    18,   113,     8,    21,     0,
       0,    19,     0,     0,     0,     0,     0,     0,    13,     0,
      14,     0,    33,    34,    35,    15,    16,     0,    37,     0,
       0,    40,    41,    42,    21,     0,     0,    18,     0,     0,
       0,     0,     8,    19,     0,     0,     0,     0,    33,    34,
      35,     0,     0,    13,    37,    14,     0,    40,    41,    42,
      15,    16,    17,     0,     0,     0,    21,     0,   128,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
      33,    34,    35,     0,     8,     0,    37,     0,     0,    40,
      41,    42,     0,     0,     0,    13,     0,    14,     0,   353,
       0,    21,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    18,    33,    34,    35,     8,     0,
      19,    37,     0,     0,    40,    41,    42,     0,     0,    13,
       0,    14,     0,   285,     0,     0,    15,    16,     0,     0,
       0,     0,     0,    21,     0,     0,     0,     0,    18,     0,
       0,     8,     0,     0,    19,     0,     0,    33,    34,    35,
       0,     0,    13,    37,    14,     0,    40,    41,    42,    15,
      16,     0,     0,     0,     0,     0,     0,    21,     0,     0,
       0,    18,     0,     0,     0,     8,     0,    19,     0,     0,
       0,    33,    34,    35,     0,     0,    13,    37,    14,     0,
      40,    41,    42,    15,    16,     0,     0,     0,     0,     0,
      21,     0,     0,     0,     0,    18,     0,     0,     8,     0,
       0,    19,     0,     0,    33,    34,    35,     0,     0,    13,
      37,    14,     0,    40,    41,    42,    15,    16,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,    18,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    33,    34,
      35,     0,     0,    13,   468,    14,     0,    40,    41,    42,
      15,    16,    17,     0,     0,     0,     0,    21,     0,     0,
       0,     0,    18,     0,     0,     0,     0,     0,    19,     0,
       0,    33,    34,    35,     0,     0,    13,     0,    14,     0,
      40,    41,    42,    15,    16,     0,     0,     0,     0,     0,
       0,    21,     0,     0,     0,    18,     0,     0,     0,     0,
       0,    19,     0,     0,     0,    33,    34,    35,     0,     0,
       0,     0,     0,     0,    40,    41,    42,     0,     0,     0,
       0,     0,     0,     0,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    33,    34,
      35,     0,     0,     0,     0,     0,     0,    40,    41,    42
  };

  const short int
  py_parser::yycheck_[] =
  {
       9,    10,     3,     7,   172,   214,   141,   142,    17,    22,
      23,    28,   108,     8,    18,     9,    10,    10,   212,   232,
      24,   293,   294,    27,    28,    13,    14,    31,    32,    13,
      14,   240,    75,   242,   248,    39,     6,    20,     3,    21,
      20,    20,   338,    49,   206,   254,    29,    29,     0,    29,
      29,    29,    24,    49,   225,    24,    24,    29,     5,    36,
      29,    36,     3,     4,     5,   227,    13,    49,     9,    13,
     241,    49,    13,    14,    36,    16,    17,    49,    35,    20,
      49,    22,    24,    29,    91,    91,    27,    28,    29,    31,
     479,    35,   301,   389,    71,    91,    64,   486,    39,    36,
     313,    66,    77,    49,    45,   318,   319,    24,    91,    91,
     123,    91,    91,    91,    10,    77,    86,    87,   332,    91,
      85,    49,    91,    49,   128,    66,    36,    68,    65,    70,
      71,    72,    73,    74,    75,    76,   140,    78,    79,    80,
      81,    82,    83,    84,    85,    91,    91,    88,    89,    90,
      91,    92,    93,   170,    91,    65,   354,   200,   356,   202,
     369,    71,    36,    91,   377,    91,   170,    47,    48,   441,
     364,   155,   156,   387,   383,    17,   185,    29,    30,   174,
      91,    91,   391,   171,   280,    37,   395,    17,    91,    31,
      20,   463,    17,     6,    20,     8,    22,    71,   215,   203,
     204,    26,   370,   412,    25,   403,    36,   216,   217,    61,
      36,   215,     5,    46,    66,     8,   425,   221,   427,   223,
     233,   225,   216,   217,   217,   434,   435,   436,     9,    31,
      11,    12,   236,   237,   488,   239,   445,   241,     5,    49,
     494,     8,    32,   247,   253,   249,    13,    93,   502,    20,
     385,   255,    33,    34,    24,    20,    11,   466,   467,    24,
      41,    42,    43,    44,    27,    28,    24,    25,    86,    87,
       6,     7,    25,   482,   278,   279,   155,   156,    13,    21,
     448,   285,    23,    40,    24,    70,    25,    25,    25,    35,
      91,    25,    25,    20,   429,    22,    24,   506,   302,    24,
      77,    25,    11,     9,     9,    91,    25,    91,    91,    91,
      18,   479,    39,    94,    20,    21,    22,    21,   486,    91,
      23,    27,    28,    29,    25,    24,    21,    25,    24,    11,
      17,    25,    24,    39,    24,   339,    21,   338,    35,    45,
      91,    25,   346,    49,     6,   349,    77,    24,   352,   353,
      21,    25,   356,    25,   358,    82,    83,    84,   362,    24,
      24,   365,    68,    24,    91,    92,    93,   371,    24,    17,
      21,    91,    21,     3,     4,     5,    82,    83,    84,     9,
      91,    91,    88,    13,    14,    91,    92,    93,   389,    19,
      20,    24,    22,    24,   398,   399,    77,    27,    28,    29,
      24,    35,    24,    24,     6,    25,    24,    77,    21,    39,
     414,    91,    91,    25,    24,    45,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    24,    62,    87,
      49,    15,     8,    67,    24,     3,    66,    24,    68,    91,
      70,    71,    72,    73,    74,    75,    76,     3,    78,    79,
      80,    81,    82,    83,    84,    85,    15,    64,    88,    89,
      90,    91,    92,    93,    91,     3,     4,     5,    15,     3,
     474,     9,    64,   173,    91,    13,    14,   191,   154,   186,
     120,   194,    20,   358,    22,   187,    90,   496,   352,    27,
      28,    29,    21,   469,    14,   504,   341,   188,   364,   255,
     360,    39,    90,   248,   468,    90,    30,    45,    -1,    -1,
      -1,    -1,    -1,   245,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    -1,
      88,    89,    90,    91,    92,    93,     4,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    -1,    14,    -1,    -1,    17,
      -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    70,    71,    72,    73,    74,    75,    76,    -1,
      78,    79,    80,    -1,    82,    83,    84,     4,    -1,    -1,
      88,    -1,     9,    91,    92,    93,    -1,    14,    -1,    -1,
      17,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    70,    71,    72,    73,    74,    75,    76,
      -1,    78,    79,    80,    -1,    82,    83,    84,     9,    -1,
      -1,    88,    -1,    -1,    91,    92,    93,    -1,    -1,    20,
      21,    22,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    20,    21,    22,    49,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,     9,    68,    -1,    -1,
      45,    -1,    -1,    -1,    49,    -1,    -1,    20,    21,    22,
      -1,    82,    83,    84,    27,    28,    29,    88,    -1,    -1,
      91,    92,    93,    68,    -1,    -1,    39,    -1,    -1,    -1,
      -1,     9,    45,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    20,    88,    22,    23,    91,    92,    93,    27,
      28,    29,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    39,    -1,     9,    -1,    -1,    -1,    45,    -1,    82,
      83,    84,    -1,    -1,    20,    88,    22,    -1,    91,    92,
      93,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,     9,
      68,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      20,    -1,    22,    -1,    82,    83,    84,    27,    28,    29,
      88,    -1,    -1,    91,    92,    93,    -1,    -1,    -1,    39,
      -1,    -1,    68,    -1,    -1,    45,    72,    -1,    -1,    49,
      -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,     9,
      -1,    -1,    88,    -1,    -1,    91,    92,    93,    68,    -1,
      20,    -1,    22,    23,    24,    -1,    -1,    27,    28,    -1,
      -1,    -1,    82,    83,    84,     9,    -1,    -1,    88,    39,
      -1,    91,    92,    93,    -1,    45,    20,    -1,    22,    -1,
      -1,    -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,     9,    68,    -1,
      -1,    45,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,
      22,    -1,    82,    83,    84,    27,    28,    -1,    88,    -1,
      -1,    91,    92,    93,    68,    -1,    -1,    39,    -1,    -1,
      -1,    -1,     9,    45,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    20,    88,    22,    -1,    91,    92,    93,
      27,    28,    29,    -1,    -1,    -1,    68,    -1,    70,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      82,    83,    84,    -1,     9,    -1,    88,    -1,    -1,    91,
      92,    93,    -1,    -1,    -1,    20,    -1,    22,    -1,    24,
      -1,    68,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    82,    83,    84,     9,    -1,
      45,    88,    -1,    -1,    91,    92,    93,    -1,    -1,    20,
      -1,    22,    -1,    24,    -1,    -1,    27,    28,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    39,    -1,
      -1,     9,    -1,    -1,    45,    -1,    -1,    82,    83,    84,
      -1,    -1,    20,    88,    22,    -1,    91,    92,    93,    27,
      28,    -1,    -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    39,    -1,    -1,    -1,     9,    -1,    45,    -1,    -1,
      -1,    82,    83,    84,    -1,    -1,    20,    88,    22,    -1,
      91,    92,    93,    27,    28,    -1,    -1,    -1,    -1,    -1,
      68,    -1,    -1,    -1,    -1,    39,    -1,    -1,     9,    -1,
      -1,    45,    -1,    -1,    82,    83,    84,    -1,    -1,    20,
      88,    22,    -1,    91,    92,    93,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    20,    88,    22,    -1,    91,    92,    93,
      27,    28,    29,    -1,    -1,    -1,    -1,    68,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,
      -1,    82,    83,    84,    -1,    -1,    20,    -1,    22,    -1,
      91,    92,    93,    27,    28,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    91,    92,    93,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    91,    92,    93
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    96,    97,    99,     0,     3,     4,     5,     9,    13,
      14,    16,    17,    20,    22,    27,    28,    29,    39,    45,
      66,    68,    70,    71,    72,    73,    74,    75,    76,    78,
      79,    80,    81,    82,    83,    84,    85,    88,    89,    90,
      91,    92,    93,    98,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,   114,   115,
     116,   117,   118,   122,   124,   125,   126,   127,   129,   130,
     131,   132,   134,   136,   138,   139,   140,   141,   148,   155,
     156,   161,   162,   164,   166,   169,   173,   176,   187,   195,
     196,   197,   198,   199,   200,   207,   209,   210,    91,   122,
     126,   115,   129,   174,   175,   174,    21,   116,   117,   160,
      23,   160,   129,    40,   122,   157,   158,   159,    91,   206,
     155,    36,    65,   201,   206,   202,   203,   206,    70,   120,
     121,   122,   122,   120,    91,   208,   208,   122,   122,    91,
      24,    29,    49,    91,   189,   190,   192,   193,   194,    24,
     122,   170,   171,    17,    26,    35,    35,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    62,    67,
     119,    25,     5,     8,    10,     9,    11,    12,    33,    34,
      41,    42,    43,    44,    94,   128,    31,    46,    32,    47,
      48,   133,    27,    28,   135,    29,    30,    37,    61,    66,
     137,   138,    49,    20,    22,    36,   142,   143,    93,   148,
     176,   195,    20,   180,    24,    11,    25,    13,   153,    21,
      23,    24,    40,    25,    17,    20,    36,   142,    36,    65,
      71,   206,    71,    25,    77,   122,    25,    70,    25,    25,
      24,    20,    24,   122,   191,   194,   194,    24,    25,    35,
      17,   101,   172,    77,    24,    25,    17,   102,   114,   116,
     114,   116,   120,   117,   124,   125,   126,    11,     9,   129,
     130,   131,   132,   134,   136,   138,   138,    21,    29,    49,
     122,   149,   150,   151,    23,    24,   122,   144,   145,   146,
      91,   143,    21,    29,    49,    91,   181,   182,   184,   185,
     186,    24,    64,   172,   120,   115,   129,   174,   122,   122,
      21,   149,    91,    20,    29,    91,   204,   205,    71,    20,
      29,   204,   206,    91,   122,   122,    91,   122,   172,    21,
     149,   172,    25,   191,   122,   190,   193,   122,    18,    86,
      87,   167,   168,   129,   172,   171,     6,   122,   122,    35,
     153,    21,    25,    24,   122,   147,    24,    23,    25,   183,
     186,   186,    24,    21,    25,    35,   172,   122,   163,    24,
      11,    24,    17,    21,   204,    77,    25,    20,    29,   204,
     204,    77,     6,    24,    21,    49,   193,    25,   100,   165,
     122,    24,     6,    87,   168,    24,   122,   122,    29,    49,
     151,   122,   147,   122,   147,   146,    25,   183,   122,   182,
     185,   122,    24,     6,     7,   172,   124,   122,    17,    21,
      91,    91,   204,    21,    91,    24,   172,    24,   194,    49,
      19,   100,    77,   172,    24,    24,    24,   172,   122,   122,
     147,    49,   185,    25,   172,    24,   122,     6,     5,   152,
     153,   154,    77,    21,   172,   172,   194,    91,   172,   172,
     172,    25,   186,    49,   177,   172,    24,    24,    88,   123,
     124,   188,    91,    87,    49,   186,    15,   172,   172,    24,
     189,   152,    24,   122,     3,   123,    24,   172,    91,   123,
     180,   178,    15,     3,    91,   180,    64,   129,    17,   179,
      15,     3,    91,   180,    64,   129,    24,   172
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    95,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   102,   102,   102,   102,   102,   102,   102,   102,
     103,   103,   103,   103,   103,   104,   105,   106,   106,   107,
     107,   107,   108,   109,   109,   110,   111,   112,   112,   112,
     113,   113,   113,   113,   114,   114,   114,   115,   116,   116,
     117,   117,   118,   118,   119,   119,   119,   119,   119,   119,
     119,   119,   119,   119,   119,   119,   119,   120,   120,   121,
     121,   122,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   128,   128,   128,   128,   128,   128,
     128,   128,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   132,   132,   133,   133,   134,   134,   135,   135,   136,
     136,   137,   137,   137,   137,   137,   138,   138,   139,   139,
     139,   140,   140,   141,   141,   141,   141,   142,   142,   143,
     143,   143,   143,   143,   144,   144,   145,   145,   146,   146,
     146,   146,   146,   146,   146,   146,   146,   147,   147,   148,
     148,   148,   149,   149,   149,   149,   149,   149,   149,   150,
     150,   151,   151,   151,   152,   152,   153,   153,   154,   154,
     155,   155,   155,   155,   155,   155,   155,   155,   155,   155,
     155,   155,   156,   156,   157,   158,   158,   159,   159,   160,
     160,   161,   161,   161,   161,   161,   161,   161,   161,   162,
     162,   163,   163,   164,   164,   165,   165,   166,   166,   166,
     166,   166,   167,   167,   168,   168,   168,   169,   170,   170,
     171,   171,   172,   172,   173,   173,   174,   174,   175,   175,
     175,   175,   176,   177,   178,   179,   176,   180,   180,   181,
     181,   181,   182,   182,   182,   182,   182,   183,   183,   184,
     184,   185,   185,   186,   186,   187,   187,   188,   188,   189,
     189,   189,   190,   190,   190,   190,   190,   191,   191,   192,
     192,   193,   193,   194,   195,   195,   195,   196,   196,   197,
     197,   198,   198,   199,   200,   200,   200,   200,   200,   200,
     200,   200,   200,   201,   201,   201,   201,   202,   202,   203,
     203,   203,   203,   204,   204,   205,   205,   205,   205,   206,
     206,   207,   208,   208,   209,   210,   210
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
       1,     1,     5,     0,     0,     0,    29,     2,     3,     1,
       3,     1,     3,     6,     2,     2,     5,     0,     3,     1,
       3,     1,     3,     1,     3,     3,     4,     3,     4,     1,
       3,     1,     3,     6,     2,     2,     5,     0,     3,     1,
       3,     1,     3,     1,     3,     5,     6,     1,     2,     2,
       2,     1,     1,     2,     4,     6,     4,     5,     7,     5,
       4,     6,     4,     1,     1,     2,     2,     1,     2,     1,
       3,     3,     5,     1,     2,     1,     3,     3,     5,     1,
       3,     2,     1,     3,     2,     2,     4
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"def\"", "\"pass\"", "\"if\"",
  "\"else\"", "\"elif\"", "\"or\"", "\"not\"", "\"and\"", "\"in\"",
  "\"is\"", "\"for\"", "\"del\"", "\"extern\"", "ENDMARKER", "NEWLINE",
  "INDENT", "DEDENT", "\"(\"", "\")\"", "\"[\"", "\"]\"", "\":\"", "\",\"",
  "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"|\"", "\"&\"", "\"<\"",
  "\">\"", "\"=\"", "\".\"", "\"%\"", "\"`\"", "\"{\"", "\"}\"", "\"==\"",
  "\"!=\"", "\"<=\"", "\">=\"", "\"~\"", "\"^\"", "\"<<\"", "\">>\"",
  "\"**\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"",
  "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"", "\"//\"", "\"//=\"",
  "\"<-\"", "\"->\"", "\"...\"", "\"@\"", "\"@=\"", "\"await\"",
  "\"async\"", "\"from\"", "\"import\"", "\"yield\"", "\"break\"",
  "\"continue\"", "\"raise\"", "\"return\"", "\"as\"", "\"global\"",
  "\"nonlocal\"", "\"assert\"", "\"while\"", "\"False\"", "\"None\"",
  "\"True\"", "\"class\"", "\"except\"", "\"finally\"", "\"lambda\"",
  "\"try\"", "\"with\"", "NAME", "NUMBER", "STRING", "\"<>\"", "$accept",
  "module", "file_input", "newline_or_stmt", "newline_stmt_seq", "stmt",
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
  "for_stmt", "exprlist", "exprlist_seq", "funcdef", "@1", "@2", "@3",
  "parameters", "typedargslist", "tfp_args", "tfp_arglist_trailer",
  "tfpnamed_args", "tfpdef_test", "tfpdef", "lambdef", "lambdef_nocond",
  "varargslist", "vfp_args", "vfp_argslist_trailer", "vfpnamed_args",
  "vfpdef_test", "vfpdef", "decorator", "decorators", "decorated",
  "import_stmt", "import_name", "import_from", "import_dots",
  "dotted_as_names", "dotted_as_names_seq", "import_as_names",
  "import_as_names_seq", "dotted_name", "global_stmt", "name_seq",
  "nonlocal_stmt", "assert_stmt", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   200,   200,   224,   232,   236,   245,   249,   270,   274,
     283,   287,   298,   299,   300,   301,   302,   303,   304,   305,
     310,   310,   310,   310,   310,   315,   323,   332,   336,   345,
     349,   353,   360,   368,   372,   383,   392,   409,   413,   417,
     435,   439,   444,   448,   464,   468,   472,   483,   500,   505,
     516,   516,   521,   526,   539,   539,   539,   539,   539,   539,
     539,   539,   539,   540,   540,   540,   540,   547,   548,   555,
     556,   571,   572,   573,   579,   580,   586,   587,   597,   598,
     608,   612,   619,   620,   633,   637,   641,   642,   643,   644,
     645,   646,   647,   648,   649,   656,   657,   666,   667,   676,
     677,   686,   687,   694,   694,   700,   701,   708,   708,   714,
     715,   722,   722,   722,   722,   722,   728,   729,   736,   736,
     736,   742,   743,   752,   753,   762,   766,   775,   776,   790,
     797,   803,   809,   816,   827,   828,   833,   834,   840,   841,
     842,   843,   844,   845,   846,   847,   848,   853,   854,   861,
     865,   869,   890,   896,   904,   911,   919,   926,   932,   947,
     953,   965,   966,   967,   977,   978,   984,   985,   993,   994,
    1008,  1014,  1021,  1025,  1033,  1037,  1042,  1043,  1044,  1045,
    1049,  1053,  1060,  1061,  1088,  1096,  1097,  1104,  1108,  1135,
    1136,  1144,  1145,  1146,  1147,  1148,  1149,  1150,  1151,  1159,
    1164,  1173,  1178,  1189,  1193,  1202,  1206,  1231,  1232,  1233,
    1234,  1235,  1240,  1241,  1247,  1248,  1249,  1255,  1259,  1260,
    1266,  1267,  1273,  1277,  1286,  1290,  1299,  1300,  1310,  1316,
    1321,  1322,  1328,  1334,  1339,  1348,  1333,  1362,  1366,  1406,
    1413,  1420,  1429,  1436,  1444,  1450,  1458,  1471,  1475,  1486,
    1490,  1498,  1502,  1516,  1523,  1538,  1539,  1545,  1546,  1583,
    1590,  1597,  1606,  1613,  1621,  1627,  1635,  1648,  1652,  1663,
    1667,  1675,  1679,  1693,  1708,  1712,  1716,  1725,  1726,  1735,
    1739,  1747,  1747,  1752,  1772,  1776,  1780,  1784,  1788,  1792,
    1796,  1800,  1804,  1815,  1820,  1825,  1830,  1842,  1843,  1848,
    1852,  1856,  1860,  1873,  1874,  1878,  1882,  1886,  1890,  1902,
    1903,  1916,  1924,  1925,  1935,  1944,  1948
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
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94
    };
    const unsigned int user_token_number_max_ = 349;
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

