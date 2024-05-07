#include "conditionals.hpp"
#include "checks.hpp"
#include "booleans.hpp"
#include "values.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// If                                                                     //
// ---------------------------------------------------------------------- //

struct If_Test_1 : Assert<
    If<true, True, False>::Type{} == true >{};

struct If_Test_2 : Assert<
    If<false, True, False>::Type{} == false >{};

struct If_Test_3 : Assert_Equal<
    If<(4 > 3), int, char>::Type,
    int >{};

struct If_Test_4 : Assert_Equal<
    If<(4 < 3), int, char>::Type,
    char >{};

struct If_Test_5 : Assert_Not_Equal<
    If<(4 > 3), int, char>::Type,
    char >{};

struct If_Test_6 : Assert_Not_Equal<
    If<(4 < 3), int, char>::Type,
    int >{};


// ---------------------------------------------------------------------- //
// Switch Case                                                            //
// ---------------------------------------------------------------------- //

struct Switch_Test_1 : Assert_Equal<
    Switch<
        Case<true, int>,
        Case<true, float>,
        Case<true, char>>
    ::Type,
    int >{};

struct Switch_Test_2 : Assert_Equal<
    Switch<
        Case<false, int>,
        Case<true, float>,
        Case<true, char>>
    ::Type,
    float >{};

struct Switch_Test_3 : Assert_Equal<
    Switch<
        Case<false, int>,
        Case<false, float>,
        Case<true, char>>
    ::Type,
    char >{};

struct Switch_Test_4 : Assert_Equal<
    Switch<
        Case<true, int>,
        Case<false, float>,
        Case<false, char>>
    ::Type,
    int >{};

struct Switch_Test_5 : Assert_Equal<
    Switch<
        Case<false, int>>
    ::Error,
    error::No_Matching_Case>{};

struct Switch_Test_6 : Assert_Equal<
    Switch<
        Case<false, int>,
        Default<short>>
    ::Type,
    short >{};

struct Switch_Test_7 : Assert_Equal<
    Switch<
        Default<short>,
        Case<true, int>>
    ::Type,
    int >{};

struct Switch_Test_8 : Assert_Equal<
    Switch<
        Default<short>,
        Case<false, int>>
    ::Type,
    short >{};

struct Switch_Test_9 : Assert_Equal<
    Switch<Default<short>>::Type,
    short >{};

struct Switch_Test_10 : Assert_Equal<
    Switch<>::Error,
    error::No_Matching_Case>{};
}


