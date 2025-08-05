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
#line 83 "syntactic.y"


#include "lexical.h"

#undef yylex
#define yylex lexer


#line 57 "syntactic.cpp"


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
#line 131 "syntactic.cpp"

  /// Build a parser object.
  parser::parser (Output &output_yyarg, Lexer &lexer_yyarg)
#if LIBSONASSMD_CODE_READER_YYDEBUG
    : yydebug_ (false),
      yycdebug_ (&std::cerr),
#else
    :
#endif
      output (output_yyarg),
      lexer (lexer_yyarg)
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
      case symbol_kind::S_dplcs: // dplcs
        value.YY_MOVE_OR_COPY< DPLCs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.YY_MOVE_OR_COPY< DynamicPatternLoadCue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.YY_MOVE_OR_COPY< DynamicPatternLoadCue::Copy > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.YY_MOVE_OR_COPY< StringList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
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
      case symbol_kind::S_dplcs: // dplcs
        value.move< DPLCs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.move< DynamicPatternLoadCue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.move< DynamicPatternLoadCue::Copy > (YY_MOVE (that.value));
        break;

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
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.move< StringList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
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
      case symbol_kind::S_dplcs: // dplcs
        value.copy< DPLCs > (that.value);
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.copy< DynamicPatternLoadCue > (that.value);
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.copy< DynamicPatternLoadCue::Copy > (that.value);
        break;

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
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.copy< StringList > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
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
      case symbol_kind::S_dplcs: // dplcs
        value.move< DPLCs > (that.value);
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.move< DynamicPatternLoadCue > (that.value);
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.move< DynamicPatternLoadCue::Copy > (that.value);
        break;

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
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.move< StringList > (that.value);
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
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
            symbol_type yylookahead (yylex ());
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
      case symbol_kind::S_dplcs: // dplcs
        yylhs.value.emplace< DPLCs > ();
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        yylhs.value.emplace< DynamicPatternLoadCue > ();
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        yylhs.value.emplace< DynamicPatternLoadCue::Copy > ();
        break;

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
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        yylhs.value.emplace< StringList > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
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
  case 2: // output: START_MAPPINGS mappings
#line 163 "syntactic.y"
        {
		output = std::move(yystack_[0].value.as < Mappings > ());
	}
#line 851 "syntactic.cpp"
    break;

  case 3: // output: START_DPLCS dplcs
#line 167 "syntactic.y"
        {
		output = std::move(yystack_[0].value.as < DPLCs > ());
	}
#line 859 "syntactic.cpp"
    break;

  case 4: // mappings: offset_table
#line 174 "syntactic.y"
        {
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 869 "syntactic.cpp"
    break;

  case 5: // mappings: labels offset_table
#line 180 "syntactic.y"
        {
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 877 "syntactic.cpp"
    break;

  case 6: // mappings: labels bytes
#line 184 "syntactic.y"
        {
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 889 "syntactic.cpp"
    break;

  case 7: // mappings: labels SPRITE_HEADER label
#line 192 "syntactic.y"
        {
		for (const auto &label : yystack_[2].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.try_emplace(label);
	}
#line 898 "syntactic.cpp"
    break;

  case 8: // mappings: labels SPRITE_HEADER sprite_frame label
#line 197 "syntactic.y"
        {
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 907 "syntactic.cpp"
    break;

  case 9: // mappings: mappings labels offset_table
#line 202 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 916 "syntactic.cpp"
    break;

  case 10: // mappings: mappings labels bytes
#line 207 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		// TODO: Catch exceptions?
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 928 "syntactic.cpp"
    break;

  case 11: // mappings: mappings labels SPRITE_HEADER label
#line 215 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[3].value.as < Mappings > ());
		for (const auto &label : yystack_[2].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.try_emplace(label);
	}
#line 938 "syntactic.cpp"
    break;

  case 12: // mappings: mappings labels SPRITE_HEADER sprite_frame label
#line 221 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[4].value.as < Mappings > ());
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 948 "syntactic.cpp"
    break;

  case 13: // dplcs: offset_table
#line 230 "syntactic.y"
        {
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		yylhs.value.as < DPLCs > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 958 "syntactic.cpp"
    break;

  case 14: // dplcs: labels offset_table
#line 236 "syntactic.y"
        {
		yylhs.value.as < DPLCs > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 966 "syntactic.cpp"
    break;

  case 15: // dplcs: labels bytes
#line 240 "syntactic.y"
        {
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const DynamicPatternLoadCue frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, frame});
	}
#line 978 "syntactic.cpp"
    break;

  case 16: // dplcs: labels DPLC_HEADER label
#line 248 "syntactic.y"
        {
		for (const auto &label : yystack_[2].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.try_emplace(label);
	}
#line 987 "syntactic.cpp"
    break;

  case 17: // dplcs: labels DPLC_HEADER dplc_frame label
#line 253 "syntactic.y"
        {
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, yystack_[1].value.as < DynamicPatternLoadCue > ()});
	}
#line 996 "syntactic.cpp"
    break;

  case 18: // dplcs: dplcs labels offset_table
#line 258 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[2].value.as < DPLCs > ());
		yylhs.value.as < DPLCs > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 1005 "syntactic.cpp"
    break;

  case 19: // dplcs: dplcs labels bytes
#line 263 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[2].value.as < DPLCs > ());
		// TODO: Catch exceptions?
		const DynamicPatternLoadCue frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, frame});
	}
#line 1017 "syntactic.cpp"
    break;

  case 20: // dplcs: dplcs labels DPLC_HEADER label
#line 271 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[3].value.as < DPLCs > ());
		for (const auto &label : yystack_[2].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.try_emplace(label);
	}
#line 1027 "syntactic.cpp"
    break;

  case 21: // dplcs: dplcs labels DPLC_HEADER dplc_frame label
#line 277 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[4].value.as < DPLCs > ());
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, yystack_[1].value.as < DynamicPatternLoadCue > ()});
	}
