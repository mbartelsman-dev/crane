
#pragma once
#define CRANE_HEADER_CONTENTS

#include <concepts>

#include "conditionals.hpp"
#include "parameters.hpp"
#include "returns.hpp"
#include "values.hpp"

namespace crane::meta::v1
{

// ---------------------------------------------------------------------- //
// IBoolean                                                               //
// ---------------------------------------------------------------------- //

template <typename T>
concept IBoolean =
    requires { { T::Value }->std::convertible_to<bool>; };

template <IBoolean>
struct Is_IBoolean : Return_Value<bool, true> {};


// ---------------------------------------------------------------------- //
// True                                                                   //
// ---------------------------------------------------------------------- //

struct True : Return_Value<bool, true> { };


// ---------------------------------------------------------------------- //
// False                                                                  //
// ---------------------------------------------------------------------- //

struct False : Return_Value<bool, false> { };


// ---------------------------------------------------------------------- //
// Not                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IBoolean> = void>
struct Not;

template <>
struct Not<True> : Return_Type<False> {};

template <>
struct Not<False> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// And                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IBoolean> = void, IParameter<Is_IBoolean> = void>
struct And;

template <>
struct And<True, True> : Return_Type<True> {};

template <IParameter<Is_IBoolean> Lhs, IParameter<Is_IBoolean> Rhs>
    requires IBoolean<Lhs> && IBoolean<Rhs>
struct And<Lhs, Rhs> : Return_Type<False> {};


// ---------------------------------------------------------------------- //
// Or                                                                     //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IBoolean> = void, IParameter<Is_IBoolean> = void>
struct Or;

template <>
struct Or<False, False> : Return_Type<False> {};

template <IParameter<Is_IBoolean> Lhs, IParameter<Is_IBoolean> Rhs>
    requires IBoolean<Lhs> && IBoolean<Rhs>
struct Or<Lhs, Rhs> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// Xor                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IBoolean> = void, IParameter<Is_IBoolean> = void>
struct Xor;

template <>
struct Xor<True, True> : Return_Type<False> {};

template <>
struct Xor<False, False> : Return_Type<False> {};

template <IParameter<Is_IBoolean> Lhs, IParameter<Is_IBoolean> Rhs>
    requires IBoolean<Lhs> && IBoolean<Rhs>
struct Xor<Lhs, Rhs> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// As_Boolean                                                                //
// ---------------------------------------------------------------------- //

template <bool Value>
struct As_Boolean : If<Value, True, False> {};

}

#undef CRANE_HEADER_CONTENTS