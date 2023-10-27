#include <ray/render/image_render.hpp>

namespace ray{
    ImageRender::ImageRender(std::size_t height, std::size_t width) {
        assert(height > 0 && width > 0);
        this->width = width;
        this->height = height;
    }

    void ImageRender::render_image(std::ofstream &out) {
       out << "P3\n" << width << ' ' << height << "\n255\n";

        for (std::size_t j = 0; j < height; ++j) {
            if(print_progress){
                std::clog << '\r' <<  "Progress: "<< std::setw(4) <<  j + 1 << " / " << height << std::endl;
            }
            for (std::size_t i = 0; i < width; ++i) {
                auto r = double(i) / (width-1);
                auto g = double(j) / (height-1);
                auto b = 0;

                int ir = static_cast<int>(255.999 * r);
                int ig = static_cast<int>(255.999 * g);
                int ib = static_cast<int>(255.999 * b);

                out << ir << ' ' << ig << ' ' << ib << '\n';
            }
        }
    }
}
