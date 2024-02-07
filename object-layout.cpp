#include "object-layout.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <utility>

namespace libsonassmd {

bool ObjectLayout::compareObjects(const Object &a, const Object &b)
{
	return a.x < b.x;
}

void ObjectLayout::fromBinaryStream(std::istream &stream)
{
	objects.clear();

	// We use peek() to detect EOF, so disable the exceptions that it would throw.
	const auto original_exceptions = stream.exceptions();
	const auto new_exceptions = original_exceptions & ~(std::ios::eofbit | std::ios::failbit);

	stream.exceptions(new_exceptions);

	while (stream.peek() != std::istream::traits_type::eof())
	{
		stream.exceptions(original_exceptions);

		Object object;
		object.fromBinaryStream(stream);

		// Detect end-of-file sentinel.
		if (object.x == 0xFFFF)
			break;

		objects.insert(object);

		stream.exceptions(new_exceptions);
	}

	stream.clear();
	stream.exceptions(original_exceptions);
}

void ObjectLayout::toStreamCommon(std::ostream &stream, const bool assembly) const
{
	for (const auto &object : std::as_const(objects))
	{
		if (assembly)
			object.toAssemblyStream(stream);
		else
			object.toBinaryStream(stream);
	}
}

void ObjectLayout::toBinaryStream(std::ostream &stream) const
{
	toStreamCommon(stream, false);
}

void ObjectLayout::toAssemblyStream(std::ostream &stream) const
{
	toStreamCommon(stream, true);
}

}
