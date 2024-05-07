
#pragma once
#define CRANE_HEADER_CONTENTS

#include "returns.hpp"
#include "tuples.hpp"

namespace crane::meta::v1
{

namespace error
{
    struct Not_A_Tuple;
}

// ---------------------------------------------------------------------- //
// Under_Name                                                             //
// ---------------------------------------------------------------------- //

/// Returns all types filed under containers of the requested type
template <template <typename...> typename, typename>
struct Under_Name : Return_Error<error::Not_A_Tuple> {};

template <template <typename...> typename Query>
struct Under_Name<Query, Tuple<>> : Return_Type<Tuple<>> {};

template <
    template <typename...> typename Name,
    typename ...Contents,
    typename ...Containers>
struct Under_Name<
    Name,
    Tuple<
        Name<Contents...>,
        Containers...>>
    : Concat<
        Tuple<Contents...>,
        typename Under_Name<Name, Tuple<Containers...>>::Type> {};

template <
    template <typename...> typename Name,
    typename Container,
    typename ...Containers>
struct Under_Name<
    Name,
    Tuple<
        Container,
        Containers...>>
    : Under_Name<Name, Tuple<Containers...>> {};

// ---------------------------------------------------------------------- //
// Top_Level                                                              //
// ---------------------------------------------------------------------- //

/// Returns all top level types. That is, types that are not contained by
/// others and that don't contain any types themselves .
template <typename>
struct Top_Level : Return_Error<error::Not_A_Tuple> {};

template <>
struct Top_Level<Tuple<>> : Return_Type<Tuple<>> {};

template <
    template <typename...> typename Container,
    typename ...Contents,
    typename ...Rest>
struct Top_Level<Tuple<Container<Contents...>, Rest...>> : Top_Level<Tuple<Rest...>> {};

template <
    typename Element,
    typename ...Rest>
struct Top_Level<Tuple<Element, Rest...>> : Cons<Element, typename Top_Level<Tuple<Rest...>>::Type> {};


// ---------------------------------------------------------------------- //
// Directory                                                              //
// ---------------------------------------------------------------------- //

/// Container for nested packs
template <typename... Elems>
struct Directory
{
    template <template <typename...> typename Container>
    using Get_Under_Name = Under_Name<Container, Tuple<Elems...>>;

    using Get_Top_Level = Top_Level<Tuple<Elems...>>;
};

}

#undef CRANE_HEADER_CONTENTS