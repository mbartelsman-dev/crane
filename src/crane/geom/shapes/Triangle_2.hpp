
#pragma once
#define CRANE_HEADER_CONTENTS

#include <crane/geom/kernel.hpp>

namespace crane::geom
{
struct Circle;
struct Vector_2;

struct Triangle_2
{
private:
    Point_2 a_ { };
    Point_2 b_ { };
    Point_2 c_ { };

public:
    [[nodiscard]] Point_2 a() const { return a_; }
    [[nodiscard]] Point_2 b() const { return b_; }
    [[nodiscard]] Point_2 c() const { return c_; }

    [[nodiscard]] Vector_2 ab() const;
    [[nodiscard]] Vector_2 bc() const;
    [[nodiscard]] Vector_2 ca() const;

    [[nodiscard]] Circle circumscribed_circle() const;
    [[nodiscard]] Circle medioscribed_circle() const;
    [[nodiscard]] Circle inscribed_circle() const;

    [[nodiscard]] std::array<Fp_T, 3> barycentric_coords(const Point_2 & point) const;
};
}

#undef CRANE_HEADER_CONTENTS