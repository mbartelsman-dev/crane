
#include "Triangle_3.hpp"

#include "crane/geom/numerics/Vector_3.hpp"


crane::geom::Vector_3
crane::geom::Triangle_3::ab() const { return b_ - a_; }


crane::geom::Vector_3
crane::geom::Triangle_3::bc() const { return c_ - b_; }


crane::geom::Vector_3
crane::geom::Triangle_3::ca() const { return a_ - c_; }


std::array<crane::Fp_T, 3>
crane::geom::Triangle_3::barycentric_coords(const Point_3 & point) const
{
    const Vector_3 v_0 = b() - a();
    const Vector_3 v_1 = c() - a();
    const Vector_3 v_2 = point - a();

    const Fp_T dot_00 = dot(v_0, v_0);
    const Fp_T dot_01 = dot(v_0, v_1);
    const Fp_T dot_11 = dot(v_1, v_1);
    const Fp_T dot_20 = dot(v_2, v_0);
    const Fp_T dot_21 = dot(v_2, v_1);

    const Fp_T denom = dot_00 * dot_11 - dot_01 * dot_01;

    const Fp_T y = (dot_11 * dot_20 - dot_01 * dot_21) / denom;
    const Fp_T z = (dot_00 * dot_21 - dot_01 * dot_20) / denom;
    const Fp_T x = 1.0f - (z + y);

    return { x, y, z };
}
