#include "checks.hpp"
#include "booleans.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// Not                                                                    //
// ---------------------------------------------------------------------- //

struct Not_Test_1 : Assert_Equal<
    Not<True>::Type,
    False >{};

struct Not_Test_2 : Assert_Equal<
    Not<False>::Type,
    True >{};


// ---------------------------------------------------------------------- //
// And                                                                    //
// ---------------------------------------------------------------------- //

struct And_Test_1 : Assert_Equal<
    And<True, True>::Type,
    True >{};

struct And_Test_2 : Assert_Equal<
    And<True, False>::Type,
    False >{};

struct And_Test_3 : Assert_Equal<
    And<False, True>::Type,
    False >{};

struct And_Test_4 : Assert_Equal<
    And<False, False>::Type,
    False >{};


// ---------------------------------------------------------------------- //
// Or                                                                     //
// ---------------------------------------------------------------------- //

struct Or_Test_1 : Assert_Equal<
    Or<True, True>::Type,
    True >{};

struct Or_Test_2 : Assert_Equal<
    Or<True, False>::Type,
    True >{};

struct Or_Test_3 : Assert_Equal<
    Or<False, True>::Type,
    True >{};

struct Or_Test_4 : Assert_Equal<
    Or<False, False>::Type,
False >{};


// ---------------------------------------------------------------------- //
// Xor                                                                    //
// ---------------------------------------------------------------------- //

struct Xor_Test_1 : Assert_Equal<
    Xor<True, True>::Type,
    False >{};

struct Xor_Test_2 : Assert_Equal<
    Xor<True, False>::Type,
    True >{};

struct Xor_Test_3 : Assert_Equal<
    Xor<False, True>::Type,
    True >{};

struct Xor_Test_4 : Assert_Equal<
    Xor<False, False>::Type,
    False >{};
}
