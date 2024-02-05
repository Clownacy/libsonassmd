#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembler.h"

namespace libsonassmd {

struct DynamicPatternLoadCues
{
	struct Frame
	{
		struct Copy
		{
			int start;
			int length;

			int size_encoded() const;
			int total_segments() const;
			void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
		};

		std::vector<Copy> copies;

		int getMappedTile(int tile_index) const;
		int size_encoded() const;
		int total_segments() const;
		void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
	};

	void fromAssemblyStream(std::istream &stream, Game game);
	void fromBinaryStream(std::istream &stream, Game game);
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
	void toBinaryStream(std::ostream &stream, Game game) const;

	std::vector<Frame> frames;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
