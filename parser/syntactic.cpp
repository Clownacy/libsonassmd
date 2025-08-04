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
#line 75 "syntactic.y"


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

#line 23 "syntactic.y"
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
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
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
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
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
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
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
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
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
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
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
#line 152 "syntactic.y"
        {
		mappings = std::move(yystack_[0].value.as < Mappings > ());
	}
#line 782 "syntactic.cpp"
    break;

  case 3: // mappings: offset_table
#line 159 "syntactic.y"
        {
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 792 "syntactic.cpp"
    break;

  case 4: // mappings: labels offset_table
#line 165 "syntactic.y"
        {
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 800 "syntactic.cpp"
    break;

  case 5: // mappings: labels bytes
#line 169 "syntactic.y"
        {
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > (), game);
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 812 "syntactic.cpp"
    break;

  case 6: // mappings: labels SPRITE_HEADER sprite_frame label
#line 177 "syntactic.y"
        {
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 821 "syntactic.cpp"
    break;

  case 7: // mappings: mappings labels offset_table
#line 182 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 830 "syntactic.cpp"
    break;

  case 8: // mappings: mappings labels bytes
#line 187 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		// TODO: Catch exceptions?
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > (), game);
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 842 "syntactic.cpp"
    break;

  case 9: // mappings: mappings labels SPRITE_HEADER sprite_frame label
#line 195 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[4].value.as < Mappings > ());
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 852 "syntactic.cpp"
    break;

  case 10: // label: LABEL
#line 204 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 860 "syntactic.cpp"
    break;

  case 11: // label: LOCAL_LABEL
#line 208 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 868 "syntactic.cpp"
    break;

  case 12: // labels: label
#line 215 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 876 "syntactic.cpp"
    break;

  case 13: // labels: labels label
#line 219 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 885 "syntactic.cpp"
    break;

  case 14: // offset_table: offset_table_entry
#line 227 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 893 "syntactic.cpp"
    break;

  case 15: // offset_table: offset_table offset_table_entry
#line 231 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 902 "syntactic.cpp"
    break;

  case 16: // offset_table: MAPPINGS_TABLE
#line 236 "syntactic.y"
        {}
#line 908 "syntactic.cpp"
    break;

  case 17: // sprite_piece: SPRITE_PIECE expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression
#line 241 "syntactic.y"
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
#line 924 "syntactic.cpp"
    break;

  case 18: // sprite_frame: sprite_piece
#line 256 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 932 "syntactic.cpp"
    break;

  case 19: // sprite_frame: sprite_frame sprite_piece
#line 260 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > () = std::move(yystack_[1].value.as < SpriteFrame > ());
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 941 "syntactic.cpp"
    break;

  case 20: // dc: DIRECTIVE_DC size
#line 268 "syntactic.y"
        {
		yylhs.value.as < Size > () = yystack_[0].value.as < Size > ();
	}
#line 949 "syntactic.cpp"
    break;

  case 21: // offset_table_entry: dc IDENTIFIER "-" IDENTIFIER
#line 275 "syntactic.y"
        {
		static_cast<void>(yystack_[0].value.as < std::string > ());
		yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());
	}
#line 958 "syntactic.cpp"
    break;

  case 22: // offset_table_entry: MAPPINGS_TABLE_ENTRY size IDENTIFIER
#line 280 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 966 "syntactic.cpp"
    break;

  case 23: // bytes: dc expression_list
#line 287 "syntactic.y"
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
#line 991 "syntactic.cpp"
    break;

  case 24: // bytes: bytes dc expression_list
#line 308 "syntactic.y"
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
#line 1019 "syntactic.cpp"
    break;

  case 25: // expression_list: expression
#line 335 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1027 "syntactic.cpp"
    break;

  case 26: // expression_list: expression_list "," expression
#line 339 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > () = std::move(yystack_[2].value.as < std::vector<unsigned long> > ());
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1036 "syntactic.cpp"
    break;

  case 27: // size: SIZE_BYTE
#line 347 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::BYTE;
	}
#line 1044 "syntactic.cpp"
    break;

  case 28: // size: SIZE_SHORT
#line 351 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::SHORT;
	}
#line 1052 "syntactic.cpp"
    break;

  case 29: // size: SIZE_WORD
#line 355 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::WORD;
	}
#line 1060 "syntactic.cpp"
    break;

  case 30: // size: SIZE_LONGWORD
