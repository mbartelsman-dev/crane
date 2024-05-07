
#pragma once
#define CRANE_HEADER_CONTENTS

#include "Vector_Impl.hpp"
#include "crane/geom/kernel_fwd.hpp"

namespace crane::geom
{
// ========================================================================== //
// POINT 2 ------------------------------------------------------------------ //
// ========================================================================== //

struct Point_2 : Vector_Impl<Point_2, Fp_T, 2>
{
    static constexpr Uint_T Size = 2;

    using Type = Fp_T;
    using Impl = Vector_Impl;

    friend Vector_Impl;

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Point_2() = default;

    Point_2(const Type x, const Type y):
        Vector_Impl {{ x, y }} { }


    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    static Point_2 origin();


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T x() const { return (*this)[0]; }
    [[nodiscard]] Fp_T y() const { return (*this)[1]; }
};

inline namespace point_2
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    Point_2 lerp(const Point_2 & a, const Point_2 & b, Fp_T t);

    Point_2 min(const Point_2 & a, const Point_2 & b);
    Point_2 max(const Point_2 & a, const Point_2 & b);
    Point_2 clamp(const Point_2 & p, const Point_2 & min, const Point_2 & max);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    bool operator==(const Point_2 & a, const Point_2 & b);
    bool almost_equal(const Point_2 & a, const Point_2 & b, Fp_T epsilon);

    Point_2 operator+(const Point_2 & a, const Vector_2 & b);
    Point_2 operator-(const Point_2 & a, const Vector_2 & b);
    Vector_2 operator-(const Point_2 & a, const Point_2 & b);

    Point_2 & operator+=(Point_2 & target, const Vector_2 & operand);
    Point_2 & operator-=(Point_2 & target, const Vector_2 & operand);
}
}


#undef CRANE_HEADER_CONTENTS