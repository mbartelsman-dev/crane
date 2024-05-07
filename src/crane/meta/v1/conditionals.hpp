
#pragma once
#define CRANE_HEADER_CONTENTS

#include "errors.hpp"
#include "returns.hpp"

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// IF                                                                     //
// ---------------------------------------------------------------------- //

template <bool guard, typename TrueCase, typename FalseCase>
struct If;

template <typename TrueCase, typename FalseCase>
struct If<true, TrueCase, FalseCase> : Return_Type<TrueCase> { };

template <typename TrueCase, typename FalseCase>
struct If<false, TrueCase, FalseCase> : Return_Type<FalseCase> { };


// ---------------------------------------------------------------------- //
// Switch Case                                                            //
// ---------------------------------------------------------------------- //

//
// Case
// ------------------------------------------------------------------- //

template <bool guard, typename Type>
struct Case;

//
// Default
// ------------------------------------------------------------------- //

template <typename Type>
struct Default : Case<true, Type> {};

//
// Switch
// ------------------------------------------------------------------- //

namespace error
{
    struct No_Matching_Case;
}

/// Selects the first true case in the switch, if a default is provided,
/// it'll be selected so long as no other cases match.
template <typename ...Cases>
struct Switch;

// No cases left to match against
template <>
struct Switch<> : Return_Error<error::No_Matching_Case> { };

// Only default case left
template <typename Type>
struct Switch<Default<Type>> : Return_Type<Type> { };

// Postpone default until no other cases match
template <typename Type, typename Case, typename ...Cases>
struct Switch<Default<Type>, Case, Cases...> : Switch<Case, Default<Type>, Cases...> { };

// Matching case
template <typename Type, typename ...Cases>
struct Switch<Case<true, Type>, Cases...> : Return_Type<Type> { };

// Failed match
template <typename Type, typename ...Cases>
struct Switch<Case<false, Type>, Cases...> : Switch<Cases...> { };
}

#undef CRANE_HEADER_CONTENTS