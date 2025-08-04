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
#define yylex   libsonassmd_code_reader_yylex



#include "syntactic.h"


// Unqualified %code blocks.
#line 76 "syntactic.y"


#include <initializer_list>

YY_DECL;
void libsonassmd_yyerror(const std::string &message);

void libsonassmd::CodeReader::parser::error(const std::string &message)
{
	libsonassmd_yyerror(message);
}


#line 62 "syntactic.cpp"


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
#if LIBSONASSMD_CODE_READER_YYDEBUG

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

#else // !LIBSONASSMD_CODE_READER_YYDEBUG

# define YYCDEBUG if (false) std::cerr
# define YY_SYMBOL_PRINT(Title, Symbol)  YY_USE (Symbol)
# define YY_REDUCE_PRINT(Rule)           static_cast<void> (0)
# define YY_STACK_PRINT()                static_cast<void> (0)

#endif // !LIBSONASSMD_CODE_READER_YYDEBUG

#define yyerrok         (yyerrstatus_ = 0)
#define yyclearin       (yyla.clear ())

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYRECOVERING()  (!!yyerrstatus_)

#line 24 "syntactic.y"
namespace libsonassmd { namespace CodeReader {
#line 136 "syntactic.cpp"

  /// Build a parser object.
  parser::parser (void *scanner_yyarg, Mappings &mappings_yyarg, Game game_yyarg)
#if LIBSONASSMD_CODE_READER_YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      scanner (scanner_yyarg),
      mappings (mappings_yyarg),
      game (game_yyarg)
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
      case symbol_kind::S_mappings: // mappings
        value.YY_MOVE_OR_COPY< Mappings > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.YY_MOVE_OR_COPY< Size > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.YY_MOVE_OR_COPY< SpriteFrame > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.YY_MOVE_OR_COPY< SpritePiece > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
        value.YY_MOVE_OR_COPY< StringList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
        value.YY_MOVE_OR_COPY< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bytes: // bytes
        value.YY_MOVE_OR_COPY< std::stringstream > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.YY_MOVE_OR_COPY< std::vector<unsigned long> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
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
      case symbol_kind::S_mappings: // mappings
        value.move< Mappings > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.move< Size > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.move< SpriteFrame > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.move< SpritePiece > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
        value.move< StringList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
        value.move< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bytes: // bytes
        value.move< std::stringstream > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<unsigned long> > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
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
      case symbol_kind::S_mappings: // mappings
        value.copy< Mappings > (that.value);
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.copy< Size > (that.value);
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.copy< SpriteFrame > (that.value);
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.copy< SpritePiece > (that.value);
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
        value.copy< StringList > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
        value.copy< std::string > (that.value);
        break;

      case symbol_kind::S_bytes: // bytes
        value.copy< std::stringstream > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::vector<unsigned long> > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
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
      case symbol_kind::S_mappings: // mappings
        value.move< Mappings > (that.value);
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.move< Size > (that.value);
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.move< SpriteFrame > (that.value);
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.move< SpritePiece > (that.value);
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
        value.move< StringList > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
        value.move< std::string > (that.value);
        break;

      case symbol_kind::S_bytes: // bytes
        value.move< std::stringstream > (that.value);
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<unsigned long> > (that.value);
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
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

#if LIBSONASSMD_CODE_READER_YYDEBUG
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

#if LIBSONASSMD_CODE_READER_YYDEBUG
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
#endif // LIBSONASSMD_CODE_READER_YYDEBUG

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
      case symbol_kind::S_mappings: // mappings
        yylhs.value.emplace< Mappings > ();
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        yylhs.value.emplace< Size > ();
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        yylhs.value.emplace< SpriteFrame > ();
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        yylhs.value.emplace< SpritePiece > ();
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
        yylhs.value.emplace< StringList > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
        yylhs.value.emplace< std::string > ();
        break;

      case symbol_kind::S_bytes: // bytes
        yylhs.value.emplace< std::stringstream > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        yylhs.value.emplace< std::vector<unsigned long> > ();
        break;

