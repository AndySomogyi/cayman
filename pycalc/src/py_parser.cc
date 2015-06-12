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
            case 3: // DEF


        { yyoutput << (yysym.value); }

        break;

      case 4: // PASS


        { yyoutput << (yysym.value); }

        break;

      case 5: // "if"


        { yyoutput << (yysym.value); }

        break;

      case 6: // "else"


        { yyoutput << (yysym.value); }

        break;

      case 7: // "or"


        { yyoutput << (yysym.value); }

        break;

      case 8: // "not"


        { yyoutput << (yysym.value); }

        break;

      case 9: // "and"


        { yyoutput << (yysym.value); }

        break;

      case 10: // "in"


        { yyoutput << (yysym.value); }

        break;

      case 11: // "is"


        { yyoutput << (yysym.value); }

        break;

      case 12: // "for"


        { yyoutput << (yysym.value); }

        break;

      case 13: // ENDMARKER


        { yyoutput << (yysym.value); }

        break;

      case 14: // NEWLINE


        { yyoutput << (yysym.value); }

        break;

      case 15: // INDENT


        { yyoutput << (yysym.value); }

        break;

      case 16: // DEDENT


        { yyoutput << (yysym.value); }

        break;

      case 17: // "("


        { yyoutput << (yysym.value); }

        break;

      case 18: // ")"


        { yyoutput << (yysym.value); }

        break;

      case 19: // LSQB


        { yyoutput << (yysym.value); }

        break;

      case 20: // RSQB


        { yyoutput << (yysym.value); }

        break;

      case 21: // ":"


        { yyoutput << (yysym.value); }

        break;

      case 22: // ","


        { yyoutput << (yysym.value); }

        break;

      case 23: // ";"


        { yyoutput << (yysym.value); }

        break;

      case 24: // "+"


        { yyoutput << (yysym.value); }

        break;

      case 25: // "-"


        { yyoutput << (yysym.value); }

        break;

      case 26: // "*"


        { yyoutput << (yysym.value); }

        break;

      case 27: // "/"


        { yyoutput << (yysym.value); }

        break;

      case 28: // VBAR


        { yyoutput << (yysym.value); }

        break;

      case 29: // "&"


        { yyoutput << (yysym.value); }

        break;

      case 30: // "<"


        { yyoutput << (yysym.value); }

        break;

      case 31: // ">"


        { yyoutput << (yysym.value); }

        break;

      case 32: // "="


        { yyoutput << (yysym.value); }

        break;

      case 33: // "."


        { yyoutput << (yysym.value); }

        break;

      case 34: // "%"


        { yyoutput << (yysym.value); }

        break;

      case 35: // "`"


        { yyoutput << (yysym.value); }

        break;

      case 36: // LBRACE


        { yyoutput << (yysym.value); }

        break;

      case 37: // RBRACE


        { yyoutput << (yysym.value); }

        break;

      case 38: // "=="


        { yyoutput << (yysym.value); }

        break;

      case 39: // "!="


        { yyoutput << (yysym.value); }

        break;

      case 40: // "<="


        { yyoutput << (yysym.value); }

        break;

      case 41: // ">="


        { yyoutput << (yysym.value); }

        break;

      case 42: // "~"


        { yyoutput << (yysym.value); }

        break;

      case 43: // "^"


        { yyoutput << (yysym.value); }

        break;

      case 44: // "<<"


        { yyoutput << (yysym.value); }

        break;

      case 45: // ">>"


        { yyoutput << (yysym.value); }

        break;

      case 46: // "**"


        { yyoutput << (yysym.value); }

        break;

      case 47: // "+="


        { yyoutput << (yysym.value); }

        break;

      case 48: // "-="


        { yyoutput << (yysym.value); }

        break;

      case 49: // "*="


        { yyoutput << (yysym.value); }

        break;

      case 50: // "/="


        { yyoutput << (yysym.value); }

        break;

      case 51: // "%="


        { yyoutput << (yysym.value); }

        break;

      case 52: // "&="


        { yyoutput << (yysym.value); }

        break;

      case 53: // "|="


        { yyoutput << (yysym.value); }

        break;

      case 54: // "^="


        { yyoutput << (yysym.value); }

        break;

      case 55: // "<<="


        { yyoutput << (yysym.value); }

        break;

      case 56: // ">>="


        { yyoutput << (yysym.value); }

        break;

      case 57: // "**+"


        { yyoutput << (yysym.value); }

        break;

      case 58: // "//"


        { yyoutput << (yysym.value); }

        break;

      case 59: // "//="


        { yyoutput << (yysym.value); }

        break;

      case 60: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 61: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 62: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 63: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 64: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 65: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 66: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 67: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 68: // "|"


        { yyoutput << (yysym.value); }

        break;

      case 69: // "@="


        { yyoutput << (yysym.value); }

        break;

      case 70: // "**="


        { yyoutput << (yysym.value); }

        break;

      case 71: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 72: // "def"


        { yyoutput << (yysym.value); }

        break;

      case 73: // "->"


        { yyoutput << (yysym.value); }

        break;

      case 75: // module


        { yyoutput << (yysym.value); }

        break;

      case 76: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 77: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 78: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 79: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 80: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 81: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 82: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 83: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 84: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 85: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 86: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 87: // yield_arg


        { yyoutput << (yysym.value); }

        break;

      case 88: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 89: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 90: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 91: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 92: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 93: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 94: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 95: // test


        { yyoutput << (yysym.value); }

        break;

      case 96: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 97: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 98: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 99: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 100: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 101: // expr


        { yyoutput << (yysym.value); }

        break;

      case 102: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 103: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 104: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 105: // shift_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 106: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 107: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 108: // term


        { yyoutput << (yysym.value); }

        break;

      case 109: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 110: // factor


        { yyoutput << (yysym.value); }

        break;

      case 111: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 112: // power


        { yyoutput << (yysym.value); }

        break;

      case 113: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 114: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 115: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 116: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 117: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 118: // argument


        { yyoutput << (yysym.value); }

        break;

      case 119: // atom


        { yyoutput << (yysym.value); }

        break;

      case 120: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 121: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 122: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 123: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 124: // suite


        { yyoutput << (yysym.value); }

        break;

      case 125: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 126: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 127: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 128: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 129: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 130: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 131: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 132: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 133: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 134: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 135: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 136: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 137: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 138: // dotted_name


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

  case 12:

    {
        (yylhs.value) = (yystack_[0].value); /* pass_stmt */
    }

    break;

  case 13:

    {
        (yylhs.value) = (yystack_[0].value); /* expr_stmt */
    }

    break;

  case 14:

    {
        (yylhs.value) = (yystack_[0].value); // small_stmt_seq: small_stmt
    }

    break;

  case 15:

    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value)); 
    }

    break;

  case 17:

    {
        throw syntax_error(yylhs.location, "not implemented");
    }

    break;

  case 18:

    {
        (yylhs.value) = (yystack_[0].value);  /*foo*/
    }

    break;

  case 19:

    {
        (yylhs.value) = (yystack_[0].value); // expr_stmt: testlist_star_expr
    }

    break;

  case 20:

    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 21:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 22:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 23:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 29:

    {
        AstNode *a1 = (yystack_[0].value);
        (yylhs.value) = (yystack_[0].value); // testlist_star_expr:  test_star_expr_seq
    }

    break;

  case 30:

    {
        AstNode *a1 = (yystack_[1].value);
        (yylhs.value) = (yystack_[1].value); // testlist_star_expr: test_star_expr_seq ","
    }

    break;

  case 33:

    {
        // test_star_expr_seq: test_star_expr
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 34:

    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 114:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 115:

    {
        // atom: |"(" testlist_comp ")"
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 116:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 117:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 118:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 140:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 141:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 142:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 143:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 144:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetVararg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 145:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 146:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 147:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 149:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 150:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[0].value));
    }

    break;

  case 151:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 152:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 153:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = dynamic_cast<Expr*>((yystack_[0].value));
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 154:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 155:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
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


  const short int py_parser::yypact_ninf_ = -198;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -198,    30,  -198,    57,  -198,   -23,  -198,   346,   358,  -198,
    -198,   135,  -198,  -198,   189,  -198,   -21,   102,  -198,  -198,
    -198,   -12,  -198,  -198,  -198,  -198,    27,  -198,  -198,    32,
    -198,   382,  -198,    37,  -198,     7,    64,  -198,    16,     9,
      23,    50,  -198,    38,    -9,  -198,   189,  -198,    40,  -198,
    -198,  -198,  -198,  -198,    12,  -198,  -198,  -198,  -198,     9,
      78,    68,  -198,  -198,    76,     9,  -198,    95,  -198,    81,
    -198,   201,   227,   227,  -198,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,  -198,  -198,  -198,  -198,  -198,   346,   307,   346,
     346,   346,    94,  -198,    98,  -198,  -198,  -198,  -198,  -198,
    -198,  -198,   189,   189,   189,   189,  -198,  -198,    -8,   189,
    -198,  -198,  -198,  -198,   189,  -198,   189,   -10,  -198,  -198,
     346,   358,  -198,  -198,   255,    43,   -10,     2,   -15,  -198,
    -198,   294,  -198,  -198,  -198,  -198,  -198,    88,  -198,  -198,
      96,    64,  -198,  -198,  -198,     9,    23,    50,  -198,   189,
     189,    -9,  -198,  -198,   281,    48,  -198,   106,  -198,     9,
     117,   346,   100,   115,   119,  -198,  -198,  -198,    72,    72,
     121,   127,  -198,   128,  -198,   123,   216,   346,   346,  -198,
    -198,   346,   346,    38,    38,  -198,   133,  -198,   216,  -198,
    -198,   346,   140,   320,   141,  -198,  -198,   346,  -198,   -13,
     346,   147,  -198,  -198,   144,  -198,  -198,  -198,  -198,   160,
    -198,  -198,  -198,   -30,   148,  -198,  -198,  -198,  -198,   132,
     216,   150,    72,  -198,   -25,  -198,   122,  -198,   216,  -198,
      72,  -198,  -198,  -198,  -198
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    16,     0,     0,     3,
       4,     0,    95,    96,     0,    97,     0,     0,   116,   117,
     118,     0,     7,     5,     8,    14,     0,    12,    13,    18,
      32,    19,    33,    29,    31,    52,    54,    56,    59,    60,
      73,    75,    77,    80,    83,    87,     0,    94,    98,   102,
       9,   120,   122,   159,     0,   121,   123,    58,   133,   132,
       0,   130,   114,   119,     0,    28,   162,     0,   102,     0,
      10,     0,     0,     0,    35,    36,    37,    39,    40,    41,
      42,    43,    44,    45,    47,    38,    46,     0,    30,     0,
       0,     0,     0,    69,    71,    62,    63,    64,    68,    66,
      65,    67,     0,     0,     0,     0,    85,    86,    79,     0,
      89,    90,    91,    92,     0,    93,     0,   100,   161,   160,
       0,   131,   115,   156,     0,     0,   101,     0,     0,    11,
      15,    24,    22,    23,    20,    21,    17,    48,    50,    34,
       0,    55,    57,    70,    72,    61,    74,    76,    78,     0,
       0,    84,    88,    99,     0,     0,   103,     0,   135,   134,
       0,     0,   111,     0,   107,   109,   163,   138,   148,     0,
     154,     0,   142,   140,   150,   152,     0,     0,     0,    25,
      27,    49,     0,    81,    82,   105,     0,   104,     0,   157,
     113,     0,     0,   108,   146,   148,   145,     0,   139,     0,
       0,     0,   126,   136,     0,    26,    51,    53,   106,   128,
     112,   158,   110,     0,   143,   155,   141,   151,   153,     0,
       0,     0,     0,   149,     0,   124,     0,   137,     0,   147,
       0,   127,   125,   129,   144
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -198,  -198,  -198,  -198,  -198,  -197,    -3,   101,  -198,  -198,
    -198,  -198,   103,  -198,    -6,    28,    85,  -198,  -198,  -112,
    -198,   -86,    86,    89,    -2,  -198,  -198,    -5,    75,    77,
      79,  -198,   -29,  -198,    71,  -198,   -36,  -198,  -198,  -198,
     118,  -198,    31,  -198,    10,   173,  -198,  -198,   137,  -198,
    -177,  -198,  -198,  -198,  -198,  -198,    -4,    13,  -198,  -123,
    -137,   153,  -198,  -198,  -198
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    22,     3,    23,   202,    25,    26,    27,
      28,    29,   132,   179,    30,    31,    32,    33,    87,   136,
     137,    34,    35,    36,    37,    38,   102,    39,    40,    41,
      42,   108,    43,   109,    44,   114,    45,    46,    47,    48,
     117,   156,   163,   164,   165,    49,    64,    50,    51,   226,
     203,    52,    60,    61,   128,   171,   172,   194,   173,   223,
     175,    53,    54,    55,    67
  };

  const unsigned char
  py_parser::yytable_[] =
  {
      24,   138,    58,    59,   174,    57,   176,   154,   157,    65,
     115,   209,    89,   168,    90,     5,   222,   110,   111,   180,
     167,   230,   225,   155,    92,   112,    93,    94,   168,   232,
       4,   195,   196,   169,   138,   170,   149,   150,   162,    63,
     170,    70,    56,   227,    66,   138,    95,    96,   169,   113,
      71,   233,   170,    69,    97,    98,    99,   100,   177,    88,
       5,     6,   106,   107,    72,     7,   104,   170,   162,     8,
       9,    10,    16,    91,    11,   190,   217,   103,   152,   105,
     153,    12,    13,    14,    21,   229,   116,   101,   120,   142,
     121,   204,   205,   234,   122,   206,   207,   145,   127,    15,
     133,   135,   182,    90,   143,   210,   144,   162,   166,   123,
     181,   215,   124,   187,   218,   158,   159,    16,    17,    11,
     183,   184,    18,    19,    20,     5,     6,   188,   125,    21,
       7,   189,   191,   192,     8,     5,     6,   170,   231,    11,
       7,   193,   197,     7,     8,   198,    12,    13,    14,    11,
     199,   208,    11,    62,   211,   200,    12,    13,    14,    12,
      13,    14,   219,   213,    15,   220,   221,    18,    19,    20,
     224,   228,   130,   139,    15,   140,   134,    15,   146,   141,
     151,   147,    16,    17,   148,   186,   126,    18,    19,    20,
      68,   118,    16,    17,    21,   216,    17,    18,    19,    20,
      18,    19,    20,   212,    21,     6,    11,   119,   214,     7,
       0,     0,     0,    12,    13,   129,    24,     0,    11,     0,
       6,     0,     0,    24,     7,    12,    13,    14,     0,     0,
     201,    15,     0,    11,     0,     7,     0,     0,     0,     0,
      12,    13,    14,    15,    11,     0,     0,     0,     0,     0,
      17,    12,    13,    14,    18,    19,    20,     0,    15,     0,
       0,     0,    17,     7,     0,     0,    18,    19,    20,    15,
       0,     0,    11,   160,     0,     0,     0,    17,     0,    12,
      13,    18,    19,    20,     0,     0,     0,     0,    17,     7,
       0,   131,    18,    19,    20,     0,     0,    15,    11,   185,
       0,   161,     7,     0,     0,    12,    13,     0,     0,     0,
       0,    11,     0,     0,     0,     7,    17,     0,    12,    13,
      18,    19,    20,    15,    11,     0,     0,   161,     7,     0,
       0,    12,    13,    14,     0,     0,    15,    11,     0,     0,
       0,     0,    17,     0,    12,    13,    18,    19,    20,    15,
       0,     0,     0,     0,     7,    17,     0,   178,     0,    18,
      19,    20,    15,    11,     0,     0,   161,     0,    17,     0,
      12,    13,    18,    19,    20,    11,     0,     0,     0,     0,
       0,    17,    12,    13,    14,    18,    19,    20,    15,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,     0,     0,     0,     0,     0,     0,    17,     0,     0,
       0,    18,    19,    20,    73,     0,     0,     0,     0,    17,
       0,     0,     0,    18,    19,    20,     0,     0,     0,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,     0,
       0,    84,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    85,    86
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,    87,     8,     8,   127,     7,    21,    17,   120,    14,
      46,   188,     5,    26,     7,     3,    46,    26,    27,   131,
      18,    46,   219,    33,     8,    34,    10,    11,    26,   226,
       0,   168,   169,    46,   120,    65,    44,    45,   124,    11,
      65,    14,    65,   220,    65,   131,    30,    31,    46,    58,
      23,   228,    65,    65,    38,    39,    40,    41,    73,    22,
       3,     4,    24,    25,    32,     8,    43,    65,   154,    12,
      13,    14,    60,     9,    17,   161,   199,    68,   114,    29,
     116,    24,    25,    26,    72,   222,    46,    71,    10,    91,
      22,   177,   178,   230,    18,   181,   182,   102,    17,    42,
      72,    73,     6,     7,    10,   191,     8,   193,    65,    14,
      22,   197,    17,    65,   200,   121,   121,    60,    61,    17,
     149,   150,    65,    66,    67,     3,     4,    21,    33,    72,
       8,    14,    32,    18,    12,     3,     4,    65,    16,    17,
       8,    22,    21,     8,    12,    18,    24,    25,    26,    17,
      22,    18,    17,    18,    14,    32,    24,    25,    26,    24,
      25,    26,    15,    22,    42,    21,     6,    65,    66,    67,
      22,    21,    71,    88,    42,    89,    73,    42,   103,    90,
     109,   104,    60,    61,   105,   154,    68,    65,    66,    67,
      17,    54,    60,    61,    72,   199,    61,    65,    66,    67,
      65,    66,    67,   193,    72,     4,    17,    54,   195,     8,
      -1,    -1,    -1,    24,    25,    14,   219,    -1,    17,    -1,
       4,    -1,    -1,   226,     8,    24,    25,    26,    -1,    -1,
      14,    42,    -1,    17,    -1,     8,    -1,    -1,    -1,    -1,
      24,    25,    26,    42,    17,    -1,    -1,    -1,    -1,    -1,
      61,    24,    25,    26,    65,    66,    67,    -1,    42,    -1,
      -1,    -1,    61,     8,    -1,    -1,    65,    66,    67,    42,
      -1,    -1,    17,    18,    -1,    -1,    -1,    61,    -1,    24,
      25,    65,    66,    67,    -1,    -1,    -1,    -1,    61,     8,
      -1,    64,    65,    66,    67,    -1,    -1,    42,    17,    18,
      -1,    46,     8,    -1,    -1,    24,    25,    -1,    -1,    -1,
      -1,    17,    -1,    -1,    -1,     8,    61,    -1,    24,    25,
      65,    66,    67,    42,    17,    -1,    -1,    46,     8,    -1,
      -1,    24,    25,    26,    -1,    -1,    42,    17,    -1,    -1,
      -1,    -1,    61,    -1,    24,    25,    65,    66,    67,    42,
      -1,    -1,    -1,    -1,     8,    61,    -1,    63,    -1,    65,
      66,    67,    42,    17,    -1,    -1,    46,    -1,    61,    -1,
      24,    25,    65,    66,    67,    17,    -1,    -1,    -1,    -1,
      -1,    61,    24,    25,    26,    65,    66,    67,    42,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,    -1,
      -1,    65,    66,    67,    32,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    -1,
      -1,    59,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    69,    70
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    75,    76,    78,     0,     3,     4,     8,    12,    13,
      14,    17,    24,    25,    26,    42,    60,    61,    65,    66,
      67,    72,    77,    79,    80,    81,    82,    83,    84,    85,
      88,    89,    90,    91,    95,    96,    97,    98,    99,   101,
     102,   103,   104,   106,   108,   110,   111,   112,   113,   119,
     121,   122,   125,   135,   136,   137,    65,    98,    88,   101,
     126,   127,    18,    89,   120,   101,    65,   138,   119,    65,
      14,    23,    32,    32,    47,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    59,    69,    70,    92,    22,     5,
       7,     9,     8,    10,    11,    30,    31,    38,    39,    40,
      41,    71,   100,    68,    43,    29,    24,    25,   105,   107,
      26,    27,    34,    58,   109,   110,    46,   114,   122,   135,
      10,    22,    18,    14,    17,    33,   114,    17,   128,    14,
      81,    64,    86,    89,    86,    89,    93,    94,    95,    90,
      96,    97,    98,    10,     8,   101,   102,   103,   104,    44,
      45,   108,   110,   110,    17,    33,   115,    93,    88,   101,
      18,    46,    95,   116,   117,   118,    65,    18,    26,    46,
      65,   129,   130,   132,   133,   134,    21,    73,    63,    87,
      93,    22,     6,   106,   106,    18,   116,    65,    21,    14,
      95,    32,    18,    22,   131,   134,   134,    21,    18,    22,
      32,    14,    80,   124,    95,    95,    95,    95,    18,   124,
      95,    14,   118,    22,   131,    95,   130,   133,    95,    15,
      21,     6,    46,   133,    22,    79,   123,   124,    21,   134,
      46,    16,    79,   124,   134
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    74,    75,    76,    77,    77,    78,    78,    79,    79,
      80,    80,    81,    81,    82,    82,    83,    84,    84,    84,
      85,    85,    85,    85,    86,    86,    87,    87,    88,    89,
      89,    90,    90,    91,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    92,    92,    92,    92,    93,    93,
      94,    94,    95,    95,    96,    96,    97,    97,    98,    98,
      99,    99,   100,   100,   100,   100,   100,   100,   100,   100,
     100,   100,   100,   101,   101,   102,   102,   103,   103,   104,
     105,   105,   105,   106,   106,   107,   107,   108,   108,   109,
     109,   109,   109,   110,   110,   111,   111,   111,   112,   112,
     113,   113,   114,   114,   115,   115,   115,   116,   116,   117,
     117,   118,   118,   118,   119,   119,   119,   119,   119,   120,
     121,   121,   121,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   127,   122,   122,   128,   128,
     129,   129,   129,   130,   130,   130,   130,   130,   131,   131,
     132,   132,   133,   133,   134,   134,   135,   135,   135,   136,
     136,   137,   138,   138
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     3,     1,     3,     1,     1,
       3,     3,     3,     3,     1,     2,     2,     1,     2,     1,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     3,     1,     5,     1,     3,     1,     3,     2,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     2,     1,     3,     1,     3,     1,     3,     2,
       0,     3,     3,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       2,     3,     0,     2,     2,     2,     3,     1,     2,     1,
       3,     1,     3,     2,     2,     3,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     2,     1,     4,     6,     9,
       1,     2,     1,     1,     3,     3,     5,     7,     2,     3,
       1,     3,     1,     3,     6,     2,     2,     5,     0,     3,
       1,     3,     1,     3,     1,     3,     3,     5,     6,     1,
       2,     2,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "DEF", "PASS", "\"if\"", "\"else\"",
  "\"or\"", "\"not\"", "\"and\"", "\"in\"", "\"is\"", "\"for\"",
  "ENDMARKER", "NEWLINE", "INDENT", "DEDENT", "\"(\"", "\")\"", "LSQB",
  "RSQB", "\":\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "VBAR", "\"&\"", "\"<\"", "\">\"", "\"=\"", "\".\"", "\"%\"", "\"`\"",
  "LBRACE", "RBRACE", "\"==\"", "\"!=\"", "\"<=\"", "\">=\"", "\"~\"",
  "\"^\"", "\"<<\"", "\">>\"", "\"**\"", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"",
  "\"**+\"", "\"//\"", "\"//=\"", "\"@\"", "\"await\"", "\"async\"",
  "\"from\"", "\"yield\"", "NAME", "NUMBER", "STRING", "\"|\"", "\"@=\"",
  "\"**=\"", "\"<>\"", "\"def\"", "\"->\"", "$accept", "module",
  "file_input", "newline_or_stmt", "newline_stmt_seq", "stmt",
  "simple_stmt", "small_stmt", "small_stmt_seq", "pass_stmt", "expr_stmt",
  "assign_expr_seq", "yield_expr", "yield_arg", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "shift_expr_seq", "arith_expr", "arith_op", "term",
  "term_op", "factor", "factor_op", "power", "atom_expr", "trailer_seq",
  "trailer", "arglist", "arglist_seq", "argument", "atom", "testlist_comp",
  "compound_stmt", "funcdef", "stmt_seq", "suite", "for_stmt", "exprlist",
  "exprlist_seq", "parameters", "typedargslist", "var_args",
  "var_arglist_trailer", "named_args", "tfpdef_test", "tfpdef",
  "decorator", "decorators", "decorated", "dotted_name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   170,   170,   191,   199,   203,   212,   216,   237,   241,
     251,   255,   266,   270,   280,   284,   295,   309,   313,   317,
     335,   339,   344,   348,   375,   376,   382,   383,   393,   412,
     417,   428,   428,   433,   438,   450,   450,   450,   450,   450,
     450,   450,   450,   450,   451,   451,   451,   451,   458,   459,
     466,   467,   479,   480,   486,   487,   493,   494,   500,   501,
     508,   509,   518,   519,   520,   521,   522,   523,   524,   525,
     526,   527,   528,   535,   536,   542,   543,   549,   550,   556,
     565,   566,   567,   578,   579,   583,   583,   589,   590,   594,
     594,   594,   594,   600,   601,   605,   605,   605,   611,   612,
     618,   619,   625,   626,   632,   633,   634,   641,   642,   649,
     650,   668,   669,   670,   701,   707,   712,   713,   714,   734,
     746,   747,   748,   754,   760,   761,   767,   768,   774,   775,
     781,   782,   788,   789,   790,   791,   797,   798,   804,   805,
     842,   849,   856,   865,   872,   880,   886,   894,   907,   908,
     919,   923,   931,   935,   948,   955,   969,   970,   971,   977,
     978,   984,   990,   991
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
    };
    const unsigned int user_token_number_max_ = 328;
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

