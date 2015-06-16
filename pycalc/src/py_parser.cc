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

      case 19: // "["


        { yyoutput << (yysym.value); }

        break;

      case 20: // "]"


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

      case 28: // "|"


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

      case 36: // "{"


        { yyoutput << (yysym.value); }

        break;

      case 37: // "}"


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

      case 68: // "@="


        { yyoutput << (yysym.value); }

        break;

      case 69: // "**="


        { yyoutput << (yysym.value); }

        break;

      case 70: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 71: // "->"


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

      case 103: // shift_op


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

      case 120: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 121: // suite


        { yyoutput << (yysym.value); }

        break;

      case 122: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 123: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 124: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 125: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 126: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 127: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 128: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 129: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 130: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 131: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 132: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 133: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 134: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 135: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 136: // dotted_name


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

  case 28:

    {
        (yylhs.value) = ctx.ast->CreateStarred(yylhs.location, (yystack_[0].value));
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

  case 51:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 61:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 62:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 63:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
    }

    break;

  case 74:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 76:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 78:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 80:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 84:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 88:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 99:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 101:

    {
        Call *call = dynamic_cast<Call*>((yystack_[0].value));
        assert(call);
        call->SetFunc((yystack_[1].value));

        (yylhs.value) = call;
    }

    break;

  case 102:

    {
        assert(0);
    }

    break;

  case 103:

    {
        assert(0);
    }

    break;

  case 107:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 108:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[1].value));
    }

    break;

  case 110:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 111:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 112:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 115:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 116:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 117:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 118:

    {
        // atom: |"(" testlist_comp ")"
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 119:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 120:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 121:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 126:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 127:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 128:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 129:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 130:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 131:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 133:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 134:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 135:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 138:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 139:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[0].value));
    }

    break;

  case 140:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 141:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 142:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 143:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 144:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 145:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 146:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 147:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 148:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 149:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 150:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 151:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 152:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 153:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 154:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 155:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 156:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 157:

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


  const short int py_parser::yypact_ninf_ = -190;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -190,    21,  -190,     6,  -190,   -54,  -190,   342,   362,  -190,
    -190,   246,  -190,  -190,   377,  -190,   -19,    -5,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,     1,  -190,  -190,    17,  -190,
     398,  -190,    46,  -190,    79,    76,  -190,   217,    64,    31,
      68,    14,    65,     7,  -190,   377,  -190,    52,    37,  -190,
    -190,  -190,  -190,     3,  -190,    82,  -190,  -190,    64,    91,
      80,  -190,  -190,    87,    64,  -190,    23,    37,  -190,   139,
     266,   266,  -190,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
    -190,  -190,  -190,  -190,  -190,   342,   311,   342,   342,   342,
      97,  -190,   101,  -190,  -190,  -190,  -190,  -190,  -190,  -190,
     377,   377,   377,   377,  -190,  -190,   377,  -190,  -190,   377,
    -190,  -190,  -190,  -190,   377,  -190,   377,   151,    48,    37,
    -190,  -190,  -190,    -1,     8,   342,   362,  -190,  -190,   235,
      49,    37,  -190,  -190,   332,  -190,  -190,  -190,  -190,  -190,
      96,  -190,  -190,    89,    76,  -190,  -190,  -190,    64,    31,
      68,    14,    65,     7,  -190,  -190,  -190,   342,  -190,    92,
      93,   104,  -190,  -190,  -190,  -190,    58,    58,   110,   115,
    -190,   112,  -190,   103,   184,   342,   119,  -190,    64,   128,
     126,  -190,   342,  -190,  -190,   342,   342,  -190,   342,  -190,
     297,   123,  -190,  -190,   342,  -190,   -10,   342,   131,  -190,
    -190,   130,   184,  -190,   138,  -190,  -190,  -190,  -190,  -190,
      -8,   132,  -190,  -190,  -190,  -190,   124,   184,   152,  -190,
      58,  -190,     4,  -190,   113,  -190,   136,  -190,    58,  -190,
    -190,   184,  -190,  -190
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    16,     0,     0,     3,
       4,     0,    95,    96,     0,    97,     0,     0,   119,   120,
     121,     7,     5,     8,    14,     0,    12,    13,    18,    32,
      19,    33,    29,    31,    52,    54,    56,    59,    60,    73,
      75,    77,    79,    83,    87,     0,    93,    98,   100,     9,
     125,   123,   161,     0,   124,     0,    58,   137,   136,     0,
     132,   117,   122,     0,    28,   164,     0,   102,    10,     0,
       0,     0,    35,    36,    37,    39,    40,    41,    42,    43,
      44,    45,    47,    38,    46,     0,    30,     0,     0,     0,
       0,    71,    72,    64,    65,    66,    70,    68,    67,    69,
       0,     0,     0,     0,    81,    82,     0,    85,    86,     0,
      89,    90,    91,    92,     0,    94,     0,     0,     0,   101,
     104,   163,   162,     0,     0,     0,   133,   118,   158,     0,
       0,   103,    11,    15,    24,    22,    23,    20,    21,    17,
      48,    50,    34,     0,    55,    57,    62,    63,    61,    74,
      76,    78,    80,    84,    88,    99,   107,     0,   114,   113,
       0,   109,   111,   106,   105,   140,   150,     0,   156,     0,
     144,   142,   152,   154,     0,     0,     0,   135,   134,     0,
       0,   165,     0,    25,    27,    49,     0,   116,     0,   108,
     110,   148,   150,   147,     0,   141,     0,     0,     0,   128,
     138,     0,     0,   159,     0,    26,    51,    53,   115,   112,
       0,   145,   157,   143,   153,   155,     0,     0,   130,   160,
       0,   151,     0,   126,     0,   139,     0,   149,     0,   129,
     127,     0,   146,   131
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -190,  -190,  -190,  -190,  -190,  -133,    -3,    98,  -190,  -190,
    -190,  -190,    90,  -190,    -7,    11,    74,  -190,  -190,   -81,
    -190,   -82,    75,    83,    -2,  -190,  -190,    -6,    69,    70,
      84,  -190,    88,  -190,    73,  -190,   -38,  -190,  -190,  -190,
     129,   -80,    57,  -190,     5,   182,  -190,  -190,  -190,  -189,
    -190,  -190,  -190,   149,  -190,  -190,    15,    22,  -190,  -119,
    -140,   150,  -190,  -190,  -190
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    21,     3,    22,   199,    24,    25,    26,
      27,    28,   135,   183,    29,    30,    31,    32,    85,   139,
     140,    33,    34,    35,    36,    37,   100,    38,    39,    40,
      41,   106,    42,   109,    43,   114,    44,    45,    46,    47,
     119,   120,   160,   161,   162,    48,    63,    49,   224,   200,
      50,    59,    60,    51,   124,   169,   170,   191,   171,   221,
     173,    52,    53,    54,    66
  };

  const unsigned char
  py_parser::yytable_[] =
  {
      23,    57,    58,   141,   172,    56,     5,   115,    64,     5,
       6,    55,    11,   218,     7,    68,   166,   165,     8,     9,
      10,     4,    62,    11,    69,   166,   192,   193,   225,   174,
      12,    13,    14,   110,   111,   159,   167,   128,   220,   164,
     129,   112,   233,   141,   176,   167,    65,   159,    15,    70,
     228,   164,   141,   184,   117,   168,   130,   168,   104,   105,
      18,    19,    20,    16,   168,   113,    16,    17,    86,   168,
     118,    18,    19,    20,   102,   187,   154,   214,   155,   175,
     227,   136,   138,   223,    87,    89,    88,   145,   232,   107,
     108,   230,   101,   201,   148,   186,    88,   103,   116,   123,
     205,   125,   126,   206,   207,   127,   208,   146,   159,   147,
     158,   189,   212,   163,   181,   215,     5,     6,   185,   177,
     178,     7,   158,   168,   188,     8,   190,     5,     6,   229,
      11,   194,     7,   195,   196,   197,     8,    12,    13,    14,
     202,    11,   203,     6,   204,   210,   216,     7,    12,    13,
      14,   217,   219,   132,   222,    15,    11,   231,   226,     7,
     142,   137,   143,    12,    13,    14,    15,   133,    11,   156,
     149,   144,   150,    16,    17,    12,    13,    14,    18,    19,
      20,    15,   153,   158,    16,    17,   180,   151,     6,    18,
      19,    20,     7,    15,   152,   209,   131,   157,   198,    67,
      17,    11,   121,   122,    18,    19,    20,     0,    12,    13,
      14,   213,    17,    23,   211,     0,    18,    19,    20,     0,
       0,    23,     0,     0,     0,    90,    15,    91,    92,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     7,     0,    17,     0,    93,    94,    18,
      19,    20,    11,   179,     7,    95,    96,    97,    98,    12,
      13,    14,     0,    11,    61,     0,     0,     0,     0,     0,
      12,    13,    14,     0,     7,     0,     0,    15,     0,     0,
       0,   157,     0,    11,     0,     0,     0,    99,    15,     0,
      12,    13,    14,     0,     0,     0,    17,     0,     0,     0,
      18,    19,    20,     0,     0,     7,     0,    17,    15,     0,
       0,    18,    19,    20,    11,     0,     0,     0,     0,     7,
       0,    12,    13,    14,     0,     0,     0,    17,    11,     0,
     134,    18,    19,    20,     0,    12,    13,    14,     0,    15,
       7,     0,     0,   157,     0,     0,     0,     0,     0,    11,
       7,     0,     0,    15,     0,     0,    12,    13,    17,    11,
       0,     0,    18,    19,    20,     0,    12,    13,     0,     0,
       0,     0,    17,     0,    15,     0,    18,    19,    20,    11,
       0,     0,     0,     0,    15,     0,    12,    13,    14,     0,
       0,     0,     0,    17,    11,   182,     0,    18,    19,    20,
       0,    12,    13,    17,    15,     0,     0,    18,    19,    20,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    15,
       0,     0,     0,    17,     0,     0,     0,    18,    19,    20,
      71,     0,     0,     0,     0,     0,     0,     0,    17,     0,
       0,     0,    18,    19,    20,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,     0,     0,    82,     0,     0,
       0,     0,     0,     0,     0,     0,    83,    84
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     8,     8,    85,   123,     7,     3,    45,    14,     3,
       4,    65,    17,   202,     8,    14,    26,    18,    12,    13,
      14,     0,    11,    17,    23,    26,   166,   167,   217,    21,
      24,    25,    26,    26,    27,   117,    46,    14,    46,   119,
      17,    34,   231,   125,   125,    46,    65,   129,    42,    32,
      46,   131,   134,   134,    17,    65,    33,    65,    44,    45,
      65,    66,    67,    60,    65,    58,    60,    61,    22,    65,
      33,    65,    66,    67,    43,   157,   114,   196,   116,    71,
     220,    70,    71,   216,     5,     9,     7,    89,   228,    24,
      25,   224,    28,   175,   100,     6,     7,    29,    46,    17,
     182,    10,    22,   185,   186,    18,   188,    10,   190,     8,
     117,    18,   194,    65,    65,   197,     3,     4,    22,   126,
     126,     8,   129,    65,    32,    12,    22,     3,     4,    16,
      17,    21,     8,    18,    22,    32,    12,    24,    25,    26,
      21,    17,    14,     4,    18,    22,    15,     8,    24,    25,
      26,    21,    14,    14,    22,    42,    17,    21,     6,     8,
      86,    71,    87,    24,    25,    26,    42,    69,    17,    18,
     101,    88,   102,    60,    61,    24,    25,    26,    65,    66,
      67,    42,   109,   190,    60,    61,   129,   103,     4,    65,
      66,    67,     8,    42,   106,   190,    67,    46,    14,    17,
      61,    17,    53,    53,    65,    66,    67,    -1,    24,    25,
      26,   196,    61,   216,   192,    -1,    65,    66,    67,    -1,
      -1,   224,    -1,    -1,    -1,     8,    42,    10,    11,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     8,    -1,    61,    -1,    30,    31,    65,
      66,    67,    17,    18,     8,    38,    39,    40,    41,    24,
      25,    26,    -1,    17,    18,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,     8,    -1,    -1,    42,    -1,    -1,
      -1,    46,    -1,    17,    -1,    -1,    -1,    70,    42,    -1,
      24,    25,    26,    -1,    -1,    -1,    61,    -1,    -1,    -1,
      65,    66,    67,    -1,    -1,     8,    -1,    61,    42,    -1,
      -1,    65,    66,    67,    17,    -1,    -1,    -1,    -1,     8,
      -1,    24,    25,    26,    -1,    -1,    -1,    61,    17,    -1,
      64,    65,    66,    67,    -1,    24,    25,    26,    -1,    42,
       8,    -1,    -1,    46,    -1,    -1,    -1,    -1,    -1,    17,
       8,    -1,    -1,    42,    -1,    -1,    24,    25,    61,    17,
      -1,    -1,    65,    66,    67,    -1,    24,    25,    -1,    -1,
      -1,    -1,    61,    -1,    42,    -1,    65,    66,    67,    17,
      -1,    -1,    -1,    -1,    42,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    61,    17,    63,    -1,    65,    66,    67,
      -1,    24,    25,    61,    42,    -1,    -1,    65,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    61,    -1,    -1,    -1,    65,    66,    67,
      32,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    61,    -1,
      -1,    -1,    65,    66,    67,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    68,    69
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    73,    74,    76,     0,     3,     4,     8,    12,    13,
      14,    17,    24,    25,    26,    42,    60,    61,    65,    66,
      67,    75,    77,    78,    79,    80,    81,    82,    83,    86,
      87,    88,    89,    93,    94,    95,    96,    97,    99,   100,
     101,   102,   104,   106,   108,   109,   110,   111,   117,   119,
     122,   125,   133,   134,   135,    65,    96,    86,    99,   123,
     124,    18,    87,   118,    99,    65,   136,   117,    14,    23,
      32,    32,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    59,    68,    69,    90,    22,     5,     7,     9,
       8,    10,    11,    30,    31,    38,    39,    40,    41,    70,
      98,    28,    43,    29,    44,    45,   103,    24,    25,   105,
      26,    27,    34,    58,   107,   108,    46,    17,    33,   112,
     113,   125,   133,    17,   126,    10,    22,    18,    14,    17,
      33,   112,    14,    79,    64,    84,    87,    84,    87,    91,
      92,    93,    88,    94,    95,    96,    10,     8,    99,   100,
     101,   102,   104,   106,   108,   108,    18,    46,    86,    93,
     114,   115,   116,    65,   113,    18,    26,    46,    65,   127,
     128,   130,   131,   132,    21,    71,    91,    86,    99,    18,
     114,    65,    63,    85,    91,    22,     6,    93,    32,    18,
      22,   129,   132,   132,    21,    18,    22,    32,    14,    78,
     121,    93,    21,    14,    18,    93,    93,    93,    93,   116,
      22,   129,    93,   128,   131,    93,    15,    21,   121,    14,
      46,   131,    22,    77,   120,   121,     6,   132,    46,    16,
      77,    21,   132,   121
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
     102,   103,   103,   104,   104,   105,   105,   106,   106,   107,
     107,   107,   107,   108,   108,   109,   109,   109,   110,   110,
     111,   111,   111,   111,   112,   112,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   116,   116,   117,   117,   117,
     117,   117,   118,   119,   119,   119,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   124,   124,   125,   125,
     126,   126,   127,   127,   127,   128,   128,   128,   128,   128,
     129,   129,   130,   130,   131,   131,   132,   132,   133,   133,
     133,   134,   134,   135,   136,   136
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
       1,     3,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     1,     3,     1,     3,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     3,
       1,     2,     2,     3,     1,     2,     2,     2,     3,     1,
       2,     1,     3,     1,     1,     3,     2,     2,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     4,
       6,     9,     1,     2,     3,     3,     1,     1,     5,     7,
       2,     3,     1,     3,     1,     3,     6,     2,     2,     5,
       0,     3,     1,     3,     1,     3,     1,     3,     3,     5,
       6,     1,     2,     2,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"def\"", "PASS", "\"if\"", "\"else\"",
  "\"or\"", "\"not\"", "\"and\"", "\"in\"", "\"is\"", "\"for\"",
  "ENDMARKER", "NEWLINE", "INDENT", "DEDENT", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\":\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "\"|\"", "\"&\"", "\"<\"", "\">\"", "\"=\"", "\".\"", "\"%\"", "\"`\"",
  "\"{\"", "\"}\"", "\"==\"", "\"!=\"", "\"<=\"", "\">=\"", "\"~\"",
  "\"^\"", "\"<<\"", "\">>\"", "\"**\"", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"",
  "\"**+\"", "\"//\"", "\"//=\"", "\"@\"", "\"await\"", "\"async\"",
  "\"from\"", "\"yield\"", "NAME", "NUMBER", "STRING", "\"@=\"", "\"**=\"",
  "\"<>\"", "\"->\"", "$accept", "module", "file_input", "newline_or_stmt",
  "newline_stmt_seq", "stmt", "simple_stmt", "small_stmt",
  "small_stmt_seq", "pass_stmt", "expr_stmt", "assign_expr_seq",
  "yield_expr", "yield_arg", "star_expr", "testlist_star_expr",
  "test_star_expr", "test_star_expr_seq", "augassign", "testlist",
  "test_seq", "test", "or_test", "and_test", "not_test", "comparison",
  "comp_op", "expr", "xor_expr", "and_expr", "shift_expr", "shift_op",
  "arith_expr", "arith_op", "term", "term_op", "factor", "factor_op",
  "power", "atom_expr", "trailer_seq", "trailer", "arglist", "arglist_seq",
  "argument", "atom", "testlist_comp", "compound_stmt", "stmt_seq",
  "suite", "for_stmt", "exprlist", "exprlist_seq", "funcdef", "parameters",
  "typedargslist", "var_args", "var_arglist_trailer", "named_args",
  "tfpdef_test", "tfpdef", "decorator", "decorators", "decorated",
  "dotted_name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   170,   170,   191,   199,   203,   212,   216,   237,   241,
     251,   255,   266,   270,   280,   284,   295,   309,   313,   317,
     335,   339,   344,   348,   375,   376,   382,   383,   393,   415,
     420,   431,   431,   436,   441,   453,   453,   453,   453,   453,
     453,   453,   453,   453,   454,   454,   454,   454,   461,   462,
     469,   470,   485,   486,   492,   493,   499,   500,   506,   507,
     514,   515,   528,   532,   536,   537,   538,   539,   540,   541,
     542,   543,   544,   551,   552,   561,   562,   571,   572,   581,
     582,   589,   589,   595,   596,   603,   603,   609,   610,   617,
     617,   617,   617,   623,   624,   628,   628,   628,   634,   635,
     644,   645,   653,   657,   666,   667,   673,   674,   680,   693,
     694,   704,   708,   729,   730,   731,   735,   769,   775,   780,
     781,   782,   802,   814,   815,   816,   823,   827,   836,   840,
     849,   853,   862,   863,   873,   879,   884,   885,   891,   895,
     904,   908,   948,   955,   962,   971,   978,   986,   992,  1000,
    1013,  1017,  1028,  1032,  1040,  1044,  1057,  1064,  1078,  1079,
    1080,  1086,  1087,  1093,  1099,  1100
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

