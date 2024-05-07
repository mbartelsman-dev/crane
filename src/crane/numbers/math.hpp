#pragma once
#define CRANE_HEADER_CONTENTS

#include <crane/meta/concepts.hpp>

namespace crane::numbers
{
    template <meta::IFloatingPoint TFloat>
    constexpr TFloat tau =     static_cast<TFloat>(6.28318530717958647692528676655L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat pi =      static_cast<TFloat>(3.14159265358979323846264338327L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat pi_2 =    static_cast<TFloat>(1.57079632679489661923132169163L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat pi_3 =    static_cast<TFloat>(1.04719755119659774615421446109L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat pi_4 =    static_cast<TFloat>(0.78539816339744830961566084581L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat pi_6 =    static_cast<TFloat>(0.52359877559829887307710723054L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat pi_180 =  static_cast<TFloat>(0.01745329251994329576923690768L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat _180_pi = static_cast<TFloat>(57.2957795130823208767981548141L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat e =       static_cast<TFloat>(2.71828182845904523536028747135L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat phi =     static_cast<TFloat>(1.61803398874989484820458683436L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat sqrt_2 =  static_cast<TFloat>(1.41421356237309504880168872420L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat sqrt_3 =  static_cast<TFloat>(1.73205080756887729352744634150L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat sqrt_5 =  static_cast<TFloat>(2.23606797749978969640917366873L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat sqrt2_2 = static_cast<TFloat>(0.70710678118654752440084436210L);

    template <meta::IFloatingPoint TFloat>
    constexpr TFloat sqrt3_2 = static_cast<TFloat>(0.86602540378443864676372317075L);
}

#undef CRANE_HEADER_CONTENTS
