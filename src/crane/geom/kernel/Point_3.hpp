
#pragma once
#define CRANE_HEADER_CONTENTS

#include "Vector_Impl.hpp"
#include "crane/geom/kernel_fwd.hpp"

namespace crane::geom
{
// ========================================================================== //
// POINT 2 ------------------------------------------------------------------ //
// ========================================================================== //

struct Point_3 : Vector_Impl<Point_3, Fp_T, 3>
{
    static constexpr Uint_T Size = 3;

    using Type = Fp_T;
    using Impl = Vector_Impl;

    friend Vector_Impl;

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Point_3() = default;

    Point_3(const Type x, const Type y, const Type z):
        Vector_Impl {{ x, y, z }} { }


    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    static Point_3 origin();


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T x() const { return (*this)[0]; }
    [[nodiscard]] Fp_T y() const { return (*this)[1]; }
    [[nodiscard]] Fp_T z() const { return (*this)[2]; }
};

inline namespace point_3
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    Point_3 lerp(const Point_3 & a, const Point_3 & b, Fp_T t);

    Point_3 min(const Point_3 & a, const Point_3 & b);
    Point_3 max(const Point_3 & a, const Point_3 & b);
    Point_3 clamp(const Point_3 & p, const Point_3 & min, const Point_3 & max);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    bool operator==(const Point_3 & a, const Point_3 & b);
    bool almost_equal(const Point_3 & a, const Point_3 & b, Fp_T epsilon);

    Point_3 operator+(const Point_3 & a, const Vector_3 & b);
    Point_3 operator-(const Point_3 & a, const Vector_3 & b);
    Vector_3 operator-(const Point_3 & a, const Point_3 & b);

    Point_3 & operator+=(Point_3 & target, const Vector_3 & operand);
    Point_3 & operator-=(Point_3 & target, const Vector_3 & operand);
}
}


#undef CRANE_HEADER_CONTENTS