#line 359 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::LONGWORD;
	}
#line 1068 "syntactic.cpp"
    break;

  case 31: // expression: expression1
#line 366 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1076 "syntactic.cpp"
    break;

  case 32: // expression: expression LOGICAL_AND expression1
#line 371 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () && yystack_[0].value.as < unsigned long > ();
	}
#line 1084 "syntactic.cpp"
    break;

  case 33: // expression: expression LOGICAL_OR expression1
#line 376 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () || yystack_[0].value.as < unsigned long > ();
	}
#line 1092 "syntactic.cpp"
    break;

  case 34: // expression1: expression2
#line 383 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1100 "syntactic.cpp"
    break;

  case 35: // expression1: expression1 "=" expression2
#line 387 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1108 "syntactic.cpp"
    break;

  case 36: // expression1: expression1 EQUALITY expression2
#line 391 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1116 "syntactic.cpp"
    break;

  case 37: // expression1: expression1 INEQUALITY expression2
#line 395 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () != yystack_[0].value.as < unsigned long > ();
	}
#line 1124 "syntactic.cpp"
    break;

  case 38: // expression2: expression3
#line 402 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1132 "syntactic.cpp"
    break;

  case 39: // expression2: expression2 "<" expression3
#line 406 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () < yystack_[0].value.as < unsigned long > ();
	}
#line 1140 "syntactic.cpp"
    break;

  case 40: // expression2: expression2 LESS_OR_EQUAL expression3
#line 410 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () <= yystack_[0].value.as < unsigned long > ();
	}
#line 1148 "syntactic.cpp"
    break;

  case 41: // expression2: expression2 ">" expression3
#line 414 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () > yystack_[0].value.as < unsigned long > ();
	}
#line 1156 "syntactic.cpp"
    break;

  case 42: // expression2: expression2 MORE_OR_EQUAL expression3
#line 418 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >= yystack_[0].value.as < unsigned long > ();
	}
#line 1164 "syntactic.cpp"
    break;

  case 43: // expression3: expression4
#line 425 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1172 "syntactic.cpp"
    break;

  case 44: // expression3: expression3 "+" expression4
#line 429 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () + yystack_[0].value.as < unsigned long > ();
	}
#line 1180 "syntactic.cpp"
    break;

  case 45: // expression3: expression3 "-" expression4
#line 433 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () - yystack_[0].value.as < unsigned long > ();
	}
#line 1188 "syntactic.cpp"
    break;

  case 46: // expression4: expression5
#line 440 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1196 "syntactic.cpp"
    break;

  case 47: // expression4: expression4 "*" expression5
#line 444 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () * yystack_[0].value.as < unsigned long > ();
	}
#line 1204 "syntactic.cpp"
    break;

  case 48: // expression4: expression4 "/" expression5
#line 448 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () / yystack_[0].value.as < unsigned long > ();
	}
#line 1212 "syntactic.cpp"
    break;

  case 49: // expression4: expression4 "%" expression5
#line 452 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () % yystack_[0].value.as < unsigned long > ();
	}
#line 1220 "syntactic.cpp"
    break;

  case 50: // expression5: expression6
#line 459 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1228 "syntactic.cpp"
    break;

  case 51: // expression5: expression5 "&" expression6
#line 463 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () & yystack_[0].value.as < unsigned long > ();
	}
#line 1236 "syntactic.cpp"
    break;

  case 52: // expression5: expression5 "!" expression6
#line 467 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1244 "syntactic.cpp"
    break;

  case 53: // expression5: expression5 "|" expression6
#line 471 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1252 "syntactic.cpp"
    break;

  case 54: // expression5: expression5 "^" expression6
#line 475 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () ^ yystack_[0].value.as < unsigned long > ();
	}
#line 1260 "syntactic.cpp"
    break;

  case 55: // expression6: expression7
#line 482 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1268 "syntactic.cpp"
    break;

  case 56: // expression6: expression6 LEFT_SHIFT expression7
#line 486 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () << yystack_[0].value.as < unsigned long > ();
	}
#line 1276 "syntactic.cpp"
    break;

  case 57: // expression6: expression6 RIGHT_SHIFT expression7
#line 490 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >> yystack_[0].value.as < unsigned long > ();
	}
#line 1284 "syntactic.cpp"
    break;

  case 58: // expression7: expression8
