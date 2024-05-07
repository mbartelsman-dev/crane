#pragma once
#define CRANE_HEADER_CONTENTS

#include "Vector_Impl.hpp"
#include "crane/geom/kernel_fwd.hpp"

namespace crane::geom
{

// ========================================================================== //
// DIRECTION 2 -------------------------------------------------------------- //
// ========================================================================== //

struct Direction_2 : Vector_Impl<Direction_2, Fp_T, 2>
{
    static constexpr Uint_T Size = 2;

    using Type = Fp_T;
    using Impl = Vector_Impl;

    friend Vector_Impl;

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Direction_2() = default;

    Direction_2(const Fp_T dx, const Fp_T dy):
        Vector_Impl {{ dx, dy }} {}


    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    static Direction_2 x_axis();
    static Direction_2 y_axis();


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T dx() const { return (*this)[0]; }
    [[nodiscard]] Fp_T dy() const { return (*this)[1]; }
};

inline namespace direction_2
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    Direction_2 rotate(const Direction_2 & d, const Angle & ang);
    Direction_2 lerp(const Direction_2 & start, const Direction_2 & end, Fp_T t);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    bool operator==(const Direction_2 & lhs, const Direction_2 & rhs);
    bool almost_equal(const Direction_2 & lhs, const Direction_2 & rhs, Fp_T epsilon);

    Direction_2 operator-(const Direction_2 & dir);

    Direction_2 operator+(const Direction_2 & dir, const Angle & ang);
    Direction_2 operator-(const Direction_2 & dir, const Angle & ang);
    Angle operator-(const Direction_2 & lhs, const Direction_2 & rhs);

    Direction_2 & operator+=(Direction_2 & target, const Angle & operand);
    Direction_2 & operator-=(Direction_2 & target, const Angle & operand);

    Vector_2 operator*(const Direction_2 & dir, Fp_T mag);
    Vector_2 operator*(Fp_T mag, const Direction_2 & dir);
}

} // crane::geom

#undef CRANE_HEADER_CONTENTS
