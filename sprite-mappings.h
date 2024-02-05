#ifndef LIBSONASSMD_SPRITE_MAPPINGS_H
#define LIBSONASSMD_SPRITE_MAPPINGS_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembler.h"
#include "dynamic-pattern-load-cues.h"
#include "sprite-frame.h"

namespace libsonassmd {

struct SpriteMappings
{
	void fromAssemblyStream(std::istream &stream, Game game);
	void fromBinaryStream(std::istream &stream, Game game);
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
	void toBinaryStream(std::ostream &stream, Game game) const;

	bool applyDPLCs(const DynamicPatternLoadCues &dplcs);
	DynamicPatternLoadCues removeDPLCs();

	std::vector<SpriteFrame> frames;
};

}

#endif // LIBSONASSMD_SPRITE_MAPPINGS_H
