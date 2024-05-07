#include <type_traits>

#include "checks.hpp"

namespace crane::meta::v1::tests
{

struct Dummy {};
struct Dummy_2 {};

template <typename>
struct Dummy_Template;

template <typename>
struct Dummy_Template_2;

template <template <typename> typename>
struct Dummy_Template_Template;


// ---------------------------------------------------------------------- //
// Assert_Equal                                                           //
// ---------------------------------------------------------------------- //

struct Assert_Equal_Test_1 : Assert_Equal<int, int> {};
struct Assert_Equal_Test_2 : Assert_Equal<Dummy, Dummy> {};

struct Assert_Equal_Test_3 : Assert_Equal<
    Dummy_Template<int>,
    Dummy_Template<int>> {};

struct Assert_Equal_Test_4 : Assert_Equal<
    Dummy_Template_Template<Dummy_Template>,
    Dummy_Template_Template<Dummy_Template>> {};


// ---------------------------------------------------------------------- //
// Assert_Not_Equal                                                       //
// ---------------------------------------------------------------------- //

struct Assert_Not_Equal_Test_1 : Assert_Not_Equal<int, bool> {};
struct Assert_Not_Equal_Test_2 : Assert_Not_Equal<Dummy, Dummy_2> {};

struct Assert_Not_Equal_Test_3 : Assert_Not_Equal<
    Dummy_Template<int>,
    Dummy_Template<bool>> {};

struct Assert_Not_Equal_Test_4 : Assert_Not_Equal<
    Dummy_Template_Template<Dummy_Template>,
    Dummy_Template_Template<Dummy_Template_2>> {};

struct Assert_Not_Equal_Test_5 : Assert_Not_Equal<
    Dummy,
    Dummy_Template<bool>> {};

struct Assert_Not_Equal_Test_6 : Assert_Not_Equal<
    Dummy_Template<bool>,
    Dummy_Template_Template<Dummy_Template>> {};


// ---------------------------------------------------------------------- //
// Assert                                                                 //
// ---------------------------------------------------------------------- //

struct Assert_Test_1 : Assert<true> {};
struct Assert_Test_3 : Assert<0 != 1> {};
struct Assert_Test_4 : Assert<(3 < 17)> {};
struct Assert_Test_5 : Assert<std::is_same_v<int, int>> {};

}


