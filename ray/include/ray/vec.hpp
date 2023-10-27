#pragma once

#include <array>
#include <cassert>
#include <cmath>
#include <cstdint>

namespace ray {
    template<typename Type, std::size_t Dimension>
    class Vec {
        using storage = std::array<Type, Dimension>;

    public:
        using value_type = Type;
        using iterator = typename storage::iterator;
        using const_iterator = typename storage::const_iterator;
        static constexpr auto size_v = Dimension;

        static constexpr std::size_t size() { return size_v; }

        Vec() = default;

        explicit constexpr Vec(Type const t) {
            for (Type &value: values) { value = t; }
        }

        template<std::same_as<Type>... T>
        requires(sizeof...(T) == Dimension)
        constexpr Vec(T const... t) : values{t...} {}

        constexpr Type& at(std::size_t index){
            assert(index < Dimension);
            return values[index];
        }


        constexpr Type& operator[](std::size_t index) { return at(index); }
        constexpr Type const& operator[](std::size_t index) const { return at(index); }

        constexpr Type& x() { return at(0); }
        constexpr Type const& x() const { return at(0); }
        constexpr Type& y() requires(Dimension > 1) { return at(1); }
        constexpr Type const& y() const requires(Dimension > 1) { return at(1); }
        constexpr Type& z() requires(Dimension > 2) { return at(2); }
        constexpr Type const& z() const requires(Dimension > 2) { return at(2); }

        constexpr Vec& operator+=(Vec const& other) {
            for_each(*this, [&other](std::size_t i, Type& value) { value += other.at(i); });
            return *this;
        }

        constexpr Vec& operator-=(Vec const& other) {
            for_each(*this, [&other](std::size_t i, Type& value) { value -= other.at(i); });
            return *this;
        }

        constexpr Vec& operator*=(Vec const& other) {
            for_each(*this, [&other](std::size_t i, Type& value) { value *= other.at(i); });
            return *this;
        }

        constexpr Vec& operator/=(Vec const& other) {
            for_each(*this, [&other](std::size_t i, Type& value) { value /= other.at(i); });
            return *this;
        }

        constexpr Vec& operator+=(Type const type) {
            for_each(*this, [type](std::size_t, Type& value) { value += type; });
            return *this;
        }

        constexpr Vec& operator-=(Type const type) {
            for_each(*this, [type](std::size_t, Type& value) { value -= type; });
            return *this;
        }

        constexpr Vec& operator*=(Type const type) {
            for_each(*this, [type](std::size_t, Type& value) { value *= type; });
            return *this;
        }

        constexpr Vec& operator/=(Type const type) {
            for_each(*this, [type](std::size_t, Type& value) { value /= type; });
            return *this;
        }

        friend constexpr Vec operator-(Vec const& v) {
            auto ret = v;
            for (auto& value : ret.m_values) { value = -value; }
            return ret;
        }

        template <typename F, typename T>
        static constexpr void for_each(T&& vec, F&& func) {
            for (std::size_t i = 0; i < Dimension; ++i) { func(i, vec.m_values[i]); }
        }

        constexpr iterator begin() { return values.begin(); }
        constexpr iterator end() { return values.end(); }
        constexpr const_iterator begin() const { return values.begin(); }
        constexpr const_iterator end() const { return values.end(); }

        bool operator==(Vec const&) const = default;

    private:
        storage values{};
    };

    template <std::size_t Dimension>
    constexpr Vec<float, Dimension> lerp(Vec<float, Dimension> const& a, Vec<float, Dimension> const& b, float const t) {
        auto ret = Vec<float, Dimension>{};
        Vec<float, Dimension>::for_each(ret, [&a, &b, t](std::size_t i, float& value) { value = std::lerp(a[i], b[i], t); });
        return ret;
    }

    template <typename Type, std::size_t Dimension>
    constexpr Type dot(Vec<Type, Dimension> const& a, Vec<Type, Dimension> const& b) {
        auto ret = Type{};
        Vec<Type, Dimension>::for_each(a, [&b, &ret](std::size_t i, Type const& value) { ret += value * b[i]; });
        return ret;
    }

    template <typename Type, std::size_t Dimension>
    constexpr Vec<Type, Dimension> sqr_mag(Vec<Type, Dimension> const& vec) {
        return dot(vec, vec);
    }

    template <typename Type, std::size_t Dimension>
    float magnitude(Vec<Type, Dimension> const& vec) {
        return std::sqrt(dot(vec, vec));
    }

    template <std::size_t Dimension>
    Vec<float, Dimension> normalize(Vec<float, Dimension> const& in, float const epsilon = 0.001f) {
        auto const mag = magnitude(in);
        if (std::abs(mag) < epsilon) { return {}; }
        return in / mag;
    }

    template <typename Type>
    constexpr auto zero_v = Type{};

    template <typename Type>
    constexpr auto one_v = static_cast<Type>(1);

    using fvec2 = Vec<float, 2>;
    using uvec2 = Vec<std::uint32_t, 2>;
    using ivec2 = Vec<std::int32_t, 2>;

    using fvec3 = Vec<float, 3>;
    using uvec3 = Vec<std::uint32_t, 3>;
    using ivec3 = Vec<std::int32_t, 3>;


}