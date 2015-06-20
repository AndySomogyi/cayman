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

      case 80: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 81: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 82: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 83: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 85: // module


        { yyoutput << (yysym.value); }

        break;

      case 86: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 87: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 88: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 89: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 90: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 91: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 92: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 93: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 94: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 95: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 96: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 97: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 98: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 99: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 100: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 101: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 102: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 103: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 104: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 105: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 106: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 107: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 108: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 109: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 110: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 111: // test


        { yyoutput << (yysym.value); }

        break;

      case 112: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 113: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 114: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 115: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 116: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 117: // expr


        { yyoutput << (yysym.value); }

        break;

      case 118: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 119: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 120: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 121: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 122: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 123: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 124: // term


        { yyoutput << (yysym.value); }

        break;

      case 125: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 126: // factor


        { yyoutput << (yysym.value); }

        break;

      case 127: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 128: // power


        { yyoutput << (yysym.value); }

        break;

      case 129: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 130: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 131: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 132: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 133: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 134: // argument


        { yyoutput << (yysym.value); }

        break;

      case 135: // atom


        { yyoutput << (yysym.value); }

        break;

      case 136: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 137: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 138: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 139: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 140: // while_stmt


        { yyoutput << (yysym.value); }

        break;

      case 141: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 142: // suite


        { yyoutput << (yysym.value); }

        break;

      case 143: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 144: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 145: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 146: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 147: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 148: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 149: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 150: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 151: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 152: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 153: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 154: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 155: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 156: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 157: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 158: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 159: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 160: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 161: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 162: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 163: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 164: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 165: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 166: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 167: // name_seq


        { yyoutput << (yysym.value); }

        break;

      case 168: // nonlocal_stmt


        { yyoutput << (yysym.value); }

        break;

      case 169: // assert_stmt


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

  case 128:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 129:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 130:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 133:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 134:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 135:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 136:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 137:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 138:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 139:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 146:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 147:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 148:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 149:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 150:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 151:

    {
        (yylhs.value) = ctx.ast->CreateWhile(yylhs.location, (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 152:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 153:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 154:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 155:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 156:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 157:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 159:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 160:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 161:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 164:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 165:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 166:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 167:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 168:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 169:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 170:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 171:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 172:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 173:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 174:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 175:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 176:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 177:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 178:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 179:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 180:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 181:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 182:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 183:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 184:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 185:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[3].value), NULL);
    }

    break;

  case 186:

    {
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[4].value), (yystack_[2].value));
    }

    break;

  case 188:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 189:

    {
        (yylhs.value) = ctx.ast->CreateDecorated(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 192:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 193:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 194:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 195:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 196:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 197:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 198:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 199:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 200:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 201:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 202:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 203:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 204:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 205:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 208:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 209:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 210:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 211:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 214:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 215:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 216:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 217:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 219:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 220:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 222:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 223:

    {
        (yylhs.value) = ctx.ast->CreateNonLocal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 224:

    {
        (yylhs.value) = ctx.ast->CreateAssert(yylhs.location, (yystack_[0].value));
    }

    break;

  case 225:

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
    -237,    39,  -237,   204,  -237,   -37,  -237,   515,   515,     3,
       3,  -237,  -237,   224,  -237,  -237,   119,  -237,    10,    13,
      51,    10,   492,  -237,  -237,   515,   515,    18,    18,   515,
     515,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,   118,  -237,  -237,  -237,    77,  -237,
    -237,   285,  -237,    55,  -237,   146,   107,  -237,    16,    91,
      99,   111,   132,   155,   120,  -237,   119,  -237,   104,    15,
    -237,  -237,  -237,  -237,  -237,  -237,    11,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,   136,   135,  -237,  -237,    91,   151,
     140,  -237,  -237,  -237,   147,    91,  -237,    62,    15,  -237,
    -237,    97,    -2,  -237,   145,   -14,   515,  -237,   170,  -237,
     103,  -237,  -237,   171,   171,   172,   174,  -237,   383,    26,
      26,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,   515,   511,   515,   515,   515,   187,  -237,
     193,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   119,   119,
     119,   119,  -237,  -237,   119,  -237,  -237,   119,  -237,  -237,
    -237,  -237,   119,  -237,   119,   109,   123,    15,  -237,  -237,
    -237,    85,    14,   403,   515,     3,  -237,  -237,   469,   124,
      15,  -237,  -237,    32,     6,    45,    10,   125,  -237,   515,
     515,   126,   515,   403,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,    36,   107,  -237,  -237,  -237,    91,    99,   111,
     132,   155,   120,  -237,  -237,  -237,   515,  -237,   177,   192,
     190,  -237,  -237,  -237,  -237,   141,   141,   199,   195,  -237,
     200,  -237,   182,   403,   515,   208,  -237,  -237,   203,  -237,
      91,   211,   209,  -237,   154,  -237,   160,  -237,   212,    46,
     154,  -237,  -237,     5,  -237,  -237,  -237,  -237,  -237,   231,
     515,  -237,   515,  -237,   481,   214,  -237,  -237,   515,  -237,
      34,   515,  -237,   216,   304,   181,   403,  -237,   225,   220,
     162,   165,   154,  -237,  -237,   226,   167,   230,  -237,  -237,
    -237,   -12,   233,  -237,  -237,  -237,  -237,   403,  -237,   284,
     232,   515,   243,  -237,  -237,  -237,   185,   241,  -237,  -237,
     403,   141,  -237,     7,  -237,  -237,  -237,   403,   240,   244,
     184,  -237,  -237,  -237,   141,  -237,   403,   403,  -237,  -237,
    -237,  -237
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    36,     0,     0,     0,
       0,     3,     4,     0,   113,   114,     0,   115,     0,     0,
       0,     0,    44,    25,    26,    29,    27,     0,     0,     0,
       0,   137,   138,   139,     7,     5,     8,    33,    15,    20,
      21,    22,    23,    24,     0,    13,    14,    12,    38,    32,
      51,    39,    52,    48,    50,    70,    72,    74,    77,    78,
      91,    93,    95,    97,   101,   105,     0,   111,   116,   118,
       9,   141,   142,   143,   144,   187,     0,   145,    16,   190,
     191,    17,    18,    19,     0,     0,    76,   163,   162,     0,
     158,    35,   135,   140,     0,    47,   218,     0,   120,   202,
     203,     0,     0,   192,   206,   208,     0,    45,    66,    68,
      30,    28,   221,   220,   223,   224,     0,    10,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,     0,    49,     0,     0,     0,     0,    89,
      90,    82,    83,    84,    88,    86,    85,    87,     0,     0,
       0,     0,    99,   100,     0,   103,   104,     0,   107,   108,
     109,   110,     0,   112,     0,     0,     0,   119,   122,   189,
     188,     0,     0,     0,     0,   159,   136,   184,     0,     0,
     121,   204,   205,     0,     0,     0,   207,     0,    46,    67,
       0,     0,     0,     0,    11,    34,    42,    43,    40,    41,
      37,    53,     0,    73,    75,    80,    81,    79,    92,    94,
      96,    98,   102,   106,   117,   125,     0,   132,   131,     0,
     127,   129,   124,   123,   166,   176,     0,   182,     0,   170,
     168,   178,   180,     0,     0,     0,   154,   148,     0,   161,
     160,     0,     0,   219,     0,   199,   214,   201,   212,     0,
       0,   193,   195,   210,   209,    69,    31,   222,   225,   150,
       0,   134,     0,   126,   128,   174,   176,   173,     0,   167,
       0,     0,   164,     0,     0,   146,     0,   185,     0,     0,
       0,   213,     0,   196,   198,     0,     0,     0,    71,   133,
     130,     0,   171,   183,   169,   179,   181,     0,   152,     0,
       0,     0,   156,   186,   200,   215,   216,     0,   194,   211,
       0,     0,   177,     0,   165,   155,   153,     0,     0,     0,
       0,   197,   151,   175,     0,   147,     0,     0,   217,   172,
     149,   157
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -237,  -237,  -237,  -237,  -237,  -236,    -3,   148,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    73,
      -5,     0,   157,  -237,  -237,   -24,  -237,    -6,   144,   156,
       4,  -237,  -237,    -1,   150,   164,   143,  -237,   161,  -237,
     159,  -237,   -40,  -237,  -237,  -237,   202,   -79,   142,  -237,
      37,   302,  -237,  -237,  -237,  -237,  -237,  -237,  -187,  -237,
     312,  -237,   248,  -237,  -237,    56,    59,  -237,  -168,  -208,
     251,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -178,
    -237,   -10,  -237,   301,  -237,  -237
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    34,     3,    35,   236,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,    47,    48,    49,
      50,    51,    52,    53,   133,   107,   108,    54,    55,    56,
      57,    58,   148,    59,    60,    61,    62,   154,    63,   157,
      64,   162,    65,    66,    67,    68,   167,   168,   219,   220,
     221,    69,    94,    70,    71,   275,    72,   299,   237,    73,
      89,    90,    74,   172,   228,   229,   265,   230,   312,   232,
      75,    76,    77,    78,    79,    80,   101,   103,   104,   247,
     248,    97,    81,   113,    82,    83
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      36,    85,   111,   231,    87,    87,   259,   252,    88,    88,
     102,   105,    86,    93,     5,    95,   109,   266,   267,   110,
     109,   179,    13,   115,   116,   138,   163,   139,   140,    14,
      15,    16,    13,   179,   165,     8,   311,   233,   298,     4,
     179,   179,   260,    84,   136,    13,   272,    17,   141,   142,
     166,   244,    14,    15,    16,   324,   143,   144,   145,   146,
     245,   187,   225,   316,   250,   282,   279,   185,   227,    19,
      17,   284,   285,   251,   283,   249,    18,   234,   177,   134,
     286,   178,   226,    31,    32,    33,    99,   227,   223,   302,
      96,   184,    19,    31,    32,    33,    22,   179,   112,   147,
     188,   223,   295,   323,   307,   224,    31,    32,    33,   200,
     314,   119,   246,   225,   227,   100,   329,   137,     8,   197,
     199,   149,   213,   322,   214,   246,   246,   109,    13,   215,
     325,    96,   181,   226,   117,    14,    15,    16,    13,   330,
     331,   204,   151,   118,   150,    14,    15,   207,   158,   159,
     238,   135,   164,    17,   136,   171,   160,   216,   173,   218,
     217,   182,   174,    17,   175,   227,   183,   176,   109,   186,
     239,   190,   218,   217,   240,    19,   253,    96,   152,   153,
     161,   155,   156,   255,   256,    19,   258,   300,   301,    31,
      32,    33,   196,   198,   189,   191,   192,   193,   205,    31,
      32,    33,   206,   222,   243,   254,   257,     5,     6,     7,
     261,   262,   263,     8,   264,   269,   271,     9,    10,    11,
      12,   227,   268,    13,   270,   274,   276,   277,   273,   278,
      14,    15,    16,     8,   246,   280,   281,   287,   291,   297,
     304,   303,   305,    13,    92,   306,   308,   309,    17,   319,
      14,    15,    16,   310,   288,   317,   289,   313,   218,   217,
     320,   321,   293,   326,   328,   296,   195,   327,    17,    18,
      19,    36,    20,    21,    22,    23,    24,    25,    26,   202,
      27,    28,    29,    30,    31,    32,    33,     5,     6,     7,
      19,   201,   203,     8,   210,   318,    36,     9,    10,   208,
     180,   290,   315,    13,    31,    32,    33,     5,     6,     7,
      14,    15,    16,     8,   209,   211,   212,     9,    10,   120,
     242,    98,    91,    13,   169,   292,   294,   170,    17,   114,
      14,    15,    16,     0,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,     0,   132,     0,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,     0,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,    30,    31,    32,    33,     6,     0,     0,
       0,     0,     8,     0,     0,     0,     0,    10,     0,   194,
       0,     0,    13,     0,     0,     0,     0,     6,     0,    14,
      15,    16,     8,     0,     0,     0,     0,    10,     0,   235,
       0,     0,    13,     0,     0,     0,     0,    17,     0,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,     0,    19,
       0,    20,    21,    22,    23,    24,    25,    26,     0,    27,
      28,    29,     0,    31,    32,    33,     0,     0,     0,    19,
       0,    20,    21,    22,    23,    24,    25,    26,     8,    27,
      28,    29,     0,    31,    32,    33,     0,     0,    13,   241,
       8,     0,     0,     0,     0,    14,    15,    16,     0,     0,
      13,     8,     0,     0,     0,     0,     0,    14,    15,    16,
       0,    13,     0,    17,     0,     0,     0,   216,    14,    15,
       8,     0,     0,     0,     8,    17,     0,     0,     0,   216,
      13,     0,     0,     0,    13,    19,    17,    14,    15,    16,
       0,    14,    15,     0,     0,     0,     0,    19,     0,    31,
      32,    33,     0,     0,     0,    17,     0,     0,    19,    17,
     106,    31,    32,    33,     0,     0,     0,     0,     0,     0,
       0,     0,    31,    32,    33,     0,     0,    19,     0,     0,
       0,    19,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    31,    32,    33,     0,    31,    32,    33
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,    26,   171,     9,    10,   193,   185,     9,    10,
      20,    21,     8,    13,     3,    16,    22,   225,   226,    25,
      26,    35,    19,    29,    30,     9,    66,    11,    12,    26,
      27,    28,    19,    35,    19,     9,    48,    23,   274,     0,
      35,    35,     6,    80,     8,    19,   233,    44,    32,    33,
      35,    19,    26,    27,    28,    48,    40,    41,    42,    43,
      28,    75,    28,   299,    19,    19,   244,    69,    80,    66,
      44,   249,   250,    28,    28,    69,    65,    63,    16,    24,
      75,    19,    48,    80,    81,    82,    35,    80,   167,   276,
      80,   101,    66,    80,    81,    82,    70,    35,    80,    83,
     106,   180,   270,   311,   282,    20,    80,    81,    82,   133,
     297,    34,    80,    28,    80,    64,   324,    10,     9,   119,
     120,    30,   162,   310,   164,    80,    80,   133,    19,    20,
     317,    80,    35,    48,    16,    26,    27,    28,    19,   326,
     327,   137,    31,    25,    45,    26,    27,   148,    28,    29,
     174,     5,    48,    44,     8,    19,    36,    48,    23,   165,
     165,    64,    11,    44,    24,    80,    69,    20,   174,    24,
     175,    68,   178,   178,   175,    66,   186,    80,    46,    47,
      60,    26,    27,   189,   190,    66,   192,     6,     7,    80,
      81,    82,   119,   120,    24,    24,    24,    23,    11,    80,
      81,    82,     9,    80,    80,    80,    80,     3,     4,     5,
     216,    34,    20,     9,    24,    20,    34,    13,    14,    15,
      16,    80,    23,    19,    24,    17,    23,    16,   234,    20,
      26,    27,    28,     9,    80,    75,    24,     6,    24,    23,
      20,    16,    80,    19,    20,    80,    20,    80,    44,     6,
      26,    27,    28,    23,   260,    23,   262,    24,   264,   264,
      75,    20,   268,    23,    80,   271,   118,    23,    44,    65,
      66,   274,    68,    69,    70,    71,    72,    73,    74,   135,
      76,    77,    78,    79,    80,    81,    82,     3,     4,     5,
      66,   134,   136,     9,   151,   301,   299,    13,    14,   149,
      98,   264,    18,    19,    80,    81,    82,     3,     4,     5,
      26,    27,    28,     9,   150,   154,   157,    13,    14,    34,
     178,    19,    10,    19,    76,   266,   270,    76,    44,    28,
      26,    27,    28,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    -1,    61,    -1,    44,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    79,    80,    81,    82,     4,    -1,    -1,
      -1,    -1,     9,    -1,    -1,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    -1,    -1,    -1,     4,    -1,    26,
      27,    28,     9,    -1,    -1,    -1,    -1,    14,    -1,    16,
      -1,    -1,    19,    -1,    -1,    -1,    -1,    44,    -1,    26,
      27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,    -1,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,    -1,    76,
      77,    78,    -1,    80,    81,    82,    -1,    -1,    -1,    66,
      -1,    68,    69,    70,    71,    72,    73,    74,     9,    76,
      77,    78,    -1,    80,    81,    82,    -1,    -1,    19,    20,
       9,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      19,     9,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    19,    -1,    44,    -1,    -1,    -1,    48,    26,    27,
       9,    -1,    -1,    -1,     9,    44,    -1,    -1,    -1,    48,
      19,    -1,    -1,    -1,    19,    66,    44,    26,    27,    28,
      -1,    26,    27,    -1,    -1,    -1,    -1,    66,    -1,    80,
      81,    82,    -1,    -1,    -1,    44,    -1,    -1,    66,    44,
      68,    80,    81,    82,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    80,    81,    82,    -1,    -1,    66,    -1,    -1,
      -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    80,    81,    82,    -1,    80,    81,    82
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    85,    86,    88,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    26,    27,    28,    44,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    76,    77,    78,
      79,    80,    81,    82,    87,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   105,   106,   107,   111,   112,   113,   114,   115,   117,
     118,   119,   120,   122,   124,   126,   127,   128,   129,   135,
     137,   138,   140,   143,   146,   154,   155,   156,   157,   158,
     159,   166,   168,   169,    80,   111,   114,   104,   117,   144,
     145,   144,    20,   105,   136,   117,    80,   165,   135,    35,
      64,   160,   165,   161,   162,   165,    68,   109,   110,   111,
     111,   109,    80,   167,   167,   111,   111,    16,    25,    34,
      34,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    61,   108,    24,     5,     8,    10,     9,    11,
      12,    32,    33,    40,    41,    42,    43,    83,   116,    30,
      45,    31,    46,    47,   121,    26,    27,   123,    28,    29,
      36,    60,   125,   126,    48,    19,    35,   130,   131,   146,
     154,    19,   147,    23,    11,    24,    20,    16,    19,    35,
     130,    35,    64,    69,   165,    69,    24,    75,   111,    24,
      68,    24,    24,    23,    16,    91,   103,   105,   103,   105,
     109,   106,   112,   113,   114,    11,     9,   117,   118,   119,
     120,   122,   124,   126,   126,    20,    48,   104,   111,   132,
     133,   134,    80,   131,    20,    28,    48,    80,   148,   149,
     151,   152,   153,    23,    63,    16,    90,   142,   109,   104,
     117,    20,   132,    80,    19,    28,    80,   163,   164,    69,
      19,    28,   163,   165,    80,   111,   111,    80,   111,   142,
       6,   111,    34,    20,    24,   150,   153,   153,    23,    20,
      24,    34,   142,   111,    17,   139,    23,    16,    20,   163,
      75,    24,    19,    28,   163,   163,    75,     6,   111,   111,
     134,    24,   150,   111,   149,   152,   111,    23,    89,   141,
       6,     7,   142,    16,    20,    80,    80,   163,    20,    80,
      23,    48,   152,    24,   142,    18,    89,    23,   111,     6,
      75,    20,   142,   153,    48,   142,    23,    23,    80,   153,
     142,   142
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    84,    85,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    91,    91,    91,    91,    91,    91,    91,    91,
      92,    92,    92,    92,    92,    93,    94,    95,    95,    96,
      96,    96,    97,    98,    98,    99,   100,   101,   101,   101,
     102,   102,   102,   102,   103,   103,   103,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   114,   114,   115,   115,
     116,   116,   116,   116,   116,   116,   116,   116,   116,   116,
     116,   117,   117,   118,   118,   119,   119,   120,   120,   121,
     121,   122,   122,   123,   123,   124,   124,   125,   125,   125,
     125,   126,   126,   127,   127,   127,   128,   128,   129,   129,
     129,   129,   130,   130,   131,   131,   131,   132,   132,   133,
     133,   134,   134,   134,   134,   135,   135,   135,   135,   135,
     136,   137,   137,   137,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   143,   143,   144,   144,
     145,   145,   145,   145,   146,   146,   147,   147,   148,   148,
     148,   149,   149,   149,   149,   149,   150,   150,   151,   151,
     152,   152,   153,   153,   154,   154,   154,   155,   155,   156,
     157,   157,   158,   159,   159,   159,   159,   159,   159,   159,
     159,   159,   160,   160,   160,   160,   161,   161,   162,   162,
     162,   162,   163,   163,   164,   164,   164,   164,   165,   165,
     166,   167,   167,   168,   169,   169
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
       2,     3,     1,     2,     2,     2,     3,     1,     2,     1,
       3,     1,     1,     3,     2,     2,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     8,     0,     5,
       4,     7,     1,     2,     1,     4,     6,     9,     1,     2,
       3,     3,     1,     1,     5,     7,     2,     3,     1,     3,
       1,     3,     6,     2,     2,     5,     0,     3,     1,     3,
       1,     3,     1,     3,     3,     5,     6,     1,     2,     2,
       1,     1,     2,     4,     6,     4,     5,     7,     5,     4,
       6,     4,     1,     1,     2,     2,     1,     2,     1,     3,
       3,     5,     1,     2,     1,     3,     3,     5,     1,     3,
       2,     1,     3,     2,     2,     4
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
  "\"while\"", "NAME", "NUMBER", "STRING", "\"<>\"", "$accept", "module",
  "file_input", "newline_or_stmt", "newline_stmt_seq", "stmt",
  "simple_stmt", "small_stmt", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "raise_stmt", "yield_stmt", "small_stmt_seq", "del_stmt",
  "pass_stmt", "expr_stmt", "assign_expr_seq", "yield_expr", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "shift_op", "arith_expr", "arith_op", "term", "term_op",
  "factor", "factor_op", "power", "atom_expr", "trailer_seq", "trailer",
  "arglist", "arglist_seq", "argument", "atom", "testlist_comp",
  "compound_stmt", "if_stmt", "elif_seq", "while_stmt", "stmt_seq",
  "suite", "for_stmt", "exprlist", "exprlist_seq", "funcdef", "parameters",
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
       0,   187,   187,   211,   219,   223,   232,   236,   257,   261,
     271,   275,   286,   287,   288,   289,   290,   291,   292,   293,
     298,   298,   298,   298,   298,   303,   311,   320,   324,   333,
     337,   341,   348,   358,   362,   373,   382,   399,   403,   407,
     425,   429,   434,   438,   465,   469,   473,   494,   516,   521,
     532,   532,   537,   542,   554,   554,   554,   554,   554,   554,
     554,   554,   555,   555,   555,   555,   562,   563,   570,   571,
     586,   587,   593,   594,   604,   605,   615,   619,   626,   627,
     640,   644,   648,   649,   650,   651,   652,   653,   654,   655,
     656,   663,   664,   673,   674,   683,   684,   693,   694,   701,
     701,   707,   708,   715,   715,   721,   722,   729,   729,   729,
     729,   735,   736,   743,   743,   743,   749,   750,   759,   760,
     769,   773,   782,   783,   797,   804,   810,   823,   824,   834,
     838,   859,   860,   861,   865,   899,   905,   912,   913,   914,
     934,   946,   947,   948,   949,   950,   958,   963,   972,   977,
     988,   992,  1018,  1022,  1031,  1035,  1044,  1048,  1057,  1058,
    1068,  1074,  1079,  1080,  1086,  1091,  1101,  1105,  1145,  1152,
    1159,  1168,  1175,  1183,  1189,  1197,  1210,  1214,  1225,  1229,
    1237,  1241,  1254,  1261,  1275,  1279,  1283,  1292,  1293,  1302,
    1310,  1310,  1315,  1335,  1339,  1343,  1347,  1351,  1355,  1359,
    1363,  1367,  1378,  1383,  1388,  1393,  1405,  1406,  1411,  1415,
    1419,  1423,  1436,  1437,  1441,  1445,  1449,  1453,  1465,  1466,
    1479,  1487,  1488,  1498,  1507,  1511
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
      75,    76,    77,    78,    79,    80,    81,    82,    83
    };
    const unsigned int user_token_number_max_ = 338;
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

