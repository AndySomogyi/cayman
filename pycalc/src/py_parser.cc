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

      case 64: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 65: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 66: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 67: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 68: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 69: // "break"


        { yyoutput << (yysym.value); }

        break;

      case 70: // "continue"


        { yyoutput << (yysym.value); }

        break;

      case 71: // "raise"


        { yyoutput << (yysym.value); }

        break;

      case 72: // "return"


        { yyoutput << (yysym.value); }

        break;

      case 73: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 74: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 75: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 76: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 78: // module


        { yyoutput << (yysym.value); }

        break;

      case 79: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 80: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 81: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 82: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 83: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 84: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 85: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 86: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 87: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 88: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 89: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 90: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 91: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 92: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 93: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 94: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 95: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 96: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 97: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 98: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 99: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 100: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 101: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 102: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 103: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 104: // test


        { yyoutput << (yysym.value); }

        break;

      case 105: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 106: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 107: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 108: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 109: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 110: // expr


        { yyoutput << (yysym.value); }

        break;

      case 111: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 112: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 113: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 114: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 115: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 116: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 117: // term


        { yyoutput << (yysym.value); }

        break;

      case 118: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 119: // factor


        { yyoutput << (yysym.value); }

        break;

      case 120: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 121: // power


        { yyoutput << (yysym.value); }

        break;

      case 122: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 123: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 124: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 125: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 126: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 127: // argument


        { yyoutput << (yysym.value); }

        break;

      case 128: // atom


        { yyoutput << (yysym.value); }

        break;

      case 129: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 130: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 131: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 132: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 133: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 134: // suite


        { yyoutput << (yysym.value); }

        break;

      case 135: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 136: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 137: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 138: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 139: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 140: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 141: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 142: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 143: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 144: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 145: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 146: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 147: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 148: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 149: // dotted_name


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
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 158:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
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


  const short int py_parser::yypact_ninf_ = -192;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -192,    23,  -192,    26,  -192,   -40,  -192,   412,   412,    85,
      85,  -192,  -192,   170,  -192,  -192,   408,  -192,    20,    32,
     355,  -192,  -192,   412,   412,  -192,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,    39,  -192,
    -192,  -192,    38,  -192,  -192,   440,  -192,    52,  -192,    63,
      73,  -192,    16,    84,    74,    87,    -9,    34,   196,  -192,
     408,  -192,    75,     1,  -192,  -192,  -192,  -192,  -192,    10,
    -192,   101,   105,  -192,  -192,    84,   113,   109,  -192,  -192,
    -192,   117,    84,  -192,    46,     1,   412,  -192,   118,  -192,
      94,  -192,  -192,   246,   127,   127,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,   412,   389,
     412,   412,   412,   130,  -192,   153,  -192,  -192,  -192,  -192,
    -192,  -192,  -192,   408,   408,   408,   408,  -192,  -192,   408,
    -192,  -192,   408,  -192,  -192,  -192,  -192,   408,  -192,   408,
     282,    92,     1,  -192,  -192,  -192,    -4,     3,   318,   412,
      85,  -192,  -192,   332,    93,     1,  -192,   412,   412,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,    67,    73,  -192,
    -192,  -192,    84,    74,    87,    -9,    34,   196,  -192,  -192,
    -192,   412,  -192,   133,   148,   145,  -192,  -192,  -192,  -192,
      97,    97,   149,   154,  -192,   164,  -192,   139,   318,   412,
     161,  -192,  -192,   168,  -192,    84,   178,   179,  -192,  -192,
    -192,   412,  -192,   412,  -192,   375,   180,  -192,  -192,   412,
    -192,    15,   412,  -192,   183,   214,    72,   318,  -192,   187,
    -192,  -192,  -192,   -27,   184,  -192,  -192,  -192,  -192,   318,
    -192,   112,   188,   412,   206,  -192,    97,  -192,   -26,  -192,
    -192,  -192,   318,   192,   197,  -192,    97,  -192,   318,   318,
    -192,  -192,  -192
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
    -192,  -192,  -192,  -192,  -192,  -191,    -3,   128,  -192,  -192,
    -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,  -192,    14,
      -5,   -10,   120,  -192,  -192,   -22,  -192,    -6,   116,   119,
      -2,  -192,  -192,    -1,   107,   111,   108,  -192,   110,  -192,
     114,  -192,   -50,  -192,  -192,  -192,   162,  -123,    95,  -192,
      36,   230,  -192,  -192,  -192,  -192,  -192,   -95,  -192,   242,
    -192,   185,  -192,  -192,    40,    42,  -192,  -139,  -179,   194,
    -192,  -192,  -192
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
     138,   217,   218,     5,    89,    82,   189,    90,    89,   188,
     140,   246,   256,     4,   190,   113,   198,   114,   115,     5,
       6,     7,   188,    71,   240,     8,   141,   127,   128,     9,
      10,    11,    12,   190,   191,    13,   192,   192,   116,   117,
     251,    13,    14,    15,    16,    92,   118,   119,   120,   121,
     130,   131,   152,   191,    93,   153,   199,   255,   110,   192,
      17,   111,    94,   211,    18,   111,   109,   260,   242,   243,
     156,   154,   237,   112,   162,   164,   165,   178,   192,   179,
      18,    19,   122,    83,    20,    21,    22,    23,    24,    25,
      26,    27,    89,   223,    13,    25,    26,    27,   161,   163,
     169,    14,    15,    16,   124,     5,     6,     7,   126,   125,
     146,     8,   172,   139,   149,     9,    10,   203,   148,    17,
     250,    13,   244,   150,   183,   182,     8,   151,    14,    15,
      16,   170,   157,    89,   249,   204,    13,   183,   182,   205,
      19,   209,   210,    14,    15,    16,    17,   257,    25,    26,
      27,   158,   171,   261,   262,   187,   208,   213,   214,   215,
     192,    17,   219,   222,   220,   212,    18,    19,   225,     8,
      20,    21,    22,    23,    24,    25,    26,    27,   221,    13,
      79,   227,    19,   224,   228,    20,    14,    15,    16,   229,
      25,    26,    27,   245,   233,   230,   239,   231,   248,   183,
     182,   252,   254,   235,    17,   258,   238,     5,     6,     7,
     259,   160,    30,     8,   133,   134,   167,     9,    10,   166,
     168,   173,   135,    13,   175,    19,   174,   253,    30,   176,
      14,    15,    16,    25,    26,    27,   177,   155,   207,    85,
       6,   232,    78,     0,   144,     8,   136,     0,    17,   234,
      10,   236,   159,   145,     0,    13,     0,     0,     0,     0,
       0,     0,    14,    15,    16,     0,     0,     0,    18,    19,
       0,     0,    20,    21,    22,    23,    24,    25,    26,    27,
      17,     8,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    13,   180,     0,     0,     0,     0,     0,    14,    15,
      16,    19,     0,     0,    20,    21,    22,    23,    24,    25,
      26,    27,     6,     0,     0,     0,    17,     8,     0,     0,
     181,     0,    10,     0,   200,     0,     0,    13,     0,     0,
       0,     8,     0,     0,    14,    15,    16,    19,     0,     0,
       0,    13,   206,     0,     0,    25,    26,    27,    14,    15,
      16,     0,    17,     0,     8,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    13,     0,    17,     0,     0,     0,
     181,    14,    15,    19,     8,     0,    20,    21,    22,    23,
      24,    25,    26,    27,    13,     0,     0,    19,     8,    17,
       0,    14,    15,    16,     0,    25,    26,    27,    13,     0,
       0,     0,     0,     0,     0,    14,    15,    16,     0,    17,
      19,     8,    86,   181,     0,     0,     0,    13,    25,    26,
      27,    13,     0,    17,    14,    15,     0,     0,    14,    15,
      19,     0,     0,     0,     0,     0,     0,     0,    25,    26,
      27,     0,    17,     0,    19,     0,    17,     0,     0,     0,
       0,     0,    25,    26,    27,     0,     0,     0,     0,     0,
       0,     0,     0,    19,    95,     0,     0,    19,     0,     0,
       0,    25,    26,    27,     0,    25,    26,    27,     0,    96,
      97,    98,    99,   100,   101,   102,   103,   104,   105,   106,
       0,   107
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,    24,    13,     9,    10,     8,   146,     9,    10,
      60,   190,   191,     3,    20,    16,    20,    23,    24,   142,
      19,    48,    48,     0,    28,     9,    23,    11,    12,     3,
       4,     5,   155,    73,   225,     9,    35,    46,    47,    13,
      14,    15,    16,    28,    48,    19,    73,    73,    32,    33,
     241,    19,    26,    27,    28,    16,    40,    41,    42,    43,
      26,    27,    16,    48,    25,    19,    63,   246,     5,    73,
      44,     8,    34,     6,    64,     8,    24,   256,     6,     7,
      86,    35,   221,    10,    94,    95,   108,   137,    73,   139,
      64,    65,    76,    73,    68,    69,    70,    71,    72,    73,
      74,    75,   108,   198,    19,    73,    74,    75,    94,    95,
     112,    26,    27,    28,    30,     3,     4,     5,    31,    45,
      19,     9,   123,    48,    11,    13,    14,   149,    23,    44,
      18,    19,   227,    24,   140,   140,     9,    20,    26,    27,
      28,    11,    24,   149,   239,   150,    19,   153,   153,   150,
      65,   157,   158,    26,    27,    28,    44,   252,    73,    74,
      75,    67,     9,   258,   259,    73,    73,    34,    20,    24,
      73,    44,    23,    34,    20,   181,    64,    65,    17,     9,
      68,    69,    70,    71,    72,    73,    74,    75,    24,    19,
      20,    23,    65,   199,    16,    68,    26,    27,    28,    20,
      73,    74,    75,    16,    24,   211,    23,   213,    24,   215,
     215,    23,     6,   219,    44,    23,   222,     3,     4,     5,
      23,    93,   225,     9,    28,    29,   110,    13,    14,   109,
     111,   124,    36,    19,   126,    65,   125,   243,   241,   129,
      26,    27,    28,    73,    74,    75,   132,    85,   153,    19,
       4,   215,    10,    -1,    69,     9,    60,    -1,    44,   217,
      14,   221,    16,    69,    -1,    19,    -1,    -1,    -1,    -1,
      -1,    -1,    26,    27,    28,    -1,    -1,    -1,    64,    65,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      44,     9,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    19,    20,    -1,    -1,    -1,    -1,    -1,    26,    27,
      28,    65,    -1,    -1,    68,    69,    70,    71,    72,    73,
      74,    75,     4,    -1,    -1,    -1,    44,     9,    -1,    -1,
      48,    -1,    14,    -1,    16,    -1,    -1,    19,    -1,    -1,
      -1,     9,    -1,    -1,    26,    27,    28,    65,    -1,    -1,
      -1,    19,    20,    -1,    -1,    73,    74,    75,    26,    27,
      28,    -1,    44,    -1,     9,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    19,    -1,    44,    -1,    -1,    -1,
      48,    26,    27,    65,     9,    -1,    68,    69,    70,    71,
      72,    73,    74,    75,    19,    -1,    -1,    65,     9,    44,
      -1,    26,    27,    28,    -1,    73,    74,    75,    19,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    44,
      65,     9,    67,    48,    -1,    -1,    -1,    19,    73,    74,
      75,    19,    -1,    44,    26,    27,    -1,    -1,    26,    27,
      65,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    73,    74,
      75,    -1,    44,    -1,    65,    -1,    44,    -1,    -1,    -1,
      -1,    -1,    73,    74,    75,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    65,    34,    -1,    -1,    65,    -1,    -1,
      -1,    73,    74,    75,    -1,    73,    74,    75,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    58,    59,
      -1,    61
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    78,    79,    81,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    26,    27,    28,    44,    64,    65,
      68,    69,    70,    71,    72,    73,    74,    75,    80,    82,
      83,    84,    85,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    96,    97,    98,    99,   100,   104,   105,
     106,   107,   108,   110,   111,   112,   113,   115,   117,   119,
     120,   121,   122,   128,   130,   131,   135,   138,   146,   147,
     148,    73,   104,   107,    97,   110,   136,   137,   136,    20,
      98,   129,   110,    73,   149,   128,    67,   102,   103,   104,
     104,   102,    16,    25,    34,    34,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    61,   101,    24,
       5,     8,    10,     9,    11,    12,    32,    33,    40,    41,
      42,    43,    76,   109,    30,    45,    31,    46,    47,   114,
      26,    27,   116,    28,    29,    36,    60,   118,   119,    48,
      19,    35,   123,   124,   138,   146,    19,   139,    23,    11,
      24,    20,    16,    19,    35,   123,   104,    24,    67,    16,
      84,    96,    98,    96,    98,   102,    99,   105,   106,   107,
      11,     9,   110,   111,   112,   113,   115,   117,   119,   119,
      20,    48,    97,   104,   125,   126,   127,    73,   124,    20,
      28,    48,    73,   140,   141,   143,   144,   145,    23,    63,
      16,    83,   134,   102,    97,   110,    20,   125,    73,   104,
     104,     6,   104,    34,    20,    24,   142,   145,   145,    23,
      20,    24,    34,   134,   104,    17,   132,    23,    16,    20,
     104,   104,   127,    24,   142,   104,   141,   144,   104,    23,
      82,   133,     6,     7,   134,    16,    48,   144,    24,   134,
      18,    82,    23,   104,     6,   145,    48,   134,    23,    23,
     145,   134,   134
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    77,    78,    79,    80,    80,    81,    81,    82,    82,
      83,    83,    84,    84,    84,    84,    85,    85,    85,    85,
      85,    86,    87,    88,    88,    89,    89,    89,    90,    91,
      91,    92,    93,    94,    94,    94,    95,    95,    95,    95,
      96,    96,    96,    97,    98,    98,    99,    99,   100,   100,
     101,   101,   101,   101,   101,   101,   101,   101,   101,   101,
     101,   101,   102,   102,   103,   103,   104,   104,   105,   105,
     106,   106,   107,   107,   108,   108,   109,   109,   109,   109,
     109,   109,   109,   109,   109,   109,   109,   110,   110,   111,
     111,   112,   112,   113,   113,   114,   114,   115,   115,   116,
     116,   117,   117,   118,   118,   118,   118,   119,   119,   120,
     120,   120,   121,   121,   122,   122,   122,   122,   123,   123,
     124,   124,   124,   125,   125,   126,   126,   127,   127,   127,
     127,   128,   128,   128,   128,   128,   129,   130,   130,   130,
     130,   131,   131,   132,   132,   133,   133,   134,   134,   135,
     135,   136,   136,   137,   137,   137,   137,   138,   138,   139,
     139,   140,   140,   140,   141,   141,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   145,   145,   146,   146,   146,
     147,   147,   148,   149,   149
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
  "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"", "\"//\"", "\"//=\"", "\"<-\"",
  "\"->\"", "\"@\"", "\"await\"", "\"async\"", "\"from\"", "\"yield\"",
  "\"break\"", "\"continue\"", "\"raise\"", "\"return\"", "NAME", "NUMBER",
  "STRING", "\"<>\"", "$accept", "module", "file_input", "newline_or_stmt",
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
       0,   180,   180,   204,   212,   216,   225,   229,   250,   254,
     264,   268,   279,   280,   281,   282,   287,   287,   287,   287,
     287,   292,   300,   309,   313,   322,   326,   330,   337,   347,
     351,   362,   371,   388,   392,   396,   414,   418,   423,   427,
     454,   458,   462,   483,   505,   510,   521,   521,   526,   531,
     543,   543,   543,   543,   543,   543,   543,   543,   544,   544,
     544,   544,   551,   552,   559,   560,   575,   576,   582,   583,
     593,   594,   604,   608,   615,   616,   629,   633,   637,   638,
     639,   640,   641,   642,   643,   644,   645,   652,   653,   662,
     663,   672,   673,   682,   683,   690,   690,   696,   697,   704,
     704,   710,   711,   718,   718,   718,   718,   724,   725,   732,
     732,   732,   738,   739,   748,   749,   758,   762,   771,   772,
     786,   793,   799,   812,   813,   823,   827,   848,   849,   850,
     854,   888,   894,   901,   902,   903,   923,   935,   936,   937,
     938,   946,   951,   960,   965,   990,   994,  1003,  1007,  1016,
    1020,  1029,  1030,  1040,  1046,  1051,  1052,  1058,  1063,  1073,
    1077,  1117,  1124,  1131,  1140,  1147,  1155,  1161,  1169,  1182,
    1186,  1197,  1201,  1209,  1213,  1226,  1233,  1247,  1248,  1249,
    1255,  1256,  1262,  1268,  1269
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
      75,    76
    };
    const unsigned int user_token_number_max_ = 331;
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

