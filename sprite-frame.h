#ifndef LIBSONASSMD_SPRITE_FRAME_H
#define LIBSONASSMD_SPRITE_FRAME_H

#include <istream>
#include <ostream>
#include <vector>

#include "sprite-piece.h"

namespace libsonassmd {

class SpriteFrame
{
private:
	void fromBinaryStream(std::istream &stream, Game game);

public:
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;

	std::vector<SpritePiece> pieces;

	SpriteFrame() = default;
	SpriteFrame(std::istream &stream, const Game game) {fromBinaryStream(stream, game);}
};

}

#endif // LIBSONASSMD_SPRITE_FRAME_H
