
#include "ray/image_render.hpp"
#include "ray/vec.hpp"
#include "ray/image.hpp"

int main() {
    static constexpr auto extent = ray::uvec2{1000U, 80U};
    auto image = ray::Image{extent};
    for (std::uint32_t row = 0; row < image.extent().y(); ++row) {
        auto const ratio = static_cast<float>(row) / static_cast<float>(image.extent().y());
        auto const tint = ratio * static_cast<float>(0xff);
        for (std::uint32_t col = 0; col < image.extent().x(); ++col) {
            auto& rgb = image[{row,col}];
            rgb.x() = 0xff;
            rgb.y() = static_cast<std::uint8_t>(tint);
        }
    } 

    ray::io::write(image, "test.ppm");
    return 0;
}
