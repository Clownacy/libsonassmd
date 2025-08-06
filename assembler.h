#ifndef LIBSONASSMD_ASSEMBLER
#define LIBSONASSMD_ASSEMBLER

#include <filesystem>
#include <istream>
#include <ostream>

namespace libsonassmd {

void Assemble(std::istream &input, std::ostream &output);
void Assemble(const std::filesystem::path &path, std::ostream &output);

}

#endif // LIBSONASSMD_ASSEMBLER
