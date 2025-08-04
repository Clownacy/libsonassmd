#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "syntactic.h"
#include "lexical.h"

void libsonassmd_yyerror(const std::string &message)
{
	std::cerr << message << '\n';
}

static yyscan_t flex_state;
static libsonassmd::CodeReader::Mappings mappings;

int main([[maybe_unused]] const int argc, [[maybe_unused]] char** const argv)
{
	if (libsonassmd_code_reader_yylex_init_extra(NULL, &flex_state) != 0)
	{
		//InternalError(&state, "libsonassmd_code_reader_yylex_init failed.");
	}

	const char* const input_file_path = argv[1];

	std::FILE* const file = std::fopen(input_file_path, "r");

	if (file == nullptr)
	{
		std::cerr << "Could not open file '" << input_file_path << "'.";
		return EXIT_FAILURE;
	}

	const YY_BUFFER_STATE buffer = libsonassmd_code_reader_yy_create_buffer(file, YY_BUF_SIZE, flex_state);
	libsonassmd_code_reader_yy_switch_to_buffer(buffer, flex_state);
	libsonassmd::CodeReader::parser parser(flex_state, mappings, libsonassmd::Game::SONIC_3_AND_KNUCKLES);
#ifdef LIBSONASSMD_CODE_READER_YYDEBUG
	//parser.set_debug_level(1);
#endif
	const int parse_result = parser.parse();
	libsonassmd_code_reader_yy_delete_buffer(buffer, flex_state);

	std::fclose(file);

	if (libsonassmd_code_reader_yylex_destroy(flex_state) != 0)
	{
		//InternalError(&state, "libsonassmd_code_reader_yylex_destroy failed.");
	}

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
