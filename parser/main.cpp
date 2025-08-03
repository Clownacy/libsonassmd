#include "syntactic.h"
#include "lexical.h"

void m68kasm_warning([[maybe_unused]] void *scanner, [[maybe_unused]] Statement *statement, [[maybe_unused]] const char *message)
{
	
}

void m68kasm_warning_pedantic([[maybe_unused]] void *scanner, [[maybe_unused]] Statement *statement, [[maybe_unused]] const char *message)
{
	
}

void m68kasm_error([[maybe_unused]] void *scanner, [[maybe_unused]] Statement *statement, [[maybe_unused]] const char *message)
{
	
}

static yyscan_t flex_state;
static Statement statement;

int main([[maybe_unused]] const int argc, [[maybe_unused]] char** const argv)
{
	if (m68kasm_lex_init_extra(NULL, &flex_state) != 0)
	{
		//InternalError(&state, "m68kasm_lex_init failed.");
	}

	const YY_BUFFER_STATE buffer = m68kasm__scan_bytes(NULL, 0, flex_state);
	const int parse_result = m68kasm_parse(flex_state, &statement);
	m68kasm__delete_buffer(buffer, flex_state);

	if (m68kasm_lex_destroy(flex_state) != 0)
	{
		//InternalError(&state, "m68kasm_lex_destroy failed.");
	}
}
