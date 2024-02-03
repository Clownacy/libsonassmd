#include "common.h"

#include <cassert>
#include <iomanip>
#include <sstream>

namespace libmdsonass {

static unsigned long ReadBE(std::istream &stream, const unsigned int total_bytes)
{
	unsigned char bytes[sizeof(unsigned long)];

	assert(total_bytes <= sizeof(bytes));

	stream.read(reinterpret_cast<char*>(bytes), total_bytes);

	unsigned long value = 0;
	for (unsigned int i = 0; i < total_bytes; ++i)
	{
		value <<= 8;
		value |= bytes[i];
	}

	return value;
}

unsigned int ReadU8(std::istream &stream)
{
	return ReadBE(stream, 1);
}

unsigned int ReadU16BE(std::istream &stream)
{
	return ReadBE(stream, 2);
}

unsigned long ReadU32BE(std::istream &stream)
{
	return ReadBE(stream, 4);
}

int ReadS8(std::istream &stream)
{
	return CC_SIGN_EXTEND_UINT(7, ReadU8(stream));
}

int ReadS16BE(std::istream &stream)
{
	return CC_SIGN_EXTEND_UINT(15, ReadU16BE(stream));
}

long ReadS32BE(std::istream &stream)
{
	return CC_SIGN_EXTEND_ULONG(31, ReadU32BE(stream));
}

static void WriteBE(std::ostream &stream, const unsigned long value, const unsigned int total_bytes)
{
	unsigned char bytes[sizeof(unsigned long)];

	assert(total_bytes <= sizeof(bytes));

	for (unsigned int i = 0; i < total_bytes; ++i)
		bytes[i] = (value >> (total_bytes - 1 - i) * 8) & 0xFF;

	stream.write(reinterpret_cast<char*>(bytes), total_bytes);
}

void WriteU8(std::ostream &stream, const unsigned int value)
{
	WriteBE(stream, value, 1);
}

void WriteU16BE(std::ostream &stream, const unsigned int value)
{
	WriteBE(stream, value, 2);
}

void WriteU32BE(std::ostream &stream, const unsigned long value)
{
	WriteBE(stream, value, 4);
}

std::string IntegerToHexString(const unsigned long integer, const unsigned int minimum_digits)
{
	std::stringstream string_stream;
	string_stream << std::hex << std::uppercase << std::setfill('0') << std::setw(minimum_digits) << integer;
	return string_stream.str();
}

}
