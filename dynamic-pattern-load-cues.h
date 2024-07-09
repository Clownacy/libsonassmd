#ifndef LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
#define LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H

#include <filesystem>
#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"

namespace libsonassmd {

class DynamicPatternLoadCues : public Assembleable
{
private:
	void fromBinaryStream(std::istream &stream) override;

public:
	class Frame
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

		Frame() = default;
		Frame(std::istream &stream) {fromBinaryStream(stream);}

		int getMappedTile(int tile_index) const;
		int size_encoded() const;
		int total_segments() const;
		void toAssemblyStream(std::ostream &stream) const;
	};

	DynamicPatternLoadCues() = default;
	DynamicPatternLoadCues(const std::filesystem::path &file_path, const Format format) {fromFile(file_path, format);}
	DynamicPatternLoadCues(std::istream &stream, const Format format) {fromStream(stream, format);}

	void toAssemblyStream(std::ostream &stream) const override;

	std::vector<Frame> frames;
};

}

#endif // LIBSONASSMD_DYNAMIC_PATTERN_LOAD_CUES_H
