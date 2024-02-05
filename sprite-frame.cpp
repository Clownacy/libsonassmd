#include "sprite-frame.h"

#include <sstream>

#include "assembler.h"
#include "common.h"

namespace libsonassmd {

void SpriteFrame::fromAssemblyStream(std::istream &stream, const SpritePiece::Format format)
{
	std::stringstream string_stream;
	if (!Assemble(stream, string_stream, format == SpritePiece::Format::SONIC_1 ? 1 : format == SpritePiece::Format::SONIC_2 ? 2 : 3))
		throw std::ios::failure("File could not be assembled");
	fromBinaryStream(string_stream, format);
}

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
