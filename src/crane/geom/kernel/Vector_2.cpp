#include "Vector_2.hpp"

#include <algorithm>
#include <cmath>

#include "Direction_2.hpp"
#include "Point_2.hpp"
#include "Angle.hpp"

namespace crane::geom
{
Vector_2::Vector_2(const Type v):
    Vector_Impl {{ v, v }} { }


Vector_2::Vector_2(const Type x, const Type y):
    Vector_Impl {{ x, y }} { }


Vector_2::Vector_2(const Direction_2 & d):
    Vector_Impl { d.data() } { }


Vector_2::Vector_2(const Point_2 & p):
    Vector_Impl { p.data() } { }


Vector_2::Vector_2(std::array<Type, Size> data):
    Vector_Impl { std::forward<std::array<Type, Size>>(data) } {}


Vector_2
Vector_2::zero() { return Vector_2 { 0.0f }; }


Vector_2
Vector_2::one() { return Vector_2 { 1.0f }; }


Vector_2
Vector_2::unit_x() { return Vector_2 { 1.0f, 0.0f }; }


Vector_2
Vector_2::unit_y() { return Vector_2 { 0.0f, 1.0f }; }


Fp_T
Vector_2::length() const
{
    return std::sqrt(length_sq());
}


Fp_T
Vector_2::length_sq() const
{
    return x() * x() + y() * y();
}


Fp_T
Vector_2::length_rectilinear() const
{
    return x() + y();
}


Direction_2
Vector_2::direction() const
{
    const Fp_T norm = length();
    return Direction_2 { x() / norm, y() / norm };
}


Fp_T
vector_2::distance(const Vector_2 & start, const Vector_2 & end)
{
    return (end - start).length();
}


Fp_T
vector_2::distance_sq(const Vector_2 & start, const Vector_2 & end)
{
    return (end - start).length_sq();
}


Fp_T
vector_2::distance_rectilinear(const Vector_2 & start, const Vector_2 & end)
{
    return (end - start).length_rectilinear();
}


Fp_T
vector_2::dot(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return lhs.x() * rhs.x() + lhs.y() * rhs.y();
}


Fp_T
vector_2::det(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return lhs.x() * rhs.y() - lhs.y() * rhs.x();
}


Angle
vector_2::angle(const Vector_2 & start, const Vector_2 & end)
{
    return atan2(det(start, end), dot(start, end));
}


Vector_2
vector_2::rotate(const Vector_2 & vec, const Angle & ang)
{
    const Fp_T cos = angle::cos(ang);
    const Fp_T sin = angle::sin(ang);

    return Vector_2 {
        vec.x() * cos - vec.y() * sin,
        vec.x() * sin + vec.y() * cos
    };
}


Vector_2
vector_2::normalize(const Vector_2 & vec)
{
    return vec / vec.length();
}


Vector_2
vector_2::perp(const Vector_2 & vec)
{
    return Vector_2 { -vec.y(), vec.x() };
}


Vector_2
vector_2::project(const Vector_2 & vec, const Vector_2 & target)
{
    return dot(target, vec) / target.length_sq() * target;
}


Vector_2
vector_2::reject(const Vector_2 & vec, const Vector_2 & target)
{
    return det(target, vec) / target.length_sq() * perp(target);
}


Vector_2
vector_2::reflect(const Vector_2 & vec, const Vector_2 & normal)
{
    return vec - 2 * project(vec, normal);
}


Vector_2
vector_2::mirror(const Vector_2 & vec, const Vector_2 & normal)
{
    return -reflect(vec, normal);
}


Vector_2
vector_2::lerp(const Vector_2 & start, const Vector_2 & end, const Fp_T t)
{
    return Vector_2::Impl::lerp(start, end, t);
}


Vector_2
vector_2::fast_slerp(const Vector_2 & start, const Vector_2 & end, const Fp_T t)
{
    return normalize(lerp(start, end, t)) * math::lerp(start.length(), end.length(), t);
}


Vector_2
vector_2::slerp(const Vector_2 & start, const Vector_2 & end, const Fp_T t)
{
    const Angle rotation = angle(start, end);

    if (rotation <= Angle::half_turn())
        return rotate(start, rotation * t) * math::lerp(start.length(), end.length(), t);

    return rotate(end, (Angle::full_turn() - rotation) * (1.0f - t)) * math::lerp(start.length(), end.length(), t);
}


Vector_2
vector_2::min(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::min(lhs, rhs);
}


Vector_2
vector_2::max(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::max(lhs, rhs);
}


Vector_2
vector_2::clamp(const Vector_2 & vec, const Vector_2 & min, const Vector_2 & max)
{
    return Vector_2::Impl::clamp(vec, min, max);
}


Vector_2
vector_2::operator-(const Vector_2 & vector)
{
    return Vector_2::Impl::neg(vector);
}


Vector_2
vector_2::operator+(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::add(lhs, rhs);
}


Vector_2
vector_2::operator-(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::sub(lhs, rhs);
}


Vector_2
vector_2::operator*(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::mul(lhs, rhs);
}


Vector_2
vector_2::operator/(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::div(lhs, rhs);
}


Vector_2 &
vector_2::operator+=(Vector_2 & target, const Vector_2 & operand)
{
    return target = target + operand;
}


Vector_2 &
vector_2::operator-=(Vector_2 & target, const Vector_2 & operand)
{
    return target = target - operand;
}


Vector_2 &
vector_2::operator*=(Vector_2 & target, const Vector_2 & operand)
{
    return target = target * operand;
}


Vector_2 &
vector_2::operator/=(Vector_2 & target, const Vector_2 & operand)
{
    return target = target / operand;
}


Vector_2
vector_2::operator*(const Fp_T scalar, const Vector_2 & vector)
{
    return Vector_2::Impl::scale(vector, scalar);
}


Vector_2
vector_2::operator*(const Vector_2 & vector, const Fp_T scalar)
{
    return Vector_2::Impl::scale(vector, scalar);
}


Vector_2
vector_2::operator/(const Fp_T scalar, const Vector_2 & vector)
{
    return Vector_2::Impl::div(Vector_2 (scalar) , vector);
}


Vector_2
vector_2::operator/(const Vector_2 & vector, const Fp_T scalar)
{
    return Vector_2::Impl::div(vector, Vector_2 (scalar));
}


Vector_2 &
vector_2::operator*=(Vector_2 & target, const Fp_T operand)
{
    return target = target * operand;
}


Vector_2 &
vector_2::operator/=(Vector_2 & target, const Fp_T operand)
{
    return target = target / operand;
}


bool
vector_2::almost_equal(const Vector_2 & lhs, const Vector_2 & rhs, Fp_T epsilon)
{
    return Vector_2::Impl::almost_equal(lhs, rhs, epsilon);
}


bool
vector_2::operator==(const Vector_2 & lhs, const Vector_2 & rhs)
{
    return Vector_2::Impl::equal(lhs, rhs);
}
}
