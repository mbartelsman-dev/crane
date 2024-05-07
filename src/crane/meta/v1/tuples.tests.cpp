#include "tuples.hpp"
#include "checks.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// Tuple                                                                  //
// ---------------------------------------------------------------------- //

struct Tuple_Size_Test_1 : Assert<
    Tuple<int, float, char, double>::Size == 4> {};

struct Tuple_Size_Test_2 : Assert<
    Tuple<void, void>::Size == 2> {};

struct Tuple_Size_Test_3 : Assert<
    Tuple<>::Size == 0> {};

struct Tuple_Get_Test_1 : Assert_Equal<
    Tuple<int, float, char, double>::Get<0>::Type,
    int> {};

struct Tuple_Get_Test_2 : Assert_Equal<
    Tuple<int, float, char, double>::Get<1>::Type,
    float> {};

struct Tuple_Get_Test_3 : Assert_Equal<
    Tuple<int, float, char, double>::Get<2>::Type,
    char> {};

struct Tuple_Get_Test_4 : Assert_Equal<
    Tuple<int, float, char, double>::Get<3>::Type,
    double> {};

struct Tuple_Get_Test_5 : Assert_Equal<
    Tuple<int, float, char, double>::Get<4>::Error,
    error::Out_Of_Bounds> {};

struct Tuple_Get_Test_6 : Assert_Equal<
    Tuple<>::Get<0>::Error,
    error::Out_Of_Bounds> {};

struct Tuple_Get_Test_7 : Assert_Equal<
    Tuple<>::Get<5>::Error,
    error::Out_Of_Bounds> {};


// ---------------------------------------------------------------------- //
// Empty                                                                  //
// ---------------------------------------------------------------------- //

struct Empty_Test_1 : Assert_Equal<
    Empty<Tuple<>>::Type,
    True> {};

struct Empty_Test_2 : Assert_Not_Equal<
    Empty<Tuple<>>::Type,
    False> {};

struct Empty_Test_3 : Assert_Equal<
    Empty<Tuple<void>>::Type,
    False> {};

struct Empty_Test_4 : Assert_Equal<
    Empty<Tuple<int, bool>>::Type,
    False> {};

struct Empty_Test_5 : Assert_Not_Equal<
    Empty<Tuple<int>>::Type,
    True> {};


// ---------------------------------------------------------------------- //
// Head                                                                   //
// ---------------------------------------------------------------------- //

struct Head_Test_1 : Assert_Equal<
    Head<Tuple<int, float, char, double>>::Type,
    int >{};

struct Head_Test_2 : Assert_Equal<
    Head<Tuple<float, char, double>>::Type,
    float >{};

struct Head_Test_3 : Assert_Equal<
    Head<Tuple<>>::Error,
    error::Out_Of_Bounds >{};


// ---------------------------------------------------------------------- //
// Tail                                                                   //
// ---------------------------------------------------------------------- //

struct Tail_Test_1 : Assert_Equal<
    Tail<Tuple<int, float, char, double>>::Type,
    Tuple<float, char, double> >{};

struct Tail_Test_2 : Assert_Equal<
    Tail<Tuple<float, char, double>>::Type,
    Tuple<char, double> >{};

struct Tail_Test_3 : Assert_Equal<
    Tail<Tuple<>>::Error,
    error::Out_Of_Bounds >{};


// ---------------------------------------------------------------------- //
// Cons                                                                   //
// ---------------------------------------------------------------------- //

struct Cons_Test_1 : Assert_Equal<
    Cons<int, Tuple<>>::Type,
    Tuple<int> >{};

struct Cons_Test_2 : Assert_Equal<
    Cons<int, Tuple<float>>::Type,
Tuple<int, float> >{};

struct Cons_Test_3 : Assert_Equal<
    Cons<int, Tuple<float, char>>::Type,
    Tuple<int, float, char> >{};

struct Cons_Test_4 : Assert_Equal<
    Cons<int,
        Cons<float,
            Cons<char, Tuple<>>
            ::Type>
        ::Type>
    ::Type,
    Tuple<int, float, char> >{};


// ---------------------------------------------------------------------- //
// Reverse                                                                //
// ---------------------------------------------------------------------- //

struct Reverse_Test_1 : Assert_Equal<
    Reverse<Tuple<>>::Type,
    Tuple<> >{};

struct Reverse_Test_2 : Assert_Equal<
    Reverse<Tuple<int>>::Type,
    Tuple<int> >{};

struct Reverse_Test_3 : Assert_Equal<
    Reverse<Tuple<float, char>>::Type,
    Tuple<char, float> >{};

struct Reverse_Test_4 : Assert_Equal<
    Reverse<Tuple<char[1], char[2], char[3], char[4], char[5]>>::Type,
    Tuple<char[5], char[4], char[3], char[2], char[1]> >{};

