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
static libsonassmd::CodeReader::BlockList block_list;

template<class... Ts>
struct overloaded : Ts... { using Ts::operator()...; };

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
	libsonassmd::CodeReader::parser parser(flex_state, block_list, libsonassmd::Game::SONIC_3_AND_KNUCKLES);
#ifdef LIBSONASSMD_CODE_READER_YYDEBUG
	parser.set_debug_level(1);
#endif
	const int parse_result = parser.parse();
	libsonassmd_code_reader_yy_delete_buffer(buffer, flex_state);

	std::fclose(file);

	if (libsonassmd_code_reader_yylex_destroy(flex_state) != 0)
	{
		//InternalError(&state, "libsonassmd_code_reader_yylex_destroy failed.");
	}

	std::cerr << std::format("There are {} blocks.\n", std::size(block_list));

	for (const auto &block : block_list)
	{
		std::visit(overloaded{
			[](const libsonassmd::CodeReader::OffsetTable &offset_table)
			{
				std::cerr << "Block type: Offset table\n";

				for (const auto &identifier : offset_table)
					std::cerr << std::format("\t{}\n", identifier);
			},
			[](const libsonassmd::CodeReader::MappingFrame &frame)
			{
				std::cerr << "Block type: Mapping frame\n";

				std::cerr << "\tLabels:\n";
				for (const auto &label : frame.labels)
					std::cerr << std::format("\t\t{}\n", label);
				std::cerr << "\tData:\n";
				frame.frame.toAssemblyStream(std::cerr, libsonassmd::Game::SONIC_1, true);
			}
		}, block);
	}

	return EXIT_SUCCESS;
}
