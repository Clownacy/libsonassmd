#ifndef LIBSONASSMD_OBJECT_LAYOUT_H
#define LIBSONASSMD_OBJECT_LAYOUT_H

#include <istream>
#include <ostream>
#include <vector>

#include "object.h"

namespace libsonassmd {

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

}

#endif // LIBSONASSMD_OBJECT_LAYOUT_H
