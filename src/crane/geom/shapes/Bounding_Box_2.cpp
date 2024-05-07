
#include "Bounding_Box_2.hpp"

namespace crane::geom
{
Bounding_Box_2::Bounding_Box_2(std::initializer_list<Vector_2> points)
{
    for (auto & point : points)
        *this |= point;
}

Bounding_Box_2 &
Bounding_Box_2::operator|=(const Vector_2 & other)
{
    _min = vector_2::min(_min, other);
    _max = vector_2::max(_max, other);
    return *this;
}
}
