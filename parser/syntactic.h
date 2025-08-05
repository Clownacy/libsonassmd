// A Bison parser, made by GNU Bison 3.8.2.

// Skeleton interface for Bison LALR(1) parsers in C++

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


/**
 ** \file syntactic.h
 ** Define the libsonassmd::CodeReader::parser class.
 */

// C++ LALR(1) parser skeleton written by Akim Demaille.

// DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
// especially those whose name start with YY_ or yy_.  They are
// private implementation details that can be changed or removed.

#ifndef YY_LIBSONASSMD_CODE_READER_YY_SYNTACTIC_H_INCLUDED
# define YY_LIBSONASSMD_CODE_READER_YY_SYNTACTIC_H_INCLUDED
// "%code requires" blocks.
#line 34 "syntactic.y"


#include <map>
#include <sstream>
#include <string>
#include <variant>
#include <vector>

#include "../dynamic-pattern-load-cue.h"
#include "../sprite-frame.h"

namespace libsonassmd
{
	namespace CodeReader
	{
		class Lexer;

		enum class Size
		{
			BYTE,
			SHORT,
			WORD,
			LONGWORD
		};

		using StringList = std::vector<std::string>;

		struct Mappings
		{
			std::vector<StringList> offset_tables;
			std::map<std::string, libsonassmd::SpriteFrame> frames;
		};

		struct DPLCs
		{
			std::vector<StringList> offset_tables;
			std::map<std::string, libsonassmd::DynamicPatternLoadCue> frames;
		};

		using Output = std::variant<Mappings, DPLCs>;
	}
}


#line 94 "syntactic.h"


# include <cstdlib> // std::abort
# include <iostream>
# include <stdexcept>
# include <string>
# include <vector>

#if defined __cplusplus
# define YY_CPLUSPLUS __cplusplus
#else
# define YY_CPLUSPLUS 199711L
#endif

// Support move semantics when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_MOVE           std::move
# define YY_MOVE_OR_COPY   move
# define YY_MOVE_REF(Type) Type&&
# define YY_RVREF(Type)    Type&&
# define YY_COPY(Type)     Type
#else
# define YY_MOVE
# define YY_MOVE_OR_COPY   copy
# define YY_MOVE_REF(Type) Type&
# define YY_RVREF(Type)    const Type&
# define YY_COPY(Type)     const Type&
#endif

// Support noexcept when possible.
#if 201103L <= YY_CPLUSPLUS
# define YY_NOEXCEPT noexcept
# define YY_NOTHROW
#else
# define YY_NOEXCEPT
# define YY_NOTHROW throw ()
#endif

// Support constexpr when possible.
#if 201703 <= YY_CPLUSPLUS
# define YY_CONSTEXPR constexpr
#else
# define YY_CONSTEXPR
#endif



#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Debug traces.  */
#ifndef LIBSONASSMD_CODE_READER_YYDEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define LIBSONASSMD_CODE_READER_YYDEBUG 1
#  else
#   define LIBSONASSMD_CODE_READER_YYDEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define LIBSONASSMD_CODE_READER_YYDEBUG 0
# endif /* ! defined YYDEBUG */
#endif  /* ! defined LIBSONASSMD_CODE_READER_YYDEBUG */

#line 23 "syntactic.y"
namespace libsonassmd { namespace CodeReader {
#line 238 "syntactic.h"




  /// A Bison parser.
  class parser
  {
  public:
#ifdef LIBSONASSMD_CODE_READER_YYSTYPE
# ifdef __GNUC__
#  pragma GCC message "bison: do not #define LIBSONASSMD_CODE_READER_YYSTYPE in C++, use %define api.value.type"
# endif
    typedef LIBSONASSMD_CODE_READER_YYSTYPE value_type;
#else
  /// A buffer to store and retrieve objects.
  ///
  /// Sort of a variant, but does not keep track of the nature
  /// of the stored data, since that knowledge is available
  /// via the current parser state.
  class value_type
  {
  public:
    /// Type of *this.
    typedef value_type self_type;

    /// Empty construction.
    value_type () YY_NOEXCEPT
      : yyraw_ ()
    {}

    /// Construct and fill.
    template <typename T>
    value_type (YY_RVREF (T) t)
    {
      new (yyas_<T> ()) T (YY_MOVE (t));
    }

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    value_type (const self_type&) = delete;
    /// Non copyable.
    self_type& operator= (const self_type&) = delete;
#endif

    /// Destruction, allowed only if empty.
    ~value_type () YY_NOEXCEPT
    {}

# if 201103L <= YY_CPLUSPLUS
    /// Instantiate a \a T in here from \a t.
    template <typename T, typename... U>
    T&
    emplace (U&&... u)
    {
      return *new (yyas_<T> ()) T (std::forward <U>(u)...);
    }
# else
    /// Instantiate an empty \a T in here.
    template <typename T>
    T&
    emplace ()
    {
      return *new (yyas_<T> ()) T ();
    }

    /// Instantiate a \a T in here from \a t.
    template <typename T>
    T&
    emplace (const T& t)
    {
      return *new (yyas_<T> ()) T (t);
    }
# endif

    /// Instantiate an empty \a T in here.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build ()
    {
      return emplace<T> ();
    }

    /// Instantiate a \a T in here from \a t.
    /// Obsolete, use emplace.
    template <typename T>
    T&
    build (const T& t)
    {
      return emplace<T> (t);
    }

    /// Accessor to a built \a T.
    template <typename T>
    T&
    as () YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Const accessor to a built \a T (for %printer).
    template <typename T>
    const T&
    as () const YY_NOEXCEPT
    {
      return *yyas_<T> ();
    }

    /// Swap the content with \a that, of same type.
    ///
    /// Both variants must be built beforehand, because swapping the actual
    /// data requires reading it (with as()), and this is not possible on
    /// unconstructed variants: it would require some dynamic testing, which
    /// should not be the variant's responsibility.
    /// Swapping between built and (possibly) non-built is done with
    /// self_type::move ().
    template <typename T>
    void
    swap (self_type& that) YY_NOEXCEPT
    {
      std::swap (as<T> (), that.as<T> ());
    }

    /// Move the content of \a that to this.
    ///
    /// Destroys \a that.
    template <typename T>
    void
    move (self_type& that)
    {
# if 201103L <= YY_CPLUSPLUS
      emplace<T> (std::move (that.as<T> ()));
# else
      emplace<T> ();
      swap<T> (that);
# endif
      that.destroy<T> ();
    }

# if 201103L <= YY_CPLUSPLUS
    /// Move the content of \a that to this.
    template <typename T>
    void
    move (self_type&& that)
    {
      emplace<T> (std::move (that.as<T> ()));
      that.destroy<T> ();
    }
#endif

