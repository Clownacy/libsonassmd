#include "assembleable.h"

#include <sstream>

#include "comper.h"
#include "kosinski.h"
#include "kosplus.h"
#include "nemesis.h"

#include "assembler.h"

namespace libsonassmd {

// File IO

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

// Compressed IO

void Assembleable::fromCompressedStream(std::istream &stream, bool (* const function)(std::istream &input, std::iostream &output))
{
	std::stringstream string_stream(std::ios::binary | std::ios::in | std::ios::out);
	function(stream, string_stream);
	fromBinaryStream(string_stream);
}

void Assembleable::fromComperStream(std::istream &stream)
{
	fromCompressedStream(stream, comper::decode);
}

void Assembleable::fromKosinskiStream(std::istream &stream)
{
	fromCompressedStream(stream, kosinski::decode);
}

void Assembleable::fromModuledKosinskiStream(std::istream &stream)
{
	fromCompressedStream(stream, [](std::istream &input, std::iostream &output){return kosinski::moduled_decode(input, output);});
}

void Assembleable::fromKosinskiPlusStream(std::istream &stream)
{
	fromCompressedStream(stream, kosplus::decode);
}

void Assembleable::fromModuledKosinskiPlusStream(std::istream &stream)
{
	fromCompressedStream(stream, [](std::istream &input, std::iostream &output){return kosplus::moduled_decode(input, output);});
}

void Assembleable::fromNemesisStream(std::istream &stream)
{
	fromCompressedStream(stream, [](std::istream &input, std::iostream &output){return nemesis::decode(input, output);});
}

void Assembleable::toCompressedStream(std::ostream &stream, bool (* const function)(std::istream &input, std::ostream &output))
{
	std::stringstream string_stream(std::ios::binary | std::ios::in | std::ios::out);
	toBinaryStream(string_stream);
	function(string_stream, stream);
}

void Assembleable::toComperStream(std::ostream &stream)
{
	toCompressedStream(stream, comper::encode);
}

void Assembleable::toKosinskiStream(std::ostream &stream)
{
	toCompressedStream(stream, kosinski::encode);
}

void Assembleable::toModuledKosinskiStream(std::ostream &stream)
{
	toCompressedStream(stream, [](std::istream &input, std::ostream &output){return kosinski::moduled_encode(input, output);});
}

void Assembleable::toKosinskiPlusStream(std::ostream &stream)
{
	toCompressedStream(stream, kosplus::encode);
}

void Assembleable::toModuledKosinskiPlusStream(std::ostream &stream)
{
	toCompressedStream(stream, [](std::istream &input, std::ostream &output){return kosplus::moduled_encode(input, output);});
}

void Assembleable::toNemesisStream(std::ostream &stream)
{
	toCompressedStream(stream, nemesis::encode);
}

// Assembler IO

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
