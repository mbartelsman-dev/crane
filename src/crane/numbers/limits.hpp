#pragma once
#define CRANE_HEADER_CONTENTS

#include <limits>

#include <crane.hpp>
#include <crane/meta/concepts.hpp>

namespace crane::numbers
{
    /*-----------------------------------------------------------------------*
     | COMMON
     *-----------------------------------------------------------------------*/

    /* DEFINITIONS ----------------------------------------------------------*/

    /// Returns the least element in the set of values for the type.
    /// This may be 0 for unsigned integers, a large negative number
    /// for signed integers, or negative infinity for floating point numbers.
    template <meta::INumeric TNumber>
    constexpr TNumber least;

    /// Returns the greatest element in the set of values for the type.
    /// This may be a large finite number for integers or infinity for
    /// floating point numbers.
    template <meta::INumeric TNumber>
    constexpr TNumber greatest;

    /// Returns the zero element (the additive identity) of the type
    template <meta::INumeric TNumber>
    constexpr TNumber zero = static_cast<TNumber>(0);

    /// Returns the one element (the multiplicative identity) of the type
    template <meta::INumeric TNumber>
    constexpr TNumber one = static_cast<TNumber>(1);


    /*-----------------------------------------------------------------------*
     | INTEGERS
     *-----------------------------------------------------------------------*/

    /* UNSIGNED INTEGERS ----------------------------------------------------*/

    template <> constexpr Uint_8 least<Uint_8> = 0;
    template <> constexpr Uint_8 greatest<Uint_8> = UINT8_MAX;

    template <> constexpr Uint_16 least<Uint_16> = 0;
    template <> constexpr Uint_16 greatest<Uint_16> = UINT16_MAX;

    template <> constexpr Uint_32 least<Uint_32> = 0;
    template <> constexpr Uint_32 greatest<Uint_32> = UINT32_MAX;

    template <> constexpr Uint_64 least<Uint_64> = 0;
    template <> constexpr Uint_64 greatest<Uint_64> = UINT64_MAX;


    /* SIGNED INTEGERS ------------------------------------------------------*/

    template <> constexpr Int_8 least<Int_8> = INT8_MIN;
    template <> constexpr Int_8 greatest<Int_8> = INT8_MAX;

    template <> constexpr Int_16 least<Int_16> = INT16_MIN;
    template <> constexpr Int_16 greatest<Int_16> = INT16_MAX;

    template <> constexpr Int_32 least<Int_32> = INT32_MIN;
    template <> constexpr Int_32 greatest<Int_32> = INT32_MAX;

    template <> constexpr Int_64 least<Int_64> = INT64_MIN;
    template <> constexpr Int_64 greatest<Int_64> = INT64_MAX;


    /*-----------------------------------------------------------------------*
     | FLOATING POINT
     *-----------------------------------------------------------------------*/

    /* DEFINITIONS ----------------------------------------------------------*/

    /// Returns the positive infinity of the type.
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber inf;

    /// Returns the smallest number that can be added to 1.0 to produce
    /// a result greater than 1.0.
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber eps;

    /// Returns a quite NaN value for the type
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber nan;

    /// Returns a signalling NaN value for the type
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber signaling_nan;

    /// Returns the least normal, finite number representable by the type
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber least_normal;

    /// Returns the greatest normal, finite number representable by the type
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber greatest_normal;

    /// Returns the smallest normal value greater than zero representable by the type
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber least_positive;

    /// Returns the smallest non-normal value representable by the type
    template <meta::IFloatingPoint TNumber>
    constexpr TNumber least_positive_denormal;


    /* FLOATING POINT -------------------------------------------------------*/

    template <> constexpr Fp_32 least<Fp_32> = -std::numeric_limits<Fp_32>::infinity();
    template <> constexpr Fp_32 greatest<Fp_32> = std::numeric_limits<Fp_32>::infinity();
    template <> constexpr Fp_32 least_normal<Fp_32> = std::numeric_limits<Fp_32>::lowest();
    template <> constexpr Fp_32 greatest_normal<Fp_32> = std::numeric_limits<Fp_32>::max();
    template <> constexpr Fp_32 least_positive<Fp_32> = std::numeric_limits<Fp_32>::min();
    template <> constexpr Fp_32 least_positive_denormal<Fp_32> = std::numeric_limits<Fp_32>::denorm_min();
    template <> constexpr Fp_32 inf<Fp_32> = std::numeric_limits<Fp_32>::infinity();
    template <> constexpr Fp_32 eps<Fp_32> = std::numeric_limits<Fp_32>::epsilon();
    template <> constexpr Fp_32 nan<Fp_32> = std::numeric_limits<Fp_32>::quiet_NaN();
    template <> constexpr Fp_32 signaling_nan<Fp_32> = std::numeric_limits<Fp_32>::signaling_NaN();

    template <> constexpr Fp_64 least<Fp_64> = -std::numeric_limits<Fp_64>::infinity();
    template <> constexpr Fp_64 greatest<Fp_64> = std::numeric_limits<Fp_64>::infinity();
    template <> constexpr Fp_64 least_normal<Fp_64> = std::numeric_limits<Fp_64>::lowest();
    template <> constexpr Fp_64 greatest_normal<Fp_64> = std::numeric_limits<Fp_64>::max();
    template <> constexpr Fp_64 least_positive<Fp_64> = std::numeric_limits<Fp_64>::min();
    template <> constexpr Fp_64 least_positive_denormal<Fp_64> = std::numeric_limits<Fp_64>::denorm_min();
    template <> constexpr Fp_64 inf<Fp_64> = std::numeric_limits<Fp_64>::infinity();
    template <> constexpr Fp_64 eps<Fp_64> = std::numeric_limits<Fp_64>::epsilon();
    template <> constexpr Fp_64 nan<Fp_64> = std::numeric_limits<Fp_64>::quiet_NaN();
    template <> constexpr Fp_64 signaling_nan<Fp_64> = std::numeric_limits<Fp_64>::signaling_NaN();

    template <> constexpr Fp_Ext least<Fp_Ext> = -std::numeric_limits<Fp_Ext>::infinity();
    template <> constexpr Fp_Ext greatest<Fp_Ext> = std::numeric_limits<Fp_Ext>::infinity();
    template <> constexpr Fp_Ext least_normal<Fp_Ext> = std::numeric_limits<Fp_Ext>::lowest();
    template <> constexpr Fp_Ext greatest_normal<Fp_Ext> = std::numeric_limits<Fp_Ext>::max();
    template <> constexpr Fp_Ext least_positive<Fp_Ext> = std::numeric_limits<Fp_Ext>::min();
    template <> constexpr Fp_Ext least_positive_denormal<Fp_Ext> = std::numeric_limits<Fp_Ext>::denorm_min();
    template <> constexpr Fp_Ext inf<Fp_Ext> = std::numeric_limits<Fp_Ext>::infinity();
    template <> constexpr Fp_Ext eps<Fp_Ext> = std::numeric_limits<Fp_Ext>::epsilon();
    template <> constexpr Fp_Ext nan<Fp_Ext> = std::numeric_limits<Fp_Ext>::quiet_NaN();
    template <> constexpr Fp_Ext signaling_nan<Fp_Ext> = std::numeric_limits<Fp_Ext>::signaling_NaN();
}

#undef CRANE_HEADER_CONTENTS