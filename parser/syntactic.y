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

/*%define parse.trace*/

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

#include <variant>
#include <vector>

#include "string.h"

// Temporary junk!
#define YYNOMEM YYERROR

#define CREATE_LIST_TYPE(TYPE)\
typedef struct TYPE\
{\
	TYPE##Node *head;\
	TYPE##Node *tail;\
} TYPE

typedef enum Size
{
	SIZE_BYTE      = 1 << 0,
	SIZE_SHORT     = 1 << 1,
	SIZE_WORD      = 1 << 2,
	SIZE_LONGWORD  = 1 << 3,
	SIZE_UNDEFINED = 1 << 4
} Size;

typedef enum ExpressionType
{
	EXPRESSION_SUBTRACT,
	EXPRESSION_ADD,
	EXPRESSION_MULTIPLY,
	EXPRESSION_DIVIDE,
	EXPRESSION_MODULO,
	EXPRESSION_NEGATE,
	EXPRESSION_LOGICAL_NOT,
	EXPRESSION_LOGICAL_OR,
	EXPRESSION_LOGICAL_AND,
	EXPRESSION_BITWISE_NOT,
	EXPRESSION_BITWISE_OR,
	EXPRESSION_BITWISE_XOR,
	EXPRESSION_BITWISE_AND,
	EXPRESSION_EQUALITY,
	EXPRESSION_INEQUALITY,
	EXPRESSION_LESS_THAN,
	EXPRESSION_LESS_OR_EQUAL,
	EXPRESSION_MORE_THAN,
	EXPRESSION_MORE_OR_EQUAL,
	EXPRESSION_LEFT_SHIFT,
	EXPRESSION_RIGHT_SHIFT,
	EXPRESSION_NUMBER
} ExpressionType;

typedef struct Expression
{
	ExpressionType type;
	std::variant<std::monostate, unsigned long, String, std::vector<Expression>> shared;
} Expression;

typedef struct IdentifierListNode
{
	struct IdentifierListNode *next;

	String identifier;
} IdentifierListNode;

CREATE_LIST_TYPE(IdentifierList);

typedef struct StatementDc
{
	Size size;
	std::vector<Expression> values;
} StatementDc;

typedef enum StatementType
{
	STATEMENT_TYPE_EMPTY,
	STATEMENT_TYPE_DC,
	STATEMENT_TYPE_EVEN
} StatementType;

typedef struct Statement
{
	StatementType type;
	std::variant<std::monostate, StatementDc, Expression, String> shared;
} Statement;

}

%code provides {

#define YY_DECL m68kasm::parser::symbol_type m68kasm_lex(void *yyscanner)

}

%code {

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

}

%define api.token.prefix {TOKEN_}

%token DIRECTIVE_DC
%token DIRECTIVE_EVEN
%token SIZE_BYTE
%token SIZE_SHORT
%token SIZE_WORD
%token SIZE_LONGWORD
%token<unsigned long> NUMBER
%token<String> IDENTIFIER
%token<String> LOCAL_IDENTIFIER
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
%type<std::vector<Expression>> expression_list
%type<Expression> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8

%start statement

%%

statement
	:
	{
		statement->type = STATEMENT_TYPE_EMPTY;
	}
	| DIRECTIVE_DC size expression_list
	{
		statement->type = STATEMENT_TYPE_DC;
		statement->shared.emplace<StatementDc>($2, std::move($3));
	}
	| DIRECTIVE_EVEN
	{
		statement->type = STATEMENT_TYPE_EVEN;
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
		DoExpression($$, EXPRESSION_LOGICAL_AND, {std::move($1), std::move($3)});
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| expression LOGICAL_OR expression1
	{
		DoExpression($$, EXPRESSION_LOGICAL_OR, {std::move($1), std::move($3)});
	}
	;

expression1
	: expression2
	{
		$$ = $1;
	}
	| expression1 "=" expression2
	{
		DoExpression($$, EXPRESSION_EQUALITY, {std::move($1), std::move($3)});
	}
	| expression1 EQUALITY expression2
	{
		DoExpression($$, EXPRESSION_EQUALITY, {std::move($1), std::move($3)});
	}
	| expression1 INEQUALITY expression2
	{
		DoExpression($$, EXPRESSION_INEQUALITY, {std::move($1), std::move($3)});
	}
	;

expression2
	: expression3
	{
		$$ = $1;
	}
	| expression2 "<" expression3
	{
		DoExpression($$, EXPRESSION_LESS_THAN, {std::move($1), std::move($3)});
	}
	| expression2 LESS_OR_EQUAL expression3
	{
		DoExpression($$, EXPRESSION_LESS_OR_EQUAL, {std::move($1), std::move($3)});
	}
	| expression2 ">" expression3
	{
		DoExpression($$, EXPRESSION_MORE_THAN, {std::move($1), std::move($3)});
	}
	| expression2 MORE_OR_EQUAL expression3
	{
		DoExpression($$, EXPRESSION_MORE_OR_EQUAL, {std::move($1), std::move($3)});
	}
	;

expression3
	: expression4
	{
		$$ = $1;
	}
	| expression3 "+" expression4
	{
		DoExpression($$, EXPRESSION_ADD, {std::move($1), std::move($3)});
	}
	| expression3 "-" expression4
	{
		DoExpression($$, EXPRESSION_SUBTRACT, {std::move($1), std::move($3)});
	}
	;

expression4
	: expression5
	{
		$$ = $1;
	}
	| expression4 "*" expression5
	{
		DoExpression($$, EXPRESSION_MULTIPLY, {std::move($1), std::move($3)});
	}
	| expression4 "/" expression5
	{
		DoExpression($$, EXPRESSION_DIVIDE, {std::move($1), std::move($3)});
	}
	| expression4 "%" expression5
	{
		DoExpression($$, EXPRESSION_MODULO, {std::move($1), std::move($3)});
	}
	;

expression5
	: expression6
	{
		$$ = $1;
	}
	| expression5 "&" expression6
	{
		DoExpression($$, EXPRESSION_BITWISE_AND, {std::move($1), std::move($3)});
	}
	| expression5 "!" expression6
	{
		DoExpression($$, EXPRESSION_BITWISE_OR, {std::move($1), std::move($3)});
	}
	| expression5 "|" expression6
	{
		DoExpression($$, EXPRESSION_BITWISE_OR, {std::move($1), std::move($3)});
	}
	| expression5 "^" expression6
	{
		DoExpression($$, EXPRESSION_BITWISE_XOR, {std::move($1), std::move($3)});
	}
	;

expression6
	: expression7
	{
		$$ = $1;
	}
	| expression6 LEFT_SHIFT expression7
	{
		DoExpression($$, EXPRESSION_LEFT_SHIFT, {std::move($1), std::move($3)});
	}
	| expression6 RIGHT_SHIFT expression7
	{
		DoExpression($$, EXPRESSION_RIGHT_SHIFT, {std::move($1), std::move($3)});
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
		DoExpression($$, EXPRESSION_NEGATE, {std::move($2)});
	}
	| "~" expression7
	{
		DoExpression($$, EXPRESSION_BITWISE_NOT, {std::move($2)});
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| "!" expression7
	{
		DoExpression($$, EXPRESSION_LOGICAL_NOT, {std::move($2)});
	}
	;

expression8
	: NUMBER
	{
		$$.type = EXPRESSION_NUMBER;
		$$.shared.emplace<unsigned long>($1);
	}
	| "(" expression ")"
	{
		$$ = $2;
	}
	;

%%
