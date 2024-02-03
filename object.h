#ifndef LIBSONASSMD_OBJECT_H
#define LIBSONASSMD_OBJECT_H

#include <istream>
#include <ostream>

namespace libsonassmd {

class Object
{
public:
	static constexpr unsigned int size_in_file = 6;

	unsigned short x, y;
	unsigned char id, subtype;
	bool respawn, x_flip, y_flip;

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
	Object(std::istream &stream);
	std::istream& operator<<(std::istream &stream);
	std::ostream& operator>>(std::ostream &stream) const;
	bool operator==(const Object &object) const;
};

}

#endif // LIBSONASSMD_OBJECT_H