      case symbol_kind::S_NUMBER: // NUMBER
      case symbol_kind::S_expression: // expression
      case symbol_kind::S_expression1: // expression1
      case symbol_kind::S_expression2: // expression2
      case symbol_kind::S_expression3: // expression3
      case symbol_kind::S_expression4: // expression4
      case symbol_kind::S_expression5: // expression5
      case symbol_kind::S_expression6: // expression6
      case symbol_kind::S_expression7: // expression7
      case symbol_kind::S_expression8: // expression8
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
  case 2: // output: mappings
#line 151 "syntactic.y"
        {
		mappings = std::move(yystack_[0].value.as < Mappings > ());
	}
#line 772 "syntactic.cpp"
    break;

  case 3: // mappings: offset_table
#line 158 "syntactic.y"
        {
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 782 "syntactic.cpp"
    break;

  case 4: // mappings: labels offset_table
#line 164 "syntactic.y"
        {
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 790 "syntactic.cpp"
    break;

  case 5: // mappings: labels bytes
#line 168 "syntactic.y"
        {
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > (), game);
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 802 "syntactic.cpp"
    break;

  case 6: // mappings: labels SPRITE_HEADER sprite_frame IDENTIFIER
#line 176 "syntactic.y"
        {
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 811 "syntactic.cpp"
    break;

  case 7: // mappings: mappings labels offset_table
#line 181 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 820 "syntactic.cpp"
    break;

  case 8: // mappings: mappings labels bytes
#line 186 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		// TODO: Catch exceptions?
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > (), game);
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 832 "syntactic.cpp"
    break;

  case 9: // mappings: mappings labels SPRITE_HEADER sprite_frame IDENTIFIER
#line 194 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[4].value.as < Mappings > ());
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 842 "syntactic.cpp"
    break;

  case 10: // label: IDENTIFIER ":"
#line 203 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[1].value.as < std::string > ());
	}
#line 850 "syntactic.cpp"
    break;

  case 11: // labels: label
#line 210 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 858 "syntactic.cpp"
    break;

  case 12: // labels: labels label
#line 214 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 867 "syntactic.cpp"
    break;

  case 13: // offset_table: offset_table_entry
#line 222 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 875 "syntactic.cpp"
    break;

  case 14: // offset_table: offset_table offset_table_entry
#line 226 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 884 "syntactic.cpp"
    break;

  case 15: // offset_table: MAPPINGS_TABLE
#line 231 "syntactic.y"
        {}
#line 890 "syntactic.cpp"
    break;

  case 16: // sprite_piece: SPRITE_PIECE expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression
#line 236 "syntactic.y"
        {
		yylhs.value.as < SpritePiece > ().x = yystack_[16].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().y = yystack_[14].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().width = yystack_[12].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().height = yystack_[10].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().tile_index = yystack_[8].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().x_flip = yystack_[6].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().y_flip = yystack_[4].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().palette_line = yystack_[2].value.as < unsigned long > ();
		yylhs.value.as < SpritePiece > ().priority = yystack_[0].value.as < unsigned long > ();
	}
#line 906 "syntactic.cpp"
    break;

  case 17: // sprite_frame: sprite_piece
#line 251 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 914 "syntactic.cpp"
    break;

  case 18: // sprite_frame: sprite_frame sprite_piece
#line 255 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > () = std::move(yystack_[1].value.as < SpriteFrame > ());
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 923 "syntactic.cpp"
    break;

  case 19: // dc: DIRECTIVE_DC size
#line 263 "syntactic.y"
        {
		yylhs.value.as < Size > () = yystack_[0].value.as < Size > ();
	}
#line 931 "syntactic.cpp"
    break;

  case 20: // offset_table_entry: dc IDENTIFIER "-" IDENTIFIER
#line 270 "syntactic.y"
        {
		static_cast<void>(yystack_[0].value.as < std::string > ());
		yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());
	}
#line 940 "syntactic.cpp"
    break;

  case 21: // offset_table_entry: MAPPINGS_TABLE_ENTRY size IDENTIFIER
#line 275 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 948 "syntactic.cpp"
    break;

