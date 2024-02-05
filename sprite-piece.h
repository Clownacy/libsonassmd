#ifndef LIBSONASSMD_SPRITE_PIECE_H
#define LIBSONASSMD_SPRITE_PIECE_H

#include <istream>
#include <ostream>

#include "assembler.h"

namespace libsonassmd {

struct SpritePiece
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

	void fromAssemblyStream(std::istream &stream, Game game);
	void fromBinaryStream(std::istream &stream, Game game);
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
	void toBinaryStream(std::ostream &stream, Game game) const;

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
