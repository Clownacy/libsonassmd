#include "common.h"

#include <cassert>
#include <iomanip>
#include <sstream>

namespace libsonassmd {

Game game;
bool mapmacros;

std::string IntegerToHexString(const unsigned long integer, const unsigned int minimum_digits)
{
	std::stringstream string_stream;
	string_stream << std::hex << std::uppercase << std::setfill('0') << std::setw(minimum_digits) << integer;
	return string_stream.str();
}

}
