#include "assembleable.h"

#include <sstream>

#include "assembler.h"

namespace libsonassmd {

std::ifstream Assembleable::createFileInputStream(const char* const file_path, const std::ios::openmode flags) const
{
	std::ifstream stream;

	stream.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
	stream.open(file_path, flags);

	return stream;
}

std::ofstream Assembleable::createFileOutputStream(const char* const file_path, const std::ios::openmode flags) const
{
	std::ofstream stream;

	stream.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
	stream.open(file_path, flags);

	return stream;
}

void Assembleable::fromAssemblyFile(const char* const file_path)
{
	auto stream = createFileInputStream(file_path, 0);
	fromAssemblyStream(stream);
}

void Assembleable::fromBinaryFile(const char* const file_path)
{
	auto stream = createFileInputStream(file_path, std::ios::binary);
	fromBinaryStream(stream);
}

void Assembleable::toAssemblyFile(const char* const file_path) const
{
	auto stream = createFileOutputStream(file_path, 0);
	toAssemblyStream(stream);
}

void Assembleable::toBinaryFile(const char* const file_path) const
{
	auto stream = createFileOutputStream(file_path, std::ios::binary);
	toBinaryStream(stream);
}

void Assembleable::fromAssemblyStream(std::istream &stream)
{
	std::stringstream string_stream(std::ios::in | std::ios::out | std::ios::binary);
	if (!Assemble(stream, string_stream, game))
		throw std::ios::failure("File could not be assembled"); // TODO: Find a more appropriate exception type.
	fromBinaryStream(string_stream);
}

void Assembleable::toBinaryStream(std::ostream &stream) const
{
	std::stringstream string_stream;
	toAssemblyStream(string_stream);
	// TODO: Handle this failing.
	Assemble(string_stream, stream, game);
}

}
