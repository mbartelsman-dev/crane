#include "packs.hpp"
#include "checks.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// Type_At                                                                //
// ---------------------------------------------------------------------- //

struct Type_At_Test_1 : Assert_Equal<
    Type_At<0, int, float, char, double>::Type,
    int >{};

struct Type_At_Test_2 : Assert_Equal<
    Type_At<1, int, float, char, double>::Type,
    float >{};

struct Type_At_Test_3 : Assert_Equal<
    Type_At<2, int, float, char, double>::Type,
    char >{};

struct Type_At_Test_4 : Assert_Equal<
    Type_At<3, int, float, char, double>::Type,
    double >{};

struct Type_At_Test_5 : Assert_Equal<
    Type_At<0>::Error, error::Out_Of_Bounds >{};


// ---------------------------------------------------------------------- //
// Pack_Length                                                            //
// ---------------------------------------------------------------------- //

struct Pack_Length_Test_1 : Assert<
    Pack_Length<>{} == 0 >{};

struct Pack_Length_Test_2 : Assert<
    Pack_Length<int>{} == 1 >{};

struct Pack_Length_Test_3 : Assert<
    Pack_Length<int, int>{} == 2 >{};

struct Pack_Length_Test_4 : Assert<
    Pack_Length<int, char, void>{} == 3 >{};

struct Pack_Length_Test_5 : Assert<
    Pack_Length<int, char, int, float>{} == 4 >{};

}


