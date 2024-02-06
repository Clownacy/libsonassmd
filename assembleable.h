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
	static Game game;
	static bool mapmacros;

	std::ifstream createFileInputStream(const char *file_path, std::ios::openmode flags) const;
	std::ofstream createFileOutputStream(const char *file_path, std::ios::openmode flags) const;

public:
	static Game getGame() {return game;}
	static bool mapMacrosEnabled() {return mapmacros;}
	static void setGame(const Game game) {Assembleable::game = game;}
	static void enableMapMacros(const bool mapmacros) {Assembleable::mapmacros = mapmacros;}

	void fromAssemblyFile(const char *file_path);
	void fromBinaryFile(const char *file_path);
	void toAssemblyFile(const char *file_path) const;
	void toBinaryFile(const char *file_path) const;

	virtual void fromAssemblyStream(std::istream &stream);
	virtual void fromBinaryStream(std::istream &stream) = 0;
	virtual void toAssemblyStream(std::ostream &stream) const = 0;
	virtual void toBinaryStream(std::ostream &stream) const;
};

}

#endif // LIBSONASSMD_ASSEMBLEABLE
