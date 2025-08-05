#include "dynamic-pattern-load-cues.h"

#include <random>
#include <string>

#include "common.h"

namespace libsonassmd {

void DynamicPatternLoadCues::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

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

	frames.reserve(total_frames);

	for (unsigned int current_frame = 0; current_frame < total_frames; ++current_frame)
	{
		stream.seekg(starting_position);
		stream.seekg(current_frame * 2, std::ios::cur);
		const unsigned int offset = ReadU16BE(stream);
		stream.seekg(starting_position);
		stream.seekg(offset);

		frames.emplace_back(stream);
	}

	stream.clear();
	stream.exceptions(original_exceptions);
}

void DynamicPatternLoadCues::toAssemblyStream(std::ostream &stream) const
{
	// TODO: This code is duplicated in the mappings code. Can this be made into a common function?
	std::random_device random_device;
	const std::string table_label = mapmacros ? ".offsets" : "CME_" + IntegerToHexString(random_device(), 8);

	stream << table_label << ":";

	if (mapmacros)
		stream << "\tmappingsTable";

	stream << "\n";

	for (const auto &frame : frames)
	{
		const std::string frame_label = mapmacros ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());

		if (mapmacros)
			stream << "\tmappingsTableEntry.w\t" << frame_label << "\n";
		else
			stream << "\tdc.w\t" << frame_label << "-" << table_label << "\n";
	}

	stream << "\n";

	for (const auto &frame : frames)
	{
		const std::string frame_label = mapmacros ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());
		stream << frame_label << ":";

		if (mapmacros)
			stream << "\tdplcHeader";

		stream << "\n";
		frame.toAssemblyStream(stream);

		if (mapmacros)
			stream << frame_label << "_End\n";

		stream << "\n";
	}

	stream << "\teven\n";
}

}
