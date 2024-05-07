
#pragma once
#define CRANE_HEADER_CONTENTS

#include "crane/geom/kernel.hpp"

namespace crane::geom
{
    struct Triangle_3
    {
    private:
        Point_3 a_ { };
        Point_3 b_ { };
        Point_3 c_ { };

    public:
        [[nodiscard]] Point_3 a() const { return a_; }
        [[nodiscard]] Point_3 b() const { return b_; }
        [[nodiscard]] Point_3 c() const { return c_; }
        [[nodiscard]] Vector_3 ab() const;
        [[nodiscard]] Vector_3 bc() const;
        [[nodiscard]] Vector_3 ca() const;

        [[nodiscard]] std::array<Fp_T, 3> barycentric_coords(const Point_3 & point) const;
    };
}

#undef CRANE_HEADER_CONTENTS