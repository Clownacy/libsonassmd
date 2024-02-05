#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"

namespace libsonassmd {

struct DynamicPatternLoadCues : Assembleable
{
	struct Frame : Assembleable
	{
		struct Copy : Assembleable
		{
			int start;
			int length;

			Copy() = default;
			Copy(const int start, const int length) : start(start), length(length) {}

			int size_encoded() const;
			int total_segments() const;
			void fromBinaryStream(std::istream &stream, Game game) override;
			void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;
		};

		std::vector<Copy> copies;

		int getMappedTile(int tile_index) const;
		int size_encoded() const;
		int total_segments() const;
		void fromBinaryStream(std::istream &stream, Game game) override;
		void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;
	};

	void fromBinaryStream(std::istream &stream, Game game) override;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const override;

	std::vector<Frame> frames;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
