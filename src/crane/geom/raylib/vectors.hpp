//
// #pragma once
// #define CRANE_HEADER_CONTENTS
//
// #include <crane.hpp>
// #include <crane/geom/kernel.hpp>
//
// // NOLINTBEGIN(*-explicit-constructor)
// // ReSharper disable CppNonExplicitConversionOperator
// // ReSharper disable CppNonExplicitConvertingConstructor
//
// struct Vector3;
// struct Vector4;
// struct Rectangle;
//
// #define DECLARE_ADAPTER(raylib_struct, crane_struct)        \
// struct raylib_struct;                                       \
// namespace crane::geom::raylib                               \
// {                                                           \
//     struct raylib_struct                                    \
//     {                                                       \
//         crane_struct data;                                  \
//                                                             \
//         raylib_struct(const ::raylib_struct & orig);        \
//         operator crane_struct() const;                      \
//                                                             \
//         explicit raylib_struct(const crane_struct & vec);   \
//         operator ::raylib_struct() const;                   \
//     };                                                      \
// }
//
// DECLARE_ADAPTER(Vector2, geom::Vector_2)
// DECLARE_ADAPTER(Vector3, geom::Vector_3)
//
// // NOLINTEND(*-explicit-constructor)
// // ReSharper restore CppNonExplicitConversionOperator
// // ReSharper restore CppNonExplicitConvertingConstructor
//
// #undef DECLARE_ADAPTER
// #undef CRANE_HEADER_CONTENTS