#include "assembleable.h"

#include <sstream>

#include "assembler.h"

namespace libsonassmd {

void Assembleable::fromAssemblyStream(std::istream &stream, const Game game)
{
	std::stringstream string_stream;
	if (!Assemble(stream, string_stream, game))
		throw std::ios::failure("File could not be assembled"); // TODO: Find a more appropriate exception type.
	fromBinaryStream(string_stream, game);
}

// TODO: Move this to an interface class or something.
void Assembleable::toBinaryStream(std::ostream &stream, const Game game) const
{
	std::stringstream string_stream;
	toAssemblyStream(string_stream, game, true);
	// TODO: Handle this failing.
	Assemble(string_stream, stream, game);
}

}
