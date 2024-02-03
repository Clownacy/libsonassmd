#ifndef LIBSONASSMD_SPRITE_MAPPINGS_H
#define LIBSONASSMD_SPRITE_MAPPINGS_H

#include <istream>
#include <ostream>
#include <vector>

#include "dynamic-pattern-load-cues.h"
#include "sprite-frame.h"

namespace libsonassmd {

struct SpriteMappings
{
	void fromStream(std::istream &stream, SpritePiece::Format format);
	void toStream(std::ostream &stream, SpritePiece::Format format) const;

	bool applyDPLCs(const DynamicPatternLoadCues &dplcs);
	DynamicPatternLoadCues removeDPLCs();

	std::vector<SpriteFrame> frames;
};

}

#endif // LIBSONASSMD_SPRITE_MAPPINGS_H
