#ifndef LIBMDSONASS_COMMON_H
#define LIBMDSONASS_COMMON_H

#include <istream>
#include <string>

#include "clowncommon/clowncommon.h"

namespace libsonassmd {

unsigned int ReadU8(std::istream &stream);
unsigned int ReadU16BE(std::istream &stream);
unsigned long ReadU32BE(std::istream &stream);
int ReadS8(std::istream &stream);
int ReadS16BE(std::istream &stream);
long ReadS32BE(std::istream &stream);

void WriteU8(std::ostream &stream, unsigned int value);
void WriteU16BE(std::ostream &stream, unsigned int value);
void WriteU32BE(std::ostream &stream, unsigned long value);

std::string IntegerToHexString(unsigned long integer, unsigned int minimum_digits = 1);

}

#endif // LIBMDSONASS_COMMON_H
