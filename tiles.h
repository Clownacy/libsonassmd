#ifndef LIBSONASSMD_TILES_H
#define LIBSONASSMD_TILES_H

#include <istream>
#include <ostream>
#include <vector>

#include "tile.h"

namespace libsonassmd {

struct Tiles
{
	std::vector<Tile> vector;

	auto total_bytes() const {return Tile::size * vector.size();}
	void fromBinaryStream(std::istream &stream);
	void toAssemblyStream(std::ostream &stream) const;
	void toBinaryStream(std::ostream &stream) const;
};

}

#endif // LIBSONASSMD_TILES_H
