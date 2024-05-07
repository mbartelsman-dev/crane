
#pragma once
#define CRANE_HEADER_CONTENTS

#include <crane/geom/kernel.hpp>

namespace crane::geom
{
    struct Circle
    {
        Point_2 center_ { };
        Fp_T radius_ { };

        [[nodiscard]] Point_2 center() const { return center_; }
        [[nodiscard]] Fp_T radius() const { return radius_; }
    };
}

#undef CRANE_HEADER_CONTENTS