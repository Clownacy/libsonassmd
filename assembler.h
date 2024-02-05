#ifndef LIBSONASSMD_ASSEMBLER
#define LIBSONASSMD_ASSEMBLER

#include <istream>
#include <ostream>

#include "clowncommon/clowncommon.h"

namespace libsonassmd {

cc_bool Assemble(std::istream &input, std::ostream &output, unsigned int mapmacros_format);

}

#endif // LIBSONASSMD_ASSEMBLER