struct Reverse_Test_5 : Assert_Equal<
    Reverse<Reverse<Tuple<char[1], char[2], char[3], char[4]>>::Type>::Type,
    Tuple<char[1], char[2], char[3], char[4]> >{};


// ---------------------------------------------------------------------- //
// Concat                                                                 //
// ---------------------------------------------------------------------- //

struct Concat_Test_1 : Assert_Equal<
    Concat<Tuple<>, Tuple<float>>::Type,
    Tuple<float> >{};

struct Concat_Test_2 : Assert_Equal<
    Concat<Tuple<int>, Tuple<>>::Type,
    Tuple<int> >{};

struct Concat_Test_3 : Assert_Equal<
    Concat<Tuple<int>, Tuple<float>>::Type,
    Tuple<int, float> >{};

struct Concat_Test_4 : Assert_Equal<
    Concat<Tuple<int>, Tuple<float>, Tuple<char>>::Type,
    Tuple<int, float, char> >{};

struct Concat_Test_5 : Assert_Equal<
    Concat<Tuple<int>, Tuple<float, Tuple<char>>>::Type,
    Tuple<int, float, Tuple<char>> >{};


// ---------------------------------------------------------------------- //
// Flatten                                                                //
// ---------------------------------------------------------------------- //

struct Flatten_Test_1 : Assert_Equal<
    Flatten<Tuple<int, char, float>>::Type,
    Tuple<int, char, float> >{};

struct Flatten_Test_2 : Assert_Equal<
    Flatten<Tuple<Tuple<>, Tuple<float>>>::Type,
    Tuple<float> >{};

struct Flatten_Test_3 : Assert_Equal<
    Flatten<Tuple<Tuple<int>, Tuple<>>>::Type,
    Tuple<int> >{};

struct Flatten_Test_4 : Assert_Equal<
    Flatten<Tuple<Tuple<int>, Tuple<float>>>::Type,
    Tuple<int, float> >{};

struct Flatten_Test_5 : Assert_Equal<
    Flatten<Tuple<int, Tuple<float>>>::Type,
    Tuple<int, float> >{};

struct Flatten_Test_6 : Assert_Equal<
    Flatten<Tuple<Tuple<int>, float>>::Type,
    Tuple<int, float> >{};

struct Flatten_Test_7 : Assert_Equal<
    Flatten<Tuple<double, Tuple<int>, Tuple<float, Tuple<char>>>>::Type,
    Tuple<double, int, float, Tuple<char>> >{};

// ---------------------------------------------------------------------- //
// Map                                                                    //
// ---------------------------------------------------------------------- //

struct Map_Test_1 : Assert_Equal<
    Map<Not, Tuple<>>::Type,
    Tuple<> >{};

struct Map_Test_2 : Assert_Equal<
    Map<Not, Tuple<True, False, True>>::Type,
    Tuple<False, True, False> >{};

struct Map_Test_3 : Assert_Equal<
    Map<Return_Type, Tuple<True, False, True>>::Type,
Tuple<True, False, True> >{};


// ---------------------------------------------------------------------- //
// Filter                                                                 //
// ---------------------------------------------------------------------- //

template <typename = void>  struct Is_True          : Return_Type<False> {};
template <>                 struct Is_True<True>    : Return_Type<True> {};

struct Filter_Test_1 : Assert_Equal<
    Filter<Is_True, Tuple<True, int, False, True, False>>::Type,
    Tuple<True, True>> {};

struct Filter_Test_2 : Assert_Equal<
    Filter<Is_True, Tuple<False, True, True, False, True>>::Type,
    Tuple<True, True, True>> {};

struct Filter_Test_3 : Assert_Equal<
    Filter<Is_True, Tuple<True, True, True, True, int>>::Type,
    Tuple<True, True, True, True>> {};

struct Filter_Test_4 : Assert_Equal<
    Filter<Is_True, Tuple<False, int, False>>::Type,
    Tuple<>> {};

struct Filter_Test_5 : Assert_Equal<
    Filter<Is_True, Tuple<>>::Type,
    Tuple<>> {};


// ---------------------------------------------------------------------- //
// Count                                                                  //
// ---------------------------------------------------------------------- //

struct Count_Test_1 : Assert_Equal<
    Count<Is_True, Tuple<True, int, False, True, False>>::Type,
    Integer<2>> {};

struct Count_Test_2 : Assert_Equal<
    Count<Is_True, Tuple<False, True, True, False, True>>::Type,
    Integer<3>> {};

struct Count_Test_3 : Assert_Equal<
    Count<Is_True, Tuple<True, True, True, True, int>>::Type,
    Integer<4>> {};

struct Count_Test_4 : Assert_Equal<
    Count<Is_True, Tuple<False, int, False>>::Type,
    Integer<0>> {};

struct Count_Test_5 : Assert_Equal<
    Count<Is_True, Tuple<>>::Type,
    Integer<0>> {};
}