#line 497 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1292 "syntactic.cpp"
    break;

  case 59: // expression7: "+" expression7
#line 501 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1300 "syntactic.cpp"
    break;

  case 60: // expression7: "-" expression7
#line 505 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = -yystack_[0].value.as < unsigned long > ();
	}
#line 1308 "syntactic.cpp"
    break;

  case 61: // expression7: "~" expression7
#line 509 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = ~yystack_[0].value.as < unsigned long > ();
	}
#line 1316 "syntactic.cpp"
    break;

  case 62: // expression7: "!" expression7
#line 514 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = !yystack_[0].value.as < unsigned long > ();
	}
#line 1324 "syntactic.cpp"
    break;

  case 63: // expression8: NUMBER
#line 521 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1332 "syntactic.cpp"
    break;

  case 64: // expression8: "(" expression ")"
#line 525 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[1].value.as < unsigned long > ();
	}
#line 1340 "syntactic.cpp"
    break;


#line 1344 "syntactic.cpp"

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
      22,   119,   -33,   119,   -33,   -33,     5,   -12,   -33,    -1,
       7,    18,   -33,   -33,   -33,   -33,   -33,   -33,    32,   -33,
      16,   -28,   -33,     7,    12,    41,   -33,    23,   -33,   -28,
       7,    41,    68,   -33,    99,   -33,    68,    68,    68,    68,
      68,    38,   139,    57,    37,   128,    89,    94,   137,   -33,
     -33,    68,    60,    99,    52,   -33,   -33,     6,   -33,   -33,
     -33,   -33,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    68,    68,    68,    68,    68,    68,    68,
      68,    68,    68,    38,   -33,   -33,    68,   -33,   139,    57,
      57,    37,    37,    37,   128,   128,   128,   128,    89,    89,
      94,    94,    94,   137,   137,   137,   137,   -33,   -33,    63,
      68,    83,    68,    86,    68,    88,    68,    98,    68,   100,
      68,   102,    68,   139
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,    16,     0,    10,    11,     0,     2,    12,     0,
       3,     0,    14,    27,    28,    29,    30,    20,     0,     1,
       0,     0,    13,     4,     0,     5,    15,     0,    22,     0,
       7,     8,     0,    18,     0,    63,     0,     0,     0,     0,
       0,    23,    25,    31,    34,    38,    43,    46,    50,    55,
      58,     0,     0,     0,     0,     6,    19,     0,    59,    60,
      62,    61,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    24,    21,     9,     0,    64,    26,    32,
      33,    36,    37,    35,    40,    42,    39,    41,    44,    45,
      47,    48,    49,    51,    52,    53,    54,    56,    57,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17
  };

  const signed char
  parser::yypgoto_[] =
  {
     -33,   -33,   -33,    -8,    66,     2,   -19,    48,     4,    -7,
      61,    28,    84,   -32,    93,    79,    64,    87,    73,    59,
     -31,   -33
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     6,     7,     8,     9,    10,    33,    34,    11,    12,
      25,    41,    17,    42,    43,    44,    45,    46,    47,    48,
      49,    50
  };

  const signed char
  parser::yytable_[] =
  {
      54,    22,     1,    26,    57,    19,    58,    59,    60,    61,
       1,    23,    22,    24,    32,    56,    26,    63,    64,     1,
      35,    27,    30,    26,    24,     1,    55,    27,    87,    51,
      88,     4,     5,    36,    56,    51,    37,    38,     2,     3,
      21,    28,     4,     5,     1,    85,    39,     3,    52,    40,
     107,   108,    68,    69,   109,     2,     3,    29,    62,     4,
       5,     2,     3,    63,    64,     4,     5,    70,    71,    84,
      65,    66,    86,    20,    63,    64,    35,    53,   111,    83,
     113,    31,   115,   110,   117,    67,   119,    18,   121,    36,
     123,     0,    37,    38,    63,    64,     0,    63,    64,    63,
      64,     0,    39,   112,     0,    40,   114,     0,   116,    63,
      64,    63,    64,    63,    64,    74,    75,     0,   118,     0,
     120,    76,   122,    13,    14,    15,    16,    77,    78,    79,
      80,     0,    94,    95,    96,    97,   103,   104,   105,   106,
       0,    32,     4,     5,    91,    92,    93,   100,   101,   102,
      63,    64,    72,    73,    81,    82,    89,    90,     0,    98,
      99
  };

  const signed char
  parser::yycheck_[] =
  {
      32,     9,     3,    10,    36,     0,    37,    38,    39,    40,
       3,     9,    20,     9,    42,    34,    23,    11,    12,     3,
       8,     9,    20,    30,    20,     3,    34,     9,    22,    25,
      62,    43,    44,    21,    53,    31,    24,    25,    39,    40,
      41,     9,    43,    44,     3,    53,    34,    40,    25,    37,
      81,    82,    15,    16,    86,    39,    40,    41,    20,    43,
      44,    39,    40,    11,    12,    43,    44,    30,    31,     9,
      13,    14,    20,     7,    11,    12,     8,    29,   110,    51,
     112,    20,   114,    20,   116,    28,   118,     3,   120,    21,
     122,    -1,    24,    25,    11,    12,    -1,    11,    12,    11,
      12,    -1,    34,    20,    -1,    37,    20,    -1,    20,    11,
      12,    11,    12,    11,    12,    26,    27,    -1,    20,    -1,
      20,    32,    20,     4,     5,     6,     7,    33,    34,    35,
      36,    -1,    68,    69,    70,    71,    77,    78,    79,    80,
      -1,    42,    43,    44,    65,    66,    67,    74,    75,    76,
      11,    12,    24,    25,    17,    18,    63,    64,    -1,    72,
      73
  };

  const signed char
  parser::yystos_[] =
  {
       0,     3,    39,    40,    43,    44,    46,    47,    48,    49,
      50,    53,    54,     4,     5,     6,     7,    57,    57,     0,
      49,    41,    48,    50,    53,    55,    54,     9,     9,    41,
      50,    55,    42,    51,    52,     8,    21,    24,    25,    34,
      37,    56,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    53,    25,    52,    58,    48,    51,    58,    65,    65,
      65,    65,    20,    11,    12,    13,    14,    28,    15,    16,
      30,    31,    24,    25,    26,    27,    32,    33,    34,    35,
      36,    17,    18,    56,     9,    48,    20,    22,    58,    59,
      59,    60,    60,    60,    61,    61,    61,    61,    62,    62,
      63,    63,    63,    64,    64,    64,    64,    65,    65,    58,
      20,    58,    20,    58,    20,    58,    20,    58,    20,    58,
      20,    58,    20,    58
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    45,    46,    47,    47,    47,    47,    47,    47,    47,
      48,    48,    49,    49,    50,    50,    50,    51,    52,    52,
      53,    54,    54,    55,    55,    56,    56,    57,    57,    57,
      57,    58,    58,    58,    59,    59,    59,    59,    60,    60,
      60,    60,    60,    61,    61,    61,    62,    62,    62,    62,
      63,    63,    63,    63,    63,    64,    64,    64,    65,    65,
      65,    65,    65,    66,    66
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     1,     1,     2,     2,     4,     3,     3,     5,
       1,     1,     1,     2,     1,     2,     1,    18,     1,     2,
       2,     4,     3,     2,     3,     1,     3,     1,     1,     1,
       1,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     3,     3,     3,
       1,     3,     3,     3,     3,     1,     3,     3,     1,     2,
       2,     2,     2,     1,     3
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
  "MAPPINGS_TABLE_ENTRY", "SPRITE_HEADER", "SPRITE_PIECE", "LABEL",
  "LOCAL_LABEL", "$accept", "output", "mappings", "label", "labels",
  "offset_table", "sprite_piece", "sprite_frame", "dc",
  "offset_table_entry", "bytes", "expression_list", "size", "expression",
  "expression1", "expression2", "expression3", "expression4",
  "expression5", "expression6", "expression7", "expression8", YY_NULLPTR
  };
#endif


#if LIBSONASSMD_CODE_READER_YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   151,   151,   158,   164,   168,   176,   181,   186,   194,
     203,   207,   214,   218,   226,   230,   235,   240,   255,   259,
     267,   274,   279,   286,   307,   334,   338,   346,   350,   354,
     358,   365,   370,   375,   382,   386,   390,   394,   401,   405,
     409,   413,   417,   424,   428,   432,   439,   443,   447,   451,
     458,   462,   466,   470,   474,   481,   485,   489,   496,   500,
     504,   508,   513,   520,   524
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


#line 23 "syntactic.y"
} } // libsonassmd::CodeReader
#line 1901 "syntactic.cpp"

#line 530 "syntactic.y"

