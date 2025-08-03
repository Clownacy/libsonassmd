/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_M68KASM_SYNTACTIC_H_INCLUDED
# define YY_M68KASM_SYNTACTIC_H_INCLUDED
/* Debug traces.  */
#ifndef M68KASM_DEBUG
# if defined YYDEBUG
#if YYDEBUG
#   define M68KASM_DEBUG 1
#  else
#   define M68KASM_DEBUG 0
#  endif
# else /* ! defined YYDEBUG */
#  define M68KASM_DEBUG 1
# endif /* ! defined YYDEBUG */
#endif  /* ! defined M68KASM_DEBUG */
#if M68KASM_DEBUG
extern int m68kasm_debug;
#endif
/* "%code requires" blocks.  */
#line 30 "syntactic.y"


#include "string.h"

/* A hack for older versions of Bison. */
/* Should probably be removed when they go out of circulation. */
#if defined(YYBISON) && YYBISON < 30802 && !defined(YYNOMEM)
#define YYNOMEM goto yyexhaustedlab;
#endif

#define YYSTYPE M68KASM_STYPE

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


#line 166 "syntactic.h"

/* Token kinds.  */
#ifndef M68KASM_TOKENTYPE
# define M68KASM_TOKENTYPE
  enum m68kasm_tokentype
  {
    M68KASM_EMPTY = -2,
    M68KASM_EOF = 0,               /* "end of file"  */
    M68KASM_error = 256,           /* error  */
    M68KASM_UNDEF = 257,           /* "invalid token"  */
    TOKEN_DIRECTIVE_DC = 258,      /* TOKEN_DIRECTIVE_DC  */
    TOKEN_DIRECTIVE_EVEN = 259,    /* TOKEN_DIRECTIVE_EVEN  */
    TOKEN_SIZE_BYTE = 260,         /* TOKEN_SIZE_BYTE  */
    TOKEN_SIZE_SHORT = 261,        /* TOKEN_SIZE_SHORT  */
    TOKEN_SIZE_WORD = 262,         /* TOKEN_SIZE_WORD  */
    TOKEN_SIZE_LONGWORD = 263,     /* TOKEN_SIZE_LONGWORD  */
    TOKEN_NUMBER = 264,            /* TOKEN_NUMBER  */
    TOKEN_IDENTIFIER = 265,        /* TOKEN_IDENTIFIER  */
    TOKEN_LOCAL_IDENTIFIER = 266,  /* TOKEN_LOCAL_IDENTIFIER  */
    TOKEN_LOGICAL_AND = 267,       /* TOKEN_LOGICAL_AND  */
    TOKEN_LOGICAL_OR = 268,        /* TOKEN_LOGICAL_OR  */
    TOKEN_EQUALITY = 269,          /* TOKEN_EQUALITY  */
    TOKEN_INEQUALITY = 270,        /* TOKEN_INEQUALITY  */
    TOKEN_LESS_OR_EQUAL = 271,     /* TOKEN_LESS_OR_EQUAL  */
    TOKEN_MORE_OR_EQUAL = 272,     /* TOKEN_MORE_OR_EQUAL  */
    TOKEN_LEFT_SHIFT = 273,        /* TOKEN_LEFT_SHIFT  */
    TOKEN_RIGHT_SHIFT = 274        /* TOKEN_RIGHT_SHIFT  */
  };
  typedef enum m68kasm_tokentype m68kasm_token_kind_t;
#endif

/* Value type.  */
#if ! defined M68KASM_STYPE && ! defined M68KASM_STYPE_IS_DECLARED
union M68KASM_STYPE
{
#line 164 "syntactic.y"

	unsigned long unsigned_long;
	String string;
	Size size;
	Statement statement;
	ExpressionList expression_list;
	Expression expression;

#line 211 "syntactic.h"

};
typedef union M68KASM_STYPE M68KASM_STYPE;
# define M68KASM_STYPE_IS_TRIVIAL 1
# define M68KASM_STYPE_IS_DECLARED 1
#endif




int m68kasm_parse (void *scanner, Statement *statement);

/* "%code provides" blocks.  */
#line 139 "syntactic.y"


void DestroyExpression(Expression *expression);
void DestroyStatement(Statement *statement);


#line 232 "syntactic.h"

#endif /* !YY_M68KASM_SYNTACTIC_H_INCLUDED  */
