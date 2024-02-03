#ifndef LIBMDSONASS_SPRITE_PIECE_H
#define LIBMDSONASS_SPRITE_PIECE_H

#include <functional>
#include <istream>
#include <ostream>

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
		static constexpr unsigned int width = 8;
		static constexpr unsigned int height = 8;

		int index;
		int x;
		int y;
		int palette_line;
		bool x_flip;
		bool y_flip;
	};

	void fromStream(std::istream &stream, Format format);
	void toStream(std::ostream &stream, Format format) const;

	void iterateTiles(const std::function<void(const SpritePiece::Tile&)> &callback) const;

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

#endif // LIBMDSONASS_SPRITE_PIECE_H
