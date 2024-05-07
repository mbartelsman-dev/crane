#pragma once
#define CRANE_HEADER_CONTENTS

#include "Vector_Impl.hpp"
#include "crane/geom/kernel_fwd.hpp"

namespace crane::geom
{

// ========================================================================== //
// VECTOR 3 ----------------------------------------------------------------- //
// ========================================================================== //

struct Vector_3: Vector_Impl<Vector_3, Fp_T, 3>
{
    static constexpr Uint_T Size = 3;

    using Type = Fp_T;
    using Impl = Vector_Impl;

    friend Vector_Impl;

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Vector_3() = default;

    explicit
    Vector_3(Type v);

    Vector_3(Type x, Type y, Type z);

    explicit
    Vector_3(const Direction_3 & d);

    explicit
    Vector_3(const Point_3 & p);

    explicit
    Vector_3(std::array<Type, Size> data);

    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    static Vector_3 zero();
    static Vector_3 one();
    static Vector_3 unit_x();
    static Vector_3 unit_y();
    static Vector_3 unit_z();


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Type x() const { return (*this)[0]; }
    [[nodiscard]] Type y() const { return (*this)[1]; }
    [[nodiscard]] Type z() const { return (*this)[2]; }


    // ---------------------------------------------------------------------- //
    // PROPERTIES                                                             //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T length() const;
    [[nodiscard]] Fp_T length_sq() const;
    [[nodiscard]] Fp_T length_rectilinear() const;
    [[nodiscard]] Direction_3 direction() const;
};

inline namespace vector_3
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    //
    // Scalars
    // ------------------------------------------------------------------- //

    Fp_T distance(const Vector_3 & start, const Vector_3 & end);
    Fp_T distance_sq(const Vector_3 & start, const Vector_3 & end);
    Fp_T distance_rectilinear(const Vector_3 & start, const Vector_3 & end);

    Fp_T dot(const Vector_3 & lhs, const Vector_3 & rhs);
    Vector_3 cross(const Vector_3 & lhs, const Vector_3 & rhs);

    //
    // Rotations
    // ------------------------------------------------------------------- //

    Angle angle(const Vector_3 & start, const Vector_3 & end);
    Vector_3 rotate(const Vector_3 & vec, const Euler & euler);
    Vector_3 rotate(const Vector_3 & vec, const Vector_3 & axis, const Angle & angle);
    Vector_3 rotate(const Vector_3 & vec, const Quaternion & quaternion);

    //
    // Modified vectors
    // ------------------------------------------------------------------- //

    Vector_3 normalize(const Vector_3 & vec);
    std::tuple<Vector_3, Vector_3> ortho_normalize(const Vector_3 & a, const Vector_3 & b);
    Vector_3 perp(const Vector_3 & vec);
    Vector_3 project(const Vector_3 & vec, const Vector_3 & target);
    Vector_3 reject(const Vector_3 & vec, const Vector_3 & target);
    Vector_3 reflect(const Vector_3 & vec, const Vector_3 & normal);
    // Vector_3 refract(const Vector_3 & vec, const Vector_3 & normal, Fp_T refractivity);
    Vector_3 mirror(const Vector_3 & vec, const Vector_3 & normal);

    //
    // Interpolation
    // ------------------------------------------------------------------- //

    Vector_3 lerp(const Vector_3 & start, const Vector_3 & end, Fp_T t);
    Vector_3 fast_slerp(const Vector_3 & start, const Vector_3 & end, Fp_T t);
    Vector_3 slerp(const Vector_3 & start, const Vector_3 & end, Fp_T t);

    //
    // Limits
    // ------------------------------------------------------------------- //

    Vector_3 min(const Vector_3 & lhs, const Vector_3 & rhs);
    Vector_3 max(const Vector_3 & lhs, const Vector_3 & rhs);
    Vector_3 clamp(const Vector_3 & vec, const Vector_3 & min, const Vector_3 & max);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    //
    // Arithmetic
    // ------------------------------------------------------------------- //

    Vector_3 operator-(const Vector_3 & vector);
    Vector_3 operator+(const Vector_3 & lhs, const Vector_3 & rhs);
    Vector_3 operator-(const Vector_3 & lhs, const Vector_3 & rhs);
    Vector_3 operator*(const Vector_3 & lhs, const Vector_3 & rhs);
    Vector_3 operator/(const Vector_3 & lhs, const Vector_3 & rhs);

    Vector_3 operator*(Fp_T scalar, const Vector_3 & vector);
    Vector_3 operator*(const Vector_3 & vector, Fp_T scalar);
    Vector_3 operator/(Fp_T scalar, const Vector_3 & vector);
    Vector_3 operator/(const Vector_3 & vector, Fp_T scalar);

    //
    // Arithmetic asignment
    // ------------------------------------------------------------------- //

    Vector_3 & operator+=(Vector_3 & target, const Vector_3 & operand);
    Vector_3 & operator-=(Vector_3 & target, const Vector_3 & operand);
    Vector_3 & operator*=(Vector_3 & target, const Vector_3 & operand);
    Vector_3 & operator/=(Vector_3 & target, const Vector_3 & operand);

    Vector_3 & operator*=(Vector_3 & target, Fp_T operand);
    Vector_3 & operator/=(Vector_3 & target, Fp_T operand);

    //
    // Comparison operators
    // ------------------------------------------------------------------- //

    bool almost_equal(const Vector_3 & lhs, const Vector_3 & rhs, Fp_T epsilon = numbers::eps<Fp_T>);
    bool operator==(const Vector_3 & lhs, const Vector_3 & rhs);
}

} // crane::geom

#undef CRANE_HEADER_CONTENTS
