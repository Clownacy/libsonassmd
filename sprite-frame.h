#ifndef LIBSONASSMD_SPRITE_FRAME_H
#define LIBSONASSMD_SPRITE_FRAME_H

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

#endif // LIBSONASSMD_SPRITE_FRAME_H