  case 22: // bytes: dc expression_list
#line 282 "syntactic.y"
        {
		for (const auto &value : yystack_[0].value.as < std::vector<unsigned long> > ())
		{
			switch (yystack_[1].value.as < Size > ())
			{
				case Size::BYTE:
					libsonassmd::WriteU8(yylhs.value.as < std::stringstream > (), value);
					break;

				case Size::SHORT:
				case Size::WORD:
					libsonassmd::WriteU16BE(yylhs.value.as < std::stringstream > (), value);
					break;

				case Size::LONGWORD:
					libsonassmd::WriteU32BE(yylhs.value.as < std::stringstream > (), value);
					break;
			}
		}
	}
#line 973 "syntactic.cpp"
    break;

  case 23: // bytes: bytes dc expression_list
#line 303 "syntactic.y"
        {
		yylhs.value.as < std::stringstream > () = std::move(yystack_[2].value.as < std::stringstream > ());

		// TODO: Deduplicate this.
		for (const auto &value : yystack_[0].value.as < std::vector<unsigned long> > ())
		{
			switch (yystack_[1].value.as < Size > ())
			{
				case Size::BYTE:
					libsonassmd::WriteU8(yylhs.value.as < std::stringstream > (), value);
					break;

				case Size::SHORT:
				case Size::WORD:
					libsonassmd::WriteU16BE(yylhs.value.as < std::stringstream > (), value);
					break;

				case Size::LONGWORD:
					libsonassmd::WriteU32BE(yylhs.value.as < std::stringstream > (), value);
					break;
			}
		}
	}
#line 1001 "syntactic.cpp"
    break;

  case 24: // expression_list: expression
#line 330 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1009 "syntactic.cpp"
    break;

  case 25: // expression_list: expression_list "," expression
#line 334 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > () = std::move(yystack_[2].value.as < std::vector<unsigned long> > ());
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1018 "syntactic.cpp"
    break;

  case 26: // size: SIZE_BYTE
#line 342 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::BYTE;
	}
#line 1026 "syntactic.cpp"
    break;

  case 27: // size: SIZE_SHORT
#line 346 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::SHORT;
	}
#line 1034 "syntactic.cpp"
    break;

  case 28: // size: SIZE_WORD
#line 350 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::WORD;
	}
#line 1042 "syntactic.cpp"
    break;

  case 29: // size: SIZE_LONGWORD
#line 354 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::LONGWORD;
	}
#line 1050 "syntactic.cpp"
    break;

  case 30: // expression: expression1
#line 361 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1058 "syntactic.cpp"
    break;

  case 31: // expression: expression LOGICAL_AND expression1
#line 366 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () && yystack_[0].value.as < unsigned long > ();
	}
#line 1066 "syntactic.cpp"
    break;

  case 32: // expression: expression LOGICAL_OR expression1
#line 371 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () || yystack_[0].value.as < unsigned long > ();
	}
#line 1074 "syntactic.cpp"
    break;

  case 33: // expression1: expression2
#line 378 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1082 "syntactic.cpp"
    break;

  case 34: // expression1: expression1 "=" expression2
#line 382 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1090 "syntactic.cpp"
    break;

  case 35: // expression1: expression1 EQUALITY expression2
#line 386 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1098 "syntactic.cpp"
    break;

  case 36: // expression1: expression1 INEQUALITY expression2
#line 390 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () != yystack_[0].value.as < unsigned long > ();
	}
#line 1106 "syntactic.cpp"
    break;

  case 37: // expression2: expression3
#line 397 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1114 "syntactic.cpp"
    break;

  case 38: // expression2: expression2 "<" expression3
#line 401 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () < yystack_[0].value.as < unsigned long > ();
	}
#line 1122 "syntactic.cpp"
    break;

  case 39: // expression2: expression2 LESS_OR_EQUAL expression3
#line 405 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () <= yystack_[0].value.as < unsigned long > ();
	}
#line 1130 "syntactic.cpp"
    break;

  case 40: // expression2: expression2 ">" expression3
