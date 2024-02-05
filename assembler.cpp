#include "assembler.h"

#include <cstring>
#include <sstream>

#include "clownassembler/semantic.h"

namespace libsonassmd {

struct InputCallbackData
{
	std::istream *input;
	std::stringstream mapmacros;
};

struct OutputCallbackData
{
	std::ostream *output;
	std::ostream::pos_type base_position;
};

static int ReadCharacter(std::istream &stream)
{
	const auto value = stream.get();

	return stream.eof() ? -1 : value;
}

static int ReadCharacter(void* const user_data)
{
	InputCallbackData* const callback_data = static_cast<InputCallbackData*>(user_data);

	const auto value = ReadCharacter(callback_data->mapmacros);

	return value != -1 ? value : ReadCharacter(*callback_data->input);
}

static char* ReadLine(std::istream* const stream, char* const buffer, const size_t buffer_size)
{
	// TODO: This isn't the closest emulation of fgets...
	stream->getline(buffer, buffer_size);

	if (stream->fail())
		return buffer[0] == '\0' ? nullptr : buffer;

	buffer[std::strlen(buffer)] = '\n'; // TODO: Doesn't properly null-terminate.

	return buffer;
}

static char* ReadLine(void* const user_data, char* const buffer, const size_t buffer_size)
{
	InputCallbackData* const callback_data = static_cast<InputCallbackData*>(user_data);

	const auto value = ReadLine(&callback_data->mapmacros, buffer, buffer_size);

	return value != nullptr ? value : ReadLine(callback_data->input, buffer, buffer_size);
}

static void Seek(void* const user_data, const size_t position)
{
	OutputCallbackData* const callback_data = static_cast<OutputCallbackData*>(user_data);

	callback_data->output->seekp(callback_data->base_position);
	callback_data->output->seekp(position, std::ios::cur);
}

static void WriteCharacter(void* const user_data, const int character)
{
	OutputCallbackData* const callback_data = static_cast<OutputCallbackData*>(user_data);

	callback_data->output->put(character);
}

static void WriteCharacters(void* const user_data, const char* const characters, const size_t total_characters)
{
	OutputCallbackData* const callback_data = static_cast<OutputCallbackData*>(user_data);

	callback_data->output->write(characters, total_characters);
}

static unsigned int GameToNumber(const Game game)
{
	switch (game)
	{
		case Game::SONIC_1:
			return 1;

		case Game::SONIC_2:
			return 2;

		case Game::SONIC_3_AND_KNUCKLES:
			return 3;
	}
}

static void EmitMapMacros(std::ostream &stream, const Game game)
{
	stream << "SonicMappingsVer = " << GameToNumber(game) << "\n";
	stream << R"(
mappingsTable macro
currentMappingsTable set *
	endm

mappingsTableEntry macro label
	dc.\0	label-currentMappingsTable
	endm

spriteHeader macro *
\* equ *
	if SonicMappingsVer=1
		dc.b	(\*_End-\*_Begin)/5
	elseif SonicMappingsVer=2
		dc.w	(\*_End-\*_Begin)/8
	elseif SonicMappingsVer=3
		dc.w	(\*_End-\*_Begin)/6
	endif
\*_Begin equ *
	endm

spritePiece macro xOffset, yOffset, width, height, tileIndex, xFlip, yFlip, palette, priority
	dc.b	yOffset
	dc.b	((width-1)<<2)|((height-1)<<0)
	dc.w	(priority<<15)|(palette<<13)|(yFlip<<12)|(xFlip<<11)|(tileIndex<<0)
	if SonicMappingsVer=2
		dc.w	(priority<<15)|(palette<<13)|(yFlip<<12)|(xFlip<<11)|((tileIndex/2)<<0)
	endif
	if SonicMappingsVer=1
		dc.b	xOffset
	else
		dc.w	xOffset
	endif
	endm

dplcHeader macro *
\* equ *
	if SonicMappingsVer=1
		dc.b	(\*_End-\*_Begin)/2
	elseif SonicMappingsVer=2
		dc.w	(\*_End-\*_Begin)/2
	elseif SonicMappingsVer=3
		dc.w	((\*_End-\*_Begin)/2)-1
	endif
\*_Begin equ *
	endm

dplcEntry macro totalTiles, tileIndex
	if SonicMappingsVer=3
		dc.w	(tileIndex<<4)|((totalTiles-1)<<0)
	else
		dc.w	((totalTiles-1)<<12)|(tileIndex<<0)
	endif
	endm

s3kPlayerDplcHeader macro *
	dplcHeader \*
	endm

s3kPlayerDplcEntry macro totalTiles, tileIndex
	dplcEntry \*
	endm
)";
};

bool Assemble(std::istream &input, std::ostream &output, const Game game)
{
	InputCallbackData input_callback_data = {
		&input
	};

	ClownAssembler_TextInput input_callbacks = {
		&input_callback_data,
		ReadCharacter,
		ReadLine
	};

	OutputCallbackData output_callback_data = {
		&output,
		output.tellp()
	};

	ClownAssembler_BinaryOutput output_callbacks = {
		&output_callback_data,
		WriteCharacter,
		WriteCharacters,
		Seek
	};

	EmitMapMacros(input_callback_data.mapmacros, game);

	// It's okay for some IO errors to occur here.
	const auto original_exceptions = input.exceptions();
	input.exceptions(original_exceptions & ~(std::ios::eofbit | std::ios::failbit));

	// TODO: Real filename.
	const bool success = ClownAssembler_Assemble(&input_callbacks, &output_callbacks, nullptr, nullptr, nullptr, "[Filename unknown]", cc_false, cc_false, cc_false, cc_false, cc_false, nullptr, nullptr);

	input.clear();
	input.exceptions(original_exceptions);

	return success;
}

}
