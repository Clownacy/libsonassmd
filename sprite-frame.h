#ifndef LIBSONASSMD_SPRITE_FRAME_H
#define LIBSONASSMD_SPRITE_FRAME_H

#include <istream>
#include <ostream>
#include <vector>

#include "sprite-piece.h"

namespace libsonassmd {

struct SpriteFrame
{
	void fromAssemblyStream(std::istream &stream, SpritePiece::Format format);
	void fromBinaryStream(std::istream &stream, SpritePiece::Format format);
	void toAssemblyStream(std::ostream &stream, SpritePiece::Format format) const;
	void toBinaryStream(std::ostream &stream, SpritePiece::Format format) const;

	std::vector<SpritePiece> pieces;
};

}

#endif // LIBSONASSMD_SPRITE_FRAME_H
