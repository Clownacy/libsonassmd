#include "object-layout.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <utility>

namespace libsonassmd {

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
		objects.emplace_back();
		objects.back().fromBinaryStream(stream);

		// Detect end-of-file sentinel.
		if (objects.back().x == 0xFFFF)
		{
			objects.pop_back();
			objects.shrink_to_fit();
			break;
		}

		stream.exceptions(new_exceptions);
	}

	stream.clear();
	stream.exceptions(original_exceptions);
}

void ObjectLayout::toStreamCommon(std::ostream &stream, const bool assembly) const
{
	// TODO: Not this.
	ObjectLayout copy(*this);

	// Objects must be sorted by their X coordinate.
	std::stable_sort(copy.objects.begin(), copy.objects.end(),
		[](const auto &a, const auto &b)
		{
			return (a.x < b.x);
		}
	);

	for (const auto &object : std::as_const(copy.objects))
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
