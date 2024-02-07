#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"

namespace libsonassmd {

struct DynamicPatternLoadCues : Assembleable
{
	struct Frame
	{
		struct Copy
		{
			int start;
			int length;

			Copy() = default;
			Copy(const int start, const int length) : start(start), length(length) {}

			int size_encoded() const;
			int total_segments() const;
			void fromBinaryStream(std::istream &stream);
			void toAssemblyStream(std::ostream &stream) const;
		};

		std::vector<Copy> copies;

		int getMappedTile(int tile_index) const;
		int size_encoded() const;
		int total_segments() const;
		void fromBinaryStream(std::istream &stream);
		void toAssemblyStream(std::ostream &stream) const;
	};

	DynamicPatternLoadCues() = default;
	DynamicPatternLoadCues(const char* const file_path, const Format format) {fromFile(file_path, format);}
	DynamicPatternLoadCues(std::istream &stream, const Format format) {fromStream(stream, format);}

	void fromBinaryStream(std::istream &stream) override;
	void toAssemblyStream(std::ostream &stream) const override;

	std::vector<Frame> frames;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
