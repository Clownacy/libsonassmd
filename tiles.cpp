#include "tiles.h"

#include <sstream>
#include <utility>

namespace libsonassmd {

void Tiles::fromBinaryStream(std::istream &stream)
{
	clear();

	// We use peek() to detect EOF, so disable the exceptions that it would throw.
	const auto original_exceptions = stream.exceptions();
	const auto new_exceptions = original_exceptions & ~(std::ios::eofbit | std::ios::failbit);

	stream.exceptions(new_exceptions);

	while (stream.peek() != std::ifstream::traits_type::eof())
	{
		stream.exceptions(original_exceptions);
		push_back({}); // TODO: emplace_back
		back().fromBinaryStream(stream);
		stream.exceptions(new_exceptions);
	}

	stream.clear();
	stream.exceptions(original_exceptions);
}

void Tiles::toBinaryStream(std::ostream &stream) const
{
	for (const auto &tile : std::as_const(*this))
		tile.toBinaryStream(stream);
}

void Tiles::toAssemblyStream(std::ostream &stream) const
{
	for (const auto &tile : std::as_const(*this))
		tile.toAssemblyStream(stream);
}

}
