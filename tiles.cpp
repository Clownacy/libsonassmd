#include "tiles.h"

#include <sstream>
#include <utility>

namespace libsonassmd {

void Tiles::fromBinaryStream(std::istream &stream)
{
	clear();

	// TODO: Detect and handle files that end with a partial tile.
	do
	{
		push_back({}); // TODO: emplace_back
		back().fromBinaryStream(stream);
	} while (!stream.eof());

	pop_back();
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
