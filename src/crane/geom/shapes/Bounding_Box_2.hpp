
#pragma once
#define CRANE_HEADER_CONTENTS
#include <crane/geom/kernel.hpp>

namespace crane::geom
{
struct Bounding_Box_2
{
private:
    Vector_2 _min { numbers::inf<Fp_T> };
    Vector_2 _max { -numbers::inf<Fp_T> };
public:

    Bounding_Box_2() = default;
    Bounding_Box_2(std::initializer_list<Vector_2> points);

    [[nodiscard]] Vector_2 min() const { return _min; }
    [[nodiscard]] Vector_2 max() const { return _max; }

    Bounding_Box_2 & operator|=(const Vector_2 & other);
};

}

#undef CRANE_HEADER_CONTENTS
