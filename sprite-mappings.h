#ifndef LIBSONASSMD_SPRITE_MAPPINGS_H
#define LIBSONASSMD_SPRITE_MAPPINGS_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "dynamic-pattern-load-cues.h"
#include "sprite-frame.h"

namespace libsonassmd {

struct SpriteMappings : Assembleable
{
	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;

	bool applyDPLCs(const DynamicPatternLoadCues &dplcs);
	DynamicPatternLoadCues removeDPLCs();

	std::vector<SpriteFrame> frames;
};

}

#endif // LIBSONASSMD_SPRITE_MAPPINGS_H
