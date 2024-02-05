#include "sprite-piece.h"

#include <cassert>
#include <sstream>

#include "assembler.h"
#include "common.h"

namespace libsonassmd {

void SpritePiece::fromAssemblyStream(std::istream &stream, const Format format)
{
	std::stringstream string_stream;
	if (!Assemble(stream, string_stream, format == Format::SONIC_1 ? 1 : format == Format::SONIC_2 ? 2 : 3))
		throw std::ios::failure("File could not be assembled");
	fromBinaryStream(string_stream, format);
}

void SpritePiece::fromBinaryStream(std::istream &stream, const Format format)
{
	// This is specifically Sonic 2's mappings format. // TODO: No this fucking isn't
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

	switch (format)
	{
		case Format::MAPMACROS:
			assert(false);
			// Fallthrough
		case Format::SONIC_1:
			x = ReadS8(stream);
			break;

		case Format::SONIC_2:
			ReadU16BE(stream); // TODO: Actually use the 2-player data?
			// Fallthrough
		case Format::SONIC_3_AND_KNUCKLES:
			x = ReadS16BE(stream);
			break;
	}
}

void SpritePiece::toAssemblyStream(std::ostream &stream, const Format format) const
{
	if (format == Format::MAPMACROS)
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

		switch (format)
		{
			case Format::MAPMACROS:
				assert(false);
				// Fallthrough
			case Format::SONIC_1:
				stream << "\tdc.b\t" << x << "\n";
				break;

			case Format::SONIC_2:
				stream << "\tdc.w\t$" << IntegerToHexString(art_tile_upper_bits | static_cast<unsigned int>(tile_index) / 2, 2) << "\n";
				// Fallthrough
			case Format::SONIC_3_AND_KNUCKLES:
				stream << "\tdc.w\t" << x << "\n";
				break;
		}
	}
}

}
