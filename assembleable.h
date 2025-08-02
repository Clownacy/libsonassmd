#ifndef LIBSONASSMD_ASSEMBLEABLE
#define LIBSONASSMD_ASSEMBLEABLE

#include <filesystem>
#include <iostream>
#include <istream>
#include <ostream>

namespace libsonassmd {

class Assembleable
{
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

private:
	virtual void fromAssemblyFile(const std::filesystem::path &file_path);
	virtual void fromBinaryFile(const std::filesystem::path &file_path);
	virtual void fromAssemblyStream(std::istream &stream);
	virtual void fromBinaryStream(std::istream &stream) = 0;
	virtual void toAssemblyStream(std::ostream &stream) const = 0;
	virtual void toBinaryStream(std::ostream &stream) const;

protected:
	void fromFile(const std::filesystem::path &file_path, Format format);
	void fromStream(std::istream &stream, Format format);

public:
	void toFile(const std::filesystem::path &file_path, Format format) const;
	void toStream(std::ostream &stream, Format format) const;
};

}

#endif // LIBSONASSMD_ASSEMBLEABLE
