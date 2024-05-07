
#pragma once
#define CRANE_HEADER_CONTENTS
#include <crane.hpp>

#include <crane/geom.hpp>


namespace crane::viz
{

// ========================================================================== //
// BASE CAMERA -------------------------------------------------------------- //
// ========================================================================== //

template <typename Concrete>
struct Base_Camera
{
    enum class Type : int { Perspective = 0, Orthographic = 1 };

    // ---------------------------------------------------------------------- //
    // MEMBERS                                                                //
    // ---------------------------------------------------------------------- //

    Type _camera_type { Concrete::camera_type };
    geom::Vector_3 _position { };
    geom::Vector_3 _target { };
    geom::Vector_3 _up_direction { };

    union
    {
        Fp_T _field_of_view { };
        Fp_T _view_width;
    };


    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Base_Camera(
        const geom::Vector_3 & position,
        const geom::Vector_3 & target,
        const geom::Vector_3 & up_direction,
        const Fp_T fov_vw):
            _position { position },
            _target { target },
            _up_direction { up_direction },
            _field_of_view { fov_vw } {}


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    //
    // Getters
    // ------------------------------------------------------------------- //

    [[nodiscard]] const geom::Vector_3 & position() const { return _position; }
    [[nodiscard]] const geom::Vector_3 & target() const { return _target; }
    [[nodiscard]] const geom::Vector_3 & up_direction() const { return _up_direction; }

    [[nodiscard]] geom::Vector_3 & position() { return _position; }
    [[nodiscard]] geom::Vector_3 & target() { return _target; }
    [[nodiscard]] geom::Vector_3 & up_direction() { return _up_direction; }
};



// ========================================================================== //
// PERSPECTIVE CAMERA ------------------------------------------------------- //
// ========================================================================== //

struct Perspective_Camera : Base_Camera<Perspective_Camera> {

    static constexpr Type camera_type { Type::Perspective };


    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Perspective_Camera():
        Base_Camera {
            geom::normalize({ 10.0f, 10.0f, 10.0f }),
            { 0, 0, 0 },
            { 0, 1, 0 },
            75
        } { }

    Perspective_Camera(
        const geom::Vector_3 & position,
        const geom::Vector_3 & target,
        const geom::Vector_3 & up_direction,
        const Fp_T field_of_view):
            Base_Camera { position, target, up_direction, field_of_view } { }


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T field_of_view() const { return _field_of_view; }
    [[nodiscard]] Fp_T & field_of_view() { return _field_of_view; }


    // ---------------------------------------------------------------------- //
    // METHODS                                                                //
    // ---------------------------------------------------------------------- //

    /// Moves the camera using OpenGL conventions (-z forwards, +x right, +y up)
    /// by the specified distances.
    void move(const geom::Vector_3 & delta);

    /// Pans the camera around its normal plane by the specified distance.
    void pan(const geom::Vector_2 & delta);

    /// Moves the camera forwards (-) or backwards (+) by the specified distance.
    void dolly(Fp_T delta);

    /// Rotates the camera position and its target around a specified pivot
    void rotate(const geom::Vector_3 & pivot, const geom::Euler & angles);

    /// Rotates the camera with the target as a pivot
    void orbit(const geom::Euler & angles);

    /// Rotates the camera's target with the camera position as the pivot
    void turn(const geom::Euler & angles);

    /// Scales the field of view by the inverse of the provided factor
    void zoom(Fp_T factor);
};



// ========================================================================== //
// ORTHOGRAPHIC CAMERA ------------------------------------------------------ //
// ========================================================================== //


struct Orthographic_Camera : Base_Camera<Orthographic_Camera> {

    static constexpr Type camera_type { Type::Orthographic };


    // ---------------------------------------------------------------------- //
    // CONSTRUCTORS                                                           //
    // ---------------------------------------------------------------------- //

    Orthographic_Camera():
        Base_Camera {
            { 500.0f, 500.0f, 500.0f },
            { 0, 0, 0 },
            { 0, 1, 0 },
            20.0f
        } { }

    Orthographic_Camera(
        const geom::Vector_3 & position,
        const geom::Vector_3 & target,
        const geom::Vector_3 & up_direction,
        const Fp_T view_width):
            Base_Camera { position, target, up_direction, view_width } { }


    // ---------------------------------------------------------------------- //
    // ACCESSORS                                                              //
    // ---------------------------------------------------------------------- //

    [[nodiscard]] Fp_T view_width() const { return _view_width; }
    [[nodiscard]] Fp_T & view_width() { return _view_width; }


    // ---------------------------------------------------------------------- //
    // METHODS                                                                //
    // ---------------------------------------------------------------------- //

    /// Pans the camera around its normal plane by the specified distance.
    void pan(const geom::Vector_2 & delta);

    /// Rotates the camera with the target as a pivot
    void orbit(const geom::Euler & angles);

    /// Scales the view_width by the inverse of the provided factor
    void zoom(Fp_T factor);
};

}

#undef CRANE_HEADER_CONTENTS
