
#pragma once
#define CRANE_HEADER_CONTENTS

#include <concepts>

#include "booleans.hpp"
#include "returns.hpp"
#include "values.hpp"

namespace crane::meta::v1
{

namespace error
{
    struct Division_By_Zero;
}

// ---------------------------------------------------------------------- //
// IInteger                                                               //
// ---------------------------------------------------------------------- //

template <typename T>
concept IInteger = requires
{
    { T::Value } -> std::convertible_to<int>;
};

template <IInteger>
struct Is_IInteger : Return_Value<bool, true> {};


// ---------------------------------------------------------------------- //
// Integer                                                                //
// ---------------------------------------------------------------------- //

template <int Value>
struct Integer : Return_Value<int, Value> {};


// ---------------------------------------------------------------------- //
// Succ                                                                   //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void>
struct Succ;

template <int Value>
struct Succ<Integer<Value>> : Return_Type<Integer<(Value + 1)>> {};


// ---------------------------------------------------------------------- //
// Pred                                                                   //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void>
struct Pred;

template <int Value>
struct Pred<Integer<Value>> : Return_Type<Integer<(Value - 1)>> {};


// ---------------------------------------------------------------------- //
// Neg                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void>
struct Neg;

template <int Value>
struct Neg<Integer<Value>> : Return_Type<Integer<(-Value)>> {};


// ---------------------------------------------------------------------- //
// Add                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Add;

template <int Lhs, int Rhs>
struct Add<Integer<Lhs>, Integer<Rhs>> : Return_Type<Integer<Lhs + Rhs>> {};


// ---------------------------------------------------------------------- //
// Sub                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Sub;

template <int Lhs, int Rhs>
struct Sub<Integer<Lhs>, Integer<Rhs>> : Return_Type<Integer<Lhs - Rhs>> {};


// ---------------------------------------------------------------------- //
// Mul                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Mul;

template <int Lhs, int Rhs>
struct Mul<Integer<Lhs>, Integer<Rhs>> : Return_Type<Integer<Lhs * Rhs>> {};


// ---------------------------------------------------------------------- //
// Div                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Div;

template <int Lhs, int Rhs>
struct Div<Integer<Lhs>, Integer<Rhs>> : Return_Type<Integer<Lhs / Rhs>> {};

template <int Lhs>
struct Div<Integer<Lhs>, Integer<0>> : Return_Error<error::Division_By_Zero> {};


// ---------------------------------------------------------------------- //
// Mod                                                                    //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Mod;

template <int Lhs, int Rhs>
struct Mod<Integer<Lhs>, Integer<Rhs>> : Return_Type<Integer<Lhs % Rhs>> {};

template <int Lhs>
struct Mod<Integer<Lhs>, Integer<0>> : Return_Error<error::Division_By_Zero> {};


// ---------------------------------------------------------------------- //
// Greater_Than                                                           //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Greater_Than;

template <int Lhs, int Rhs>
struct Greater_Than<Integer<Lhs>, Integer<Rhs>> : As_Boolean<(Lhs > Rhs)> {};


// ---------------------------------------------------------------------- //
// Less_Than                                                              //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Less_Than;

template <int Lhs, int Rhs>
struct Less_Than<Integer<Lhs>, Integer<Rhs>> : As_Boolean<(Lhs < Rhs)> {};


// ---------------------------------------------------------------------- //
// Greater_Or_Equal                                                       //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Greater_Or_Equal;

template <int Lhs, int Rhs>
struct Greater_Or_Equal<Integer<Lhs>, Integer<Rhs>> : As_Boolean<(Lhs >= Rhs)> {};


// ---------------------------------------------------------------------- //
// Less_Or_Equal                                                          //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Less_Or_Equal;

template <int Lhs, int Rhs>
struct Less_Or_Equal<Integer<Lhs>, Integer<Rhs>> : As_Boolean<(Lhs <= Rhs)> {};


// ---------------------------------------------------------------------- //
// Equal                                                                  //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Equal;

template <int Lhs, int Rhs>
struct Equal<Integer<Lhs>, Integer<Rhs>> : As_Boolean<(Lhs == Rhs)> {};


// ---------------------------------------------------------------------- //
// Not_Equal                                                              //
// ---------------------------------------------------------------------- //

template <IParameter<Is_IInteger> = void, IParameter<Is_IInteger> = void>
struct Not_Equal;

template <int Lhs, int Rhs>
struct Not_Equal<Integer<Lhs>, Integer<Rhs>> : As_Boolean<(Lhs != Rhs)> {};

}


#undef CRANE_HEADER_CONTENTS