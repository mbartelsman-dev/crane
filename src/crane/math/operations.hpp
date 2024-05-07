
#pragma once
#define CRANE_HEADER_CONTENTS

#include <crane.hpp>
#include <crane/numbers/limits.hpp>
#include <crane/meta/concepts.hpp>

namespace crane::math
{
template <meta::INumeric TNum>
TNum lerp(TNum start, TNum end, Matching_Float<TNum> t);

template <meta::IFloatingPoint TNum>
bool almost_equal(TNum a, TNum b, TNum epsilon = numbers::eps<TNum>);

template <meta::IFloatingPoint TNum>
TNum mod(TNum a, TNum m);
}

#include "operations.tpp"

#undef CRANE_HEADER_CONTENTS