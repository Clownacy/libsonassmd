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

  case 7: // mappings: labels SPRITE_HEADER sprite_frame label
#line 192 "syntactic.y"
        {
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 898 "syntactic.cpp"
    break;

  case 8: // mappings: mappings labels offset_table
#line 197 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		yylhs.value.as < Mappings > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 907 "syntactic.cpp"
    break;

  case 9: // mappings: mappings labels bytes
#line 202 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[2].value.as < Mappings > ());
		// TODO: Catch exceptions?
		const SpriteFrame frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, frame});
	}
#line 919 "syntactic.cpp"
    break;

  case 10: // mappings: mappings labels SPRITE_HEADER sprite_frame label
#line 210 "syntactic.y"
        {
		yylhs.value.as < Mappings > () = std::move(yystack_[4].value.as < Mappings > ());
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < Mappings > ().frames.insert({label, yystack_[1].value.as < SpriteFrame > ()});
	}
#line 929 "syntactic.cpp"
    break;

  case 11: // dplcs: offset_table
#line 219 "syntactic.y"
        {
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		yylhs.value.as < DPLCs > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 939 "syntactic.cpp"
    break;

  case 12: // dplcs: labels offset_table
#line 225 "syntactic.y"
        {
		yylhs.value.as < DPLCs > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 947 "syntactic.cpp"
    break;

  case 13: // dplcs: labels bytes
#line 229 "syntactic.y"
        {
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const DynamicPatternLoadCue frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, frame});
	}
#line 959 "syntactic.cpp"
    break;

  case 14: // dplcs: labels DPLC_HEADER label
#line 237 "syntactic.y"
        {
		for (const auto &label : yystack_[2].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.try_emplace(label);
	}
#line 968 "syntactic.cpp"
    break;

  case 15: // dplcs: labels DPLC_HEADER dplc_frame label
#line 242 "syntactic.y"
        {
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, yystack_[1].value.as < DynamicPatternLoadCue > ()});
	}
#line 977 "syntactic.cpp"
    break;

  case 16: // dplcs: dplcs labels offset_table
#line 247 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[2].value.as < DPLCs > ());
		yylhs.value.as < DPLCs > ().offset_tables.emplace_back(std::move(yystack_[0].value.as < StringList > ()));
	}
#line 986 "syntactic.cpp"
    break;

  case 17: // dplcs: dplcs labels bytes
#line 252 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[2].value.as < DPLCs > ());
		// TODO: Catch exceptions?
		const DynamicPatternLoadCue frame(yystack_[0].value.as < std::stringstream > ());
		for (const auto &label : yystack_[1].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, frame});
	}
#line 998 "syntactic.cpp"
    break;

  case 18: // dplcs: dplcs labels DPLC_HEADER label
#line 260 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[3].value.as < DPLCs > ());
		for (const auto &label : yystack_[2].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.try_emplace(label);
	}
#line 1008 "syntactic.cpp"
    break;

  case 19: // dplcs: dplcs labels DPLC_HEADER dplc_frame label
#line 266 "syntactic.y"
        {
		yylhs.value.as < DPLCs > () = std::move(yystack_[4].value.as < DPLCs > ());
		for (const auto &label : yystack_[3].value.as < StringList > ())
			yylhs.value.as < DPLCs > ().frames.insert({label, yystack_[1].value.as < DynamicPatternLoadCue > ()});
	}
#line 1018 "syntactic.cpp"
    break;

  case 20: // label: LABEL
#line 275 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1026 "syntactic.cpp"
    break;

  case 21: // label: LOCAL_LABEL
#line 279 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1034 "syntactic.cpp"
    break;

  case 22: // labels: label
#line 286 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1042 "syntactic.cpp"
    break;

  case 23: // labels: labels label
#line 290 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1051 "syntactic.cpp"
    break;

  case 24: // offset_table: offset_table_line
#line 298 "syntactic.y"
        {
		for (auto &entry : yystack_[0].value.as < StringList > ())
			yylhs.value.as < StringList > ().emplace_back(std::move(entry));
	}
#line 1060 "syntactic.cpp"
    break;

  case 25: // offset_table: offset_table offset_table_line
