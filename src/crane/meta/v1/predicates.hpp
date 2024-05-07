
#pragma once
#define CRANE_HEADER_CONTENTS

#include "booleans.hpp"
#include "returns.hpp"

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// Is_Template                                                            //
// ---------------------------------------------------------------------- //

template <template <typename...> typename, typename>
struct Is_Template : Return_Type<False> {};

template <template <typename...> typename Template, typename... Contents>
struct Is_Template<Template, Template<Contents...>> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// Is_Ref                                                                 //
// ---------------------------------------------------------------------- //

template <typename>
struct Is_Ref : Return_Type<False> {};

template <typename T>
struct Is_Ref<T&> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// Is_Const_Ref                                                           //
// ---------------------------------------------------------------------- //

template <typename>
struct Is_Const_Ref : Return_Type<False> {};

template <typename T>
struct Is_Const_Ref<const T &> : Return_Type<True> {};


// ---------------------------------------------------------------------- //
// Is_Mut_Ref                                                             //
// ---------------------------------------------------------------------- //

template <typename>
struct Is_Mut_Ref : Return_Type<False> {};

template <typename T>
struct Is_Mut_Ref<const T &> : Return_Type<False> {};

template <typename T>
struct Is_Mut_Ref<T&> : Return_Type<True> {};

}
#undef CRANE_HEADER_CONTENTS