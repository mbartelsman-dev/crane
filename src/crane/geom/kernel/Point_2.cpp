
#include "Point_2.hpp"

#include "Vector_2.hpp"

namespace crane::geom
{
Point_2
Point_2::origin() { return Point_2 { 0.0f, 0.0f }; }


Point_2
point_2::lerp(const Point_2 & a, const Point_2 & b, const Fp_T t)
{
    return Point_2::Impl::lerp(a, b, t);
}


Point_2
point_2::min(const Point_2 & a, const Point_2 & b)
{
    return Point_2::Impl::min(a, b);
}


Point_2
point_2::max(const Point_2 & a, const Point_2 & b)
{
    return Point_2::Impl::max(a, b);
}


Point_2
point_2::clamp(const Point_2 & p, const Point_2 & min, const Point_2 & max)
{
    return Point_2::Impl::clamp(p, min, max);
}


bool
point_2::almost_equal(const Point_2 & a, const Point_2 & b, const Fp_T epsilon)
{
    return Point_2::Impl::almost_equal(a, b, epsilon);
}


bool
point_2::operator==(const Point_2 & a, const Point_2 & b)
{
    return Point_2::Impl::equal(a, b);
}

Point_2
point_2::operator+(const Point_2 & a, const Vector_2 & b)
{
    return Point_2::Impl::add(a, Point_2::Impl { b.data() });
}


Point_2
point_2::operator-(const Point_2 & a, const Vector_2 & b)
{
    return Point_2::Impl::sub(a, Point_2::Impl { b.data() });
}


Vector_2
point_2::operator-(const Point_2 & a, const Point_2 & b)
{
    return Vector_2 { Point_2::Impl::sub(a, b) };
}


Point_2 &
point_2::operator+=(Point_2 & target, const Vector_2 & operand)
{
    return target = target + operand;
}


Point_2 &
point_2::operator-=(Point_2 & target, const Vector_2 & operand)
{
    return target = target - operand;
}
}
