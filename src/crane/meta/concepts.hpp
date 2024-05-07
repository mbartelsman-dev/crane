
#pragma once
#define CRANE_HEADER_CONTENTS

#include <type_traits>

namespace crane::meta
{
/// Concept for empty structs/classes
template <typename T>
concept IEmpty = std::is_empty_v<T>;

/// Concept for empty structs/classes
template <typename T>
concept IEnum = std::is_enum_v<T>;

/// Concept for functions
template <typename F>
concept IFunction = std::is_function_v<F>;

/// Concept for numeric types
template <typename T>
concept INumeric = std::is_arithmetic_v<T>;

/// Concept for integer types
template <typename T>
concept IInteger = std::is_integral_v<T>;

/// Concept for floating point types
template <typename T>
concept IFloatingPoint = std::is_floating_point_v<T>;

// ---------------------------------------------------------------------- //
// Require                                                                //
// ---------------------------------------------------------------------- //

/// Enforces a condition using SFINAE
template <bool Expr, typename T>
struct Require;

template <typename T>
struct Require<true, T>
{
    using Type = T;
};

template <bool Expr, typename T>
using Require_t = typename Require<Expr, T>::Type;
}

#undef CRANE_HEADER_CONTENTS