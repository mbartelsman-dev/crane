#include "values.hpp"
#include "checks.hpp"
#include "booleans.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// Return_Value                                                           //
// ---------------------------------------------------------------------- //

struct Return_Value_Test_1 : Assert<
    Return_Value<bool, true>::Value == true> {};

struct Return_Value_Test_2 : Assert<
    Return_Value<bool, false>::Value == false> {};

struct Return_Value_Test_3 : Assert<
    Return_Value<float, 0.8f>::Value == 0.8f> {};

struct Return_Value_Test_4 : Assert<
    Return_Value<int, 5>::Value == 5> {};

struct Return_Value_Test_5 : Assert<
    Return_Value<float, 0.8f>{ } == 0.8f> {};

// ---------------------------------------------------------------------- //
// True                                                                   //
// ---------------------------------------------------------------------- //

struct True_Test_1 : Assert<
    True::Value == true> {};

struct True_Test_2 : Assert<
    True{ } == true> {};


// ---------------------------------------------------------------------- //
// False                                                                  //
// ---------------------------------------------------------------------- //

struct False_Test_1 : Assert<
    False::Value == false> {};

struct False_Test_2 : Assert<
    False{ } == false> {};
}
