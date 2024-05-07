
#pragma once
#define CRANE_HEADER_CONTENTS

namespace crane::meta::v1
{
// ---------------------------------------------------------------------- //
// Return_Error                                                           //
// ---------------------------------------------------------------------- //

/// Metafunction that returns the given type as an error
template <typename TError>
struct Return_Error
{
    using Error = TError;
};

}

#undef CRANE_HEADER_CONTENTS