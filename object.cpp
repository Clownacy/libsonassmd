#include "object.h"

#include <climits>

#include "common.h"

namespace libsonassmd {

void Object::fromBinaryStream(std::istream &stream)
{
	const auto original_exceptions = stream.exceptions();
	stream.exceptions(stream.badbit | stream.eofbit | stream.failbit);

	const unsigned int word1 = ReadU16BE(stream);
	const unsigned int word2 = ReadU16BE(stream);
	const unsigned int byte1 = ReadU8(stream);
	const unsigned int byte2 = ReadU8(stream);

	switch (settings.game)
	{
		case Game::SONIC_1:
			x = word1;
			y = word2 & 0xFFF;
			id = byte1 & 0x7F;
			subtype = byte2;
			respawn = (byte1 & 0x80) != 0;
			y_flip = (word2 & (1u << 15)) != 0;
			x_flip = (word2 & (1u << 14)) != 0;
			two_player_flag = false;
			break;

		case Game::SONIC_2:
			x = word1;
			y = word2 & 0xFFF;
			id = byte1;
			subtype = byte2;
			respawn = (word2 & (1u << 15)) != 0;
			y_flip = (word2 & (1u << 14)) != 0;
			x_flip = (word2 & (1u << 14)) != 0;
			two_player_flag = (word2 & (1u << 12)) != 0;
			break;

		case Game::SONIC_3_AND_KNUCKLES:
			x = word1;
			y = word2 & 0xFFF;
			id = byte1;
			subtype = byte2;
			respawn = (word2 & (1u << 15)) != 0;
			y_flip = (word2 & (1u << 14)) != 0;
			x_flip = (word2 & (1u << 13)) != 0;
			two_player_flag = false;
			break;
	}

	stream.clear();
	stream.exceptions(original_exceptions);
}

void Object::toStreamCommon(std::ostream &stream, const bool assembly) const
{
#if USHRT_MAX != 0xFFFF
	if (x > 0xFFFF)
		throw std::range_error("X is too large");
#endif

	if (y > 0xFFF)
		throw std::range_error("Y is too large");

	if (id > (settings.game == Game::SONIC_1 ? 0x7F : 0xFF))
		throw std::range_error("ID is too large");

#if UCHAR_MAX != 0xFF
	if (subtype > 0xFF)
		throw std::range_error("Subtype is too large");
#endif

	unsigned int compact_word;

	switch (settings.game)
	{
		case Game::SONIC_1:
			compact_word = (y << 0) | (static_cast<unsigned int>(x_flip) << 14) | (static_cast<unsigned int>(y_flip) << 15);
			break;

		case Game::SONIC_2:
			compact_word = (y << 0) | (static_cast<unsigned int>(two_player_flag) << 12) | (static_cast<unsigned int>(x_flip) << 13) | (static_cast<unsigned int>(y_flip) << 14) | (static_cast<unsigned int>(respawn) << 15);
			break;

		case Game::SONIC_3_AND_KNUCKLES:
			compact_word = (y << 0) | (static_cast<unsigned int>(x_flip) << 13) | (static_cast<unsigned int>(y_flip) << 14) | (static_cast<unsigned int>(respawn) << 15);
			break;

		default:
			throw std::exception();

	}

	unsigned int compact_byte;

	switch (settings.game)
	{
		case Game::SONIC_1:
			compact_byte = (id << 0) | (static_cast<unsigned int>(respawn) << 7);
			break;

		case Game::SONIC_2:
		case Game::SONIC_3_AND_KNUCKLES:
			compact_byte = id;
			break;

		default:
			throw std::exception();
	}

	if (assembly)
	{
		stream << "\tdc.w\t$" << IntegerToHexString(x, 4) << ", " << IntegerToHexString(compact_word, 4) << '\n';
		stream << "\tdc.b\t$" << IntegerToHexString(compact_byte, 2) << ", " << IntegerToHexString(subtype, 2) << '\n';
	}
	else
	{
		WriteU16BE(stream, x);
		WriteU16BE(stream, compact_word);
		WriteU8(stream, compact_byte);
		WriteU8(stream, subtype);
	}
}

void Object::toBinaryStream(std::ostream &stream) const
{
	toStreamCommon(stream, false);
}

void Object::toAssemblyStream(std::ostream &stream) const
{
	toStreamCommon(stream, true);
}

bool Object::operator==(const Object &object) const
{
	return x == object.x
	    && y == object.y
	    && id == object.id
	    && subtype == object.subtype
	    && x_flip == object.x_flip
	    && y_flip == object.y_flip
	    && respawn == object.respawn
	    && two_player_flag == object.two_player_flag;
}

}
