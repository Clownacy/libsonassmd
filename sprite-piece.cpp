#include "sprite-piece.h"

#include "common.h"

namespace libsonassmd {

void SpritePiece::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

	y = ReadS8(stream);
	const unsigned int size = ReadU8(stream);
	width = ((size >> 2) & 3) + 1;
	height = ((size >> 0) & 3) + 1;
	const unsigned int art_tile = ReadU16BE(stream);
	priority = (art_tile & (1 << 15)) != 0;
	palette_line = (art_tile >> 13) & 3;
	y_flip = (art_tile & (1 << 12)) != 0;
	x_flip = (art_tile & (1 << 11)) != 0;
	tile_index = art_tile & 0x7FF;

	switch (game)
	{
		case Game::SONIC_1:
			x = ReadS8(stream);
			break;

		case Game::SONIC_2:
			ReadU16BE(stream); // TODO: Actually use the 2-player data?
			// Fallthrough
		case Game::SONIC_3_AND_KNUCKLES:
			x = ReadS16BE(stream);
			break;
	}

	stream.clear();
	stream.exceptions(original_exceptions);
}

void SpritePiece::toAssemblyStream(std::ostream &stream) const
{
	if (mapmacros)
	{
		stream << "\tspritePiece " << x << ", " << y << ", " << width << ", " << height << ", " << tile_index << ", " << x_flip << ", " << y_flip << ", " << palette_line << ", " << priority;
	}
	else
	{
		// TODO: Report to the user when the coordinates are truncated!
		stream << "\tdc.b\t" << y << "\n";
		stream << "\tdc.b\t$" << IntegerToHexString(((static_cast<unsigned int>(width) - 1) << 2) | (static_cast<unsigned int>(height) - 1), 2) << "\n";

		const unsigned int art_tile_upper_bits = static_cast<unsigned int>(priority)     << 15
		                                       | static_cast<unsigned int>(palette_line) << 13
		                                       | static_cast<unsigned int>(y_flip)       << 12
		                                       | static_cast<unsigned int>(x_flip)       << 11;

		stream << "\tdc.w\t$" << IntegerToHexString(art_tile_upper_bits | static_cast<unsigned int>(tile_index), 4) << "\n";

		switch (game)
		{
			case Game::SONIC_1:
				stream << "\tdc.b\t" << x << "\n";
				break;

			case Game::SONIC_2:
				stream << "\tdc.w\t$" << IntegerToHexString(art_tile_upper_bits | static_cast<unsigned int>(tile_index) / 2, 2) << "\n";
				// Fallthrough
			case Game::SONIC_3_AND_KNUCKLES:
				stream << "\tdc.w\t" << x << "\n";
				break;
		}
	}
}

}