#line 303 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[1].value.as < StringList > ());
		for (auto &entry : yystack_[0].value.as < StringList > ())
			yylhs.value.as < StringList > ().emplace_back(std::move(entry));
	}
#line 1070 "syntactic.cpp"
    break;

  case 26: // offset_table: MAPPINGS_TABLE
#line 309 "syntactic.y"
        {}
#line 1076 "syntactic.cpp"
    break;

  case 27: // sprite_piece: SPRITE_PIECE expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression
#line 314 "syntactic.y"
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
#line 1092 "syntactic.cpp"
    break;

  case 28: // sprite_frame: sprite_piece
#line 329 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 1100 "syntactic.cpp"
    break;

  case 29: // sprite_frame: sprite_frame sprite_piece
#line 333 "syntactic.y"
        {
		yylhs.value.as < SpriteFrame > () = std::move(yystack_[1].value.as < SpriteFrame > ());
		yylhs.value.as < SpriteFrame > ().pieces.emplace_back(std::move(yystack_[0].value.as < SpritePiece > ()));
	}
#line 1109 "syntactic.cpp"
    break;

  case 30: // dplc_copy: DPLC_ENTRY expression "," expression
#line 341 "syntactic.y"
        {
		yylhs.value.as < DynamicPatternLoadCue::Copy > ().length = yystack_[2].value.as < unsigned long > ();
		yylhs.value.as < DynamicPatternLoadCue::Copy > ().start = yystack_[0].value.as < unsigned long > ();
	}
#line 1118 "syntactic.cpp"
    break;

  case 31: // dplc_frame: dplc_copy
#line 349 "syntactic.y"
        {
		yylhs.value.as < DynamicPatternLoadCue > ().copies.emplace_back(std::move(yystack_[0].value.as < DynamicPatternLoadCue::Copy > ()));
	}
#line 1126 "syntactic.cpp"
    break;

  case 32: // dplc_frame: dplc_frame dplc_copy
#line 353 "syntactic.y"
        {
		yylhs.value.as < DynamicPatternLoadCue > () = std::move(yystack_[1].value.as < DynamicPatternLoadCue > ());
		yylhs.value.as < DynamicPatternLoadCue > ().copies.emplace_back(std::move(yystack_[0].value.as < DynamicPatternLoadCue::Copy > ()));
	}
#line 1135 "syntactic.cpp"
    break;

  case 33: // dc: DIRECTIVE_DC size
#line 361 "syntactic.y"
        {
		yylhs.value.as < Size > () = yystack_[0].value.as < Size > ();
	}
#line 1143 "syntactic.cpp"
    break;

  case 34: // offset_table_line: dc offset_table_entries
#line 368 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[0].value.as < StringList > ());
	}
#line 1151 "syntactic.cpp"
    break;

  case 35: // offset_table_line: MAPPINGS_TABLE_ENTRY size identifier
#line 372 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1159 "syntactic.cpp"
    break;

  case 36: // offset_table_entries: offset_table_entry
#line 379 "syntactic.y"
        {
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1167 "syntactic.cpp"
    break;

  case 37: // offset_table_entries: offset_table_entries "," offset_table_entry
#line 383 "syntactic.y"
        {
		yylhs.value.as < StringList > () = std::move(yystack_[2].value.as < StringList > ());
		yylhs.value.as < StringList > ().emplace_back(std::move(yystack_[0].value.as < std::string > ()));
	}
#line 1176 "syntactic.cpp"
    break;

  case 38: // offset_table_entry: identifier "-" identifier
#line 391 "syntactic.y"
        {
		static_cast<void>(yystack_[0].value.as < std::string > ());
		yylhs.value.as < std::string > () = std::move(yystack_[2].value.as < std::string > ());
	}
#line 1185 "syntactic.cpp"
    break;

  case 39: // identifier: IDENTIFIER
#line 399 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1193 "syntactic.cpp"
    break;

  case 40: // identifier: LOCAL_IDENTIFIER
#line 403 "syntactic.y"
        {
		yylhs.value.as < std::string > () = std::move(yystack_[0].value.as < std::string > ());
	}
#line 1201 "syntactic.cpp"
    break;

  case 41: // bytes: dc expression_list
#line 410 "syntactic.y"
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
#line 1226 "syntactic.cpp"
    break;

  case 42: // bytes: bytes dc expression_list
#line 431 "syntactic.y"
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
#line 1254 "syntactic.cpp"
    break;

  case 43: // expression_list: expression
#line 458 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1262 "syntactic.cpp"
    break;

  case 44: // expression_list: expression_list "," expression
#line 462 "syntactic.y"
        {
		yylhs.value.as < std::vector<unsigned long> > () = std::move(yystack_[2].value.as < std::vector<unsigned long> > ());
		yylhs.value.as < std::vector<unsigned long> > ().emplace_back(std::move(yystack_[0].value.as < unsigned long > ()));
	}
#line 1271 "syntactic.cpp"
    break;

  case 45: // size: SIZE_BYTE
#line 470 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::BYTE;
	}
