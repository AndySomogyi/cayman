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

      case 67: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 68: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 69: // STRING


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

      case 81: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 82: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 83: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 84: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 85: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 86: // yield_arg


        { yyoutput << (yysym.value); }

        break;

      case 87: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 88: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 89: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 90: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 91: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 92: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 93: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 94: // test


        { yyoutput << (yysym.value); }

        break;

      case 95: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 96: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 97: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 98: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 99: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 100: // expr


        { yyoutput << (yysym.value); }

        break;

      case 101: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 102: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 103: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 104: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 105: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 106: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 107: // term


        { yyoutput << (yysym.value); }

        break;

      case 108: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 109: // factor


        { yyoutput << (yysym.value); }

        break;

      case 110: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 111: // power


        { yyoutput << (yysym.value); }

        break;

      case 112: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 113: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 114: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 115: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 116: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 117: // argument


        { yyoutput << (yysym.value); }

        break;

      case 118: // atom


        { yyoutput << (yysym.value); }

        break;

      case 119: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 120: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 121: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 122: // elif_seq


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

      case 128: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 129: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 130: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 131: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 132: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 133: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 134: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 135: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 136: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 137: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 138: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 139: // dotted_name


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

  case 15:

    {
        (yylhs.value) = (yystack_[0].value); // small_stmt_seq: small_stmt
    }

    break;

  case 16:

    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value)); 
    }

    break;

  case 17:

    {
        (yylhs.value) = ctx.ast->CreateDelete(yylhs.location, (yystack_[0].value));
    }

    break;

  case 19:

    {
        (yylhs.value) = ctx.ast->CreateAugAssign(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 20:

    {
        (yylhs.value) = (yystack_[0].value);  /*foo*/
    }

    break;

  case 21:

    {
        (yylhs.value) = (yystack_[0].value); // expr_stmt: testlist_star_expr
    }

    break;

  case 22:

    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 23:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 24:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 25:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 30:

    {
        (yylhs.value) = ctx.ast->CreateStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 31:

    {
        AstNode *a1 = (yystack_[0].value);
        (yylhs.value) = (yystack_[0].value); // testlist_star_expr:  test_star_expr_seq
    }

    break;

  case 32:

    {
        AstNode *a1 = (yystack_[1].value);
        (yylhs.value) = (yystack_[1].value); // testlist_star_expr: test_star_expr_seq ","
    }

    break;

  case 35:

    {
        // test_star_expr_seq: test_star_expr
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 36:

    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 52:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 56:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 58:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 59:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 62:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 63:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 64:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
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

  case 81:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 85:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 89:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 95:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 100:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 102:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 103:

    {
        assert(0);
    }

    break;

  case 104:

    {
        assert(0);
    }

    break;

  case 106:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 107:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 108:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 109:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[1].value));
    }

    break;

  case 111:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 112:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 113:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 116:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 117:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 118:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 119:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 120:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 121:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 122:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 128:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 129:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 130:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 131:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 132:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 133:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 134:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 135:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 136:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 137:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 139:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 140:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 141:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 144:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 145:

    {
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[0].value));
    }

    break;

  case 146:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 147:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 148:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 149:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 150:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 151:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 152:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 153:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 154:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 155:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 156:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 157:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 158:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 159:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 160:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 161:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 162:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 163:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 171:

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


  const short int py_parser::yypact_ninf_ = -197;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -197,    25,  -197,    19,  -197,   -37,  -197,   354,   354,   320,
     320,  -197,  -197,   247,  -197,  -197,   381,  -197,   -18,    22,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,    11,  -197,  -197,
    -197,    20,  -197,   377,  -197,    38,  -197,    56,    75,  -197,
     207,    64,    55,    72,    26,    42,   -10,  -197,   381,  -197,
      57,    40,  -197,  -197,  -197,  -197,  -197,     9,  -197,    90,
      88,  -197,  -197,    64,    99,    95,  -197,  -197,  -197,   100,
      64,  -197,    80,    40,  -197,   135,   262,   262,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,  -197,
     354,   323,   354,   354,   354,   110,  -197,   115,  -197,  -197,
    -197,  -197,  -197,  -197,  -197,   381,   381,   381,   381,  -197,
    -197,   381,  -197,  -197,   381,  -197,  -197,  -197,  -197,   381,
    -197,   381,   232,    59,    40,  -197,  -197,  -197,   164,   -16,
     201,   354,   320,  -197,  -197,   235,    65,    40,  -197,  -197,
     334,  -197,  -197,  -197,  -197,  -197,   114,  -197,  -197,    87,
      75,  -197,  -197,  -197,    64,    55,    72,    26,    42,   -10,
    -197,  -197,  -197,   354,  -197,   106,   113,   117,  -197,  -197,
    -197,  -197,    76,    76,   119,   125,  -197,   122,  -197,   116,
     201,   354,   130,  -197,  -197,   129,  -197,    64,   132,   136,
    -197,   354,  -197,  -197,   354,   354,  -197,   354,  -197,   308,
     131,  -197,  -197,   354,  -197,   -11,   354,  -197,   137,   109,
      91,   201,  -197,   142,  -197,  -197,  -197,  -197,  -197,   -28,
     140,  -197,  -197,  -197,  -197,   201,  -197,    39,   143,   354,
     153,  -197,    76,  -197,   -27,  -197,  -197,  -197,   201,   144,
     146,  -197,    76,  -197,   201,   201,  -197,  -197,  -197
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    18,     0,     0,     0,
       0,     3,     4,     0,    96,    97,     0,    98,     0,     0,
     120,   121,   122,     7,     5,     8,    15,     0,    14,    12,
      13,    20,    34,    21,    35,    31,    33,    53,    55,    57,
      60,    61,    74,    76,    78,    80,    84,    88,     0,    94,
      99,   101,     9,   127,   126,   124,   167,     0,   125,     0,
       0,    59,   143,   142,     0,   138,    17,   118,   123,     0,
      30,   170,     0,   103,    10,     0,     0,     0,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
       0,    32,     0,     0,     0,     0,    72,    73,    65,    66,
      67,    71,    69,    68,    70,     0,     0,     0,     0,    82,
      83,     0,    86,    87,     0,    90,    91,    92,    93,     0,
      95,     0,     0,     0,   102,   105,   169,   168,     0,     0,
       0,     0,   139,   119,   164,     0,     0,   104,    11,    16,
      26,    24,    25,    22,    23,    19,    49,    51,    36,     0,
      56,    58,    63,    64,    62,    75,    77,    79,    81,    85,
      89,   100,   108,     0,   115,   114,     0,   110,   112,   107,
     106,   146,   156,     0,   162,     0,   150,   148,   158,   160,
       0,     0,     0,   134,   130,     0,   141,   140,     0,     0,
     171,     0,    27,    29,    50,     0,   117,     0,   109,   111,
     154,   156,   153,     0,   147,     0,     0,   144,     0,     0,
     128,     0,   165,     0,    28,    52,    54,   116,   113,     0,
     151,   163,   149,   159,   161,     0,   132,     0,     0,     0,
     136,   166,     0,   157,     0,   145,   135,   133,     0,     0,
       0,   155,     0,   129,     0,     0,   152,   131,   137
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -197,  -197,  -197,  -197,  -197,  -196,    -3,    98,  -197,  -197,
    -197,  -197,  -197,    93,  -197,    -5,     1,    74,  -197,  -197,
     -80,  -197,    -6,    82,    89,    -2,  -197,  -197,    -1,    77,
      73,    78,  -197,    70,  -197,    81,  -197,   -45,  -197,  -197,
    -197,   123,  -108,    52,  -197,    -9,   182,  -197,  -197,  -197,
    -197,  -197,   -12,  -197,   197,  -197,   151,  -197,  -197,     4,
      10,  -197,  -126,  -162,   157,  -197,  -197,  -197
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    23,     3,    24,   183,    26,    27,    28,
      29,    30,    31,   141,   192,    32,    33,    34,    35,    90,
     145,   146,    36,    37,    38,    39,    40,   105,    41,    42,
      43,    44,   111,    45,   114,    46,   119,    47,    48,    49,
      50,   124,   125,   166,   167,   168,    51,    69,    52,    53,
     210,   227,   184,    54,    64,    65,    55,   129,   175,   176,
     200,   177,   233,   179,    56,    57,    58,    72
  };

  const unsigned char
  py_parser::yytable_[] =
  {
      25,    60,   178,   120,    62,    62,    61,   180,    63,    63,
     201,   202,     5,   226,    68,    70,   170,   172,   115,   116,
     232,   242,     5,     6,     7,     4,   117,    74,     8,   170,
      59,   237,     9,    10,    11,    12,    75,   173,    13,   174,
     174,    13,     5,     6,     7,    14,    15,    16,     8,    71,
     118,   185,     9,    10,    76,   181,   174,   236,    13,   122,
     193,    92,    91,    17,    93,    14,    15,    16,   112,   113,
     241,    18,   109,   110,   160,   123,   161,   142,   144,   223,
     246,    18,    19,    17,   147,    94,    20,    21,    22,    20,
      21,    22,   151,   195,   106,    93,   134,   228,   229,   135,
     107,    18,    19,   108,   154,   121,    20,    21,    22,   128,
     131,   130,     5,     6,     7,   136,   165,   164,     8,   132,
     133,   152,     9,    10,   153,   147,   169,   186,    13,   165,
     164,   187,   190,   198,   147,    14,    15,    16,   194,     6,
     197,   199,   203,   174,     8,   204,   205,   209,   212,    10,
     206,   138,   211,    17,    13,   219,   213,   196,   231,   240,
     225,    14,    15,    16,   234,   148,   238,   244,   207,   245,
     143,    18,    19,   139,   149,   208,    20,    21,    22,    17,
     156,   158,   150,   155,   171,   214,   157,   189,   215,   216,
     218,   217,   172,   165,   164,   159,   137,   221,    19,   230,
     224,    73,    20,    21,    22,     6,    25,    66,   126,   222,
       8,   220,   173,   235,   127,    10,    95,   182,    96,    97,
      13,     0,     0,   239,    25,     0,   243,    14,    15,    16,
       0,   174,   247,   248,     0,     0,     0,     0,     0,    98,
      99,     8,     0,     0,     8,    17,     0,   100,   101,   102,
     103,    13,   162,     0,    13,   188,     8,     0,    14,    15,
      16,    14,    15,    16,    19,     0,    13,    67,    20,    21,
      22,     8,     0,    14,    15,    16,    17,   104,     0,    17,
     163,    13,     0,   163,     0,     0,     0,     0,    14,    15,
      16,    17,     0,     0,     0,    19,     0,     0,    19,    20,
      21,    22,    20,    21,    22,     0,    17,     0,     0,     0,
      19,     0,     0,     0,    20,    21,    22,     8,     0,     0,
       0,     0,     0,     0,     0,    19,     0,    13,   140,    20,
      21,    22,     8,     0,    14,    15,    16,     0,     0,    13,
       0,     0,    13,     8,     0,     0,    14,    15,    16,    14,
      15,    16,    17,    13,     0,     0,   163,     0,     0,     0,
      14,    15,     0,     8,    17,     0,     0,    17,     0,     0,
       0,    19,     0,    13,     0,    20,    21,    22,    17,     0,
      14,    15,     0,    19,     0,     0,    19,    20,    21,    22,
      20,    21,    22,     0,     0,     0,     0,    19,    17,   191,
      13,    20,    21,    22,     0,     0,     0,    14,    15,     0,
       0,    77,     0,     0,     0,     0,     0,    19,     0,     0,
       0,    20,    21,    22,     0,    17,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,     0,    89,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    20,    21,
      22
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,   128,    48,     9,    10,     8,    23,     9,    10,
     172,   173,     3,   209,    13,    16,   124,    28,    28,    29,
      48,    48,     3,     4,     5,     0,    36,    16,     9,   137,
      67,   227,    13,    14,    15,    16,    25,    48,    19,    67,
      67,    19,     3,     4,     5,    26,    27,    28,     9,    67,
      60,   131,    13,    14,    34,    71,    67,    18,    19,    19,
     140,     5,    24,    44,     8,    26,    27,    28,    26,    27,
     232,    62,    46,    47,   119,    35,   121,    76,    77,   205,
     242,    62,    63,    44,    90,    10,    67,    68,    69,    67,
      68,    69,    94,     6,    30,     8,    16,     6,     7,    19,
      45,    62,    63,    31,   105,    48,    67,    68,    69,    19,
      11,    23,     3,     4,     5,    35,   122,   122,     9,    24,
      20,    11,    13,    14,     9,   131,    67,   132,    19,   135,
     135,   132,    67,    20,   140,    26,    27,    28,    24,     4,
      34,    24,    23,    67,     9,    20,    24,    17,    16,    14,
      34,    16,    23,    44,    19,    24,    20,   163,    16,     6,
      23,    26,    27,    28,    24,    91,    23,    23,   180,    23,
      77,    62,    63,    75,    92,   181,    67,    68,    69,    44,
     107,   111,    93,   106,    20,   191,   108,   135,   194,   195,
     199,   197,    28,   199,   199,   114,    73,   203,    63,   211,
     206,    19,    67,    68,    69,     4,   209,    10,    57,   205,
       9,   201,    48,   225,    57,    14,     9,    16,    11,    12,
      19,    -1,    -1,   229,   227,    -1,   238,    26,    27,    28,
      -1,    67,   244,   245,    -1,    -1,    -1,    -1,    -1,    32,
      33,     9,    -1,    -1,     9,    44,    -1,    40,    41,    42,
      43,    19,    20,    -1,    19,    20,     9,    -1,    26,    27,
      28,    26,    27,    28,    63,    -1,    19,    20,    67,    68,
      69,     9,    -1,    26,    27,    28,    44,    70,    -1,    44,
      48,    19,    -1,    48,    -1,    -1,    -1,    -1,    26,    27,
      28,    44,    -1,    -1,    -1,    63,    -1,    -1,    63,    67,
      68,    69,    67,    68,    69,    -1,    44,    -1,    -1,    -1,
      63,    -1,    -1,    -1,    67,    68,    69,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    63,    -1,    19,    66,    67,
      68,    69,     9,    -1,    26,    27,    28,    -1,    -1,    19,
      -1,    -1,    19,     9,    -1,    -1,    26,    27,    28,    26,
      27,    28,    44,    19,    -1,    -1,    48,    -1,    -1,    -1,
      26,    27,    -1,     9,    44,    -1,    -1,    44,    -1,    -1,
      -1,    63,    -1,    19,    -1,    67,    68,    69,    44,    -1,
      26,    27,    -1,    63,    -1,    -1,    63,    67,    68,    69,
      67,    68,    69,    -1,    -1,    -1,    -1,    63,    44,    65,
      19,    67,    68,    69,    -1,    -1,    -1,    26,    27,    -1,
      -1,    34,    -1,    -1,    -1,    -1,    -1,    63,    -1,    -1,
      -1,    67,    68,    69,    -1,    44,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    -1,    61,    -1,
      -1,    -1,    -1,    -1,    63,    -1,    -1,    -1,    67,    68,
      69
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    73,    74,    76,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    26,    27,    28,    44,    62,    63,
      67,    68,    69,    75,    77,    78,    79,    80,    81,    82,
      83,    84,    87,    88,    89,    90,    94,    95,    96,    97,
      98,   100,   101,   102,   103,   105,   107,   109,   110,   111,
     112,   118,   120,   121,   125,   128,   136,   137,   138,    67,
      94,    97,    87,   100,   126,   127,   126,    20,    88,   119,
     100,    67,   139,   118,    16,    25,    34,    34,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    61,
      91,    24,     5,     8,    10,     9,    11,    12,    32,    33,
      40,    41,    42,    43,    70,    99,    30,    45,    31,    46,
      47,   104,    26,    27,   106,    28,    29,    36,    60,   108,
     109,    48,    19,    35,   113,   114,   128,   136,    19,   129,
      23,    11,    24,    20,    16,    19,    35,   113,    16,    79,
      66,    85,    88,    85,    88,    92,    93,    94,    89,    95,
      96,    97,    11,     9,   100,   101,   102,   103,   105,   107,
     109,   109,    20,    48,    87,    94,   115,   116,   117,    67,
     114,    20,    28,    48,    67,   130,   131,   133,   134,   135,
      23,    71,    16,    78,   124,    92,    87,   100,    20,   115,
      67,    65,    86,    92,    24,     6,    94,    34,    20,    24,
     132,   135,   135,    23,    20,    24,    34,   124,    94,    17,
     122,    23,    16,    20,    94,    94,    94,    94,   117,    24,
     132,    94,   131,   134,    94,    23,    77,   123,     6,     7,
     124,    16,    48,   134,    24,   124,    18,    77,    23,    94,
       6,   135,    48,   124,    23,    23,   135,   124,   124
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    72,    73,    74,    75,    75,    76,    76,    77,    77,
      78,    78,    79,    79,    79,    80,    80,    81,    82,    83,
      83,    83,    84,    84,    84,    84,    85,    85,    86,    86,
      87,    88,    88,    89,    89,    90,    90,    91,    91,    91,
      91,    91,    91,    91,    91,    91,    91,    91,    91,    92,
      92,    93,    93,    94,    94,    95,    95,    96,    96,    97,
      97,    98,    98,    99,    99,    99,    99,    99,    99,    99,
      99,    99,    99,    99,   100,   100,   101,   101,   102,   102,
     103,   103,   104,   104,   105,   105,   106,   106,   107,   107,
     108,   108,   108,   108,   109,   109,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   113,   113,   114,   114,   114,
     115,   115,   116,   116,   117,   117,   117,   117,   118,   118,
     118,   118,   118,   119,   120,   120,   120,   120,   121,   121,
     122,   122,   123,   123,   124,   124,   125,   125,   126,   126,
     127,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   131,   131,   131,   131,   131,   132,   132,   133,   133,
     134,   134,   135,   135,   136,   136,   136,   137,   137,   138,
     139,   139
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     1,     3,     2,     1,     3,
       1,     1,     3,     3,     3,     3,     1,     2,     2,     1,
       2,     1,     2,     1,     1,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       2,     1,     3,     1,     5,     1,     3,     1,     3,     2,
       1,     1,     3,     2,     2,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     3,     1,     3,
       1,     3,     1,     1,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     1,     1,     2,     1,     1,     1,     1,
       3,     1,     2,     2,     3,     1,     2,     2,     2,     3,
       1,     2,     1,     3,     1,     1,     3,     2,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     5,     8,
       0,     5,     1,     2,     1,     4,     6,     9,     1,     2,
       3,     3,     1,     1,     5,     7,     2,     3,     1,     3,
       1,     3,     6,     2,     2,     5,     0,     3,     1,     3,
       1,     3,     1,     3,     3,     5,     6,     1,     2,     2,
       1,     3
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "$end", "error", "$undefined", "\"def\"", "PASS", "\"if\"", "\"else\"",
  "\"elif\"", "\"or\"", "\"not\"", "\"and\"", "\"in\"", "\"is\"",
  "\"for\"", "\"del\"", "ENDMARKER", "NEWLINE", "INDENT", "DEDENT",
  "\"(\"", "\")\"", "\"[\"", "\"]\"", "\":\"", "\",\"", "\";\"", "\"+\"",
  "\"-\"", "\"*\"", "\"/\"", "\"|\"", "\"&\"", "\"<\"", "\">\"", "\"=\"",
  "\".\"", "\"%\"", "\"`\"", "\"{\"", "\"}\"", "\"==\"", "\"!=\"",
  "\"<=\"", "\">=\"", "\"~\"", "\"^\"", "\"<<\"", "\">>\"", "\"**\"",
  "\"+=\"", "\"-=\"", "\"*=\"", "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"",
  "\"^=\"", "\"<<=\"", "\">>=\"", "\"**=\"", "\"//\"", "\"//=\"", "\"@\"",
  "\"await\"", "\"async\"", "\"from\"", "\"yield\"", "NAME", "NUMBER",
  "STRING", "\"<>\"", "\"->\"", "$accept", "module", "file_input",
  "newline_or_stmt", "newline_stmt_seq", "stmt", "simple_stmt",
  "small_stmt", "small_stmt_seq", "del_stmt", "pass_stmt", "expr_stmt",
  "assign_expr_seq", "yield_expr", "yield_arg", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "shift_op", "arith_expr", "arith_op", "term", "term_op",
  "factor", "factor_op", "power", "atom_expr", "trailer_seq", "trailer",
  "arglist", "arglist_seq", "argument", "atom", "testlist_comp",
  "compound_stmt", "if_stmt", "elif_seq", "stmt_seq", "suite", "for_stmt",
  "exprlist", "exprlist_seq", "funcdef", "parameters", "typedargslist",
  "var_args", "var_arglist_trailer", "named_args", "tfpdef_test", "tfpdef",
  "decorator", "decorators", "decorated", "dotted_name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   172,   172,   196,   204,   208,   217,   221,   242,   246,
     256,   260,   271,   272,   273,   280,   284,   295,   304,   318,
     322,   326,   344,   348,   353,   357,   384,   385,   391,   392,
     402,   424,   429,   440,   440,   445,   450,   462,   462,   462,
     462,   462,   462,   462,   462,   463,   463,   463,   463,   470,
     471,   478,   479,   494,   495,   501,   502,   512,   513,   523,
     527,   534,   535,   548,   552,   556,   557,   558,   559,   560,
     561,   562,   563,   564,   571,   572,   581,   582,   591,   592,
     601,   602,   609,   609,   615,   616,   623,   623,   629,   630,
     637,   637,   637,   637,   643,   644,   651,   651,   651,   657,
     658,   667,   668,   677,   681,   690,   691,   705,   712,   718,
     731,   732,   742,   746,   767,   768,   769,   773,   807,   813,
     820,   821,   822,   842,   854,   855,   856,   857,   865,   870,
     879,   884,   909,   913,   922,   926,   935,   939,   948,   949,
     959,   965,   970,   971,   977,   981,   990,   994,  1034,  1041,
    1048,  1057,  1064,  1072,  1078,  1086,  1099,  1103,  1114,  1118,
    1126,  1130,  1143,  1150,  1164,  1165,  1166,  1172,  1173,  1179,
    1185,  1186
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

