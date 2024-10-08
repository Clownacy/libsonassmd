#ifndef LIBSONASSMD_TILES_H
#define LIBSONASSMD_TILES_H

#include <filesystem>
#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "tile.h"

namespace libsonassmd {

struct Tiles : public std::vector<Tile>, public Assembleable
{
	Tiles() = default;
	Tiles(const std::filesystem::path &file_path, const Format format) {fromFile(file_path, format);}
	Tiles(std::istream &stream, const Format format) {fromStream(stream, format);}

	auto total_bytes() const {return Tile::size * size();}
	void fromBinaryStream(std::istream &stream) override;
	void toAssemblyStream(std::ostream &stream) const override;
	void toBinaryStream(std::ostream &stream) const override;
};

}

#endif // LIBSONASSMD_TILES_H
