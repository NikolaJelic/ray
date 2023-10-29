#pragma once

#include <vector>

#include "vec.hpp"
#include "color.hpp"

namespace ray{
    struct Index2D {
	std::uint32_t row{};
	std::uint32_t col{};

	constexpr std::size_t index(uvec2 const extent) { return row * extent.x() + col; }
};
    class Image{
    public:
        Image() = default;
        explicit Image(uvec2 size){
            resize(size);
        }
        void resize(uvec2 size);

        Color const& operator[](Index2D i) const;
        Color& operator[](Index2D i);

        [[nodiscard]] uvec2 extent() const { return m_size; }

    private:
        std::vector<Color> m_data{};
        uvec2 m_size{};
    };
}