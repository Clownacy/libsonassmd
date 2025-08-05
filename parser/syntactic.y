/*
 * Copyright (C) 2022-2025 Clownacy
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License as published
 * by the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Affero General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

%language "c++"

%require "3.2"

%define api.prefix {libsonassmd_code_reader_yy}
%define api.namespace {libsonassmd::CodeReader}

%define api.token.raw
%define api.token.constructor 
%define api.value.type variant 

%parse-param {Output &output}
%parse-param {Game game}
%parse-param {Lexer &lexer}

%define parse.error verbose

%code requires {

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

}

%code provides {

}

%code {

#include <initializer_list>
#include "lexical.h"

#undef yylex
#define yylex(x) lexer(x)

}

%define api.token.prefix {TOKEN_}

%token DIRECTIVE_DC
%token SIZE_BYTE
%token SIZE_SHORT
%token SIZE_WORD
%token SIZE_LONGWORD
%token<unsigned long> NUMBER
%token<std::string> IDENTIFIER
%token<std::string> LOCAL_IDENTIFIER
%token LOGICAL_AND
%token LOGICAL_OR
%token EQUALITY
%token INEQUALITY
%token LESS_OR_EQUAL
%token MORE_OR_EQUAL
%token LEFT_SHIFT
%token RIGHT_SHIFT
%token PERIOD "."
%token COMMA ","
%token PARENTHESIS_LEFT "("
%token PARENTHESIS_RIGHT ")"
%token DOLLAR "$"
%token PLUS "+"
%token MINUS "-"
%token ASTERIX "*"
%token FORWARD_SLASH "/"
%token EQUAL "="
%token AT "@"
%token LESS "<"
%token MORE ">"
%token PERCENT "%"
%token AMPERSAND "&"
%token EXCLAMATION "!"
%token VERTICAL_BAR "|"
%token CARET "^"
%token TILDE "~"
%token COLON ":"
%token MAPPINGS_TABLE
%token MAPPINGS_TABLE_ENTRY
%token SPRITE_HEADER
%token SPRITE_PIECE
%token DPLC_HEADER
%token DPLC_ENTRY
%token<std::string> LABEL
%token<std::string> LOCAL_LABEL
%token START_MAPPINGS
%token START_DPLCS

%type<Mappings> mappings
%type<DPLCs> dplcs
%type<StringList> offset_table
%type<std::string> label offset_table_entry
%type<StringList> labels
%type<std::vector<unsigned long>> expression_list
%type<std::stringstream> bytes
%type<SpritePiece> sprite_piece;
%type<SpriteFrame> sprite_frame;
%type<DynamicPatternLoadCue::Copy> dplc_copy;
%type<DynamicPatternLoadCue> dplc_frame;
%type<Size> size
%type<Size> dc
%type<unsigned long> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8

%start output

%%

output
	: START_MAPPINGS mappings
	{
		output = std::move($2);
	}
	| START_DPLCS dplcs
	{
		output = std::move($2);
	}
	;

mappings
	: offset_table
	{
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		$$.offset_tables.emplace_back(std::move($1));
	}
	| labels offset_table
	{
		$$.offset_tables.emplace_back(std::move($2));
	}
	| labels bytes
	{
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const SpriteFrame frame($2, game);
		for (const auto &label : $1)
			$$.frames.insert({label, frame});
	}
	| labels SPRITE_HEADER sprite_frame label
	{
		for (const auto &label : $1)
			$$.frames.insert({label, $3});
	}
	| mappings labels offset_table
	{
		$$ = std::move($1);
		$$.offset_tables.emplace_back(std::move($3));
	}
	| mappings labels bytes
	{
		$$ = std::move($1);
		// TODO: Catch exceptions?
		const SpriteFrame frame($3, game);
		for (const auto &label : $2)
			$$.frames.insert({label, frame});
	}
	| mappings labels SPRITE_HEADER sprite_frame label
	{
		$$ = std::move($1);
		for (const auto &label : $2)
			$$.frames.insert({label, $4});
	}
	;

dplcs
	: offset_table
	{
		// A label-less offset table can occur at the start of the file, but no later.
		// This restriction is important for avoiding shift-reduce conflicts.
		$$.offset_tables.emplace_back(std::move($1));
	}
	| labels offset_table
	{
		$$.offset_tables.emplace_back(std::move($2));
	}
	| labels bytes
	{
		// TODO: Catch exceptions?
		// TODO: Deduplicate this all, dammit!
		const DynamicPatternLoadCue frame($2);
		for (const auto &label : $1)
			$$.frames.insert({label, frame});
	}
	| labels DPLC_HEADER dplc_frame label
	{
		for (const auto &label : $1)
			$$.frames.insert({label, $3});
	}
	| dplcs labels offset_table
	{
		$$ = std::move($1);
		$$.offset_tables.emplace_back(std::move($3));
	}
	| dplcs labels bytes
	{
		$$ = std::move($1);
		// TODO: Catch exceptions?
		const DynamicPatternLoadCue frame($3);
		for (const auto &label : $2)
			$$.frames.insert({label, frame});
	}
	| dplcs labels DPLC_HEADER dplc_frame label
	{
		$$ = std::move($1);
		for (const auto &label : $2)
			$$.frames.insert({label, $4});
	}
	;

label
	: LABEL
	{
		$$ = std::move($1);
	}
	| LOCAL_LABEL
	{
		$$ = std::move($1);
	}
	;

labels
	: label
	{
		$$.emplace_back(std::move($1));
	}
	| labels label
	{
		$$ = std::move($1);
		$$.emplace_back(std::move($2));
	}
	;

offset_table
	: offset_table_entry
	{
		$$.emplace_back(std::move($1));
	}
	| offset_table offset_table_entry
	{
		$$ = std::move($1);
		$$.emplace_back(std::move($2));
	}
	| MAPPINGS_TABLE
	{}
	;

sprite_piece
	: SPRITE_PIECE expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression "," expression
	{
		$$.x = $2;
		$$.y = $4;
		$$.width = $6;
		$$.height = $8;
		$$.tile_index = $10;
		$$.x_flip = $12;
		$$.y_flip = $14;
		$$.palette_line = $16;
		$$.priority = $18;
	}
	;

sprite_frame
	: sprite_piece
	{
		$$.pieces.emplace_back(std::move($1));
	}
	| sprite_frame sprite_piece
	{
		$$ = std::move($1);
		$$.pieces.emplace_back(std::move($2));
	}
	;

dplc_copy
	: DPLC_ENTRY expression "," expression
	{
		$$.start = $2;
		$$.length = $4;
	}
	;

dplc_frame
	: dplc_copy
	{
		$$.copies.emplace_back(std::move($1));
	}
	| dplc_frame dplc_copy
	{
		$$ = std::move($1);
		$$.copies.emplace_back(std::move($2));
	}
	;

dc
	: DIRECTIVE_DC size
	{
		$$ = $2;
	}
	;

offset_table_entry
	: dc IDENTIFIER "-" IDENTIFIER
	{
		static_cast<void>($4);
		$$ = std::move($2);
	}
	| MAPPINGS_TABLE_ENTRY size IDENTIFIER
	{
		$$ = std::move($3);
	}
	;

bytes
	: dc expression_list
	{
		for (const auto &value : $2)
		{
			switch ($1)
			{
				case Size::BYTE:
					libsonassmd::WriteU8($$, value);
					break;

				case Size::SHORT:
				case Size::WORD:
					libsonassmd::WriteU16BE($$, value);
					break;

				case Size::LONGWORD:
					libsonassmd::WriteU32BE($$, value);
					break;
			}
		}
	}
	| bytes dc expression_list
	{
		$$ = std::move($1);

		// TODO: Deduplicate this.
		for (const auto &value : $3)
		{
			switch ($2)
			{
				case Size::BYTE:
					libsonassmd::WriteU8($$, value);
					break;

				case Size::SHORT:
				case Size::WORD:
					libsonassmd::WriteU16BE($$, value);
					break;

				case Size::LONGWORD:
					libsonassmd::WriteU32BE($$, value);
					break;
			}
		}
	}
	;

expression_list
	: expression
	{
		$$.emplace_back(std::move($1));
	}
	| expression_list "," expression
	{
		$$ = std::move($1);
		$$.emplace_back(std::move($3));
	}
	;

size
	: SIZE_BYTE
	{
		$$ = Size::BYTE;
	}
	| SIZE_SHORT
	{
		$$ = Size::SHORT;
	}
	| SIZE_WORD
	{
		$$ = Size::WORD;
	}
	| SIZE_LONGWORD
	{
		$$ = Size::LONGWORD;
	}
	;

expression
	: expression1
	{
		$$ = $1;
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| expression LOGICAL_AND expression1
	{
		$$ = $1 && $3;
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| expression LOGICAL_OR expression1
	{
		$$ = $1 || $3;
	}
	;

expression1
	: expression2
	{
		$$ = $1;
	}
	| expression1 "=" expression2
	{
		$$ = $1 == $3;
	}
	| expression1 EQUALITY expression2
	{
		$$ = $1 == $3;
	}
	| expression1 INEQUALITY expression2
	{
		$$ = $1 != $3;
	}
	;

expression2
	: expression3
	{
		$$ = $1;
	}
	| expression2 "<" expression3
	{
		$$ = $1 < $3;
	}
	| expression2 LESS_OR_EQUAL expression3
	{
		$$ = $1 <= $3;
	}
	| expression2 ">" expression3
	{
		$$ = $1 > $3;
	}
	| expression2 MORE_OR_EQUAL expression3
	{
		$$ = $1 >= $3;
	}
	;

expression3
	: expression4
	{
		$$ = $1;
	}
	| expression3 "+" expression4
	{
		$$ = $1 + $3;
	}
	| expression3 "-" expression4
	{
		$$ = $1 - $3;
	}
	;

expression4
	: expression5
	{
		$$ = $1;
	}
	| expression4 "*" expression5
	{
		$$ = $1 * $3;
	}
	| expression4 "/" expression5
	{
		$$ = $1 / $3;
	}
	| expression4 "%" expression5
	{
		$$ = $1 % $3;
	}
	;

expression5
	: expression6
	{
		$$ = $1;
	}
	| expression5 "&" expression6
	{
		$$ = $1 & $3;
	}
	| expression5 "!" expression6
	{
		$$ = $1 | $3;
	}
	| expression5 "|" expression6
	{
		$$ = $1 | $3;
	}
	| expression5 "^" expression6
	{
		$$ = $1 ^ $3;
	}
	;

expression6
	: expression7
	{
		$$ = $1;
	}
	| expression6 LEFT_SHIFT expression7
	{
		$$ = $1 << $3;
	}
	| expression6 RIGHT_SHIFT expression7
	{
		$$ = $1 >> $3;
	}
	;

expression7
	: expression8
	{
		$$ = $1;
	}
	| "+" expression7
	{
		$$ = $2;
	}
	| "-" expression7
	{
		$$ = -$2;
	}
	| "~" expression7
	{
		$$ = ~$2;
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| "!" expression7
	{
		$$ = !$2;
	}
	;

expression8
	: NUMBER
	{
		$$ = $1;
	}
	| "(" expression ")"
	{
		$$ = $2;
	}
	;

%%
