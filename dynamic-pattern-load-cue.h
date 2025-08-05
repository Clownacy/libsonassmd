#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUE_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUE_H

#include <istream>
#include <ostream>
#include <vector>

#include "common.h"

namespace libsonassmd {

class DynamicPatternLoadCue
{
private:
	void fromBinaryStream(std::istream &stream, Game game);

public:
	class Copy
	{
	private:
		void fromBinaryStream(std::istream &stream);

	public:
		int start;
		int length;

		Copy() = default;
		Copy(const int start, const int length) : start(start), length(length) {}
		Copy(std::istream &stream) {fromBinaryStream(stream);}

		int size_encoded() const;
		int total_segments() const;
		void toAssemblyStream(std::ostream &stream, bool mapmacros) const;
	};

	std::vector<Copy> copies;

	DynamicPatternLoadCue() = default;
	DynamicPatternLoadCue(std::istream &stream, const Game game) {fromBinaryStream(stream, game);}

	int getMappedTile(int tile_index) const;
	int size_encoded() const;
	int total_segments() const;
	void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
