#ifndef LIBSONASSMD_TILE_H
#define LIBSONASSMD_TILE_H

#include <istream>
#include <ostream>

#include <array>
#include <istream>
#include <ostream>

#include "assembler.h"

namespace libsonassmd {

struct Tile
{
	static constexpr unsigned int width = 8;
	static constexpr unsigned int height = 8;
	static constexpr unsigned int size = width * height / 2;

	std::array<std::array<unsigned char, width>, height> pixels;

	void fromBinaryStream(std::istream &stream, Game game);
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
	void toBinaryStream(std::ostream &stream, Game game) const;
};

}

#endif // LIBSONASSMD_TILE_H
