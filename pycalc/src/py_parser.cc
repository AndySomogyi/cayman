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

      case 12: // ENDMARKER


        { yyoutput << (yysym.value); }

        break;

      case 13: // NEWLINE


        { yyoutput << (yysym.value); }

        break;

      case 14: // INDENT


        { yyoutput << (yysym.value); }

        break;

      case 15: // DEDENT


        { yyoutput << (yysym.value); }

        break;

      case 16: // ")"


        { yyoutput << (yysym.value); }

        break;

      case 17: // "("


        { yyoutput << (yysym.value); }

        break;

      case 18: // LSQB


        { yyoutput << (yysym.value); }

        break;

      case 19: // RSQB


        { yyoutput << (yysym.value); }

        break;

      case 20: // ":"


        { yyoutput << (yysym.value); }

        break;

      case 21: // ","


        { yyoutput << (yysym.value); }

        break;

      case 22: // ";"


        { yyoutput << (yysym.value); }

        break;

      case 23: // "+"


        { yyoutput << (yysym.value); }

        break;

      case 24: // "-"


        { yyoutput << (yysym.value); }

        break;

      case 25: // "*"


        { yyoutput << (yysym.value); }

        break;

      case 26: // "/"


        { yyoutput << (yysym.value); }

        break;

      case 27: // VBAR


        { yyoutput << (yysym.value); }

        break;

      case 28: // "&"


        { yyoutput << (yysym.value); }

        break;

      case 29: // "<"


        { yyoutput << (yysym.value); }

        break;

      case 30: // ">"


        { yyoutput << (yysym.value); }

        break;

      case 31: // "="


        { yyoutput << (yysym.value); }

        break;

      case 32: // "."


        { yyoutput << (yysym.value); }

        break;

      case 33: // "%"


        { yyoutput << (yysym.value); }

        break;

      case 34: // "`"


        { yyoutput << (yysym.value); }

        break;

      case 35: // LBRACE


        { yyoutput << (yysym.value); }

        break;

      case 36: // RBRACE


        { yyoutput << (yysym.value); }

        break;

      case 37: // "=="


        { yyoutput << (yysym.value); }

        break;

      case 38: // "!="


        { yyoutput << (yysym.value); }

        break;

      case 39: // "<="


        { yyoutput << (yysym.value); }

        break;

      case 40: // ">="


        { yyoutput << (yysym.value); }

        break;

      case 41: // "~"


        { yyoutput << (yysym.value); }

        break;

      case 42: // "^"


        { yyoutput << (yysym.value); }

        break;

      case 43: // "<<"


        { yyoutput << (yysym.value); }

        break;

      case 44: // ">>"


        { yyoutput << (yysym.value); }

        break;

      case 45: // "**"


        { yyoutput << (yysym.value); }

        break;

      case 46: // "+="


        { yyoutput << (yysym.value); }

        break;

      case 47: // "-="


        { yyoutput << (yysym.value); }

        break;

      case 48: // "*="


        { yyoutput << (yysym.value); }

        break;

      case 49: // "/="


        { yyoutput << (yysym.value); }

        break;

      case 50: // "%="


        { yyoutput << (yysym.value); }

        break;

      case 51: // "&="


        { yyoutput << (yysym.value); }

        break;

      case 52: // "|="


        { yyoutput << (yysym.value); }

        break;

      case 53: // "^="


        { yyoutput << (yysym.value); }

        break;

      case 54: // "<<="


        { yyoutput << (yysym.value); }

        break;

      case 55: // ">>="


        { yyoutput << (yysym.value); }

        break;

      case 56: // "**+"


        { yyoutput << (yysym.value); }

        break;

      case 57: // "//"


        { yyoutput << (yysym.value); }

        break;

      case 58: // "//="


        { yyoutput << (yysym.value); }

        break;

      case 59: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 60: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 61: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 62: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 63: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 64: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 65: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 66: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 67: // "|"


        { yyoutput << (yysym.value); }

        break;

      case 68: // "@="


        { yyoutput << (yysym.value); }

        break;

      case 69: // "**="


        { yyoutput << (yysym.value); }

        break;

      case 70: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 72: // module


        { yyoutput << (yysym.value); }

        break;

      case 73: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 74: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 75: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 76: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 77: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 78: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 79: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 80: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 81: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 82: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 83: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 84: // yield_arg


        { yyoutput << (yysym.value); }

        break;

      case 85: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 86: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 87: // test_or_star


        { yyoutput << (yysym.value); }

        break;

      case 88: // test_or_star_seq


        { yyoutput << (yysym.value); }

        break;

      case 89: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 90: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 91: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 92: // test


        { yyoutput << (yysym.value); }

        break;

      case 93: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 94: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 95: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 96: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 97: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 98: // expr


        { yyoutput << (yysym.value); }

        break;

      case 99: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 100: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 101: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 102: // shift_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 103: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 104: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 105: // term


        { yyoutput << (yysym.value); }

        break;

      case 106: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 107: // factor


        { yyoutput << (yysym.value); }

        break;

      case 108: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 109: // power


        { yyoutput << (yysym.value); }

        break;

      case 110: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 111: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 112: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 113: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 114: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 115: // argument


        { yyoutput << (yysym.value); }

        break;

      case 116: // atom


        { yyoutput << (yysym.value); }

        break;

      case 117: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 118: // funcdef


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
        (yylhs.value) = NULL;
    }

    break;

  case 5:

    {
        (yylhs.value) = (yystack_[0].value);
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
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 9:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 10:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 11:

    {
        (yylhs.value) = (yystack_[2].value);
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
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 20:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 21:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 22:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 113:

    {(yylhs.value) = (yystack_[2].value);}

    break;

  case 114:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 115:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 116:

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


  const signed char py_parser::yypact_ninf_ = -79;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
     -79,     4,   -79,     2,   -79,   -56,   -79,   169,   -79,   -79,
      96,   -79,   -79,   181,   -79,   -14,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,     8,   -79,   -79,   -19,   -79,   205,   -79,
      -3,   -79,     6,    14,   -79,    72,   -36,    -8,    11,   -79,
       5,    -9,   -79,   181,   -79,     9,   -79,   -79,   -79,   -79,
     -79,    28,   -36,   -79,   -79,    32,    83,    83,   -79,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,   -79,
     -79,   169,    96,   169,   169,   169,    43,   -79,    51,   -79,
     -79,   -79,   -79,   -79,   -79,   -79,   181,   181,   181,   181,
     -79,   -79,   -11,   181,   -79,   -79,   -79,   -79,   181,   -79,
     181,   -10,   -79,   -10,   -79,   -79,   147,   -79,   -79,   -79,
     -79,   -79,    39,   -79,   -79,    31,    14,   -79,   -79,   -79,
     -36,    -8,    11,   -79,   181,   181,    -9,   -79,   -79,   109,
      12,   -79,   169,   -79,   -79,   169,   169,     5,     5,   -79,
     169,    41,    47,    57,   -79,   -79,   -79,   -79,   -79,   -79,
     169,   -79,   155,   -79,   -79
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    16,     0,     3,     4,
       0,    94,    95,     0,    96,     0,   114,   115,   116,     7,
       5,     8,    14,     0,    12,    13,    18,    31,     0,    32,
      28,    30,    51,    53,    55,    58,    59,    72,    74,    76,
      79,    82,    86,     0,    93,    97,   101,     9,   117,   118,
      57,     0,    27,   101,    10,     0,     0,     0,    34,    35,
      36,    38,    39,    40,    41,    42,    43,    44,    46,    37,
      45,     0,    29,     0,     0,     0,     0,    68,    70,    61,
      62,    63,    67,    65,    64,    66,     0,     0,     0,     0,
      84,    85,    78,     0,    88,    89,    90,    91,     0,    92,
       0,    99,   113,   100,    11,    15,    23,    21,    22,    19,
      20,    17,    47,    49,    33,     0,    54,    56,    69,    71,
      60,    73,    75,    77,     0,     0,    83,    87,    98,     0,
       0,   102,     0,    24,    26,    48,     0,    80,    81,   104,
       0,   110,     0,   106,   108,   103,    25,    50,    52,   112,
       0,   105,   107,   111,   109
  };

  const signed char
  py_parser::yypgoto_[] =
  {
     -79,   -79,   -79,   -79,   -79,   -79,   -79,    29,   -79,   -79,
     -79,   -79,    30,   -79,   -79,   -15,    -1,   -79,   -79,   -21,
     -79,   -71,    13,    15,    -5,   -79,   -79,   -12,     1,     7,
      10,   -79,   -78,   -79,     0,   -79,   -23,   -79,   -79,   -79,
      37,   -79,   -79,   -79,   -58,    88,   -79,   -79
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    19,     3,    20,    21,    22,    23,    24,
      25,    26,   107,   133,    27,    28,    29,    30,    71,   111,
     112,    31,    32,    33,    34,    35,    86,    36,    37,    38,
      39,    92,    40,    93,    41,    98,    42,    43,    44,    45,
     101,   131,   142,   143,   144,    46,    47,    48
  };

  const unsigned char
  py_parser::yytable_[] =
  {
     113,    52,    50,    10,     4,     5,     6,   129,    49,    51,
       7,    73,    56,    74,     8,     9,    94,    95,    72,    10,
      99,    54,   130,    75,    96,    11,    12,    13,    90,    91,
      55,    87,   124,   125,    88,   113,     6,   136,    74,    89,
       7,   108,   110,    14,   102,   104,   137,   138,    97,    10,
      16,    17,    18,   118,   100,    11,    12,    13,   141,   119,
     135,   146,    15,   151,   147,   148,    16,    17,    18,   149,
     117,   114,   150,    14,   120,   127,   145,   128,   152,   153,
      76,   141,    77,    78,   105,   134,   115,   109,   121,   116,
     103,     7,    15,   126,   154,   122,    16,    17,    18,   123,
      10,    79,    80,    53,     7,     0,    11,    12,    13,    81,
      82,    83,    84,    10,     0,     0,     0,     7,     0,    11,
      12,    13,     0,     0,    14,   139,    10,     0,     0,     0,
       0,     0,    11,    12,     0,     0,     0,    14,     0,     0,
       0,     0,    85,    15,     0,     0,   106,    16,    17,    18,
      14,     0,     0,     0,   140,     7,    15,     0,     0,     0,
      16,    17,    18,     7,    10,     0,     0,     0,     0,    15,
      11,    12,    10,    16,    17,    18,     0,     7,    11,    12,
       0,     0,     0,     0,     0,     0,    10,     0,    14,     0,
       0,     0,    11,    12,     0,     0,    14,     0,    10,     0,
     140,     0,     0,     0,    11,    12,     0,    15,     0,   132,
      14,    16,    17,    18,     0,    15,     0,     0,     0,    16,
      17,    18,    14,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    16,    17,    18,    57,     0,     0,     0,
       0,    15,     0,     0,     0,    16,    17,    18,     0,     0,
       0,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,     0,     0,    68,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    69,    70
  };

  const short int
  py_parser::yycheck_[] =
  {
      71,    13,     7,    17,     0,     3,     4,    17,    64,    10,
       8,     5,    31,     7,    12,    13,    25,    26,    21,    17,
      43,    13,    32,     9,    33,    23,    24,    25,    23,    24,
      22,    67,    43,    44,    42,   106,     4,     6,     7,    28,
       8,    56,    57,    41,    16,    13,   124,   125,    57,    17,
      64,    65,    66,    10,    45,    23,    24,    25,   129,     8,
      21,   132,    60,    16,   135,   136,    64,    65,    66,   140,
      75,    72,    31,    41,    86,    98,    64,   100,    21,   150,
       8,   152,    10,    11,    55,   106,    73,    57,    87,    74,
      53,     8,    60,    93,   152,    88,    64,    65,    66,    89,
      17,    29,    30,    15,     8,    -1,    23,    24,    25,    37,
      38,    39,    40,    17,    -1,    -1,    -1,     8,    -1,    23,
      24,    25,    -1,    -1,    41,    16,    17,    -1,    -1,    -1,
      -1,    -1,    23,    24,    -1,    -1,    -1,    41,    -1,    -1,
      -1,    -1,    70,    60,    -1,    -1,    63,    64,    65,    66,
      41,    -1,    -1,    -1,    45,     8,    60,    -1,    -1,    -1,
      64,    65,    66,     8,    17,    -1,    -1,    -1,    -1,    60,
      23,    24,    17,    64,    65,    66,    -1,     8,    23,    24,
      -1,    -1,    -1,    -1,    -1,    -1,    17,    -1,    41,    -1,
      -1,    -1,    23,    24,    -1,    -1,    41,    -1,    17,    -1,
      45,    -1,    -1,    -1,    23,    24,    -1,    60,    -1,    62,
      41,    64,    65,    66,    -1,    60,    -1,    -1,    -1,    64,
      65,    66,    41,    -1,    -1,    -1,    -1,    -1,    -1,    60,
      -1,    -1,    -1,    64,    65,    66,    31,    -1,    -1,    -1,
      -1,    60,    -1,    -1,    -1,    64,    65,    66,    -1,    -1,
      -1,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    -1,    -1,    58,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    72,    73,    75,     0,     3,     4,     8,    12,    13,
      17,    23,    24,    25,    41,    60,    64,    65,    66,    74,
      76,    77,    78,    79,    80,    81,    82,    85,    86,    87,
      88,    92,    93,    94,    95,    96,    98,    99,   100,   101,
     103,   105,   107,   108,   109,   110,   116,   117,   118,    64,
      95,    87,    98,   116,    13,    22,    31,    31,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    58,    68,
      69,    89,    21,     5,     7,     9,     8,    10,    11,    29,
      30,    37,    38,    39,    40,    70,    97,    67,    42,    28,
      23,    24,   102,   104,    25,    26,    33,    57,   106,   107,
      45,   111,    16,   111,    13,    78,    63,    83,    86,    83,
      86,    90,    91,    92,    87,    93,    94,    95,    10,     8,
      98,    99,   100,   101,    43,    44,   105,   107,   107,    17,
      32,   112,    62,    84,    90,    21,     6,   103,   103,    16,
      45,    92,   113,   114,   115,    64,    92,    92,    92,    92,
      31,    16,    21,    92,   115
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    82,
      82,    82,    82,    83,    83,    84,    84,    85,    86,    86,
      87,    87,    88,    88,    89,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   102,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   109,   109,   110,
     110,   111,   111,   112,   112,   112,   113,   113,   114,   114,
     115,   115,   115,   116,   116,   116,   116,   117,   118
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     3,     1,     3,     1,     3,
       3,     3,     3,     1,     2,     2,     1,     2,     1,     2,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     5,     1,     3,     1,     3,     2,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       1,     2,     1,     3,     1,     3,     1,     3,     2,     0,
       3,     3,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     2,     1,     1,     1,     1,     1,     3,     2,
       3,     0,     2,     2,     2,     3,     1,     2,     1,     3,
       1,     3,     2,     3,     1,     1,     1,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "DEF", "PASS", "\"if\"", "\"else\"",
  "\"or\"", "\"not\"", "\"and\"", "\"in\"", "\"is\"", "ENDMARKER",
  "NEWLINE", "INDENT", "DEDENT", "\")\"", "\"(\"", "LSQB", "RSQB", "\":\"",
  "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "VBAR", "\"&\"",
  "\"<\"", "\">\"", "\"=\"", "\".\"", "\"%\"", "\"`\"", "LBRACE", "RBRACE",
  "\"==\"", "\"!=\"", "\"<=\"", "\">=\"", "\"~\"", "\"^\"", "\"<<\"",
  "\">>\"", "\"**\"", "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"",
  "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"", "\"**+\"", "\"//\"",
  "\"//=\"", "\"@\"", "\"await\"", "\"async\"", "\"from\"", "\"yield\"",
  "NAME", "NUMBER", "STRING", "\"|\"", "\"@=\"", "\"**=\"", "\"<>\"",
  "$accept", "module", "file_input", "newline_or_stmt", "newline_stmt_seq",
  "stmt", "simple_stmt", "small_stmt", "small_stmt_seq", "pass_stmt",
  "expr_stmt", "assign_expr_seq", "yield_expr", "yield_arg", "star_expr",
  "testlist_star_expr", "test_or_star", "test_or_star_seq", "augassign",
  "testlist", "test_seq", "test", "or_test", "and_test", "not_test",
  "comparison", "comp_op", "expr", "xor_expr", "and_expr", "shift_expr",
  "shift_expr_seq", "arith_expr", "arith_op", "term", "term_op", "factor",
  "factor_op", "power", "atom_expr", "trailer_seq", "trailer", "arglist",
  "arglist_seq", "argument", "atom", "compound_stmt", "funcdef", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   169,   169,   190,   198,   202,   211,   215,   236,   240,
     249,   253,   264,   268,   278,   279,   286,   298,   302,   320,
     324,   329,   333,   360,   361,   367,   368,   378,   386,   387,
     392,   392,   397,   398,   405,   405,   405,   405,   405,   405,
     405,   405,   405,   406,   406,   406,   406,   413,   414,   421,
     422,   434,   435,   441,   442,   448,   449,   455,   456,   463,
     464,   473,   474,   475,   476,   477,   478,   479,   480,   481,
     482,   483,   490,   491,   497,   498,   504,   505,   511,   520,
     521,   522,   533,   534,   538,   538,   544,   545,   549,   549,
     549,   549,   555,   556,   560,   560,   560,   566,   567,   573,
     574,   580,   581,   587,   588,   589,   596,   597,   604,   605,
     623,   624,   625,   656,   657,   658,   659,   673,   679
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
      65,    66,    67,    68,    69,    70
    };
    const unsigned int user_token_number_max_ = 325;
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

