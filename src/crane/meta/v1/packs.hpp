
#pragma once
#define CRANE_HEADER_CONTENTS

#include "errors.hpp"
#include "returns.hpp"
#include "values.hpp"

namespace crane::meta::v1
{

namespace error
{
    struct Out_Of_Bounds;
}

// ---------------------------------------------------------------------- //
// Type_At                                                                //
// ---------------------------------------------------------------------- //

/// Returns the type at the specified index (zero-indexed) in the parameter pack
template <unsigned long long Index, typename ...Ts>
struct Type_At;

template <unsigned long long Index>
struct Type_At<Index> : Return_Error<error::Out_Of_Bounds> { };

template <typename T, typename ...Ts>
struct Type_At<0, T, Ts...> : Return_Type<T> { };

template <unsigned long long Index, typename T, typename ...Ts>
struct Type_At<Index, T, Ts...> : Type_At<Index - 1, Ts...> { };


// ---------------------------------------------------------------------- //
// Pack_Length                                                            //
// ---------------------------------------------------------------------- //

/// Returns the length of the parameter pack
template <typename ...Ts>
struct Pack_Length;

template <>
struct Pack_Length<> : Return_Value<unsigned long long, 0> {};

template <typename T, typename ...Ts>
struct Pack_Length<T, Ts...> : Return_Value<unsigned long long, 1 + Pack_Length<Ts...>{}> {};


}

#undef CRANE_HEADER_CONTENTS