#include "sprite-frame.h"

#include "common.h"

namespace libsonassmd {

void SpriteFrame::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

	const int total_pieces = game == Game::SONIC_1 ? ReadU8(stream) : ReadU16BE(stream);
	pieces.reserve(total_pieces);

	for (int i = 0; i < total_pieces; ++i)
		pieces.emplace_back(stream);

	stream.clear();
	stream.exceptions(original_exceptions);
}

void SpriteFrame::toAssemblyStream(std::ostream &stream) const
{
	if (!mapmacros)
	{
		// TODO: Report to the user when this is truncated!
		stream << "\tdc." << (game == Game::SONIC_1 ? "b" : "w") << "\t" << pieces.size() << "\n\n";
	}

	for (const auto &piece : pieces)
	{
		piece.toAssemblyStream(stream);
		stream << "\n";
	}
}

}
