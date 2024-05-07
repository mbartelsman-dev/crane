
#pragma once
#define CRANE_HEADER_CONTENTS

#include "booleans.hpp"
#include "conditionals.hpp"
#include "integers.hpp"
#include "packs.hpp"

namespace crane::meta::v1
{

namespace error
{
    struct Tuple_Is_Empty;
}

// ---------------------------------------------------------------------- //
// Tuple                                                                  //
// ---------------------------------------------------------------------- //

/// N-tuple template container
template <typename ...Ts>
struct Tuple
{
    /// The length of the tuple
    static constexpr unsigned long long Size = Pack_Length<Ts...>::Value;

    /// Retrieve the element at the specified index
    template <unsigned long long Index>
    using Get = Type_At<Index, Ts...>;

    template <template <typename...> typename Container>
    using As = Return_Type<Container<Ts...>>; // TODO tests
};


// ---------------------------------------------------------------------- //
// As_Tuple                                                               //
// ---------------------------------------------------------------------- //

/// Returns True if the tuple is empty
template <typename Container>
struct As_Tuple;

template <typename Element>
struct As_Tuple : Return_Type<Tuple<Element>> {};

template <template <typename...> typename Container>
struct As_Tuple<Container<>> : Return_Type<Tuple<>> {};

template <template <typename...> typename Container, typename ...Contents>
struct As_Tuple<Container<Contents...>> : Return_Type<Tuple<Contents...>> {};


// ---------------------------------------------------------------------- //
// Empty                                                                  //
// ---------------------------------------------------------------------- //

/// Returns True if the tuple is empty
template <typename>
struct Empty : Return_Type<False> {};

template <>
struct Empty<Tuple<>> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// Head                                                                   //
// ---------------------------------------------------------------------- //

/// Returns the element at the head of the tuple
template <typename ...Tuple>
struct Head;

template <>
struct Head<Tuple<>> : Return_Error<error::Out_Of_Bounds> { };

template <typename TupleHead, typename ...TupleTail>
struct Head<Tuple<TupleHead, TupleTail...>> : Return_Type<TupleHead> { };


// ---------------------------------------------------------------------- //
// Tail                                                                   //
// ---------------------------------------------------------------------- //

/// Returns the tail of the tuple.
/// Returns an empty tuple if the input only has one element
template <typename ...Tuple>
struct Tail;

template <>
struct Tail<Tuple<>> : Return_Error<error::Out_Of_Bounds> { };

template <typename TupleHead, typename ...TupleTail>
struct Tail<Tuple<TupleHead, TupleTail...>> : Return_Type<Tuple<TupleTail...>> { };


// ---------------------------------------------------------------------- //
// Cons                                                                   //
// ---------------------------------------------------------------------- //

/// Prepends an element to a tuple
template <typename Head, typename ...Tail>
struct Cons;

template <typename Head, typename ...Tail>
struct Cons<Head, Tuple<Tail...>> : Return_Type<Tuple<Head, Tail...>> { };


// ---------------------------------------------------------------------- //
// Reverse                                                                //
// ---------------------------------------------------------------------- //

/// Reverses a tuple
template <typename T>
struct Reverse
{
    template <typename Orig, typename Rev>
    struct Reverse_Impl;

    template <typename Rev>
    struct Reverse_Impl<Tuple<>, Rev> : Return_Type<Rev> {};

    template <typename O, typename ...Os, typename ...Rs>
    struct Reverse_Impl<Tuple<O, Os...>, Tuple<Rs...>> : Reverse_Impl<Tuple<Os...>, Tuple<O, Rs...>> {};

