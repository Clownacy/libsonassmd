// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton implementation for Bison LALR(1) parsers in C++

// Copyright (C) 2002-2015, 2018-2021 Free Software Foundation, Inc.

// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.

// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.

// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.

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

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.


// Take the name prefix into account.
#define yylex   m68kasm_lex



#include "syntactic.h"


// Unqualified %code blocks.
#line 131 "syntactic.y"


#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <initializer_list>

YY_DECL;
void m68kasm_warning(void *scanner, Statement *statement, const char *message);
void m68kasm_warning_pedantic(void *scanner, Statement *statement, const char *message);
void m68kasm_error(void *scanner, Statement *statement, const char *message);

static void DoExpression(Expression &expression, ExpressionType type, const std::initializer_list<Expression> &subexpressions)
{
	expression.type = type;
	expression.shared.emplace<std::vector<Expression>>(subexpressions);
}

void m68kasm::parser::error(const std::string &message)
{
	m68kasm_error(nullptr, nullptr, message.c_str());
}


#line 74 "syntactic.cpp"


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


// Whether we are compiled with exception support.
#ifndef YY_EXCEPTIONS
# if defined __GNUC__ && !defined __EXCEPTIONS
#  define YY_EXCEPTIONS 0
# else
#  define YY_EXCEPTIONS 1
# endif
#endif



// Enable debugging if requested.
#if M68KASM_DEBUG

// A pseudo ostream that takes yydebug_ into account.
# define YYCDEBUG if (yydebug_) (*yycdebug_)

# define YY_SYMBOL_PRINT(Title, Symbol)         \
  do {                                          \
    if (yydebug_)                               \
    {                                           \
      *yycdebug_ << Title << ' ';               \
      yy_print_ (*yycdebug_, Symbol);           \
      *yycdebug_ << '\n';                       \
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
      yy_stack_print_ ();                \
  } while (false)

#else // !M68KASM_DEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !M68KASM_DEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 25 "syntactic.y"
namespace m68kasm {
#line 148 "syntactic.cpp"

  /// Build a parser object.
  parser::parser (void *scanner_yyarg, Statement *statement_yyarg)
#if M68KASM_DEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      statement (statement_yyarg)
  {}

  parser::~parser ()
  {}

  parser::syntax_error::~syntax_error () YY_NOEXCEPT YY_NOTHROW
  {}

  /*---------.
  | symbol.  |
  `---------*/



  // by_state.
  parser::by_state::by_state () YY_NOEXCEPT
    : state (empty_state)
  {}

  parser::by_state::by_state (const by_state& that) YY_NOEXCEPT
    : state (that.state)
  {}

  void
  parser::by_state::clear () YY_NOEXCEPT
  {
    state = empty_state;
  }

  void
  parser::by_state::move (by_state& that)
  {
    state = that.state;
    that.clear ();
  }

  parser::by_state::by_state (state_type s) YY_NOEXCEPT
    : state (s)
  {}

  parser::symbol_kind_type
  parser::by_state::kind () const YY_NOEXCEPT
  {
    if (state == empty_state)
      return symbol_kind::S_YYEMPTY;
    else
      return YY_CAST (symbol_kind_type, yystos_[+state]);
  }

  parser::stack_symbol_type::stack_symbol_type ()
  {}

  parser::stack_symbol_type::stack_symbol_type (YY_RVREF (stack_symbol_type) that)
    : super_type (YY_MOVE (that.state))
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
        value.YY_MOVE_OR_COPY< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_size: // size
        value.YY_MOVE_OR_COPY< Size > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
        value.YY_MOVE_OR_COPY< String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.YY_MOVE_OR_COPY< unsigned long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

#if 201103L <= YY_CPLUSPLUS
    // that is emptied.
    that.state = empty_state;
#endif
  }

  parser::stack_symbol_type::stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) that)
    : super_type (s)
  {
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
        value.move< Expression > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_size: // size
        value.move< Size > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
        value.move< String > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<Expression> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< unsigned long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

    // that is emptied.
    that.kind_ = symbol_kind::S_YYEMPTY;
  }

