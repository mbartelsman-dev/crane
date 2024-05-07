
#pragma once
#define CRANE_HEADER_CONTENTS
#include "Vec.hpp"
#include "../../math/operations.hpp"

namespace crane::geom
{
template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>::Vec(TValue value)
{
    for (int index = 0; index < VSize; ++index)
        operator[](index) = value;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>::Vec(std::array<TValue, VSize> data):
    _data { data } {}


template <typename TValue, Uint_8 VSize>
template <Uint_8 Index> requires Index < VSize
typename Vec<TValue, VSize>::Value
Vec<TValue, VSize>::at() { return _data[Index]; }


template <typename TValue, Uint_8 VSize>
template <Uint_8 Index> requires Index < VSize
const typename Vec<TValue, VSize>::Value &
Vec<TValue, VSize>::at() const { return _data[Index]; }


template <typename TValue, Uint_8 VSize>
typename Vec<TValue, VSize>::Value
Vec<TValue, VSize>::operator[](const Uint_8 index) { return _data[index]; }


template <typename TValue, Uint_8 VSize>
const typename Vec<TValue, VSize>::Value &
Vec<TValue, VSize>::operator[](const Uint_8 index) const { return _data[index]; }


template <typename TValue, Uint_8 VSize>
TValue
Vec<TValue, VSize>::sum() const
{
    TValue result = numbers::zero<TValue>;
    for (Uint_8 index = 0; index < Size; ++index)
        result += operator[](index);

    return result;
}


template <typename TValue, Uint_8 VSize>
TValue
Vec<TValue, VSize>::length() const
{
    return sqrt(length_sq());
}


template <typename TValue, Uint_8 VSize>
TValue
Vec<TValue, VSize>::length_sq() const
{
    TValue result = numbers::zero<TValue>;
    for (Uint_8 index = 0; index < Size; ++index)
        result += operator[](index) * operator[](index);

    return result;
}


template <typename TValue, Uint_8 VSize>
TValue
Vec<TValue, VSize>::inner_product(const Vec & other) const
{
    TValue result = numbers::zero<TValue>;
    for (Uint_8 index = 0; index < Size; ++index)
        result += operator[](index) * other[index];

    return result;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize> & Vec<TValue, VSize>::operator+=(const Vec & other)
{
    for (Uint_8 index = 0; index < Size; ++index)
        operator[](index) += other[index];

    return *this;
}

template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize> & Vec<TValue, VSize>::operator-=(const Vec & other)
{
    for (Uint_8 index = 0; index < Size; ++index)
        operator[](index) -= other[index];

    return *this;
}

template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize> & Vec<TValue, VSize>::operator*=(const Vec & other)
{
    for (Uint_8 index = 0; index < Size; ++index)
        operator[](index) *= other[index];

    return *this;
}

template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize> & Vec<TValue, VSize>::operator/=(const Vec & other)
{
    for (Uint_8 index = 0; index < Size; ++index)
        operator[](index) /= other[index];

    return *this;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>
Vec<TValue, VSize>::operator-()
{
    Vec result { *this };
    for (Uint_8 index = 0; index < Size; ++index)
        operator[](index) = -operator[](index);
    return result;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>
Vec<TValue, VSize>::operator+(const Vec & other)
{
    Vec result { *this };
    result += other;
    return result;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>
Vec<TValue, VSize>::operator-(const Vec & other)
{
    Vec result { *this };
    result -= other;
    return result;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>
Vec<TValue, VSize>::operator*(const Vec & other)
{
    Vec result { *this };
    result *= other;
    return result;
}


template <typename TValue, Uint_8 VSize>
Vec<TValue, VSize>
Vec<TValue, VSize>::operator/(const Vec & other)
{
    Vec result { *this };
    result /= other;
    return result;
}


template <typename TValue, Uint_8 VSize>
bool
Vec<TValue, VSize>::operator==(const Vec & other) const
{
    for (Uint_8 index = 0; index < Size; ++index)
        if (operator[](index) != other[index])
            return false;
    return true;
}


template <meta::IFloatingPoint TValue, Uint_8 VSize>
bool
almost_equal(
    const Vec<TValue, VSize> & lhs,
    const Vec<TValue, VSize> & rhs,
    TValue epsilon)
{
    for (Uint_8 index = 0; index < VSize; ++index)
        if (!math::almost_equal(lhs[index], rhs[index], epsilon))
            return false;
    return true;
}
}

#undef CRANE_HEADER_CONTENTS