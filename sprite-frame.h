#ifndef LIBMDSONASS_SPRITE_FRAME_H
#define LIBMDSONASS_SPRITE_FRAME_H

#include <istream>
#include <functional>
#include <optional>
#include <ostream>
#include <set>
#include <utility>
#include <vector>

#include "sprite-piece.h"

namespace libmdsonass {

struct SpriteFrame
{
	void fromStream(std::istream &stream, SpritePiece::Format format);
	void toStream(std::ostream &stream, SpritePiece::Format format) const;

	std::vector<SpritePiece::Tile> getUniqueTiles() const
	{
		std::vector<SpritePiece::Tile> tiles;
		std::set<int> recorded_tiles;

		iteratePieces(
			[&recorded_tiles, &tiles](const SpritePiece &piece)
			{
				piece.iterateTiles(
					[&recorded_tiles, &tiles](const SpritePiece::Tile &tile)
					{
						if (recorded_tiles.find(tile.index) != recorded_tiles.end())
							return;

						recorded_tiles.insert(tile.index);

						tiles.push_back(tile);
					}
				);
			}
		);

		return tiles;
	}

	std::vector<SpritePiece> pieces;

private:
	void iteratePieces(const std::function<void(const SpritePiece&)> &callback) const;
};

}

#endif // LIBMDSONASS_SPRITE_FRAME_H