#if YY_CPLUSPLUS < 201103L
  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (const stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
        value.copy< Expression > (that.value);
        break;

      case symbol_kind::S_size: // size
        value.copy< Size > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
        value.copy< String > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::vector<Expression> > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.copy< unsigned long > (that.value);
        break;

      default:
        break;
    }

    return *this;
  }

  parser::stack_symbol_type&
  parser::stack_symbol_type::operator= (stack_symbol_type& that)
  {
    state = that.state;
    switch (that.kind ())
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
        value.move< Expression > (that.value);
        break;

      case symbol_kind::S_size: // size
        value.move< Size > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
        value.move< String > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<Expression> > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        value.move< unsigned long > (that.value);
        break;

      default:
        break;
    }

    // that is emptied.
    that.state = empty_state;
    return *this;
  }
#endif

  template <typename Base>
  void
  parser::yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const
  {
    if (yymsg)
      YY_SYMBOL_PRINT (yymsg, yysym);
  }

#if M68KASM_DEBUG
  template <typename Base>
  void
  parser::yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const
  {
    std::ostream& yyoutput = yyo;
    YY_USE (yyoutput);
    if (yysym.empty ())
      yyo << "empty symbol";
    else
      {
        symbol_kind_type yykind = yysym.kind ();
        yyo << (yykind < YYNTOKENS ? "token" : "nterm")
            << ' ' << yysym.name () << " (";
        YY_USE (yykind);
        yyo << ')';
      }
  }
#endif

  void
  parser::yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym)
  {
    if (m)
      YY_SYMBOL_PRINT (m, sym);
    yystack_.push (YY_MOVE (sym));
  }

  void
  parser::yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym)
  {
#if 201103L <= YY_CPLUSPLUS
    yypush_ (m, stack_symbol_type (s, std::move (sym)));
#else
    stack_symbol_type ss (s, sym);
    yypush_ (m, ss);
#endif
  }

  void
  parser::yypop_ (int n) YY_NOEXCEPT
  {
    yystack_.pop (n);
  }

#if M68KASM_DEBUG
  std::ostream&
  parser::debug_stream () const
  {
    return *yycdebug_;
  }

  void
  parser::set_debug_stream (std::ostream& o)
  {
    yycdebug_ = &o;
  }


  parser::debug_level_type
  parser::debug_level () const
  {
    return yydebug_;
  }

  void
  parser::set_debug_level (debug_level_type l)
  {
    yydebug_ = l;
  }
