#include "object-layout.h"

#include <algorithm>
#include <filesystem>
#include <fstream>
#include <utility>

ObjectLayout::ObjectLayout(const char* const file_path)
{
	const auto file_size = std::filesystem::file_size(file_path);

	if (file_size % Object::size_in_file != 0)
		throw std::runtime_error("File size is not a multiple of 6");

	std::ifstream stream(file_path, std::ios::binary);
	FromStream(stream, file_size / Object::size_in_file);
}

ObjectLayout::ObjectLayout(std::istream &stream, const std::size_t total_objects)
{
	FromStream(stream, total_objects);
}

void ObjectLayout::FromStream(std::istream &stream, const std::size_t total_objects)
{
	objects.reserve(total_objects);

	for (std::size_t i = 0; i < total_objects; ++i)
	{
		objects.emplace_back(stream);

		// If this is a sentinel object, we've reached the end.
		if (objects.back().x == 0xFFFF)
		{
			objects.pop_back();
			objects.shrink_to_fit();
			break;
		}
	}
}

std::ostream& ObjectLayout::operator>>(std::ostream &stream)
{
	// Objects must be sorted by their X coordinate.
	std::stable_sort(objects.begin(), objects.end(),
		[](const auto &a, const auto &b)
		{
			return (a.x < b.x);
		}
	);

	for (const auto &object : std::as_const(objects))
		object >> stream;

	return stream;
}
