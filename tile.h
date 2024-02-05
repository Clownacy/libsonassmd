#ifndef LIBSONASSMD_TILE_H
#define LIBSONASSMD_TILE_H

#include <array>
#include <istream>
#include <ostream>

namespace libsonassmd {

struct Tile
{
	static constexpr unsigned int width = 8;
	static constexpr unsigned int height = 8;
	static constexpr unsigned int size = width * height / 2;

	std::array<std::array<unsigned char, width>, height> pixels;

	void fromBinaryStream(std::istream &stream);
	void toAssemblyStream(std::ostream &stream) const;
	void toBinaryStream(std::ostream &stream) const;
};

}

#endif // LIBSONASSMD_TILE_H
