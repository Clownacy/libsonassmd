#include "tiles.h"

#include <sstream>
#include <utility>

namespace libsonassmd {

void Tiles::fromBinaryStream(std::istream &stream, const Game game)
{
	// TODO: Rework the API so this isn't necessary?
	static_cast<void>(game);

	vector.clear();

	// TODO: Detect and handle files that end with a partial tile.
	do
	{
		vector.push_back({}); // TODO: emplace_back
		vector.back().fromBinaryStream(stream, game);
	} while (!stream.eof());

	vector.pop_back();
}

void Tiles::toAssemblyStream(std::ostream &stream, const Game game, const bool mapmacros) const
{
	// TODO: Rework the API so this isn't necessary?
	static_cast<void>(game);
	static_cast<void>(mapmacros);

	for (const auto &tile : std::as_const(vector))
		tile.toAssemblyStream(stream, game, mapmacros);
}

void Tiles::toBinaryStream(std::ostream &stream, const Game game) const
{
	// TODO: Rework the API so this isn't necessary?
	static_cast<void>(game);

	for (const auto &tile : std::as_const(vector))
		tile.toBinaryStream(stream, game);
}

}
