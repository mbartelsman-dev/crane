#pragma once
#define CRANE_HEADER_CONTENTS

#include <compare>

#include "crane.hpp"

namespace crane::geom
{
// ========================================================================== //
// ANGLE --------------------------------------------------------------------- //
// ========================================================================== //

struct Angle
{
    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //
    private:
    explicit Angle(Fp_T data);

    public:
    Angle() = default;


    // ---------------------------------------------------------------------- //
    // DATA MEMBERS                                                           //
    // ---------------------------------------------------------------------- //

    private:
    Fp_T data_ { 0 };


    // ---------------------------------------------------------------------- //
    // FACTORY METHODS                                                        //
    // ---------------------------------------------------------------------- //

    public:

    /// New angle from degrees
    [[nodiscard]] static Angle deg(Fp_T value);

    /// New angle from radians
    [[nodiscard]] static Angle rad(Fp_T value);

    [[nodiscard]] static Angle quarter_turn();

    [[nodiscard]] static Angle half_turn();

    [[nodiscard]] static Angle full_turn();

    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    /// Get angle as degrees
    [[nodiscard]] Fp_T deg() const;

    /// Get angle as radians
    [[nodiscard]] Fp_T rad() const;
};

inline namespace angle
{
    // ---------------------------------------------------------------------- //
    // FREE FUNCTIONS                                                         //
    // ---------------------------------------------------------------------- //

    /// Normalizes angle to always be in the range [0,360)/[0,2*pi)
    Angle normalize(const Angle & a);

    /// Normalizes angle to always be in the range [-180,180)/[-pi,pi)
    Angle normalize_signed(const Angle & a);

    /// Cosine of the angle
    Fp_T cos(const Angle & a);

    /// Sine of the angle
    Fp_T sin(const Angle & a);

    /// Tangent of the angle
    Fp_T tan(const Angle & a);

    /// Arc-cosine
    Angle acos(Fp_T value);

    /// Arc-sine
    Angle asin(Fp_T value);

    /// Arc-tangent
    Angle atan(Fp_T value);

    /// Arc-tangent 2
    Angle atan2(Fp_T num, Fp_T den);

    /// Approximate floating point comparison
    bool almost_equal(const Angle & a, const Angle & b, Fp_T epsilon);


    // ---------------------------------------------------------------------- //
    // OPERATORS                                                              //
    // ---------------------------------------------------------------------- //

    /// Angle in degrees literal
    inline Angle operator ""_deg(long double value);

    /// Angle in radians literal
    inline Angle operator ""_rad(long double value);

    /// Exact comparison
    bool operator==(const Angle & a, const Angle & b);
    std::partial_ordering operator<=>(const Angle & a, const Angle & b);

    Angle operator-(const Angle & a);
    Angle operator+(const Angle & a, const Angle & b);
    Angle operator-(const Angle & a, const Angle & b);

    Angle & operator+=(Angle & t, const Angle & o);
    Angle & operator-=(Angle & t, const Angle & o);

    Angle operator*(Fp_T s, const Angle & a);
    Angle operator/(Fp_T s, const Angle & a);
    Angle operator*(const Angle & a, Fp_T s);

    Angle & operator*=(Angle & a, Fp_T s);
}
}

#undef CRANE_HEADER_CONTENTS
