#include <cstdlib>
#include <fstream>

#include "code-reader.h"

int main([[maybe_unused]] const int argc, char** const argv)
{
	const char* const input_file_path = argv[1];

	std::ifstream file(input_file_path);

	if (!file.is_open())
	{
		std::cerr << "Could not open file '" << input_file_path << "'.\n";
		return EXIT_FAILURE;
	}

	libsonassmd::game = libsonassmd::Game::SONIC_1;
	libsonassmd::mapmacros = true;

	auto mappings = libsonassmd::CodeReader::ReadDynamicPatternLoadCues(file);

	for (const auto &offset_table : mappings.offset_tables)
	{
		std::cerr << "Block type: Offset table\n";

		for (const auto &identifier : offset_table)
			std::cerr << '\t' << identifier << '\n';
	}

	std::cerr << "Block type: Mapping frame\n";

	for (const auto& [label, frame] : mappings.frames)
	{
		std::cerr << "\tLabel: " << label << '\n';
		std::cerr << "\tData:\n";
		frame.toAssemblyStream(std::cerr);
	}

	return EXIT_SUCCESS;
}
