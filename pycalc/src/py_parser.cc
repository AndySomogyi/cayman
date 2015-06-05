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

#line 37 "py_parser.cc" // lalr1.cc:404

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

#include "py_parser.hh"

// User implementation prologue.

#line 51 "py_parser.cc" // lalr1.cc:412
// Unqualified %code blocks.
#line 29 "py_parser.yy" // lalr1.cc:413

    #include "ParserContext.h"

#line 57 "py_parser.cc" // lalr1.cc:413


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

#line 4 "py_parser.yy" // lalr1.cc:479
namespace py {
#line 143 "py_parser.cc" // lalr1.cc:479

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
  py_parser::py_parser (ParserContext& context_yyarg)
    :
#if YYDEBUG
      yydebug_ (false),
      yycdebug_ (&std::cerr),
#endif
      context (context_yyarg)
  {}

  py_parser::~py_parser ()
  {}


  /*---------------.
  | Symbol types.  |
  `---------------*/



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
      switch (that.type_get ())
    {
      case 115: // atom
        value.move< ASTNode* > (that.value);
        break;

      case 64: // "number"
        value.move< int > (that.value);
        break;

      case 63: // "name"
      case 65: // "string"
        value.move< std::string > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.type = empty_symbol;
  }

  inline
  py_parser::stack_symbol_type&
  py_parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
      switch (that.type_get ())
    {
      case 115: // atom
        value.copy< ASTNode* > (that.value);
        break;

      case 64: // "number"
        value.copy< int > (that.value);
        break;

      case 63: // "name"
      case 65: // "string"
        value.copy< std::string > (that.value);
        break;

      default:
        break;
    }

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
            case 63: // "name"

#line 137 "py_parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 336 "py_parser.cc" // lalr1.cc:636
        break;

      case 64: // "number"

#line 137 "py_parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< int > (); }
#line 343 "py_parser.cc" // lalr1.cc:636
        break;

      case 65: // "string"

#line 137 "py_parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< std::string > (); }
#line 350 "py_parser.cc" // lalr1.cc:636
        break;

      case 115: // atom

#line 137 "py_parser.yy" // lalr1.cc:636
        { yyoutput << yysym.value.template as< ASTNode* > (); }
#line 357 "py_parser.cc" // lalr1.cc:636
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
    #line 22 "py_parser.yy" // lalr1.cc:745
{
  // Initialize the initial location.
    yyla.location.begin.filename = yyla.location.end.filename = &context.GetFilename();
}

#line 476 "py_parser.cc" // lalr1.cc:745

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
            symbol_type yylookahead (yylex (context));
            yyla.move (yylookahead);
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
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
        switch (yyr1_[yyn])
    {
      case 115: // atom
        yylhs.value.build< ASTNode* > ();
        break;

      case 64: // "number"
        yylhs.value.build< int > ();
        break;

      case 63: // "name"
      case 65: // "string"
        yylhs.value.build< std::string > ();
        break;

      default:
        break;
    }


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
  case 110:
#line 546 "py_parser.yy" // lalr1.cc:859
    {yylhs.value.as< ASTNode* > () = 0;}
#line 599 "py_parser.cc" // lalr1.cc:859
    break;

  case 111:
#line 547 "py_parser.yy" // lalr1.cc:859
    { yylhs.value.as< ASTNode* > () = 0; }
#line 605 "py_parser.cc" // lalr1.cc:859
    break;

  case 112:
#line 548 "py_parser.yy" // lalr1.cc:859
    { yylhs.value.as< ASTNode* > () = 0; }
#line 611 "py_parser.cc" // lalr1.cc:859
    break;

  case 113:
#line 549 "py_parser.yy" // lalr1.cc:859
    { yylhs.value.as< ASTNode* > () = 0; }
#line 617 "py_parser.cc" // lalr1.cc:859
    break;


#line 621 "py_parser.cc" // lalr1.cc:859
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


  const signed char py_parser::yypact_ninf_ = -95;

  const signed char py_parser::yytable_ninf_ = -1;

