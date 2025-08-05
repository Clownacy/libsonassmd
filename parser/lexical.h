#ifndef LEXICAL_H
#define LEXICAL_H

// Work around some insane bullshit in 'FlexLexer.h' that causes a double-defined error.
// I thought we left dogshit code like this in the past.
#ifndef yyFlexLexer
#define yyFlexLexer libsonassmd_code_reader_yyFlexLexer
#include <FlexLexer.h>
#endif

#include "syntactic.h"

namespace libsonassmd { namespace CodeReader {

class Lexer : public libsonassmd_code_reader_yyFlexLexer
{
public:
	using libsonassmd_code_reader_yyFlexLexer::libsonassmd_code_reader_yyFlexLexer;

	libsonassmd::CodeReader::parser::symbol_type operator()();
};

}}

#endif // LEXICAL_H
