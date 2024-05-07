#pragma once
#define CRANE_HEADER_CONTENTS

#include "Vector_Impl.hpp"
#include <crane/geom/kernel_fwd.hpp>

namespace crane::geom
{

// ========================================================================== //
// VECTOR 2 ----------------------------------------------------------------- //
// ========================================================================== //

struct Vector_2: Vector_Impl<Vector_2, Fp_T, 2>
{
    static constexpr Uint_T Size = 2;

    using Type = Fp_T;
    using Impl = Vector_Impl;

    friend Vector_Impl;

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Vector_2() = default;

    explicit
    Vector_2(Type v);

    Vector_2(Type x, Type y);

    explicit
    Vector_2(const Direction_2 & d);

    explicit
    Vector_2(const Point_2 & p);

    explicit
    Vector_2(std::array<Type, Size> data);


    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    static Vector_2 zero();
    static Vector_2 one();
    static Vector_2 unit_x();
    static Vector_2 unit_y();


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Type x() const { return (*this)[0]; }
    [[nodiscard]] Type y() const { return (*this)[1]; }


    // ---------------------------------------------------------------------- //
    // PROPERTIES                                                             //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T length() const;
    [[nodiscard]] Fp_T length_sq() const;
    [[nodiscard]] Fp_T length_rectilinear() const;
    [[nodiscard]] Direction_2 direction() const;
};

inline namespace vector_2
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    //
    // Scalars
    // ------------------------------------------------------------------- //

    Fp_T distance(const Vector_2 & a, const Vector_2 & b);
    Fp_T distance_sq(const Vector_2 & a, const Vector_2 & b);
    Fp_T distance_rectilinear(const Vector_2 & a, const Vector_2 & b);

    Fp_T dot(const Vector_2 & a, const Vector_2 & b);
    Fp_T det(const Vector_2 & a, const Vector_2 & b);

    //
    // Rotations
    // ------------------------------------------------------------------- //

    Angle angle(const Vector_2 & a, const Vector_2 & b);
    Vector_2 rotate(const Vector_2 & vec, const Angle & a);

    //
    // Modified vectors
    // ------------------------------------------------------------------- //

    Vector_2 normalize(const Vector_2 & vec);
    Vector_2 perp(const Vector_2 & vec);
    Vector_2 project(const Vector_2 & vec, const Vector_2 & target);
    Vector_2 reject(const Vector_2 & vec, const Vector_2 & target);
    Vector_2 reflect(const Vector_2 & vec, const Vector_2 & normal);
    Vector_2 refract(const Vector_2 & vec, const Vector_2 & normal, Fp_T refractivity);
    Vector_2 mirror(const Vector_2 & vec, const Vector_2 & normal);

    //
    // Interpolation
    // ------------------------------------------------------------------- //

    Vector_2 lerp(const Vector_2 & start, const Vector_2 & end, Fp_T t);
    Vector_2 fast_slerp(const Vector_2 & start, const Vector_2 & end, Fp_T t);
    Vector_2 slerp(const Vector_2 & start, const Vector_2 & end, Fp_T t);

    //
    // Limits
    // ------------------------------------------------------------------- //

    Vector_2 min(const Vector_2 & lhs, const Vector_2 & rhs);
    Vector_2 max(const Vector_2 & lhs, const Vector_2 & rhs);
    Vector_2 clamp(const Vector_2 & vec, const Vector_2 & min, const Vector_2 & max);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    //
    // Arithmetic
    // ------------------------------------------------------------------- //

    Vector_2 operator-(const Vector_2 & vector);
    Vector_2 operator+(const Vector_2 & lhs, const Vector_2 & rhs);
    Vector_2 operator-(const Vector_2 & lhs, const Vector_2 & rhs);
    Vector_2 operator*(const Vector_2 & lhs, const Vector_2 & rhs);
    Vector_2 operator/(const Vector_2 & lhs, const Vector_2 & rhs);

    Vector_2 operator*(Fp_T scalar, const Vector_2 & vector);
    Vector_2 operator*(const Vector_2 & vector, Fp_T scalar);
    Vector_2 operator/(Fp_T scalar, const Vector_2 & vector);
    Vector_2 operator/(const Vector_2 & vector, Fp_T scalar);

    //
    // Arithmetic asignment
    // ------------------------------------------------------------------- //

    Vector_2 & operator+=(Vector_2 & target, const Vector_2 & operand);
    Vector_2 & operator-=(Vector_2 & target, const Vector_2 & operand);
    Vector_2 & operator*=(Vector_2 & target, const Vector_2 & operand);
    Vector_2 & operator/=(Vector_2 & target, const Vector_2 & operand);

    Vector_2 & operator*=(Vector_2 & target, Fp_T operand);
    Vector_2 & operator/=(Vector_2 & target, Fp_T operand);

    //
    // Comparison operators
    // ------------------------------------------------------------------- //

    bool almost_equal(const Vector_2 & lhs, const Vector_2 & rhs, Fp_T epsilon = numbers::eps<Fp_T>);
    bool operator==(const Vector_2 & lhs, const Vector_2 & rhs);
}

} // crane::geom

#undef CRANE_HEADER_CONTENTS
