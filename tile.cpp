#include "tile.h"

#include <sstream>

#include "common.h"

namespace libsonassmd {

void Tile::fromBinaryStream(std::istream &stream, const Game game)
{
	// TODO: Rework the API so this isn't necessary?
	static_cast<void>(game);

	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; x += 2)
		{
			const unsigned char byte = ReadU8(stream);

			pixels[y][x + 0] = byte >> 4;
			pixels[y][x + 1] = byte & 0xF;
		}
	}
}

void Tile::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	// TODO: Rework the API so this isn't necessary?
	static_cast<void>(game);
	static_cast<void>(mapmacros);

	stream << "\tdc.b ";

	for (unsigned int y = 0; y < height; ++y)
	{
		for (unsigned int x = 0; x < width; x += 2)
		{
			if (x != 0 || y != 0)
				stream << ',';

			stream << '$';

			static const char nibble_to_char[0x10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
			stream << nibble_to_char[pixels[y][x + 0]];
			stream << nibble_to_char[pixels[y][x + 1]];
		}
	}

	stream << '\n';
}

}
