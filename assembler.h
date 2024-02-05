#ifndef LIBSONASSMD_ASSEMBLER
#define LIBSONASSMD_ASSEMBLER

#include <istream>
#include <ostream>

namespace libsonassmd {

enum class Game
{
	SONIC_1,
	SONIC_2,
	SONIC_3_AND_KNUCKLES
};

bool Assemble(std::istream &input, std::ostream &output, Game game);

}

#endif // LIBSONASSMD_ASSEMBLER