#endif // M68KASM_DEBUG

  parser::state_type
  parser::yy_lr_goto_state_ (state_type yystate, int yysym)
  {
    int yyr = yypgoto_[yysym - YYNTOKENS] + yystate;
    if (0 <= yyr && yyr <= yylast_ && yycheck_[yyr] == yystate)
      return yytable_[yyr];
    else
      return yydefgoto_[yysym - YYNTOKENS];
  }

  bool
  parser::yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yypact_ninf_;
  }

  bool
  parser::yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT
  {
    return yyvalue == yytable_ninf_;
  }

  int
  parser::operator() ()
  {
    return parse ();
  }

  int
  parser::parse ()
  {
    int yyn;
    /// Length of the RHS of the rule being reduced.
    int yylen = 0;

    // Error handling.
    int yynerrs_ = 0;
    int yyerrstatus_ = 0;

    /// The lookahead symbol.
    symbol_type yyla;

    /// The return value of parse ().
    int yyresult;

#if YY_EXCEPTIONS
    try
#endif // YY_EXCEPTIONS
      {
    YYCDEBUG << "Starting parse\n";


    /* Initialize the stack.  The initial state will be set in
       yynewstate, since the latter expects the semantical and the
       location values to have been already stored, initialize these
       stacks with a primary value.  */
    yystack_.clear ();
    yypush_ (YY_NULLPTR, 0, YY_MOVE (yyla));

  /*-----------------------------------------------.
  | yynewstate -- push a new symbol on the stack.  |
  `-----------------------------------------------*/
  yynewstate:
    YYCDEBUG << "Entering state " << int (yystack_[0].state) << '\n';
    YY_STACK_PRINT ();

    // Accept?
    if (yystack_[0].state == yyfinal_)
      YYACCEPT;

    goto yybackup;


  /*-----------.
  | yybackup.  |
  `-----------*/
  yybackup:
    // Try to take a decision without lookahead.
    yyn = yypact_[+yystack_[0].state];
    if (yy_pact_value_is_default_ (yyn))
      goto yydefault;

    // Read a lookahead token.
    if (yyla.empty ())
      {
        YYCDEBUG << "Reading a token\n";
#if YY_EXCEPTIONS
        try
#endif // YY_EXCEPTIONS
          {
            symbol_type yylookahead (yylex (scanner));
            yyla.move (yylookahead);
          }
#if YY_EXCEPTIONS
        catch (const syntax_error& yyexc)
          {
            YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
            error (yyexc);
            goto yyerrlab1;
          }
#endif // YY_EXCEPTIONS
      }
    YY_SYMBOL_PRINT ("Next token is", yyla);

    if (yyla.kind () == symbol_kind::S_YYerror)
    {
      // The scanner already issued an error message, process directly
      // to error recovery.  But do not keep the error token as
      // lookahead, it is too special and may lead us to an endless
      // loop in error recovery. */
      yyla.kind_ = symbol_kind::S_YYUNDEF;
      goto yyerrlab1;
    }

    /* If the proper action on seeing token YYLA.TYPE is to reduce or
       to detect an error, take that action.  */
    yyn += yyla.kind ();
    if (yyn < 0 || yylast_ < yyn || yycheck_[yyn] != yyla.kind ())
      {
        goto yydefault;
      }

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
    yypush_ ("Shifting", state_type (yyn), YY_MOVE (yyla));
    goto yynewstate;


  /*-----------------------------------------------------------.
  | yydefault -- do the default action for the current state.  |
  `-----------------------------------------------------------*/
  yydefault:
    yyn = yydefact_[+yystack_[0].state];
    if (yyn == 0)
      goto yyerrlab;
    goto yyreduce;


  /*-----------------------------.
  | yyreduce -- do a reduction.  |
  `-----------------------------*/
  yyreduce:
    yylen = yyr2_[yyn];
    {
      stack_symbol_type yylhs;
      yylhs.state = yy_lr_goto_state_ (yystack_[yylen].state, yyr1_[yyn]);
      /* Variants are always initialized to an empty instance of the
         correct type. The default '$$ = $1' action is NOT applied
         when using variants.  */
      switch (yyr1_[yyn])
    {
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
        yylhs.value.emplace< Expression > ();
        break;

      case symbol_kind::S_size: // size
        yylhs.value.emplace< Size > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
        yylhs.value.emplace< String > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< std::vector<Expression> > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
        yylhs.value.emplace< unsigned long > ();
        break;

      default:
        break;
    }



      // Perform the reduction.
      YY_REDUCE_PRINT (yyn);
#if YY_EXCEPTIONS
      try
#endif // YY_EXCEPTIONS
        {
          switch (yyn)
            {
  case 2: // statement: %empty
#line 206 "syntactic.y"
        {
		statement->type = STATEMENT_TYPE_EMPTY;
	}
#line 678 "syntactic.cpp"
    break;

  case 3: // statement: DIRECTIVE_DC size expression_list
#line 210 "syntactic.y"
        {
		statement->type = STATEMENT_TYPE_DC;
		statement->shared.emplace<StatementDc>(yystack_[1].value.as < Size > (), std::move(yystack_[0].value.as < std::vector<Expression> > ()));
	}
#line 687 "syntactic.cpp"
    break;

  case 4: // statement: DIRECTIVE_EVEN
#line 215 "syntactic.y"
        {
		statement->type = STATEMENT_TYPE_EVEN;
	}
#line 695 "syntactic.cpp"
    break;

  case 5: // expression_list: expression
#line 222 "syntactic.y"
        {
		yylhs.value.as < std::vector<Expression> > ().emplace_back(std::move(yystack_[0].value.as < Expression > ()));
	}
#line 703 "syntactic.cpp"
    break;

  case 6: // expression_list: expression_list "," expression
#line 226 "syntactic.y"
        {
		yylhs.value.as < std::vector<Expression> > () = std::move(yystack_[2].value.as < std::vector<Expression> > ());
		yylhs.value.as < std::vector<Expression> > ().emplace_back(std::move(yystack_[0].value.as < Expression > ()));
	}
#line 712 "syntactic.cpp"
    break;

  case 7: // size: SIZE_BYTE
#line 234 "syntactic.y"
        {
		yylhs.value.as < Size > () = SIZE_BYTE;
	}
#line 720 "syntactic.cpp"
    break;

  case 8: // size: SIZE_SHORT
#line 238 "syntactic.y"
        {
		yylhs.value.as < Size > () = SIZE_SHORT;
	}
#line 728 "syntactic.cpp"
    break;

  case 9: // size: SIZE_WORD
#line 242 "syntactic.y"
        {
		yylhs.value.as < Size > () = SIZE_WORD;
	}
#line 736 "syntactic.cpp"
    break;

  case 10: // size: SIZE_LONGWORD
#line 246 "syntactic.y"
        {
		yylhs.value.as < Size > () = SIZE_LONGWORD;
	}
#line 744 "syntactic.cpp"
    break;

  case 11: // expression: expression1
#line 259 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 752 "syntactic.cpp"
    break;

  case 12: // expression: expression LOGICAL_AND expression1
#line 264 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_LOGICAL_AND, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 760 "syntactic.cpp"
    break;

  case 13: // expression: expression LOGICAL_OR expression1
#line 269 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_LOGICAL_OR, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 768 "syntactic.cpp"
    break;

  case 14: // expression1: expression2
#line 276 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 776 "syntactic.cpp"
    break;

  case 15: // expression1: expression1 "=" expression2
#line 280 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_EQUALITY, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 784 "syntactic.cpp"
    break;

  case 16: // expression1: expression1 EQUALITY expression2
#line 284 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_EQUALITY, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 792 "syntactic.cpp"
    break;

  case 17: // expression1: expression1 INEQUALITY expression2
#line 288 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_INEQUALITY, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 800 "syntactic.cpp"
    break;

  case 18: // expression2: expression3
#line 295 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 808 "syntactic.cpp"
    break;

  case 19: // expression2: expression2 "<" expression3
#line 299 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_LESS_THAN, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 816 "syntactic.cpp"
    break;

  case 20: // expression2: expression2 LESS_OR_EQUAL expression3
#line 303 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_LESS_OR_EQUAL, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 824 "syntactic.cpp"
    break;

  case 21: // expression2: expression2 ">" expression3
#line 307 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_MORE_THAN, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 832 "syntactic.cpp"
    break;

  case 22: // expression2: expression2 MORE_OR_EQUAL expression3
#line 311 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_MORE_OR_EQUAL, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 840 "syntactic.cpp"
    break;

  case 23: // expression3: expression4
#line 318 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 848 "syntactic.cpp"
    break;

  case 24: // expression3: expression3 "+" expression4
#line 322 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_ADD, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 856 "syntactic.cpp"
    break;

  case 25: // expression3: expression3 "-" expression4
#line 326 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_SUBTRACT, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 864 "syntactic.cpp"
    break;

  case 26: // expression4: expression5
#line 333 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 872 "syntactic.cpp"
    break;

  case 27: // expression4: expression4 "*" expression5
#line 337 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_MULTIPLY, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 880 "syntactic.cpp"
    break;

  case 28: // expression4: expression4 "/" expression5
#line 341 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_DIVIDE, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 888 "syntactic.cpp"
    break;

  case 29: // expression4: expression4 "%" expression5
#line 345 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_MODULO, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 896 "syntactic.cpp"
    break;

  case 30: // expression5: expression6
#line 352 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 904 "syntactic.cpp"
    break;

  case 31: // expression5: expression5 "&" expression6
#line 356 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_BITWISE_AND, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 912 "syntactic.cpp"
    break;

  case 32: // expression5: expression5 "!" expression6
#line 360 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_BITWISE_OR, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 920 "syntactic.cpp"
    break;

  case 33: // expression5: expression5 "|" expression6
#line 364 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_BITWISE_OR, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 928 "syntactic.cpp"
    break;

  case 34: // expression5: expression5 "^" expression6
#line 368 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_BITWISE_XOR, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 936 "syntactic.cpp"
    break;

  case 35: // expression6: expression7
#line 375 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 944 "syntactic.cpp"
    break;

  case 36: // expression6: expression6 LEFT_SHIFT expression7
#line 379 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_LEFT_SHIFT, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 952 "syntactic.cpp"
    break;

  case 37: // expression6: expression6 RIGHT_SHIFT expression7
#line 383 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_RIGHT_SHIFT, {std::move(yystack_[2].value.as < Expression > ()), std::move(yystack_[0].value.as < Expression > ())});
	}
#line 960 "syntactic.cpp"
    break;

  case 38: // expression7: expression8
#line 390 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 968 "syntactic.cpp"
    break;

  case 39: // expression7: "+" expression7
#line 394 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[0].value.as < Expression > ();
	}
#line 976 "syntactic.cpp"
    break;

  case 40: // expression7: "-" expression7
#line 398 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_NEGATE, {std::move(yystack_[0].value.as < Expression > ())});
	}
#line 984 "syntactic.cpp"
    break;

  case 41: // expression7: "~" expression7
#line 402 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_BITWISE_NOT, {std::move(yystack_[0].value.as < Expression > ())});
	}
#line 992 "syntactic.cpp"
    break;

  case 42: // expression7: "!" expression7
#line 407 "syntactic.y"
        {
		DoExpression(yylhs.value.as < Expression > (), EXPRESSION_LOGICAL_NOT, {std::move(yystack_[0].value.as < Expression > ())});
	}
#line 1000 "syntactic.cpp"
    break;

  case 43: // expression8: NUMBER
#line 414 "syntactic.y"
        {
		yylhs.value.as < Expression > ().type = EXPRESSION_NUMBER;
		yylhs.value.as < Expression > ().shared.emplace<unsigned long>(yystack_[0].value.as < unsigned long > ());
	}
#line 1009 "syntactic.cpp"
    break;

  case 44: // expression8: "(" expression ")"
#line 419 "syntactic.y"
        {
		yylhs.value.as < Expression > () = yystack_[1].value.as < Expression > ();
	}
#line 1017 "syntactic.cpp"
    break;


#line 1021 "syntactic.cpp"

            default:
              break;
            }
        }
