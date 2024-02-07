#ifndef LIBSONASSMD_OBJECT_LAYOUT_H
#define LIBSONASSMD_OBJECT_LAYOUT_H

#include <istream>
#include <ostream>
#include <vector>

#include "assembleable.h"
#include "object.h"

namespace libsonassmd {

struct ObjectLayout : Assembleable
{
private:
	void sort();

public:
	std::vector<Object> objects;

	ObjectLayout() = default;
	ObjectLayout(const std::filesystem::path &file_path, const Format format) {fromFile(file_path, format);}
	ObjectLayout(std::istream &stream, const Format format) {fromStream(stream, format);}

	void fromBinaryStream(std::istream &stream) override;
	void toBinaryStream(std::ostream &stream) const override;
	void toAssemblyStream(std::ostream &stream) const override;
};

}

#endif // LIBSONASSMD_OBJECT_LAYOUT_H
