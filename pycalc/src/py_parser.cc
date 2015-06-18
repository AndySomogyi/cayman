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

      case 62: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 63: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 64: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 65: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 66: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 67: // "break"


        { yyoutput << (yysym.value); }

        break;

      case 68: // "continue"


        { yyoutput << (yysym.value); }

        break;

      case 69: // "raise"


        { yyoutput << (yysym.value); }

        break;

      case 70: // "return"


        { yyoutput << (yysym.value); }

        break;

      case 71: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 72: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 73: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 74: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 75: // "->"


        { yyoutput << (yysym.value); }

        break;

      case 77: // module


        { yyoutput << (yysym.value); }

        break;

      case 78: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 79: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 80: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 81: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 82: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 83: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 84: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 85: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 86: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 87: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 88: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 89: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 90: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 91: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 92: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 93: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 94: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 95: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 96: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 97: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 98: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 99: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 100: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 101: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 102: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 103: // test


        { yyoutput << (yysym.value); }

        break;

      case 104: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 105: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 106: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 107: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 108: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 109: // expr


        { yyoutput << (yysym.value); }

        break;

      case 110: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 111: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 112: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 113: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 114: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 115: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 116: // term


        { yyoutput << (yysym.value); }

        break;

      case 117: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 118: // factor


        { yyoutput << (yysym.value); }

        break;

      case 119: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 120: // power


        { yyoutput << (yysym.value); }

        break;

      case 121: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 122: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 123: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 124: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 125: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 126: // argument


        { yyoutput << (yysym.value); }

        break;

      case 127: // atom


        { yyoutput << (yysym.value); }

        break;

      case 128: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 129: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 130: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 131: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 132: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 133: // suite


        { yyoutput << (yysym.value); }

        break;

      case 134: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 135: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 136: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 137: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 138: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 139: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 140: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 141: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 142: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 143: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 144: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 145: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 146: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 147: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 148: // dotted_name


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

  case 21:

    {
        (yylhs.value) = ctx.ast->CreateBreak(yylhs.location);
    }

    break;

  case 22:

    {
        (yylhs.value) = ctx.ast->CreateContinue(yylhs.location);
    }

    break;

  case 23:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location);
    }

    break;

  case 24:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location, (yystack_[0].value));
    }

    break;

  case 25:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location);
    }

    break;

  case 26:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[0].value));
    }

    break;

  case 27:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 29:

    {
        (yylhs.value) = (yystack_[0].value); // small_stmt_seq: small_stmt
    }

    break;

  case 30:

    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value)); 
    }

    break;

  case 31:

    {
        (yylhs.value) = ctx.ast->CreateDelete(yylhs.location, (yystack_[0].value));
    }

    break;

  case 32:

    {
        (yylhs.value) = ctx.ast->CreatePass(yylhs.location);
    }

    break;

  case 33:

    {
        (yylhs.value) = ctx.ast->CreateAugAssign(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 34:

    {
        (yylhs.value) = (yystack_[0].value);  /*foo*/
    }

    break;

  case 35:

    {
        (yylhs.value) = (yystack_[0].value); // expr_stmt: testlist_star_expr
    }

    break;

  case 36:

    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 37:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 38:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 39:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 40:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location);
    }

    break;

  case 41:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location, (yystack_[0].value));
    }

    break;

  case 42:

    {
        (yylhs.value) = ctx.ast->CreateYieldFrom(yylhs.location, (yystack_[0].value));
    }

    break;

  case 43:

    {
        (yylhs.value) = ctx.ast->CreateStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 44:

    {
        AstNode *a1 = (yystack_[0].value);
        (yylhs.value) = (yystack_[0].value); // testlist_star_expr:  test_star_expr_seq
    }

    break;

  case 45:

    {
        AstNode *a1 = (yystack_[1].value);
        (yylhs.value) = (yystack_[1].value); // testlist_star_expr: test_star_expr_seq ","
    }

    break;

  case 48:

    {
        // test_star_expr_seq: test_star_expr
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 49:

    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 65:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 69:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 71:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 72:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 75:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 76:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 77:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
    }

    break;

  case 88:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 90:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
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

  case 108:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 113:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 115:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 116:

    {
        assert(0);
    }

    break;

  case 117:

    {
        assert(0);
    }

    break;

  case 119:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 120:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 121:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 122:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[1].value));
    }

    break;

  case 124:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 125:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 126:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 129:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 130:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 131:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 132:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 133:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 134:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 135:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 141:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 142:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 143:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 144:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 145:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 146:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 147:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 148:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 149:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 150:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 152:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 153:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 154:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 157:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 158:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[0].value));
    }

    break;

  case 159:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 160:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 161:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 162:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 163:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 164:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 165:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 166:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 167:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 168:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 169:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 170:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 171:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 173:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 174:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 175:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 176:

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
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
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


  const short int py_parser::yypact_ninf_ = -180;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -180,    26,  -180,    28,  -180,   -36,  -180,   443,   443,   463,
     463,  -180,  -180,   374,  -180,  -180,   459,  -180,    -9,    33,
     400,  -180,  -180,   443,   443,  -180,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,    41,  -180,
    -180,  -180,    15,  -180,  -180,   107,  -180,    44,  -180,    20,
      71,  -180,    18,    48,    38,    57,   -23,    85,    10,  -180,
     459,  -180,    55,    29,  -180,  -180,  -180,  -180,  -180,    13,
    -180,    88,    86,  -180,  -180,    48,   119,    97,  -180,  -180,
    -180,   112,    48,  -180,   134,    29,   443,  -180,   118,  -180,
      66,  -180,  -180,   235,   377,   377,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,   443,   448,
     443,   443,   443,   133,  -180,   137,  -180,  -180,  -180,  -180,
    -180,  -180,  -180,   459,   459,   459,   459,  -180,  -180,   459,
    -180,  -180,   459,  -180,  -180,  -180,  -180,   459,  -180,   459,
     316,    84,    29,  -180,  -180,  -180,    45,    -4,   305,   443,
     463,  -180,  -180,   319,    96,    29,  -180,   443,   443,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,    68,    71,  -180,
    -180,  -180,    48,    38,    57,   -23,    85,    10,  -180,  -180,
    -180,   443,  -180,   136,   151,   150,  -180,  -180,  -180,  -180,
     113,   113,   162,   166,  -180,   163,  -180,   154,   305,   443,
     172,  -180,  -180,   167,  -180,    48,   175,   174,  -180,  -180,
    -180,   443,  -180,   443,  -180,   388,   168,  -180,  -180,   443,
    -180,    -8,   443,  -180,   173,   214,   111,   305,  -180,   179,
    -180,  -180,  -180,   -35,   176,  -180,  -180,  -180,  -180,   305,
    -180,   110,   178,   443,   191,  -180,   113,  -180,   -26,  -180,
    -180,  -180,   305,   180,   181,  -180,   113,  -180,   305,   305,
    -180,  -180,  -180
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    32,     0,     0,     0,
       0,     3,     4,     0,   109,   110,     0,   111,     0,     0,
      40,    21,    22,    25,    23,   133,   134,   135,     7,     5,
       8,    29,    15,    16,    17,    18,    19,    20,     0,    13,
      14,    12,    34,    28,    47,    35,    48,    44,    46,    66,
      68,    70,    73,    74,    87,    89,    91,    93,    97,   101,
       0,   107,   112,   114,     9,   140,   139,   137,   180,     0,
     138,     0,     0,    72,   156,   155,     0,   151,    31,   131,
     136,     0,    43,   183,     0,   116,     0,    41,    62,    64,
      26,    24,    10,     0,     0,     0,    50,    51,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,     0,    45,
       0,     0,     0,     0,    85,    86,    78,    79,    80,    84,
      82,    81,    83,     0,     0,     0,     0,    95,    96,     0,
      99,   100,     0,   103,   104,   105,   106,     0,   108,     0,
       0,     0,   115,   118,   182,   181,     0,     0,     0,     0,
     152,   132,   177,     0,     0,   117,    42,    63,     0,    11,
      30,    38,    39,    36,    37,    33,    49,     0,    69,    71,
      76,    77,    75,    88,    90,    92,    94,    98,   102,   113,
     121,     0,   128,   127,     0,   123,   125,   120,   119,   159,
     169,     0,   175,     0,   163,   161,   171,   173,     0,     0,
       0,   147,   143,     0,   154,   153,     0,     0,   184,    65,
      27,     0,   130,     0,   122,   124,   167,   169,   166,     0,
     160,     0,     0,   157,     0,     0,   141,     0,   178,     0,
      67,   129,   126,     0,   164,   176,   162,   172,   174,     0,
     145,     0,     0,     0,   149,   179,     0,   170,     0,   158,
     148,   146,     0,     0,     0,   168,     0,   142,     0,     0,
     165,   144,   150
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -180,  -180,  -180,  -180,  -180,  -172,    -3,   105,  -180,  -180,
    -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,  -180,    31,
      -5,   -10,    90,  -180,  -180,   -22,  -180,    -6,    92,    95,
      -2,  -180,  -180,    -1,    87,    83,    89,  -180,    91,  -180,
      80,  -180,   -50,  -180,  -180,  -180,   129,  -121,    72,  -180,
       6,   205,  -180,  -180,  -180,  -180,  -180,  -119,  -180,   216,
    -180,   160,  -180,  -180,     9,    14,  -180,  -139,  -179,   165,
    -180,  -180,  -180
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    28,     3,    29,   201,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    45,    46,    47,   108,    87,    88,    48,    49,    50,
      51,    52,   123,    53,    54,    55,    56,   129,    57,   132,
      58,   137,    59,    60,    61,    62,   142,   143,   184,   185,
     186,    63,    81,    64,    65,   226,   241,   202,    66,    76,
      77,    67,   147,   193,   194,   216,   195,   247,   197,    68,
      69,    70,    84
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      30,    72,    91,    80,    74,    74,    73,   196,    75,    75,
     138,   217,   218,   246,    89,    82,     5,    90,    89,   198,
     190,   188,   256,   127,   128,   110,     4,   113,   111,   114,
     115,     5,     6,     7,   188,    71,   192,     8,   133,   134,
     191,     9,    10,    11,    12,   192,   135,    13,   140,    94,
     116,   117,    13,   240,    14,    15,    16,    92,   118,   119,
     120,   121,    83,   192,   141,   189,    93,   255,   109,   251,
     136,   199,    17,   190,   211,    18,   111,   260,   124,   223,
     156,   112,   237,   125,   162,   164,   165,   178,   126,   179,
      18,    19,   122,   191,    20,    21,    22,    23,    24,    25,
      26,    27,    89,   139,    25,    26,    27,   146,   244,   148,
     169,   130,   131,     5,     6,     7,   192,   242,   243,     8,
     249,   150,   172,     9,    10,   161,   163,   203,   250,    13,
     149,   158,   151,   257,   183,   182,    14,    15,    16,   261,
     262,    95,   157,    89,   170,   204,   171,   183,   182,   205,
     152,   209,   210,   153,    17,   187,    96,    97,    98,    99,
     100,   101,   102,   103,   104,   105,   106,   208,   107,   154,
     213,   214,    18,    19,   215,   212,    20,    21,    22,    23,
      24,    25,    26,    27,   192,   219,   220,   221,   222,   225,
     227,   228,   233,   224,   229,   245,   239,   254,   160,   166,
     248,   252,   167,   258,   259,   230,   168,   231,   174,   183,
     182,   173,   177,   235,   155,   175,   238,     5,     6,     7,
     176,   232,    30,     8,    85,   207,    78,     9,    10,   144,
     236,   234,     0,    13,   145,     0,     0,   253,    30,     6,
      14,    15,    16,     0,     8,     0,     0,     0,     0,    10,
       0,   159,     0,     0,    13,     0,     0,     0,    17,     0,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    18,    19,     0,    17,
      20,    21,    22,    23,    24,    25,    26,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    26,    27,     6,
       0,     0,     0,     0,     8,     0,     0,     0,     0,    10,
       0,   200,     0,     0,    13,     8,     0,     0,     8,     0,
       0,    14,    15,    16,     0,    13,   180,     0,    13,   206,
       0,     0,    14,    15,    16,    14,    15,    16,     0,    17,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      17,     0,     0,    17,   181,     0,     0,   181,    19,     0,
       0,    20,    21,    22,    23,    24,    25,    26,    27,    19,
       0,     0,    19,     8,     0,     0,     8,    25,    26,    27,
      25,    26,    27,    13,    79,     0,    13,     8,     0,     0,
      14,    15,    16,    14,    15,    16,     0,    13,     0,     8,
       0,     0,     0,     0,    14,    15,    16,     0,    17,    13,
       0,    17,     0,     0,     0,     0,    14,    15,     0,     0,
       0,     0,    17,     0,     0,     0,   181,    19,     0,     0,
      19,     0,     0,    20,    17,    25,    26,    27,    25,    26,
      27,    19,     8,     0,     0,     0,     0,     8,     0,    25,
      26,    27,    13,    19,     0,    86,     0,    13,     0,    14,
      15,    25,    26,    27,    14,    15,    16,     0,    13,     0,
       0,     0,    13,     0,     0,    14,    15,    17,     0,    14,
      15,    16,    17,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,     0,     0,    19,    17,     0,     0,
       0,    19,     0,     0,    25,    26,    27,     0,     0,    25,
      26,    27,    19,     0,     0,     0,    19,     0,     0,     0,
      25,    26,    27,     0,    25,    26,    27
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,    24,    13,     9,    10,     8,   146,     9,    10,
      60,   190,   191,    48,    20,    16,     3,    23,    24,    23,
      28,   142,    48,    46,    47,     5,     0,     9,     8,    11,
      12,     3,     4,     5,   155,    71,    71,     9,    28,    29,
      48,    13,    14,    15,    16,    71,    36,    19,    19,    34,
      32,    33,    19,   225,    26,    27,    28,    16,    40,    41,
      42,    43,    71,    71,    35,    20,    25,   246,    24,   241,
      60,    75,    44,    28,     6,    62,     8,   256,    30,   198,
      86,    10,   221,    45,    94,    95,   108,   137,    31,   139,
      62,    63,    74,    48,    66,    67,    68,    69,    70,    71,
      72,    73,   108,    48,    71,    72,    73,    19,   227,    23,
     112,    26,    27,     3,     4,     5,    71,     6,     7,     9,
     239,    24,   123,    13,    14,    94,    95,   149,    18,    19,
      11,    65,    20,   252,   140,   140,    26,    27,    28,   258,
     259,    34,    24,   149,    11,   150,     9,   153,   153,   150,
      16,   157,   158,    19,    44,    71,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    71,    61,    35,
      34,    20,    62,    63,    24,   181,    66,    67,    68,    69,
      70,    71,    72,    73,    71,    23,    20,    24,    34,    17,
      23,    16,    24,   199,    20,    16,    23,     6,    93,   109,
      24,    23,   110,    23,    23,   211,   111,   213,   125,   215,
     215,   124,   132,   219,    85,   126,   222,     3,     4,     5,
     129,   215,   225,     9,    19,   153,    10,    13,    14,    69,
     221,   217,    -1,    19,    69,    -1,    -1,   243,   241,     4,
      26,    27,    28,    -1,     9,    -1,    -1,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    44,    -1,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    63,    -1,    44,
      66,    67,    68,    69,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,     4,
      -1,    -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,     9,    -1,    -1,     9,    -1,
      -1,    26,    27,    28,    -1,    19,    20,    -1,    19,    20,
      -1,    -1,    26,    27,    28,    26,    27,    28,    -1,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    44,    48,    -1,    -1,    48,    63,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    63,
      -1,    -1,    63,     9,    -1,    -1,     9,    71,    72,    73,
      71,    72,    73,    19,    20,    -1,    19,     9,    -1,    -1,
      26,    27,    28,    26,    27,    28,    -1,    19,    -1,     9,
      -1,    -1,    -1,    -1,    26,    27,    28,    -1,    44,    19,
      -1,    44,    -1,    -1,    -1,    -1,    26,    27,    -1,    -1,
      -1,    -1,    44,    -1,    -1,    -1,    48,    63,    -1,    -1,
      63,    -1,    -1,    66,    44,    71,    72,    73,    71,    72,
      73,    63,     9,    -1,    -1,    -1,    -1,     9,    -1,    71,
      72,    73,    19,    63,    -1,    65,    -1,    19,    -1,    26,
      27,    71,    72,    73,    26,    27,    28,    -1,    19,    -1,
      -1,    -1,    19,    -1,    -1,    26,    27,    44,    -1,    26,
      27,    28,    44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    44,    -1,    -1,    63,    44,    -1,    -1,
      -1,    63,    -1,    -1,    71,    72,    73,    -1,    -1,    71,
      72,    73,    63,    -1,    -1,    -1,    63,    -1,    -1,    -1,
      71,    72,    73,    -1,    71,    72,    73
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    77,    78,    80,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    26,    27,    28,    44,    62,    63,
      66,    67,    68,    69,    70,    71,    72,    73,    79,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,    91,
      92,    93,    94,    95,    96,    97,    98,    99,   103,   104,
     105,   106,   107,   109,   110,   111,   112,   114,   116,   118,
     119,   120,   121,   127,   129,   130,   134,   137,   145,   146,
     147,    71,   103,   106,    96,   109,   135,   136,   135,    20,
      97,   128,   109,    71,   148,   127,    65,   101,   102,   103,
     103,   101,    16,    25,    34,    34,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,   100,    24,
       5,     8,    10,     9,    11,    12,    32,    33,    40,    41,
      42,    43,    74,   108,    30,    45,    31,    46,    47,   113,
      26,    27,   115,    28,    29,    36,    60,   117,   118,    48,
      19,    35,   122,   123,   137,   145,    19,   138,    23,    11,
      24,    20,    16,    19,    35,   122,   103,    24,    65,    16,
      83,    95,    97,    95,    97,   101,    98,   104,   105,   106,
      11,     9,   109,   110,   111,   112,   114,   116,   118,   118,
      20,    48,    96,   103,   124,   125,   126,    71,   123,    20,
      28,    48,    71,   139,   140,   142,   143,   144,    23,    75,
      16,    82,   133,   101,    96,   109,    20,   124,    71,   103,
     103,     6,   103,    34,    20,    24,   141,   144,   144,    23,
      20,    24,    34,   133,   103,    17,   131,    23,    16,    20,
     103,   103,   126,    24,   141,   103,   140,   143,   103,    23,
      81,   132,     6,     7,   133,    16,    48,   143,    24,   133,
      18,    81,    23,   103,     6,   144,    48,   133,    23,    23,
     144,   133,   133
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    76,    77,    78,    79,    79,    80,    80,    81,    81,
      82,    82,    83,    83,    83,    83,    84,    84,    84,    84,
      84,    85,    86,    87,    87,    88,    88,    88,    89,    90,
      90,    91,    92,    93,    93,    93,    94,    94,    94,    94,
      95,    95,    95,    96,    97,    97,    98,    98,    99,    99,
     100,   100,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   101,   101,   102,   102,   103,   103,   104,   104,
     105,   105,   106,   106,   107,   107,   108,   108,   108,   108,
     108,   108,   108,   108,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   113,   113,   114,   114,   115,
     115,   116,   116,   117,   117,   117,   117,   118,   118,   119,
     119,   119,   120,   120,   121,   121,   121,   121,   122,   122,
     123,   123,   123,   124,   124,   125,   125,   126,   126,   126,
     126,   127,   127,   127,   127,   127,   128,   129,   129,   129,
     129,   130,   130,   131,   131,   132,   132,   133,   133,   134,
     134,   135,   135,   136,   136,   136,   136,   137,   137,   138,
     138,   139,   139,   139,   140,   140,   140,   140,   140,   141,
     141,   142,   142,   143,   143,   144,   144,   145,   145,   145,
     146,   146,   147,   148,   148
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     2,     4,     1,     1,
       3,     2,     1,     3,     1,     1,     3,     3,     3,     3,
       1,     2,     3,     2,     1,     2,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     3,     1,     5,     1,     3,
       1,     3,     2,     1,     1,     3,     2,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     3,     1,     1,     1,     1,     1,     2,     1,
       1,     1,     1,     3,     1,     2,     2,     3,     1,     2,
       2,     2,     3,     1,     2,     1,     3,     1,     1,     3,
       2,     2,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     5,     8,     0,     5,     1,     2,     1,     4,     6,
       9,     1,     2,     3,     3,     1,     1,     5,     7,     2,
       3,     1,     3,     1,     3,     6,     2,     2,     5,     0,
       3,     1,     3,     1,     3,     1,     3,     3,     5,     6,
       1,     2,     2,     1,     3
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
  "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"", "\"//\"", "\"//=\"", "\"@\"",
  "\"await\"", "\"async\"", "\"from\"", "\"yield\"", "\"break\"",
  "\"continue\"", "\"raise\"", "\"return\"", "NAME", "NUMBER", "STRING",
  "\"<>\"", "\"->\"", "$accept", "module", "file_input", "newline_or_stmt",
  "newline_stmt_seq", "stmt", "simple_stmt", "small_stmt", "flow_stmt",
  "break_stmt", "continue_stmt", "return_stmt", "raise_stmt", "yield_stmt",
  "small_stmt_seq", "del_stmt", "pass_stmt", "expr_stmt",
  "assign_expr_seq", "yield_expr", "star_expr", "testlist_star_expr",
  "test_star_expr", "test_star_expr_seq", "augassign", "testlist",
  "test_seq", "test", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr", "shift_op",
  "arith_expr", "arith_op", "term", "term_op", "factor", "factor_op",
  "power", "atom_expr", "trailer_seq", "trailer", "arglist", "arglist_seq",
  "argument", "atom", "testlist_comp", "compound_stmt", "if_stmt",
  "elif_seq", "stmt_seq", "suite", "for_stmt", "exprlist", "exprlist_seq",
  "funcdef", "parameters", "typedargslist", "var_args",
  "var_arglist_trailer", "named_args", "tfpdef_test", "tfpdef",
  "decorator", "decorators", "decorated", "dotted_name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   176,   176,   200,   208,   212,   221,   225,   246,   250,
     260,   264,   275,   276,   277,   278,   283,   283,   283,   283,
     283,   288,   296,   305,   309,   318,   322,   326,   333,   343,
     347,   358,   367,   384,   388,   392,   410,   414,   419,   423,
     450,   454,   458,   479,   501,   506,   517,   517,   522,   527,
     539,   539,   539,   539,   539,   539,   539,   539,   540,   540,
     540,   540,   547,   548,   555,   556,   571,   572,   578,   579,
     589,   590,   600,   604,   611,   612,   625,   629,   633,   634,
     635,   636,   637,   638,   639,   640,   641,   648,   649,   658,
     659,   668,   669,   678,   679,   686,   686,   692,   693,   700,
     700,   706,   707,   714,   714,   714,   714,   720,   721,   728,
     728,   728,   734,   735,   744,   745,   754,   758,   767,   768,
     782,   789,   795,   808,   809,   819,   823,   844,   845,   846,
     850,   884,   890,   897,   898,   899,   919,   931,   932,   933,
     934,   942,   947,   956,   961,   986,   990,   999,  1003,  1012,
    1016,  1025,  1026,  1036,  1042,  1047,  1048,  1054,  1058,  1067,
    1071,  1111,  1118,  1125,  1134,  1141,  1149,  1155,  1163,  1176,
    1180,  1191,  1195,  1203,  1207,  1220,  1227,  1241,  1242,  1243,
    1249,  1250,  1256,  1262,  1263
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
      75
    };
    const unsigned int user_token_number_max_ = 330;
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

