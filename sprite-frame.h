#ifndef LIBSONASSMD_SPRITE_FRAME_H
#define LIBSONASSMD_SPRITE_FRAME_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembler.h"
#include "sprite-piece.h"

namespace libsonassmd {

struct SpriteFrame
{
	void fromAssemblyStream(std::istream &stream, Game game);
	void fromBinaryStream(std::istream &stream, Game game);
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
	void toBinaryStream(std::ostream &stream, Game game) const;

	std::vector<SpritePiece> pieces;
};

}

#endif // LIBSONASSMD_SPRITE_FRAME_H