#line 409 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () > yystack_[0].value.as < unsigned long > ();
	}
#line 1138 "syntactic.cpp"
    break;

  case 41: // expression2: expression2 MORE_OR_EQUAL expression3
#line 413 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >= yystack_[0].value.as < unsigned long > ();
	}
#line 1146 "syntactic.cpp"
    break;

  case 42: // expression3: expression4
#line 420 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1154 "syntactic.cpp"
    break;

  case 43: // expression3: expression3 "+" expression4
#line 424 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () + yystack_[0].value.as < unsigned long > ();
	}
#line 1162 "syntactic.cpp"
    break;

  case 44: // expression3: expression3 "-" expression4
#line 428 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () - yystack_[0].value.as < unsigned long > ();
	}
#line 1170 "syntactic.cpp"
    break;

  case 45: // expression4: expression5
#line 435 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1178 "syntactic.cpp"
    break;

  case 46: // expression4: expression4 "*" expression5
#line 439 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () * yystack_[0].value.as < unsigned long > ();
	}
#line 1186 "syntactic.cpp"
    break;

  case 47: // expression4: expression4 "/" expression5
#line 443 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () / yystack_[0].value.as < unsigned long > ();
	}
#line 1194 "syntactic.cpp"
    break;

  case 48: // expression4: expression4 "%" expression5
#line 447 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () % yystack_[0].value.as < unsigned long > ();
	}
#line 1202 "syntactic.cpp"
    break;

  case 49: // expression5: expression6
#line 454 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1210 "syntactic.cpp"
    break;

  case 50: // expression5: expression5 "&" expression6
#line 458 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () & yystack_[0].value.as < unsigned long > ();
	}
#line 1218 "syntactic.cpp"
    break;

  case 51: // expression5: expression5 "!" expression6
#line 462 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1226 "syntactic.cpp"
    break;

  case 52: // expression5: expression5 "|" expression6
#line 466 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1234 "syntactic.cpp"
    break;

  case 53: // expression5: expression5 "^" expression6
#line 470 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () ^ yystack_[0].value.as < unsigned long > ();
	}
#line 1242 "syntactic.cpp"
    break;

  case 54: // expression6: expression7
#line 477 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1250 "syntactic.cpp"
    break;

  case 55: // expression6: expression6 LEFT_SHIFT expression7
#line 481 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () << yystack_[0].value.as < unsigned long > ();
	}
#line 1258 "syntactic.cpp"
    break;

  case 56: // expression6: expression6 RIGHT_SHIFT expression7
#line 485 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >> yystack_[0].value.as < unsigned long > ();
	}
#line 1266 "syntactic.cpp"
    break;

  case 57: // expression7: expression8
#line 492 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1274 "syntactic.cpp"
    break;

  case 58: // expression7: "+" expression7
#line 496 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1282 "syntactic.cpp"
    break;

  case 59: // expression7: "-" expression7
#line 500 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = -yystack_[0].value.as < unsigned long > ();
	}
#line 1290 "syntactic.cpp"
    break;

  case 60: // expression7: "~" expression7
#line 504 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = ~yystack_[0].value.as < unsigned long > ();
	}
#line 1298 "syntactic.cpp"
    break;

  case 61: // expression7: "!" expression7
#line 509 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = !yystack_[0].value.as < unsigned long > ();
	}
#line 1306 "syntactic.cpp"
    break;

  case 62: // expression8: NUMBER
#line 516 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1314 "syntactic.cpp"
    break;

  case 63: // expression8: "(" expression ")"
#line 520 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[1].value.as < unsigned long > ();
	}
#line 1322 "syntactic.cpp"
    break;


