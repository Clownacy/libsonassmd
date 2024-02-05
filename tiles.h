#ifndef LIBSONASSMD_TILES_H
#define LIBSONASSMD_TILES_H

#include <istream>
#include <ostream>

#include "assembleable.h"

#include <array>
#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "tile.h"

namespace libsonassmd {

struct Tiles : Assembleable
{
	std::vector<Tile> vector;

	auto size() const {return Tile::size * vector.size();}
	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;
};

}

#endif // LIBSONASSMD_TILES_H
