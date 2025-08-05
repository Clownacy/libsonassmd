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
%option c++
%option prefix="libsonassmd_code_reader_yy"
%option caseless
%option yyclass="Lexer"

%{

#include <charconv>
#include <format>
#include <string>

#include "syntactic.h"
#include "lexical.h"

#undef YY_DECL
#define YY_DECL libsonassmd::CodeReader::parser::symbol_type libsonassmd::CodeReader::Lexer::operator()()

static unsigned long ParseNumber(const char* const string_start, const size_t string_length, const int base)
{
	unsigned long value;

	if (std::from_chars(string_start, string_start + string_length, value, base).ec != std::errc{})
		throw libsonassmd::CodeReader::parser::syntax_error("Number is invalid and cannot be parsed.");

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

identifier        [A-Za-z_][A-Za-z_0-9\?]*
local_identifier  [@\.][A-Za-z_0-9\?]+

%%

 /* Ignore whitespace */
[ \t]+          ;

 /* Ignore comments */
;.*?$           ;

 /* Terminate at end of file. When terminating, revert to initial state. */
<<EOF>>         return libsonassmd::CodeReader::parser::make_YYEOF();

 /* Directives. */
dc              return libsonassmd::CodeReader::parser::make_DIRECTIVE_DC();
even            ; // Just get rid of this junk; we don't need it.

 /* Sizes. */
".b"            return libsonassmd::CodeReader::parser::make_SIZE_BYTE();
".s"            return libsonassmd::CodeReader::parser::make_SIZE_SHORT();
".w"            return libsonassmd::CodeReader::parser::make_SIZE_WORD();
".l"            return libsonassmd::CodeReader::parser::make_SIZE_LONGWORD();

 /* Misc. symbols. */
"."             return libsonassmd::CodeReader::parser::make_PERIOD();
","             return libsonassmd::CodeReader::parser::make_COMMA();
"("             return libsonassmd::CodeReader::parser::make_PARENTHESIS_LEFT();
")"             return libsonassmd::CodeReader::parser::make_PARENTHESIS_RIGHT();
"$"             return libsonassmd::CodeReader::parser::make_DOLLAR();
"+"             return libsonassmd::CodeReader::parser::make_PLUS();
"-"             return libsonassmd::CodeReader::parser::make_MINUS();
"*"             return libsonassmd::CodeReader::parser::make_ASTERIX();
"/"             return libsonassmd::CodeReader::parser::make_FORWARD_SLASH();
"="             return libsonassmd::CodeReader::parser::make_EQUAL();
"@"             return libsonassmd::CodeReader::parser::make_AT();
"<"             return libsonassmd::CodeReader::parser::make_LESS();
">"             return libsonassmd::CodeReader::parser::make_MORE();
"%"             return libsonassmd::CodeReader::parser::make_PERCENT();
"&"             return libsonassmd::CodeReader::parser::make_AMPERSAND();
"!"             return libsonassmd::CodeReader::parser::make_EXCLAMATION();
"|"             return libsonassmd::CodeReader::parser::make_VERTICAL_BAR();
"^"             return libsonassmd::CodeReader::parser::make_CARET();
"~"             return libsonassmd::CodeReader::parser::make_TILDE();
":"             return libsonassmd::CodeReader::parser::make_COLON();

 /* Operators. */
"&&"            return libsonassmd::CodeReader::parser::make_LOGICAL_AND();
"||"            return libsonassmd::CodeReader::parser::make_LOGICAL_OR();
"=="            return libsonassmd::CodeReader::parser::make_EQUALITY();   /* An assembler extension, for programmers that are familiar with C. */
"!="            return libsonassmd::CodeReader::parser::make_INEQUALITY(); /* An assembler extension, for programmers that are familiar with C. */
"<>"            return libsonassmd::CodeReader::parser::make_INEQUALITY();
"><"            return libsonassmd::CodeReader::parser::make_INEQUALITY();
"<="            return libsonassmd::CodeReader::parser::make_LESS_OR_EQUAL();
">="            return libsonassmd::CodeReader::parser::make_MORE_OR_EQUAL();
"<<"            return libsonassmd::CodeReader::parser::make_LEFT_SHIFT();
">>"            return libsonassmd::CodeReader::parser::make_RIGHT_SHIFT();

 /* MapMacros. */
"mappingsTable"      return libsonassmd::CodeReader::parser::make_MAPPINGS_TABLE();
"mappingsTableEntry" return libsonassmd::CodeReader::parser::make_MAPPINGS_TABLE_ENTRY();
"spriteHeader"       return libsonassmd::CodeReader::parser::make_SPRITE_HEADER();
"spritePiece"        return libsonassmd::CodeReader::parser::make_SPRITE_PIECE();

 /* Decimal number. */
{decimal} {
	return libsonassmd::CodeReader::parser::make_NUMBER(ParseNumber(yytext, yyleng, 10));
}

 /* Hexadecimal number (68k). */
\${hexadecimal} {
	return libsonassmd::CodeReader::parser::make_NUMBER(ParseNumber(yytext + 1, yyleng - 1, 16));
}

 /* Binary number (68k). */
\%{binary} {
	return libsonassmd::CodeReader::parser::make_NUMBER(ParseNumber(yytext + 1, yyleng - 1, 2));
}

 /* Labels. */
{identifier}: {
	return libsonassmd::CodeReader::parser::make_LABEL(std::string(yytext, yyleng - 1));
}

{local_identifier}:  {
	return libsonassmd::CodeReader::parser::make_LOCAL_LABEL(std::string(yytext, yyleng - 1));
}

[\r\n]{identifier} {
	return libsonassmd::CodeReader::parser::make_LABEL(std::string(yytext + 1, yyleng - 1));
}

[\r\n]{local_identifier} {
	return libsonassmd::CodeReader::parser::make_LOCAL_LABEL(std::string(yytext + 1, yyleng - 1));
}

[\r\n]{identifier}: {
	return libsonassmd::CodeReader::parser::make_LABEL(std::string(yytext + 1, yyleng - 2));
}

[\r\n]{local_identifier}: {
	return libsonassmd::CodeReader::parser::make_LOCAL_LABEL(std::string(yytext + 1, yyleng - 2));
}

 /* Identifier. */
{identifier} {
	return libsonassmd::CodeReader::parser::make_IDENTIFIER(std::string(yytext, yyleng));
}

 /* Local identifier. */
{local_identifier} {
	return libsonassmd::CodeReader::parser::make_LOCAL_IDENTIFIER(std::string(yytext, yyleng));
}

 /* Make Bison signal a syntax error for unrecognised symbols */
.       throw libsonassmd::CodeReader::parser::syntax_error(std::format("Invalid character '{}'.", yytext));

%%
