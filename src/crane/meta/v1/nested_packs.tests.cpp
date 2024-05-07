
#include "checks.hpp"
#include "nested_packs.hpp"

namespace crane::meta::v1::tests
{

template <typename...> struct Cont_1;
template <typename...> struct Cont_2;
template <typename...> struct Cont_3;
template <typename...> struct Cont_4;

// ---------------------------------------------------------------------- //
// Under_Name                                                             //
// ---------------------------------------------------------------------- //

struct Under_Name_Test_1 : Assert_Equal<
    Under_Name<Cont_2, Tuple<>>::Type,
    Tuple<>> {};

struct Under_Name_Test_2 : Assert_Equal<
    Under_Name<
        Cont_1,
        Tuple<
            Cont_1<double>,
            Cont_2<char, char>,
            Cont_1<int, int>,
            Cont_3<float, float>>>::Type,
    Tuple<double, int, int>> {};

struct Under_Name_Test_3 : Assert_Equal<
    Under_Name<
        Cont_2,
        Tuple<
            Cont_1<int, int>,
            Cont_2<>,
            Cont_3<float, float>>>::Type,
    Tuple<>> {};

struct Under_Name_Test_4 : Assert_Equal<
    Under_Name<
        Cont_4,
        Tuple<
            Cont_1<int, int>,
            Cont_2<char, char>,
            Cont_3<float, float>>>::Type,
    Tuple<>> {};

struct Under_Name_Test_5 : Assert_Equal<
    Under_Name<Cont_1, Cont_1<float>>::Error,
    error::Not_A_Tuple> {};


// ---------------------------------------------------------------------- //
// Top_Level                                                              //
// ---------------------------------------------------------------------- //

struct Top_Level_Test_1 : Assert_Equal<
    Top_Level<Tuple<Cont_1<>>>::Type,
    Tuple<>> {};

struct Top_Level_Test_2 : Assert_Equal<
    Top_Level<Tuple<Cont_1<int>, Cont_2<char>>>::Type,
    Tuple<>> {};

struct Top_Level_Test_3 : Assert_Equal<
    Top_Level<Tuple<
        long[1],
        long[2],
        long[3]>>
    ::Type,
    Tuple<long[1], long[2], long[3]>> {};

struct Top_Level_Test_4 : Assert_Equal<
    Top_Level<Tuple<
        long[1],
        Cont_1<int>,
        long[2],
        Cont_2<char>,
        long[3]>>
    ::Type,
    Tuple<long[1], long[2], long[3]>> {};

struct Top_Level_Test_5 : Assert_Equal<
    Top_Level<Tuple<>>::Type,
    Tuple<>> {};

struct Top_Level_Test_6 : Assert_Equal<
    Top_Level<Cont_1<>>::Error,
    error::Not_A_Tuple> {};


// ---------------------------------------------------------------------- //
// Directory                                                              //
// ---------------------------------------------------------------------- //

//
// Get_Under_Name
// ------------------------------------------------------------------- //

struct Directory_Get_Under_Name_Test_1 : Assert_Equal<
    Directory<>
    ::Get_Under_Name<Cont_1>
    ::Type,
    Tuple<>> {};

struct Directory_Get_Under_Name_Test_2 : Assert_Equal<
    Directory<
        Cont_1<double>,
        Cont_2<char, char>,
        Cont_1<int, int>,
        Cont_3<float, float>>
    ::Get_Under_Name<Cont_1>
    ::Type,
    Tuple<double, int, int>> {};

struct Directory_Get_Under_Name_Test_3 : Assert_Equal<
    Directory<
        Cont_1<int, int>,
        Cont_2<>,
        Cont_3<float, float>>
    ::Get_Under_Name<Cont_2>
    ::Type,
    Tuple<>> {};

struct Directory_Get_Under_Name_Test_4 : Assert_Equal<
    Directory<
        Cont_1<int, int>,
        Cont_2<char, char>,
        Cont_3<float, float>>
    ::Get_Under_Name<Cont_4>
    ::Type,
    Tuple<>> {};

//
// Get_Top_Level
// ------------------------------------------------------------------- //

struct Directory_Get_Top_Level_Test_1 : Assert_Equal<
    Directory<Cont_1<>>::Get_Top_Level::Type,
    Tuple<>> {};

struct Directory_Get_Top_Level_Test_2 : Assert_Equal<
    Directory<Cont_1<int>, Cont_2<char>>::Get_Top_Level::Type,
    Tuple<>> {};

struct Directory_Get_Top_Level_Test_3 : Assert_Equal<
    Directory<
        long[1],
        long[2],
        long[3]>
    ::Get_Top_Level::Type,
    Tuple<long[1], long[2], long[3]>> {};

struct Directory_Get_Top_Level_Test_4 : Assert_Equal<
    Directory<
        long[1],
        Cont_1<int>,
        long[2],
        Cont_2<char>,
        long[3]>
    ::Get_Top_Level::Type,
    Tuple<long[1], long[2], long[3]>> {};

struct Directory_Get_Top_Level_Test_5 : Assert_Equal<
    Directory<>::Get_Top_Level::Type,
    Tuple<>> {};

}
