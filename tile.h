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

	std::array<std::array<unsigned char, width>, height> pixels;

	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;
};

}

#endif // LIBSONASSMD_TILE_H
