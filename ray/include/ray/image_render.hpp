#pragma once
#include <iostream>
#include <cassert>
#include <fstream>
#include <iomanip>
#include "image.hpp"


namespace ray {
    std::ostream& operator<<(std::ostream& out, Image const& image);

    namespace io {
        bool write(Image const& image, char const* path);
    }
} // namespace ray