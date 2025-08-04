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

%define parse.trace

%language "c++"

%require "3.2"

%define api.prefix {m68kasm_}
%define api.namespace {m68kasm}

%define api.token.raw
%define api.token.constructor 
%define api.value.type variant 

%param {void *scanner}

%parse-param {Statement *statement}

%define parse.error verbose

%code requires {

#include <string>
#include <variant>
#include <vector>

enum Size
{
	SIZE_BYTE      = 1 << 0,
	SIZE_SHORT     = 1 << 1,
	SIZE_WORD      = 1 << 2,
	SIZE_LONGWORD  = 1 << 3,
	SIZE_UNDEFINED = 1 << 4
};

struct StatementDc
{
	Size size;
	std::vector<unsigned long> values;
};

enum StatementType
{
	STATEMENT_TYPE_EMPTY,
	STATEMENT_TYPE_OFFSET_TABLE,
	STATEMENT_TYPE_EVEN
};

struct Statement
{
	StatementType type;
	std::variant<std::monostate, StatementDc, std::string, std::vector<std::string>> shared;
};

}

%code provides {

#define YY_DECL m68kasm::parser::symbol_type m68kasm_lex(void *yyscanner)

}

%code {

#include <initializer_list>

YY_DECL;
void m68kasm_error(const std::string &message);

void m68kasm::parser::error(const std::string &message)
{
	m68kasm_error(message);
}

}

%define api.token.prefix {TOKEN_}

%token DIRECTIVE_DC
%token DIRECTIVE_EVEN
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

%type<Size> size
%type<std::vector<std::string>> offset_table
%type<std::string> label offset_table_entry
%type<std::vector<unsigned long>> expression_list
%type<unsigned long> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8

%start statement

%%

statement
	:
	{
		statement->type = STATEMENT_TYPE_EMPTY;
	}
	| label offset_table
	{
		statement->type = STATEMENT_TYPE_OFFSET_TABLE;
		statement->shared.emplace<std::vector<std::string>>(std::move($2));
	}
	| offset_table
	{
		statement->type = STATEMENT_TYPE_OFFSET_TABLE;
		statement->shared.emplace<std::vector<std::string>>(std::move($1));
	}
	| DIRECTIVE_EVEN
	{
		statement->type = STATEMENT_TYPE_EVEN;
	}
	;

label
	: IDENTIFIER ":"
	{
		$$ = std::move($1);
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
	;

offset_table_entry
	: DIRECTIVE_DC size IDENTIFIER "-" IDENTIFIER
	{
		static_cast<void>($5);
		$$ = std::move($3);
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
		$$ = SIZE_BYTE;
	}
	| SIZE_SHORT
	{
		$$ = SIZE_SHORT;
	}
	| SIZE_WORD
	{
		$$ = SIZE_WORD;
	}
	| SIZE_LONGWORD
	{
		$$ = SIZE_LONGWORD;
	}
	;

/*
number
	: NUMBER
	| "$" NUMBER
	;
*/
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
