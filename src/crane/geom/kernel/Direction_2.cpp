
#include "Direction_2.hpp"

#include <algorithm>
#include <cmath>

#include "Vector_2.hpp"
#include "Vector_Impl.hpp"
#include "Angle.hpp"

namespace crane::geom
{

Direction_2
Direction_2::x_axis()
{
    return Direction_2 { 1.0f, 0.0f };
}


Direction_2
Direction_2::y_axis()
{
    return Direction_2 { 0.0f, 1.0f };
}


Direction_2
direction_2::rotate(const Direction_2 & d, const Angle & ang)
{
    const Fp_T cos = angle::cos(ang);
    const Fp_T sin = angle::sin(ang);

    return Direction_2 {
        d.dx() * cos - d.dy() * sin,
        d.dx() * sin + d.dy() * cos
    };
}


Direction_2
direction_2::lerp(const Direction_2 & start, const Direction_2 & end, const Fp_T t)
{
    return Direction_2::Impl::lerp(start, end, t);
}


bool
direction_2::operator==(const Direction_2 & lhs, const Direction_2 & rhs)
{
    return Direction_2::Impl::equal(lhs, rhs);
}


bool
direction_2::almost_equal(const Direction_2 & lhs, const Direction_2 & rhs, const Fp_T epsilon)
{
    return Direction_2::Impl::almost_equal(lhs, rhs, epsilon);
}


Direction_2
direction_2::operator-(const Direction_2 & dir)
{
    return Direction_2::Impl::neg(dir);
}


Direction_2
direction_2::operator+(const Direction_2 & dir, const Angle & ang)
{
    return rotate(dir, ang);
}


Direction_2
direction_2::operator-(const Direction_2 & dir, const Angle & ang)
{
    return dir + (-ang);
}


Angle
direction_2::operator-(const Direction_2 & lhs, const Direction_2 & rhs)
{
    const Fp_T dot = lhs.dx() * rhs.dx() + lhs.dy() * rhs.dy();
    const Fp_T det = lhs.dx() * rhs.dy() - lhs.dy() * rhs.dx();
    return atan2(det, dot);
}


Direction_2 &
direction_2::operator+=(Direction_2 & target, const Angle & operand)
{
    return target = target + operand;
}


Direction_2 &
direction_2::operator-=(Direction_2 & target, const Angle & operand)
{
    return target = target - operand;
}


Vector_2
direction_2::operator*(const Direction_2 & dir, const Fp_T mag)
{
    return Vector_2 { Direction_2::Impl::scale(dir, mag) };
}


Vector_2
direction_2::operator*(const Fp_T mag, const Direction_2 & dir)
{
    return Vector_2 { Direction_2::Impl::scale(dir, mag) };
}

}
