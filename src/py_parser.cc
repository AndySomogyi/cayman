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

      case 177: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 178: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 179: // tfp_args


        { yyoutput << (yysym.value); }

        break;

      case 180: // tfp_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 181: // tfpnamed_args


        { yyoutput << (yysym.value); }

        break;

      case 182: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 183: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 184: // lambdef


        { yyoutput << (yysym.value); }

        break;

      case 185: // lambdef_nocond


        { yyoutput << (yysym.value); }

        break;

      case 186: // varargslist


        { yyoutput << (yysym.value); }

        break;

      case 187: // vfp_args


        { yyoutput << (yysym.value); }

        break;

      case 188: // vfp_argslist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 189: // vfpnamed_args


        { yyoutput << (yysym.value); }

        break;

      case 190: // vfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 191: // vfpdef


        { yyoutput << (yysym.value); }

        break;

      case 192: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 193: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 194: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 195: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 196: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 197: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 198: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 199: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 200: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 201: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 202: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 203: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 204: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 205: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 206: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 207: // assert_stmt


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
        (yylhs.value) = ctx.ast->CreateExternFunctionDef(yylhs.location, (yystack_[1].value), (yystack_[0].value), NULL, NULL);
    }

    break;

  case 235:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateExternFunctionDef(yylhs.location, (yystack_[4].value), (yystack_[3].value), (yystack_[1].value), NULL);
    }

    break;

  case 236:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateExternFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
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


  const short int py_parser::yypact_ninf_ = -311;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -311,    65,  -311,    58,  -311,   -15,  -311,  1223,  1299,  1303,
    1303,   101,  -311,  -311,   817,   844,  -311,  -311,  1331,  1039,
    -311,   -10,   322,     4,   -10,  1065,  -311,  -311,  1223,  1223,
      79,    79,  1223,  1223,  -311,  -311,  -311,    88,    15,   169,
    1223,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,  -311,   146,  -311,  -311,  -311,   171,  -311,
    -311,   450,  -311,   193,  -311,    84,   202,  -311,   229,   191,
     179,   195,    -6,   177,   199,  -311,  1331,  -311,   182,  -311,
     135,   149,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,    28,  -311,  -311,  -311,  -311,  -311,  -311,  -311,   214,
     215,  -311,  -311,   191,   238,   236,  -311,   175,  -311,  -311,
     254,   248,  -311,   255,   191,  -311,   256,   239,  -311,   257,
    -311,   164,   135,  -311,  -311,   124,    43,  -311,   258,    21,
    1223,  -311,   260,  -311,   218,  -311,  -311,   264,   264,   265,
     267,   187,  1223,   201,   201,  -311,   269,  -311,   271,  -311,
     259,   544,   220,   223,  -311,  -311,   625,   875,   875,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,
    -311,  -311,  1223,  1097,  1299,  1299,  1299,   288,  -311,   291,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  1331,  1331,  1331,
    1331,  -311,  -311,  1331,  -311,  -311,  1331,  -311,  -311,  -311,
    -311,  -311,  1331,  -311,  1331,   701,   951,   210,   135,  -311,
    -311,  -311,  -311,  -311,    62,    29,   544,  1223,  1303,   214,
    1303,  -311,  -311,  -311,  1223,  -311,  1223,  -311,   727,   212,
     135,  -311,  -311,    16,   109,    17,   -10,   213,  -311,  1223,
    1223,   216,  1223,   544,   759,   544,  -311,   280,  -311,  -311,
    1223,    71,  1223,   290,  -311,   170,  1331,   544,  1223,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,   186,   202,  -311,
    -311,  -311,   191,   179,   195,    -6,   177,   199,  -311,  -311,
    -311,  1223,  1223,   141,   285,   284,  -311,  -311,  1173,   286,
     289,   292,  -311,  -311,  -311,  -311,   222,   222,   287,   294,
    -311,   293,  -311,   281,   544,  1223,  -311,   295,  -311,   191,
     261,   310,  -311,   298,   307,   305,  -311,   237,  -311,   250,
    -311,   304,    30,   237,  -311,  -311,    24,  -311,  -311,  -311,
    -311,  -311,   324,   308,   312,  -311,    -1,   306,  -311,  -311,
    -311,  -311,   454,  1223,   311,    32,   313,   191,  -311,  -311,
    1223,  -311,  -311,  1223,  -311,  -311,   972,  1223,   314,  -311,
    1173,  -311,  1195,   309,  -311,  -311,  1223,  -311,    76,  1223,
    -311,   315,   252,   544,  1331,  1299,  1223,  -311,   328,   320,
     263,   266,   237,  -311,  -311,   326,   272,   327,   544,   332,
     201,  -311,     5,  -311,   362,   275,   544,   334,   336,   340,
     544,  -311,  -311,  1223,  1223,  -311,  -311,  -311,   314,  -311,
    -311,    73,   323,  -311,  -311,  -311,  -311,   544,   344,  1223,
     366,   142,   183,  -311,  -311,  -311,  -311,   296,   353,  -311,
    -311,   544,  -311,   544,  -311,   201,  -311,  -311,   297,  -311,
     544,   544,   544,  -311,   354,  -311,  -311,   222,  -311,    78,
    -311,   544,   356,   359,  -311,   544,  1273,  -311,  -311,  -311,
     302,  -311,  -311,  -311,  -311,  -311,   299,  -311,  -311,   329,
    -311,   222,  -311,   544,   544,  -311,    53,    42,   377,  -311,
    -311,   363,  1223,  -311,  -311,  -311,  1273,   370,  -311,   544,
    -311,  -311,  1273,  -311,  -311
  };

  const unsigned short int
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     0,     3,     4,     0,     0,   118,   119,     0,     0,
     120,     0,     0,     0,     0,    44,    25,    26,    29,    27,
       0,     0,     0,     0,   180,   181,   179,     0,     0,     0,
       0,   176,   177,   182,     7,     5,     8,    33,    15,    20,
      21,    22,    23,    24,     0,    13,    14,    12,    38,    32,
      51,    39,    52,    48,    50,    71,    76,    78,    81,    82,
      95,    97,    99,   101,   105,   109,     0,   116,   121,   197,
     123,   178,     9,   191,   192,   194,   195,   193,   196,    73,
     277,     0,   198,    16,   281,   282,    17,    18,    19,     0,
       0,    80,   231,   230,     0,   226,    35,     0,   170,   189,
      52,     0,   172,     0,    47,   174,     0,     0,   184,   185,
     309,     0,   125,   293,   294,     0,     0,   283,   297,   299,
       0,    45,    67,    69,    30,    28,   312,   311,   314,   315,
       0,     0,     0,   267,     0,   273,     0,   261,   259,   269,
     271,     0,   220,     0,   218,    10,     0,     0,     0,    54,
      55,    56,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    57,     0,    49,     0,     0,     0,     0,    93,    94,
      86,    87,    88,    92,    90,    89,    91,     0,     0,     0,
       0,   103,   104,     0,   107,   108,     0,   111,   113,   114,
     115,   112,     0,   117,     0,     0,     0,     0,   124,   127,
     183,   280,   279,   278,     0,     0,     0,     0,   227,     0,
       0,   190,   171,   173,     0,   175,   186,   274,     0,     0,
     126,   295,   296,     0,     0,     0,   298,     0,    46,    68,
       0,     0,     0,     0,     0,     0,   255,   265,   267,   264,
       0,     0,     0,     0,   222,     0,     0,     0,     0,    11,
      34,    42,    43,    40,    41,    37,    53,     0,    77,    79,
      84,    85,    83,    96,    98,   100,   102,   106,   110,   122,
     130,     0,     0,   161,     0,   152,   159,   132,   139,   138,
       0,   134,   136,   129,   128,   237,   247,     0,   253,     0,
     241,   239,   249,   251,     0,     0,   201,     0,   229,   228,
     234,     0,   187,     0,     0,     0,   310,     0,   290,   305,
     292,   303,     0,     0,   284,   286,   301,   300,    70,    31,
     313,   316,   203,     0,     0,   149,     0,   262,   256,   260,
     270,   272,     0,   214,     0,   207,     0,   221,   217,   219,
       0,   154,   156,     0,   162,   131,   153,   147,   141,   140,
     143,   133,   135,   245,   247,   244,     0,   238,     0,     0,
     232,     0,   199,     0,     0,     0,     0,   275,     0,     0,
       0,   304,     0,   287,   289,     0,     0,     0,     0,     0,
       0,   268,     0,   205,     0,   215,     0,     0,     0,     0,
       0,    72,   163,     0,     0,   160,   148,   142,   145,   144,
     137,     0,   242,   254,   240,   250,   252,     0,     0,     0,
     224,     0,   166,   188,   276,   291,   306,   307,     0,   285,
     302,     0,   150,     0,   266,     0,   223,   206,     0,   211,
       0,     0,     0,   212,   155,   157,   146,     0,   248,     0,
     233,     0,     0,     0,   235,     0,     0,   167,   164,   165,
       0,   288,   204,   151,   263,   216,   208,   210,   213,     0,
     246,     0,   200,     0,     0,   236,     0,   168,    74,    75,
     308,     0,     0,   243,   202,   225,     0,     0,   169,     0,
     158,   257,     0,   209,   258
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -311,  -311,  -311,  -311,  -311,  -310,    -2,   242,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,  -311,   119,
       6,    20,     9,  -311,  -311,   -20,  -311,    -7,  -284,  -172,
     224,    11,  -311,  -311,    -4,   207,   211,   219,  -311,   209,
    -311,   221,  -311,   -46,  -311,  -311,  -311,   300,  -142,  -311,
    -311,    41,  -309,   317,  -176,  -311,    54,   -66,   -93,  -311,
     394,  -311,  -311,  -311,  -311,   403,  -311,  -311,  -311,  -311,
    -311,  -311,  -311,    74,  -311,  -311,   162,  -187,  -311,     3,
    -311,   330,   204,  -311,    56,    61,  -311,  -194,  -286,  -311,
    -311,   -50,   176,   181,  -311,  -224,  -140,   348,  -311,  -311,
    -311,  -311,  -311,  -311,  -311,  -311,  -207,  -311,   -16,  -311,
     400,  -311,  -311
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    44,     3,    45,   254,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,   172,   131,   132,    64,   477,    65,
      66,    67,    68,   187,    69,    70,    71,    72,   193,    73,
     196,    74,   202,    75,    76,    77,    78,   208,   209,   290,
     291,   292,   359,    79,   284,   285,   286,   457,   458,   459,
      80,    81,   117,   118,   119,   111,    82,    83,   372,    84,
     394,    85,   345,   346,    86,   153,   154,   255,    87,   104,
     105,    88,   215,   299,   300,   363,   301,   448,   303,    89,
     479,   146,   147,   247,   148,   149,   150,    90,    91,    92,
      93,    94,    95,   125,   127,   128,   320,   321,   121,    96,
     137,    97,    98
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
     100,    46,   267,   248,   249,   103,   103,   126,   129,   135,
     364,   365,   116,   106,   114,   102,   102,   221,   133,   101,
     302,   134,   133,   110,   110,   139,   140,   340,   325,   306,
     203,     5,   393,   152,   109,   109,   317,   323,   397,   142,
     123,   191,   192,    11,   143,   318,   324,   456,   390,   407,
     382,   409,   315,   304,   435,   220,   332,   229,   335,   383,
     229,     5,     6,     7,   144,     4,   294,     8,   334,   124,
     348,     9,    10,    11,    12,    13,    99,   486,    14,   229,
      15,   120,   143,   295,   437,    16,    17,    18,   294,   174,
     145,   296,   175,   305,    21,   120,   145,    19,   237,   446,
     143,   386,   144,    20,   107,   296,   145,   319,   319,   234,
     379,   297,   391,    37,   235,   384,   385,   370,   343,   398,
     144,   319,   447,   238,    21,   297,    22,   471,    23,    24,
      25,    26,    27,    28,    29,   246,    30,    31,    32,    33,
      34,    35,    36,    37,   145,   229,    38,    39,    40,    41,
      42,    43,   265,   298,   220,   205,   278,   206,   279,   454,
     231,   470,   145,   155,   298,   133,   455,   298,   391,   298,
     136,   207,   156,   188,   415,   428,   353,   262,   264,   141,
     322,   227,   266,   272,   228,   483,   420,   269,   456,   232,
     354,   175,   350,   151,   175,   233,   220,   307,   283,   289,
     229,   432,   491,   422,   194,   195,   157,   244,   494,   439,
     133,   245,   176,   443,   309,   120,   103,   312,   173,   313,
     326,   283,   188,   311,   308,   189,   102,   190,   197,   198,
     450,   204,   328,   329,   214,   331,   199,   283,   177,   216,
     178,   179,   210,   338,   462,   341,   463,   257,   258,   217,
     434,   152,   347,   466,   467,   468,   343,   344,   418,   419,
     200,   218,   180,   181,   472,   201,   219,   220,   475,   222,
     182,   183,   184,   185,   351,   352,   261,   263,   223,   225,
     224,   358,   226,   236,   478,   239,   484,   485,   240,   241,
     242,   243,   145,   250,   252,   464,   251,   256,   371,   270,
     271,   293,   493,   316,   327,   336,   355,   330,   342,   356,
     360,   366,   361,   298,   478,   367,   369,   362,   368,   373,
     478,   375,   376,   186,   377,   374,   378,   380,   319,   381,
     387,   392,   388,   389,   411,   396,   395,   400,   357,   417,
      46,   425,    14,   401,    15,   424,   402,   429,   449,   283,
     406,   431,   438,   408,   426,   289,   433,   427,   440,   413,
     441,    19,   416,   430,   442,     5,     6,     7,   451,   423,
     421,     8,   453,   460,   461,     9,    10,    11,   482,   469,
     473,   436,    14,   474,    15,   175,   481,   489,   465,    16,
      17,    18,    46,   480,   492,   273,   444,   445,   260,   268,
     274,    19,   276,   410,    34,    35,    36,    20,   211,   275,
     405,   488,   452,    41,    42,    43,   122,   277,   113,   399,
     349,   212,   230,   310,   414,   412,   487,   339,    21,   337,
      22,   138,    23,    24,    25,    26,    27,    28,    29,   213,
      30,    31,    32,    33,    34,    35,    36,    37,     0,     0,
      38,    39,    40,    41,    42,    43,     0,     5,     6,     7,
       0,     0,     0,     8,     0,     0,     0,     9,    10,    11,
       0,     0,     0,     0,    14,   490,    15,     0,     0,     0,
       0,    16,    17,    18,     0,   158,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,    20,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,     0,   170,     0,     0,     0,     0,   171,     0,     0,
      21,     0,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,    33,    34,    35,    36,    37,
       0,     0,    38,    39,    40,    41,    42,    43,     6,     0,
       0,     0,     0,     8,     0,     0,     0,     0,    10,     0,
       0,   253,     0,     0,    14,     0,    15,     0,     0,     0,
       0,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     0,     0,     0,     0,     0,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    22,     0,    23,    24,    25,    26,    27,    28,
      29,     0,    30,    31,    32,     0,    34,    35,    36,     6,
       0,     0,    38,     0,     8,    41,    42,    43,     0,    10,
       0,     0,   259,     0,     0,    14,     0,    15,     0,     0,
       0,     0,    16,    17,    18,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    22,     0,    23,    24,    25,    26,    27,
      28,    29,     0,    30,    31,    32,     0,    34,    35,    36,
       8,     0,     0,    38,     0,     0,    41,    42,    43,     0,
       0,    14,   280,    15,     0,     0,     0,     0,    16,    17,
     281,     0,     0,     0,     0,     0,     8,     0,     0,     0,
      19,     0,     0,     0,     0,     0,    20,    14,   314,    15,
     282,     0,     0,     0,    16,    17,   281,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    19,     0,     8,    22,
       0,     0,    20,     0,     0,     0,   282,     0,     0,    14,
     333,    15,     0,    34,    35,    36,    16,    17,   281,    38,
       0,     0,    41,    42,    43,    22,     0,     0,    19,     0,
       0,     0,     0,     0,    20,     0,     0,     0,   282,    34,
      35,    36,     0,     0,     0,    38,     0,     0,    41,    42,
      43,     0,     0,     0,     0,     0,     8,    22,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    14,   108,    15,
       0,    34,    35,    36,    16,    17,    18,    38,     0,     0,
      41,    42,    43,     8,     0,     0,    19,     0,     0,     0,
       0,     0,    20,     0,    14,     0,    15,   112,     0,     0,
       0,    16,    17,    18,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    19,     8,    22,     0,     0,     0,    20,
       0,     0,     0,     0,     0,    14,     0,    15,     0,    34,
      35,    36,    16,    17,    18,    38,     0,     0,    41,    42,
      43,     0,    22,     0,    19,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,    34,    35,    36,     0,
       0,     0,    38,     0,     0,    41,    42,    43,     0,     0,
       0,     0,     0,    22,     0,     0,     0,    25,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       8,     0,     0,    38,     0,     0,    41,    42,    43,     0,
       0,    14,     0,    15,   287,   288,     0,     0,    16,    17,
       0,     8,     0,     0,     0,     0,     0,     0,     0,     0,
      19,     0,    14,     0,    15,     0,    20,     0,     0,    16,
      17,   403,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    19,     0,     0,     0,     0,     0,    20,     0,    22,
       0,   404,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,     0,    38,
      22,     0,    41,    42,    43,     0,     0,     0,     8,     0,
       0,     0,     0,     0,    34,    35,    36,     0,     0,    14,
      38,    15,     0,    41,    42,    43,    16,    17,     0,     0,
       0,     0,     0,     0,     8,     0,     0,     0,    19,   115,
       0,     0,     0,     0,    20,    14,     0,    15,     0,     0,
       0,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    19,     0,     8,    22,     0,     0,
      20,     0,     0,     0,     0,     0,     0,    14,     0,    15,
       0,    34,    35,    36,    16,    17,    18,    38,     0,     0,
      41,    42,    43,    22,     0,   130,    19,     0,     0,     0,
       0,     0,    20,     0,     0,     0,     0,    34,    35,    36,
       0,     0,     0,    38,     0,     0,    41,    42,    43,     0,
       0,     0,     0,     0,     0,    22,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    34,
      35,    36,     8,     0,     0,    38,     0,     0,    41,    42,
      43,     0,     0,    14,     0,    15,     0,   357,     0,     0,
      16,    17,     0,     0,     8,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    14,     0,    15,    20,   288,
       0,     0,    16,    17,     0,     0,     0,     0,     0,     0,
       0,     0,     8,     0,    19,     0,     0,     0,     0,     0,
      20,    22,     0,    14,     0,    15,     0,     0,     0,     0,
      16,    17,     0,     0,     0,    34,    35,    36,     0,     0,
       0,    38,    19,    22,    41,    42,    43,     0,    20,     0,
       0,     0,     0,     0,     0,     0,     0,    34,    35,    36,
       0,     0,     8,    38,     0,     0,    41,    42,    43,     0,
       0,    22,     0,    14,     0,    15,     0,     0,     0,     0,
      16,    17,     0,     0,     0,    34,    35,    36,     8,     0,
       0,    38,    19,     0,    41,    42,    43,     0,    20,    14,
       0,    15,     0,    14,     0,    15,    16,    17,     0,     0,
      16,    17,    18,     0,     0,     0,     0,     0,    19,     0,
       0,    22,    19,     0,    20,     0,     0,     0,    20,     0,
       0,    14,     0,    15,     0,    34,    35,    36,    16,    17,
       0,   476,     0,     0,    41,    42,    43,    22,     0,     0,
      19,    22,     0,     0,     0,     0,    20,     0,     0,     0,
       0,    34,    35,    36,     0,    34,    35,    36,     0,     0,
      41,    42,    43,     0,    41,    42,    43,     0,     0,    22,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    34,    35,    36,     0,     0,     0,     0,
       0,     0,    41,    42,    43
  };

  const short int
  py_parser::yycheck_[] =
  {
       7,     3,   174,   143,   144,     9,    10,    23,    24,    29,
     296,   297,    19,    10,    18,     9,    10,   110,    25,     8,
     214,    28,    29,    14,    15,    32,    33,   251,   235,   216,
      76,     3,   342,    40,    14,    15,    20,    20,     6,    24,
      36,    47,    48,    15,    29,    29,    29,     5,    49,   358,
      20,   360,   228,    24,    49,    13,   243,    36,   245,    29,
      36,     3,     4,     5,    49,     0,   208,     9,   244,    65,
     257,    13,    14,    15,    16,    17,    91,    24,    20,    36,
      22,    91,    29,    21,   394,    27,    28,    29,   230,     5,
      91,    29,     8,    64,    66,    91,    91,    39,    77,   408,
      29,    77,    49,    45,     3,    29,    91,    91,    91,   125,
     317,    49,   336,    85,    71,   322,   323,   304,    86,    87,
      49,    91,    49,   130,    66,    49,    68,    49,    70,    71,
      72,    73,    74,    75,    76,   142,    78,    79,    80,    81,
      82,    83,    84,    85,    91,    36,    88,    89,    90,    91,
      92,    93,   172,    91,    13,    20,   202,    22,   204,    17,
      36,   447,    91,    17,    91,   172,    24,    91,   392,    91,
      91,    36,    26,    31,   368,   382,    35,   157,   158,    91,
      71,    17,   173,   187,    20,   471,   373,   176,     5,    65,
     283,     8,     6,    24,     8,    71,    13,   217,   205,   206,
      36,   388,   486,   375,    27,    28,    35,    20,   492,   396,
     217,    24,    10,   400,   218,    91,   220,   224,    25,   226,
     236,   228,    31,   220,   218,    46,   220,    32,    29,    30,
     417,    49,   239,   240,    20,   242,    37,   244,     9,    24,
      11,    12,    93,   250,   431,   252,   433,    24,    25,    11,
     390,   258,   256,   440,   441,   442,    86,    87,     6,     7,
      61,    25,    33,    34,   451,    66,    91,    13,   455,    21,
      41,    42,    43,    44,   281,   282,   157,   158,    23,    40,
      24,   288,    25,    25,   456,    25,   473,   474,    70,    25,
      25,    24,    91,    24,    35,   435,    25,    77,   305,    11,
       9,    91,   489,    91,    91,    25,    21,    91,    18,    25,
      24,    24,    23,    91,   486,    21,    35,    25,    25,    24,
     492,    11,    24,    94,    17,    64,    21,    77,    91,    25,
       6,    25,    24,    21,    25,    24,   343,    24,    24,    24,
     342,    21,    20,   350,    22,    17,   353,    21,    25,   356,
     357,    24,    77,   360,    91,   362,    24,    91,    24,   366,
      24,    39,   369,    91,    24,     3,     4,     5,    24,   376,
     374,     9,     6,    77,    21,    13,    14,    15,    49,    25,
      24,    19,    20,    24,    22,     8,    87,    24,    91,    27,
      28,    29,   394,    91,    24,   188,   403,   404,   156,   175,
     189,    39,   193,   362,    82,    83,    84,    45,    91,   190,
     356,   477,   419,    91,    92,    93,    22,   196,    15,   345,
     258,    91,   122,   219,   368,   364,   476,   251,    66,   248,
      68,    31,    70,    71,    72,    73,    74,    75,    76,    91,
      78,    79,    80,    81,    82,    83,    84,    85,    -1,    -1,
      88,    89,    90,    91,    92,    93,    -1,     3,     4,     5,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    13,    14,    15,
      -1,    -1,    -1,    -1,    20,   482,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    35,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    -1,    62,    -1,    -1,    -1,    -1,    67,    -1,    -1,
      66,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    81,    82,    83,    84,    85,
      -1,    -1,    88,    89,    90,    91,    92,    93,     4,    -1,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,    -1,
      -1,    17,    -1,    -1,    20,    -1,    22,    -1,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    -1,    70,    71,    72,    73,    74,    75,
      76,    -1,    78,    79,    80,    -1,    82,    83,    84,     4,
      -1,    -1,    88,    -1,     9,    91,    92,    93,    -1,    14,
      -1,    -1,    17,    -1,    -1,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    70,    71,    72,    73,    74,
      75,    76,    -1,    78,    79,    80,    -1,    82,    83,    84,
       9,    -1,    -1,    88,    -1,    -1,    91,    92,    93,    -1,
      -1,    20,    21,    22,    -1,    -1,    -1,    -1,    27,    28,
      29,    -1,    -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    20,    21,    22,
      49,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    39,    -1,     9,    68,
      -1,    -1,    45,    -1,    -1,    -1,    49,    -1,    -1,    20,
      21,    22,    -1,    82,    83,    84,    27,    28,    29,    88,
      -1,    -1,    91,    92,    93,    68,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,    49,    82,
      83,    84,    -1,    -1,    -1,    88,    -1,    -1,    91,    92,
      93,    -1,    -1,    -1,    -1,    -1,     9,    68,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    20,    21,    22,
      -1,    82,    83,    84,    27,    28,    29,    88,    -1,    -1,
      91,    92,    93,     9,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    20,    -1,    22,    23,    -1,    -1,
      -1,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    39,     9,    68,    -1,    -1,    -1,    45,
      -1,    -1,    -1,    -1,    -1,    20,    -1,    22,    -1,    82,
      83,    84,    27,    28,    29,    88,    -1,    -1,    91,    92,
      93,    -1,    68,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,    -1,
      -1,    -1,    88,    -1,    -1,    91,    92,    93,    -1,    -1,
      -1,    -1,    -1,    68,    -1,    -1,    -1,    72,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
       9,    -1,    -1,    88,    -1,    -1,    91,    92,    93,    -1,
      -1,    20,    -1,    22,    23,    24,    -1,    -1,    27,    28,
      -1,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      39,    -1,    20,    -1,    22,    -1,    45,    -1,    -1,    27,
      28,    29,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    -1,    68,
      -1,    49,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    88,
      68,    -1,    91,    92,    93,    -1,    -1,    -1,     9,    -1,
      -1,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,    20,
      88,    22,    -1,    91,    92,    93,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    39,    40,
      -1,    -1,    -1,    -1,    45,    20,    -1,    22,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    -1,     9,    68,    -1,    -1,
      45,    -1,    -1,    -1,    -1,    -1,    -1,    20,    -1,    22,
      -1,    82,    83,    84,    27,    28,    29,    88,    -1,    -1,
      91,    92,    93,    68,    -1,    70,    39,    -1,    -1,    -1,
      -1,    -1,    45,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,    -1,    88,    -1,    -1,    91,    92,    93,    -1,
      -1,    -1,    -1,    -1,    -1,    68,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,
      83,    84,     9,    -1,    -1,    88,    -1,    -1,    91,    92,
      93,    -1,    -1,    20,    -1,    22,    -1,    24,    -1,    -1,
      27,    28,    -1,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    -1,    -1,    20,    -1,    22,    45,    24,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,     9,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      45,    68,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    82,    83,    84,    -1,    -1,
      -1,    88,    39,    68,    91,    92,    93,    -1,    45,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    82,    83,    84,
      -1,    -1,     9,    88,    -1,    -1,    91,    92,    93,    -1,
      -1,    68,    -1,    20,    -1,    22,    -1,    -1,    -1,    -1,
      27,    28,    -1,    -1,    -1,    82,    83,    84,     9,    -1,
      -1,    88,    39,    -1,    91,    92,    93,    -1,    45,    20,
      -1,    22,    -1,    20,    -1,    22,    27,    28,    -1,    -1,
      27,    28,    29,    -1,    -1,    -1,    -1,    -1,    39,    -1,
      -1,    68,    39,    -1,    45,    -1,    -1,    -1,    45,    -1,
      -1,    20,    -1,    22,    -1,    82,    83,    84,    27,    28,
      -1,    88,    -1,    -1,    91,    92,    93,    68,    -1,    -1,
      39,    68,    -1,    -1,    -1,    -1,    45,    -1,    -1,    -1,
      -1,    82,    83,    84,    -1,    82,    83,    84,    -1,    -1,
      91,    92,    93,    -1,    91,    92,    93,    -1,    -1,    68,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    91,    92,    93
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    96,    97,    99,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    17,    20,    22,    27,    28,    29,    39,
      45,    66,    68,    70,    71,    72,    73,    74,    75,    76,
      78,    79,    80,    81,    82,    83,    84,    85,    88,    89,
      90,    91,    92,    93,    98,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   122,   124,   125,   126,   127,   129,
     130,   131,   132,   134,   136,   138,   139,   140,   141,   148,
     155,   156,   161,   162,   164,   166,   169,   173,   176,   184,
     192,   193,   194,   195,   196,   197,   204,   206,   207,    91,
     122,   126,   115,   129,   174,   175,   174,     3,    21,   116,
     117,   160,    23,   160,   129,    40,   122,   157,   158,   159,
      91,   203,   155,    36,    65,   198,   203,   199,   200,   203,
      70,   120,   121,   122,   122,   120,    91,   205,   205,   122,
     122,    91,    24,    29,    49,    91,   186,   187,   189,   190,
     191,    24,   122,   170,   171,    17,    26,    35,    35,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      62,    67,   119,    25,     5,     8,    10,     9,    11,    12,
      33,    34,    41,    42,    43,    44,    94,   128,    31,    46,
      32,    47,    48,   133,    27,    28,   135,    29,    30,    37,
      61,    66,   137,   138,    49,    20,    22,    36,   142,   143,
      93,   148,   176,   192,    20,   177,    24,    11,    25,    91,
      13,   153,    21,    23,    24,    40,    25,    17,    20,    36,
     142,    36,    65,    71,   203,    71,    25,    77,   122,    25,
      70,    25,    25,    24,    20,    24,   122,   188,   191,   191,
      24,    25,    35,    17,   101,   172,    77,    24,    25,    17,
     102,   114,   116,   114,   116,   120,   117,   124,   125,   126,
      11,     9,   129,   130,   131,   132,   134,   136,   138,   138,
      21,    29,    49,   122,   149,   150,   151,    23,    24,   122,
     144,   145,   146,    91,   143,    21,    29,    49,    91,   178,
     179,   181,   182,   183,    24,    64,   172,   120,   115,   129,
     177,   174,   122,   122,    21,   149,    91,    20,    29,    91,
     201,   202,    71,    20,    29,   201,   203,    91,   122,   122,
      91,   122,   172,    21,   149,   172,    25,   188,   122,   187,
     190,   122,    18,    86,    87,   167,   168,   129,   172,   171,
       6,   122,   122,    35,   153,    21,    25,    24,   122,   147,
      24,    23,    25,   180,   183,   183,    24,    21,    25,    35,
     172,   122,   163,    24,    64,    11,    24,    17,    21,   201,
      77,    25,    20,    29,   201,   201,    77,     6,    24,    21,
      49,   190,    25,   100,   165,   122,    24,     6,    87,   168,
      24,   122,   122,    29,    49,   151,   122,   147,   122,   147,
     146,    25,   180,   122,   179,   182,   122,    24,     6,     7,
     172,   129,   124,   122,    17,    21,    91,    91,   201,    21,
      91,    24,   172,    24,   191,    49,    19,   100,    77,   172,
      24,    24,    24,   172,   122,   122,   147,    49,   182,    25,
     172,    24,   122,     6,    17,    24,     5,   152,   153,   154,
      77,    21,   172,   172,   191,    91,   172,   172,   172,    25,
     183,    49,   172,    24,    24,   172,    88,   123,   124,   185,
      91,    87,    49,   183,   172,   172,    24,   186,   152,    24,
     122,   123,    24,   172,   123
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
     175,   175,   176,   176,   176,   176,   176,   177,   177,   178,
     178,   178,   179,   179,   179,   179,   179,   180,   180,   181,
     181,   182,   182,   183,   183,   184,   184,   185,   185,   186,
     186,   186,   187,   187,   187,   187,   187,   188,   188,   189,
     189,   190,   190,   191,   192,   192,   192,   193,   193,   194,
     194,   195,   195,   196,   197,   197,   197,   197,   197,   197,
     197,   197,   197,   198,   198,   198,   198,   199,   199,   200,
     200,   200,   200,   201,   201,   202,   202,   202,   202,   203,
     203,   204,   205,   205,   206,   207,   207
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
       1,     1,     5,     7,     4,     7,     8,     2,     3,     1,
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
       0,   203,   203,   227,   235,   239,   248,   252,   273,   277,
     286,   290,   301,   302,   303,   304,   305,   306,   307,   308,
     313,   313,   313,   313,   313,   318,   326,   335,   339,   348,
     352,   356,   363,   371,   375,   386,   395,   412,   416,   420,
     438,   442,   447,   451,   467,   471,   475,   486,   503,   508,
     519,   519,   524,   529,   542,   542,   542,   542,   542,   542,
     542,   542,   542,   543,   543,   543,   543,   550,   551,   558,
     559,   574,   575,   576,   582,   583,   589,   590,   600,   601,
     611,   615,   622,   623,   636,   640,   644,   645,   646,   647,
     648,   649,   650,   651,   652,   659,   660,   669,   670,   679,
     680,   689,   690,   697,   697,   703,   704,   711,   711,   717,
     718,   725,   725,   725,   725,   725,   731,   732,   739,   739,
     739,   745,   746,   755,   756,   765,   769,   778,   779,   793,
     800,   806,   812,   819,   830,   831,   836,   837,   843,   844,
     845,   846,   847,   848,   849,   850,   851,   856,   857,   864,
     868,   872,   893,   899,   907,   914,   922,   929,   935,   950,
     956,   968,   969,   970,   980,   981,   987,   988,   996,   997,
    1011,  1017,  1024,  1028,  1036,  1040,  1045,  1046,  1047,  1048,
    1052,  1056,  1063,  1064,  1091,  1099,  1100,  1107,  1111,  1138,
    1139,  1147,  1148,  1149,  1150,  1151,  1152,  1153,  1154,  1162,
    1167,  1176,  1181,  1192,  1196,  1205,  1209,  1234,  1235,  1236,
    1237,  1238,  1243,  1244,  1250,  1251,  1252,  1258,  1262,  1263,
    1269,  1270,  1276,  1280,  1289,  1293,  1302,  1303,  1313,  1319,
    1324,  1325,  1331,  1336,  1341,  1350,  1355,  1365,  1369,  1409,
    1416,  1423,  1432,  1439,  1447,  1453,  1461,  1474,  1478,  1489,
    1493,  1501,  1505,  1519,  1526,  1541,  1542,  1548,  1549,  1586,
    1593,  1600,  1609,  1616,  1624,  1630,  1638,  1651,  1655,  1666,
    1670,  1678,  1682,  1696,  1711,  1715,  1719,  1728,  1729,  1738,
    1742,  1750,  1750,  1755,  1775,  1779,  1783,  1787,  1791,  1795,
    1799,  1803,  1807,  1818,  1823,  1828,  1833,  1845,  1846,  1851,
    1855,  1859,  1863,  1876,  1877,  1881,  1885,  1889,  1893,  1905,
    1906,  1919,  1927,  1928,  1938,  1947,  1951
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

