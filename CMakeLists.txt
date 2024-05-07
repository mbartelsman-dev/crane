cmake_minimum_required(VERSION 3.28)
include(tools/cmake/utils.cmake)

#
# Project settings
# -----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.28)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Crane.Crane
        VERSION 0.1.0
        DESCRIPTION "A Library"
        LANGUAGES CXX
)

set_project_names(${PROJECT_NAME})

#
# Targets
# -----------------------------------------------------------------------------

## Static library
add_library(${PROJECT_NAME} STATIC
        include/crane.hpp
        include/crane/geom.hpp
        include/crane/geom/kernel.hpp
        include/crane/geom/kernel_fwd.hpp
        include/crane/geom/shapes.hpp
        include/crane/geom/shapes_fwd.hpp
        include/crane/geom_fwd.hpp
        include/crane/math.hpp
        include/crane/meta/concepts.hpp
        include/crane/meta/macros.hpp
        include/crane/meta/tmp.hpp
        include/crane/numbers/limits.hpp
        include/crane/numbers/math.hpp
        src/crane/geom/_fwd.hpp
        src/crane/geom/kernel.hpp
        src/crane/geom/kernel/Angle.cpp
        src/crane/geom/kernel/Angle.hpp
        src/crane/geom/kernel/Direction_2.cpp
        src/crane/geom/kernel/Direction_2.hpp
        src/crane/geom/kernel/Direction_3.cpp
        src/crane/geom/kernel/Direction_3.hpp
        src/crane/geom/kernel/Euler.cpp
        src/crane/geom/kernel/Euler.hpp
        src/crane/geom/kernel/Matrix_2.hpp
        src/crane/geom/kernel/Matrix_3.hpp
        src/crane/geom/kernel/Matrix_Impl.hpp
        src/crane/geom/kernel/Point_2.cpp
        src/crane/geom/kernel/Point_2.hpp
        src/crane/geom/kernel/Point_3.cpp
        src/crane/geom/kernel/Point_3.hpp
        src/crane/geom/kernel/Quaternion.hpp
        src/crane/geom/kernel/Vec.hpp
        src/crane/geom/kernel/Vec.tpp
        src/crane/geom/kernel/Vector_2.cpp
        src/crane/geom/kernel/Vector_2.hpp
        src/crane/geom/kernel/Vector_3.cpp
        src/crane/geom/kernel/Vector_3.hpp
        src/crane/geom/kernel/Vector_Impl.cpp
        src/crane/geom/kernel/Vector_Impl.hpp
        src/crane/geom/kernel/Vector_Impl.tpp
        src/crane/geom/raylib/vectors.cpp
        src/crane/geom/raylib/vectors.hpp
        src/crane/geom/shapes/Circle.cpp
        src/crane/geom/shapes/Circle.hpp
        src/crane/geom/shapes/Triangle_2.cpp
        src/crane/geom/shapes/Triangle_2.hpp
        src/crane/math/operations.hpp
        src/crane/math/operations.tpp
        src/crane/meta/concepts.hpp
        src/crane/meta/macros.hpp
        src/crane/meta/v1/associative_packs.hpp
        src/crane/meta/v1/associative_packs.tests.cpp
        src/crane/meta/v1/booleans.hpp
        src/crane/meta/v1/booleans.tests.cpp
        src/crane/meta/v1/checks.hpp
        src/crane/meta/v1/checks.tests.cpp
        src/crane/meta/v1/conditionals.hpp
        src/crane/meta/v1/conditionals.tests.cpp
        src/crane/meta/v1/conversions.hpp
        src/crane/meta/v1/errors.hpp
        src/crane/meta/v1/errors.tests.cpp
        src/crane/meta/v1/functions.hpp
        src/crane/meta/v1/integers.hpp
        src/crane/meta/v1/integers.tests.cpp
        src/crane/meta/v1/nested_packs.hpp
        src/crane/meta/v1/nested_packs.tests.cpp
        src/crane/meta/v1/packs.hpp
        src/crane/meta/v1/packs.tests.cpp
        src/crane/meta/v1/parameters.hpp
        src/crane/meta/v1/predicates.hpp
        src/crane/meta/v1/returns.hpp
        src/crane/meta/v1/returns.tests.cpp
        src/crane/meta/v1/tuples.hpp
        src/crane/meta/v1/tuples.tests.cpp
        src/crane/meta/v1/values.hpp
        src/crane/meta/v1/values.tests.cpp
        src/crane/numbers/limits.hpp
        src/crane/numbers/math.hpp
        src/crane/numeric_types.hpp
        src/crane/viz/Scene.hpp
        src/crane/viz/Visualizer.cpp
        src/crane/viz/Visualizer.hpp
        src/crane/viz/cameras.cpp
        src/crane/viz/cameras.hpp
        src/main.cpp
)

add_library(${PROJECT_NAMESPACE} ALIAS ${PROJECT_NAME})

target_include_directories(${PROJECT_NAME}
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        include
)

set_target_properties(${PROJECT_NAME}
        PROPERTIES
        LINKER_LANGUAGE         CXX
        VERSION                 ${PROJECT_VERSION}
)

#
# Dependencies
# -----------------------------------------------------------------------------

find_package(fmt CONFIG REQUIRED)
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)

include(FetchContent)

set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE) # don't build the supplied examples
set(BUILD_GAMES    OFF CACHE BOOL "" FORCE) # don't build the supplied example games
add_git_library(
        raylib
        https://github.com/raysan5/raylib.git
        5.0
)
target_link_libraries(${PROJECT_NAME} PRIVATE raylib)