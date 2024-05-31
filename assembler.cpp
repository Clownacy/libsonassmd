#include "assembler.h"

#include <cassert>
#include <sstream>

#include "clownassembler/cpp/clownassembler.h"

namespace libsonassmd {

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

	assert(false);
	return 1;
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
	std::stringstream expanded_input;
	EmitMapMacros(expanded_input, game);
	// TODO: Is there any way to make a meta-stream that concatonates these two instead?
	expanded_input << input.rdbuf();

	// It's okay for some IO errors to occur here.
	const auto original_exceptions = input.exceptions();
	input.exceptions(original_exceptions & ~(std::ios::eofbit | std::ios::failbit));

	// TODO: Real filename.
	const bool success = ClownAssembler::Assemble(expanded_input, output, nullptr, nullptr, nullptr, "[Filename unknown]", false, false, false, false, false, nullptr);

	input.clear();
	input.exceptions(original_exceptions);

	return success;
}

}
