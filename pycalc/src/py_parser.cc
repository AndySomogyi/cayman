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

      case 77: // NAME


        { yyoutput << (yysym.value); }

        break;

      case 78: // NUMBER


        { yyoutput << (yysym.value); }

        break;

      case 79: // STRING


        { yyoutput << (yysym.value); }

        break;

      case 80: // "<>"


        { yyoutput << (yysym.value); }

        break;

      case 82: // module


        { yyoutput << (yysym.value); }

        break;

      case 83: // file_input


        { yyoutput << (yysym.value); }

        break;

      case 84: // newline_or_stmt


        { yyoutput << (yysym.value); }

        break;

      case 85: // newline_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 86: // stmt


        { yyoutput << (yysym.value); }

        break;

      case 87: // simple_stmt


        { yyoutput << (yysym.value); }

        break;

      case 88: // small_stmt


        { yyoutput << (yysym.value); }

        break;

      case 89: // flow_stmt


        { yyoutput << (yysym.value); }

        break;

      case 90: // break_stmt


        { yyoutput << (yysym.value); }

        break;

      case 91: // continue_stmt


        { yyoutput << (yysym.value); }

        break;

      case 92: // return_stmt


        { yyoutput << (yysym.value); }

        break;

      case 93: // raise_stmt


        { yyoutput << (yysym.value); }

        break;

      case 94: // yield_stmt


        { yyoutput << (yysym.value); }

        break;

      case 95: // small_stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 96: // del_stmt


        { yyoutput << (yysym.value); }

        break;

      case 97: // pass_stmt


        { yyoutput << (yysym.value); }

        break;

      case 98: // expr_stmt


        { yyoutput << (yysym.value); }

        break;

      case 99: // assign_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 100: // yield_expr


        { yyoutput << (yysym.value); }

        break;

      case 101: // star_expr


        { yyoutput << (yysym.value); }

        break;

      case 102: // testlist_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 103: // test_star_expr


        { yyoutput << (yysym.value); }

        break;

      case 104: // test_star_expr_seq


        { yyoutput << (yysym.value); }

        break;

      case 105: // augassign


        { yyoutput << (yysym.value); }

        break;

      case 106: // testlist


        { yyoutput << (yysym.value); }

        break;

      case 107: // test_seq


        { yyoutput << (yysym.value); }

        break;

      case 108: // test


        { yyoutput << (yysym.value); }

        break;

      case 109: // or_test


        { yyoutput << (yysym.value); }

        break;

      case 110: // and_test


        { yyoutput << (yysym.value); }

        break;

      case 111: // not_test


        { yyoutput << (yysym.value); }

        break;

      case 112: // comparison


        { yyoutput << (yysym.value); }

        break;

      case 113: // comp_op


        { yyoutput << (yysym.value); }

        break;

      case 114: // expr


        { yyoutput << (yysym.value); }

        break;

      case 115: // xor_expr


        { yyoutput << (yysym.value); }

        break;

      case 116: // and_expr


        { yyoutput << (yysym.value); }

        break;

      case 117: // shift_expr


        { yyoutput << (yysym.value); }

        break;

      case 118: // shift_op


        { yyoutput << (yysym.value); }

        break;

      case 119: // arith_expr


        { yyoutput << (yysym.value); }

        break;

      case 120: // arith_op


        { yyoutput << (yysym.value); }

        break;

      case 121: // term


        { yyoutput << (yysym.value); }

        break;

      case 122: // term_op


        { yyoutput << (yysym.value); }

        break;

      case 123: // factor


        { yyoutput << (yysym.value); }

        break;

      case 124: // factor_op


        { yyoutput << (yysym.value); }

        break;

      case 125: // power


        { yyoutput << (yysym.value); }

        break;

      case 126: // atom_expr


        { yyoutput << (yysym.value); }

        break;

      case 127: // trailer_seq


        { yyoutput << (yysym.value); }

        break;

      case 128: // trailer


        { yyoutput << (yysym.value); }

        break;

      case 129: // arglist


        { yyoutput << (yysym.value); }

        break;

      case 130: // arglist_seq


        { yyoutput << (yysym.value); }

        break;

      case 131: // argument


        { yyoutput << (yysym.value); }

        break;

      case 132: // atom


        { yyoutput << (yysym.value); }

        break;

      case 133: // testlist_comp


        { yyoutput << (yysym.value); }

        break;

      case 134: // compound_stmt


        { yyoutput << (yysym.value); }

        break;

      case 135: // if_stmt


        { yyoutput << (yysym.value); }

        break;

      case 136: // elif_seq


        { yyoutput << (yysym.value); }

        break;

      case 137: // stmt_seq


        { yyoutput << (yysym.value); }

        break;

      case 138: // suite


        { yyoutput << (yysym.value); }

        break;

      case 139: // for_stmt


        { yyoutput << (yysym.value); }

        break;

      case 140: // exprlist


        { yyoutput << (yysym.value); }

        break;

      case 141: // exprlist_seq


        { yyoutput << (yysym.value); }

        break;

      case 142: // funcdef


        { yyoutput << (yysym.value); }

        break;

      case 143: // parameters


        { yyoutput << (yysym.value); }

        break;

      case 144: // typedargslist


        { yyoutput << (yysym.value); }

        break;

      case 145: // var_args


        { yyoutput << (yysym.value); }

        break;

      case 146: // var_arglist_trailer


        { yyoutput << (yysym.value); }

        break;

      case 147: // named_args


        { yyoutput << (yysym.value); }

        break;

      case 148: // tfpdef_test


        { yyoutput << (yysym.value); }

        break;

      case 149: // tfpdef


        { yyoutput << (yysym.value); }

        break;

      case 150: // decorator


        { yyoutput << (yysym.value); }

        break;

      case 151: // decorators


        { yyoutput << (yysym.value); }

        break;

      case 152: // decorated


        { yyoutput << (yysym.value); }

        break;

      case 153: // import_stmt


        { yyoutput << (yysym.value); }

        break;

      case 154: // import_name


        { yyoutput << (yysym.value); }

        break;

      case 155: // import_from


        { yyoutput << (yysym.value); }

        break;

      case 156: // import_dots


        { yyoutput << (yysym.value); }

        break;

      case 157: // dotted_as_names


        { yyoutput << (yysym.value); }

        break;

      case 158: // dotted_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 159: // import_as_names


        { yyoutput << (yysym.value); }

        break;

      case 160: // import_as_names_seq


        { yyoutput << (yysym.value); }

        break;

      case 161: // dotted_name


        { yyoutput << (yysym.value); }

        break;

      case 162: // global_stmt


        { yyoutput << (yysym.value); }

        break;

      case 163: // name_seq


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

  case 23:

    {
        (yylhs.value) = ctx.ast->CreateBreak(yylhs.location);
    }

    break;

  case 24:

    {
        (yylhs.value) = ctx.ast->CreateContinue(yylhs.location);
    }

    break;

  case 25:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location);
    }

    break;

  case 26:

    {
        (yylhs.value) = ctx.ast->CreateReturn(yylhs.location, (yystack_[0].value));
    }

    break;

  case 27:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location);
    }

    break;

  case 28:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[0].value));
    }

    break;

  case 29:

    {
        (yylhs.value) = ctx.ast->CreateRaise(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 31:

    {
        (yylhs.value) = (yystack_[0].value); // small_stmt_seq: small_stmt
    }

    break;

  case 32:

    {
        // // small_stmt_seq: small_stmt_seq ";" small_stmt
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value)); 
    }

    break;

  case 33:

    {
        (yylhs.value) = ctx.ast->CreateDelete(yylhs.location, (yystack_[0].value));
    }

    break;

  case 34:

    {
        (yylhs.value) = ctx.ast->CreatePass(yylhs.location);
    }

    break;

  case 35:

    {
        (yylhs.value) = ctx.ast->CreateAugAssign(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 36:

    {
        (yylhs.value) = (yystack_[0].value);  /*foo*/
    }

    break;

  case 37:

    {
        (yylhs.value) = (yystack_[0].value); // expr_stmt: testlist_star_expr
    }

    break;

  case 38:

    {
        std::cout << "testlist_star_expr = yield_expr" << std::endl;
    }

    break;

  case 39:

    {
        std::cout << "testlist_star_expr = testlist_star_expr" << std::endl;
        (yylhs.value) = ctx.ast->CreateAssign(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 40:

    {
        std::cout << "assign_expr_seq = yield_expr" << std::endl;
    }

    break;

  case 41:

    {
        Assign *a = dynamic_cast<Assign*>((yystack_[2].value));
        assert(a);
        a->AddValue((yystack_[0].value));
        (yylhs.value) = a;
        std::cout << "assign_expr_seq = testlist_star_expr" << std::endl;
    }

    break;

  case 42:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location);
    }

    break;

  case 43:

    {
        (yylhs.value) = ctx.ast->CreateYield(yylhs.location, (yystack_[0].value));
    }

    break;

  case 44:

    {
        (yylhs.value) = ctx.ast->CreateYieldFrom(yylhs.location, (yystack_[0].value));
    }

    break;

  case 45:

    {
        (yylhs.value) = ctx.ast->CreateStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 46:

    {
        AstNode *a1 = (yystack_[0].value);
        (yylhs.value) = (yystack_[0].value); // testlist_star_expr:  test_star_expr_seq
    }

    break;

  case 47:

    {
        AstNode *a1 = (yystack_[1].value);
        (yylhs.value) = (yystack_[1].value); // testlist_star_expr: test_star_expr_seq ","
    }

    break;

  case 50:

    {
        // test_star_expr_seq: test_star_expr
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 51:

    {
        // test_star_expr_seq: test_star_expr_seq "," test_star_expr
        // don't know at this point what context, 
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 67:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 71:

    {
        // or_test: or_test "or" and_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 73:

    {
        // and_test: and_test "and" not_test
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 74:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 77:

    {
        // comparison: comparison comp_op expr
        (yylhs.value) = ctx.ast->CreateCompare(yylhs.location, (yystack_[2].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 78:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::NotIn);
    }

    break;

  case 79:

    {
        (yylhs.value) = TokenAstNodes::GetAstNodeForOperatorType(py::IsNot);
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

  case 96:

    {
       (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 100:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 104:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 110:

    {
        (yylhs.value) = ctx.ast->CreateUnaryOp(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 115:

    {
        (yylhs.value) = ctx.ast->CreateBinOp(yylhs.location, (yystack_[1].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 117:

    {
        // atom_expr: atom trailer_seq
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->GetTerminalExpr()->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 118:

    {
        assert(0);
    }

    break;

  case 119:

    {
        assert(0);
    }

    break;

  case 121:

    {
        // trailer_seq: trailer_seq trailer
        AstNode *trailer = (yystack_[0].value);
        ExprSeq *seq = dynamic_cast<ExprSeq*>(trailer);
        assert(seq);
        seq->SetBaseExpr((yystack_[1].value));
        (yylhs.value) = trailer;
    }

    break;

  case 122:

    {
        // trailer: "." NAME
        // base type is not known at this point, filled in 
        // in trailer_seq
        (yylhs.value) = ctx.ast->CreateAttribute(yylhs.location, UnknownCtx, NULL, (yystack_[0].value));
    }

    break;

  case 123:

    {
        // trailer: ()
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location);
    }

    break;

  case 124:

    {
        // trailer: ( arglist )
        // name is not known until atom expr
        (yylhs.value) = ctx.ast->CreateCall(yylhs.location, (yystack_[1].value));
    }

    break;

  case 126:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 127:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
   }

    break;

  case 128:

    {
       (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
   }

    break;

  case 131:

    {
        (yylhs.value) = ctx.ast->CreateKeywordArg(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 132:

    {
        (yylhs.value) = ctx.ast->CreateDblStarred(yylhs.location, (yystack_[0].value));
    }

    break;

  case 133:

    {
        // atom: "(" ")"
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, Load);
    }

    break;

  case 134:

    {
        // atom: |"(" testlist_comp ")"
        AstNode *testlistComp = (yystack_[1].value);
        testlistComp->SetAtomic(true);
        (yylhs.value) = testlistComp;
    }

    break;

  case 135:

    { (yylhs.value) = (yystack_[0].value); /*name*/}

    break;

  case 136:

    { (yylhs.value) = (yystack_[0].value); /*num*/}

    break;

  case 137:

    { (yylhs.value) = (yystack_[0].value); /*str*/}

    break;

  case 143:

    {
        // if_stmt:     "if" test ":" suite elif_seq
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[3].value), (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 144:

    {
        // if_stmt: "if" test ":" suite elif_seq "else" ":" suite
        (yylhs.value) = ctx.ast->CreateIf(yylhs.location, (yystack_[6].value), (yystack_[4].value), (yystack_[3].value), (yystack_[0].value)); 
    }

    break;

  case 145:

    {
        // elif_seq: %empty
        (yylhs.value) = NULL;
    }

    break;

  case 146:

    {
        // elif_seq: elif_seq "elif" test ":" suite
        (yylhs.value) = ctx.ast->CreateElif(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 147:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 148:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[1].value), (yystack_[0].value));
    }

    break;

  case 149:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 150:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 151:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 152:

    {
        (yylhs.value) = ctx.ast->CreateFor(yylhs.location, (yystack_[7].value), (yystack_[5].value), (yystack_[3].value), (yystack_[0].value));
    }

    break;

  case 154:

    {
        // exprlist:
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 155:

    {
        // exprlist_seq: exprlist_seq "," expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 156:

    {
        // exprlist_seq: exprlist_seq "," star_expr
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 159:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[3].value), (yystack_[2].value), NULL, (yystack_[0].value));
    }

    break;

  case 160:

    {
        // CreateFunctionDef(loc, nm, args, returns, suite)
        (yylhs.value) = ctx.ast->CreateFunctionDef(yylhs.location, (yystack_[5].value), (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 161:

    {
        (yylhs.value) = ctx.ast->CreateTmpArguments(yylhs.location);
    }

    break;

  case 162:

    {
        (yylhs.value) = (yystack_[1].value);
    }

    break;

  case 163:

    {
        // name_args is a tuple (list of args)
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 164:

    {
        TmpArguments *args = dynamic_cast<TmpArguments*>((yystack_[0].value));
        assert(args);
        args->SetArgs((yystack_[2].value));
        (yylhs.value) = args;
    }

    break;

  case 165:

    {
        // var_args is already an TmpArguments type
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 166:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[1].value));
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 167:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetVararg((yystack_[4].value));
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 168:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 169:

    {
        // var_args: "*" var_arglist_trailer      
        // func(*, a) is actually valid syntax, here a is a kw only arg.
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 170:

    {
        TmpArguments *args = ctx.ast->CreateTmpArguments(yylhs.location);
        args->SetKwOnlyArgs((yystack_[3].value));
        args->SetKwArg((yystack_[0].value));
        (yylhs.value) = args;
    }

    break;

  case 171:

    {
        (yylhs.value) = NULL;
    }

    break;

  case 172:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, UnknownCtx, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 173:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[0].value));
    }

    break;

  case 174:

    {
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 175:

    {
        (yylhs.value) = (yystack_[0].value);
    }

    break;

  case 176:

    {
        Arg *arg = dynamic_cast<Arg*>((yystack_[2].value));
        assert(arg);
        arg->def = (yystack_[0].value);
        assert(arg->def);
        (yylhs.value) = arg;
    }

    break;

  case 177:

    {
        AstNode *name = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name);
        ctx.ast->Free(name);
        (yylhs.value) = result;
    }

    break;

  case 178:

    {
        AstNode *name = (yystack_[2].value);
        AstNode *type = (yystack_[0].value);
        Arg* result = ctx.ast->CreateArg(yylhs.location, name, NULL, type);
        ctx.ast->Free(name);
        ctx.ast->Free(type);
        (yylhs.value) = result;
    }

    break;

  case 187:

    {
        (yylhs.value) = ctx.ast->CreateImport(yylhs.location, (yystack_[0].value));
    }

    break;

  case 188:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 189:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value));
    }

    break;

  case 190:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 191:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 192:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[4].value), (yystack_[1].value), (yystack_[5].value));
    }

    break;

  case 193:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[2].value), (yystack_[0].value), (yystack_[3].value));
    }

    break;

  case 194:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 195:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[1].value), (yystack_[4].value));
    }

    break;

  case 196:

    {
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, NULL, (yystack_[0].value), (yystack_[2].value));
    }

    break;

  case 197:

    {
        // import_dots: "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 1);
    }

    break;

  case 198:

    {
        // import_dots: "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, 3);
    }

    break;

  case 199:

    {
        // import_dots: import_dots "."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 1);
    }

    break;

  case 200:

    {
        // import_dots: import_dots "..."
        (yylhs.value) = ctx.ast->CreateImportFrom(yylhs.location, (yystack_[1].value), 3);
    }

    break;

  case 203:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 204:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 205:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 206:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 209:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[0].value), NULL);
    }

    break;

  case 210:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, NULL, (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 211:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[2].value), (yystack_[0].value), NULL);
    }

    break;

  case 212:

    {
        (yylhs.value) = ctx.ast->CreateAliasNodes(yylhs.location, (yystack_[4].value), (yystack_[2].value), (yystack_[0].value));
    }

    break;

  case 214:

    {
        Name *dottedName = dynamic_cast<Name*>((yystack_[2].value));
        assert(dottedName);
        dottedName->AppendName((yystack_[0].value));
        ctx.ast->Free((yystack_[0].value));
        (yylhs.value) = dottedName;
    }

    break;

  case 215:

    {
        (yylhs.value) = ctx.ast->CreateGlobal(yylhs.location, (yystack_[0].value));
    }

    break;

  case 217:

    {
        // name_seq: name_seq "," NAME
        (yylhs.value) = ctx.ast->CreateTuple(yylhs.location, (yystack_[2].value), (yystack_[0].value));
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
    -237,    18,  -237,   200,  -237,   -32,  -237,   446,   446,   516,
     516,  -237,  -237,   449,  -237,  -237,   513,  -237,    31,     4,
       1,    31,   104,  -237,  -237,   446,   446,    37,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,    91,  -237,  -237,  -237,    33,  -237,  -237,   281,  -237,
      72,  -237,    55,    43,  -237,    15,    94,    88,   112,    82,
      44,     6,  -237,   513,  -237,    99,    45,  -237,  -237,  -237,
    -237,  -237,    11,  -237,  -237,  -237,  -237,  -237,   123,   126,
    -237,  -237,    94,   141,   130,  -237,  -237,  -237,   133,    94,
    -237,    90,    45,  -237,  -237,   -18,     8,  -237,   131,    17,
     446,  -237,   132,  -237,    89,  -237,  -237,   134,  -237,   118,
     452,   452,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,  -237,  -237,  -237,   446,   475,   446,   446,   446,   149,
    -237,   157,  -237,  -237,  -237,  -237,  -237,  -237,  -237,   513,
     513,   513,   513,  -237,  -237,   513,  -237,  -237,   513,  -237,
    -237,  -237,  -237,   513,  -237,   513,   385,    92,    45,  -237,
    -237,  -237,    13,    21,   371,   446,   516,  -237,  -237,   408,
      96,    45,  -237,  -237,     9,    19,    10,    31,   100,  -237,
     446,   446,   101,  -237,  -237,  -237,  -237,  -237,  -237,  -237,
    -237,   111,    43,  -237,  -237,  -237,    94,    88,   112,    82,
      44,     6,  -237,  -237,  -237,   446,  -237,   137,   148,   152,
    -237,  -237,  -237,  -237,   102,   102,   162,   160,  -237,   169,
    -237,   164,   371,   446,   183,  -237,  -237,   178,  -237,    94,
     186,   187,  -237,   135,  -237,   136,  -237,   182,    12,   135,
    -237,  -237,    27,  -237,  -237,  -237,  -237,   446,  -237,   446,
    -237,   472,   184,  -237,  -237,   446,  -237,     2,   446,  -237,
     195,   300,   129,   371,  -237,   194,   201,   143,   145,   135,
    -237,  -237,   203,   147,  -237,  -237,  -237,    -9,   205,  -237,
    -237,  -237,  -237,   371,  -237,   280,   202,   446,   224,  -237,
    -237,  -237,   156,   212,  -237,  -237,   102,  -237,    24,  -237,
    -237,  -237,   371,   210,   211,   158,  -237,  -237,   102,  -237,
     371,   371,  -237,  -237,  -237,  -237
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       6,     0,     2,     0,     1,     0,    34,     0,     0,     0,
       0,     3,     4,     0,   111,   112,     0,   113,     0,     0,
       0,     0,    42,    23,    24,    27,    25,     0,   135,   136,
     137,     7,     5,     8,    31,    15,    18,    19,    20,    21,
      22,     0,    13,    14,    12,    36,    30,    49,    37,    50,
      46,    48,    68,    70,    72,    75,    76,    89,    91,    93,
      95,    99,   103,     0,   109,   114,   116,     9,   142,   141,
     139,   182,     0,   140,    16,   185,   186,    17,     0,     0,
      74,   158,   157,     0,   153,    33,   133,   138,     0,    45,
     213,     0,   118,   197,   198,     0,     0,   187,   201,   203,
       0,    43,    64,    66,    28,    26,   216,   215,    10,     0,
       0,     0,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,     0,    47,     0,     0,     0,     0,
      87,    88,    80,    81,    82,    86,    84,    83,    85,     0,
       0,     0,     0,    97,    98,     0,   101,   102,     0,   105,
     106,   107,   108,     0,   110,     0,     0,     0,   117,   120,
     184,   183,     0,     0,     0,     0,   154,   134,   179,     0,
       0,   119,   199,   200,     0,     0,     0,   202,     0,    44,
      65,     0,     0,    11,    32,    40,    41,    38,    39,    35,
      51,     0,    71,    73,    78,    79,    77,    90,    92,    94,
      96,   100,   104,   115,   123,     0,   130,   129,     0,   125,
     127,   122,   121,   161,   171,     0,   177,     0,   165,   163,
     173,   175,     0,     0,     0,   149,   145,     0,   156,   155,
       0,     0,   214,     0,   194,   209,   196,   207,     0,     0,
     188,   190,   205,   204,    67,    29,   217,     0,   132,     0,
     124,   126,   169,   171,   168,     0,   162,     0,     0,   159,
       0,     0,   143,     0,   180,     0,     0,     0,   208,     0,
     191,   193,     0,     0,    69,   131,   128,     0,   166,   178,
     164,   174,   176,     0,   147,     0,     0,     0,   151,   181,
     195,   210,   211,     0,   189,   206,     0,   172,     0,   160,
     150,   148,     0,     0,     0,     0,   192,   170,     0,   144,
       0,     0,   212,   167,   146,   152
  };

  const short int
  py_parser::yypgoto_[] =
  {
    -237,  -237,  -237,  -237,  -237,  -236,    -3,   127,  -237,  -237,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,    29,
      -5,     0,   113,  -237,  -237,   -24,  -237,    -6,   114,   110,
      -2,  -237,  -237,    -1,   107,    98,   106,  -237,    97,  -237,
     103,  -237,   -56,  -237,  -237,  -237,   161,   -67,    81,  -237,
       3,   236,  -237,  -237,  -237,  -237,  -237,  -190,  -237,   246,
    -237,   185,  -237,  -237,     5,     7,  -237,  -159,  -193,   189,
    -237,  -237,  -237,  -237,  -237,  -237,  -237,  -237,  -164,  -237,
     -10,  -237,  -237
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,     1,     2,    31,     3,    32,   225,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    45,    46,
      47,    48,    49,    50,   124,   101,   102,    51,    52,    53,
      54,    55,   139,    56,    57,    58,    59,   145,    60,   148,
      61,   153,    62,    63,    64,    65,   158,   159,   208,   209,
     210,    66,    88,    67,    68,   262,   285,   226,    69,    83,
      84,    70,   163,   217,   218,   252,   219,   297,   221,    71,
      72,    73,    74,    75,    76,    95,    97,    98,   236,   237,
      91,    77,   107
  };

  const unsigned short int
  py_parser::yytable_[] =
  {
      33,    79,   105,   220,    81,    81,    80,   154,    82,    82,
      96,    99,   241,    87,     5,    89,   103,   172,     4,   104,
     103,   253,   254,    13,   129,   284,   130,   131,   233,   239,
     214,   269,   259,   213,   149,   150,    93,   234,   240,   296,
     270,   214,   151,   170,   222,    78,   173,   132,   133,   301,
     215,   174,   170,   128,   170,   134,   135,   136,   137,    90,
     126,   215,   170,   127,   156,    94,   152,   110,   216,   266,
     146,   147,   308,   288,   271,   272,    18,   176,    90,   216,
     157,    28,    29,    30,   223,   175,   235,   235,   238,   235,
     216,   212,   178,   299,   179,   138,   125,   202,   281,   203,
     189,   216,   273,   307,   212,   293,   168,   108,    90,   169,
     186,   188,   309,     8,   106,   313,   109,   247,   103,   127,
     314,   315,     6,    13,   140,   170,   193,     8,   143,   144,
      14,    15,    10,   141,   183,   286,   287,    13,   196,   185,
     187,   227,   162,   142,    14,    15,    16,   155,    17,   164,
     207,   206,   165,   167,   166,   177,   180,   181,   182,   103,
     194,   228,    17,   207,   206,   229,   195,   242,   250,   211,
      19,   249,   100,   232,   244,   245,   251,   243,   246,   216,
     256,    28,    29,    30,    19,   255,    20,    21,    22,    23,
      24,    25,    26,   257,    27,    28,    29,    30,   258,   248,
     261,   263,   264,     5,     6,     7,   268,   265,   277,     8,
     289,   267,   235,     9,    10,    11,    12,   260,   283,    13,
     291,   290,   292,   294,   295,   302,    14,    15,    16,   298,
     304,   305,   306,   310,   311,   312,   184,   192,   190,   198,
     191,   274,   200,   275,    17,   207,   206,   197,   199,   279,
     231,   201,   282,   171,   276,    92,    85,   160,    33,     0,
     278,   161,   280,     0,     0,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,     0,    27,    28,    29,    30,
       0,   303,    33,     5,     6,     7,     0,     0,     0,     8,
       0,     0,     0,     9,    10,     0,     0,     0,   300,    13,
       0,     0,     0,     5,     6,     7,    14,    15,    16,     8,
       0,     0,     0,     9,    10,   111,     0,     0,     0,    13,
       0,     0,     0,     0,    17,     0,    14,    15,    16,     0,
     112,   113,   114,   115,   116,   117,   118,   119,   120,   121,
     122,     0,   123,     0,    17,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,     0,    27,    28,    29,    30,
       0,     0,     0,     0,     0,    18,    19,     0,    20,    21,
      22,    23,    24,    25,    26,     6,    27,    28,    29,    30,
       8,     0,     0,     0,     0,    10,     0,   224,     0,     0,
      13,     0,     0,     0,     8,     0,     0,    14,    15,    16,
       0,     0,     0,     0,    13,   204,     0,     0,     0,     0,
       0,    14,    15,    16,     0,    17,     0,     8,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    13,   230,    17,
       0,     0,     0,   205,    14,    15,    16,    19,     0,    20,
      21,    22,    23,    24,    25,    26,     0,    27,    28,    29,
      30,    19,    17,     0,     0,     8,   205,     0,     8,     0,
       0,     8,    28,    29,    30,    13,     0,     0,    13,    86,
       0,    13,    14,    15,    19,    14,    15,    16,    14,    15,
      16,     8,     0,     0,     8,    28,    29,    30,     0,     0,
      17,    13,     0,    17,    13,     0,    17,     0,    14,    15,
      16,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,    19,     0,     0,    19,    17,     0,    19,    17,
     205,     0,    22,    28,    29,    30,    28,    29,    30,    28,
      29,    30,    13,     0,     0,    13,     0,     0,    19,    14,
      15,    19,    14,    15,    16,     0,     0,     0,     0,    28,
      29,    30,    28,    29,    30,     0,     0,    17,     0,     0,
      17,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    19,
       0,     0,    19,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    30,    28,    29,    30
  };

  const short int
  py_parser::yycheck_[] =
  {
       3,     7,    26,   162,     9,    10,     8,    63,     9,    10,
      20,    21,   176,    13,     3,    16,    22,    35,     0,    25,
      26,   214,   215,    19,     9,   261,    11,    12,    19,    19,
      28,    19,   222,    20,    28,    29,    35,    28,    28,    48,
      28,    28,    36,    35,    23,    77,    64,    32,    33,   285,
      48,    69,    35,    10,    35,    40,    41,    42,    43,    77,
       5,    48,    35,     8,    19,    64,    60,    34,    77,   233,
      26,    27,    48,   263,   238,   239,    65,    69,    77,    77,
      35,    77,    78,    79,    63,    95,    77,    77,    69,    77,
      77,   158,    75,   283,   100,    80,    24,   153,   257,   155,
     124,    77,    75,   296,   171,   269,    16,    16,    77,    19,
     110,   111,   302,     9,    77,   308,    25,     6,   124,     8,
     310,   311,     4,    19,    30,    35,   128,     9,    46,    47,
      26,    27,    14,    45,    16,     6,     7,    19,   139,   110,
     111,   165,    19,    31,    26,    27,    28,    48,    44,    23,
     156,   156,    11,    20,    24,    24,    24,    68,    24,   165,
      11,   166,    44,   169,   169,   166,     9,   177,    20,    77,
      66,    34,    68,    77,   180,   181,    24,    77,    77,    77,
      20,    77,    78,    79,    66,    23,    68,    69,    70,    71,
      72,    73,    74,    24,    76,    77,    78,    79,    34,   205,
      17,    23,    16,     3,     4,     5,    24,    20,    24,     9,
      16,    75,    77,    13,    14,    15,    16,   223,    23,    19,
      77,    20,    77,    20,    77,    23,    26,    27,    28,    24,
       6,    75,    20,    23,    23,    77,   109,   127,   125,   141,
     126,   247,   145,   249,    44,   251,   251,   140,   142,   255,
     169,   148,   258,    92,   251,    19,    10,    72,   261,    -1,
     253,    72,   257,    -1,    -1,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      -1,   287,   285,     3,     4,     5,    -1,    -1,    -1,     9,
      -1,    -1,    -1,    13,    14,    -1,    -1,    -1,    18,    19,
      -1,    -1,    -1,     3,     4,     5,    26,    27,    28,     9,
      -1,    -1,    -1,    13,    14,    34,    -1,    -1,    -1,    19,
      -1,    -1,    -1,    -1,    44,    -1,    26,    27,    28,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    58,
      59,    -1,    61,    -1,    44,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,    -1,    76,    77,    78,    79,
      -1,    -1,    -1,    -1,    -1,    65,    66,    -1,    68,    69,
      70,    71,    72,    73,    74,     4,    76,    77,    78,    79,
       9,    -1,    -1,    -1,    -1,    14,    -1,    16,    -1,    -1,
      19,    -1,    -1,    -1,     9,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    -1,    19,    20,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    -1,    44,    -1,     9,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    19,    20,    44,
      -1,    -1,    -1,    48,    26,    27,    28,    66,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    76,    77,    78,
      79,    66,    44,    -1,    -1,     9,    48,    -1,     9,    -1,
      -1,     9,    77,    78,    79,    19,    -1,    -1,    19,    20,
      -1,    19,    26,    27,    66,    26,    27,    28,    26,    27,
      28,     9,    -1,    -1,     9,    77,    78,    79,    -1,    -1,
      44,    19,    -1,    44,    19,    -1,    44,    -1,    26,    27,
      28,    26,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    66,    -1,    -1,    66,    44,    -1,    66,    44,
      48,    -1,    70,    77,    78,    79,    77,    78,    79,    77,
      78,    79,    19,    -1,    -1,    19,    -1,    -1,    66,    26,
      27,    66,    26,    27,    28,    -1,    -1,    -1,    -1,    77,
      78,    79,    77,    78,    79,    -1,    -1,    44,    -1,    -1,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      -1,    -1,    66,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      77,    78,    79,    77,    78,    79
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,    82,    83,    85,     0,     3,     4,     5,     9,    13,
      14,    15,    16,    19,    26,    27,    28,    44,    65,    66,
      68,    69,    70,    71,    72,    73,    74,    76,    77,    78,
      79,    84,    86,    87,    88,    89,    90,    91,    92,    93,
      94,    95,    96,    97,    98,    99,   100,   101,   102,   103,
     104,   108,   109,   110,   111,   112,   114,   115,   116,   117,
     119,   121,   123,   124,   125,   126,   132,   134,   135,   139,
     142,   150,   151,   152,   153,   154,   155,   162,    77,   108,
     111,   101,   114,   140,   141,   140,    20,   102,   133,   114,
      77,   161,   132,    35,    64,   156,   161,   157,   158,   161,
      68,   106,   107,   108,   108,   106,    77,   163,    16,    25,
      34,    34,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    58,    59,    61,   105,    24,     5,     8,    10,     9,
      11,    12,    32,    33,    40,    41,    42,    43,    80,   113,
      30,    45,    31,    46,    47,   118,    26,    27,   120,    28,
      29,    36,    60,   122,   123,    48,    19,    35,   127,   128,
     142,   150,    19,   143,    23,    11,    24,    20,    16,    19,
      35,   127,    35,    64,    69,   161,    69,    24,    75,   108,
      24,    68,    24,    16,    88,   100,   102,   100,   102,   106,
     103,   109,   110,   111,    11,     9,   114,   115,   116,   117,
     119,   121,   123,   123,    20,    48,   101,   108,   129,   130,
     131,    77,   128,    20,    28,    48,    77,   144,   145,   147,
     148,   149,    23,    63,    16,    87,   138,   106,   101,   114,
      20,   129,    77,    19,    28,    77,   159,   160,    69,    19,
      28,   159,   161,    77,   108,   108,    77,     6,   108,    34,
      20,    24,   146,   149,   149,    23,    20,    24,    34,   138,
     108,    17,   136,    23,    16,    20,   159,    75,    24,    19,
      28,   159,   159,    75,   108,   108,   131,    24,   146,   108,
     145,   148,   108,    23,    86,   137,     6,     7,   138,    16,
      20,    77,    77,   159,    20,    77,    48,   148,    24,   138,
      18,    86,    23,   108,     6,    75,    20,   149,    48,   138,
      23,    23,    77,   149,   138,   138
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    81,    82,    83,    84,    84,    85,    85,    86,    86,
      87,    87,    88,    88,    88,    88,    88,    88,    89,    89,
      89,    89,    89,    90,    91,    92,    92,    93,    93,    93,
      94,    95,    95,    96,    97,    98,    98,    98,    99,    99,
      99,    99,   100,   100,   100,   101,   102,   102,   103,   103,
     104,   104,   105,   105,   105,   105,   105,   105,   105,   105,
     105,   105,   105,   105,   106,   106,   107,   107,   108,   108,
     109,   109,   110,   110,   111,   111,   112,   112,   113,   113,
     113,   113,   113,   113,   113,   113,   113,   113,   113,   114,
     114,   115,   115,   116,   116,   117,   117,   118,   118,   119,
     119,   120,   120,   121,   121,   122,   122,   122,   122,   123,
     123,   124,   124,   124,   125,   125,   126,   126,   126,   126,
     127,   127,   128,   128,   128,   129,   129,   130,   130,   131,
     131,   131,   131,   132,   132,   132,   132,   132,   133,   134,
     134,   134,   134,   135,   135,   136,   136,   137,   137,   138,
     138,   139,   139,   140,   140,   141,   141,   141,   141,   142,
     142,   143,   143,   144,   144,   144,   145,   145,   145,   145,
     145,   146,   146,   147,   147,   148,   148,   149,   149,   150,
     150,   150,   151,   151,   152,   153,   153,   154,   155,   155,
     155,   155,   155,   155,   155,   155,   155,   156,   156,   156,
     156,   157,   157,   158,   158,   158,   158,   159,   159,   160,
     160,   160,   160,   161,   161,   162,   163,   163
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     1,     2,     1,     1,     0,     2,     1,     1,
       2,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     4,
       1,     1,     3,     2,     1,     3,     1,     1,     3,     3,
       3,     3,     1,     2,     3,     2,     1,     2,     1,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     5,
       1,     3,     1,     3,     2,     1,     1,     3,     2,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     1,
       2,     1,     1,     1,     1,     3,     1,     2,     2,     3,
       1,     2,     2,     2,     3,     1,     2,     1,     3,     1,
       1,     3,     2,     2,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     5,     8,     0,     5,     1,     2,     1,
       4,     6,     9,     1,     2,     3,     3,     1,     1,     5,
       7,     2,     3,     1,     3,     1,     3,     6,     2,     2,
       5,     0,     3,     1,     3,     1,     3,     1,     3,     3,
       5,     6,     1,     2,     2,     1,     1,     2,     4,     6,
       4,     5,     7,     5,     4,     6,     4,     1,     1,     2,
       2,     1,     2,     1,     3,     3,     5,     1,     2,     1,
       3,     3,     5,     1,     3,     2,     1,     3
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
  "\"return\"", "\"as\"", "\"global\"", "NAME", "NUMBER", "STRING",
  "\"<>\"", "$accept", "module", "file_input", "newline_or_stmt",
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
  "decorator", "decorators", "decorated", "import_stmt", "import_name",
  "import_from", "import_dots", "dotted_as_names", "dotted_as_names_seq",
  "import_as_names", "import_as_names_seq", "dotted_name", "global_stmt",
  "name_seq", YY_NULLPTR
  };

