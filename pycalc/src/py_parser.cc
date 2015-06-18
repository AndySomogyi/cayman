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

      case 14: // ENDMARKER


        { yyoutput << (yysym.value); }

        break;

      case 15: // NEWLINE


        { yyoutput << (yysym.value); }

        break;

      case 16: // INDENT


        { yyoutput << (yysym.value); }

        break;

      case 17: // DEDENT


        { yyoutput << (yysym.value); }

        break;

      case 18: // "("


        { yyoutput << (yysym.value); }

        break;

      case 19: // ")"


        { yyoutput << (yysym.value); }

        break;

      case 20: // "["


        { yyoutput << (yysym.value); }

        break;

      case 21: // "]"


        { yyoutput << (yysym.value); }

        break;

      case 22: // ":"


        { yyoutput << (yysym.value); }

        break;

      case 23: // ","


        { yyoutput << (yysym.value); }

        break;

      case 24: // ";"


        { yyoutput << (yysym.value); }

        break;

      case 25: // "+"


        { yyoutput << (yysym.value); }

        break;

      case 26: // "-"


        { yyoutput << (yysym.value); }

        break;

      case 27: // "*"


        { yyoutput << (yysym.value); }

        break;

      case 28: // "/"


        { yyoutput << (yysym.value); }

        break;

      case 29: // "|"


        { yyoutput << (yysym.value); }

        break;

      case 30: // "&"


        { yyoutput << (yysym.value); }

        break;

      case 31: // "<"


        { yyoutput << (yysym.value); }

        break;

      case 32: // ">"


        { yyoutput << (yysym.value); }

        break;

      case 33: // "="


        { yyoutput << (yysym.value); }

        break;

      case 34: // "."


        { yyoutput << (yysym.value); }

        break;

      case 35: // "%"


        { yyoutput << (yysym.value); }

        break;

      case 36: // "`"


        { yyoutput << (yysym.value); }

        break;

      case 37: // "{"


        { yyoutput << (yysym.value); }

        break;

      case 38: // "}"


        { yyoutput << (yysym.value); }

        break;

      case 39: // "=="


        { yyoutput << (yysym.value); }

        break;

      case 40: // "!="


        { yyoutput << (yysym.value); }

        break;

      case 41: // "<="


        { yyoutput << (yysym.value); }

        break;

      case 42: // ">="


        { yyoutput << (yysym.value); }

        break;

      case 43: // "~"


        { yyoutput << (yysym.value); }

        break;

      case 44: // "^"


        { yyoutput << (yysym.value); }

        break;

      case 45: // "<<"


        { yyoutput << (yysym.value); }

        break;

      case 46: // ">>"


        { yyoutput << (yysym.value); }

        break;

      case 47: // "**"


        { yyoutput << (yysym.value); }

        break;

      case 48: // "+="


        { yyoutput << (yysym.value); }

        break;

      case 49: // "-="


        { yyoutput << (yysym.value); }

        break;

      case 50: // "*="


        { yyoutput << (yysym.value); }

        break;

      case 51: // "/="


        { yyoutput << (yysym.value); }

        break;

      case 52: // "%="


        { yyoutput << (yysym.value); }

        break;

      case 53: // "&="


        { yyoutput << (yysym.value); }

        break;

      case 54: // "|="


        { yyoutput << (yysym.value); }

        break;

      case 55: // "^="


        { yyoutput << (yysym.value); }

        break;

      case 56: // "<<="


        { yyoutput << (yysym.value); }

        break;

      case 57: // ">>="


        { yyoutput << (yysym.value); }

        break;

      case 58: // "**="


        { yyoutput << (yysym.value); }

        break;

      case 59: // "//"


        { yyoutput << (yysym.value); }

        break;

      case 60: // "//="


        { yyoutput << (yysym.value); }

        break;

      case 61: // "@"


        { yyoutput << (yysym.value); }

        break;

      case 62: // "await"


        { yyoutput << (yysym.value); }

        break;

      case 63: // "async"


        { yyoutput << (yysym.value); }

        break;

      case 64: // "from"


        { yyoutput << (yysym.value); }

        break;

      case 65: // "yield"


        { yyoutput << (yysym.value); }

        break;

      case 66: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 67: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 68: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 69: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 70: // "->"


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

      case 87: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 88: // test_star_expr_seq


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

      case 102: // shift_op


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

      case 117: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 118: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 119: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 120: // elif_seq


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

      case 126: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 127: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 128: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 129: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 130: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 131: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 132: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 133: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 134: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 135: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 136: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 137: // dotted_name


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
        (yylhs.value) = ctx.ast->CreateAugAssign(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
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

  case 50:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 54:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 56:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 57:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 60:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 61:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 62:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
    }

    break;

  case 73:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 75:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 77:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 79:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 83:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 87:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 93:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 98:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 100:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 101:

    {
        assert(0);
    }

    break;

  case 102:

    {
        assert(0);
    }

    break;

  case 104:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 105:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 106:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 107:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[1].value));
    }

    break;

  case 109:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 110:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 111:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 114:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 115:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 116:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 117:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 118:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 119:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 120:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 126:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 127:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 128:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 129:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 130:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 131:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 132:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 133:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 134:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 135:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 137:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 138:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 139:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 142:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 143:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[0].value));
    }

    break;

  case 144:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 145:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 146:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 147:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 148:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 149:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 150:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 151:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 152:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 153:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 154:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 155:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 156:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 157:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 158:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 159:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 160:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 161:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 169:

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


  const short int py_parser::yypact_ninf_ = -183;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -183,    19,  -183,    25,  -183,   -39,  -183,   320,   320,    35,
    -183,  -183,   265,  -183,  -183,   346,  -183,   -35,    -9,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,    40,  -183,  -183,    15,
    -183,   368,  -183,    43,  -183,   102,    62,  -183,     5,    51,
      44,    69,    60,    86,   134,  -183,   346,  -183,    68,    -8,
    -183,  -183,  -183,  -183,  -183,     9,  -183,   105,    97,  -183,
    -183,    51,   118,   109,  -183,  -183,   117,    51,  -183,     7,
      -8,  -183,   183,   112,   112,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,  -183,  -183,  -183,  -183,  -183,   320,   317,   320,
     320,   320,   129,  -183,   135,  -183,  -183,  -183,  -183,  -183,
    -183,  -183,   346,   346,   346,   346,  -183,  -183,   346,  -183,
    -183,   346,  -183,  -183,  -183,  -183,   346,  -183,   346,   209,
      83,    -8,  -183,  -183,  -183,   101,    -1,   198,   320,    35,
    -183,  -183,   254,    84,    -8,  -183,  -183,   332,  -183,  -183,
    -183,  -183,  -183,   137,  -183,  -183,   127,    62,  -183,  -183,
    -183,    51,    44,    69,    60,    86,   134,  -183,  -183,  -183,
     320,  -183,   133,   149,   147,  -183,  -183,  -183,  -183,   107,
     107,   153,   152,  -183,   160,  -183,   143,   198,   320,   168,
    -183,  -183,   167,  -183,    51,   180,   177,  -183,   320,  -183,
    -183,   320,   320,  -183,   320,  -183,   287,   188,  -183,  -183,
     320,  -183,   -12,   320,  -183,   190,   138,   139,   198,  -183,
     199,  -183,  -183,  -183,  -183,  -183,   -34,   192,  -183,  -183,
    -183,  -183,   198,  -183,    91,   195,   320,   213,  -183,   107,
    -183,    24,  -183,  -183,  -183,   198,   200,   207,  -183,   107,
    -183,   198,   198,  -183,  -183,  -183
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    16,     0,     0,     0,
       3,     4,     0,    94,    95,     0,    96,     0,     0,   118,
     119,   120,     7,     5,     8,    14,     0,    12,    13,    18,
      32,    19,    33,    29,    31,    51,    53,    55,    58,    59,
      72,    74,    76,    78,    82,    86,     0,    92,    97,    99,
       9,   125,   124,   122,   165,     0,   123,     0,     0,    57,
     141,   140,     0,   136,   116,   121,     0,    28,   168,     0,
     101,    10,     0,     0,     0,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    45,    46,     0,    30,     0,
       0,     0,     0,    70,    71,    63,    64,    65,    69,    67,
      66,    68,     0,     0,     0,     0,    80,    81,     0,    84,
      85,     0,    88,    89,    90,    91,     0,    93,     0,     0,
       0,   100,   103,   167,   166,     0,     0,     0,     0,   137,
     117,   162,     0,     0,   102,    11,    15,    24,    22,    23,
      20,    21,    17,    47,    49,    34,     0,    54,    56,    61,
      62,    60,    73,    75,    77,    79,    83,    87,    98,   106,
       0,   113,   112,     0,   108,   110,   105,   104,   144,   154,
       0,   160,     0,   148,   146,   156,   158,     0,     0,     0,
     132,   128,     0,   139,   138,     0,     0,   169,     0,    25,
      27,    48,     0,   115,     0,   107,   109,   152,   154,   151,
       0,   145,     0,     0,   142,     0,     0,   126,     0,   163,
       0,    26,    50,    52,   114,   111,     0,   149,   161,   147,
     157,   159,     0,   130,     0,     0,     0,   134,   164,     0,
     155,     0,   143,   133,   131,     0,     0,     0,   153,     0,
     127,     0,     0,   150,   129,   135
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -183,  -183,  -183,  -183,  -183,  -182,    -3,   158,  -183,  -183,
    -183,  -183,   157,  -183,    -5,    11,   144,  -183,  -183,   -72,
    -183,    -6,   148,   150,    -2,  -183,  -183,    -4,   130,   140,
     141,  -183,   131,  -183,   132,  -183,   -43,  -183,  -183,  -183,
     172,  -101,   106,  -183,    52,   229,  -183,  -183,  -183,  -183,
    -183,  -159,  -183,  -183,  -183,   202,  -183,  -183,    53,    55,
    -183,  -123,  -162,   203,  -183,  -183,  -183
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    22,     3,    23,   180,    25,    26,    27,
      28,    29,   138,   189,    30,    31,    32,    33,    87,   142,
     143,    34,    35,    36,    37,    38,   102,    39,    40,    41,
      42,   108,    43,   111,    44,   116,    45,    46,    47,    48,
     121,   122,   163,   164,   165,    49,    66,    50,    51,   207,
     224,   181,    52,    62,    63,    53,   126,   172,   173,   197,
     174,   230,   176,    54,    55,    56,    69
  };

  const unsigned char
  py_parser::yytable_[] =
  {
      24,    58,   175,   117,    60,    61,    59,   198,   199,    12,
     119,    67,     5,   229,    92,   169,    93,    94,   204,     4,
     167,   177,   131,    65,   223,   132,   120,    57,     5,     6,
       7,    68,   171,   167,     8,   170,    95,    96,     9,    10,
      11,   133,   234,    12,    97,    98,    99,   100,    73,   227,
      13,    14,    15,    12,   171,    71,   182,    19,    20,    21,
      13,    14,    15,   232,    72,   190,    88,   238,    16,   178,
      17,   239,    91,   157,   101,   158,   240,   243,    16,   220,
     103,   144,   244,   245,   139,   141,    17,    18,   104,   148,
     171,    19,    20,    21,     5,     6,     7,    18,   151,   105,
       8,    19,    20,    21,     9,   106,   107,    89,   233,    12,
      90,   109,   110,   162,   161,   118,    13,    14,    15,   127,
     168,     8,   144,   125,   183,   184,   162,   161,   169,   128,
      12,   144,   129,   192,    16,    90,   130,    13,    14,    15,
     149,     5,     6,     7,   150,   225,   226,     8,   170,   166,
     187,     9,    17,    18,   193,    16,    12,    19,    20,    21,
     191,   112,   113,    13,    14,    15,   194,   171,   195,   114,
     196,   201,   205,   171,    18,   200,   203,   137,    19,    20,
      21,    16,   211,   202,   206,   212,   213,     6,   214,   208,
     162,   161,     8,   115,   218,   209,   210,   221,   135,    17,
      18,    12,     6,    24,    19,    20,    21,     8,    13,    14,
      15,   216,   222,   179,   228,   231,    12,   235,     8,   237,
     236,    24,   241,    13,    14,    15,    16,    12,   159,   242,
     136,   140,   145,   152,    13,    14,    15,   146,   186,   155,
     147,    16,   134,   156,   153,    18,   154,    70,   215,    19,
      20,    21,    16,   217,     0,   219,   160,   123,   124,     0,
      18,     0,     0,     8,    19,    20,    21,     0,     0,     0,
       0,    18,    12,   185,     8,    19,    20,    21,     0,    13,
      14,    15,     0,    12,    64,     0,     0,     0,     0,     0,
      13,    14,    15,     0,     0,     0,     8,    16,     0,     0,
       0,   160,     0,     0,     0,    12,     0,     0,    16,     0,
       0,     0,    13,    14,    15,     0,    18,     0,     0,     0,
      19,    20,    21,     0,     0,     0,     8,    18,     0,     8,
      16,    19,    20,    21,   160,    12,     0,     0,    12,     0,
       0,     8,    13,    14,    15,    13,    14,     0,     0,    18,
      12,     0,     0,    19,    20,    21,     0,    13,    14,     0,
      16,     0,     0,    16,    12,     0,     0,     0,     0,     0,
       0,    13,    14,     0,     0,    16,     0,     0,     0,    18,
       0,     0,    18,    19,    20,    21,    19,    20,    21,    16,
       0,     0,     0,     0,    18,     0,   188,     0,    19,    20,
      21,    74,     0,     0,     0,     0,     0,     0,    18,     0,
       0,     0,    19,    20,    21,     0,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,     0,    86
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,   125,    46,     9,     9,     8,   169,   170,    18,
      18,    15,     3,    47,     9,    27,    11,    12,   177,     0,
     121,    22,    15,    12,   206,    18,    34,    66,     3,     4,
       5,    66,    66,   134,     9,    47,    31,    32,    13,    14,
      15,    34,   224,    18,    39,    40,    41,    42,    33,   208,
      25,    26,    27,    18,    66,    15,   128,    66,    67,    68,
      25,    26,    27,   222,    24,   137,    23,   229,    43,    70,
      61,    47,    10,   116,    69,   118,   235,   239,    43,   202,
      29,    87,   241,   242,    73,    74,    61,    62,    44,    91,
      66,    66,    67,    68,     3,     4,     5,    62,   102,    30,
       9,    66,    67,    68,    13,    45,    46,     5,    17,    18,
       8,    25,    26,   119,   119,    47,    25,    26,    27,    22,
      19,     9,   128,    18,   129,   129,   132,   132,    27,    11,
      18,   137,    23,     6,    43,     8,    19,    25,    26,    27,
      11,     3,     4,     5,     9,     6,     7,     9,    47,    66,
      66,    13,    61,    62,   160,    43,    18,    66,    67,    68,
      23,    27,    28,    25,    26,    27,    33,    66,    19,    35,
      23,    19,   178,    66,    62,    22,    33,    65,    66,    67,
      68,    43,   188,    23,    16,   191,   192,     4,   194,    22,
     196,   196,     9,    59,   200,    15,    19,   203,    15,    61,
      62,    18,     4,   206,    66,    67,    68,     9,    25,    26,
      27,    23,    22,    15,    15,    23,    18,    22,     9,     6,
     226,   224,    22,    25,    26,    27,    43,    18,    19,    22,
      72,    74,    88,   103,    25,    26,    27,    89,   132,   108,
      90,    43,    70,   111,   104,    62,   105,    18,   196,    66,
      67,    68,    43,   198,    -1,   202,    47,    55,    55,    -1,
      62,    -1,    -1,     9,    66,    67,    68,    -1,    -1,    -1,
      -1,    62,    18,    19,     9,    66,    67,    68,    -1,    25,
      26,    27,    -1,    18,    19,    -1,    -1,    -1,    -1,    -1,
      25,    26,    27,    -1,    -1,    -1,     9,    43,    -1,    -1,
      -1,    47,    -1,    -1,    -1,    18,    -1,    -1,    43,    -1,
      -1,    -1,    25,    26,    27,    -1,    62,    -1,    -1,    -1,
      66,    67,    68,    -1,    -1,    -1,     9,    62,    -1,     9,
      43,    66,    67,    68,    47,    18,    -1,    -1,    18,    -1,
      -1,     9,    25,    26,    27,    25,    26,    -1,    -1,    62,
      18,    -1,    -1,    66,    67,    68,    -1,    25,    26,    -1,
      43,    -1,    -1,    43,    18,    -1,    -1,    -1,    -1,    -1,
      -1,    25,    26,    -1,    -1,    43,    -1,    -1,    -1,    62,
      -1,    -1,    62,    66,    67,    68,    66,    67,    68,    43,
      -1,    -1,    -1,    -1,    62,    -1,    64,    -1,    66,    67,
      68,    33,    -1,    -1,    -1,    -1,    -1,    -1,    62,    -1,
      -1,    -1,    66,    67,    68,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    -1,    60
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    72,    73,    75,     0,     3,     4,     5,     9,    13,
      14,    15,    18,    25,    26,    27,    43,    61,    62,    66,
      67,    68,    74,    76,    77,    78,    79,    80,    81,    82,
      85,    86,    87,    88,    92,    93,    94,    95,    96,    98,
      99,   100,   101,   103,   105,   107,   108,   109,   110,   116,
     118,   119,   123,   126,   134,   135,   136,    66,    92,    95,
      85,    98,   124,   125,    19,    86,   117,    98,    66,   137,
     116,    15,    24,    33,    33,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    60,    89,    23,     5,
       8,    10,     9,    11,    12,    31,    32,    39,    40,    41,
      42,    69,    97,    29,    44,    30,    45,    46,   102,    25,
      26,   104,    27,    28,    35,    59,   106,   107,    47,    18,
      34,   111,   112,   126,   134,    18,   127,    22,    11,    23,
      19,    15,    18,    34,   111,    15,    78,    65,    83,    86,
      83,    86,    90,    91,    92,    87,    93,    94,    95,    11,
       9,    98,    99,   100,   101,   103,   105,   107,   107,    19,
      47,    85,    92,   113,   114,   115,    66,   112,    19,    27,
      47,    66,   128,   129,   131,   132,   133,    22,    70,    15,
      77,   122,    90,    85,    98,    19,   113,    66,    64,    84,
      90,    23,     6,    92,    33,    19,    23,   130,   133,   133,
      22,    19,    23,    33,   122,    92,    16,   120,    22,    15,
      19,    92,    92,    92,    92,   115,    23,   130,    92,   129,
     132,    92,    22,    76,   121,     6,     7,   122,    15,    47,
     132,    23,   122,    17,    76,    22,    92,     6,   133,    47,
     122,    22,    22,   133,   122,   122
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    71,    72,    73,    74,    74,    75,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    80,    81,    81,    81,
      82,    82,    82,    82,    83,    83,    84,    84,    85,    86,
      86,    87,    87,    88,    88,    89,    89,    89,    89,    89,
      89,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    92,    92,    93,    93,    94,    94,    95,    95,    96,
      96,    97,    97,    97,    97,    97,    97,    97,    97,    97,
      97,    97,    98,    98,    99,    99,   100,   100,   101,   101,
     102,   102,   103,   103,   104,   104,   105,   105,   106,   106,
     106,   106,   107,   107,   108,   108,   108,   109,   109,   110,
     110,   110,   110,   111,   111,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   115,   115,   116,   116,   116,   116,
     116,   117,   118,   118,   118,   118,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     125,   125,   126,   126,   127,   127,   128,   128,   128,   129,
     129,   129,   129,   129,   130,   130,   131,   131,   132,   132,
     133,   133,   134,   134,   134,   135,   135,   136,   137,   137
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     3,     1,     3,     1,     1,
       3,     3,     3,     3,     1,     2,     2,     1,     2,     1,
       2,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     1,
       3,     1,     5,     1,     3,     1,     3,     2,     1,     1,
       3,     2,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     1,     3,     1,     3,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     3,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     3,     1,
       2,     2,     3,     1,     2,     2,     2,     3,     1,     2,
       1,     3,     1,     1,     3,     2,     2,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     5,     8,     0,     5,
       1,     2,     1,     4,     6,     9,     1,     2,     3,     3,
       1,     1,     5,     7,     2,     3,     1,     3,     1,     3,
       6,     2,     2,     5,     0,     3,     1,     3,     1,     3,
       1,     3,     3,     5,     6,     1,     2,     2,     1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"def\"", "PASS", "\"if\"", "\"else\"",
  "\"elif\"", "\"or\"", "\"not\"", "\"and\"", "\"in\"", "\"is\"",
  "\"for\"", "ENDMARKER", "NEWLINE", "INDENT", "DEDENT", "\"(\"", "\")\"",
  "\"[\"", "\"]\"", "\":\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"",
  "\"/\"", "\"|\"", "\"&\"", "\"<\"", "\">\"", "\"=\"", "\".\"", "\"%\"",
  "\"`\"", "\"{\"", "\"}\"", "\"==\"", "\"!=\"", "\"<=\"", "\">=\"",
  "\"~\"", "\"^\"", "\"<<\"", "\">>\"", "\"**\"", "\"+=\"", "\"-=\"",
  "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"",
  "\">>=\"", "\"**=\"", "\"//\"", "\"//=\"", "\"@\"", "\"await\"",
  "\"async\"", "\"from\"", "\"yield\"", "NAME", "NUMBER", "STRING",
  "\"<>\"", "\"->\"", "$accept", "module", "file_input", "newline_or_stmt",
  "newline_stmt_seq", "stmt", "simple_stmt", "small_stmt",
  "small_stmt_seq", "pass_stmt", "expr_stmt", "assign_expr_seq",
  "yield_expr", "yield_arg", "star_expr", "testlist_star_expr",
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
       0,   171,   171,   195,   203,   207,   216,   220,   241,   245,
     255,   259,   270,   274,   284,   288,   299,   313,   317,   321,
     339,   343,   348,   352,   379,   380,   386,   387,   397,   419,
     424,   435,   435,   440,   445,   457,   457,   457,   457,   457,
     457,   457,   457,   458,   458,   458,   458,   465,   466,   473,
     474,   489,   490,   496,   497,   507,   508,   518,   522,   529,
     530,   543,   547,   551,   552,   553,   554,   555,   556,   557,
     558,   559,   566,   567,   576,   577,   586,   587,   596,   597,
     604,   604,   610,   611,   618,   618,   624,   625,   632,   632,
     632,   632,   638,   639,   646,   646,   646,   652,   653,   662,
     663,   672,   676,   685,   686,   700,   707,   713,   726,   727,
     737,   741,   762,   763,   764,   768,   802,   808,   815,   816,
     817,   837,   849,   850,   851,   852,   860,   865,   874,   879,
     904,   908,   917,   921,   930,   934,   943,   944,   954,   960,
     965,   966,   972,   976,   985,   989,  1029,  1036,  1043,  1052,
    1059,  1067,  1073,  1081,  1094,  1098,  1109,  1113,  1121,  1125,
    1138,  1145,  1159,  1160,  1161,  1167,  1168,  1174,  1180,  1181
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

