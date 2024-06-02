#ifndef LIBSONASSMD_ASSEMBLER
#define LIBSONASSMD_ASSEMBLER

#include <filesystem>
#include <istream>
#include <ostream>

#include "common.h"

namespace libsonassmd {

void Assemble(std::istream &input, std::ostream &output, Game game);
void Assemble(const std::filesystem::path &path, std::ostream &output, Game game);

}

#endif // LIBSONASSMD_ASSEMBLER
