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

      case 76: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 77: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 78: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 79: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 81: // module


        { yyoutput << (yysym.value); }

        break;

      case 82: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 83: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 84: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 85: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 86: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 87: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 88: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 89: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 90: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 91: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 92: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 93: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 94: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 95: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 96: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 97: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 98: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 99: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 100: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 101: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 102: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 103: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 104: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 105: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 106: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 107: // test


        { yyoutput << (yysym.value); }

        break;

      case 108: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 109: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 110: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 111: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 112: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 113: // expr


        { yyoutput << (yysym.value); }

        break;

      case 114: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 115: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 116: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 117: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 118: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 119: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 120: // term


        { yyoutput << (yysym.value); }

        break;

      case 121: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 122: // factor


        { yyoutput << (yysym.value); }

        break;

      case 123: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 124: // power


        { yyoutput << (yysym.value); }

        break;

      case 125: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 126: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 127: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 128: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 129: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 130: // argument


        { yyoutput << (yysym.value); }

        break;

      case 131: // atom


        { yyoutput << (yysym.value); }

        break;

      case 132: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 133: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 134: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 135: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 136: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 137: // suite


        { yyoutput << (yysym.value); }

        break;

      case 138: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 139: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 140: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 141: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 142: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 143: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 144: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 145: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 146: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 147: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 148: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 149: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 150: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 151: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 152: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 153: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 154: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 155: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 156: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 157: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 158: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 159: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 160: // dotted_name


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

  case 22:

    {
        (yylhs.value) = ctx.ast->CreateBreak(yylhs.location);
    }

    break;

  case 23:

    {
        (yylhs.value) = ctx.ast->CreateContinue(yylhs.location);
    }

    break;

  case 24:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location);
    }

    break;

  case 25:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location, (yystack_[0].value));
    }

    break;

  case 26:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location);
    }

    break;

  case 27:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[0].value));
    }

    break;

  case 28:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 30:

    {
        (yylhs.value) = (yystack_[0].value); // small_stmt_seq: small_stmt
    }

    break;

  case 31:

    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value)); 
    }

    break;

  case 32:

    {
        (yylhs.value) = ctx.ast->CreateDelete(yylhs.location, (yystack_[0].value));
    }

    break;

  case 33:

    {
        (yylhs.value) = ctx.ast->CreatePass(yylhs.location);
    }

    break;

  case 34:

    {
        (yylhs.value) = ctx.ast->CreateAugAssign(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 35:

    {
        (yylhs.value) = (yystack_[0].value);  /*foo*/
    }

    break;

  case 36:

    {
        (yylhs.value) = (yystack_[0].value); // expr_stmt: testlist_star_expr
    }

    break;

  case 37:

    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 38:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 39:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 40:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 41:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location);
    }

    break;

  case 42:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location, (yystack_[0].value));
    }

    break;

  case 43:

    {
        (yylhs.value) = ctx.ast->CreateYieldFrom(yylhs.location, (yystack_[0].value));
    }

    break;

  case 44:

    {
        (yylhs.value) = ctx.ast->CreateStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 45:

    {
        AstNode *a1 = (yystack_[0].value);
        (yylhs.value) = (yystack_[0].value); // testlist_star_expr:  test_star_expr_seq
    }

    break;

  case 46:

    {
        AstNode *a1 = (yystack_[1].value);
        (yylhs.value) = (yystack_[1].value); // testlist_star_expr: test_star_expr_seq ","
    }

    break;

  case 49:

    {
        // test_star_expr_seq: test_star_expr
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 50:

    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 66:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 70:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 72:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 73:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 76:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 77:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 78:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
    }

    break;

  case 89:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 91:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 93:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 95:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 99:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 103:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 109:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 114:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 116:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 117:

    {
        assert(0);
    }

    break;

  case 118:

    {
        assert(0);
    }

    break;

  case 120:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 121:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 122:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 123:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[1].value));
    }

    break;

  case 125:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 126:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 127:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 130:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 131:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 132:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 133:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 134:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 135:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 136:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 142:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 143:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 144:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 145:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 146:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 147:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 148:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 149:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 150:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 151:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 153:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 154:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 155:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 158:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 159:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 160:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 161:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 162:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 163:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 164:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 165:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 166:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 167:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 168:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 169:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 170:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 171:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 173:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 174:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 175:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 176:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 177:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 186:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 187:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 188:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 189:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 190:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 191:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 192:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 193:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 194:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 195:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 196:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 197:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 198:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 199:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 202:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 203:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 204:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 205:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
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

  case 213:

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


  const short int py_parser::yypact_ninf_ = -224;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
    -224,    50,  -224,   188,  -224,    17,  -224,   300,   300,   502,
     502,  -224,  -224,   446,  -224,  -224,   508,  -224,    21,     3,
      -4,    21,   106,  -224,  -224,   300,   300,  -224,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
      52,  -224,  -224,  -224,    41,  -224,  -224,   172,  -224,    89,
    -224,    38,   111,  -224,    12,    37,    78,   110,    57,    85,
      42,  -224,   508,  -224,    94,    22,  -224,  -224,  -224,  -224,
    -224,    11,  -224,  -224,  -224,  -224,   126,   120,  -224,  -224,
      37,   138,   127,  -224,  -224,  -224,   132,    37,  -224,   119,
      22,  -224,  -224,    60,     4,  -224,   129,    -9,   300,  -224,
     134,  -224,    88,  -224,  -224,   355,   467,   467,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,
     300,   487,   300,   300,   300,   151,  -224,   155,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,   508,   508,   508,   508,  -224,
    -224,   508,  -224,  -224,   508,  -224,  -224,  -224,  -224,   508,
    -224,   508,   100,    91,    22,  -224,  -224,  -224,    10,    24,
     375,   300,   502,  -224,  -224,   441,    92,    22,  -224,  -224,
       6,     5,     8,    21,    93,  -224,   300,   300,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,    43,   111,  -224,  -224,
    -224,    37,    78,   110,    57,    85,    42,  -224,  -224,  -224,
     300,  -224,   131,   153,   156,  -224,  -224,  -224,  -224,    99,
      99,   158,   159,  -224,   161,  -224,   152,   375,   300,   170,
    -224,  -224,   165,  -224,    37,   173,   175,  -224,   114,  -224,
     121,  -224,   174,     9,   114,  -224,  -224,    13,  -224,  -224,
    -224,   300,  -224,   300,  -224,   472,   176,  -224,  -224,   300,
    -224,    14,   300,  -224,   182,   284,   124,   375,  -224,   183,
     189,   135,   137,   114,  -224,  -224,   190,   141,  -224,  -224,
    -224,   -15,   184,  -224,  -224,  -224,  -224,   375,  -224,   264,
     195,   300,   213,  -224,  -224,  -224,   145,   214,  -224,  -224,
      99,  -224,   -13,  -224,  -224,  -224,   375,   215,   218,   160,
    -224,  -224,    99,  -224,   375,   375,  -224,  -224,  -224,  -224
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    33,     0,     0,     0,
       0,     3,     4,     0,   110,   111,     0,   112,     0,     0,
       0,     0,    41,    22,    23,    26,    24,   134,   135,   136,
       7,     5,     8,    30,    15,    17,    18,    19,    20,    21,
       0,    13,    14,    12,    35,    29,    48,    36,    49,    45,
      47,    67,    69,    71,    74,    75,    88,    90,    92,    94,
      98,   102,     0,   108,   113,   115,     9,   141,   140,   138,
     181,     0,   139,    16,   184,   185,     0,     0,    73,   157,
     156,     0,   152,    32,   132,   137,     0,    44,   212,     0,
     117,   196,   197,     0,     0,   186,   200,   202,     0,    42,
      63,    65,    27,    25,    10,     0,     0,     0,    51,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
       0,    46,     0,     0,     0,     0,    86,    87,    79,    80,
      81,    85,    83,    82,    84,     0,     0,     0,     0,    96,
      97,     0,   100,   101,     0,   104,   105,   106,   107,     0,
     109,     0,     0,     0,   116,   119,   183,   182,     0,     0,
       0,     0,   153,   133,   178,     0,     0,   118,   198,   199,
       0,     0,     0,   201,     0,    43,    64,     0,    11,    31,
      39,    40,    37,    38,    34,    50,     0,    70,    72,    77,
      78,    76,    89,    91,    93,    95,    99,   103,   114,   122,
       0,   129,   128,     0,   124,   126,   121,   120,   160,   170,
       0,   176,     0,   164,   162,   172,   174,     0,     0,     0,
     148,   144,     0,   155,   154,     0,     0,   213,     0,   193,
     208,   195,   206,     0,     0,   187,   189,   204,   203,    66,
      28,     0,   131,     0,   123,   125,   168,   170,   167,     0,
     161,     0,     0,   158,     0,     0,   142,     0,   179,     0,
       0,     0,   207,     0,   190,   192,     0,     0,    68,   130,
     127,     0,   165,   177,   163,   173,   175,     0,   146,     0,
       0,     0,   150,   180,   194,   209,   210,     0,   188,   205,
       0,   171,     0,   159,   149,   147,     0,     0,     0,     0,
     191,   169,     0,   143,     0,     0,   211,   166,   145,   151
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -224,  -224,  -224,  -224,  -224,  -223,    -3,   139,  -224,  -224,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,    33,
      -5,     0,   128,  -224,  -224,   -24,  -224,    -6,   123,   125,
      -2,  -224,  -224,    -1,   115,   105,   109,  -224,   122,  -224,
     130,  -224,   -50,  -224,  -224,  -224,   180,   -49,    90,  -224,
      26,   231,  -224,  -224,  -224,  -224,  -224,  -188,  -224,   262,
    -224,   208,  -224,  -224,    29,    34,  -224,  -151,  -192,   223,
    -224,  -224,  -224,  -224,  -224,  -224,  -224,  -224,  -169,  -224,
     -10
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    30,     3,    31,   220,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    44,    45,
      46,    47,    48,    49,   120,    99,   100,    50,    51,    52,
      53,    54,   135,    55,    56,    57,    58,   141,    59,   144,
      60,   149,    61,    62,    63,    64,   154,   155,   203,   204,
     205,    65,    86,    66,    67,   256,   279,   221,    68,    81,
      82,    69,   159,   212,   213,   246,   214,   291,   216,    70,
      71,    72,    73,    74,    75,    93,    95,    96,   231,   232,
      89
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      32,    77,   103,   236,    79,    79,    78,   215,    80,    80,
      94,    97,   150,    85,     5,    87,   101,   247,   248,   102,
     101,   125,    13,   126,   127,   228,   166,   234,   263,   253,
     208,    91,   278,   290,   229,   302,   235,   264,   209,   166,
     166,   152,   209,   122,   128,   129,   123,   217,   166,   241,
       4,   123,   130,   131,   132,   133,   295,   153,   210,   260,
      92,   211,   210,   211,   265,   266,   174,   136,   104,   282,
     145,   146,    88,   172,   233,   106,    18,   105,   147,    27,
      28,    29,   230,   171,   230,   230,   211,   218,   267,   293,
     211,   134,   175,    76,   287,   168,   184,    88,   301,   197,
     275,   198,   148,   139,   140,   207,   181,   183,   303,     8,
     307,   142,   143,   121,   101,     8,   308,   309,   207,    13,
     199,   124,   188,   137,   169,    13,    14,    15,    16,   170,
     280,   281,    14,    15,   191,   164,    88,   222,   165,   180,
     182,   138,   151,   160,    17,   158,   202,   201,   200,   161,
      17,   162,   163,   173,   166,   101,   177,   223,   176,   202,
     201,   224,   189,   237,   190,   243,    19,   206,   227,   238,
     239,   240,    19,   244,    98,   211,    27,    28,    29,   250,
     245,   249,    27,    28,    29,   251,   252,   255,   257,   258,
     230,     5,     6,     7,   242,   259,   261,     8,   262,   283,
     271,     9,    10,    11,    12,   277,   107,    13,   292,   284,
     288,   285,   254,   286,    14,    15,    16,   289,   296,   298,
     299,   108,   109,   110,   111,   112,   113,   114,   115,   116,
     117,   118,    17,   119,   300,   268,   306,   269,   304,   202,
     201,   305,   193,   273,   179,   186,   276,   194,   187,   185,
      90,   192,    32,    18,    19,   226,    20,    21,    22,    23,
      24,    25,    26,   195,    27,    28,    29,     5,     6,     7,
     167,   270,    83,     8,   196,   297,    32,     9,    10,   156,
     274,   272,   294,    13,     0,     0,     0,     5,     6,     7,
      14,    15,    16,     8,   157,     0,     0,     9,    10,     0,
       0,     0,     0,    13,     0,     0,     0,     0,    17,     8,
      14,    15,    16,     0,     0,     0,     0,     0,     0,    13,
       0,     0,     0,     0,     0,     0,    14,    15,    17,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,     0,
      27,    28,    29,     0,    17,     0,     0,     0,     0,    18,
      19,     0,    20,    21,    22,    23,    24,    25,    26,     6,
      27,    28,    29,     0,     8,     0,    19,     0,     0,    10,
       0,   178,     0,     0,    13,     0,    27,    28,    29,     6,
       0,    14,    15,    16,     8,     0,     0,     0,     0,    10,
       0,   219,     0,     0,    13,     0,     0,     0,     0,    17,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
       0,    19,     0,    20,    21,    22,    23,    24,    25,    26,
       0,    27,    28,    29,     0,     0,     0,     0,     0,     0,
       0,    19,     0,    20,    21,    22,    23,    24,    25,    26,
       8,    27,    28,    29,     0,     8,     0,     0,     0,     0,
      13,   225,     0,     0,     0,    13,    84,    14,    15,    16,
       0,     0,    14,    15,    16,     0,     8,     0,     0,     0,
       0,     8,     0,     0,     0,    17,    13,     0,     0,   200,
      17,    13,     0,    14,    15,    16,     8,     0,    14,    15,
      16,     0,     0,     0,     0,     0,    13,    19,     0,     0,
       0,    17,    19,    14,    15,    16,    17,    27,    28,    29,
     200,    13,    27,    28,    29,     0,     0,    13,    14,    15,
      16,    17,     0,    19,    14,    15,     0,    22,    19,     0,
       0,     0,     0,    27,    28,    29,    17,     0,    27,    28,
      29,     0,    17,    19,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27,    28,    29,     0,     0,    19,     0,
       0,     0,     0,     0,    19,     0,     0,     0,    27,    28,
      29,     0,     0,     0,    27,    28,    29
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,    26,   172,     9,    10,     8,   158,     9,    10,
      20,    21,    62,    13,     3,    16,    22,   209,   210,    25,
      26,     9,    19,    11,    12,    19,    35,    19,    19,   217,
      20,    35,   255,    48,    28,    48,    28,    28,    28,    35,
      35,    19,    28,     5,    32,    33,     8,    23,    35,     6,
       0,     8,    40,    41,    42,    43,   279,    35,    48,   228,
      64,    76,    48,    76,   233,   234,    75,    30,    16,   257,
      28,    29,    76,    69,    69,    34,    65,    25,    36,    76,
      77,    78,    76,    93,    76,    76,    76,    63,    75,   277,
      76,    79,    98,    76,   263,    35,   120,    76,   290,   149,
     251,   151,    60,    46,    47,   154,   106,   107,   296,     9,
     302,    26,    27,    24,   120,     9,   304,   305,   167,    19,
      20,    10,   124,    45,    64,    19,    26,    27,    28,    69,
       6,     7,    26,    27,   135,    16,    76,   161,    19,   106,
     107,    31,    48,    23,    44,    19,   152,   152,    48,    11,
      44,    24,    20,    24,    35,   161,    68,   162,    24,   165,
     165,   162,    11,   173,     9,    34,    66,    76,    76,    76,
     176,   177,    66,    20,    68,    76,    76,    77,    78,    20,
      24,    23,    76,    77,    78,    24,    34,    17,    23,    16,
      76,     3,     4,     5,   200,    20,    75,     9,    24,    16,
      24,    13,    14,    15,    16,    23,    34,    19,    24,    20,
      20,    76,   218,    76,    26,    27,    28,    76,    23,     6,
      75,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    44,    61,    20,   241,    76,   243,    23,   245,
     245,    23,   137,   249,   105,   122,   252,   138,   123,   121,
      19,   136,   255,    65,    66,   165,    68,    69,    70,    71,
      72,    73,    74,   141,    76,    77,    78,     3,     4,     5,
      90,   245,    10,     9,   144,   281,   279,    13,    14,    71,
     251,   247,    18,    19,    -1,    -1,    -1,     3,     4,     5,
      26,    27,    28,     9,    71,    -1,    -1,    13,    14,    -1,
      -1,    -1,    -1,    19,    -1,    -1,    -1,    -1,    44,     9,
      26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    44,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,    -1,
      76,    77,    78,    -1,    44,    -1,    -1,    -1,    -1,    65,
      66,    -1,    68,    69,    70,    71,    72,    73,    74,     4,
      76,    77,    78,    -1,     9,    -1,    66,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    76,    77,    78,     4,
      -1,    26,    27,    28,     9,    -1,    -1,    -1,    -1,    14,
      -1,    16,    -1,    -1,    19,    -1,    -1,    -1,    -1,    44,
      -1,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    44,
      -1,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
      -1,    76,    77,    78,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    -1,    68,    69,    70,    71,    72,    73,    74,
       9,    76,    77,    78,    -1,     9,    -1,    -1,    -1,    -1,
      19,    20,    -1,    -1,    -1,    19,    20,    26,    27,    28,
      -1,    -1,    26,    27,    28,    -1,     9,    -1,    -1,    -1,
      -1,     9,    -1,    -1,    -1,    44,    19,    -1,    -1,    48,
      44,    19,    -1,    26,    27,    28,     9,    -1,    26,    27,
      28,    -1,    -1,    -1,    -1,    -1,    19,    66,    -1,    -1,
      -1,    44,    66,    26,    27,    28,    44,    76,    77,    78,
      48,    19,    76,    77,    78,    -1,    -1,    19,    26,    27,
      28,    44,    -1,    66,    26,    27,    -1,    70,    66,    -1,
      -1,    -1,    -1,    76,    77,    78,    44,    -1,    76,    77,
      78,    -1,    44,    66,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    76,    77,    78,    -1,    -1,    66,    -1,
      -1,    -1,    -1,    -1,    66,    -1,    -1,    -1,    76,    77,
      78,    -1,    -1,    -1,    76,    77,    78
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    81,    82,    84,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    26,    27,    28,    44,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    76,    77,    78,
      83,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     107,   108,   109,   110,   111,   113,   114,   115,   116,   118,
     120,   122,   123,   124,   125,   131,   133,   134,   138,   141,
     149,   150,   151,   152,   153,   154,    76,   107,   110,   100,
     113,   139,   140,   139,    20,   101,   132,   113,    76,   160,
     131,    35,    64,   155,   160,   156,   157,   160,    68,   105,
     106,   107,   107,   105,    16,    25,    34,    34,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    61,
     104,    24,     5,     8,    10,     9,    11,    12,    32,    33,
      40,    41,    42,    43,    79,   112,    30,    45,    31,    46,
      47,   117,    26,    27,   119,    28,    29,    36,    60,   121,
     122,    48,    19,    35,   126,   127,   141,   149,    19,   142,
      23,    11,    24,    20,    16,    19,    35,   126,    35,    64,
      69,   160,    69,    24,    75,   107,    24,    68,    16,    87,
      99,   101,    99,   101,   105,   102,   108,   109,   110,    11,
       9,   113,   114,   115,   116,   118,   120,   122,   122,    20,
      48,   100,   107,   128,   129,   130,    76,   127,    20,    28,
      48,    76,   143,   144,   146,   147,   148,    23,    63,    16,
      86,   137,   105,   100,   113,    20,   128,    76,    19,    28,
      76,   158,   159,    69,    19,    28,   158,   160,    76,   107,
     107,     6,   107,    34,    20,    24,   145,   148,   148,    23,
      20,    24,    34,   137,   107,    17,   135,    23,    16,    20,
     158,    75,    24,    19,    28,   158,   158,    75,   107,   107,
     130,    24,   145,   107,   144,   147,   107,    23,    85,   136,
       6,     7,   137,    16,    20,    76,    76,   158,    20,    76,
      48,   147,    24,   137,    18,    85,    23,   107,     6,    75,
      20,   148,    48,   137,    23,    23,    76,   148,   137,   137
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    80,    81,    82,    83,    83,    84,    84,    85,    85,
      86,    86,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    88,    89,    90,    91,    91,    92,    92,    92,    93,
      94,    94,    95,    96,    97,    97,    97,    98,    98,    98,
      98,    99,    99,    99,   100,   101,   101,   102,   102,   103,
     103,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   105,   105,   106,   106,   107,   107,   108,
     108,   109,   109,   110,   110,   111,   111,   112,   112,   112,
     112,   112,   112,   112,   112,   112,   112,   112,   113,   113,
     114,   114,   115,   115,   116,   116,   117,   117,   118,   118,
     119,   119,   120,   120,   121,   121,   121,   121,   122,   122,
     123,   123,   123,   124,   124,   125,   125,   125,   125,   126,
     126,   127,   127,   127,   128,   128,   129,   129,   130,   130,
     130,   130,   131,   131,   131,   131,   131,   132,   133,   133,
     133,   133,   134,   134,   135,   135,   136,   136,   137,   137,
     138,   138,   139,   139,   140,   140,   140,   140,   141,   141,
     142,   142,   143,   143,   143,   144,   144,   144,   144,   144,
     145,   145,   146,   146,   147,   147,   148,   148,   149,   149,
     149,   150,   150,   151,   152,   152,   153,   154,   154,   154,
     154,   154,   154,   154,   154,   154,   155,   155,   155,   155,
     156,   156,   157,   157,   157,   157,   158,   158,   159,   159,
     159,   159,   160,   160
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     4,     1,
       1,     3,     2,     1,     3,     1,     1,     3,     3,     3,
       3,     1,     2,     3,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     2,     1,     3,     1,     5,     1,
       3,     1,     3,     2,     1,     1,     3,     2,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     3,     1,     3,     1,     3,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     3,     1,     2,     2,     3,     1,
       2,     2,     2,     3,     1,     2,     1,     3,     1,     1,
       3,     2,     2,     3,     1,     1,     1,     1,     1,     1,
       1,     1,     5,     8,     0,     5,     1,     2,     1,     4,
       6,     9,     1,     2,     3,     3,     1,     1,     5,     7,
       2,     3,     1,     3,     1,     3,     6,     2,     2,     5,
       0,     3,     1,     3,     1,     3,     1,     3,     3,     5,
       6,     1,     2,     2,     1,     1,     2,     4,     6,     4,
       5,     7,     5,     4,     6,     4,     1,     1,     2,     2,
       1,     2,     1,     3,     3,     5,     1,     2,     1,     3,
       3,     5,     1,     3
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
  "\"return\"", "\"as\"", "NAME", "NUMBER", "STRING", "\"<>\"", "$accept",
  "module", "file_input", "newline_or_stmt", "newline_stmt_seq", "stmt",
  "simple_stmt", "small_stmt", "flow_stmt", "break_stmt", "continue_stmt",
  "return_stmt", "raise_stmt", "yield_stmt", "small_stmt_seq", "del_stmt",
  "pass_stmt", "expr_stmt", "assign_expr_seq", "yield_expr", "star_expr",
  "testlist_star_expr", "test_star_expr", "test_star_expr_seq",
  "augassign", "testlist", "test_seq", "test", "or_test", "and_test",
  "not_test", "comparison", "comp_op", "expr", "xor_expr", "and_expr",
  "shift_expr", "shift_op", "arith_expr", "arith_op", "term", "term_op",
  "factor", "factor_op", "power", "atom_expr", "trailer_seq", "trailer",
  "arglist", "arglist_seq", "argument", "atom", "testlist_comp",
  "compound_stmt", "if_stmt", "elif_seq", "stmt_seq", "suite", "for_stmt",
  "exprlist", "exprlist_seq", "funcdef", "parameters", "typedargslist",
  "var_args", "var_arglist_trailer", "named_args", "tfpdef_test", "tfpdef",
  "decorator", "decorators", "decorated", "import_stmt", "import_name",
  "import_from", "import_dots", "dotted_as_names", "dotted_as_names_seq",
  "import_as_names", "import_as_names_seq", "dotted_name", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   183,   183,   207,   215,   219,   228,   232,   253,   257,
     267,   271,   282,   283,   284,   285,   286,   291,   291,   291,
     291,   291,   296,   304,   313,   317,   326,   330,   334,   341,
     351,   355,   366,   375,   392,   396,   400,   418,   422,   427,
     431,   458,   462,   466,   487,   509,   514,   525,   525,   530,
     535,   547,   547,   547,   547,   547,   547,   547,   547,   548,
     548,   548,   548,   555,   556,   563,   564,   579,   580,   586,
     587,   597,   598,   608,   612,   619,   620,   633,   637,   641,
     642,   643,   644,   645,   646,   647,   648,   649,   656,   657,
     666,   667,   676,   677,   686,   687,   694,   694,   700,   701,
     708,   708,   714,   715,   722,   722,   722,   722,   728,   729,
     736,   736,   736,   742,   743,   752,   753,   762,   766,   775,
     776,   790,   797,   803,   816,   817,   827,   831,   852,   853,
     854,   858,   892,   898,   905,   906,   907,   927,   939,   940,
     941,   942,   950,   955,   964,   969,   994,   998,  1007,  1011,
    1020,  1024,  1033,  1034,  1044,  1050,  1055,  1056,  1062,  1067,
    1077,  1081,  1121,  1128,  1135,  1144,  1151,  1159,  1165,  1173,
    1186,  1190,  1201,  1205,  1213,  1217,  1230,  1237,  1251,  1252,
    1253,  1259,  1260,  1266,  1271,  1271,  1276,  1296,  1300,  1304,
    1308,  1312,  1316,  1320,  1324,  1328,  1339,  1344,  1349,  1354,
    1366,  1367,  1372,  1376,  1380,  1384,  1397,  1398,  1402,  1406,
    1410,  1414,  1426,  1427
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
      75,    76,    77,    78,    79
    };
    const unsigned int user_token_number_max_ = 334;
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

