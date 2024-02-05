#ifndef LIBSONASSMD_SPRITE_PIECE_H
#define LIBSONASSMD_SPRITE_PIECE_H

#include <istream>
#include <ostream>

#include "assembleable.h"

namespace libsonassmd {

struct SpritePiece : Assembleable
{
	enum class Format
	{
		SONIC_1,
		SONIC_2,
		SONIC_3_AND_KNUCKLES,
		MAPMACROS
	};

	struct Tile
	{
		int index;
		int x;
		int y;
		int palette_line;
		bool x_flip;
		bool y_flip;
	};

	SpritePiece() = default;
	SpritePiece(
		const int x,
		const int y,
		const int width,
		const int height,
		const bool priority,
		const int palette_line,
		const bool y_flip,
		const bool x_flip,
		const int tile_index)
		: x(x)
		, y(y)
		, width(width)
		, height(height)
		, priority(priority)
		, palette_line(palette_line)
		, y_flip(y_flip)
		, x_flip(x_flip)
		, tile_index(tile_index){};

	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;

	int x;
	int y;
	int width;
	int height;
	bool priority;
	int palette_line;
	bool y_flip;
	bool x_flip;
	int tile_index;
};

}

#endif // LIBSONASSMD_SPRITE_PIECE_H
