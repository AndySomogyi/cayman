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

      case 73: // module


        { yyoutput << (yysym.value); }

        break;

      case 74: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 75: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 76: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 77: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 78: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 79: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 80: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 81: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 82: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 83: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 84: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 85: // yield_arg


        { yyoutput << (yysym.value); }

        break;

      case 86: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 87: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 88: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 89: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 90: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 91: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 92: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 93: // test


        { yyoutput << (yysym.value); }

        break;

      case 94: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 95: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 96: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 97: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 98: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 99: // expr


        { yyoutput << (yysym.value); }

        break;

      case 100: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 101: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 102: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 103: // shift_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 104: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 105: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 106: // term


        { yyoutput << (yysym.value); }

        break;

      case 107: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 108: // factor


        { yyoutput << (yysym.value); }

        break;

      case 109: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 110: // power


        { yyoutput << (yysym.value); }

        break;

      case 111: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 112: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 113: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 114: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 115: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 116: // argument


        { yyoutput << (yysym.value); }

        break;

      case 117: // atom


        { yyoutput << (yysym.value); }

        break;

      case 118: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 119: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 120: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 121: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 122: // suite


        { yyoutput << (yysym.value); }

        break;

      case 123: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 124: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 125: // exprlist_seq


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


  const short int py_parser::yypact_ninf_ = -153;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -153,     8,  -153,    17,  -153,   -53,  -153,   264,   291,  -153,
    -153,   168,  -153,  -153,   294,  -153,   -13,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,    -5,  -153,  -153,     0,  -153,   315,
    -153,     6,  -153,    40,    46,  -153,   150,    -3,    23,    41,
    -153,    13,   -12,  -153,   294,  -153,    27,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,    -3,    65,    55,  -153,  -153,    62,
      -3,  -153,  -153,   102,   188,   188,  -153,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,  -153,   264,
     201,   264,   264,   264,    71,  -153,    77,  -153,  -153,  -153,
    -153,  -153,  -153,  -153,   294,   294,   294,   294,  -153,  -153,
     -28,   294,  -153,  -153,  -153,  -153,   294,  -153,   294,    -6,
     264,   291,  -153,    -6,  -153,  -153,   233,  -153,  -153,  -153,
    -153,  -153,    66,  -153,  -153,    44,    46,  -153,  -153,  -153,
      -3,    23,    41,  -153,   294,   294,   -12,  -153,  -153,   198,
      25,  -153,    73,  -153,    -3,   264,  -153,  -153,   264,   264,
      13,    13,  -153,   264,    63,    83,    80,  -153,  -153,   117,
    -153,  -153,  -153,  -153,   264,  -153,   261,    92,  -153,   103,
    -153,  -153,    88,    87,  -153,    32,   117,  -153,  -153,  -153
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    16,     0,     0,     3,
       4,     0,    95,    96,     0,    97,     0,   116,   117,   118,
       7,     5,     8,    14,     0,    12,    13,    18,    32,    19,
      33,    29,    31,    52,    54,    56,    59,    60,    73,    75,
      77,    80,    83,    87,     0,    94,    98,   102,     9,   120,
     121,   122,    58,   132,   131,     0,   129,   114,   119,     0,
      28,   102,    10,     0,     0,     0,    35,    36,    37,    39,
      40,    41,    42,    43,    44,    45,    47,    38,    46,     0,
      30,     0,     0,     0,     0,    69,    71,    62,    63,    64,
      68,    66,    65,    67,     0,     0,     0,     0,    85,    86,
      79,     0,    89,    90,    91,    92,     0,    93,     0,   100,
       0,   130,   115,   101,    11,    15,    24,    22,    23,    20,
      21,    17,    48,    50,    34,     0,    55,    57,    70,    72,
      61,    74,    76,    78,     0,     0,    84,    88,    99,     0,
       0,   103,     0,   134,   133,     0,    25,    27,    49,     0,
      81,    82,   105,     0,   111,     0,   107,   109,   104,     0,
      26,    51,    53,   113,     0,   106,   108,     0,   125,   127,
     112,   110,     0,     0,   123,     0,     0,   126,   124,   128
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -153,  -153,  -153,  -153,  -153,  -149,  -152,    48,  -153,  -153,
    -153,  -153,    50,  -153,    -7,    -1,    37,  -153,  -153,   -97,
    -153,   -77,    39,    36,    -4,  -153,  -153,    -8,    28,    26,
      35,  -153,   -74,  -153,    34,  -153,   -39,  -153,  -153,  -153,
      68,  -153,  -153,  -153,   -42,   120,  -153,  -153,  -153,  -153,
     -43,  -153,  -153,  -153
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    20,     3,    21,    22,    23,    24,    25,
      26,    27,   117,   146,    28,    29,    30,    31,    79,   121,
     122,    32,    33,    34,    35,    36,    94,    37,    38,    39,
      40,   100,    41,   101,    42,   106,    43,    44,    45,    46,
     109,   141,   155,   156,   157,    47,    59,    48,    49,   175,
     169,    50,    55,    56
  };

  const unsigned char
  py_parser::yytable_[] =
  {
      54,    53,   123,    52,    11,   107,    60,   168,     4,    62,
      58,   139,    51,   142,   102,   103,   134,   135,    63,   147,
       5,     6,   104,   174,   168,     7,   178,   140,    80,     8,
       9,    10,    64,   123,    11,     5,     6,    98,    99,   123,
       7,    12,    13,    14,     8,    81,   105,    82,   177,    11,
     149,    82,    17,    18,    19,    83,    12,    13,    14,    15,
     150,   151,   154,   118,   120,    95,    96,   137,   160,   138,
      97,   161,   162,   108,    15,   110,   163,   111,    16,   127,
     112,   128,    17,    18,    19,   129,   130,   170,   148,   154,
     158,     5,     6,    16,   159,   164,     7,    17,    18,    19,
       8,   165,   166,   144,   143,    11,     6,   172,   176,   173,
       7,   115,    12,    13,    14,   119,   114,   124,   126,    11,
     125,     6,   132,   131,   171,     7,    12,    13,    14,   113,
      15,   167,   133,   179,    11,   136,    61,     0,     0,     0,
       0,    12,    13,    14,    15,     0,     0,     0,     0,    16,
       0,     0,     0,    17,    18,    19,     0,     0,    84,    15,
      85,    86,     0,    16,     0,     0,     0,    17,    18,    19,
       0,     0,     0,     0,     0,     0,     7,     0,    16,     0,
      87,    88,    17,    18,    19,    11,    57,     0,    89,    90,
      91,    92,    12,    13,    14,     0,     7,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     7,     0,     0,     7,
      15,     0,    12,    13,    14,    11,   152,     0,    11,     0,
       0,    93,    12,    13,     0,    12,    13,    14,     0,    16,
      15,     0,     0,    17,    18,    19,     0,     0,     0,     0,
      15,     7,     0,    15,   153,     0,     0,     0,     0,    16,
      11,     0,   116,    17,    18,    19,     0,    12,    13,    16,
       0,     0,    16,    17,    18,    19,    17,    18,    19,     7,
       0,     0,     7,     0,     0,    15,     0,     0,    11,     0,
       0,    11,     0,     0,     0,    12,    13,     0,    12,    13,
       0,     0,     0,     0,    16,     0,   145,     0,    17,    18,
      19,     0,     0,    15,     0,     0,    15,   153,    11,     0,
       0,    11,     0,     0,     0,    12,    13,    14,    12,    13,
       0,     0,    16,     0,     0,    16,    17,    18,    19,    17,
      18,    19,     0,    15,     0,     0,    15,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    65,     0,     0,
       0,     0,    16,     0,     0,    16,    17,    18,    19,    17,
      18,    19,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,     0,     0,    76,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    77,    78
  };

  const short int
  py_parser::yycheck_[] =
  {
       8,     8,    79,     7,    17,    44,    14,   159,     0,    14,
      11,    17,    65,   110,    26,    27,    44,    45,    23,   116,
       3,     4,    34,   172,   176,     8,   175,    33,    22,    12,
      13,    14,    32,   110,    17,     3,     4,    24,    25,   116,
       8,    24,    25,    26,    12,     5,    58,     7,    16,    17,
       6,     7,    65,    66,    67,     9,    24,    25,    26,    42,
     134,   135,   139,    64,    65,    68,    43,   106,   145,   108,
      29,   148,   149,    46,    42,    10,   153,    22,    61,    83,
      18,    10,    65,    66,    67,     8,    94,   164,    22,   166,
      65,     3,     4,    61,    21,    32,     8,    65,    66,    67,
      12,    18,    22,   111,   111,    17,     4,    15,    21,     6,
       8,    63,    24,    25,    26,    65,    14,    80,    82,    17,
      81,     4,    96,    95,   166,     8,    24,    25,    26,    61,
      42,    14,    97,   176,    17,   101,    16,    -1,    -1,    -1,
      -1,    24,    25,    26,    42,    -1,    -1,    -1,    -1,    61,
      -1,    -1,    -1,    65,    66,    67,    -1,    -1,     8,    42,
      10,    11,    -1,    61,    -1,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,     8,    -1,    61,    -1,
      30,    31,    65,    66,    67,    17,    18,    -1,    38,    39,
      40,    41,    24,    25,    26,    -1,     8,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    17,     8,    -1,    -1,     8,
      42,    -1,    24,    25,    26,    17,    18,    -1,    17,    -1,
      -1,    71,    24,    25,    -1,    24,    25,    26,    -1,    61,
      42,    -1,    -1,    65,    66,    67,    -1,    -1,    -1,    -1,
      42,     8,    -1,    42,    46,    -1,    -1,    -1,    -1,    61,
      17,    -1,    64,    65,    66,    67,    -1,    24,    25,    61,
      -1,    -1,    61,    65,    66,    67,    65,    66,    67,     8,
      -1,    -1,     8,    -1,    -1,    42,    -1,    -1,    17,    -1,
      -1,    17,    -1,    -1,    -1,    24,    25,    -1,    24,    25,
      -1,    -1,    -1,    -1,    61,    -1,    63,    -1,    65,    66,
      67,    -1,    -1,    42,    -1,    -1,    42,    46,    17,    -1,
      -1,    17,    -1,    -1,    -1,    24,    25,    26,    24,    25,
      -1,    -1,    61,    -1,    -1,    61,    65,    66,    67,    65,
      66,    67,    -1,    42,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    32,    -1,    -1,
      -1,    -1,    61,    -1,    -1,    61,    65,    66,    67,    65,
      66,    67,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    -1,    -1,    59,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    69,    70
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    73,    74,    76,     0,     3,     4,     8,    12,    13,
      14,    17,    24,    25,    26,    42,    61,    65,    66,    67,
      75,    77,    78,    79,    80,    81,    82,    83,    86,    87,
      88,    89,    93,    94,    95,    96,    97,    99,   100,   101,
     102,   104,   106,   108,   109,   110,   111,   117,   119,   120,
     123,    65,    96,    86,    99,   124,   125,    18,    87,   118,
      99,   117,    14,    23,    32,    32,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    59,    69,    70,    90,
      22,     5,     7,     9,     8,    10,    11,    30,    31,    38,
      39,    40,    41,    71,    98,    68,    43,    29,    24,    25,
     103,   105,    26,    27,    34,    58,   107,   108,    46,   112,
      10,    22,    18,   112,    14,    79,    64,    84,    87,    84,
      87,    91,    92,    93,    88,    94,    95,    96,    10,     8,
      99,   100,   101,   102,    44,    45,   106,   108,   108,    17,
      33,   113,    91,    86,    99,    63,    85,    91,    22,     6,
     104,   104,    18,    46,    93,   114,   115,   116,    65,    21,
      93,    93,    93,    93,    32,    18,    22,    14,    78,   122,
      93,   116,    15,     6,    77,   121,    21,    16,    77,   122
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    72,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    80,    80,    81,    82,    82,    82,
      83,    83,    83,    83,    84,    84,    85,    85,    86,    87,
      87,    88,    88,    89,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    90,    90,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      97,    97,    98,    98,    98,    98,    98,    98,    98,    98,
      98,    98,    98,    99,    99,   100,   100,   101,   101,   102,
     103,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   107,   107,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   112,   112,   113,   113,   113,   114,   114,   115,
     115,   116,   116,   116,   117,   117,   117,   117,   117,   118,
     119,   119,   120,   121,   121,   122,   122,   123,   123,   124,
     124,   125,   125,   125,   125
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
       1,     1,     2,     1,     2,     1,     4,     6,     9,     1,
       2,     1,     1,     3,     3
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
  "\"**=\"", "\"<>\"", "$accept", "module", "file_input",
  "newline_or_stmt", "newline_stmt_seq", "stmt", "simple_stmt",
  "small_stmt", "small_stmt_seq", "pass_stmt", "expr_stmt",
  "assign_expr_seq", "yield_expr", "yield_arg", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "shift_expr_seq", "arith_expr", "arith_op", "term",
  "term_op", "factor", "factor_op", "power", "atom_expr", "trailer_seq",
  "trailer", "arglist", "arglist_seq", "argument", "atom", "testlist_comp",
  "compound_stmt", "funcdef", "stmt_seq", "suite", "for_stmt", "exprlist",
  "exprlist_seq", YY_NULLPTR
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
     746,   747,   753,   759,   760,   766,   767,   773,   774,   780,
     781,   787,   788,   789,   790
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
      65,    66,    67,    68,    69,    70,    71
    };
    const unsigned int user_token_number_max_ = 326;
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

