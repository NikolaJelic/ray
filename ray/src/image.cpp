#include <ray/image.hpp>

namespace ray {

void Image::resize(uvec2 size) {
	m_data.resize(size.x() * size.y());
	m_size = size;
}

Color const& Image::operator[](Index2D i) const {
	auto const index = i.index(m_size);
	assert(index < m_data.size());
	return m_data[index];
}

Color& Image::operator[](Index2D i) { return const_cast<Color&>(std::as_const(*this)[i]); }
} // namespace ray