#line 1037 "syntactic.cpp"
    break;

  case 22: // label: LABEL
#line 286 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1045 "syntactic.cpp"
    break;

  case 23: // label: LOCAL_LABEL
#line 290 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1053 "syntactic.cpp"
    break;

  case 24: // labels: label
#line 297 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1061 "syntactic.cpp"
    break;

  case 25: // labels: labels label
#line 301 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1070 "syntactic.cpp"
    break;

  case 26: // offset_table: offset_table_line
#line 309 "syntactic.y"
        {
		for (auto &entry : yystack_[0].value.as < StringList > ())
			yylhs.value.as < StringList > ().emplace_back(std::move(entry));
	}
#line 1079 "syntactic.cpp"
    break;

  case 27: // offset_table: offset_table offset_table_line
#line 314 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		for (auto &entry : yystack_[0].value.as < StringList > ())
			yylhs.value.as < StringList > ().emplace_back(std::move(entry));
	}
#line 1089 "syntactic.cpp"
    break;

  case 28: // offset_table: MAPPINGS_TABLE
#line 320 "syntactic.y"
        {}
#line 1095 "syntactic.cpp"
    break;

  case 29: // sprite_piece: SPRITE_PIECE expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression
#line 325 "syntactic.y"
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
#line 1111 "syntactic.cpp"
    break;

  case 30: // sprite_frame: sprite_piece
#line 340 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 1119 "syntactic.cpp"
    break;

  case 31: // sprite_frame: sprite_frame sprite_piece
#line 344 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > () = std::move(yystack_[1].value.as < SpriteFrame > ());
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 1128 "syntactic.cpp"
    break;

  case 32: // dplc_copy: DPLC_ENTRY expression "," expression
#line 352 "syntactic.y"
        {
		yylhs.value.as < DynamicPatternLoadCue::Copy > ().length = yystack_[2].value.as < unsigned long > ();
		yylhs.value.as < DynamicPatternLoadCue::Copy > ().start = yystack_[0].value.as < unsigned long > ();
	}
#line 1137 "syntactic.cpp"
    break;

  case 33: // dplc_frame: dplc_copy
#line 360 "syntactic.y"
        {
		yylhs.value.as < DynamicPatternLoadCue > ().copies.emplace_back(std::move(yystack_[0].value.as < DynamicPatternLoadCue::Copy > ()));
	}
#line 1145 "syntactic.cpp"
    break;

  case 34: // dplc_frame: dplc_frame dplc_copy
#line 364 "syntactic.y"
        {
		yylhs.value.as < DynamicPatternLoadCue > () = std::move(yystack_[1].value.as < DynamicPatternLoadCue > ());
		yylhs.value.as < DynamicPatternLoadCue > ().copies.emplace_back(std::move(yystack_[0].value.as < DynamicPatternLoadCue::Copy > ()));
	}
