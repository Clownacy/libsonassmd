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

%param {void *scanner}

%parse-param {Statement *statement}

%define parse.error verbose

%code requires {

#include "string.h"

// Temporary junk!
#define YYNOMEM YYERROR

#define YYSTYPE m68kasm::parser::semantic_type

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
	union
	{
		unsigned long unsigned_long;
		String string;
		struct Expression *subexpressions;
	} shared;
} Expression;

typedef struct ExpressionListNode
{
	struct ExpressionListNode *next;

	Expression expression;
} ExpressionListNode;

CREATE_LIST_TYPE(ExpressionList);

typedef struct IdentifierListNode
{
	struct IdentifierListNode *next;

	String identifier;
} IdentifierListNode;

CREATE_LIST_TYPE(IdentifierList);

typedef struct StatementDc
{
	Size size;
	ExpressionList values;
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
	union
	{
		StatementDc dc;
		Expression expression;
		String string;
	} shared;
} Statement;

}

%code provides {

void DestroyExpression(Expression *expression);
void DestroyStatement(Statement *statement);

}

%code {

#include <assert.h>
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

int m68kasm_lex(YYSTYPE *yylval_param, void *yyscanner);
void m68kasm_warning(void *scanner, Statement *statement, const char *message);
void m68kasm_warning_pedantic(void *scanner, Statement *statement, const char *message);
void m68kasm_error(void *scanner, Statement *statement, const char *message);

static bool DoExpressionTriple(Expression *expression, ExpressionType type, Expression *left_expression, Expression *middle_expression, Expression *right_expression);
static bool DoExpression(Expression *expression, ExpressionType type, Expression *left_expression, Expression *right_expression);
static void DestroyExpressionList(ExpressionList *list);

void m68kasm::parser::error(const std::string &message)
{
	m68kasm_error(nullptr, nullptr, message.c_str());
}

}

%union {
	unsigned long unsigned_long;
	String string;
	Size size;
	Statement statement;
	ExpressionList expression_list;
	Expression expression;
}

%token TOKEN_DIRECTIVE_DC
%token TOKEN_DIRECTIVE_EVEN
%token TOKEN_SIZE_BYTE
%token TOKEN_SIZE_SHORT
%token TOKEN_SIZE_WORD
%token TOKEN_SIZE_LONGWORD
%token<unsigned_long> TOKEN_NUMBER
%token<string> TOKEN_IDENTIFIER
%token<string> TOKEN_LOCAL_IDENTIFIER
%token TOKEN_LOGICAL_AND
%token TOKEN_LOGICAL_OR
%token TOKEN_EQUALITY
%token TOKEN_INEQUALITY
%token TOKEN_LESS_OR_EQUAL
%token TOKEN_MORE_OR_EQUAL
%token TOKEN_LEFT_SHIFT
%token TOKEN_RIGHT_SHIFT

%type<size> size
%type<expression_list> expression_list
%type<expression> expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8

%destructor { String_Destroy(&$$); } TOKEN_IDENTIFIER TOKEN_LOCAL_IDENTIFIER
%destructor { DestroyExpressionList(&$$); } expression_list
%destructor { DestroyExpression(&$$); } expression expression1 expression2 expression3 expression4 expression5 expression6 expression7 expression8

%start statement

%%

statement
	:
	{
		statement->type = STATEMENT_TYPE_EMPTY;
	}
	| TOKEN_DIRECTIVE_DC size expression_list
	{
		statement->type = STATEMENT_TYPE_DC;
		statement->shared.dc.size = $2;
		statement->shared.dc.values = $3;
	}
	| TOKEN_DIRECTIVE_EVEN
	{
		statement->type = STATEMENT_TYPE_EVEN;
	}
	;

expression_list
	: expression
	{
		ExpressionListNode *node = (ExpressionListNode*)malloc(sizeof(ExpressionListNode));

		if (node == NULL)
		{
			DestroyExpression(&$1);
			YYNOMEM;
		}
		else
		{
			node->expression = $1;
			node->next = NULL;
		}

		$$.head = $$.tail = node;
	}
	| expression_list ',' expression
	{
		ExpressionListNode *node = (ExpressionListNode*)malloc(sizeof(ExpressionListNode));

		$$ = $1;

		if (node == NULL)
		{
			DestroyExpressionList(&$1);
			DestroyExpression(&$3);
			YYNOMEM;
		}
		else
		{
			node->expression = $3;
			node->next = NULL;

			if ($$.head == NULL)
				$$.head = node;
			else
				((ExpressionListNode*)$$.tail)->next = node;

			$$.tail = node;
		}
	}
	;