#if YY_EXCEPTIONS
      catch (const syntax_error& yyexc)
        {
          YYCDEBUG << "Caught exception: " << yyexc.what() << '\n';
          error (yyexc);
          YYERROR;
        }
#endif // YY_EXCEPTIONS
      YY_SYMBOL_PRINT ("-> $$ =", yylhs);
      yypop_ (yylen);
      yylen = 0;

      // Shift the result of the reduction.
      yypush_ (YY_NULLPTR, YY_MOVE (yylhs));
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
        context yyctx (*this, yyla);
        std::string msg = yysyntax_error_ (yyctx);
        error (YY_MOVE (msg));
      }


    if (yyerrstatus_ == 3)
      {
        /* If just tried and failed to reuse lookahead token after an
           error, discard it.  */

        // Return failure if at end of input.
        if (yyla.kind () == symbol_kind::S_YYEOF)
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
    /* Pacify compilers when the user code never invokes YYERROR and
       the label yyerrorlab therefore never appears in user code.  */
    if (false)
      YYERROR;

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYERROR.  */
    yypop_ (yylen);
    yylen = 0;
    YY_STACK_PRINT ();
    goto yyerrlab1;


  /*-------------------------------------------------------------.
  | yyerrlab1 -- common code for both syntax error and YYERROR.  |
  `-------------------------------------------------------------*/
  yyerrlab1:
    yyerrstatus_ = 3;   // Each real token shifted decrements this.
    // Pop stack until we find a state that shifts the error token.
    for (;;)
      {
        yyn = yypact_[+yystack_[0].state];
        if (!yy_pact_value_is_default_ (yyn))
          {
            yyn += symbol_kind::S_YYerror;
            if (0 <= yyn && yyn <= yylast_
                && yycheck_[yyn] == symbol_kind::S_YYerror)
              {
                yyn = yytable_[yyn];
                if (0 < yyn)
                  break;
              }
          }

        // Pop the current state because it cannot handle the error token.
        if (yystack_.size () == 1)
          YYABORT;

        yy_destroy_ ("Error: popping", yystack_[0]);
        yypop_ ();
        YY_STACK_PRINT ();
      }
    {
      stack_symbol_type error_token;


      // Shift the error token.
      error_token.state = state_type (yyn);
      yypush_ ("Shifting", YY_MOVE (error_token));
    }
    goto yynewstate;


  /*-------------------------------------.
  | yyacceptlab -- YYACCEPT comes here.  |
  `-------------------------------------*/
  yyacceptlab:
    yyresult = 0;
    goto yyreturn;


  /*-----------------------------------.
  | yyabortlab -- YYABORT comes here.  |
  `-----------------------------------*/
  yyabortlab:
    yyresult = 1;
    goto yyreturn;


  /*-----------------------------------------------------.
  | yyreturn -- parsing is finished, return the result.  |
  `-----------------------------------------------------*/
  yyreturn:
    if (!yyla.empty ())
      yy_destroy_ ("Cleanup: discarding lookahead", yyla);

    /* Do not reclaim the symbols of the rule whose action triggered
       this YYABORT or YYACCEPT.  */
    yypop_ (yylen);
    YY_STACK_PRINT ();
    while (1 < yystack_.size ())
      {
        yy_destroy_ ("Cleanup: popping", yystack_[0]);
        yypop_ ();
      }

    return yyresult;
  }