  const short int
  py_parser::yypact_[] =
  {
      39,   -55,   -95,   164,   -95,   159,   -95,   -95,   169,   -95,
     -14,   -95,   -95,   -95,    12,   -95,   -95,   -95,    -7,   -95,
     -95,   -95,   188,   -95,     9,   -95,     5,    23,   -95,   100,
     -32,    -8,     7,   -95,   -10,   -17,   -95,   169,   -95,    -9,
     -95,    28,   -95,   -95,   -95,    29,   -32,   -95,   -95,   -95,
      14,    92,    92,   -95,   -95,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   -95,   -95,   -95,   -95,    13,   164,   159,   164,
     164,   164,    36,   -95,    43,   -95,   -95,   -95,   -95,   -95,
     -95,   -95,   169,   169,   169,   169,   -95,   -95,   -23,   169,
     -95,   -95,   -95,   -95,   169,   -95,   169,   -13,   -95,   -95,
     -13,   -95,   -95,   -95,   -95,   -95,   -95,    31,   -95,   159,
     -95,    33,   -95,   -95,    17,    23,   -95,   -95,   -95,   -32,
      -8,     7,   -95,   169,   169,   -17,   -95,   -95,   134,    -5,
     -95,    81,   -95,   -95,   164,   164,   -10,   -10,   -95,   164,
      27,    45,    38,   -95,   -95,   -95,   -95,   -95,   -95,   164,
     -95,   154,   -95,   -95
  };

  const unsigned char
  py_parser::yydefact_[] =
  {
       0,     0,    18,     0,     3,     0,    91,    92,     0,    93,
       0,   111,   112,   113,     0,     9,     4,    16,     0,    14,
      15,    28,    21,    29,    25,    27,    48,    50,    52,    55,
      56,    69,    71,    73,    76,    79,    83,     0,    90,    94,
      98,     0,   114,   115,    54,     0,    24,    98,     1,     2,
       0,     0,     0,    31,    32,    33,    35,    36,    37,    38,
      39,    40,    41,    43,    34,    42,    20,     0,    26,     0,
       0,     0,     0,    65,    67,    58,    59,    60,    64,    62,
      61,    63,     0,     0,     0,     0,    81,    82,    75,     0,
      85,    86,    87,    88,     0,    89,     0,    96,     5,   110,
      97,     6,     7,    10,     8,    11,    12,     0,    17,     0,
      19,    44,    46,    30,     0,    51,    53,    66,    68,    57,
      70,    72,    74,     0,     0,    80,    84,    95,     0,     0,
      99,     0,    22,    23,    45,     0,    77,    78,   101,     0,
     107,     0,   103,   105,   100,    13,    47,    49,   109,     0,
     102,   104,   108,   106
  };

  const signed char
  py_parser::yypgoto_[] =
  {
     -95,   -95,   -95,   -95,   -95,   -95,   -95,    16,   -51,    19,
     -95,   -95,   -95,   -95,   -95,   -36,     1,   -95,   -95,   -95,
     -95,   -67,    18,     4,     0,   -95,   -95,    -6,     6,     8,
       3,   -95,   -94,   -95,     2,   -95,   -11,   -95,   -95,   -95,
      46,   -95,   -95,   -95,   -57,    86,    48,   -95
  };

  const short int
  py_parser::yydefgoto_[] =
  {
      -1,    14,    15,    49,   103,    50,   104,    16,    17,    18,
      19,    20,    66,   132,    21,    22,    23,    24,    67,   110,
     111,    25,    26,    27,    28,    29,    82,    30,    31,    32,
      33,    88,    34,    89,    35,    94,    36,    37,    38,    39,
      97,   130,   141,   142,   143,    40,    41,    42
  };

