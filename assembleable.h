#ifndef LIBSONASSMD_ASSEMBLEABLE
#define LIBSONASSMD_ASSEMBLEABLE

#include <fstream>
#include <istream>
#include <ostream>

namespace libsonassmd {

class Assembleable
{
private:
	std::ifstream createFileInputStream(const char *file_path, std::ios::openmode flags) const;
	std::ofstream createFileOutputStream(const char *file_path, std::ios::openmode flags) const;

public:
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
