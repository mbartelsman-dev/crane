
#pragma once
#define CRANE_HEADER_CONTENTS

#include "returns.hpp"

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// Assert_Equal                                                           //
// ---------------------------------------------------------------------- //

/// Asserts that two types are the same. Fails to compile otherwise.
/// To use, declare a type with the types to compare as the arguments.
template <typename Left, typename Right>
struct Assert_Equal;

template <typename T>
struct Assert_Equal<T, T> {};


// ---------------------------------------------------------------------- //
// Assert_Not_Equal                                                       //
// ---------------------------------------------------------------------- //

/// Asserts that two types are different. Fails to compile otherwise.
/// To use, declare a type with the types to compare as the arguments.
template <typename, typename>
struct Assert_Not_Equal {};

template <typename T>
struct Assert_Not_Equal<T, T>;

// ---------------------------------------------------------------------- //
// Assert                                                            //
// ---------------------------------------------------------------------- //

/// Asserts that two types are the same. Fails to compile otherwise.
/// To use, declare a type with the types to compare as the arguments.
template <bool Expr>
struct Assert;

template <>
struct Assert<false>;

template <>
struct Assert<true> {};
}


#undef CRANE_HEADER_CONTENTS