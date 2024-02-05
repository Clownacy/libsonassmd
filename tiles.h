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
	// This function isn't virtual, but that's okay since nothing calls the base one.
	// TODO: Maybe make this virtual anyway, since eventually the mappings will have their own binary output methods too.
	void toBinaryStream(std::ostream &stream, Game game) const;
};

}

#endif // LIBSONASSMD_TILES_H