    using Type = typename Reverse_Impl<T, Tuple<>>::Type;
};


// ---------------------------------------------------------------------- //
// Concat                                                                 //
// ---------------------------------------------------------------------- //

/// Concatenates the passed tuples
template <typename ...Tuples>
struct Concat;

template <>
struct Concat<Tuple<>> : Return_Type<Tuple<>> { };

template <typename ...Tuples>
struct Concat<Tuple<>, Tuples...> : Concat<Tuples...> { };

template <typename Head, typename ...Tail, typename ...Tuples>
struct Concat<Tuple<Head, Tail...>, Tuples...> :
    Cons<Head, typename Concat<Tuple<Tail...>, Tuples...>::Type> { };


// ---------------------------------------------------------------------- //
// Flatten                                                                //
// ---------------------------------------------------------------------- //

/// Concatenates a tuple's contained tuples with its elements, reducing the
/// tuple's order by 1.
template <typename Tuple>
struct Flatten;

template <>
struct Flatten<Tuple<>> : Return_Type<Tuple<>> { };

template <typename ...Tuples>
struct Flatten<Tuple<Tuple<>, Tuples...>> : Flatten<Tuple<Tuples...>> { };

template <typename Elem, typename ...Tuples>
struct Flatten<Tuple<Elem, Tuples...>> :
    Cons<Elem, typename Flatten<Tuple<Tuples...>>::Type> { };

template <typename Head, typename ...Tail, typename ...Tuples>
struct Flatten<Tuple<Tuple<Head, Tail...>, Tuples...>> :
    Cons<Head, typename Flatten<Tuple<Tuple<Tail...>, Tuples...>>::Type> { };


// ---------------------------------------------------------------------- //
// Map                                                                    //
// ---------------------------------------------------------------------- //

/// Maps the values of a tuple according to the provided unary meta function
template <template <typename> typename Func, typename List>
struct Map;

template <template <typename> typename Func>
struct Map<Func, Tuple<>> : Return_Type<Tuple<>> {};

template <template <typename> typename Func, typename Head, typename ...Tail>
struct Map<Func, Tuple<Head, Tail...>> :
Cons<typename Func<Head>::Type, typename Map<Func, Tuple<Tail...>>::Type> {};


// ---------------------------------------------------------------------- //
// Reduce                                                                 //
// ---------------------------------------------------------------------- //

template <template <typename, typename> typename Func, typename Seed, typename List>
struct Reduce;

template <template <typename, typename> typename Func, typename Seed>
struct Reduce<Func, Seed, Tuple<>> : Return_Error<error::Tuple_Is_Empty> {};

template <template <typename, typename> typename Func, typename Seed, typename Val>
struct Reduce<Func, Seed, Tuple<Val>> : Return_Type<typename Func<Seed, Val>::Type> {};

template <template <typename, typename> typename Func, typename Seed, typename Head, typename ...Tail>
struct Reduce<Func, Seed, Tuple<Head, Tail...>> :
    Reduce<Func, typename Func<Seed, Head>::Type, Tuple<Tail...>> {};


// ---------------------------------------------------------------------- //
// Filter                                                                 //
// ---------------------------------------------------------------------- //

template <template <typename> typename Pred, typename List>
struct Filter;

template <template <typename> typename Pred>
struct Filter<Pred, Tuple<>> : Return_Type<Tuple<>> {};

template <template <typename> typename Pred, typename Head, typename ...Tail>
struct Filter<Pred, Tuple<Head, Tail...>> :
    If<Pred<Head>::Type::Value,
        Cons<Head, typename Filter<Pred, Tuple<Tail...>>::Type>,
    Filter<Pred, Tuple<Tail...>>>::Type {};


// ---------------------------------------------------------------------- //
// Count                                                                  //
// ---------------------------------------------------------------------- //

template <template <typename> typename Pred, typename List>
struct Count;

template <template <typename> typename Pred>
struct Count<Pred, Tuple<>> : Return_Type<Integer<0>> {};

template <template <typename> typename Pred, typename Head, typename ...Tail>
struct Count<Pred, Tuple<Head, Tail...>> :
    If<Pred<Head>::Type::Value,
        Succ<typename Count<Pred, Tuple<Tail...>>::Type>,
        Count<Pred, Tuple<Tail...>>>::Type {};

}

#undef CRANE_HEADER_CONTENTS