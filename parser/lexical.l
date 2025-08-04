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
%option reentrant
%option prefix="m68kasm_"
%option caseless

%{

#include <charconv>
#include <string>

#include "syntactic.h"

void m68kasm_error(const std::string &message);

static unsigned long ParseNumber(const char* const string_start, const size_t string_length, const int base)
{
	unsigned long value;

	if (std::from_chars(string_start, string_start + string_length, value, base).ec != std::errc{})
		throw m68kasm::parser::syntax_error("Number is invalid and cannot be parsed.");

	return value;
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
<<EOF>>         return m68kasm::parser::make_YYEOF();

 /* Directives. */
even            return m68kasm::parser::make_DIRECTIVE_EVEN();

 /* Sizes. */
".b"            return m68kasm::parser::make_SIZE_BYTE();
".s"            return m68kasm::parser::make_SIZE_SHORT();
".w"            return m68kasm::parser::make_SIZE_WORD();
".l"            return m68kasm::parser::make_SIZE_LONGWORD();

 /* Misc. symbols. */
"."             return m68kasm::parser::make_PERIOD();
","             return m68kasm::parser::make_COMMA();
"("             return m68kasm::parser::make_PARENTHESIS_LEFT();
")"             return m68kasm::parser::make_PARENTHESIS_RIGHT();
"$"             return m68kasm::parser::make_DOLLAR();
"+"             return m68kasm::parser::make_PLUS();
"-"             return m68kasm::parser::make_MINUS();
"*"             return m68kasm::parser::make_ASTERIX();
"/"             return m68kasm::parser::make_FORWARD_SLASH();
"="             return m68kasm::parser::make_EQUAL();
"@"             return m68kasm::parser::make_AT();
"<"             return m68kasm::parser::make_LESS();
">"             return m68kasm::parser::make_MORE();
"%"             return m68kasm::parser::make_PERCENT();
"&"             return m68kasm::parser::make_AMPERSAND();
"!"             return m68kasm::parser::make_EXCLAMATION();
"|"             return m68kasm::parser::make_VERTICAL_BAR();
"^"             return m68kasm::parser::make_CARET();
"~"             return m68kasm::parser::make_TILDE();

 /* Operators. */
"&&"            return m68kasm::parser::make_LOGICAL_AND();
"||"            return m68kasm::parser::make_LOGICAL_OR();
"=="            return m68kasm::parser::make_EQUALITY();   /* An assembler extension, for programmers that are familiar with C. */
"!="            return m68kasm::parser::make_INEQUALITY(); /* An assembler extension, for programmers that are familiar with C. */
"<>"            return m68kasm::parser::make_INEQUALITY();
"><"            return m68kasm::parser::make_INEQUALITY();
"<="            return m68kasm::parser::make_LESS_OR_EQUAL();
">="            return m68kasm::parser::make_MORE_OR_EQUAL();
"<<"            return m68kasm::parser::make_LEFT_SHIFT();
">>"            return m68kasm::parser::make_RIGHT_SHIFT();

 /* Decimal number. */
{decimal} {
	return m68kasm::parser::make_NUMBER(ParseNumber(yytext, yyleng, 10));
}

 /* Hexadecimal number (68k). */
\${hexadecimal} {
	return m68kasm::parser::make_NUMBER(ParseNumber(yytext + 1, yyleng - 1, 16));
}

 /* Binary number (68k). */
\%{binary} {
	return m68kasm::parser::make_NUMBER(ParseNumber(yytext + 1, yyleng - 1, 2));
}

 /* Identifier. */
[A-Za-z_][A-Za-z_0-9\?]* {
	return m68kasm::parser::make_IDENTIFIER(std::string(yytext, yyleng));
}

 /* Local label. */
[@\.][A-Za-z_0-9\?]+ {
	return m68kasm::parser::make_LOCAL_IDENTIFIER(std::string(yytext, yyleng));
}

 /* Make Bison signal a syntax error for unrecognised symbols */
.       throw m68kasm::parser::syntax_error(std::string("Invalid character '") + yytext + "'.");

%%
