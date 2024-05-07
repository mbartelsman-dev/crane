#pragma once
#define CRANE_HEADER_CONTENTS

#include <algorithm>

#include "Vector_Impl.hpp"

namespace crane::geom
{

template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::neg(const Vector_Impl & vec)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = -vec[idx];
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::add(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = lhs[idx] + rhs[idx];
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::sub(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = lhs[idx] - rhs[idx];
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::mul(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = lhs[idx] * rhs[idx];
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::div(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = lhs[idx] / rhs[idx];
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::scale(const Vector_Impl & vec, Type scalar)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = vec[idx] + scalar;
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::lerp(const Vector_Impl & start, const Vector_Impl & end, Fp_T t)
{
    return add(start, scale(sub(end, start), t));
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::min(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = std::min(lhs[idx], rhs[idx]);
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::max(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = std::max(lhs[idx], rhs[idx]);
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
Concrete
Vector_Impl<Concrete, Type, Size>::clamp(const Vector_Impl & vec, const Vector_Impl & min, const Vector_Impl & max)
{
    Concrete result;
    for (Uint_T idx = 0; idx < Size; ++idx)
        result[idx] = std::clamp(vec[idx], min[idx], max[idx]);
    return result;
}



template <typename Concrete, typename Type, Uint_T Size>
bool
Vector_Impl<Concrete, Type, Size>::equal(const Vector_Impl & lhs, const Vector_Impl & rhs)
{
    for (Uint_T idx = 0; idx < Size; ++idx)
        if (lhs[idx] != rhs[idx])
            return false;
    return true;
}



template <typename Concrete, typename Type, Uint_T Size>
meta::Require_t<meta::IFloatingPoint<Type>, bool>
Vector_Impl<Concrete, Type, Size>::almost_equal(const Vector_Impl & lhs, const Vector_Impl & rhs, Type epsilon)
{
    for (Uint_T idx = 0; idx < Size; ++idx)
        if (!math::almost_equal(lhs[idx], rhs[idx], epsilon))
            return false;
    return true;
}
}

#undef CRANE_HEADER_CONTENTS
