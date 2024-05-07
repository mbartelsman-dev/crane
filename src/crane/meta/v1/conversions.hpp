
#pragma once
#define CRANE_HEADER_CONTENTS

#include "returns.hpp"

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// As_Value                                                               //
// ---------------------------------------------------------------------- //

template <typename T>
struct As_Value : Return_Type<T> {};

template <typename T>
struct As_Value<T&> : Return_Type<T> {};

template <typename T>
struct As_Value<T&&> : Return_Type<T> {};

template <typename T>
struct As_Value<const T&> : Return_Type<T> {};

template <typename T>
struct As_Value<const T&&> : Return_Type<T> {};


// ---------------------------------------------------------------------- //
// As_Ref                                                                 //
// ---------------------------------------------------------------------- //

template <typename T>
struct As_Ref : Return_Type<T&> {};


// ---------------------------------------------------------------------- //
// As_Const_Ref                                                           //
// ---------------------------------------------------------------------- //

template <typename T>
struct As_Const_Ref : Return_Type<const T&> {};

}

#undef CRANE_HEADER_CONTENTS