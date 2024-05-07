
#pragma once
#define CRANE_HEADER_CONTENTS

#include "returns.hpp"
#include "tuples.hpp"

namespace crane::meta::v1
{

namespace error
{
    struct Key_Not_Found;
}

// ---------------------------------------------------------------------- //
// Entry                                                                  //
// ---------------------------------------------------------------------- //

/// Dictionary entry storing a key and a value
template <typename TKey, typename Value>
struct Entry : Tuple<TKey, Value>
{
    using Key = TKey;
    using Value_T = Value;
};


// ---------------------------------------------------------------------- //
// Key_T                                                                  //
// ---------------------------------------------------------------------- //

template <typename>
struct Key_T;

template <typename TKey, typename Value>
struct Key_T<Tuple<TKey, Value>> : Return_Type<TKey> {};

template <typename TKey, typename Value>
struct Key_T<Entry<TKey, Value>> : Return_Type<TKey> {};


// ---------------------------------------------------------------------- //
// Value_T                                                                //
// ---------------------------------------------------------------------- //

template <typename>
struct Value_T;

template <typename Key, typename TValue>
struct Value_T<Tuple<Key, TValue>> : Return_Type<TValue> {};

template <typename Key, typename TValue>
struct Value_T<Entry<Key, TValue>> : Return_Type<TValue> {};


// ---------------------------------------------------------------------- //
// Entries_Of                                                             //
// ---------------------------------------------------------------------- //

template <typename, typename...>
struct Entries_Of;

template <typename Key>
struct Entries_Of<Key> : Return_Type<Tuple<>> {};

template <typename Key, typename Value, typename... Entries>
struct Entries_Of<Key, Entry<Key, Value>, Entries...> :
Cons<Entry<Key, Value>, typename Entries_Of<Key, Entries...>::Type> {};

template <typename Key, typename Value, typename... Entries>
struct Entries_Of<Key, Tuple<Key, Value>, Entries...> :
    Cons<Entry<Key, Value>, typename Entries_Of<Key, Entries...>::Type> {};

template <typename Key, typename Entry, typename... Entries>
struct Entries_Of<Key, Entry, Entries...> : Entries_Of<Key, Entries...> {};


// ---------------------------------------------------------------------- //
// Values_Of                                                              //
// ---------------------------------------------------------------------- //

template <typename Key, typename ...Entries>
struct Values_Of : Map<Value_T, typename Entries_Of<Key, Entries...>::Type> {};


// ---------------------------------------------------------------------- //
// Entry_Of                                                               //
// ---------------------------------------------------------------------- //

template <typename Key, typename ...Entries>
struct Entry_Of : Head<typename Entries_Of<Key, Entries...>::Type> {};


// ---------------------------------------------------------------------- //
// Value_Of                                                               //
// ---------------------------------------------------------------------- //

template <typename Key, typename ...Entries>
struct Value_Of : Head<typename Values_Of<Key, Entries...>::Type> {};


// ---------------------------------------------------------------------- //
// Dictionary                                                             //
// ---------------------------------------------------------------------- //

/// Dictionary storing key-value pairs as entries
template <typename... Entries>
struct Dictionary
{
    /// Returns the first entry that has the provided key
    template <typename Key>
    using Get_Entries_Of = Entries_Of<Key, Entries...>;

    /// Returns all values associated with the provided key
    template <typename Key>
    using Get_Values_Of = Values_Of<Key, Entries...>;

    /// Returns the first entry that has the provided key
    template <typename Key>
    using Get_Entry_Of = Entry_Of<Key, Entries...>;

    /// Returns the first value associated with the provided key
    template <typename Key>
    using Get_Value_Of = Value_Of<Key, Entries...>;

    /// Returns all the keys stored in the dictionary
    using Keys = Map<Key_T, Tuple<Entries...>>;

    /// Returns all the values stored in the dictionary
    using Values = Map<Value_T, Tuple<Entries...>>;
};

}
#undef CRANE_HEADER_CONTENTS