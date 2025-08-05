#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUE_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUE_H

#include <istream>
#include <ostream>
#include <vector>

namespace libsonassmd {

class DynamicPatternLoadCue
{
private:
	void fromBinaryStream(std::istream &stream);

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
		void toAssemblyStream(std::ostream &stream) const;
	};

	std::vector<Copy> copies;

	DynamicPatternLoadCue() = default;
	DynamicPatternLoadCue(std::istream &stream) {fromBinaryStream(stream);}

	int getMappedTile(int tile_index) const;
	int size_encoded() const;
	int total_segments() const;
	void toAssemblyStream(std::ostream &stream) const;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
