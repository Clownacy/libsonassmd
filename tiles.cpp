#include "tiles.h"

#include <sstream>
#include <utility>

namespace libsonassmd {

void Tiles::fromBinaryStream(std::istream &stream)
{
	vector.clear();

	// TODO: Detect and handle files that end with a partial tile.
	do
	{
		vector.push_back({}); // TODO: emplace_back
		vector.back().fromBinaryStream(stream);
	} while (!stream.eof());

	vector.pop_back();
}

void Tiles::toBinaryStream(std::ostream &stream) const
{
	for (const auto &tile : std::as_const(vector))
		tile.toBinaryStream(stream);
}

}