    /// Copy the content of \a that to this.
    template <typename T>
    void
    copy (const self_type& that)
    {
      emplace<T> (that.as<T> ());
    }

    /// Destroy the stored \a T.
    template <typename T>
    void
    destroy ()
    {
      as<T> ().~T ();
    }

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    value_type (const self_type&);
    /// Non copyable.
    self_type& operator= (const self_type&);
#endif

    /// Accessor to raw memory as \a T.
    template <typename T>
    T*
    yyas_ () YY_NOEXCEPT
    {
      void *yyp = yyraw_;
      return static_cast<T*> (yyp);
     }

    /// Const accessor to raw memory as \a T.
    template <typename T>
    const T*
    yyas_ () const YY_NOEXCEPT
    {
      const void *yyp = yyraw_;
      return static_cast<const T*> (yyp);
     }

    /// An auxiliary type to compute the largest semantic type.
    union union_type
    {
      // dplcs
      char dummy1[sizeof (DPLCs)];

      // dplc_frame
      char dummy2[sizeof (DynamicPatternLoadCue)];

      // dplc_copy
      char dummy3[sizeof (DynamicPatternLoadCue::Copy)];

      // mappings
      char dummy4[sizeof (Mappings)];

      // dc
      // size
      char dummy5[sizeof (Size)];

      // sprite_frame
      char dummy6[sizeof (SpriteFrame)];

      // sprite_piece
      char dummy7[sizeof (SpritePiece)];

      // labels
      // offset_table
      // offset_table_line
      // offset_table_entries
      char dummy8[sizeof (StringList)];

      // IDENTIFIER
      // LOCAL_IDENTIFIER
      // LABEL
      // LOCAL_LABEL
      // label
      // offset_table_entry
      // identifier
      char dummy9[sizeof (std::string)];

      // bytes
      char dummy10[sizeof (std::stringstream)];

      // expression_list
      char dummy11[sizeof (std::vector<unsigned long>)];

      // NUMBER
      // expression
      // expression1
      // expression2
      // expression3
      // expression4
      // expression5
      // expression6
      // expression7
      // expression8
      char dummy12[sizeof (unsigned long)];
    };

    /// The size of the largest semantic type.
    enum { size = sizeof (union_type) };

    /// A buffer to store semantic values.
    union
    {
      /// Strongest alignment constraints.
      long double yyalign_me_;
      /// A buffer large enough to store any of the semantic values.
      char yyraw_[size];
    };
  };

#endif
    /// Backward compatibility (Bison 3.8).
    typedef value_type semantic_type;


    /// Syntax errors thrown from user actions.
    struct syntax_error : std::runtime_error
    {
      syntax_error (const std::string& m)
        : std::runtime_error (m)
      {}

      syntax_error (const syntax_error& s)
        : std::runtime_error (s.what ())
      {}

      ~syntax_error () YY_NOEXCEPT YY_NOTHROW;
    };

    /// Token kinds.
    struct token
    {
      enum token_kind_type
      {
        TOKEN_LIBSONASSMD_CODE_READER_YYEMPTY = -2,
    TOKEN_YYEOF = 0,               // "end of file"
    TOKEN_LIBSONASSMD_CODE_READER_YYerror = 1, // error
    TOKEN_LIBSONASSMD_CODE_READER_YYUNDEF = 2, // "invalid token"
    TOKEN_DIRECTIVE_DC = 3,        // DIRECTIVE_DC
    TOKEN_SIZE_BYTE = 4,           // SIZE_BYTE
    TOKEN_SIZE_SHORT = 5,          // SIZE_SHORT
    TOKEN_SIZE_WORD = 6,           // SIZE_WORD
    TOKEN_SIZE_LONGWORD = 7,       // SIZE_LONGWORD
    TOKEN_NUMBER = 8,              // NUMBER
    TOKEN_IDENTIFIER = 9,          // IDENTIFIER
    TOKEN_LOCAL_IDENTIFIER = 10,   // LOCAL_IDENTIFIER
    TOKEN_LOGICAL_AND = 11,        // LOGICAL_AND
    TOKEN_LOGICAL_OR = 12,         // LOGICAL_OR
    TOKEN_EQUALITY = 13,           // EQUALITY
    TOKEN_INEQUALITY = 14,         // INEQUALITY
    TOKEN_LESS_OR_EQUAL = 15,      // LESS_OR_EQUAL
    TOKEN_MORE_OR_EQUAL = 16,      // MORE_OR_EQUAL
    TOKEN_LEFT_SHIFT = 17,         // LEFT_SHIFT
    TOKEN_RIGHT_SHIFT = 18,        // RIGHT_SHIFT
    TOKEN_PERIOD = 19,             // "."
    TOKEN_COMMA = 20,              // ","
    TOKEN_PARENTHESIS_LEFT = 21,   // "("
    TOKEN_PARENTHESIS_RIGHT = 22,  // ")"
    TOKEN_DOLLAR = 23,             // "$"
    TOKEN_PLUS = 24,               // "+"
    TOKEN_MINUS = 25,              // "-"
    TOKEN_ASTERIX = 26,            // "*"
    TOKEN_FORWARD_SLASH = 27,      // "/"
    TOKEN_EQUAL = 28,              // "="
    TOKEN_AT = 29,                 // "@"
    TOKEN_LESS = 30,               // "<"
    TOKEN_MORE = 31,               // ">"
    TOKEN_PERCENT = 32,            // "%"
    TOKEN_AMPERSAND = 33,          // "&"
    TOKEN_EXCLAMATION = 34,        // "!"
    TOKEN_VERTICAL_BAR = 35,       // "|"
    TOKEN_CARET = 36,              // "^"
    TOKEN_TILDE = 37,              // "~"
    TOKEN_COLON = 38,              // ":"
    TOKEN_MAPPINGS_TABLE = 39,     // MAPPINGS_TABLE
    TOKEN_MAPPINGS_TABLE_ENTRY = 40, // MAPPINGS_TABLE_ENTRY
    TOKEN_SPRITE_HEADER = 41,      // SPRITE_HEADER
    TOKEN_SPRITE_PIECE = 42,       // SPRITE_PIECE
    TOKEN_DPLC_HEADER = 43,        // DPLC_HEADER
    TOKEN_DPLC_ENTRY = 44,         // DPLC_ENTRY
    TOKEN_LABEL = 45,              // LABEL
    TOKEN_LOCAL_LABEL = 46,        // LOCAL_LABEL
    TOKEN_START_MAPPINGS = 47,     // START_MAPPINGS
    TOKEN_START_DPLCS = 48         // START_DPLCS
      };
      /// Backward compatibility alias (Bison 3.6).
      typedef token_kind_type yytokentype;
    };

