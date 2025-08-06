#include "sprite-mappings.h"

#include <algorithm>
#include <fstream>
#include <random>
#include <string>

#include "common.h"
#include "parser/code-reader.h"

namespace libsonassmd {

SpriteMappings::SpriteMappings(const SpriteMappings &sprite_mappings, const DynamicPatternLoadCues &dplcs)
	: SpriteMappings(sprite_mappings)
{
	if (frames.size() != dplcs.frames.size())
		throw std::invalid_argument("Mappings and cues have differing number of frames");

	for (unsigned int frame_index = 0; frame_index < frames.size(); ++frame_index)
	{
		auto &dplc_frame = dplcs.frames[frame_index];

		for (auto &piece : frames[frame_index].pieces)
		{
			const int base_mapped_tile = dplc_frame.getMappedTile(piece.tile_index);

			for (int i = 0; i < piece.width * piece.height; ++i)
			{
				const int mapped_tile = dplc_frame.getMappedTile(piece.tile_index + i);

				if (mapped_tile == -1 || mapped_tile != base_mapped_tile + i)
					throw std::invalid_argument("Cues are not compatible with given mappings");
			}

			piece.tile_index = base_mapped_tile;
		}
	}
}

void SpriteMappings::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

	// TODO: This code is duplicated in the DPLC code. Can this be made into a common function?

	const auto starting_position = stream.tellg();

	// We need a heuristic to determine how many frames are contained
	// in this file, since the file itself lacks a proper indicator.
	unsigned int earliest_frame = ReadU16BE(stream);
	unsigned int total_frames = 1;

	for (unsigned int position = 2; position < earliest_frame; position += 2)
	{
		const unsigned int frame_offset = ReadU16BE(stream);

		// Valid offsets are never odd.
		if (settings.game != Game::SONIC_1 && frame_offset % 2 != 0)
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

void SpriteMappings::fromAssemblyStream(std::istream &stream)
{
	const auto raw_mappings = CodeReader::ReadMappings(stream);

	// TODO: Handle there being multiple offset tables (like Sonic 3's Sonic sprites).
	for (const auto &label : raw_mappings.offset_tables[0])
		frames.emplace_back(raw_mappings.frames.at(label));
}

void SpriteMappings::fromAssemblyFile(const std::filesystem::path &file_path)
{
	std::ifstream stream(file_path);
	fromAssemblyStream(stream);
}

void SpriteMappings::toAssemblyStream(std::ostream &stream) const
{
	// TODO: This code is duplicated in the DPLC code. Can this be made into a common function?
	std::random_device random_device;
	const std::string table_label = settings.mapmacros ? ".offsets" : "CME_" + IntegerToHexString(random_device(), 8);

	stream << table_label << ":";

	if (settings.mapmacros)
		stream << "\tmappingsTable";

	stream << "\n";

	for (const auto &frame : frames)
	{
		const std::string frame_label = settings.mapmacros ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());

		if (settings.mapmacros)
			stream << "\tmappingsTableEntry.w\t" << frame_label << "\n";
		else
			stream << "\tdc.w\t" << frame_label << "-" << table_label << "\n";
	}

	stream << "\n";

	for (const auto &frame : frames)
	{
		const std::string frame_label = settings.mapmacros ? ".frame" + std::to_string(&frame - frames.data()) : table_label + "_" + IntegerToHexString(&frame - frames.data());
		stream << frame_label << ":";

		if (settings.mapmacros)
			stream << "\tspriteHeader";

		stream << "\n";
		frame.toAssemblyStream(stream);

		if (settings.mapmacros)
			stream << frame_label << "_End\n\n";
	}

	stream << "\teven\n";
}

DynamicPatternLoadCues SpriteMappings::removeDPLCs()
{
	// Determine the total number of tiles.
	int total_tiles = 0;
	for (const auto &frame : frames)
		for (const auto &piece : frame.pieces)
			total_tiles = std::max(total_tiles, piece.tile_index + piece.width * piece.height);

	// I suppose a hash map would work here too.
	std::vector<int> tile_indices;
	tile_indices.resize(total_tiles);

	DynamicPatternLoadCues dplcs;
	dplcs.frames.reserve(frames.size());

	// Produce DPLC frames and modify the mappings frames to be relative to them.
	for (auto &frame : frames)
	{
		// Mark which tiles are mapped to which DPLC tiles.
		std::fill(tile_indices.begin(), tile_indices.end(), false);

		for (const auto &piece : frame.pieces)
			for (int i = 0; i < piece.width * piece.height; ++i)
				tile_indices[piece.tile_index + i] = true;

		// Use the marked tiles to determine the DPLC data for this frame.
		DynamicPatternLoadCues::Frame dplc_frame;

		for (int search_start = 0;;)
		{
			const auto first_true = std::find(std::next(tile_indices.begin(), search_start), tile_indices.end(), static_cast<int>(true));

			if (first_true == tile_indices.end())
				break;

			const int dplc_start = first_true - tile_indices.begin();

			const auto first_false = std::find(std::next(tile_indices.begin(), dplc_start), tile_indices.end(), static_cast<int>(false));

			if (first_false == tile_indices.end())
				search_start = total_tiles;
			else
				search_start = first_false - tile_indices.begin();

			const int dplc_length = search_start - dplc_start;

			dplc_frame.copies.emplace_back(dplc_start, dplc_length);
		}

		dplcs.frames.push_back(dplc_frame);

		// Go back and modify the mappings to be relative to the DPLC data.
		int current_tile_index = 0;
		for (auto &tile_index : tile_indices)
			if (tile_index != false)
				tile_index = current_tile_index++;

		for (auto &piece : frame.pieces)
			piece.tile_index = tile_indices[piece.tile_index];
	}

	return dplcs;
}

}