#if YY_EXCEPTIONS
    catch (...)
      {
        YYCDEBUG << "Exception caught: cleaning lookahead and stack\n";
        // Do not try to display the values of the reclaimed symbols,
        // as their printers might throw an exception.
        if (!yyla.empty ())
          yy_destroy_ (YY_NULLPTR, yyla);

        while (1 < yystack_.size ())
          {
            yy_destroy_ (YY_NULLPTR, yystack_[0]);
            yypop_ ();
          }
        throw;
      }
#endif // YY_EXCEPTIONS
  }

  void
  parser::error (const syntax_error& yyexc)
  {
    error (yyexc.what ());
  }

  /* Return YYSTR after stripping away unnecessary quotes and
     backslashes, so that it's suitable for yyerror.  The heuristic is
     that double-quoting is unnecessary unless the string contains an
     apostrophe, a comma, or backslash (other than backslash-backslash).
     YYSTR is taken from yytname.  */
  std::string
  parser::yytnamerr_ (const char *yystr)
  {
    if (*yystr == '"')
      {
        std::string yyr;
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
              else
                goto append;

            append:
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

  std::string
  parser::symbol_name (symbol_kind_type yysymbol)
  {
    return yytnamerr_ (yytname_[yysymbol]);
  }



  // parser::context.
  parser::context::context (const parser& yyparser, const symbol_type& yyla)
    : yyparser_ (yyparser)
    , yyla_ (yyla)
  {}

  int
  parser::context::expected_tokens (symbol_kind_type yyarg[], int yyargn) const
  {
    // Actual number of expected tokens
    int yycount = 0;

    const int yyn = yypact_[+yyparser_.yystack_[0].state];
    if (!yy_pact_value_is_default_ (yyn))
      {
        /* Start YYX at -YYN if negative to avoid negative indexes in
           YYCHECK.  In other words, skip the first -YYN actions for
           this state because they are default actions.  */
        const int yyxbegin = yyn < 0 ? -yyn : 0;
        // Stay within bounds of both yycheck and yytname.
        const int yychecklim = yylast_ - yyn + 1;
        const int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
        for (int yyx = yyxbegin; yyx < yyxend; ++yyx)
          if (yycheck_[yyx + yyn] == yyx && yyx != symbol_kind::S_YYerror
              && !yy_table_value_is_error_ (yytable_[yyx + yyn]))
            {
              if (!yyarg)
                ++yycount;
              else if (yycount == yyargn)
                return 0;
              else
                yyarg[yycount++] = YY_CAST (symbol_kind_type, yyx);
            }
      }

    if (yyarg && yycount == 0 && 0 < yyargn)
      yyarg[0] = symbol_kind::S_YYEMPTY;
    return yycount;
  }






  int
  parser::yy_syntax_error_arguments_ (const context& yyctx,
                                                 symbol_kind_type yyarg[], int yyargn) const
  {
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
         scanner and before detecting a syntax error.  Thus, state merging
         (from LALR or IELR) and default reductions corrupt the expected
         token list.  However, the list is correct for canonical LR with
         one exception: it will still contain any token that will not be
         accepted due to an error action in a later state.
    */

    if (!yyctx.lookahead ().empty ())
      {
        if (yyarg)
          yyarg[0] = yyctx.token ();
        int yyn = yyctx.expected_tokens (yyarg ? yyarg + 1 : yyarg, yyargn - 1);
        return yyn + 1;
      }
    return 0;
  }

  // Generate an error message.
  std::string
  parser::yysyntax_error_ (const context& yyctx) const
  {
    // Its maximum.
    enum { YYARGS_MAX = 5 };
    // Arguments of yyformat.
    symbol_kind_type yyarg[YYARGS_MAX];
    int yycount = yy_syntax_error_arguments_ (yyctx, yyarg, YYARGS_MAX);

    char const* yyformat = YY_NULLPTR;
    switch (yycount)
      {
#define YYCASE_(N, S)                         \
        case N:                               \
          yyformat = S;                       \
        break
      default: // Avoid compiler warnings.
        YYCASE_ (0, YY_("syntax error"));
        YYCASE_ (1, YY_("syntax error, unexpected %s"));
        YYCASE_ (2, YY_("syntax error, unexpected %s, expecting %s"));
        YYCASE_ (3, YY_("syntax error, unexpected %s, expecting %s or %s"));
        YYCASE_ (4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
        YYCASE_ (5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
      }

    std::string yyres;
    // Argument number.
    std::ptrdiff_t yyi = 0;
    for (char const* yyp = yyformat; *yyp; ++yyp)
      if (yyp[0] == '%' && yyp[1] == 's' && yyi < yycount)
        {
          yyres += symbol_name (yyarg[yyi++]);
          ++yyp;
        }
      else
        yyres += *yyp;
    return yyres;
  }


  const signed char parser::yypact_ninf_ = -19;

  const signed char parser::yytable_ninf_ = -1;

  const signed char
  parser::yypact_[] =
  {
      15,    29,   -19,    16,   -19,   -19,   -19,   -19,    -5,   -19,
     -19,    -5,    -5,    -5,    -5,    -5,   -15,    19,    -3,    -9,
      30,   -18,     6,    39,   -19,   -19,     1,   -19,   -19,   -19,
     -19,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,    -5,
      -5,    -5,   -19,    19,    -3,    -3,    -9,    -9,    -9,    30,
      30,    30,    30,   -18,   -18,     6,     6,     6,    39,    39,
      39,    39,   -19,   -19
  };

  const signed char
  parser::yydefact_[] =
  {
       2,     0,     4,     0,     7,     8,     9,    10,     0,     1,
      43,     0,     0,     0,     0,     0,     3,     5,    11,    14,
      18,    23,    26,    30,    35,    38,     0,    39,    40,    42,
      41,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    44,     6,    12,    13,    16,    17,    15,    20,
      22,    19,    21,    24,    25,    27,    28,    29,    31,    32,
      33,    34,    36,    37
  };

  const signed char
  parser::yypgoto_[] =
  {
     -19,   -19,   -19,   -19,    -6,    27,    -7,     7,    20,     9,
       2,   -12,   -19
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,    16,     8,    17,    18,    19,    20,    21,    22,
      23,    24,    25
  };

  const signed char
  parser::yytable_[] =
  {
      27,    28,    29,    30,    10,    26,    31,    37,    38,    43,
      44,    34,    35,    32,    33,    45,     9,    11,     1,     2,
      12,    13,    39,    40,    52,    53,    36,    56,    57,    58,
      14,    32,    33,    15,     4,     5,     6,     7,    72,    73,
      46,    47,    48,    49,    59,    60,    61,    62,    68,    69,
      70,    71,    65,    66,    67,    41,    42,    50,    51,    54,
      55,    63,    64
  };

  const signed char
  parser::yycheck_[] =
  {
      12,    13,    14,    15,     9,    11,    21,    16,    17,    27,
      28,    14,    15,    12,    13,    33,     0,    22,     3,     4,
      25,    26,    31,    32,    23,    31,    29,    34,    35,    36,
      35,    12,    13,    38,     5,     6,     7,     8,    50,    51,
      34,    35,    36,    37,    37,    38,    39,    40,    46,    47,
      48,    49,    43,    44,    45,    25,    26,    18,    19,    32,
      33,    41,    42
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     4,    40,     5,     6,     7,     8,    42,     0,
       9,    22,    25,    26,    35,    38,    41,    43,    44,    45,
      46,    47,    48,    49,    50,    51,    43,    50,    50,    50,
      50,    21,    12,    13,    14,    15,    29,    16,    17,    31,
      32,    25,    26,    27,    28,    33,    34,    35,    36,    37,
      18,    19,    23,    43,    44,    44,    45,    45,    45,    46,
      46,    46,    46,    47,    47,    48,    48,    48,    49,    49,
      49,    49,    50,    50
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    39,    40,    40,    40,    41,    41,    42,    42,    42,
      42,    43,    43,    43,    44,    44,    44,    44,    45,    45,
      45,    45,    45,    46,    46,    46,    47,    47,    47,    47,
      48,    48,    48,    48,    48,    49,    49,    49,    50,    50,
      50,    50,    50,    51,    51
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     0,     3,     1,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     2,
       2,     2,     2,     1,     3
  };


#if M68KASM_DEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DIRECTIVE_DC",
  "DIRECTIVE_EVEN", "SIZE_BYTE", "SIZE_SHORT", "SIZE_WORD",
  "SIZE_LONGWORD", "NUMBER", "IDENTIFIER", "LOCAL_IDENTIFIER",
  "LOGICAL_AND", "LOGICAL_OR", "EQUALITY", "INEQUALITY", "LESS_OR_EQUAL",
  "MORE_OR_EQUAL", "LEFT_SHIFT", "RIGHT_SHIFT", "\".\"", "\",\"", "\"(\"",
  "\")\"", "\"$\"", "\"+\"", "\"-\"", "\"*\"", "\"/\"", "\"=\"", "\"@\"",
  "\"<\"", "\">\"", "\"%\"", "\"&\"", "\"!\"", "\"|\"", "\"^\"", "\"~\"",
  "$accept", "statement", "expression_list", "size", "expression",
  "expression1", "expression2", "expression3", "expression4",
  "expression5", "expression6", "expression7", "expression8", YY_NULLPTR
  };
#endif


#if M68KASM_DEBUG
  const short
  parser::yyrline_[] =
  {
       0,   206,   206,   209,   214,   221,   225,   233,   237,   241,
     245,   258,   263,   268,   275,   279,   283,   287,   294,   298,
     302,   306,   310,   317,   321,   325,   332,   336,   340,   344,
     351,   355,   359,   363,   367,   374,   378,   382,   389,   393,
     397,   401,   406,   413,   418
  };

  void
  parser::yy_stack_print_ () const
  {
    *yycdebug_ << "Stack now";
    for (stack_type::const_iterator
           i = yystack_.begin (),
           i_end = yystack_.end ();
         i != i_end; ++i)
      *yycdebug_ << ' ' << int (i->state);
    *yycdebug_ << '\n';
  }

  void
  parser::yy_reduce_print_ (int yyrule) const
  {
    int yylno = yyrline_[yyrule];
    int yynrhs = yyr2_[yyrule];
    // Print the symbols being reduced, and their result.
    *yycdebug_ << "Reducing stack by rule " << yyrule - 1
               << " (line " << yylno << "):\n";
    // The symbols being reduced.
    for (int yyi = 0; yyi < yynrhs; yyi++)
      YY_SYMBOL_PRINT ("   $" << yyi + 1 << " =",
                       yystack_[(yynrhs) - (yyi + 1)]);
  }
#endif // M68KASM_DEBUG


#line 25 "syntactic.y"
} // m68kasm
#line 1532 "syntactic.cpp"

#line 424 "syntactic.y"

