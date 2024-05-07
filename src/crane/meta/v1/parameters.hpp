
#pragma once
#define CRANE_HEADER_CONTENTS
#include <type_traits>

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// IParameter                                                             //
// ---------------------------------------------------------------------- //

template <typename T, template <typename> typename U>
concept IParameter = requires { U<T>::Value; } || std::is_same_v<T, void>;

}

#undef CRANE_HEADER_CONTENTS