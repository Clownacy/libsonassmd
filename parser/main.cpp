#include <cstdlib>
#include <iostream>
#include <fstream>

#include "syntactic.h"
#include "lexical.h"

void libsonassmd_yyerror(const std::string &message)
{
	std::cerr << message << '\n';
}

static libsonassmd::CodeReader::Mappings mappings;

int main([[maybe_unused]] const int argc, [[maybe_unused]] char** const argv)
{
	const char* const input_file_path = argv[1];

	std::ifstream file(input_file_path);

	if (!file.is_open())
	{
		std::cerr << "Could not open file '" << input_file_path << "'.";
		return EXIT_FAILURE;
	}

	libsonassmd::CodeReader::Lexer lexer(file, std::cout);
	libsonassmd::CodeReader::parser parser(mappings, libsonassmd::Game::SONIC_1, lexer);
#ifdef LIBSONASSMD_CODE_READER_YYDEBUG
	parser.set_debug_level(1);
#endif
	const int parse_result = parser();

	for (const auto &offset_table : mappings.offset_tables)
	{
		std::cerr << "Block type: Offset table\n";

		for (const auto &identifier : offset_table)
			std::cerr << std::format("\t{}\n", identifier);
	}

	std::cerr << "Block type: Mapping frame\n";

	for (const auto& [label, frame] : mappings.frames)
	{
		std::cerr << std::format("\tLabel: {}\n", label);
		std::cerr << "\tData:\n";
		frame.toAssemblyStream(std::cerr, libsonassmd::Game::SONIC_1, true);
	}

	return EXIT_SUCCESS;
}
