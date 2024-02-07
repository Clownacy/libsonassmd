#ifndef LIBSONASSMD_OBJECT_H
#define LIBSONASSMD_OBJECT_H

#include <istream>
#include <ostream>

namespace libsonassmd {

struct Object
{
private:
	unsigned int OutputCommon() const;

public:
	static constexpr unsigned int size_in_file = 6;

	unsigned short x, y;
	unsigned char id, subtype;
	bool respawn, x_flip, y_flip;

	Object() = default;
	Object(
		const unsigned short x,
		const unsigned short y,
		const unsigned char id,
		const unsigned char subtype,
		const bool respawn,
		const bool x_flip,
		const bool y_flip
	)
		: x(x)
		, y(y)
		, id(id)
		, subtype(subtype)
		, respawn(respawn)
		, x_flip(x_flip)
		, y_flip(y_flip)
	{};
	void fromBinaryStream(std::istream &stream);
	void toBinaryStream(std::ostream &stream) const;
	void toAssemblyStream(std::ostream &stream) const;
	bool operator==(const Object &object) const; // TODO: This shouldn't be necessary.
};

}

#endif // LIBSONASSMD_OBJECT_H