#line 1154 "syntactic.cpp"
    break;

  case 35: // dc: DIRECTIVE_DC size
#line 372 "syntactic.y"
        {
		yylhs.value.as < Size > () = yystack_[0].value.as < Size > ();
	}
#line 1162 "syntactic.cpp"
    break;

  case 36: // offset_table_line: dc offset_table_entries
#line 379 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[0].value.as < StringList > ());
	}
#line 1170 "syntactic.cpp"
    break;

  case 37: // offset_table_line: MAPPINGS_TABLE_ENTRY size identifier
#line 383 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1178 "syntactic.cpp"
    break;

  case 38: // offset_table_entries: offset_table_entry
#line 390 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1186 "syntactic.cpp"
    break;

  case 39: // offset_table_entries: offset_table_entries "," offset_table_entry
#line 394 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[2].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1195 "syntactic.cpp"
    break;

  case 40: // offset_table_entry: identifier "-" identifier
#line 402 "syntactic.y"
        {
		static_cast<void>(yystack_[0].value.as < std::string > ());
		yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());
	}
#line 1204 "syntactic.cpp"
    break;

  case 41: // identifier: IDENTIFIER
#line 410 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1212 "syntactic.cpp"
    break;

  case 42: // identifier: LOCAL_IDENTIFIER
#line 414 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1220 "syntactic.cpp"
    break;

  case 43: // bytes: dc expression_list
#line 421 "syntactic.y"
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
#line 1245 "syntactic.cpp"
    break;

  case 44: // bytes: bytes dc expression_list
#line 442 "syntactic.y"
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
#line 1273 "syntactic.cpp"
    break;

  case 45: // expression_list: expression
#line 469 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1281 "syntactic.cpp"
    break;

  case 46: // expression_list: expression_list "," expression
#line 473 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > () = std::move(yystack_[2].value.as < std::vector<unsigned long> > ());
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1290 "syntactic.cpp"
    break;

  case 47: // size: SIZE_BYTE
#line 481 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::BYTE;
	}
#line 1298 "syntactic.cpp"
    break;

  case 48: // size: SIZE_SHORT
#line 485 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::SHORT;
	}
#line 1306 "syntactic.cpp"
    break;

  case 49: // size: SIZE_WORD
#line 489 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::WORD;
	}
#line 1314 "syntactic.cpp"
    break;

  case 50: // size: SIZE_LONGWORD
#line 493 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::LONGWORD;
	}
#line 1322 "syntactic.cpp"
    break;

  case 51: // expression: expression1
#line 500 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1330 "syntactic.cpp"
    break;

  case 52: // expression: expression LOGICAL_AND expression1
#line 505 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () && yystack_[0].value.as < unsigned long > ();
	}
#line 1338 "syntactic.cpp"
    break;

  case 53: // expression: expression LOGICAL_OR expression1
#line 510 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () || yystack_[0].value.as < unsigned long > ();
	}
#line 1346 "syntactic.cpp"
    break;

  case 54: // expression1: expression2
#line 517 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1354 "syntactic.cpp"
    break;

  case 55: // expression1: expression1 "=" expression2
#line 521 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1362 "syntactic.cpp"
    break;

  case 56: // expression1: expression1 EQUALITY expression2
#line 525 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1370 "syntactic.cpp"
    break;

  case 57: // expression1: expression1 INEQUALITY expression2
#line 529 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () != yystack_[0].value.as < unsigned long > ();
	}
#line 1378 "syntactic.cpp"
    break;

  case 58: // expression2: expression3
#line 536 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1386 "syntactic.cpp"
    break;

  case 59: // expression2: expression2 "<" expression3
#line 540 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () < yystack_[0].value.as < unsigned long > ();
	}
#line 1394 "syntactic.cpp"
    break;

  case 60: // expression2: expression2 LESS_OR_EQUAL expression3
#line 544 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () <= yystack_[0].value.as < unsigned long > ();
	}
#line 1402 "syntactic.cpp"
    break;

  case 61: // expression2: expression2 ">" expression3
#line 548 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () > yystack_[0].value.as < unsigned long > ();
	}
#line 1410 "syntactic.cpp"
    break;

  case 62: // expression2: expression2 MORE_OR_EQUAL expression3
#line 552 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >= yystack_[0].value.as < unsigned long > ();
	}
#line 1418 "syntactic.cpp"
    break;

  case 63: // expression3: expression4
