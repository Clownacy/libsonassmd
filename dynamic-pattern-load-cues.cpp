#include "dynamic-pattern-load-cues.h"

#include <algorithm>
#include <random>
#include <string>
#include <utility>

#include "common.h"

namespace libsonassmd {

DynamicPatternLoadCues::DynamicPatternLoadCues(std::istream &stream, const Format format)
{
	const auto starting_position = stream.tellg();

	unsigned int earliest_frame = ReadU16BE(stream);
	unsigned int total_frames = 1;

	for (unsigned int position = 2; position < earliest_frame; position += 2)
	{
		const unsigned int frame_offset = ReadU16BE(stream);

		if (format == Format::SONIC_2_AND_3_AND_KNUCKLES_AND_CD && (frame_offset & 1) != 0)
			break;

		++total_frames;

		if (earliest_frame > frame_offset)
			earliest_frame = frame_offset;
	}

	frames.resize(total_frames);

	for (unsigned int current_frame = 0; current_frame < total_frames; ++current_frame)
	{
		Frame &frame = frames[current_frame];

		stream.seekg(starting_position);
		stream.seekg(current_frame * 2, std::ios::cur);
		const unsigned int offset = ReadU16BE(stream);
		stream.seekg(starting_position);
		stream.seekg(offset);

		const unsigned int total_copies = format == Format::SONIC_2_AND_3_AND_KNUCKLES_AND_CD ? ReadU16BE(stream) :  ReadU8(stream);

		frame.copies.resize(total_copies);

		for (unsigned int current_copy = 0; current_copy < total_copies; ++current_copy)
		{
			const unsigned int word = ReadU16BE(stream);
			const int total_tiles = (word >> 4 * 3) + 1;
			const int tile_index = word & 0xFFF;

			frame.copies[current_copy] = Frame::Copy{tile_index, total_tiles};
		}
	}
}

void DynamicPatternLoadCues::toStream(std::ostream &stream, const Format format) const
{
	std::random_device random_device;
	const std::string table_label = format == Format::MAPMACROS ? ".offsets" : "CME_" + IntegerToHexString(random_device(), 8);

	stream << table_label << ":";

	if (format == DynamicPatternLoadCues::Format::MAPMACROS)
		stream << "\tmappingsTable";

	stream << "\n";

	for (const auto &frame : std::as_const(frames))
	{
		const std::string frame_label = format == Format::MAPMACROS ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());

		if (format == Format::MAPMACROS)
			stream << "\tmappingsTableEntry.w\t" << frame_label << "\n";
		else
			stream << "\tdc.w\t" << frame_label << "-" << table_label << "\n";
	}

	stream << "\n";

	for (const auto &frame : std::as_const(frames))
	{
		const std::string frame_label = format == Format::MAPMACROS ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());
		stream << frame_label << ":";

		if (format == DynamicPatternLoadCues::Format::MAPMACROS)
			stream << "\tdplcHeader";

		stream << "\n";
		frame.toStream(stream, format);

		if (format == DynamicPatternLoadCues::Format::MAPMACROS)
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

void DynamicPatternLoadCues::Frame::toStream(std::ostream &stream, const Format format) const
{
	if (format != Format::MAPMACROS)
		stream << "\tdc." << (format == Format::SONIC_1 ? 'b' : 'w') << '\t' << total_segments() << '\n';

	for (const auto &copy : std::as_const(copies))
		copy.toStream(stream, format);
}

int DynamicPatternLoadCues::Frame::Copy::size_encoded() const
{
	return 2 * total_segments();
}

int DynamicPatternLoadCues::Frame::Copy::total_segments() const
{
	return CC_DIVIDE_CEILING(length, 0x10);
}

void DynamicPatternLoadCues::Frame::Copy::toStream(std::ostream &stream, const Format format) const
{
	// TODO: Sanity checks (overflow).
	for (int i = 0; i < total_segments(); ++i)
	{
		const int segment_start = start + 0x10 * i;
		const int segment_length = std::min(0x10, length - 0x10 * i);

		if (format == Format::MAPMACROS)
			stream << "\tdplcEntry\t" << segment_length << ", " << segment_start << "\n";
		else
			stream << "\tdc.w\t$" << IntegerToHexString((segment_length - 1) << 12 | (segment_start & 0xFFF), 4) << '\n';
	}
}

}