#line 1279 "syntactic.cpp"
    break;

  case 46: // size: SIZE_SHORT
#line 474 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::SHORT;
	}
#line 1287 "syntactic.cpp"
    break;

  case 47: // size: SIZE_WORD
#line 478 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::WORD;
	}
#line 1295 "syntactic.cpp"
    break;

  case 48: // size: SIZE_LONGWORD
#line 482 "syntactic.y"
        {
		yylhs.value.as < Size > () = Size::LONGWORD;
	}
#line 1303 "syntactic.cpp"
    break;

  case 49: // expression: expression1
#line 489 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1311 "syntactic.cpp"
    break;

  case 50: // expression: expression LOGICAL_AND expression1
#line 494 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () && yystack_[0].value.as < unsigned long > ();
	}
#line 1319 "syntactic.cpp"
    break;

  case 51: // expression: expression LOGICAL_OR expression1
#line 499 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () || yystack_[0].value.as < unsigned long > ();
	}
#line 1327 "syntactic.cpp"
    break;

  case 52: // expression1: expression2
#line 506 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1335 "syntactic.cpp"
    break;

  case 53: // expression1: expression1 "=" expression2
#line 510 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1343 "syntactic.cpp"
    break;

  case 54: // expression1: expression1 EQUALITY expression2
#line 514 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () == yystack_[0].value.as < unsigned long > ();
	}
#line 1351 "syntactic.cpp"
    break;

  case 55: // expression1: expression1 INEQUALITY expression2
#line 518 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () != yystack_[0].value.as < unsigned long > ();
	}
#line 1359 "syntactic.cpp"
    break;

  case 56: // expression2: expression3
#line 525 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1367 "syntactic.cpp"
    break;

  case 57: // expression2: expression2 "<" expression3
#line 529 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () < yystack_[0].value.as < unsigned long > ();
	}
#line 1375 "syntactic.cpp"
    break;

  case 58: // expression2: expression2 LESS_OR_EQUAL expression3
#line 533 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () <= yystack_[0].value.as < unsigned long > ();
	}
#line 1383 "syntactic.cpp"
    break;

  case 59: // expression2: expression2 ">" expression3
#line 537 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () > yystack_[0].value.as < unsigned long > ();
	}
#line 1391 "syntactic.cpp"
    break;

  case 60: // expression2: expression2 MORE_OR_EQUAL expression3
#line 541 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >= yystack_[0].value.as < unsigned long > ();
	}
#line 1399 "syntactic.cpp"
    break;

  case 61: // expression3: expression4
#line 548 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1407 "syntactic.cpp"
    break;

  case 62: // expression3: expression3 "+" expression4
#line 552 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () + yystack_[0].value.as < unsigned long > ();
	}
#line 1415 "syntactic.cpp"
    break;

  case 63: // expression3: expression3 "-" expression4
#line 556 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () - yystack_[0].value.as < unsigned long > ();
	}
#line 1423 "syntactic.cpp"
    break;

  case 64: // expression4: expression5
#line 563 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1431 "syntactic.cpp"
    break;

  case 65: // expression4: expression4 "*" expression5
#line 567 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () * yystack_[0].value.as < unsigned long > ();
	}
