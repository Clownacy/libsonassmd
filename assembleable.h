#ifndef LIBSONASSMD_ASSEMBLEABLE
#define LIBSONASSMD_ASSEMBLEABLE

#include <fstream>
#include <istream>
#include <ostream>

#include "assembler.h"

namespace libsonassmd {

class Assembleable
{
private:
	std::ifstream createFileInputStream(const char *file_path, std::ios::openmode flags) const;
	std::ofstream createFileOutputStream(const char *file_path, std::ios::openmode flags) const;

public:
	void fromAssemblyFile(const char *file_path, Game game);
	void fromBinaryFile(const char *file_path, Game game);
	void toAssemblyFile(const char *file_path, Game game, bool mapmacros) const;
	void toBinaryFile(const char *file_path, Game game) const;

	void fromAssemblyStream(std::istream &stream, Game game);
	virtual void fromBinaryStream(std::istream &stream, Game game) = 0;
	virtual void toAssemblyStream(std::ostream &stream, Game game, bool mapmacros) const = 0;
	void toBinaryStream(std::ostream &stream, Game game) const;
};

}

#endif // LIBSONASSMD_ASSEMBLEABLE
