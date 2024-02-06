#ifndef LIBSONASSMD_ASSEMBLER
#define LIBSONASSMD_ASSEMBLER

#include <istream>
#include <ostream>

#include "common.h"

namespace libsonassmd {

bool Assemble(std::istream &input, std::ostream &output, Game game);

}

#endif // LIBSONASSMD_ASSEMBLER
