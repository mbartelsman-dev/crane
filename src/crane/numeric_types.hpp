#pragma once
#define CRANE_HEADER_CONTENTS

#include <cstdint>
#include <type_traits>

#include <crane/meta/macros.hpp>
#include <crane/meta/tmp.hpp>

/*---------------------------------------------------------------------------*
 | MACROS
 *---------------------------------------------------------------------------*/

#ifndef CRANE_CHAR
    #define CRANE_CHAR char
#endif

#ifndef CRANE_INT_KIND
    #define CRANE_INT_KIND fast
#endif

#ifndef CRANE_INT_SIZE
    #define CRANE_INT_SIZE 32
#endif

#if (CRANE_INT_SIZE != 16) && (CRANE_INT_SIZE != 32) && (CRANE_INT_SIZE != 64)
    #error "CRANE_INT_SIZE may only be one of: 16, 32, or 64"
#endif

#ifndef CRANE_FLOAT_SIZE
    #define CRANE_FLOAT_SIZE 32
#endif

#if (CRANE_FLOAT_SIZE != 32) && (CRANE_FLOAT_SIZE != 64)
    #error "CRANE_FLOAT_SIZE may only be one of: 32, 64"
#endif

#define CRANE_SIGNED_INT        CRANE_CONCAT(int_, CRANE_INT_KIND, CRANE_INT_SIZE, _t)
#define CRANE_UNSIGNED_INT      CRANE_CONCAT(uint_, CRANE_INT_KIND, CRANE_INT_SIZE, _t)
#define CRANE_FLOATING_POINT    CRANE_CONCAT(Fp_, CRANE_FLOAT_SIZE)

namespace crane
{
    // NOLINTBEGIN(*-identifier-naming)

    /*-----------------------------------------------------------------------*
     | ALIASES
     *-----------------------------------------------------------------------*/

    /* CHARACTER TYPES ------------------------------------------------------*/

    /// Platform character type.
    using Char = char;

    /// Type for UTF-8 representation.
    using Utf_8 = char8_t;

    /// Type for UTF-16 representation.
    using Utf_16 = char16_t;

    /// Type for UTF-32 representation.
    using Utf_32 = char32_t;

    /// Designated basic character type, defaults to `char`.
    using Char_T = CRANE_CHAR;


    /* UNSIGNED INTEGERS ----------------------------------------------------*/

    /// Unsigned 8 bit integer.
    using Uint_8 = uint8_t;

    /// Unsigned 16 bit integer.
    using Uint_16 = uint16_t;

    /// Unsigned 32 bit integer.
    using Uint_32 = uint32_t;

    /// Unsigned 64 bit integer.
    using Uint_64 = uint64_t;

    /// Unsigned integer with the largest size available for the implementation.
    using Uint_Max = uintmax_t;

    /// Unsigned integer type capable of holding a pointer to void.
    using Uint_Ptr = uintptr_t;

    /// Designated basic unsigned int type. Defaults to `uint_fast32_t`.
    using Uint_T = CRANE_UNSIGNED_INT;


    /* SIGNED INTEGERS ------------------------------------------------------*/

    /// Signed 8 bit integer.
    using Int_8 = int8_t;

    /// Signed 16 bit integer.
    using Int_16 = int16_t;

    /// Signed 32 bit integer.
    using Int_32 = int32_t;

    /// Signed 64 bit integer.
    using Int_64 = int64_t;

    /// Signed integer with the largest size available for the implementation.
    using Int_Max = intmax_t;

    /// Signed integer type capable of holding a pointer to void.
    using Int_Ptr = intptr_t;

    /// Designated basic signed int type. Defaults to `int_fast32_t`.
    using Int_T = CRANE_SIGNED_INT;


    /* FLOATING POINT -------------------------------------------------------*/

    /// 32-bit floating point number.
    using Fp_32 = float;

    /// 64-bit floating point number.
    using Fp_64 = double;

    /// Extended precision floating point number. Size is implementation-defined.
    using Fp_Ext = long double;

    /// Designated basic floating point type. Defaults to `float`.
    using Fp_T = CRANE_FLOATING_POINT;

    /*-----------------------------------------------------------------------*
     | INFERRED TYPES
    *-----------------------------------------------------------------------*/

    template <typename T>
    using Matching_Float = typename meta::Switch<
        meta::Case<std::is_floating_point_v<T>, T>,
        meta::Case<sizeof(T) <= sizeof(Fp_32), Fp_32>,
        meta::Case<sizeof(T) <= sizeof(Fp_64), Fp_64>,
        meta::Default<Fp_Ext>>::Type;

    // NOLINTEND(*-identifier-naming)
}


/*---------------------------------------------------------------------------*
 | MACRO CLEANUP
 *---------------------------------------------------------------------------*/

#undef CRANE_CHAR
#undef CRANE_INT_KIND
#undef CRANE_INT_SIZE
#undef CRANE_FLOAT_SIZE
#undef CRANE_SIGNED_INT
#undef CRANE_UNSIGNED_INT
#undef CRANE_FLOATING_POINT

#undef CRANE_HEADER_CONTENTS
