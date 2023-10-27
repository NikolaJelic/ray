#pragma once
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>


namespace ray{
    class ImageRender{
        std::size_t  height{256};
        std::size_t  width{256};
    public:
        bool print_progress{false};
        ImageRender(std::size_t height, std::size_t width);
        void render_image(std::ofstream & out);

    };
}