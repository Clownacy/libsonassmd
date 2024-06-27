#include "assembleable.h"

#include <cassert>
#include <fstream>
#include <sstream>

#include "comper.h"
#include "kosinski.h"
#include "kosplus.h"
#include "nemesis.h"

#include "assembler.h"

namespace libsonassmd {

void Assembleable::fromFile(const std::filesystem::path &file_path, const Format format)
{
	if (format == Format::ASSEMBLY)
	{
		std::stringstream string_stream(std::ios::in | std::ios::out | std::ios::binary);
		Assemble(file_path, string_stream, game);
		fromBinaryStream(string_stream);
	}
	else
	{
		std::ifstream stream(file_path, std::ios::binary);

		stream.exceptions(std::ios::failbit | std::ios::badbit | std::ios::eofbit);
		fromBinaryStream(stream);
	}
}

void Assembleable::toFile(const std::filesystem::path &file_path, const Format format) const
{
	std::ofstream stream(file_path, format == Format::ASSEMBLY ? std::ios::out : std::ios::binary);

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
			default:
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
			throw std::runtime_error("Data could not be decompressed.");

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
			default:
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
			throw std::runtime_error("Data could not be compressed.");
	}
}

void Assembleable::fromAssemblyStream(std::istream &stream)
{
	std::stringstream string_stream(std::ios::in | std::ios::out | std::ios::binary);
	Assemble(stream, string_stream, game);
	fromBinaryStream(string_stream);
}

void Assembleable::toBinaryStream(std::ostream &stream) const
{
	std::stringstream string_stream;
	toAssemblyStream(string_stream);
	Assemble(string_stream, stream, game);
}

}