#line 1439 "syntactic.cpp"
    break;

  case 66: // expression4: expression4 "/" expression5
#line 571 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () / yystack_[0].value.as < unsigned long > ();
	}
#line 1447 "syntactic.cpp"
    break;

  case 67: // expression4: expression4 "%" expression5
#line 575 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () % yystack_[0].value.as < unsigned long > ();
	}
#line 1455 "syntactic.cpp"
    break;

  case 68: // expression5: expression6
#line 582 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1463 "syntactic.cpp"
    break;

  case 69: // expression5: expression5 "&" expression6
#line 586 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () & yystack_[0].value.as < unsigned long > ();
	}
#line 1471 "syntactic.cpp"
    break;

  case 70: // expression5: expression5 "!" expression6
#line 590 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1479 "syntactic.cpp"
    break;

  case 71: // expression5: expression5 "|" expression6
#line 594 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () | yystack_[0].value.as < unsigned long > ();
	}
#line 1487 "syntactic.cpp"
    break;

  case 72: // expression5: expression5 "^" expression6
#line 598 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () ^ yystack_[0].value.as < unsigned long > ();
	}
#line 1495 "syntactic.cpp"
    break;

  case 73: // expression6: expression7
#line 605 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1503 "syntactic.cpp"
    break;

  case 74: // expression6: expression6 LEFT_SHIFT expression7
#line 609 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () << yystack_[0].value.as < unsigned long > ();
	}
#line 1511 "syntactic.cpp"
    break;

  case 75: // expression6: expression6 RIGHT_SHIFT expression7
#line 613 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[2].value.as < unsigned long > () >> yystack_[0].value.as < unsigned long > ();
	}
#line 1519 "syntactic.cpp"
    break;

  case 76: // expression7: expression8
#line 620 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1527 "syntactic.cpp"
    break;

  case 77: // expression7: "+" expression7
#line 624 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1535 "syntactic.cpp"
    break;

  case 78: // expression7: "-" expression7
#line 628 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = 0 - yystack_[0].value.as < unsigned long > ();
	}
#line 1543 "syntactic.cpp"
    break;

  case 79: // expression7: "~" expression7
#line 632 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = ~yystack_[0].value.as < unsigned long > ();
	}
#line 1551 "syntactic.cpp"
    break;

  case 80: // expression7: "!" expression7
#line 637 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = !yystack_[0].value.as < unsigned long > ();
	}
#line 1559 "syntactic.cpp"
    break;

  case 81: // expression8: NUMBER
#line 644 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[0].value.as < unsigned long > ();
	}
#line 1567 "syntactic.cpp"
    break;

  case 82: // expression8: "(" expression ")"
#line 648 "syntactic.y"
        {
		yylhs.value.as < unsigned long > () = yystack_[1].value.as < unsigned long > ();
	}
#line 1575 "syntactic.cpp"
    break;


