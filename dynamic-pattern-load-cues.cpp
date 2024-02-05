#include "dynamic-pattern-load-cues.h"

#include <algorithm>
#include <random>
#include <sstream>
#include <string>
#include <utility>

#include "assembler.h"
#include "common.h"

namespace libsonassmd {

void DynamicPatternLoadCues::fromBinaryStream(std::istream &stream, const Game game)
{
	// TODO: This code is duplicated in the mappings code. Can this be made into a common function?

	const auto starting_position = stream.tellg();

	// We need a heuristic to determine how many frames are contained
	// in this file, since the file itself lacks a proper indicator.
	unsigned int earliest_frame = ReadU16BE(stream);
	unsigned int total_frames = 1;

	for (unsigned int position = 2; position < earliest_frame; position += 2)
	{
		const unsigned int frame_offset = ReadU16BE(stream);

		// Valid offsets are never odd.
		if (game != Game::SONIC_1 && frame_offset % 2 != 0)
			break;

		++total_frames;

		// The first frame (and others) can have an offset of 0. This is a neat trick to encode
		// a sprite with 0 pieces without wasting any bytes. This trick can throw off this
		// heuristic, so we need to explicitly check for it.
		if (frame_offset != 0 && frame_offset < earliest_frame)
			earliest_frame = frame_offset;
	}

	frames.resize(total_frames);

	for (unsigned int current_frame = 0; current_frame < total_frames; ++current_frame)
	{
		stream.seekg(starting_position);
		stream.seekg(current_frame * 2, std::ios::cur);
		const unsigned int offset = ReadU16BE(stream);
		stream.seekg(starting_position);
		stream.seekg(offset);

		frames[current_frame].fromBinaryStream(stream, game);
	}
}

void DynamicPatternLoadCues::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	std::random_device random_device;
	const std::string table_label = mapmacros ? ".offsets" : "CME_" + IntegerToHexString(random_device(), 8);

	stream << table_label << ":";

	if (mapmacros)
		stream << "\tmappingsTable";

	stream << "\n";

	for (const auto &frame : std::as_const(frames))
	{
		const std::string frame_label = mapmacros ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());

		if (mapmacros)
			stream << "\tmappingsTableEntry.w\t" << frame_label << "\n";
		else
			stream << "\tdc.w\t" << frame_label << "-" << table_label << "\n";
	}

	stream << "\n";

	for (const auto &frame : std::as_const(frames))
	{
		const std::string frame_label = mapmacros ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());
		stream << frame_label << ":";

		if (mapmacros)
			stream << "\tdplcHeader";

		stream << "\n";
		frame.toAssemblyStream(stream, game, mapmacros);

		if (mapmacros)
			stream << frame_label << "_End\n";

		stream << "\n";
	}

	stream << "\teven\n";
}

int DynamicPatternLoadCues::Frame::getMappedTile(const int tile_index) const
{
	int base_tile = 0;

	for (const auto &copy : std::as_const(copies))
	{
		if (tile_index < base_tile + copy.length)
			return copy.start + (tile_index - base_tile);

		base_tile += copy.length;
	}

	return -1;
}

int DynamicPatternLoadCues::Frame::size_encoded() const
{
	int size = 0;
	for (const auto &copy : std::as_const(copies))
		size += copy.size_encoded();
	return size;
}

int DynamicPatternLoadCues::Frame::total_segments() const
{
	int segments = 0;
	for (const auto &copy : std::as_const(copies))
		segments += copy.total_segments();
	return segments;
}

void DynamicPatternLoadCues::Frame::fromBinaryStream(std::istream &stream, const Game game)
{
	const unsigned int total_copies = game != Game::SONIC_1 ? ReadU16BE(stream) :  ReadU8(stream);

	copies.resize(total_copies);

	for (unsigned int current_copy = 0; current_copy < total_copies; ++current_copy)
		copies[current_copy].fromBinaryStream(stream, game);
}

void DynamicPatternLoadCues::Frame::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	if (!mapmacros)
		stream << "\tdc." << (game == Game::SONIC_1 ? 'b' : 'w') << '\t' << total_segments() << '\n';

	for (const auto &copy : std::as_const(copies))
		copy.toAssemblyStream(stream, game, mapmacros);
}

int DynamicPatternLoadCues::Frame::Copy::size_encoded() const
{
	return 2 * total_segments();
}

int DynamicPatternLoadCues::Frame::Copy::total_segments() const
{
	return CC_DIVIDE_CEILING(length, 0x10);
}

void DynamicPatternLoadCues::Frame::Copy::fromBinaryStream(std::istream &stream, const Game game)
{
	const unsigned int word = ReadU16BE(stream);
	length = (word >> 4 * 3) + 1;
	start = word & 0xFFF;
}

void DynamicPatternLoadCues::Frame::Copy::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	// TODO: Sanity checks (overflow).
	for (int i = 0; i < total_segments(); ++i)
	{
		const int segment_start = start + 0x10 * i;
		const int segment_length = std::min(0x10, length - 0x10 * i);

		if (mapmacros)
			stream << "\tdplcEntry\t" << segment_length << ", " << segment_start << "\n";
		else
			stream << "\tdc.w\t$" << IntegerToHexString((segment_length - 1) << 12 | (segment_start & 0xFFF), 4) << '\n';
	}
}

}
