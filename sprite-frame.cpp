#include "sprite-frame.h"

#include <sstream>

#include "assembler.h"
#include "common.h"

namespace libsonassmd {

// TODO: Move this to an interface class or something.
void SpriteFrame::fromAssemblyStream(std::istream &stream, const Game game)
{
	std::stringstream string_stream;
	if (!Assemble(stream, string_stream, game))
		throw std::ios::failure("File could not be assembled"); // TODO: Find a more appropriate exception type.
	fromBinaryStream(string_stream, game);
}

// TODO: Move this to an interface class or something.
void SpriteFrame::toBinaryStream(std::ostream &stream, const Game game) const
{
	std::stringstream string_stream;
	toAssemblyStream(string_stream, game, true);
	// TODO: Handle this failing.
	Assemble(string_stream, stream, game);
}

void SpriteFrame::fromBinaryStream(std::istream &stream, const Game game)
{
	const int total_pieces = game == Game::SONIC_1 ? ReadU8(stream) : ReadU16BE(stream);
	pieces.resize(total_pieces);

	for (auto &piece : pieces)
		piece.fromBinaryStream(stream, game);
}

void SpriteFrame::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	if (!mapmacros)
	{
		// TODO: Report to the user when this is truncated!
		stream << "\tdc." << (game == Game::SONIC_1 ? "b" : "w") << "\t" << pieces.size() << "\n\n";
	}

	for (const auto &piece : pieces)
	{
		piece.toAssemblyStream(stream, game, mapmacros);
		stream << "\n";
	}
}

}
