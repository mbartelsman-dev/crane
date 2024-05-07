
#pragma once
#define CRANE_HEADER_CONTENTS
#include <array>
#include <crane.hpp>
#include <crane/meta/concepts.hpp>
#include <crane/numbers/limits.hpp>

namespace crane::geom
{
    template <typename TValue, Uint_8 VSize>
    struct Vec
    {
        using Value = TValue;
        static constexpr Uint_8 Size = VSize;

        std::array<TValue, VSize> _data;

        Vec() = default;
        explicit Vec(TValue value);
        explicit Vec(std::array<TValue, VSize> data);

        template <Uint_8 Index>
            requires Index < VSize
        Value at();

        template <Uint_8 Index>
            requires Index < VSize
        const Value & at() const;

        Value operator[](Uint_8 index);
        const Value & operator[](Uint_8 index) const;

        TValue sum() const;
        TValue length() const;
        TValue length_sq() const;
        TValue inner_product(const Vec & other) const;

        Vec & operator+=(const Vec & other);
        Vec & operator-=(const Vec & other);
        Vec & operator*=(const Vec & other);
        Vec & operator/=(const Vec & other);

        Vec operator-();
        Vec operator+(const Vec & other);
        Vec operator-(const Vec & other);
        Vec operator*(const Vec & other);
        Vec operator/(const Vec & other);

        bool operator==(const Vec & other) const;
    };

    template <meta::IFloatingPoint TValue, Uint_8 VSize>
    bool almost_equal(
        const Vec<TValue, VSize> & lhs,
        const Vec<TValue, VSize> & rhs,
        TValue epsilon = numbers::eps<TValue>);
}

#include "Vec.tpp"

#undef CRANE_HEADER_CONTENTS