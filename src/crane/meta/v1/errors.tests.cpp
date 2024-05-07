#include "errors.hpp"
#include "checks.hpp"

namespace crane::meta::v1::tests
{

// ---------------------------------------------------------------------- //
// Return_Error                                                           //
// ---------------------------------------------------------------------- //

struct Dummy_Error;
struct Dummy {};

struct Return_Error_Test_1 : Assert_Equal<
    Return_Error<Dummy_Error>::Error,
    Dummy_Error> {};

struct Return_Error_Test_2 : Assert_Equal<
    Return_Error<Dummy>::Error,
    Dummy> {};

struct Return_Error_Test_3 : Assert_Not_Equal<
    Return_Error<Dummy>::Error,
    Dummy_Error> {};
}