#line 1326 "syntactic.cpp"

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


  const signed char parser::yypact_ninf_ = -33;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      16,   119,   -26,   -33,   119,    15,    19,   -33,     2,    -2,
      31,   -33,   -33,   -33,   -33,   -33,   -33,   -33,    40,   -33,
       7,   -24,   -33,    -2,    36,    61,   -33,    -3,   -33,   -24,
      -2,    61,    68,   -33,    -7,   -33,    68,    68,    68,    68,
      68,    55,    60,    49,    37,   122,    89,    94,   131,   -33,
     -33,    68,    70,    -6,    12,   -33,   -33,    47,   -33,   -33,
     -33,   -33,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    55,   -33,   -33,    68,   -33,    60,    49,
      49,    37,    37,    37,   122,   122,   122,   122,    89,    89,
      94,    94,    94,   131,   131,   131,   131,   -33,   -33,    54,
      68,    83,    68,    86,    68,    88,    68,    98,    68,   100,
      68,   102,    68,    60
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,    15,     0,     0,     2,    11,     0,     3,
       0,    13,    26,    27,    28,    29,    19,    10,     0,     1,
       0,     0,    12,     4,     0,     5,    14,     0,    21,     0,
       7,     8,     0,    17,     0,    62,     0,     0,     0,     0,
       0,    22,    24,    30,    33,    37,    42,    45,    49,    54,
      57,     0,     0,     0,     0,     6,    18,     0,    58,    59,
      61,    60,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    23,    20,     9,     0,    63,    25,    31,
      32,    35,    36,    34,    39,    41,    38,    40,    43,    44,
      46,    47,    48,    50,    51,    52,    53,    55,    56,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    16
  };

  const signed char
  parser::yypgoto_[] =
  {
     -33,   -33,   -33,     9,    75,    13,   -14,    56,     6,     4,
      67,    32,    92,   -32,    87,    74,    63,    80,    69,    58,
     -31,   -33
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     5,     6,     7,     8,     9,    33,    34,    10,    11,
      25,    41,    16,    42,    43,    44,    45,    46,    47,    48,
      49,    50
  };

  const signed char
  parser::yytable_[] =
  {
      54,     1,    55,    85,    57,     1,    58,    59,    60,    61,
       1,     2,    17,    26,    24,    19,     2,    22,    32,     1,
      56,    23,    52,    63,    64,     2,    24,    26,     2,    22,
      88,    51,    86,    30,    26,    32,    32,    51,     4,    56,
      27,     3,     4,    21,    35,    27,     3,     4,    29,    28,
     107,   108,    68,    69,   109,     3,     4,    36,    63,    64,
      37,    38,    65,    66,     1,    63,    64,    70,    71,    87,
      39,    63,    64,    40,   110,    62,    35,    67,   111,    84,
     113,    20,   115,    83,   117,    53,   119,    31,   121,    36,
     123,     0,    37,    38,    63,    64,    18,    63,    64,    63,
      64,     0,    39,   112,     0,    40,   114,     0,   116,    63,
      64,    63,    64,    63,    64,    74,    75,     0,   118,     0,
     120,    76,   122,    12,    13,    14,    15,    77,    78,    79,
      80,    94,    95,    96,    97,   103,   104,   105,   106,    91,
      92,    93,     0,   100,   101,   102,    72,    73,    81,    82,
      89,    90,    98,    99
  };

  const signed char
  parser::yycheck_[] =
  {
      32,     3,     9,     9,    36,     3,    37,    38,    39,    40,
       3,     9,    38,     9,     8,     0,     9,     8,    42,     3,
      34,     8,    25,    11,    12,     9,    20,    23,     9,    20,
      62,    25,    20,    20,    30,    42,    42,    31,    40,    53,
       9,    39,    40,    41,     8,     9,    39,    40,    41,     9,
      81,    82,    15,    16,    86,    39,    40,    21,    11,    12,
      24,    25,    13,    14,     3,    11,    12,    30,    31,    22,
      34,    11,    12,    37,    20,    20,     8,    28,   110,     9,
     112,     6,   114,    51,   116,    29,   118,    20,   120,    21,
     122,    -1,    24,    25,    11,    12,     4,    11,    12,    11,
      12,    -1,    34,    20,    -1,    37,    20,    -1,    20,    11,
      12,    11,    12,    11,    12,    26,    27,    -1,    20,    -1,
      20,    32,    20,     4,     5,     6,     7,    33,    34,    35,
      36,    68,    69,    70,    71,    77,    78,    79,    80,    65,
      66,    67,    -1,    74,    75,    76,    24,    25,    17,    18,
      63,    64,    72,    73
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,     9,    39,    40,    44,    45,    46,    47,    48,
      51,    52,     4,     5,     6,     7,    55,    38,    55,     0,
      47,    41,    46,    48,    51,    53,    52,     9,     9,    41,
      48,    53,    42,    49,    50,     8,    21,    24,    25,    34,
      37,    54,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    51,    25,    50,    56,     9,    49,    56,    63,    63,
      63,    63,    20,    11,    12,    13,    14,    28,    15,    16,
      30,    31,    24,    25,    26,    27,    32,    33,    34,    35,
      36,    17,    18,    54,     9,     9,    20,    22,    56,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    62,    62,    62,    62,    63,    63,    56,
      20,    56,    20,    56,    20,    56,    20,    56,    20,    56,
      20,    56,    20,    56
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    43,    44,    45,    45,    45,    45,    45,    45,    45,
      46,    47,    47,    48,    48,    48,    49,    50,    50,    51,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    55,
      56,    56,    56,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    59,    59,    59,    60,    60,    60,    60,    61,
      61,    61,    61,    61,    62,    62,    62,    63,    63,    63,
      63,    63,    64,    64
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     4,     3,     3,     5,
       2,     1,     2,     1,     2,     1,    18,     1,     2,     2,
       4,     3,     2,     3,     1,     3,     1,     1,     1,     1,
       1,     3,     3,     1,     3,     3,     3,     1,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     1,
       3,     3,     3,     3,     1,     3,     3,     1,     2,     2,
       2,     2,     1,     3
  };