  const unsigned char
  py_parser::yytable_[] =
  {
     112,   108,    46,    44,     5,   128,    45,    51,    43,    90,
      91,    69,    48,    70,    86,    87,    52,    92,     1,     2,
     129,   123,   124,     3,   135,    70,    95,   101,   102,   136,
     137,    68,     5,    71,    83,    84,    85,    96,     6,     7,
       8,    93,    98,     1,     2,   109,    99,   117,     3,    11,
      12,    13,   118,     4,   131,   134,     9,     5,   144,   149,
     151,   140,   150,     6,     7,     8,   105,   146,   147,   113,
     107,   116,   148,   133,   115,    10,   119,    11,    12,    13,
     108,     9,   152,   126,   140,   127,     2,   114,   122,   120,
       3,   125,   121,   100,   153,   145,    47,     2,   106,     5,
      10,     3,    11,    12,    13,     6,     7,     8,     0,    72,
       5,    73,    74,     0,     0,     0,     6,     7,     8,     0,
       0,     0,     0,     9,     0,     0,     0,     0,     0,     0,
      75,    76,     0,     0,     9,     0,     0,     0,    77,    78,
      79,    80,    10,     3,    11,    12,    13,     0,     0,     0,
       0,   138,     5,    10,     0,    11,    12,    13,     6,     7,
       0,     0,     0,     3,     0,     0,     0,     0,     3,    81,
       0,     0,     5,     3,     0,     0,     9,     5,     6,     7,
     139,     0,     5,     6,     7,     8,     0,     5,     6,     7,
       0,     0,     0,     6,     7,    10,     9,    11,    12,    13,
     139,     9,     0,     0,     0,     0,     9,     0,     0,     0,
       0,     9,     0,     0,     0,    10,     0,    11,    12,    13,
      10,     0,    11,    12,    13,    10,     0,    11,    12,    13,
      10,     0,    11,    12,    13,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,     0,     0,    63,     0,     0,
       0,     0,     0,     0,     0,    64,    65
  };

  const short int
  py_parser::yycheck_[] =
  {
      67,    52,     8,     3,    18,    18,     5,    14,    63,    26,
      27,     6,     0,     8,    24,    25,    23,    34,     4,     5,
      33,    44,    45,     9,     7,     8,    37,    13,    14,   123,
     124,    22,    18,    10,    66,    43,    29,    46,    24,    25,
      26,    58,    14,     4,     5,    32,    17,    11,     9,    63,
      64,    65,     9,    14,    23,    22,    42,    18,    63,    32,
      22,   128,    17,    24,    25,    26,    50,   134,   135,    68,
      51,    71,   139,   109,    70,    61,    82,    63,    64,    65,
     131,    42,   149,    94,   151,    96,     5,    69,    85,    83,
       9,    89,    84,    47,   151,    14,    10,     5,    50,    18,
      61,     9,    63,    64,    65,    24,    25,    26,    -1,     9,
      18,    11,    12,    -1,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    42,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    -1,    42,    -1,    -1,    -1,    38,    39,
      40,    41,    61,     9,    63,    64,    65,    -1,    -1,    -1,
      -1,    17,    18,    61,    -1,    63,    64,    65,    24,    25,
      -1,    -1,    -1,     9,    -1,    -1,    -1,    -1,     9,    69,
      -1,    -1,    18,     9,    -1,    -1,    42,    18,    24,    25,
      46,    -1,    18,    24,    25,    26,    -1,    18,    24,    25,
      -1,    -1,    -1,    24,    25,    61,    42,    63,    64,    65,
      46,    42,    -1,    -1,    -1,    -1,    42,    -1,    -1,    -1,
      -1,    42,    -1,    -1,    -1,    61,    -1,    63,    64,    65,
      61,    -1,    63,    64,    65,    61,    -1,    63,    64,    65,
      61,    -1,    63,    64,    65,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    -1,    -1,    59,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    67,    68
  };

  const unsigned char
  py_parser::yystos_[] =
  {
       0,     4,     5,     9,    14,    18,    24,    25,    26,    42,
      61,    63,    64,    65,    71,    72,    77,    78,    79,    80,
      81,    84,    85,    86,    87,    91,    92,    93,    94,    95,
      97,    98,    99,   100,   102,   104,   106,   107,   108,   109,
     115,   116,   117,    63,    94,    86,    97,   115,     0,    73,
      75,    14,    23,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    59,    67,    68,    82,    88,    22,     6,
       8,    10,     9,    11,    12,    30,    31,    38,    39,    40,
      41,    69,    96,    66,    43,    29,    24,    25,   101,   103,
      26,    27,    34,    58,   105,   106,    46,   110,    14,    17,
     110,    13,    14,    74,    76,    77,   116,    79,    78,    32,
      89,    90,    91,    86,    92,    93,    94,    11,     9,    97,
      98,    99,   100,    44,    45,   104,   106,   106,    18,    33,
     111,    23,    83,    85,    22,     7,   102,   102,    17,    46,
      91,   112,   113,   114,    63,    14,    91,    91,    91,    32,
      17,    22,    91,   114
  };

