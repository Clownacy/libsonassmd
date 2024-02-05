#ifndef LIBSONASSMD_SPRITE_FRAME_H
#define LIBSONASSMD_SPRITE_FRAME_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "sprite-piece.h"

namespace libsonassmd {

struct SpriteFrame : Assembleable
{
	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;

	std::vector<SpritePiece> pieces;
};

}

#endif // LIBSONASSMD_SPRITE_FRAME_H