#if LIBSONASSMD_CODE_READER_YYDEBUG || 1
  // YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
  // First, the terminals, then, starting at \a YYNTOKENS, nonterminals.
  const char*
  const parser::yytname_[] =
  {
  "\"end of file\"", "error", "\"invalid token\"", "DIRECTIVE_DC",
  "SIZE_BYTE", "SIZE_SHORT", "SIZE_WORD", "SIZE_LONGWORD", "NUMBER",
  "IDENTIFIER", "LOCAL_IDENTIFIER", "LOGICAL_AND", "LOGICAL_OR",
  "EQUALITY", "INEQUALITY", "LESS_OR_EQUAL", "MORE_OR_EQUAL", "LEFT_SHIFT",
  "RIGHT_SHIFT", "\".\"", "\",\"", "\"(\"", "\")\"", "\"$\"", "\"+\"",
  "\"-\"", "\"*\"", "\"/\"", "\"=\"", "\"@\"", "\"<\"", "\">\"", "\"%\"",
  "\"&\"", "\"!\"", "\"|\"", "\"^\"", "\"~\"", "\":\"", "MAPPINGS_TABLE",
  "MAPPINGS_TABLE_ENTRY", "SPRITE_HEADER", "SPRITE_PIECE", "$accept",
  "output", "mappings", "label", "labels", "offset_table", "sprite_piece",
  "sprite_frame", "dc", "offset_table_entry", "bytes", "expression_list",
  "size", "expression", "expression1", "expression2", "expression3",
  "expression4", "expression5", "expression6", "expression7",
  "expression8", YY_NULLPTR
  };
#endif


#if LIBSONASSMD_CODE_READER_YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   150,   150,   157,   163,   167,   175,   180,   185,   193,
     202,   209,   213,   221,   225,   230,   235,   250,   254,   262,
     269,   274,   281,   302,   329,   333,   341,   345,   349,   353,
     360,   365,   370,   377,   381,   385,   389,   396,   400,   404,
     408,   412,   419,   423,   427,   434,   438,   442,   446,   453,
     457,   461,   465,   469,   476,   480,   484,   491,   495,   499,
     503,   508,   515,   519
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
#endif // LIBSONASSMD_CODE_READER_YYDEBUG


#line 24 "syntactic.y"
} } // libsonassmd::CodeReader
#line 1881 "syntactic.cpp"

#line 525 "syntactic.y"

