
#pragma once
#define CRANE_HEADER_CONTENTS

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// Return_Type                                                            //
// ---------------------------------------------------------------------- //

/// Metafunction that returns the passed type
template <typename T>
struct Return_Type
{
    using Type = T;
};

}

#undef CRANE_HEADER_CONTENTS