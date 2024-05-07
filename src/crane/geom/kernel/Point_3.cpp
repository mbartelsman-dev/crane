
#include "Point_3.hpp"

#include "Vector_3.hpp"

namespace crane::geom
{
Point_3
Point_3::origin() { return Point_3 { 0.0f, 0.0f, 0.0f }; }


Point_3
point_3::lerp(const Point_3 & a, const Point_3 & b, const Fp_T t)
{
    return Point_3::Impl::lerp(a, b, t);
}


Point_3
point_3::min(const Point_3 & a, const Point_3 & b)
{
    return Point_3::Impl::min(a, b);
}


Point_3
point_3::max(const Point_3 & a, const Point_3 & b)
{
    return Point_3::Impl::max(a, b);
}


Point_3
point_3::clamp(const Point_3 & p, const Point_3 & min, const Point_3 & max)
{
    return Point_3::Impl::clamp(p, min, max);
}


bool
point_3::almost_equal(const Point_3 & a, const Point_3 & b, const Fp_T epsilon)
{
    return Point_3::Impl::almost_equal(a, b, epsilon);
}


bool
point_3::operator==(const Point_3 & a, const Point_3 & b)
{
    return Point_3::Impl::equal(a, b);
}

Point_3
point_3::operator+(const Point_3 & a, const Vector_3 & b)
{
    return Point_3::Impl::add(a, Point_3::Impl { b.data() });
}


Point_3
point_3::operator-(const Point_3 & a, const Vector_3 & b)
{
    return Point_3::Impl::sub(a, Point_3::Impl { b.data() });
}


Vector_3
point_3::operator-(const Point_3 & a, const Point_3 & b)
{
    return Vector_3 { Point_3::Impl::sub(a, b) };
}


Point_3 &
point_3::operator+=(Point_3 & target, const Vector_3 & operand)
{
    return target = target + operand;
}


Point_3 &
point_3::operator-=(Point_3 & target, const Vector_3 & operand)
{
    return target = target - operand;
}
}
