#include "object.h"

#include "common.h"

namespace libsonassmd {

// TODO: Non-Sonic 2 file formats.

void Object::fromBinaryStream(std::istream &stream)
{
	const unsigned int word1 = ReadU16BE(stream);
	const unsigned int word2 = ReadU16BE(stream);
	const unsigned int byte1 = ReadU8(stream);
	const unsigned int byte2 = ReadU8(stream);

	x = word1;
	y = word2 & 0xFFF;
	id = byte1 & 0x7F;
	subtype = byte2;
	respawn = (byte1 & 0x80) != 0;
	y_flip = (word2 & (1u << 15)) != 0;
	x_flip = (word2 & (1u << 14)) != 0;
}

unsigned int Object::OutputCommon() const
{
	// 0xFFFF is reserved for sentinel objects.
	if (x > 0xFFFE)
		throw std::range_error("X is too large");

	if (y > 0xFFF)
		throw std::range_error("Y is too large");

	if (id > 0xFF)
		throw std::range_error("ID is too large");

	if (subtype > 0xFF)
		throw std::range_error("Subtype is too large");

	return (y << 0) | (static_cast<unsigned int>(x_flip) << 13) | (static_cast<unsigned int>(y_flip) << 14) | (static_cast<unsigned int>(respawn) << 15);
}

void Object::toBinaryStream(std::ostream &stream) const
{
	const auto compact = OutputCommon();

	WriteU16BE(stream, x);
	WriteU16BE(stream, compact);
	WriteU8(stream, id);
	WriteU8(stream, subtype);
}

void Object::toAssemblyStream(std::ostream &stream) const
{
	const auto compact = OutputCommon();

	stream << "\tdc.w\t$" << IntegerToHexString(x, 4) << ", " << IntegerToHexString(compact, 4) << '\n';
	stream << "\tdc.b\t$" << IntegerToHexString(id, 2) << ", " << IntegerToHexString(subtype, 2) << '\n';
}

bool Object::operator==(const Object &object) const
{
	return x == object.x
	    && y == object.y
	    && id == object.id
	    && subtype == object.subtype
	    && respawn == object.respawn
	    && x_flip == object.x_flip
	    && y_flip == object.y_flip;
}

}
