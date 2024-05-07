// #include "vectors.hpp"
//
// #include <raylib.h>
//
// #define DEFINE_ADAPTER(raylib_struct, crane_struct, from_raylib, from_crane)            \
// namespace crane::geom::raylib                                                           \
// {                                                                                       \
// raylib_struct::raylib_struct(const ::raylib_struct & orig):                             \
//     data from_raylib {}                                                                 \
//                                                                                         \
// raylib_struct::operator crane_struct() const                                            \
// {                                                                                       \
//     return data;                                                                        \
// }                                                                                       \
//                                                                                         \
// raylib_struct::raylib_struct(const crane_struct & vec):                                 \
//     data { vec } {}                                                                     \
//                                                                                         \
// raylib_struct::operator ::raylib_struct() const                                         \
// {                                                                                       \
//     return ::raylib_struct from_crane;                                                  \
// }                                                                                       \
// }                                                                                       \
//
// DEFINE_ADAPTER(Vector2, geom::Vector_2, (orig.x, orig.y), (data.x(), data.y()))
// DEFINE_ADAPTER(Vector3, geom::Vector_3, (orig.x, orig.y, orig.z), (data.x(), data.y(), data.z()))
