#include "dynamic-pattern-load-cue.h"

#include <algorithm>

#include "common.h"

namespace libsonassmd {

int DynamicPatternLoadCue::getMappedTile(const int tile_index) const
{
	int base_tile = 0;

	for (const auto &copy : copies)
	{
		if (tile_index < base_tile + copy.length)
			return copy.start + (tile_index - base_tile);

		base_tile += copy.length;
	}

	return -1;
}

int DynamicPatternLoadCue::size_encoded() const
{
	int size = 0;
	for (const auto &copy : copies)
		size += copy.size_encoded();
	return size;
}

int DynamicPatternLoadCue::total_segments() const
{
	int segments = 0;
	for (const auto &copy : copies)
		segments += copy.total_segments();
	return segments;
}

void DynamicPatternLoadCue::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

	const unsigned int total_copies = settings.game != Game::SONIC_1 ? ReadU16BE(stream) :  ReadU8(stream);

	copies.reserve(total_copies);

	for (unsigned int current_copy = 0; current_copy < total_copies; ++current_copy)
		copies.emplace_back(stream);

	stream.clear();
	stream.exceptions(original_exceptions);
}

void DynamicPatternLoadCue::toAssemblyStream(std::ostream &stream) const
{
	if (!settings.mapmacros)
		stream << "\tdc." << (settings.game == Game::SONIC_1 ? 'b' : 'w') << '\t' << total_segments() << '\n';

	for (const auto &copy : copies)
		copy.toAssemblyStream(stream);
}

int DynamicPatternLoadCue::Copy::size_encoded() const
{
	return 2 * total_segments();
}

int DynamicPatternLoadCue::Copy::total_segments() const
{
	return CC_DIVIDE_CEILING(length, 0x10);
}

void DynamicPatternLoadCue::Copy::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

	const unsigned int word = ReadU16BE(stream);
	length = (word >> 4 * 3) + 1;
	start = word & 0xFFF;

	stream.clear();
	stream.exceptions(original_exceptions);
}

void DynamicPatternLoadCue::Copy::toAssemblyStream(std::ostream &stream) const
{
	// TODO: Sanity checks (overflow).
	for (int i = 0; i < total_segments(); ++i)
	{
		const int segment_start = start + 0x10 * i;
		const int segment_length = std::min(0x10, length - 0x10 * i);

		if (settings.mapmacros)
			stream << "\tdplcEntry\t" << segment_length << ", " << segment_start << "\n";
		else
			stream << "\tdc.w\t$" << IntegerToHexString((segment_length - 1) << 12 | (segment_start & 0xFFF), 4) << '\n';
	}
}

}