#line 1579 "syntactic.cpp"

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


  const signed char parser::yypact_ninf_ = -69;

  const signed char parser::yytable_ninf_ = -1;

  const short
  parser::yypact_[] =
  {
      86,    20,    20,     9,   175,   -69,   175,   -69,   -69,   157,
     -69,     7,    18,   112,   -69,   157,    36,    18,   -69,   -69,
     -69,   -69,   -69,   -69,   112,    10,   -26,   -69,    18,   118,
      15,   -69,   -69,   -69,     0,   -69,    -1,    74,    42,    18,
      15,   -69,   -26,    18,    15,    59,   -69,   131,   -69,    59,
      59,    59,    59,    59,    11,   193,    -2,   114,   182,   109,
     150,   191,   -69,   -69,    59,   112,   112,    42,    18,    15,
      59,   -69,   -69,    42,   131,    98,   -69,   -69,    78,   -69,
     -69,   -69,   -69,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    59,    59,    59,    59,    59,    59,
      59,    59,    59,    59,    11,   -69,   -69,   -69,    42,   120,
     -69,   -69,   -69,    59,   -69,   193,    -2,    -2,   114,   114,
     114,   182,   182,   182,   182,   109,   109,   150,   150,   150,
     191,   191,   191,   191,   -69,   -69,   -69,    59,   136,   193,
      59,   138,    59,   142,    59,   148,    59,   152,    59,   154,
      59,   158,    59,   193
  };

  const signed char
  parser::yydefact_[] =
  {
       0,     0,     0,     0,     0,    26,     0,    20,    21,     2,
      22,     0,     4,     0,    24,     3,     0,    11,     1,    45,
      46,    47,    48,    33,     0,     0,     0,    23,     5,     0,
       6,    25,    39,    40,    34,    36,     0,     0,     0,    12,
      13,    35,     0,     8,     9,     0,    28,     0,    81,     0,
       0,     0,     0,     0,    41,    43,    49,    52,    56,    61,
      64,    68,    73,    76,     0,     0,     0,     0,    16,    17,
       0,    14,    31,     0,     0,     0,     7,    29,     0,    77,
      78,    80,    79,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    42,    37,    38,    18,     0,     0,
      15,    32,    10,     0,    82,    44,    50,    51,    54,    55,
      53,    58,    60,    57,    59,    62,    63,    65,    66,    67,
      69,    70,    71,    72,    74,    75,    19,     0,     0,    30,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    27
  };

  const signed char
  parser::yypgoto_[] =
  {
     -69,   -69,   -69,   -69,   -10,    76,   100,   -40,    -7,   -68,
     -24,    -8,     2,   -69,    -3,   -22,    17,     5,    88,   -45,
     126,   110,    99,   119,   104,    94,    21,   -69
  };

  const signed char
  parser::yydefgoto_[] =
  {
       0,     3,     9,    15,    10,    11,    12,    46,    47,    72,
      73,    13,    14,    34,    35,    36,    30,    54,    23,    55,
      56,    57,    58,    59,    60,    61,    62,    63
  };

  const unsigned char
  parser::yytable_[] =
  {
      75,    27,    41,    29,    78,   111,    27,    77,    29,    18,
       4,    86,    87,     4,    31,    27,    45,    29,     4,    31,
      65,     4,    64,     4,    66,   109,    88,    27,    71,    29,
      31,    83,    64,    40,    77,    74,    64,    76,   115,     4,
     111,    31,    44,   108,   106,    31,     5,     6,    26,     5,
       6,    42,     7,     8,    69,     7,     8,   107,     6,     5,
       6,    64,   105,   110,   112,     7,     8,    48,   138,   104,
      31,    79,    80,    81,    82,     5,     6,     4,    16,    38,
      49,     7,     8,    50,    51,    25,    70,     7,     8,    84,
      85,    37,   139,    52,    24,   141,    53,   143,   136,   145,
     114,   147,    17,   149,     0,   151,     0,   153,     0,    84,
      85,    28,     0,     5,     6,     0,    39,    67,   113,     7,
       8,    32,    33,   134,   135,    43,    48,    32,    33,    89,
      90,    84,    85,     1,     2,    95,    96,    68,     0,    49,
     137,    97,    50,    51,    91,    92,     0,    84,    85,    84,
      85,     0,    52,    84,    85,    53,   140,     0,   142,    84,
      85,     0,   144,    84,    85,    84,    85,     0,   146,    84,
      85,     0,   148,    45,   150,     0,     7,     8,   152,    19,
      20,    21,    22,    98,    99,   100,   101,     0,   121,   122,
     123,   124,   130,   131,   132,   133,   118,   119,   120,   127,
     128,   129,     7,     8,    84,    85,    93,    94,   102,   103,
     116,   117,   125,   126
  };

  const short
  parser::yycheck_[] =
  {
      45,    11,    24,    11,    49,    73,    16,    47,    16,     0,
       3,    13,    14,     3,    12,    25,    42,    25,     3,    17,
      20,     3,    30,     3,    25,    70,    28,    37,    38,    37,
      28,    20,    40,    16,    74,    42,    44,    47,    83,     3,
     108,    39,    25,    67,    66,    43,    39,    40,    41,    39,
      40,    41,    45,    46,    37,    45,    46,    67,    40,    39,
      40,    69,    65,    73,    74,    45,    46,     8,   113,    64,
      68,    50,    51,    52,    53,    39,    40,     3,     2,    43,
      21,    45,    46,    24,    25,     9,    44,    45,    46,    11,
      12,    15,   137,    34,     6,   140,    37,   142,   108,   144,
      22,   146,     2,   148,    -1,   150,    -1,   152,    -1,    11,
      12,    11,    -1,    39,    40,    -1,    16,    43,    20,    45,
      46,     9,    10,   102,   103,    25,     8,     9,    10,    15,
      16,    11,    12,    47,    48,    26,    27,    37,    -1,    21,
      20,    32,    24,    25,    30,    31,    -1,    11,    12,    11,
      12,    -1,    34,    11,    12,    37,    20,    -1,    20,    11,
      12,    -1,    20,    11,    12,    11,    12,    -1,    20,    11,
      12,    -1,    20,    42,    20,    -1,    45,    46,    20,     4,
       5,     6,     7,    33,    34,    35,    36,    -1,    89,    90,
      91,    92,    98,    99,   100,   101,    86,    87,    88,    95,
      96,    97,    45,    46,    11,    12,    24,    25,    17,    18,
      84,    85,    93,    94
  };

  const signed char
  parser::yystos_[] =
  {
       0,    47,    48,    50,     3,    39,    40,    45,    46,    51,
      53,    54,    55,    60,    61,    52,    54,    55,     0,     4,
       5,     6,     7,    67,    67,    54,    41,    53,    55,    60,
      65,    61,     9,    10,    62,    63,    64,    54,    43,    55,
      65,    64,    41,    55,    65,    42,    56,    57,     8,    21,
      24,    25,    34,    37,    66,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    60,    20,    25,    43,    55,    65,
      44,    53,    58,    59,    57,    68,    53,    56,    68,    75,
      75,    75,    75,    20,    11,    12,    13,    14,    28,    15,
      16,    30,    31,    24,    25,    26,    27,    32,    33,    34,
      35,    36,    17,    18,    66,    63,    64,    53,    59,    68,
      53,    58,    53,    20,    22,    68,    69,    69,    70,    70,
      70,    71,    71,    71,    71,    72,    72,    73,    73,    73,
      74,    74,    74,    74,    75,    75,    53,    20,    68,    68,
      20,    68,    20,    68,    20,    68,    20,    68,    20,    68,
      20,    68,    20,    68
  };

  const signed char
  parser::yyr1_[] =
  {
       0,    49,    50,    50,    51,    51,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      53,    53,    54,    54,    55,    55,    55,    56,    57,    57,
      58,    59,    59,    60,    61,    61,    62,    62,    63,    64,
      64,    65,    65,    66,    66,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    69,    69,    70,    70,    70,    70,
      70,    71,    71,    71,    72,    72,    72,    72,    73,    73,
      73,    73,    73,    74,    74,    74,    75,    75,    75,    75,
      75,    76,    76
  };

  const signed char
  parser::yyr2_[] =
  {
       0,     2,     2,     2,     1,     2,     2,     4,     3,     3,
       5,     1,     2,     2,     3,     4,     3,     3,     4,     5,
       1,     1,     1,     2,     1,     2,     1,    18,     1,     2,
       4,     1,     2,     2,     2,     3,     1,     3,     3,     1,
       1,     2,     3,     1,     3,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     3,     1,     3,     3,     3,
       3,     1,     3,     3,     1,     3,     3,     3,     1,     3,
       3,     3,     3,     1,     3,     3,     1,     2,     2,     2,
       2,     1,     3
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
     209,   218,   224,   228,   236,   241,   246,   251,   259,   265,
     274,   278,   285,   289,   297,   302,   308,   313,   328,   332,
     340,   348,   352,   360,   367,   371,   378,   382,   390,   398,
     402,   409,   430,   457,   461,   469,   473,   477,   481,   488,
     493,   498,   505,   509,   513,   517,   524,   528,   532,   536,
     540,   547,   551,   555,   562,   566,   570,   574,   581,   585,
     589,   593,   597,   604,   608,   612,   619,   623,   627,   631,
     636,   643,   647
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
#line 2163 "syntactic.cpp"

#line 653 "syntactic.y"

