#include "assembler.h"

#include <sstream>

#include "clownassembler/cpp/clownassembler.h"

namespace libsonassmd {

void Assemble(std::istream &input, std::ostream &output)
{
	std::stringstream errors;
	const bool success = ClownAssembler::Assemble(input, output, &errors);

	if (!success)
		throw std::runtime_error("Failed to assemble:\n\n" + errors.str());
}

void Assemble(const std::filesystem::path &path, std::ostream &output)
{
	std::stringstream input;
	input << "\tinclude " << path;
	Assemble(input, output);
}

}
