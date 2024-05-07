
#pragma once
#define CRANE_HEADER_CONTENTS

#include <type_traits>

#include "returns.hpp"
#include "tuples.hpp"

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// IFunction                                                              //
// ---------------------------------------------------------------------- //

template <typename F>
concept IFunction = std::is_function_v<F>;


// ---------------------------------------------------------------------- //
// Arguments_Of                                                           //
// ---------------------------------------------------------------------- //

template <typename Func>
struct Arguments_Of;

template <typename Return, typename ...Args>
struct Arguments_Of<Return(Args...)> : Return_Type<Tuple<Args...>> {};

template <typename Return, typename Class, typename ...Args>
struct Arguments_Of<Return (Class::*)(Args...)> : Return_Type<Tuple<Args...>> {};


// ---------------------------------------------------------------------- //
// Argument_At                                                            //
// ---------------------------------------------------------------------- //

template <unsigned long long Index, typename Func>
struct Argument_At : Arguments_Of<Func>::Type::template Get<Index> {};


// ---------------------------------------------------------------------- //
// Return_Of                                                              //
// ---------------------------------------------------------------------- //

template <IFunction Func>
struct Return_Of;

template <typename Return, typename ...Args>
struct Return_Of<Return(Args...)> : Return_Type<Return> {};

template <typename Return, typename Class, typename ...Args>
struct Return_Of<Return (Class::*)(Args...)> : Return_Type<Return> {};

}

#undef CRANE_HEADER_CONTENTS