#include "assembleable.h"

#include <cassert>
#include <sstream>

#include "comper.h"
#include "kosinski.h"
#include "kosplus.h"
#include "nemesis.h"

#include "assembler.h"

namespace libsonassmd {

void Assembleable::fromFile(const char* const file_path, const Format format)
{
	std::ifstream stream(file_path, format == Format::ASSEMBLY ? 0 : std::ios::binary);

	stream.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
	fromStream(stream, format);
}

void Assembleable::toFile(const char* const file_path, const Format format) const
{
	std::ofstream stream(file_path, format == Format::ASSEMBLY ? 0 : std::ios::binary);

	stream.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
	toStream(stream, format);
}

void Assembleable::fromStream(std::istream &stream, const Format format)
{
	if (format == Format::ASSEMBLY)
	{
		fromAssemblyStream(stream);
	}
	else if (format == Format::BINARY)
	{
		fromBinaryStream(stream);
	}
	else
	{
		bool success;
		std::stringstream string_stream(std::ios::binary | std::ios::in | std::ios::out);
		string_stream.exceptions(std::ios::badbit | std::ios::eofbit | std::ios::failbit);

		// mdcomp doesn't like exceptions, so temporarily disable them.
		const auto original_exceptions = stream.exceptions();
		stream.exceptions(std::ios::goodbit);

		switch (format)
		{
			case Format::ASSEMBLY:
			case Format::BINARY:
				assert(false);
				// Fallthrough
			case Format::COMPER:
				success = comper::decode(stream, string_stream);
				break;

			case Format::KOSINSKI:
				success = kosinski::decode(stream, string_stream);
				break;

			case Format::MODULED_KOSINSKI:
				success = kosinski::moduled_decode(stream, string_stream);
				break;

			case Format::KOSINSKI_PLUS:
				success = kosplus::decode(stream, string_stream);
				break;

			case Format::MODULED_KOSINSKI_PLUS:
				success = kosplus::moduled_decode(stream, string_stream);
				break;

			case Format::NEMESIS:
				success = nemesis::decode(stream, string_stream);
				break;
		}

		stream.clear();
		stream.exceptions(original_exceptions);

		if (!success)
			throw std::ios::failure("Data could not be decompressed."); // TODO: Find a more appropriate exception type.

		// mdcomp may have changed the read index (notably the Kosinski decompressor does), so rewind it here.
		string_stream.seekg(0, std::ios::beg);

		fromBinaryStream(string_stream);
	}
}

void Assembleable::toStream(std::ostream &stream, const Format format) const
{
	if (format == Format::ASSEMBLY)
	{
		toAssemblyStream(stream);
	}
	else if (format == Format::BINARY)
	{
		toBinaryStream(stream);
	}
	else
	{
		bool success;
		std::stringstream string_stream(std::ios::binary | std::ios::in | std::ios::out);

		toBinaryStream(string_stream);

		switch (format)
		{
			case Format::ASSEMBLY:
			case Format::BINARY:
				assert(false);
				// Fallthrough
			case Format::COMPER:
				success = comper::encode(string_stream, stream);
				break;

			case Format::KOSINSKI:
				success = kosinski::encode(string_stream, stream);
				break;

			case Format::MODULED_KOSINSKI:
				success = kosinski::moduled_encode(string_stream, stream);
				break;

			case Format::KOSINSKI_PLUS:
				success = kosplus::encode(string_stream, stream);
				break;

			case Format::MODULED_KOSINSKI_PLUS:
				success = kosplus::moduled_encode(string_stream, stream);
				break;

			case Format::NEMESIS:
				success = nemesis::encode(string_stream, stream);
				break;
		}

		if (!success)
			throw std::ios::failure("Data could not be compressed."); // TODO: Find a more appropriate exception type.
	}
}

void Assembleable::fromAssemblyStream(std::istream &stream)
{
	std::stringstream string_stream(std::ios::in | std::ios::out | std::ios::binary);
	if (!Assemble(stream, string_stream, game))
		throw std::ios::failure("Data could not be assembled."); // TODO: Find a more appropriate exception type.
	fromBinaryStream(string_stream);
}

void Assembleable::toBinaryStream(std::ostream &stream) const
{
	std::stringstream string_stream;
	toAssemblyStream(string_stream);
	if (!Assemble(string_stream, stream, game))
		throw std::ios::failure("Data could not be assembled."); // TODO: Find a more appropriate exception type.
}

}
