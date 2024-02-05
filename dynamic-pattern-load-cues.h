#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H

#include <istream>
#include <ostream>
#include <vector>

namespace libsonassmd {

struct DynamicPatternLoadCues
{
	enum class Format
	{
		SONIC_1,
		SONIC_2_AND_3_AND_KNUCKLES_AND_CD,
		MAPMACROS
	};

	struct Frame
	{
		struct Copy
		{
			int start;
			int length;

			int size_encoded() const;
			int total_segments() const;
			void toStream(std::ostream &stream, Format format) const;
		};

		std::vector<Copy> copies;

		int getMappedTile(int tile_index) const;
		int size_encoded() const;
		int total_segments() const;
		void toStream(std::ostream &stream, Format format) const;
	};

	void fromAssemblyStream(std::istream &stream, Format format);
	void fromBinaryStream(std::istream &stream, Format format);
	void toAssemblyStream(std::ostream &stream, Format format) const;

	std::vector<Frame> frames;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
