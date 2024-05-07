
#pragma once
#define CRANE_HEADER_CONTENTS
#include <array>
#include <raylib.h>

#include "crane.hpp"

namespace crane::geom
{
template <typename Concrete, typename Type, Uint_T rows, Uint_T cols = rows>
struct Matrix_Impl
{
    // ---------------------------------------------------------------------- //
    // MEMBERS                                                                //
    // ---------------------------------------------------------------------- //

private:
    std::array<Type, rows * cols> data_;
public:

    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Matrix_Impl() = default;

    explicit
    Matrix_Impl(std::array<Type, rows * cols> data):
        data_ { data } {}


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    Fp_T & operator()(const Uint_T row, const Uint_T col) { return data_[row * cols + col]; }
    Fp_T operator()(const Uint_T row, const Uint_T col) const { return data_[row * cols + col]; }
    [[nodiscard]] const std::array<Type, rows * cols> & data() const { return data_; }


    // ---------------------------------------------------------------------- //
    // FACTORIES                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] static Concrete identity();


    // ---------------------------------------------------------------------- //
    // STATIC METHODS                                                         //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] static Concrete add();
    [[nodiscard]] static Concrete sub();
    [[nodiscard]] static Concrete mul();

};
}

#undef CRANE_HEADER_CONTENTS