#include "sprite-frame.h"

#include "common.h"

namespace libsonassmd {

void SpriteFrame::fromBinaryStream(std::istream &stream, const SpritePiece::Format format)
{
	const int total_pieces = format == SpritePiece::Format::SONIC_1 ? ReadU8(stream) : ReadU16BE(stream);
	pieces.resize(total_pieces);

	for (auto &piece : pieces)
		piece.fromBinaryStream(stream, format);
}

void SpriteFrame::toAssemblyStream(std::ostream &stream, const SpritePiece::Format format) const
{
	if (format != SpritePiece::Format::MAPMACROS)
	{
		// TODO: Report to the user when this is truncated!
		stream << "\tdc." << (format == SpritePiece::Format::SONIC_1 ? "b" : "w") << "\t" << pieces.size() << "\n\n";
	}

	for (const auto &piece : pieces)
	{
		piece.toAssemblyStream(stream, format);
		stream << "\n";
	}
}

}
