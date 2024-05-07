
#include "Triangle_2.hpp"

#include "Circle.hpp"
#include <crane/geom/kernel.hpp>

namespace crane::geom
{

Vector_2
Triangle_2::ab() const { return b_ - a_; }


Vector_2
Triangle_2::bc() const { return c_ - b_; }


Vector_2
Triangle_2::ca() const { return a_ - c_; }


Circle
Triangle_2::circumscribed_circle() const {
    const Vector_2 ab_perp = perp(ab());
    const Point_2 center = a() + (ab() + dot(bc(), ca()) / dot(ab_perp, ca()) * ab_perp) / 2;
    const Fp_T radius = (center - a()).length();

    return { center, radius };
}


Circle
Triangle_2::medioscribed_circle() const {
    const Vector_2 ab_perp = perp(ab());
    const Point_2 center = lerp(b(), c(), 0.5) - (ab() + dot(bc(), ca()) / dot(ab_perp, ca()) * ab_perp) / 4;
    const Fp_T radius = (center - a()).length() / 2;

    return { center, radius };
}


Circle
Triangle_2::inscribed_circle() const {
    const Vector_2 m = normalize(ab()) - normalize(ca());
    const Vector_2 n = normalize(bc()) - normalize(ab());
    const Point_2 center = a() + det(n, ab()) / det(n, m) * m;
    const Fp_T radius = reject(center - a(), ab()).length();

    return { center, radius };
}


std::array<Fp_T, 3>
Triangle_2::barycentric_coords(const Point_2 & point) const
{
    const Vector_2 v_0 = b() - a();
    const Vector_2 v_1 = c() - a();
    const Vector_2 v_2 = point - a();

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

}
