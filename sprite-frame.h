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
	void fromBinaryStream(std::istream &stream);

public:
	void toAssemblyStream(std::ostream &stream) const;

	std::vector<SpritePiece> pieces;

	SpriteFrame() = default;
	SpriteFrame(std::istream &stream) {fromBinaryStream(stream);}
};

}

#endif // LIBSONASSMD_SPRITE_FRAME_H
