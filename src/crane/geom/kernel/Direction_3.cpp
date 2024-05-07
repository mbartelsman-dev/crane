
#include "Direction_3.hpp"

#include <algorithm>
#include <cmath>

#include "Direction_2.hpp"
#include "Vector_3.hpp"
#include "Vector_Impl.hpp"
#include "Angle.hpp"

namespace crane::geom
{

Direction_3
Direction_3::x_axis()
{
    return Direction_3 { 1.0f, 0.0f, 0.0f };
}


Direction_3
Direction_3::y_axis()
{
    return Direction_3 { 0.0f, 1.0f, 0.0f };
}


Direction_3
Direction_3::z_axis()
{
    return Direction_3 { 0.0f, 0.0f, 1.0f };
}


Direction_3
direction_3::rotate(const Direction_3 & dir, const Direction_3 & axis, const Angle & ang)
{
    // Rodrigues' rotation formula
    // https://en.wikipedia.org/wiki/Rodrigues%27_rotation_formula

    const Vector_3 vec_dir { dir };
    const Vector_3 vec_axis { axis };

    const Vector_3 res = (vec_dir * cos(ang))
        + (cross(vec_axis, vec_dir) * sin(ang))
        + vec_axis * dot(vec_axis, vec_dir) * (1 - cos(ang));

    return Direction_3 { res.data() };
}

Direction_3
direction_3::lerp(const Direction_3 & start, const Direction_3 & end, const Fp_T t)
{
    return Direction_3::Impl::lerp(start, end, t);
}


bool
direction_3::operator==(const Direction_3 & a, const Direction_3 & b)
{
    return Direction_3::Impl::equal(a, b);
}


bool
direction_3::almost_equal(const Direction_3 & a, const Direction_3 & b, const Fp_T epsilon)
{
    return Direction_3::Impl::almost_equal(a, b, epsilon);
}


Direction_3
direction_3::operator-(const Direction_3 & d)
{
    return Direction_3::Impl::neg(d);
}


Vector_3
direction_3::operator*(const Direction_3 & d, const Fp_T m)
{
    return Vector_3 (Direction_3::Impl::scale(d, m));
}


Vector_3
direction_3::operator*(const Fp_T m, const Direction_3 & d)
{
    return Vector_3 (Direction_3::Impl::scale(d, m));
}

}