#line 559 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1426 "syntactic.cpp"
    break;

  case 64: // expression3: expression3 "+" expression4
#line 563 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () + yystack_[0].value.as < unsigned long > ();
	}
#line 1434 "syntactic.cpp"
    break;

  case 65: // expression3: expression3 "-" expression4
#line 567 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () - yystack_[0].value.as < unsigned long > ();
	}
#line 1442 "syntactic.cpp"
    break;

  case 66: // expression4: expression5
#line 574 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1450 "syntactic.cpp"
    break;

  case 67: // expression4: expression4 "*" expression5
#line 578 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () * yystack_[0].value.as < unsigned long > ();
	}
#line 1458 "syntactic.cpp"
    break;

  case 68: // expression4: expression4 "/" expression5
#line 582 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () / yystack_[0].value.as < unsigned long > ();
	}
#line 1466 "syntactic.cpp"
    break;

  case 69: // expression4: expression4 "%" expression5
#line 586 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () % yystack_[0].value.as < unsigned long > ();
	}
#line 1474 "syntactic.cpp"
    break;

  case 70: // expression5: expression6
#line 593 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1482 "syntactic.cpp"
    break;

  case 71: // expression5: expression5 "&" expression6
#line 597 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () & yystack_[0].value.as < unsigned long > ();
	}
#line 1490 "syntactic.cpp"
    break;

  case 72: // expression5: expression5 "!" expression6
#line 601 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1498 "syntactic.cpp"
    break;

  case 73: // expression5: expression5 "|" expression6
#line 605 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1506 "syntactic.cpp"
    break;

  case 74: // expression5: expression5 "^" expression6
#line 609 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () ^ yystack_[0].value.as < unsigned long > ();
	}
#line 1514 "syntactic.cpp"
    break;

  case 75: // expression6: expression7
#line 616 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1522 "syntactic.cpp"
    break;

  case 76: // expression6: expression6 LEFT_SHIFT expression7
#line 620 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () << yystack_[0].value.as < unsigned long > ();
	}
#line 1530 "syntactic.cpp"
    break;

  case 77: // expression6: expression6 RIGHT_SHIFT expression7
#line 624 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >> yystack_[0].value.as < unsigned long > ();
	}
#line 1538 "syntactic.cpp"
    break;

  case 78: // expression7: expression8
#line 631 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1546 "syntactic.cpp"
    break;

  case 79: // expression7: "+" expression7
#line 635 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1554 "syntactic.cpp"
    break;

  case 80: // expression7: "-" expression7
#line 639 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = 0 - yystack_[0].value.as < unsigned long > ();
	}
#line 1562 "syntactic.cpp"
    break;

  case 81: // expression7: "~" expression7
#line 643 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = ~yystack_[0].value.as < unsigned long > ();
	}
#line 1570 "syntactic.cpp"
    break;

  case 82: // expression7: "!" expression7
#line 648 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = !yystack_[0].value.as < unsigned long > ();
	}
#line 1578 "syntactic.cpp"
    break;

  case 83: // expression8: NUMBER
#line 655 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1586 "syntactic.cpp"
    break;

  case 84: // expression8: "(" expression ")"
#line 659 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[1].value.as < unsigned long > ();
	}
#line 1594 "syntactic.cpp"
    break;


