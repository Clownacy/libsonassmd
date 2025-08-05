#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H

#include <filesystem>
#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "dynamic-pattern-load-cue.h"

namespace libsonassmd {

class DynamicPatternLoadCues : public Assembleable
{
private:
	void fromBinaryStream(std::istream &stream) override;

public:
	using Frame = DynamicPatternLoadCue;

	DynamicPatternLoadCues() = default;
	DynamicPatternLoadCues(const std::filesystem::path &file_path, const Format format) {fromFile(file_path, format);}
	DynamicPatternLoadCues(std::istream &stream, const Format format) {fromStream(stream, format);}

	void toAssemblyStream(std::ostream &stream) const override;

	std::vector<Frame> frames;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
