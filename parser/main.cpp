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
static std::vector<Statement> statement_list;

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
	libsonassmd::CodeReader::parser parser(flex_state, statement_list);
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

	std::cerr << std::format("There are {} blocks.\n", std::size(statement_list));

	for (const auto &statement : statement_list)
	{
		switch (statement.type)
		{
			case STATEMENT_TYPE_OFFSET_TABLE:
			{
				std::cerr << "Block type: Offset table\n";

				const auto &offset_table = std::get<std::vector<std::string>>(statement.shared);

				for (const auto &identifier : offset_table)
					std::cerr << identifier << '\n';
				break;
			}

			case STATEMENT_TYPE_MAPPING_FRAME:
			{
				std::cerr << "Block type: Mapping frame\n";

				const auto &frame = std::get<Statement::MappingFrame>(statement.shared);
				std::cerr << std::format("\tLabel: {}\n", frame.label);
				std::cerr << "\tData:\n";
				frame.frame.toAssemblyStream(std::cerr, libsonassmd::Game::SONIC_1, true);
				break;
			}
		}
	}

	return EXIT_SUCCESS;
}