#line 1598 "syntactic.cpp"

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


  const signed char parser::yypact_ninf_ = -46;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      28,    22,    22,     2,   178,   -46,   178,   -46,   -46,    83,
     -46,     4,    31,   200,   -46,    83,     8,    31,   -46,   -46,
     -46,   -46,   -46,   -46,   200,    38,    14,   -46,    31,   111,
       7,   -46,   -46,   -46,    -8,   -46,     6,    71,   155,    31,
       7,   -46,    14,    31,     7,    61,   -46,   -46,    14,   -46,
      61,    61,    61,    61,    61,    -3,   201,    78,   107,   190,
     149,   153,   199,   -46,   -46,    61,   200,   200,   155,    31,
       7,    61,   -46,   -46,   155,   -46,    14,   114,   -46,   -46,
     119,   -46,   -46,   -46,   -46,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    -3,   -46,   -46,   -46,
     155,   132,   -46,   -46,   -46,    61,   -46,   201,    78,    78,
     107,   107,   107,   190,   190,   190,   190,   149,   149,   153,
     153,   153,   199,   199,   199,   199,   -46,   -46,   -46,    61,
     138,   201,    61,   142,    61,   144,    61,   148,    61,   154,
      61,   158,    61,   160,    61,   201
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,    28,     0,    22,    23,     2,
      24,     0,     4,     0,    26,     3,     0,    13,     1,    47,
      48,    49,    50,    35,     0,     0,     0,    25,     5,     0,
       6,    27,    41,    42,    36,    38,     0,     0,     0,    14,
      15,    37,     0,     9,    10,     0,     7,    30,     0,    83,
       0,     0,     0,     0,     0,    43,    45,    51,    54,    58,
      63,    66,    70,    75,    78,     0,     0,     0,     0,    18,
      19,     0,    16,    33,     0,    11,     0,     0,     8,    31,
       0,    79,    80,    82,    81,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    44,    39,    40,    20,
       0,     0,    17,    34,    12,     0,    84,    46,    52,    53,
      56,    57,    55,    60,    62,    59,    61,    64,    65,    67,
      68,    69,    71,    72,    73,    74,    76,    77,    21,     0,
       0,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    29
  };

  const short
  parser::yypgoto_[] =
  {
     -46,   -46,   -46,   -46,   -10,   131,   102,   -34,   -13,   -22,
     -11,    -7,    -4,   -46,   -30,   -21,    65,    15,    49,   -45,
     133,   115,    99,   126,   109,    94,   -32,   -46
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     9,    15,    10,    11,    12,    47,    48,    73,
      74,    13,    14,    34,    35,    36,    30,    55,    23,    56,
      57,    58,    59,    60,    61,    62,    63,    64
  };

  const unsigned char
  parser::yytable_[] =
  {
      77,    27,    18,    41,    29,    80,    27,     4,    31,    29,
       4,     4,    66,    31,    79,    27,    46,    85,    29,    81,
      82,    83,    84,    65,    31,     4,   111,    27,    72,    76,
      29,    67,    75,    65,     4,    31,   107,    65,    78,    31,
     117,     4,    79,     5,     6,    26,   108,     5,     6,     7,
       8,    38,   113,     7,     8,    24,    45,   110,   109,     7,
       8,     5,     6,    65,   112,    31,   114,     7,     8,    49,
     140,     6,   136,   137,     4,     1,     2,     5,     6,    42,
     106,    40,    50,     7,     8,    51,    52,     0,   113,     0,
      44,    88,    89,     0,   141,    53,     0,   143,    54,   145,
     138,   147,    70,   149,    17,   151,    90,   153,     0,   155,
       5,     6,     0,    28,    68,     0,     7,     8,    39,    49,
      32,    33,    91,    92,     0,    86,    87,    43,     7,     8,
      86,    87,    50,    16,   115,    51,    52,    93,    94,    69,
      25,   116,     0,    86,    87,    53,    37,     0,    54,    86,
      87,     0,   139,    86,    87,    86,    87,     0,   142,    86,
      87,     0,   144,     0,   146,    86,    87,     0,   148,    86,
      87,    86,    87,     0,   150,    97,    98,     0,   152,     0,
     154,    99,    19,    20,    21,    22,   100,   101,   102,   103,
     123,   124,   125,   126,   132,   133,   134,   135,     0,    71,
       7,     8,     0,   120,   121,   122,   129,   130,   131,    32,
      33,     0,    86,    87,    95,    96,   104,   105,     0,   118,
     119,   127,   128
  };

  const short
  parser::yycheck_[] =
  {
      45,    11,     0,    24,    11,    50,    16,     3,    12,    16,
       3,     3,    20,    17,    48,    25,    26,    20,    25,    51,
      52,    53,    54,    30,    28,     3,    71,    37,    38,    42,
      37,    25,    42,    40,     3,    39,    66,    44,    48,    43,
      85,     3,    76,    39,    40,    41,    67,    39,    40,    45,
      46,    43,    74,    45,    46,     6,    42,    68,    68,    45,
      46,    39,    40,    70,    74,    69,    76,    45,    46,     8,
     115,    40,   104,   105,     3,    47,    48,    39,    40,    41,
      65,    16,    21,    45,    46,    24,    25,    -1,   110,    -1,
      25,    13,    14,    -1,   139,    34,    -1,   142,    37,   144,
     110,   146,    37,   148,     2,   150,    28,   152,    -1,   154,
      39,    40,    -1,    11,    43,    -1,    45,    46,    16,     8,
       9,    10,    15,    16,    -1,    11,    12,    25,    45,    46,
      11,    12,    21,     2,    20,    24,    25,    30,    31,    37,
       9,    22,    -1,    11,    12,    34,    15,    -1,    37,    11,
      12,    -1,    20,    11,    12,    11,    12,    -1,    20,    11,
      12,    -1,    20,    -1,    20,    11,    12,    -1,    20,    11,
      12,    11,    12,    -1,    20,    26,    27,    -1,    20,    -1,
      20,    32,     4,     5,     6,     7,    33,    34,    35,    36,
      91,    92,    93,    94,   100,   101,   102,   103,    -1,    44,
      45,    46,    -1,    88,    89,    90,    97,    98,    99,     9,
      10,    -1,    11,    12,    24,    25,    17,    18,    -1,    86,
      87,    95,    96
  };

  const signed char
  parser::yystos_[] =
  {
       0,    47,    48,    50,     3,    39,    40,    45,    46,    51,
      53,    54,    55,    60,    61,    52,    54,    55,     0,     4,
       5,     6,     7,    67,    67,    54,    41,    53,    55,    60,
      65,    61,     9,    10,    62,    63,    64,    54,    43,    55,
      65,    64,    41,    55,    65,    42,    53,    56,    57,     8,
      21,    24,    25,    34,    37,    66,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    60,    20,    25,    43,    55,
      65,    44,    53,    58,    59,    53,    57,    68,    53,    56,
      68,    75,    75,    75,    75,    20,    11,    12,    13,    14,
      28,    15,    16,    30,    31,    24,    25,    26,    27,    32,
      33,    34,    35,    36,    17,    18,    66,    63,    64,    53,
      59,    68,    53,    58,    53,    20,    22,    68,    69,    69,
      70,    70,    70,    71,    71,    71,    71,    72,    72,    73,
      73,    73,    74,    74,    74,    74,    75,    75,    53,    20,
      68,    68,    20,    68,    20,    68,    20,    68,    20,    68,
      20,    68,    20,    68,    20,    68
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    51,    51,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    53,    53,    54,    54,    55,    55,    55,    56,
      57,    57,    58,    59,    59,    60,    61,    61,    62,    62,
      63,    64,    64,    65,    65,    66,    66,    67,    67,    67,
      67,    68,    68,    68,    69,    69,    69,    69,    70,    70,
      70,    70,    70,    71,    71,    71,    72,    72,    72,    72,
      73,    73,    73,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    75,    76,    76
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     2,     3,     4,     3,
       3,     4,     5,     1,     2,     2,     3,     4,     3,     3,
       4,     5,     1,     1,     1,     2,     1,     2,     1,    18,
       1,     2,     4,     1,     2,     2,     2,     3,     1,     3,
       3,     1,     1,     2,     3,     1,     3,     1,     1,     1,
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
  "MAPPINGS_TABLE_ENTRY", "SPRITE_HEADER", "SPRITE_PIECE", "DPLC_HEADER",
  "DPLC_ENTRY", "LABEL", "LOCAL_LABEL", "START_MAPPINGS", "START_DPLCS",
  "$accept", "output", "mappings", "dplcs", "label", "labels",
  "offset_table", "sprite_piece", "sprite_frame", "dplc_copy",
  "dplc_frame", "dc", "offset_table_line", "offset_table_entries",
  "offset_table_entry", "identifier", "bytes", "expression_list", "size",
  "expression", "expression1", "expression2", "expression3", "expression4",
  "expression5", "expression6", "expression7", "expression8", YY_NULLPTR
  };
#endif


#if LIBSONASSMD_CODE_READER_YYDEBUG
  const short
  parser::yyrline_[] =
  {
       0,   162,   162,   166,   173,   179,   183,   191,   196,   201,
     206,   214,   220,   229,   235,   239,   247,   252,   257,   262,
     270,   276,   285,   289,   296,   300,   308,   313,   319,   324,
     339,   343,   351,   359,   363,   371,   378,   382,   389,   393,
     401,   409,   413,   420,   441,   468,   472,   480,   484,   488,
     492,   499,   504,   509,   516,   520,   524,   528,   535,   539,
     543,   547,   551,   558,   562,   566,   573,   577,   581,   585,
     592,   596,   600,   604,   608,   615,   619,   623,   630,   634,
     638,   642,   647,   654,   658
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
#line 2184 "syntactic.cpp"

#line 664 "syntactic.y"

