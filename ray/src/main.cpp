#include <iostream>

#include <ray/render/image_render.hpp>

int main() {
    std::cout << "Hello, World!" << std::endl;
    ray::ImageRender imageRender{1000, 1000};
    std::ofstream out("out.ppm", std::ios::out);
    imageRender.print_progress = true;
    imageRender.render_image(out);
    return 0;
}
