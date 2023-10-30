#pragma once

#include <ray/vec.hpp>
#include <ostream>

namespace ray{
    struct Color : Vec<std::uint8_t,3> {
        using Vec::Vec;

        static constexpr float to_f32(std::uint8_t channel) { return static_cast<float>(channel) / 0xff; }
        static constexpr std::uint8_t to_u8(float channel) { return static_cast<std::uint8_t>(channel * 0xff); }

        static constexpr Color from_f32(fvec3 const& normalized) { return {to_u8(normalized.x()), to_u8(normalized.y()), to_u8(normalized.z())}; }

        static constexpr Color from_hex(std::uint32_t hex) {
            auto ret = Color{};
            ret.z() = hex & 0xff;
            hex >>= 8;
            ret.y() = hex & 0xff;
            hex >>= 8;
            ret.x() = hex & 0xff;
            return ret;
        }

        [[nodiscard]] constexpr fvec3 to_f32() const { return {to_f32(x()), to_f32(y()), to_f32(z())}; }

    };
}