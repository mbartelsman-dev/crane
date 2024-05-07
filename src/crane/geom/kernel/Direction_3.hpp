#pragma once
#define CRANE_HEADER_CONTENTS

#include "Vector_Impl.hpp"
#include "crane/geom/kernel_fwd.hpp"

namespace crane::geom
{

// ========================================================================== //
// DIRECTION 2 -------------------------------------------------------------- //
// ========================================================================== //

struct Direction_3 : Vector_Impl<Direction_3, Fp_T, 3>
{
    static constexpr Uint_T Size = 3;

    using Type = Fp_T;
    using Impl = Vector_Impl;

    friend Vector_Impl;

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Direction_3() = default;

    Direction_3(const Fp_T dx, const Fp_T dy, const Fp_T dz):
        Vector_Impl {{ dx, dy, dz }} {}

    explicit
    Direction_3(const std::array<Type, Size> data) :
        Vector_Impl { data } {}


    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    static Direction_3 x_axis();
    static Direction_3 y_axis();
    static Direction_3 z_axis();


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T dx() const { return (*this)[0]; }
    [[nodiscard]] Fp_T dy() const { return (*this)[1]; }
    [[nodiscard]] Fp_T dz() const { return (*this)[2]; }
};

inline namespace direction_3
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    Direction_3 rotate(const Direction_3 & dir, const Direction_3 & axis, const Angle & ang);
    Vector_3 axis(const Direction_3 & lhs, const Direction_3 & rhs);
    Angle angle(const Direction_3 & lhs, const Direction_3 & rhs);
    Direction_3 lerp(const Direction_3 & start, const Direction_3 & end, Fp_T t);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    bool operator==(const Direction_3 & a, const Direction_3 & b);
    bool almost_equal(const Direction_3 & a, const Direction_3 & b, Fp_T epsilon);

    Direction_3 operator-(const Direction_3 & d);

    Vector_3 operator*(const Direction_3 & d, Fp_T m);
    Vector_3 operator*(Fp_T m, const Direction_3 & d);
}

} // crane::geom

#undef CRANE_HEADER_CONTENTS
