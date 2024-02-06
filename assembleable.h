#ifndef LIBSONASSMD_ASSEMBLEABLE
#define LIBSONASSMD_ASSEMBLEABLE

#include <fstream>
#include <istream>
#include <iostream>
#include <ostream>

namespace libsonassmd {

class Assembleable
{
private:
	std::ifstream createFileInputStream(const char *file_path, std::ios::openmode flags) const;
	std::ofstream createFileOutputStream(const char *file_path, std::ios::openmode flags) const;
	void fromCompressedStream(std::istream &stream, bool (*function)(std::istream &input, std::iostream &output));
	void toCompressedStream(std::ostream &stream, bool (*function)(std::istream &input, std::ostream &output));

public:
	void fromAssemblyFile(const char *file_path);
	void fromBinaryFile(const char *file_path);
	void toAssemblyFile(const char *file_path) const;
	void toBinaryFile(const char *file_path) const;

	void fromComperStream(std::istream &stream);
	void fromKosinskiStream(std::istream &stream);
	void fromModuledKosinskiStream(std::istream &stream);
	void fromKosinskiPlusStream(std::istream &stream);
	void fromModuledKosinskiPlusStream(std::istream &stream);
	void fromNemesisStream(std::istream &stream);
	void toComperStream(std::ostream &stream);
	void toKosinskiStream(std::ostream &stream);
	void toModuledKosinskiStream(std::ostream &stream);
	void toKosinskiPlusStream(std::ostream &stream);
	void toModuledKosinskiPlusStream(std::ostream &stream);
	void toNemesisStream(std::ostream &stream);

	virtual void fromAssemblyStream(std::istream &stream);
	virtual void fromBinaryStream(std::istream &stream) = 0;
	virtual void toAssemblyStream(std::ostream &stream) const = 0;
	virtual void toBinaryStream(std::ostream &stream) const;
};

}

#endif // LIBSONASSMD_ASSEMBLEABLE
