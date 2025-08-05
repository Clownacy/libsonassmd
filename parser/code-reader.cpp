#include "code-reader.h"

#include "syntactic.h"
#include "lexical.h"

namespace libsonassmd {namespace CodeReader {

void parser::error(const std::string &message)
{
	throw std::runtime_error(message);
}

Mappings ReadMappings(std::istream &input, const Game game)
{
	Mappings mappings;

	Lexer lexer(input, std::cout);
	parser parser(mappings, game, lexer);
#ifdef LIBSONASSMD_CODE_READER_YYDEBUG
	parser.set_debug_level(1);
#endif

	if (parser())
		throw std::runtime_error("Unspecified parser error");

	return mappings;
}

}}