  const unsigned char
  py_parser::yyr1_[] =
  {
       0,    70,    71,    72,    72,    72,    73,    74,    74,    75,
      75,    76,    76,    77,    78,    78,    79,    79,    80,    81,
      81,    82,    82,    83,    84,    85,    85,    86,    86,    87,
      87,    88,    88,    88,    88,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    89,    90,    90,    91,    91,
      92,    92,    93,    93,    94,    94,    95,    95,    96,    96,
      96,    96,    96,    96,    96,    96,    96,    96,    96,    97,
      97,    98,    98,    99,    99,   100,   101,   101,   101,   102,
     102,   103,   103,   104,   104,   105,   105,   105,   105,   106,
     106,   107,   107,   107,   108,   108,   109,   109,   110,   110,
     111,   111,   111,   112,   112,   113,   113,   114,   114,   114,
     115,   115,   115,   115,   116,   117
  };

  const unsigned char
  py_parser::yyr2_[] =
  {
       0,     2,     2,     1,     1,     2,     2,     1,     1,     0,
       2,     1,     1,     5,     1,     1,     1,     3,     1,     3,
       2,     0,     3,     1,     2,     1,     2,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     3,     1,     5,
       1,     3,     1,     3,     2,     1,     1,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     2,     1,
       3,     1,     3,     1,     3,     2,     0,     3,     3,     1,
       3,     1,     1,     1,     3,     1,     1,     1,     1,     2,
       1,     1,     1,     1,     1,     3,     2,     3,     0,     2,
       2,     2,     3,     1,     2,     1,     3,     1,     3,     2,
       3,     1,     1,     1,     1,     2
  };



  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a yyntokens_, nonterminals.
  const char*
  const py_parser::yytname_[] =
  {
  "\"end of file\"", "error", "$undefined", "\":=\"", "DEF", "PASS",
  "\"if\"", "\"else\"", "\"or\"", "\"not\"", "\"and\"", "\"in\"", "\"is\"",
  "ENDMARKER", "NEWLINE", "INDENT", "DEDENT", "\")\"", "\"(\"", "LSQB",
  "RSQB", "\":\"", "\",\"", "\";\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"",
  "VBAR", "\"&\"", "\"<\"", "\">\"", "\"=\"", "\".\"", "\"%\"", "\"`\"",
  "LBRACE", "RBRACE", "\"==\"", "\"!=\"", "\"<=\"", "\">=\"", "\"~\"",
  "\"^\"", "\"<<\"", "\">>\"", "\"**\"", "\"+=\"", "\"-=\"", "\"*=\"",
  "\"/=\"", "\"%=\"", "\"&=\"", "\"|=\"", "\"^=\"", "\"<<=\"", "\">>=\"",
  "\"**+\"", "\"//\"", "\"//=\"", "\"@\"", "\"await\"", "\"async\"",
  "\"name\"", "\"number\"", "\"string\"", "\"|\"", "\"@=\"", "\"**=\"",
  "\"<>\"", "$accept", "unit", "single_input", "file_input",
  "newline_or_stmt", "newline_stmt_seq", "stmt", "simple_stmt",
  "small_stmt", "small_stmt_seq", "pass_stmt", "expr_stmt",
  "assign_rhs_seq", "yeild_expr_or_testlist_star_expr", "star_expr",
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
       0,   156,   156,   164,   165,   166,   172,   177,   178,   184,
     185,   203,   203,   209,   218,   219,   226,   227,   234,   246,
     247,   253,   254,   260,   268,   276,   277,   282,   282,   287,
     288,   295,   295,   295,   295,   295,   295,   295,   295,   295,
     296,   296,   296,   296,   303,   304,   311,   312,   324,   325,
     331,   332,   338,   339,   345,   346,   353,   354,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   380,
     381,   387,   388,   394,   395,   401,   410,   411,   412,   423,
     424,   428,   428,   434,   435,   439,   439,   439,   439,   445,
     446,   450,   450,   450,   456,   457,   463,   464,   470,   471,
     477,   478,   479,   486,   487,   494,   495,   513,   514,   515,
     546,   547,   548,   549,   563,   569
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


#line 4 "py_parser.yy" // lalr1.cc:1167
} // py
#line 1138 "py_parser.cc" // lalr1.cc:1167
#line 577 "py_parser.yy" // lalr1.cc:1168

void py::py_parser::error (const location_type& l,
                          const std::string& m)
{
    //driver.error (l, m);
}
