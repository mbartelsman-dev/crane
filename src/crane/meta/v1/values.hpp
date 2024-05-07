
#pragma once
#define CRANE_HEADER_CONTENTS

namespace crane::meta::v1
{

// ---------------------------------------------------------------------- //
// Return_Value                                                           //
// ---------------------------------------------------------------------- //

template <typename T, T v>
struct Return_Value
{
    static constexpr T Value = v;

    // ReSharper disable once CppNonExplicitConversionOperator
    constexpr operator T() const { return Value; } // NOLINT(*-explicit-constructor)
};

}

#undef CRANE_HEADER_CONTENTS