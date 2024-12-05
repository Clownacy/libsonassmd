#ifndef LIBSONASSMD_COMMON_H
#define LIBSONASSMD_COMMON_H

#include <array>
#include <istream>
#include <numeric>
#include <string>

#include "clowncommon/clowncommon.h"

namespace libsonassmd {

enum class Game
{
	SONIC_1,
	SONIC_2,
	SONIC_3_AND_KNUCKLES
};

extern Game game;
extern bool mapmacros;

template<std::size_t S>
inline unsigned long ReadUnsignedBE(std::istream &stream)
{
	std::array<unsigned char, S> bytes;

	stream.read(reinterpret_cast<char*>(std::data(bytes)), std::size(bytes));

	return std::accumulate(bytes.cbegin(), bytes.cend(), 0UL, [](const auto &a, const auto &b)
	{
		return static_cast<unsigned long>(a) << 8 | b;
	});
}
template<>
inline unsigned long ReadUnsignedBE<1>(std::istream &stream)
{
	return stream.get();
}
inline unsigned int  ReadU8(std::istream &stream)    { return ReadUnsignedBE<1>(stream); }
inline unsigned int  ReadU16BE(std::istream &stream) { return ReadUnsignedBE<2>(stream); }
inline unsigned long ReadU32BE(std::istream &stream) { return ReadUnsignedBE<4>(stream); }

template<std::size_t S>
long ReadSignedBE(std::istream &stream)
{
	const auto value = ReadUnsignedBE<S>(stream);
	return CC_SIGN_EXTEND_ULONG(S * 8 - 1, value);
}
inline int  ReadS8(std::istream &stream)    { return ReadSignedBE<1>(stream); }
inline int  ReadS16BE(std::istream &stream) { return ReadSignedBE<2>(stream); }
inline long ReadS32BE(std::istream &stream) { return ReadSignedBE<4>(stream); }

template<std::size_t S>
inline void WriteBE(std::ostream &stream, const unsigned long value)
{
	std::array<unsigned char, S> bytes;

	for (std::size_t i = 0; i < std::size(bytes); ++i)
		bytes[i] = (value >> (std::size(bytes) - 1 - i) * 8) & 0xFF;

	stream.write(reinterpret_cast<const char*>(std::data(bytes)), std::size(bytes));
}
template<>
inline void WriteBE<1>(std::ostream &stream, const unsigned long value)
{
	stream.put(static_cast<std::ostream::char_type>(value));
}
inline void WriteU8(std::ostream &stream, const unsigned int value)     { WriteBE<1>(stream, value); }
inline void WriteU16BE(std::ostream &stream, const unsigned int value)  { WriteBE<2>(stream, value); }
inline void WriteU32BE(std::ostream &stream, const unsigned long value) { WriteBE<4>(stream, value); }

std::string IntegerToHexString(unsigned long integer, unsigned int minimum_digits = 1);

}

#endif // LIBSONASSMD_COMMON_H
