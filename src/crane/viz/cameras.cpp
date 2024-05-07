
#include "cameras.hpp"

namespace crane::viz
{
using namespace geom;

void
Perspective_Camera::move(const Vector_3 & delta)
{
    const Vector_3 forward = normalize(target() - position()) * -delta.z();
    const Vector_3 right = normalize(cross(forward, up_direction())) * delta.x();
    const Vector_3 up = cross(right, forward) * delta.y();

    position() += forward + right + up;
    target() += forward + right + up;
}


void
Perspective_Camera::pan(const Vector_2 & delta)
{
    move({ delta.x(), delta.y(), 0 });
}


void
Perspective_Camera::dolly(Fp_T delta)
{
    move({ 0, 0, delta });
}


void
Perspective_Camera::rotate(const Vector_3 & pivot, const Euler & angles)
{
    // Get distance to vertical angles
    const bool upside_up = up_direction().y() == 1.0f;
    const Fp_T y_val = upside_up ? 1.0f : -1.0f;
    const Vector_3 forwards = normalize(target() - position());

    const Angle top_limit = -vector_3::angle(forwards, Vector_3 { 0.0f, -y_val, 0.0f });
    const Angle bot_limit = vector_3::angle(forwards, { 0.0f, y_val, 0.0f });

    // "Unflip" camera when going past vertical angles
    if (angles.pitch() <= top_limit || bot_limit <= angles.pitch())
        up_direction() = -up_direction();

    // Rotate
    const Vector_3 rel_pos = position() - pivot;
    const Vector_3 rel_tgt = target() - pivot;

    position() = pivot + vector_3::rotate(rel_pos, angles);
    target() = pivot + vector_3::rotate(rel_tgt, angles);
}


void
Perspective_Camera::orbit(const Euler & angles)
{
    rotate(target(), angles);
}


void
Perspective_Camera::turn(const Euler & angles)
{
    rotate(position(), angles);
}


void
Perspective_Camera::zoom(const Fp_T factor)
{
    field_of_view() *= 1.0f / factor;
}

}

