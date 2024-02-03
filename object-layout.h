#ifndef OBJECT_LAYOUT_H
#define OBJECT_LAYOUT_H

#include <istream>
#include <ostream>
#include <vector>

#include "object.h"

class ObjectLayout
{
private:
	void FromStream(std::istream &stream, std::size_t total_objects);

public:
	std::vector<Object> objects;

	ObjectLayout() = default;
	ObjectLayout(const char *file_path);
	ObjectLayout(std::istream &stream, std::size_t total_objects);
	std::ostream& operator>>(std::ostream &stream);
};

#endif // OBJECT_LAYOUT_H
