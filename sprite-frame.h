#ifndef LIBMDSONASS_SPRITE_FRAME_H
#define LIBMDSONASS_SPRITE_FRAME_H

#include <istream>
#include <ostream>
#include <vector>

#include "sprite-piece.h"

namespace libsonassmd {

struct SpriteFrame
{
	void fromStream(std::istream &stream, SpritePiece::Format format);
	void toStream(std::ostream &stream, SpritePiece::Format format) const;

	std::vector<SpritePiece> pieces;
};

}

#endif // LIBMDSONASS_SPRITE_FRAME_H
