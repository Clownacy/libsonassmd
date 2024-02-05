#ifndef LIBSONASSMD_TILE_H
#define LIBSONASSMD_TILE_H

#include <istream>
#include <ostream>

#include "assembleable.h"

#include <array>
#include <istream>
#include <ostream>

#include "assembleable.h"

namespace libsonassmd {

struct Tile : Assembleable
{
	static constexpr unsigned int width = 8;
	static constexpr unsigned int height = 8;
	static constexpr unsigned int size = width * height / 2;

	std::array<std::array<unsigned char, width>, height> pixels;

	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;
	// This function isn't virtual, but that's okay since nothing calls the base one.
	// TODO: Maybe make this virtual anyway, since eventually the mappings will have their own binary output methods too.
	void toBinaryStream(std::ostream &stream, Game game) const;
};

}

#endif // LIBSONASSMD_TILE_H
