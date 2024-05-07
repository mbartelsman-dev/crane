#include "returns.hpp"
#include "checks.hpp"

namespace crane::meta::v1::tests
{

// ---------------------------------------------------------------------- //
// Return_Value                                                           //
// ---------------------------------------------------------------------- //

struct Dummy {};

struct Return_Type_Test_1 : Assert_Equal<
    Return_Type<bool>::Type,
    bool> {};

struct Return_Type_Test_2 : Assert_Not_Equal<
    Return_Type<bool>::Type,
    int> {};

struct Return_Type_Test_3 : Assert_Equal<
    Return_Type<int>::Type,
    int> {};

struct Return_Type_Test_4 : Assert_Equal<
    Return_Type<Dummy>::Type,
    Dummy> {};
}
