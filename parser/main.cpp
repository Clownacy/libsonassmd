#include <cstdio>
#include <cstdlib>
#include <iostream>

#include "syntactic.h"
#include "lexical.h"

void m68kasm_error(const std::string &message)
{
	std::cerr << message;
}

static yyscan_t flex_state;
static Statement statement;

int main([[maybe_unused]] const int argc, [[maybe_unused]] char** const argv)
{
	if (m68kasm_lex_init_extra(NULL, &flex_state) != 0)
	{
		//InternalError(&state, "m68kasm_lex_init failed.");
	}

	const char* const input_file_path = argv[1];

	std::FILE* const file = std::fopen(input_file_path, "r");

	if (file == nullptr)
	{
		std::cerr << "Could not open file '" << input_file_path << "'.";
		return EXIT_FAILURE;
	}

	//m68kasm_debug = 1;

	const YY_BUFFER_STATE buffer = m68kasm__create_buffer(file, YY_BUF_SIZE, flex_state);
	m68kasm__switch_to_buffer(buffer, flex_state);
	m68kasm::parser parser(flex_state, &statement);
	const int parse_result = parser.parse();
	m68kasm__delete_buffer(buffer, flex_state);

	std::fclose(file);

	if (m68kasm_lex_destroy(flex_state) != 0)
	{
		//InternalError(&state, "m68kasm_lex_destroy failed.");
	}

	return EXIT_SUCCESS;
}