size
	: TOKEN_SIZE_BYTE
	{
		$$ = SIZE_BYTE;
	}
	| TOKEN_SIZE_SHORT
	{
		$$ = SIZE_SHORT;
	}
	| TOKEN_SIZE_WORD
	{
		$$ = SIZE_WORD;
	}
	| TOKEN_SIZE_LONGWORD
	{
		$$ = SIZE_LONGWORD;
	}
	;

/*
number
	: TOKEN_NUMBER
	| '$' TOKEN_NUMBER
	;
*/
expression
	: expression1
	{
		$$ = $1;
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| expression TOKEN_LOGICAL_AND expression1
	{
		if (!DoExpression(&$$, EXPRESSION_LOGICAL_AND, &$1, &$3))
			YYNOMEM;
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| expression TOKEN_LOGICAL_OR expression1
	{
		if (!DoExpression(&$$, EXPRESSION_LOGICAL_OR, &$1, &$3))
			YYNOMEM;
	}
	;

expression1
	: expression2
	{
		$$ = $1;
	}
	| expression1 '=' expression2
	{
		if (!DoExpression(&$$, EXPRESSION_EQUALITY, &$1, &$3))
			YYNOMEM;
	}
	| expression1 TOKEN_EQUALITY expression2
	{
		if (!DoExpression(&$$, EXPRESSION_EQUALITY, &$1, &$3))
			YYNOMEM;
	}
	| expression1 TOKEN_INEQUALITY expression2
	{
		if (!DoExpression(&$$, EXPRESSION_INEQUALITY, &$1, &$3))
			YYNOMEM;
	}
	;

expression2
	: expression3
	{
		$$ = $1;
	}
	| expression2 '<' expression3
	{
		if (!DoExpression(&$$, EXPRESSION_LESS_THAN, &$1, &$3))
			YYNOMEM;
	}
	| expression2 TOKEN_LESS_OR_EQUAL expression3
	{
		if (!DoExpression(&$$, EXPRESSION_LESS_OR_EQUAL, &$1, &$3))
			YYNOMEM;
	}
	| expression2 '>' expression3
	{
		if (!DoExpression(&$$, EXPRESSION_MORE_THAN, &$1, &$3))
			YYNOMEM;
	}
	| expression2 TOKEN_MORE_OR_EQUAL expression3
	{
		if (!DoExpression(&$$, EXPRESSION_MORE_OR_EQUAL, &$1, &$3))
			YYNOMEM;
	}
	;

expression3
	: expression4
	{
		$$ = $1;
	}
	| expression3 '+' expression4
	{
		if (!DoExpression(&$$, EXPRESSION_ADD, &$1, &$3))
			YYNOMEM;
	}
	| expression3 '-' expression4
	{
		if (!DoExpression(&$$, EXPRESSION_SUBTRACT, &$1, &$3))
			YYNOMEM;
	}
	;

expression4
	: expression5
	{
		$$ = $1;
	}
	| expression4 '*' expression5
	{
		if (!DoExpression(&$$, EXPRESSION_MULTIPLY, &$1, &$3))
			YYNOMEM;
	}
	| expression4 '/' expression5
	{
		if (!DoExpression(&$$, EXPRESSION_DIVIDE, &$1, &$3))
			YYNOMEM;
	}
	| expression4 '%' expression5
	{
		if (!DoExpression(&$$, EXPRESSION_MODULO, &$1, &$3))
			YYNOMEM;
	}
	;

expression5
	: expression6
	{
		$$ = $1;
	}
	| expression5 '&' expression6
	{
		if (!DoExpression(&$$, EXPRESSION_BITWISE_AND, &$1, &$3))
			YYNOMEM;
	}
	| expression5 '!' expression6
	{
		if (!DoExpression(&$$, EXPRESSION_BITWISE_OR, &$1, &$3))
			YYNOMEM;
	}
	| expression5 '|' expression6
	{
		if (!DoExpression(&$$, EXPRESSION_BITWISE_OR, &$1, &$3))
			YYNOMEM;
	}
	| expression5 '^' expression6
	{
		if (!DoExpression(&$$, EXPRESSION_BITWISE_XOR, &$1, &$3))
			YYNOMEM;
	}
	;

expression6
	: expression7
	{
		$$ = $1;
	}
	| expression6 TOKEN_LEFT_SHIFT expression7
	{
		if (!DoExpression(&$$, EXPRESSION_LEFT_SHIFT, &$1, &$3))
			YYNOMEM;
	}
	| expression6 TOKEN_RIGHT_SHIFT expression7
	{
		if (!DoExpression(&$$, EXPRESSION_RIGHT_SHIFT, &$1, &$3))
			YYNOMEM;
	}
	;

expression7
	: expression8
	{
		$$ = $1;
	}
	| '+' expression7
	{
		$$ = $2;
	}
	| '-' expression7
	{
		if (!DoExpression(&$$, EXPRESSION_NEGATE, &$2, NULL))
			YYNOMEM;
	}
	| '~' expression7
	{
		if (!DoExpression(&$$, EXPRESSION_BITWISE_NOT, &$2, NULL))
			YYNOMEM;
	}
	/* This is an assembler extension: asm68k doesn't support this. */
	| '!' expression7
	{
		if (!DoExpression(&$$, EXPRESSION_LOGICAL_NOT, &$2, NULL))
			YYNOMEM;
	}
	;

expression8
	: TOKEN_NUMBER
	{
		$$.type = EXPRESSION_NUMBER;
		$$.shared.unsigned_long = $1;
	}
	| '(' expression ')'
	{
		$$ = $2;
	}
	;

%%

static bool DoExpressionTriple(Expression *expression, ExpressionType type, Expression *left_expression, Expression *middle_expression, Expression *right_expression)
{
	bool success = true;

	expression->type = type;

	expression->shared.subexpressions = (Expression*)malloc(sizeof(Expression) * (right_expression != NULL ? 3 : middle_expression != NULL ? 2 : 1));

	if (expression->shared.subexpressions == NULL)
	{
		DestroyExpression(left_expression);

		if (middle_expression != NULL)
			DestroyExpression(middle_expression);

		if (right_expression != NULL)
			DestroyExpression(right_expression);

		success = false;
	}
	else
	{
		expression->shared.subexpressions[0] = *left_expression;

		if (middle_expression != NULL)
			expression->shared.subexpressions[1] = *middle_expression;

		if (right_expression != NULL)
			expression->shared.subexpressions[2] = *right_expression;
	}

	return success;
}

static bool DoExpression(Expression *expression, ExpressionType type, Expression *left_expression, Expression *right_expression)
{
	return DoExpressionTriple(expression, type, left_expression, right_expression, NULL);
}

void DestroyExpression(Expression *expression)
{
	switch (expression->type)
	{
		case EXPRESSION_SUBTRACT:
		case EXPRESSION_ADD:
		case EXPRESSION_MULTIPLY:
		case EXPRESSION_DIVIDE:
		case EXPRESSION_MODULO:
		case EXPRESSION_LOGICAL_OR:
		case EXPRESSION_LOGICAL_AND:
		case EXPRESSION_BITWISE_OR:
		case EXPRESSION_BITWISE_XOR:
		case EXPRESSION_BITWISE_AND:
		case EXPRESSION_EQUALITY:
		case EXPRESSION_INEQUALITY:
		case EXPRESSION_LESS_THAN:
		case EXPRESSION_LESS_OR_EQUAL:
		case EXPRESSION_MORE_THAN:
		case EXPRESSION_MORE_OR_EQUAL:
		case EXPRESSION_LEFT_SHIFT:
		case EXPRESSION_RIGHT_SHIFT:
			DestroyExpression(&expression->shared.subexpressions[0]);
			DestroyExpression(&expression->shared.subexpressions[1]);
			free(expression->shared.subexpressions);
			break;

		case EXPRESSION_NEGATE:
		case EXPRESSION_BITWISE_NOT:
		case EXPRESSION_LOGICAL_NOT:
			DestroyExpression(&expression->shared.subexpressions[0]);
			free(expression->shared.subexpressions);
			break;

		case EXPRESSION_NUMBER:
			break;
	}
}

static void DestroyExpressionList(ExpressionList *list)
{
	ExpressionListNode *node = list->head;

	while (node != NULL)
	{
		ExpressionListNode* const next_node = node->next;

		DestroyExpression(&node->expression);

		free(node);

		node = next_node;
	}
}

void DestroyStatement(Statement *statement)
{
	switch (statement->type)
	{
		case STATEMENT_TYPE_EMPTY:
		case STATEMENT_TYPE_EVEN:
			break;

		case STATEMENT_TYPE_DC:
			DestroyExpressionList(&statement->shared.dc.values);
			break;
	}
}
