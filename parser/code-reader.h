#ifndef CODE_READER_H
#define CODE_READER_H

#include <iostream>

#include "syntactic.h"

namespace libsonassmd
{
	namespace CodeReader
	{
		Mappings ReadMappings(std::istream &input);
		DPLCs ReadDynamicPatternLoadCues(std::istream &input);
	}
}

#endif // CODE_READER_H
