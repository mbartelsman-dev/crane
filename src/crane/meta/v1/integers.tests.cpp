#include "checks.hpp"
#include "integers.hpp"

namespace crane::meta::v1::tests
{
// ---------------------------------------------------------------------- //
// Neg                                                                    //
// ---------------------------------------------------------------------- //

struct Neg_Test_1 : Assert_Equal<
    Neg<Integer<3>>::Type,
    Integer<(-3)> >{};

struct Neg_Test_2 : Assert_Equal<
    Neg<Integer<(-84)>>::Type,
Integer<84> >{};


// ---------------------------------------------------------------------- //
// Add                                                                    //
// ---------------------------------------------------------------------- //

struct Add_Test_1 : Assert_Equal<
    Add<Integer<7>, Integer<4>>::Type,
    Integer<11> >{};

struct Add_Test_2 : Assert_Equal<
    Add<Integer<0>, Integer<3>>::Type,
    Integer<3> >{};

struct Add_Test_3 : Assert_Equal<
    Add<Integer<6>, Integer<0>>::Type,
    Integer<6> >{};

struct Add_Test_4 : Assert_Equal<
    Add<Integer<3>, Integer<(-3)>>::Type,
    Integer<0> >{};


// ---------------------------------------------------------------------- //
// Sub                                                                    //
// ---------------------------------------------------------------------- //

struct Sub_Test_1 : Assert_Equal<
    Sub<Integer<7>, Integer<4>>::Type,
    Integer<3> >{};

struct Sub_Test_2 : Assert_Equal<
    Sub<Integer<4>, Integer<7>>::Type,
    Integer<-3> >{};

struct Sub_Test_3 : Assert_Equal<
    Sub<Integer<6>, Integer<0>>::Type,
    Integer<6> >{};

struct Sub_Test_4 : Assert_Equal<
    Sub<Integer<3>, Integer<(-3)>>::Type,
Integer<6> >{};


// ---------------------------------------------------------------------- //
// Mul                                                                    //
// ---------------------------------------------------------------------- //

struct Mul_Test_1 : Assert_Equal<
    Mul<Integer<7>, Integer<4>>::Type,
    Integer<28> >{};

struct Mul_Test_2 : Assert_Equal<
    Mul<Integer<1>, Integer<7>>::Type,
    Integer<7> >{};

struct Mul_Test_3 : Assert_Equal<
    Mul<Integer<2>, Integer<0>>::Type,
    Integer<0> >{};

struct Mul_Test_4 : Assert_Equal<
    Mul<Integer<0>, Integer<2>>::Type,
    Integer<0> >{};

struct Mul_Test_5 : Assert_Equal<
    Mul<Integer<6>, Integer<-1>>::Type,
    Integer<-6> >{};

struct Mul_Test_6 : Assert_Equal<
    Mul<Integer<-3>, Integer<(-3)>>::Type,
Integer<9> >{};


// ---------------------------------------------------------------------- //
// Div                                                                    //
// ---------------------------------------------------------------------- //

struct Div_Test_1 : Assert_Equal<
    Div<Integer<7>, Integer<4>>::Type,
    Integer<1> >{};

struct Div_Test_2 : Assert_Equal<
    Div<Integer<4>, Integer<7>>::Type,
    Integer<0> >{};

struct Div_Test_3 : Assert_Equal<
    Div<Integer<2>, Integer<0>>::Error,
    error::Division_By_Zero >{};

struct Div_Test_4 : Assert_Equal<
    Div<Integer<0>, Integer<2>>::Type,
    Integer<0> >{};

struct Div_Test_5 : Assert_Equal<
    Div<Integer<6>, Integer<-2>>::Type,
    Integer<-3> >{};

struct Div_Test_6 : Assert_Equal<
    Div<Integer<-9>, Integer<(-3)>>::Type,
    Integer<3> >{};


// ---------------------------------------------------------------------- //
// Mod                                                                    //
// ---------------------------------------------------------------------- //

struct Mod_Test_1 : Assert_Equal<
    Mod<Integer<7>, Integer<4>>::Type,
    Integer<3> >{};

struct Mod_Test_2 : Assert_Equal<
    Mod<Integer<4>, Integer<7>>::Type,
    Integer<4> >{};

struct Mod_Test_3 : Assert_Equal<
    Mod<Integer<2>, Integer<0>>::Error,
    error::Division_By_Zero >{};

struct Mod_Test_4 : Assert_Equal<
    Mod<Integer<0>, Integer<2>>::Type,
    Integer<0> >{};

struct Mod_Test_5 : Assert_Equal<
    Mod<Integer<6>, Integer<-2>>::Type,
    Integer<0> >{};

struct Mod_Test_6 : Assert_Equal<
    Mod<Integer<9>, Integer<(-2)>>::Type,
    Integer<1> >{};

struct Mod_Test_7 : Assert_Equal<
    Mod<Integer<(-9)>, Integer<2>>::Type,
    Integer<(-1)> >{};

struct Mod_Test_8 : Assert_Equal<
    Mod<Integer<(-9)>, Integer<(-2)>>::Type,
    Integer<(-1)> >{};
}