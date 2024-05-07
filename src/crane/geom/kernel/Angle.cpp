#include "Angle.hpp"

#include <cmath>

#include <crane/math.hpp>
#include <crane/numbers/limits.hpp>
#include <crane/numbers/math.hpp>

namespace crane::geom
{
Angle::Angle(const Fp_T data):
    data_ { data } {}


Angle
Angle::deg(const Fp_T value) { return Angle { value * numbers::_180_pi<Fp_T> }; }


Angle
Angle::rad(const Fp_T value) { return Angle { value }; }


Angle
Angle::quarter_turn() { return Angle { numbers::pi_2<Fp_T> }; }


Angle
Angle::half_turn() { return Angle { numbers::pi<Fp_T> }; }


Angle
Angle::full_turn() { return Angle { numbers::tau<Fp_T> }; }


Fp_T
Angle::deg() const { return data_ * numbers::pi_180<Fp_T>; }


Fp_T
Angle::rad() const { return data_; }


Angle
angle::normalize(const Angle & a)
{
    return Angle::rad(math::mod(a.rad(), numbers::tau<Fp_T>));
}


Angle
angle::normalize_signed(const Angle & a)
{
    Fp_T n_rads = math::mod(a.rad(), numbers::tau<Fp_T>);

    if (n_rads > numbers::pi<Fp_T>)
        return Angle::rad(n_rads - numbers::pi<Fp_T>);
    return Angle::rad(n_rads);
}


Fp_T
angle::cos(const Angle & a)
{
    return std::cos(a.rad());
}


Fp_T
angle::sin(const Angle & a)
{
    return std::sin(a.rad());
}


Fp_T
angle::tan(const Angle & a)
{
    return std::tan(a.rad());
}


Angle
angle::acos(const Fp_T value)
{
    return Angle::rad(std::acos(value));
}


Angle
angle::asin(const Fp_T value)
{
    return Angle::rad(std::asin(value));
}


Angle
angle::atan(const Fp_T value)
{
    return Angle::rad(std::atan(value));
}


Angle
angle::atan2(const Fp_T num, const Fp_T den)
{
    return Angle::rad(std::atan2(num, den));
}


bool
angle::almost_equal(const Angle & a, const Angle & b, const Fp_T epsilon = numbers::eps<Fp_T>)
{
    return math::almost_equal(a.rad(), b.rad(), epsilon);
}


Angle
angle::operator ""_deg(const long double value) { return Angle::deg(static_cast<Fp_T>(value)); }


Angle
angle::operator ""_rad(const long double value) { return Angle::rad(static_cast<Fp_T>(value)); }


bool
angle::operator==(const Angle & a, const Angle & b)
{
    return a.rad() == b.rad();
}


std::partial_ordering
angle::operator<=>(const Angle & a, const Angle & b)
{
    return a.rad() <=> b.rad();
}


Angle
angle::operator-(const Angle & a)
{
    return Angle::rad(-a.rad());
}


Angle
angle::operator+(const Angle & a, const Angle & b)
{
    return Angle::rad(a.rad() + b.rad());
}


Angle
angle::operator-(const Angle & a, const Angle & b)
{
    return Angle::rad(a.rad() - b.rad());
}


Angle &
angle::operator+=(Angle & t, const Angle & o)
{
    t = t + o;
    return t;
}


Angle &
angle::operator-=(Angle & t, const Angle & o)
{
    t = t - o;
    return t;
}


Angle
angle::operator*(const Fp_T s, const Angle & a)
{
    return Angle::rad(s * a.rad());
}


Angle
angle::operator/(const Fp_T s, const Angle & a)
{
    return Angle::rad(s / a.rad());
}


Angle
angle::operator*(const Angle & a, const Fp_T s)
{
    return Angle::rad(a.rad() * s);
}


Angle &
angle::operator*=(Angle & a, const Fp_T s)
{
    a = a * s;
    return a;
}
}
