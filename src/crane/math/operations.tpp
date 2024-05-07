
#pragma once
#define CRANE_HEADER_CONTENTS

#include <cmath>

#include "operations.hpp"

#include <crane.hpp>
#include <crane/numbers/limits.hpp>

namespace crane::math
{
template <meta::INumeric TNum>
TNum lerp(TNum start, TNum end, Matching_Float<TNum> t)
{
    return start + (end - start) * t;
}

template <meta::IFloatingPoint TNum>
bool almost_equal(TNum a, TNum b, TNum epsilon)
{
    // Shortcuts
    if (a == b)
        return true;

    if (std::isnan(a) || std::isnan(b))
        return false;

    TNum abs_a = std::abs(a);
    TNum abs_b = std::abs(b);
    TNum diff = std::abs(a - b);

    // Use absolute error near zero
    if (a == 0 || b == 0 || abs_a + abs_b < numbers::least_normal<TNum>)
        return diff < epsilon * numbers::least_normal<TNum>;

    // Else, use relative error
    return diff < epsilon * std::min(std::max(abs_a, abs_b), numbers::greatest_normal<TNum>);
}


template <meta::IFloatingPoint TNum>
TNum
mod(TNum a, TNum m)
{
    if (std::isinf(a) || std::isnan(a))
        return numbers::nan<TNum>;

    if (m == 0 || std::isnan(m))
        return numbers::nan<TNum>;

    return a - std::trunc(a / m) * m;
}
}

#undef CRANE_HEADER_CONTENTS