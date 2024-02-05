#ifndef LIBSONASSMD_ASSEMBLEABLE
#define LIBSONASSMD_ASSEMBLEABLE

#include <istream>
#include <ostream>

#include "assembler.h"

namespace libsonassmd {

class Assembleable
{
public:
	void fromAssemblyStream(std::istream &stream, Game game);
	virtual void fromBinaryStream(std::istream &stream, Game game) = 0;
	virtual void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const = 0;
	void toBinaryStream(std::ostream &stream, Game game) const;
};

}

#endif // LIBSONASSMD_ASSEMBLEABLE