    /// Token kind, as returned by yylex.
    typedef token::token_kind_type token_kind_type;

    /// Backward compatibility alias (Bison 3.6).
    typedef token_kind_type token_type;

    /// Symbol kinds.
    struct symbol_kind
    {
      enum symbol_kind_type
      {
        YYNTOKENS = 49, ///< Number of tokens.
        S_YYEMPTY = -2,
        S_YYEOF = 0,                             // "end of file"
        S_YYerror = 1,                           // error
        S_YYUNDEF = 2,                           // "invalid token"
        S_DIRECTIVE_DC = 3,                      // DIRECTIVE_DC
        S_SIZE_BYTE = 4,                         // SIZE_BYTE
        S_SIZE_SHORT = 5,                        // SIZE_SHORT
        S_SIZE_WORD = 6,                         // SIZE_WORD
        S_SIZE_LONGWORD = 7,                     // SIZE_LONGWORD
        S_NUMBER = 8,                            // NUMBER
        S_IDENTIFIER = 9,                        // IDENTIFIER
        S_LOCAL_IDENTIFIER = 10,                 // LOCAL_IDENTIFIER
        S_LOGICAL_AND = 11,                      // LOGICAL_AND
        S_LOGICAL_OR = 12,                       // LOGICAL_OR
        S_EQUALITY = 13,                         // EQUALITY
        S_INEQUALITY = 14,                       // INEQUALITY
        S_LESS_OR_EQUAL = 15,                    // LESS_OR_EQUAL
        S_MORE_OR_EQUAL = 16,                    // MORE_OR_EQUAL
        S_LEFT_SHIFT = 17,                       // LEFT_SHIFT
        S_RIGHT_SHIFT = 18,                      // RIGHT_SHIFT
        S_PERIOD = 19,                           // "."
        S_COMMA = 20,                            // ","
        S_PARENTHESIS_LEFT = 21,                 // "("
        S_PARENTHESIS_RIGHT = 22,                // ")"
        S_DOLLAR = 23,                           // "$"
        S_PLUS = 24,                             // "+"
        S_MINUS = 25,                            // "-"
        S_ASTERIX = 26,                          // "*"
        S_FORWARD_SLASH = 27,                    // "/"
        S_EQUAL = 28,                            // "="
        S_AT = 29,                               // "@"
        S_LESS = 30,                             // "<"
        S_MORE = 31,                             // ">"
        S_PERCENT = 32,                          // "%"
        S_AMPERSAND = 33,                        // "&"
        S_EXCLAMATION = 34,                      // "!"
        S_VERTICAL_BAR = 35,                     // "|"
        S_CARET = 36,                            // "^"
        S_TILDE = 37,                            // "~"
        S_COLON = 38,                            // ":"
        S_MAPPINGS_TABLE = 39,                   // MAPPINGS_TABLE
        S_MAPPINGS_TABLE_ENTRY = 40,             // MAPPINGS_TABLE_ENTRY
        S_SPRITE_HEADER = 41,                    // SPRITE_HEADER
        S_SPRITE_PIECE = 42,                     // SPRITE_PIECE
        S_DPLC_HEADER = 43,                      // DPLC_HEADER
        S_DPLC_ENTRY = 44,                       // DPLC_ENTRY
        S_LABEL = 45,                            // LABEL
        S_LOCAL_LABEL = 46,                      // LOCAL_LABEL
        S_START_MAPPINGS = 47,                   // START_MAPPINGS
        S_START_DPLCS = 48,                      // START_DPLCS
        S_YYACCEPT = 49,                         // $accept
        S_output = 50,                           // output
        S_mappings = 51,                         // mappings
        S_dplcs = 52,                            // dplcs
        S_label = 53,                            // label
        S_labels = 54,                           // labels
        S_offset_table = 55,                     // offset_table
        S_sprite_piece = 56,                     // sprite_piece
        S_sprite_frame = 57,                     // sprite_frame
        S_dplc_copy = 58,                        // dplc_copy
        S_dplc_frame = 59,                       // dplc_frame
        S_dc = 60,                               // dc
        S_offset_table_line = 61,                // offset_table_line
        S_offset_table_entries = 62,             // offset_table_entries
        S_offset_table_entry = 63,               // offset_table_entry
        S_identifier = 64,                       // identifier
        S_bytes = 65,                            // bytes
        S_expression_list = 66,                  // expression_list
        S_size = 67,                             // size
        S_expression = 68,                       // expression
        S_expression1 = 69,                      // expression1
        S_expression2 = 70,                      // expression2
        S_expression3 = 71,                      // expression3
        S_expression4 = 72,                      // expression4
        S_expression5 = 73,                      // expression5
        S_expression6 = 74,                      // expression6
        S_expression7 = 75,                      // expression7
        S_expression8 = 76                       // expression8
      };
    };

    /// (Internal) symbol kind.
    typedef symbol_kind::symbol_kind_type symbol_kind_type;

    /// The number of tokens.
    static const symbol_kind_type YYNTOKENS = symbol_kind::YYNTOKENS;

    /// A complete symbol.
    ///
    /// Expects its Base type to provide access to the symbol kind
    /// via kind ().
    ///
    /// Provide access to semantic value.
    template <typename Base>
    struct basic_symbol : Base
    {
      /// Alias to Base.
      typedef Base super_type;

