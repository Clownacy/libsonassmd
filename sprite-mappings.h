#ifndef LIBSONASSMD_SPRITE_MAPPINGS_H
#define LIBSONASSMD_SPRITE_MAPPINGS_H

#include <filesystem>
#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "dynamic-pattern-load-cues.h"
#include "sprite-frame.h"

namespace libsonassmd {

struct SpriteMappings : Assembleable
{
	SpriteMappings() = default;
	SpriteMappings(const std::filesystem::path &file_path, const Format format) {fromFile(file_path, format);}
	SpriteMappings(std::istream &stream, const Format format) {fromStream(stream, format);}

	void fromBinaryStream(std::istream &stream) override;
	void toAssemblyStream(std::ostream &stream) const override;

	bool applyDPLCs(const DynamicPatternLoadCues &dplcs);
	DynamicPatternLoadCues removeDPLCs();

	std::vector<SpriteFrame> frames;
};

}

#endif // LIBSONASSMD_SPRITE_MAPPINGS_H
