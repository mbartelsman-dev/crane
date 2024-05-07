#pragma once
#define CRANE_HEADER_CONTENTS

#include <array>

#include <crane.hpp>
#include <crane/math.hpp>


namespace crane::geom
{
template <typename Concrete, typename Type, Uint_T Size>
struct Vector_Impl
{
    // ---------------------------------------------------------------------- //
    // MEMBERS                                                                //
    // ---------------------------------------------------------------------- //

private:
    std::array<Type, Size> data_;
public:

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Vector_Impl() = default;

    explicit
    Vector_Impl(std::array<Type, Size> data): data_ { data } {}


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    Fp_T & operator[](Uint_T idx) { return data_[idx]; }
    Fp_T operator[](Uint_T idx) const { return data_[idx]; }
    const std::array<Type, Size> & data() const { return data_; }


    // ---------------------------------------------------------------------- //
    // STATIC METHODS                                                         //
    // ---------------------------------------------------------------------- //

    //
    // Arithmetic
    // ------------------------------------------------------------------- //

    static Concrete
    neg(const Vector_Impl & vec);

    static Concrete
    add(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static Concrete
    sub(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static Concrete
    mul(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static Concrete
    div(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static Concrete
    scale(const Vector_Impl & vec, Type scalar);

    static Concrete
    lerp(const Vector_Impl & start, const Vector_Impl & end, Fp_T t);

    static Concrete
    min(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static Concrete
    max(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static Concrete
    clamp(
        const Vector_Impl & vec,
        const Vector_Impl & min,
        const Vector_Impl & max);

    //
    // Comparison
    // ------------------------------------------------------------------- //

    static bool
    equal(const Vector_Impl & lhs, const Vector_Impl & rhs);

    static meta::Require_t<meta::IFloatingPoint<Type>, bool>
    almost_equal(
        const Vector_Impl & lhs,
        const Vector_Impl & rhs,
        Type epsilon = numbers::eps<Type>);
};
}

#include "Vector_Impl.tpp"

#undef CRANE_HEADER_CONTENTS
