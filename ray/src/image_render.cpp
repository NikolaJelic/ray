#include "ray/image_render.hpp"
#include "ray/color.hpp"

namespace ray {

    std::ostream &operator<<(std::ostream &out, const Image &image) {
        out << "P3\n" << image.extent().x() << ' ' << image.extent().y() << "\n255\n";
        for (std::uint32_t row = 0; row < image.extent().y(); ++row) {
            for (std::uint32_t col = 0; col < image.extent().x(); ++col) {
                auto const& rgb = image[{row, col}];
                for (auto const channel : rgb) { out << static_cast<int>(channel) << ' '; }
            }
            out << '\n';
        }
        return out;
    }
    bool io::write(Image const& image, char const* path) {
        if (auto file = std::ofstream(path)) { return static_cast<bool>(file << image); }
        return false;
    }

}
