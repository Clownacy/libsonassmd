#include "code-reader.h"

#include "syntactic.h"
#include "lexical.h"

namespace libsonassmd {namespace CodeReader {

void parser::error(const std::string &message)
{
	throw std::runtime_error(message);
}

template<typename T, Lexer::Type Type>
static T Read(std::istream &input)
{
	Output output;

	Lexer lexer(input, Type);
	parser parser(output, lexer);
#if LIBSONASSMD_CODE_READER_YYDEBUG
	parser.set_debug_level(1);
#endif

	if (parser())
		throw std::runtime_error("Unspecified parser error");

	return std::get<T>(output);
}

Mappings ReadMappings(std::istream &input)
{
	return Read<Mappings, Lexer::Type::Mappings>(input);
}

DPLCs ReadDynamicPatternLoadCues(std::istream &input)
{
	return Read<DPLCs, Lexer::Type::DPLCs>(input);
}

}}
