#include "associative_packs.hpp"
#include "checks.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// Dictionary                                                             //
// ---------------------------------------------------------------------- //

//
// Get_Entries_Of
// ------------------------------------------------------------------- //

struct Dictionary_Get_All_Entries_Test_1 : Assert_Equal<
    Dictionary<>::Get_Entries_Of<int>::Type,
Tuple<>>{};

struct Dictionary_Get_All_Entries_Test_2 : Assert_Equal<
    Entries_Of<int, Entry<int, double>>::Type,
    Tuple<Entry<int, double>>>{};

struct Dictionary_Get_All_Entries_Test_3 : Assert_Equal<
    Dictionary<
        Tuple<char[2], double>,
        Entry<char[1], int>,
        Tuple<char[2], long>,
        Entry<char[3], float>>::Get_Entries_Of<char[2]>::Type,
    Tuple<
        Entry<char[2], double>,
        Entry<char[2], long>> >{};

struct Dictionary_Get_All_Entries_Test_4 : Assert_Equal<
    Dictionary<
        Entry<char[2], double>,
        Entry<char[1], int>,
        Entry<char[2], long>,
        Entry<char[3], float>>::Get_Entries_Of<char[5]>::Type,
    Tuple<> >{};

//
// Get_Values_Of
// ------------------------------------------------------------------- //

struct Dictionary_Get_All_Test_1 : Assert_Equal<
    Dictionary<>::Get_Values_Of<int>::Type,
    Tuple<>>{};

struct Dictionary_Get_All_Test_2 : Assert_Equal<
    Dictionary<
        Entry<int, double>>::Get_Values_Of<int>::Type,
    Tuple<double>>{};

struct Dictionary_Get_All_Test_3 : Assert_Equal<
    Dictionary<
        Entry<char[2], double>,
        Entry<char[1], int>,
        Entry<char[2], long>,
        Entry<char[3], float>>::Get_Values_Of<char[2]>::Type,
    Tuple<double, long> >{};

struct Dictionary_Get_All_Test_4 : Assert_Equal<
    Dictionary<
        Entry<char[2], double>,
        Entry<char[1], int>,
        Entry<char[2], long>,
        Entry<char[3], float>>::Get_Values_Of<char[5]>::Type,
    Tuple<> >{};

//
// Get_Entry_Of
// ------------------------------------------------------------------- //

struct Dictionary_Get_Entry_Test_1 : Assert_Equal<
    Dictionary<>::Get_Entry_Of<int>::Error,
    error::Out_Of_Bounds>{};

struct Dictionary_Get_Entry_Test_2 : Assert_Equal<
    Dictionary<
        Entry<int, double>>::Get_Entry_Of<int>::Type,
    Entry<int, double>>{};

struct Dictionary_Get_Entry_Test_3 : Assert_Equal<
    Dictionary<
        Entry<char[2], double>,
        Entry<char[1], int>,
        Entry<char[2], long>,
        Entry<char[3], float>>::Get_Entry_Of<char[2]>::Type,
    Entry<char[2], double>>{};

struct Dictionary_Get_Entry_Test_4 : Assert_Equal<
    Dictionary<
        Entry<char[2], double>,
        Entry<char[1], int>,
        Entry<char[2], long>,
        Entry<char[3], float>>::Get_Entry_Of<char[5]>::Error,
    error::Out_Of_Bounds >{};

}