#if YYDEBUG
  const unsigned short int
  py_parser::yyrline_[] =
  {
       0,   184,   184,   208,   216,   220,   229,   233,   254,   258,
     268,   272,   283,   284,   285,   286,   287,   288,   293,   293,
     293,   293,   293,   298,   306,   315,   319,   328,   332,   336,
     343,   353,   357,   368,   377,   394,   398,   402,   420,   424,
     429,   433,   460,   464,   468,   489,   511,   516,   527,   527,
     532,   537,   549,   549,   549,   549,   549,   549,   549,   549,
     550,   550,   550,   550,   557,   558,   565,   566,   581,   582,
     588,   589,   599,   600,   610,   614,   621,   622,   635,   639,
     643,   644,   645,   646,   647,   648,   649,   650,   651,   658,
     659,   668,   669,   678,   679,   688,   689,   696,   696,   702,
     703,   710,   710,   716,   717,   724,   724,   724,   724,   730,
     731,   738,   738,   738,   744,   745,   754,   755,   764,   768,
     777,   778,   792,   799,   805,   818,   819,   829,   833,   854,
     855,   856,   860,   894,   900,   907,   908,   909,   929,   941,
     942,   943,   944,   952,   957,   966,   971,   996,  1000,  1009,
    1013,  1022,  1026,  1035,  1036,  1046,  1052,  1057,  1058,  1064,
    1069,  1079,  1083,  1123,  1130,  1137,  1146,  1153,  1161,  1167,
    1175,  1188,  1192,  1203,  1207,  1215,  1219,  1232,  1239,  1253,
    1254,  1255,  1261,  1262,  1268,  1273,  1273,  1278,  1298,  1302,
    1306,  1310,  1314,  1318,  1322,  1326,  1330,  1341,  1346,  1351,
    1356,  1368,  1369,  1374,  1378,  1382,  1386,  1399,  1400,  1404,
    1408,  1412,  1416,  1428,  1429,  1442,  1450,  1451
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
      75,    76,    77,    78,    79,    80
    };
    const unsigned int user_token_number_max_ = 335;
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

