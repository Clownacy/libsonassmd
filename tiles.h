#ifndef LIBSONASSMD_TILES_H
#define LIBSONASSMD_TILES_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "tile.h"

namespace libsonassmd {

struct Tiles : Assembleable
{
	std::vector<Tile> vector;

	auto total_bytes() const {return Tile::size * vector.size();}
	void fromBinaryStream(std::istream &stream) override;
	void toAssemblyStream(std::ostream &stream) const override;
	void toBinaryStream(std::ostream &stream) const override;
};

}

#endif // LIBSONASSMD_TILES_H
