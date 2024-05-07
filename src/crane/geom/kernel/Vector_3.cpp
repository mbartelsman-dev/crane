#include "Vector_3.hpp"

#include <algorithm>
#include <cmath>
#include <tuple>

#include "Direction_3.hpp"
#include "Point_3.hpp"
#include "Angle.hpp"

namespace crane::geom
{

Vector_3::Vector_3(const Type v):
    Vector_Impl {{ v, v, v }} { }


Vector_3::Vector_3(const Type x, const Type y, const Type z):
    Vector_Impl {{ x, y, z }} { }


Vector_3::Vector_3(const Direction_3 & d):
    Vector_Impl { d.data() } {}


Vector_3::Vector_3(const Point_3 & p):
    Vector_Impl { p.data() } {}


Vector_3::Vector_3(std::array<Type, Size> data):
    Vector_Impl { std::forward<std::array<Type, Size>>(data) } {}


Vector_3
Vector_3::zero() { return Vector_3 { 0.0f }; }


Vector_3
Vector_3::one() { return Vector_3 { 1.0f }; }


Vector_3
Vector_3::unit_x() { return Vector_3 { 1.0f, 0.0f, 0.0f }; }


Vector_3
Vector_3::unit_y() { return Vector_3 { 0.0f, 1.0f, 0.0f }; }


Vector_3
Vector_3::unit_z() { return Vector_3 { 0.0f, 0.0f, 1.0f }; }


Fp_T
Vector_3::length() const
{
    return std::sqrt(length_sq());
}


Fp_T
Vector_3::length_sq() const
{
    return x() * x() + y() * y() + z() * z();
}


Fp_T
Vector_3::length_rectilinear() const
{
    return x() + y() + z();
}


Direction_3
Vector_3::direction() const
{
    const Fp_T norm = length();
    return Direction_3 { x() / norm, y() / norm, z() / norm };
}


Fp_T
vector_3::distance(const Vector_3 & start, const Vector_3 & end)
{
    return (end - start).length();
}


Fp_T
vector_3::distance_sq(const Vector_3 & start, const Vector_3 & end)
{
    return (end - start).length_sq();
}


Fp_T
vector_3::distance_rectilinear(const Vector_3 & start, const Vector_3 & end)
{
    return (end - start).length_rectilinear();
}


Fp_T
vector_3::dot(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return lhs.x() * rhs.x() + lhs.y() * rhs.y() + lhs.z() * rhs.z();
}


Vector_3
vector_3::cross(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3 {
        lhs.y() * rhs.z() - lhs.z() * rhs.y(),
        lhs.z() * rhs.x() - lhs.x() * rhs.z(),
        lhs.x() * rhs.y() - lhs.y() * rhs.x()
    };
}


Angle
vector_3::angle(const Vector_3 & start, const Vector_3 & end) {}


Vector_3
vector_3::rotate(const Vector_3 & vec, const Euler & euler) {}


Vector_3
vector_3::rotate(const Vector_3 & vec, const Vector_3 & axis, const Angle & angle) {}


Vector_3
vector_3::rotate(const Vector_3 & vec, const Quaternion & quaternion) {}


Vector_3
vector_3::normalize(const Vector_3 & vec)
{
    return vec / vec.length();
}


std::tuple<Vector_3, Vector_3>
vector_3::ortho_normalize(const Vector_3 & a, const Vector_3 & b) {}


Vector_3
vector_3::perp(const Vector_3 & vec)
{
    return cross(vec, almost_equal(vec, Vector_3::unit_x(), 0.1) ? Vector_3::unit_y() : Vector_3::unit_x());
}


Vector_3
vector_3::project(const Vector_3 & vec, const Vector_3 & target)
{
    return dot(target, vec) / target.length_sq() * target;
}


Vector_3
vector_3::reject(const Vector_3 & vec, const Vector_3 & target)
{
    return vec - project(vec, target);
}


Vector_3
vector_3::reflect(const Vector_3 & vec, const Vector_3 & normal)
{
    return vec - 2 * project(vec, normal);
}


Vector_3
vector_3::mirror(const Vector_3 & vec, const Vector_3 & normal)
{
    return -reflect(vec, normal);
}


Vector_3
vector_3::lerp(const Vector_3 & start, const Vector_3 & end, const Fp_T t)
{
    return Vector_3::Impl::lerp(start, end, t);
}


Vector_3
vector_3::fast_slerp(const Vector_3 & start, const Vector_3 & end, const Fp_T t)
{
    return normalize(lerp(start, end, t)) * math::lerp(start.length(), end.length(), t);
}


Vector_3
vector_3::slerp(const Vector_3 & start, const Vector_3 & end, const Fp_T t)
{
    const Vector_3 axis = cross(start, end);
    const Angle rotation = angle(start, end);

    if (rotation <= Angle::half_turn())
        return rotate(start, axis, rotation * t) * math::lerp(start.length(), end.length(), t);

    return rotate(end, axis, (Angle::full_turn() - rotation) * (1.0f - t)) * math::lerp(start.length(), end.length(), t);
}


Vector_3
vector_3::min(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::min(lhs, rhs);
}


Vector_3
vector_3::max(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::max(lhs, rhs);
}


Vector_3
vector_3::clamp(const Vector_3 & vec, const Vector_3 & min, const Vector_3 & max)
{
    return Vector_3::Impl::clamp(vec, min, max);
}


Vector_3
vector_3::operator-(const Vector_3 & vector)
{
    return Vector_3::Impl::neg(vector);
}


Vector_3
vector_3::operator+(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::add(lhs, rhs);
}


Vector_3
vector_3::operator-(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::sub(lhs, rhs);
}


Vector_3
vector_3::operator*(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::mul(lhs, rhs);
}


Vector_3
vector_3::operator/(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::div(lhs, rhs);
}


Vector_3 &
vector_3::operator+=(Vector_3 & target, const Vector_3 & operand)
{
    return target = target + operand;
}


Vector_3 &
vector_3::operator-=(Vector_3 & target, const Vector_3 & operand)
{
    return target = target - operand;
}


Vector_3 &
vector_3::operator*=(Vector_3 & target, const Vector_3 & operand)
{
    return target = target * operand;
}


Vector_3 &
vector_3::operator/=(Vector_3 & target, const Vector_3 & operand)
{
    return target = target / operand;
}


Vector_3
vector_3::operator*(const Fp_T scalar, const Vector_3 & vector)
{
    return Vector_3::Impl::scale(vector, scalar);
}


Vector_3
vector_3::operator*(const Vector_3 & vector, const Fp_T scalar)
{
    return Vector_3::Impl::scale(vector, scalar);
}


Vector_3
vector_3::operator/(const Fp_T scalar, const Vector_3 & vector)
{
    return Vector_3::Impl::div(Vector_3 (scalar) , vector);
}


Vector_3
vector_3::operator/(const Vector_3 & vector, const Fp_T scalar)
{
    return Vector_3::Impl::div(vector, Vector_3 (scalar));
}


Vector_3 &
vector_3::operator*=(Vector_3 & target, const Fp_T operand)
{
    return target = target * operand;
}


Vector_3 &
vector_3::operator/=(Vector_3 & target, const Fp_T operand)
{
    return target = target / operand;
}


bool
vector_3::almost_equal(const Vector_3 & lhs, const Vector_3 & rhs, Fp_T epsilon)
{
    return Vector_3::Impl::almost_equal(lhs, rhs, epsilon);
}


bool
vector_3::operator==(const Vector_3 & lhs, const Vector_3 & rhs)
{
    return Vector_3::Impl::equal(lhs, rhs);
}
}
