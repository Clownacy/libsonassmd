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
	virtual void fromAssemblyStream(std::istream &stream);
	virtual void fromBinaryStream(std::istream &stream) = 0;
	virtual void toAssemblyStream(std::ostream &stream) const = 0;
	virtual void toBinaryStream(std::ostream &stream) const;

public:
	enum class Format
	{
		ASSEMBLY,
		BINARY,
		COMPER,
		KOSINSKI,
		MODULED_KOSINSKI,
		KOSINSKI_PLUS,
		MODULED_KOSINSKI_PLUS,
		NEMESIS
	};

	void fromFile(const char *file_path, Format format);
	void fromStream(std::istream &stream, Format format);
	void toFile(const char *file_path, Format format) const;
	void toStream(std::ostream &stream, Format format) const;
};

}

#endif // LIBSONASSMD_ASSEMBLEABLE
