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

%option never-interactive
%option nounistd
%option nounput noinput noyywrap
%option reentrant bison-bridge
%option prefix="m68kasm_"
%option caseless

%{

#include <stdlib.h>
#include <string.h>

#include "syntactic.h"

void m68kasm_warning(void *scanner, Statement *statement, const char *message);
void m68kasm_error(void *scanner, Statement *statement, const char *message);

static bool CharacterToInteger(unsigned int* const value, const unsigned int character)
{
	if (character >= '0' && character <= '9')
		*value = 0x0 + (character - '0');
	else if (character >= 'A' && character <= 'Z')
		*value = 0xA + (character - 'A');
	else if (character >= 'a' && character <= 'z')
		*value = 0xA + (character - 'a');
	else
		return false;

	return true;
}

/* Like `strtoul`, except this one returns a truncated value when parsing a number that is too large. */
// TODO: Replace this with 'std::from_chars' or something.
static bool StringTo32BitInteger(unsigned long* const value, const char* const string_start, const char** const string_end, const unsigned long base)
{
	bool success = true;
	const unsigned long limit = 0xFFFFFFFF / base;
	const char* string_pointer;

	*value = 0;

	for (string_pointer = string_start; ; ++string_pointer)
	{
		unsigned int digit;
		if (!CharacterToInteger(&digit, *string_pointer) || digit >= base)
			break;

		if (*value > limit)
			success = false;

		*value *= base;
		*value += digit;
	}

	*string_end = string_pointer;
	return success;
}

static bool ParseNumber(unsigned long* const value, void* const scanner, const char* const string_start, const size_t string_length, const unsigned long base)
{
	const char *string_end;

	if (!StringTo32BitInteger(value, string_start, &string_end, base))
	{
		/* S.N. 68k silently truncates values that are too large. This is relied upon by old versions of the Sonic 2 August 21st prototype disassembly. */
		m68kasm_warning(scanner, NULL, "Number is too large and will be truncated.");
	}

	if (string_end != string_start + string_length)
	{
		m68kasm_error(scanner, NULL, "Number is invalid and cannot be parsed.");
		return false;
	}

	return true;
}

%}

/* Regular expression. */
binary_digit      [0-1]
decimal_digit     [0-9]
hexadecimal_digit [0-9a-fA-F]
binary            {binary_digit}+
decimal           {decimal_digit}+
hexadecimal       {hexadecimal_digit}+

%%

 /* Ignore whitespace */
[ \t]+          ;

 /* Ignore comments */
;.*?$           ;

 /* Terminate at end of file. When terminating, revert to initial state. */
<<EOF>>         BEGIN(INITIAL); yyterminate();

 /* Directives. */
even            return m68kasm::parser::token::TOKEN_DIRECTIVE_EVEN;

 /* Sizes. */
".b"            return m68kasm::parser::token::TOKEN_SIZE_BYTE;
".s"            return m68kasm::parser::token::TOKEN_SIZE_SHORT;
".w"            return m68kasm::parser::token::TOKEN_SIZE_WORD;
".l"            return m68kasm::parser::token::TOKEN_SIZE_LONGWORD;

 /* Misc. symbols. */
"."             return yytext[0];
","             return yytext[0];
"("             return yytext[0];
")"             return yytext[0];
"$"             return yytext[0];
"+"             return yytext[0];
"-"             return yytext[0];
"*"             return yytext[0];
"/"             return yytext[0];
"="             return yytext[0];
"@"             return yytext[0];

 /* Operators. */
"&&"            return m68kasm::parser::token::TOKEN_LOGICAL_AND;
"||"            return m68kasm::parser::token::TOKEN_LOGICAL_OR;
"=="            return m68kasm::parser::token::TOKEN_EQUALITY;   /* An assembler extension, for programmers that are familiar with C. */
"!="            return m68kasm::parser::token::TOKEN_INEQUALITY; /* An assembler extension, for programmers that are familiar with C. */
"<>"            return m68kasm::parser::token::TOKEN_INEQUALITY;
"><"            return m68kasm::parser::token::TOKEN_INEQUALITY;
"<="            return m68kasm::parser::token::TOKEN_LESS_OR_EQUAL;
">="            return m68kasm::parser::token::TOKEN_MORE_OR_EQUAL;
"<<"            return m68kasm::parser::token::TOKEN_LEFT_SHIFT;
">>"            return m68kasm::parser::token::TOKEN_RIGHT_SHIFT;

 /* Decimal number. */
{decimal} {
	if (!ParseNumber(&yylval->unsigned_long, yyscanner, yytext, yyleng, 10))
		return m68kasm::parser::token::M68KASM_error;

	return m68kasm::parser::token::TOKEN_NUMBER;
}

 /* Hexadecimal number (68k). */
\${hexadecimal} {
	if (!ParseNumber(&yylval->unsigned_long, yyscanner, yytext + 1, yyleng - 1, 16))
		return m68kasm::parser::token::M68KASM_error;

	return m68kasm::parser::token::TOKEN_NUMBER;
}

 /* Binary number (68k). */
\%{binary} {
	if (!ParseNumber(&yylval->unsigned_long, yyscanner, yytext + 1, yyleng - 1, 2))
		return m68kasm::parser::token::M68KASM_error;

	return m68kasm::parser::token::TOKEN_NUMBER;
}

 /* Identifier. */
[A-Za-z_][A-Za-z_0-9\?]* {
	/* Identifier. */
	if (!String_Create(&yylval->string, yytext, yyleng))
	{
		m68kasm_error(yyscanner, NULL, "Could not allocate memory for generic string.");
		return m68kasm::parser::token::M68KASM_error;
	}

	return m68kasm::parser::token::TOKEN_IDENTIFIER;
}

 /* Local label. */
[@\.][A-Za-z_0-9\?]+ {
	if (!String_Create(&yylval->string, yytext, yyleng))
	{
		m68kasm_error(yyscanner, NULL, "Could not allocate memory for generic string.");
		return m68kasm::parser::token::M68KASM_error;
	}

	return m68kasm::parser::token::TOKEN_LOCAL_IDENTIFIER;
}

 /* Make Bison signal a syntax error for unrecognised symbols */
.               return yytext[0];

%%