      /// Default constructor.
      basic_symbol () YY_NOEXCEPT
        : value ()
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      basic_symbol (basic_symbol&& that)
        : Base (std::move (that))
        , value ()
      {
        switch (this->kind ())
    {
      case symbol_kind::S_dplcs: // dplcs
        value.move< DPLCs > (std::move (that.value));
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.move< DynamicPatternLoadCue > (std::move (that.value));
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.move< DynamicPatternLoadCue::Copy > (std::move (that.value));
        break;

      case symbol_kind::S_mappings: // mappings
        value.move< Mappings > (std::move (that.value));
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.move< Size > (std::move (that.value));
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.move< SpriteFrame > (std::move (that.value));
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.move< SpritePiece > (std::move (that.value));
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.move< StringList > (std::move (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
        value.move< std::string > (std::move (that.value));
        break;

      case symbol_kind::S_bytes: // bytes
        value.move< std::stringstream > (std::move (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<unsigned long> > (std::move (that.value));
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
        value.move< unsigned long > (std::move (that.value));
        break;

      default:
        break;
    }

      }
#endif

      /// Copy constructor.
      basic_symbol (const basic_symbol& that);

      /// Constructors for typed symbols.
#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#else
      basic_symbol (typename Base::kind_type t)
        : Base (t)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DPLCs&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DPLCs& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DynamicPatternLoadCue&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DynamicPatternLoadCue& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, DynamicPatternLoadCue::Copy&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const DynamicPatternLoadCue::Copy& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Mappings&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Mappings& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, Size&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const Size& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SpriteFrame&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SpriteFrame& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, SpritePiece&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const SpritePiece& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, StringList&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const StringList& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::string&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::string& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::stringstream&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::stringstream& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, std::vector<unsigned long>&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const std::vector<unsigned long>& v)
        : Base (t)
        , value (v)
      {}
#endif

#if 201103L <= YY_CPLUSPLUS
      basic_symbol (typename Base::kind_type t, unsigned long&& v)
        : Base (t)
        , value (std::move (v))
      {}
#else
      basic_symbol (typename Base::kind_type t, const unsigned long& v)
        : Base (t)
        , value (v)
      {}
#endif

      /// Destroy the symbol.
      ~basic_symbol ()
      {
        clear ();
      }



      /// Destroy contents, and record that is empty.
      void clear () YY_NOEXCEPT
      {
        // User destructor.
        symbol_kind_type yykind = this->kind ();
        basic_symbol<Base>& yysym = *this;
        (void) yysym;
        switch (yykind)
        {
       default:
          break;
        }

        // Value type destructor.
switch (yykind)
    {
      case symbol_kind::S_dplcs: // dplcs
        value.template destroy< DPLCs > ();
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.template destroy< DynamicPatternLoadCue > ();
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.template destroy< DynamicPatternLoadCue::Copy > ();
        break;

      case symbol_kind::S_mappings: // mappings
        value.template destroy< Mappings > ();
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.template destroy< Size > ();
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.template destroy< SpriteFrame > ();
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.template destroy< SpritePiece > ();
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.template destroy< StringList > ();
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
        value.template destroy< std::string > ();
        break;

      case symbol_kind::S_bytes: // bytes
        value.template destroy< std::stringstream > ();
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.template destroy< std::vector<unsigned long> > ();
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
        value.template destroy< unsigned long > ();
        break;

      default:
        break;
    }

        Base::clear ();
      }

      /// The user-facing name of this symbol.
      std::string name () const YY_NOEXCEPT
      {
        return parser::symbol_name (this->kind ());
      }

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// Whether empty.
      bool empty () const YY_NOEXCEPT;

      /// Destructive move, \a s is emptied into this.
      void move (basic_symbol& s);

      /// The semantic value.
      value_type value;

    private:
#if YY_CPLUSPLUS < 201103L
      /// Assignment operator.
      basic_symbol& operator= (const basic_symbol& that);
#endif
    };

    /// Type access provider for token (enum) based symbols.
    struct by_kind
    {
      /// The symbol kind as needed by the constructor.
      typedef token_kind_type kind_type;

      /// Default constructor.
      by_kind () YY_NOEXCEPT;

#if 201103L <= YY_CPLUSPLUS
      /// Move constructor.
      by_kind (by_kind&& that) YY_NOEXCEPT;
#endif

      /// Copy constructor.
      by_kind (const by_kind& that) YY_NOEXCEPT;

      /// Constructor from (external) token numbers.
      by_kind (kind_type t) YY_NOEXCEPT;



      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_kind& that);

      /// The (internal) type number (corresponding to \a type).
      /// \a empty when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// Backward compatibility (Bison 3.6).
      symbol_kind_type type_get () const YY_NOEXCEPT;

      /// The symbol kind.
      /// \a S_YYEMPTY when empty.
      symbol_kind_type kind_;
    };

    /// Backward compatibility for a private implementation detail (Bison 3.6).
    typedef by_kind by_type;

    /// "External" symbols: returned by the scanner.
    struct symbol_type : basic_symbol<by_kind>
    {
      /// Superclass.
      typedef basic_symbol<by_kind> super_type;

      /// Empty symbol.
      symbol_type () YY_NOEXCEPT {}

      /// Constructor for valueless symbols, and symbols from each type.
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#else
      symbol_type (int tok)
        : super_type (token_kind_type (tok))
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, std::string v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const std::string& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
#if 201103L <= YY_CPLUSPLUS
      symbol_type (int tok, unsigned long v)
        : super_type (token_kind_type (tok), std::move (v))
#else
      symbol_type (int tok, const unsigned long& v)
        : super_type (token_kind_type (tok), v)
#endif
      {}
    };

    /// Build a parser object.
    parser (Output &output_yyarg, Lexer &lexer_yyarg);
    virtual ~parser ();

#if 201103L <= YY_CPLUSPLUS
    /// Non copyable.
    parser (const parser&) = delete;
    /// Non copyable.
    parser& operator= (const parser&) = delete;
#endif

    /// Parse.  An alias for parse ().
    /// \returns  0 iff parsing succeeded.
    int operator() ();

    /// Parse.
    /// \returns  0 iff parsing succeeded.
    virtual int parse ();

#if LIBSONASSMD_CODE_READER_YYDEBUG
    /// The current debugging stream.
    std::ostream& debug_stream () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging stream.
    void set_debug_stream (std::ostream &);

    /// Type for debugging levels.
    typedef int debug_level_type;
    /// The current debugging level.
    debug_level_type debug_level () const YY_ATTRIBUTE_PURE;
    /// Set the current debugging level.
    void set_debug_level (debug_level_type l);
#endif

    /// Report a syntax error.
    /// \param msg    a description of the syntax error.
    virtual void error (const std::string& msg);

    /// Report a syntax error.
    void error (const syntax_error& err);

    /// The user-facing name of the symbol whose (internal) number is
    /// YYSYMBOL.  No bounds checking.
    static std::string symbol_name (symbol_kind_type yysymbol);

    // Implementation of make_symbol for each token kind.
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::TOKEN_YYEOF);
      }
#else
      static
      symbol_type
      make_YYEOF ()
      {
        return symbol_type (token::TOKEN_YYEOF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIBSONASSMD_CODE_READER_YYerror ()
      {
        return symbol_type (token::TOKEN_LIBSONASSMD_CODE_READER_YYerror);
      }
#else
      static
      symbol_type
      make_LIBSONASSMD_CODE_READER_YYerror ()
      {
        return symbol_type (token::TOKEN_LIBSONASSMD_CODE_READER_YYerror);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LIBSONASSMD_CODE_READER_YYUNDEF ()
      {
        return symbol_type (token::TOKEN_LIBSONASSMD_CODE_READER_YYUNDEF);
      }
#else
      static
      symbol_type
      make_LIBSONASSMD_CODE_READER_YYUNDEF ()
      {
        return symbol_type (token::TOKEN_LIBSONASSMD_CODE_READER_YYUNDEF);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DIRECTIVE_DC ()
      {
        return symbol_type (token::TOKEN_DIRECTIVE_DC);
      }
#else
      static
      symbol_type
      make_DIRECTIVE_DC ()
      {
        return symbol_type (token::TOKEN_DIRECTIVE_DC);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE_BYTE ()
      {
        return symbol_type (token::TOKEN_SIZE_BYTE);
      }
#else
      static
      symbol_type
      make_SIZE_BYTE ()
      {
        return symbol_type (token::TOKEN_SIZE_BYTE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE_SHORT ()
      {
        return symbol_type (token::TOKEN_SIZE_SHORT);
      }
#else
      static
      symbol_type
      make_SIZE_SHORT ()
      {
        return symbol_type (token::TOKEN_SIZE_SHORT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE_WORD ()
      {
        return symbol_type (token::TOKEN_SIZE_WORD);
      }
#else
      static
      symbol_type
      make_SIZE_WORD ()
      {
        return symbol_type (token::TOKEN_SIZE_WORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SIZE_LONGWORD ()
      {
        return symbol_type (token::TOKEN_SIZE_LONGWORD);
      }
#else
      static
      symbol_type
      make_SIZE_LONGWORD ()
      {
        return symbol_type (token::TOKEN_SIZE_LONGWORD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_NUMBER (unsigned long v)
      {
        return symbol_type (token::TOKEN_NUMBER, std::move (v));
      }
#else
      static
      symbol_type
      make_NUMBER (const unsigned long& v)
      {
        return symbol_type (token::TOKEN_NUMBER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_IDENTIFIER (std::string v)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_IDENTIFIER (const std::string& v)
      {
        return symbol_type (token::TOKEN_IDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOCAL_IDENTIFIER (std::string v)
      {
        return symbol_type (token::TOKEN_LOCAL_IDENTIFIER, std::move (v));
      }
#else
      static
      symbol_type
      make_LOCAL_IDENTIFIER (const std::string& v)
      {
        return symbol_type (token::TOKEN_LOCAL_IDENTIFIER, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGICAL_AND ()
      {
        return symbol_type (token::TOKEN_LOGICAL_AND);
      }
#else
      static
      symbol_type
      make_LOGICAL_AND ()
      {
        return symbol_type (token::TOKEN_LOGICAL_AND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOGICAL_OR ()
      {
        return symbol_type (token::TOKEN_LOGICAL_OR);
      }
#else
      static
      symbol_type
      make_LOGICAL_OR ()
      {
        return symbol_type (token::TOKEN_LOGICAL_OR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUALITY ()
      {
        return symbol_type (token::TOKEN_EQUALITY);
      }
#else
      static
      symbol_type
      make_EQUALITY ()
      {
        return symbol_type (token::TOKEN_EQUALITY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_INEQUALITY ()
      {
        return symbol_type (token::TOKEN_INEQUALITY);
      }
#else
      static
      symbol_type
      make_INEQUALITY ()
      {
        return symbol_type (token::TOKEN_INEQUALITY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS_OR_EQUAL ()
      {
        return symbol_type (token::TOKEN_LESS_OR_EQUAL);
      }
#else
      static
      symbol_type
      make_LESS_OR_EQUAL ()
      {
        return symbol_type (token::TOKEN_LESS_OR_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MORE_OR_EQUAL ()
      {
        return symbol_type (token::TOKEN_MORE_OR_EQUAL);
      }
#else
      static
      symbol_type
      make_MORE_OR_EQUAL ()
      {
        return symbol_type (token::TOKEN_MORE_OR_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LEFT_SHIFT ()
      {
        return symbol_type (token::TOKEN_LEFT_SHIFT);
      }
#else
      static
      symbol_type
      make_LEFT_SHIFT ()
      {
        return symbol_type (token::TOKEN_LEFT_SHIFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_RIGHT_SHIFT ()
      {
        return symbol_type (token::TOKEN_RIGHT_SHIFT);
      }
#else
      static
      symbol_type
      make_RIGHT_SHIFT ()
      {
        return symbol_type (token::TOKEN_RIGHT_SHIFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERIOD ()
      {
        return symbol_type (token::TOKEN_PERIOD);
      }
#else
      static
      symbol_type
      make_PERIOD ()
      {
        return symbol_type (token::TOKEN_PERIOD);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::TOKEN_COMMA);
      }
#else
      static
      symbol_type
      make_COMMA ()
      {
        return symbol_type (token::TOKEN_COMMA);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARENTHESIS_LEFT ()
      {
        return symbol_type (token::TOKEN_PARENTHESIS_LEFT);
      }
#else
      static
      symbol_type
      make_PARENTHESIS_LEFT ()
      {
        return symbol_type (token::TOKEN_PARENTHESIS_LEFT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PARENTHESIS_RIGHT ()
      {
        return symbol_type (token::TOKEN_PARENTHESIS_RIGHT);
      }
#else
      static
      symbol_type
      make_PARENTHESIS_RIGHT ()
      {
        return symbol_type (token::TOKEN_PARENTHESIS_RIGHT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DOLLAR ()
      {
        return symbol_type (token::TOKEN_DOLLAR);
      }
#else
      static
      symbol_type
      make_DOLLAR ()
      {
        return symbol_type (token::TOKEN_DOLLAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::TOKEN_PLUS);
      }
#else
      static
      symbol_type
      make_PLUS ()
      {
        return symbol_type (token::TOKEN_PLUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::TOKEN_MINUS);
      }
#else
      static
      symbol_type
      make_MINUS ()
      {
        return symbol_type (token::TOKEN_MINUS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_ASTERIX ()
      {
        return symbol_type (token::TOKEN_ASTERIX);
      }
#else
      static
      symbol_type
      make_ASTERIX ()
      {
        return symbol_type (token::TOKEN_ASTERIX);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_FORWARD_SLASH ()
      {
        return symbol_type (token::TOKEN_FORWARD_SLASH);
      }
#else
      static
      symbol_type
      make_FORWARD_SLASH ()
      {
        return symbol_type (token::TOKEN_FORWARD_SLASH);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EQUAL ()
      {
        return symbol_type (token::TOKEN_EQUAL);
      }
#else
      static
      symbol_type
      make_EQUAL ()
      {
        return symbol_type (token::TOKEN_EQUAL);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AT ()
      {
        return symbol_type (token::TOKEN_AT);
      }
#else
      static
      symbol_type
      make_AT ()
      {
        return symbol_type (token::TOKEN_AT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LESS ()
      {
        return symbol_type (token::TOKEN_LESS);
      }
#else
      static
      symbol_type
      make_LESS ()
      {
        return symbol_type (token::TOKEN_LESS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MORE ()
      {
        return symbol_type (token::TOKEN_MORE);
      }
#else
      static
      symbol_type
      make_MORE ()
      {
        return symbol_type (token::TOKEN_MORE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_PERCENT ()
      {
        return symbol_type (token::TOKEN_PERCENT);
      }
#else
      static
      symbol_type
      make_PERCENT ()
      {
        return symbol_type (token::TOKEN_PERCENT);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_AMPERSAND ()
      {
        return symbol_type (token::TOKEN_AMPERSAND);
      }
#else
      static
      symbol_type
      make_AMPERSAND ()
      {
        return symbol_type (token::TOKEN_AMPERSAND);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_EXCLAMATION ()
      {
        return symbol_type (token::TOKEN_EXCLAMATION);
      }
#else
      static
      symbol_type
      make_EXCLAMATION ()
      {
        return symbol_type (token::TOKEN_EXCLAMATION);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_VERTICAL_BAR ()
      {
        return symbol_type (token::TOKEN_VERTICAL_BAR);
      }
#else
      static
      symbol_type
      make_VERTICAL_BAR ()
      {
        return symbol_type (token::TOKEN_VERTICAL_BAR);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_CARET ()
      {
        return symbol_type (token::TOKEN_CARET);
      }
#else
      static
      symbol_type
      make_CARET ()
      {
        return symbol_type (token::TOKEN_CARET);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_TILDE ()
      {
        return symbol_type (token::TOKEN_TILDE);
      }
#else
      static
      symbol_type
      make_TILDE ()
      {
        return symbol_type (token::TOKEN_TILDE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_COLON ()
      {
        return symbol_type (token::TOKEN_COLON);
      }
#else
      static
      symbol_type
      make_COLON ()
      {
        return symbol_type (token::TOKEN_COLON);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAPPINGS_TABLE ()
      {
        return symbol_type (token::TOKEN_MAPPINGS_TABLE);
      }
#else
      static
      symbol_type
      make_MAPPINGS_TABLE ()
      {
        return symbol_type (token::TOKEN_MAPPINGS_TABLE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_MAPPINGS_TABLE_ENTRY ()
      {
        return symbol_type (token::TOKEN_MAPPINGS_TABLE_ENTRY);
      }
#else
      static
      symbol_type
      make_MAPPINGS_TABLE_ENTRY ()
      {
        return symbol_type (token::TOKEN_MAPPINGS_TABLE_ENTRY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPRITE_HEADER ()
      {
        return symbol_type (token::TOKEN_SPRITE_HEADER);
      }
#else
      static
      symbol_type
      make_SPRITE_HEADER ()
      {
        return symbol_type (token::TOKEN_SPRITE_HEADER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_SPRITE_PIECE ()
      {
        return symbol_type (token::TOKEN_SPRITE_PIECE);
      }
#else
      static
      symbol_type
      make_SPRITE_PIECE ()
      {
        return symbol_type (token::TOKEN_SPRITE_PIECE);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DPLC_HEADER ()
      {
        return symbol_type (token::TOKEN_DPLC_HEADER);
      }
#else
      static
      symbol_type
      make_DPLC_HEADER ()
      {
        return symbol_type (token::TOKEN_DPLC_HEADER);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_DPLC_ENTRY ()
      {
        return symbol_type (token::TOKEN_DPLC_ENTRY);
      }
#else
      static
      symbol_type
      make_DPLC_ENTRY ()
      {
        return symbol_type (token::TOKEN_DPLC_ENTRY);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LABEL (std::string v)
      {
        return symbol_type (token::TOKEN_LABEL, std::move (v));
      }
#else
      static
      symbol_type
      make_LABEL (const std::string& v)
      {
        return symbol_type (token::TOKEN_LABEL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_LOCAL_LABEL (std::string v)
      {
        return symbol_type (token::TOKEN_LOCAL_LABEL, std::move (v));
      }
#else
      static
      symbol_type
      make_LOCAL_LABEL (const std::string& v)
      {
        return symbol_type (token::TOKEN_LOCAL_LABEL, v);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_START_MAPPINGS ()
      {
        return symbol_type (token::TOKEN_START_MAPPINGS);
      }
#else
      static
      symbol_type
      make_START_MAPPINGS ()
      {
        return symbol_type (token::TOKEN_START_MAPPINGS);
      }
#endif
#if 201103L <= YY_CPLUSPLUS
      static
      symbol_type
      make_START_DPLCS ()
      {
        return symbol_type (token::TOKEN_START_DPLCS);
      }
#else
      static
      symbol_type
      make_START_DPLCS ()
      {
        return symbol_type (token::TOKEN_START_DPLCS);
      }
#endif


    class context
    {
    public:
      context (const parser& yyparser, const symbol_type& yyla);
      const symbol_type& lookahead () const YY_NOEXCEPT { return yyla_; }
      symbol_kind_type token () const YY_NOEXCEPT { return yyla_.kind (); }
      /// Put in YYARG at most YYARGN of the expected tokens, and return the
      /// number of tokens stored in YYARG.  If YYARG is null, return the
      /// number of expected tokens (guaranteed to be less than YYNTOKENS).
      int expected_tokens (symbol_kind_type yyarg[], int yyargn) const;

    private:
      const parser& yyparser_;
      const symbol_type& yyla_;
    };

  private:
#if YY_CPLUSPLUS < 201103L
    /// Non copyable.
    parser (const parser&);
    /// Non copyable.
    parser& operator= (const parser&);
#endif


    /// Stored state numbers (used for stacks).
    typedef unsigned char state_type;

    /// The arguments of the error message.
    int yy_syntax_error_arguments_ (const context& yyctx,
                                    symbol_kind_type yyarg[], int yyargn) const;

    /// Generate an error message.
    /// \param yyctx     the context in which the error occurred.
    virtual std::string yysyntax_error_ (const context& yyctx) const;
    /// Compute post-reduction state.
    /// \param yystate   the current state
    /// \param yysym     the nonterminal to push on the stack
    static state_type yy_lr_goto_state_ (state_type yystate, int yysym);

    /// Whether the given \c yypact_ value indicates a defaulted state.
    /// \param yyvalue   the value to check
    static bool yy_pact_value_is_default_ (int yyvalue) YY_NOEXCEPT;

    /// Whether the given \c yytable_ value indicates a syntax error.
    /// \param yyvalue   the value to check
    static bool yy_table_value_is_error_ (int yyvalue) YY_NOEXCEPT;

    static const signed char yypact_ninf_;
    static const signed char yytable_ninf_;

    /// Convert a scanner token kind \a t to a symbol kind.
    /// In theory \a t should be a token_kind_type, but character literals
    /// are valid, yet not members of the token_kind_type enum.
    static symbol_kind_type yytranslate_ (int t) YY_NOEXCEPT;

    /// Convert the symbol name \a n to a form suitable for a diagnostic.
    static std::string yytnamerr_ (const char *yystr);

    /// For a symbol, its name in clear.
    static const char* const yytname_[];


    // Tables.
    // YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
    // STATE-NUM.
    static const short yypact_[];

    // YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
    // Performed when YYTABLE does not specify something else to do.  Zero
    // means the default is an error.
    static const signed char yydefact_[];

    // YYPGOTO[NTERM-NUM].
    static const short yypgoto_[];

    // YYDEFGOTO[NTERM-NUM].
    static const signed char yydefgoto_[];

    // YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
    // positive, shift that token.  If negative, reduce the rule whose
    // number is the opposite.  If YYTABLE_NINF, syntax error.
    static const unsigned char yytable_[];

    static const short yycheck_[];

    // YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
    // state STATE-NUM.
    static const signed char yystos_[];

    // YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.
    static const signed char yyr1_[];

    // YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.
    static const signed char yyr2_[];


#if LIBSONASSMD_CODE_READER_YYDEBUG
    // YYRLINE[YYN] -- Source line where rule number YYN was defined.
    static const short yyrline_[];
    /// Report on the debug stream that the rule \a r is going to be reduced.
    virtual void yy_reduce_print_ (int r) const;
    /// Print the state stack on the debug stream.
    virtual void yy_stack_print_ () const;

    /// Debugging level.
    int yydebug_;
    /// Debug stream.
    std::ostream* yycdebug_;

    /// \brief Display a symbol kind, value and location.
    /// \param yyo    The output stream.
    /// \param yysym  The symbol.
    template <typename Base>
    void yy_print_ (std::ostream& yyo, const basic_symbol<Base>& yysym) const;
#endif

    /// \brief Reclaim the memory associated to a symbol.
    /// \param yymsg     Why this token is reclaimed.
    ///                  If null, print nothing.
    /// \param yysym     The symbol.
    template <typename Base>
    void yy_destroy_ (const char* yymsg, basic_symbol<Base>& yysym) const;

  private:
    /// Type access provider for state based symbols.
    struct by_state
    {
      /// Default constructor.
      by_state () YY_NOEXCEPT;

      /// The symbol kind as needed by the constructor.
      typedef state_type kind_type;

      /// Constructor.
      by_state (kind_type s) YY_NOEXCEPT;

      /// Copy constructor.
      by_state (const by_state& that) YY_NOEXCEPT;

      /// Record that this symbol is empty.
      void clear () YY_NOEXCEPT;

      /// Steal the symbol kind from \a that.
      void move (by_state& that);

      /// The symbol kind (corresponding to \a state).
      /// \a symbol_kind::S_YYEMPTY when empty.
      symbol_kind_type kind () const YY_NOEXCEPT;

      /// The state number used to denote an empty symbol.
      /// We use the initial state, as it does not have a value.
      enum { empty_state = 0 };

      /// The state.
      /// \a empty when empty.
      state_type state;
    };

    /// "Internal" symbol: element of the stack.
    struct stack_symbol_type : basic_symbol<by_state>
    {
      /// Superclass.
      typedef basic_symbol<by_state> super_type;
      /// Construct an empty symbol.
      stack_symbol_type ();
      /// Move or copy construction.
      stack_symbol_type (YY_RVREF (stack_symbol_type) that);
      /// Steal the contents from \a sym to build this.
      stack_symbol_type (state_type s, YY_MOVE_REF (symbol_type) sym);
#if YY_CPLUSPLUS < 201103L
      /// Assignment, needed by push_back by some old implementations.
      /// Moves the contents of that.
      stack_symbol_type& operator= (stack_symbol_type& that);

      /// Assignment, needed by push_back by other implementations.
      /// Needed by some other old implementations.
      stack_symbol_type& operator= (const stack_symbol_type& that);
#endif
    };

    /// A stack with random access from its top.
    template <typename T, typename S = std::vector<T> >
    class stack
    {
    public:
      // Hide our reversed order.
      typedef typename S::iterator iterator;
      typedef typename S::const_iterator const_iterator;
      typedef typename S::size_type size_type;
      typedef typename std::ptrdiff_t index_type;

      stack (size_type n = 200) YY_NOEXCEPT
        : seq_ (n)
      {}

#if 201103L <= YY_CPLUSPLUS
      /// Non copyable.
      stack (const stack&) = delete;
      /// Non copyable.
      stack& operator= (const stack&) = delete;
#endif

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      const T&
      operator[] (index_type i) const
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Random access.
      ///
      /// Index 0 returns the topmost element.
      T&
      operator[] (index_type i)
      {
        return seq_[size_type (size () - 1 - i)];
      }

      /// Steal the contents of \a t.
      ///
      /// Close to move-semantics.
      void
      push (YY_MOVE_REF (T) t)
      {
        seq_.push_back (T ());
        operator[] (0).move (t);
      }

      /// Pop elements from the stack.
      void
      pop (std::ptrdiff_t n = 1) YY_NOEXCEPT
      {
        for (; 0 < n; --n)
          seq_.pop_back ();
      }

      /// Pop all elements from the stack.
      void
      clear () YY_NOEXCEPT
      {
        seq_.clear ();
      }

      /// Number of elements on the stack.
      index_type
      size () const YY_NOEXCEPT
      {
        return index_type (seq_.size ());
      }

      /// Iterator on top of the stack (going downwards).
      const_iterator
      begin () const YY_NOEXCEPT
      {
        return seq_.begin ();
      }

      /// Bottom of the stack.
      const_iterator
      end () const YY_NOEXCEPT
      {
        return seq_.end ();
      }

      /// Present a slice of the top of a stack.
      class slice
      {
      public:
        slice (const stack& stack, index_type range) YY_NOEXCEPT
          : stack_ (stack)
          , range_ (range)
        {}

        const T&
        operator[] (index_type i) const
        {
          return stack_[range_ - i];
        }

      private:
        const stack& stack_;
        index_type range_;
      };

    private:
#if YY_CPLUSPLUS < 201103L
      /// Non copyable.
      stack (const stack&);
      /// Non copyable.
      stack& operator= (const stack&);
#endif
      /// The wrapped container.
      S seq_;
    };


    /// Stack type.
    typedef stack<stack_symbol_type> stack_type;

    /// The stack.
    stack_type yystack_;

    /// Push a new state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param sym  the symbol
    /// \warning the contents of \a s.value is stolen.
    void yypush_ (const char* m, YY_MOVE_REF (stack_symbol_type) sym);

    /// Push a new look ahead token on the state on the stack.
    /// \param m    a debug message to display
    ///             if null, no trace is output.
    /// \param s    the state
    /// \param sym  the symbol (for its value and location).
    /// \warning the contents of \a sym.value is stolen.
    void yypush_ (const char* m, state_type s, YY_MOVE_REF (symbol_type) sym);

    /// Pop \a n symbols from the stack.
    void yypop_ (int n = 1) YY_NOEXCEPT;

    /// Constants.
    enum
    {
      yylast_ = 222,     ///< Last index in yytable_.
      yynnts_ = 28,  ///< Number of nonterminal symbols.
      yyfinal_ = 18 ///< Termination state number.
    };


    // User arguments.
    Output &output;
    Lexer &lexer;

  };

  inline
  parser::symbol_kind_type
  parser::yytranslate_ (int t) YY_NOEXCEPT
  {
    return static_cast<symbol_kind_type> (t);
  }

  // basic_symbol.
  template <typename Base>
  parser::basic_symbol<Base>::basic_symbol (const basic_symbol& that)
    : Base (that)
    , value ()
  {
    switch (this->kind ())
    {
      case symbol_kind::S_dplcs: // dplcs
        value.copy< DPLCs > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.copy< DynamicPatternLoadCue > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.copy< DynamicPatternLoadCue::Copy > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_mappings: // mappings
        value.copy< Mappings > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.copy< Size > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.copy< SpriteFrame > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.copy< SpritePiece > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.copy< StringList > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
        value.copy< std::string > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_bytes: // bytes
        value.copy< std::stringstream > (YY_MOVE (that.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.copy< std::vector<unsigned long> > (YY_MOVE (that.value));
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
        value.copy< unsigned long > (YY_MOVE (that.value));
        break;

      default:
        break;
    }

  }




  template <typename Base>
  parser::symbol_kind_type
  parser::basic_symbol<Base>::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


  template <typename Base>
  bool
  parser::basic_symbol<Base>::empty () const YY_NOEXCEPT
  {
    return this->kind () == symbol_kind::S_YYEMPTY;
  }

  template <typename Base>
  void
  parser::basic_symbol<Base>::move (basic_symbol& s)
  {
    super_type::move (s);
    switch (this->kind ())
    {
      case symbol_kind::S_dplcs: // dplcs
        value.move< DPLCs > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dplc_frame: // dplc_frame
        value.move< DynamicPatternLoadCue > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dplc_copy: // dplc_copy
        value.move< DynamicPatternLoadCue::Copy > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_mappings: // mappings
        value.move< Mappings > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_dc: // dc
      case symbol_kind::S_size: // size
        value.move< Size > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sprite_frame: // sprite_frame
        value.move< SpriteFrame > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_sprite_piece: // sprite_piece
        value.move< SpritePiece > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_labels: // labels
      case symbol_kind::S_offset_table: // offset_table
      case symbol_kind::S_offset_table_line: // offset_table_line
      case symbol_kind::S_offset_table_entries: // offset_table_entries
        value.move< StringList > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_IDENTIFIER: // IDENTIFIER
      case symbol_kind::S_LOCAL_IDENTIFIER: // LOCAL_IDENTIFIER
      case symbol_kind::S_LABEL: // LABEL
      case symbol_kind::S_LOCAL_LABEL: // LOCAL_LABEL
      case symbol_kind::S_label: // label
      case symbol_kind::S_offset_table_entry: // offset_table_entry
      case symbol_kind::S_identifier: // identifier
        value.move< std::string > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_bytes: // bytes
        value.move< std::stringstream > (YY_MOVE (s.value));
        break;

      case symbol_kind::S_expression_list: // expression_list
        value.move< std::vector<unsigned long> > (YY_MOVE (s.value));
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
        value.move< unsigned long > (YY_MOVE (s.value));
        break;

      default:
        break;
    }

  }

  // by_kind.
  inline
  parser::by_kind::by_kind () YY_NOEXCEPT
    : kind_ (symbol_kind::S_YYEMPTY)
  {}

#if 201103L <= YY_CPLUSPLUS
  inline
  parser::by_kind::by_kind (by_kind&& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {
    that.clear ();
  }
#endif

  inline
  parser::by_kind::by_kind (const by_kind& that) YY_NOEXCEPT
    : kind_ (that.kind_)
  {}

  inline
  parser::by_kind::by_kind (token_kind_type t) YY_NOEXCEPT
    : kind_ (yytranslate_ (t))
  {}



  inline
  void
  parser::by_kind::clear () YY_NOEXCEPT
  {
    kind_ = symbol_kind::S_YYEMPTY;
  }

  inline
  void
  parser::by_kind::move (by_kind& that)
  {
    kind_ = that.kind_;
    that.clear ();
  }

  inline
  parser::symbol_kind_type
  parser::by_kind::kind () const YY_NOEXCEPT
  {
    return kind_;
  }


  inline
  parser::symbol_kind_type
  parser::by_kind::type_get () const YY_NOEXCEPT
  {
    return this->kind ();
  }


#line 23 "syntactic.y"
} } // libsonassmd::CodeReader
#line 2506 "syntactic.h"


// "%code provides" blocks.
#line 79 "syntactic.y"



#line 2514 "syntactic.h"


#endif // !YY_LIBSONASSMD_CODE_READER_YY_SYNTACTIC_H_INCLUDED
