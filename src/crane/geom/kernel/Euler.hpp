
#pragma once
#define CRANE_HEADER_CONTENTS

#include "Angle.hpp"
#include "Vector_Impl.hpp"

namespace crane::geom
{
struct Euler
{
    std::array<Angle, 3> data_;

    Euler(const Angle & roll, const Angle & pitch, const Angle & yaw):
        data_ { roll, pitch, yaw } {}

    // TODO: Quaternions
    // explicit Euler(const Quaternion & quaternion):
    //     data_ {  } { static_assert(false, "TODO"); }

    [[nodiscard]] const Angle & roll() const { return data_[0]; }
    [[nodiscard]] const Angle & pitch() const { return data_[1]; }
    [[nodiscard]] const Angle & yaw() const { return data_[2]; }
};
}
#undef CRANE_HEADER_CONTENTS
