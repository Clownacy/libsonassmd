#include "sprite-mappings.h"

#include <algorithm>
#include <random>
#include <sstream>
#include <string>
#include <utility>

#include "assembler.h"
#include "common.h"

namespace libsonassmd {

// TODO: Move this to an interface class or something.
void SpriteMappings::fromAssemblyStream(std::istream &stream, const Game game)
{
	std::stringstream string_stream;
	if (!Assemble(stream, string_stream, game))
		throw std::ios::failure("File could not be assembled"); // TODO: Find a more appropriate exception type.
	fromBinaryStream(string_stream, game);
}

// TODO: Move this to an interface class or something.
void SpriteMappings::toBinaryStream(std::ostream &stream, const Game game) const
{
	std::stringstream string_stream;
	toAssemblyStream(string_stream, game, true);
	// TODO: Handle this failing.
	Assemble(string_stream, stream, game);
}

void SpriteMappings::fromBinaryStream(std::istream &stream, const Game game)
{
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
		if ((game == Game::SONIC_2 || game == Game::SONIC_3_AND_KNUCKLES) && frame_offset % 2 != 0)
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

void SpriteMappings::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	// TODO: This code is duplicated in the DPLC code. Can this be made into a common function?
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
			stream << "\tspriteHeader";

		stream << "\n";
		frame.toAssemblyStream(stream, game, mapmacros);

		if (mapmacros)
			stream << frame_label << "_End\n\n";
	}

	stream << "\teven\n";
}

bool SpriteMappings::applyDPLCs(const DynamicPatternLoadCues &dplcs)
{
	if (frames.size() != dplcs.frames.size())
		return false;

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
					return false;
			}

			piece.tile_index = base_mapped_tile;
		}
	}

	return true;
}

DynamicPatternLoadCues SpriteMappings::removeDPLCs()
{
	// Determine the total number of tiles.
	int total_tiles = 0;
	for (const auto &frame : std::as_const(frames))
		for (const auto &piece : std::as_const(frame.pieces))
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

		for (const auto &piece : std::as_const(frame.pieces))
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

			// TODO: emplace_back
			dplc_frame.copies.push_back({dplc_start, dplc_length});
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
