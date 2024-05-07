
#include <raylib.h>
#include <raymath.h>
#include <rcamera.h>
#include <vector>
#include <algorithm>
#include <iostream>

#include <crane/math.hpp>

/// Wraps the mouse around the window when it reaches the edge
void WrapMouse()
{
    const Vector2 screen_size = { static_cast<float>(GetScreenWidth()), static_cast<float>(GetScreenHeight()) };
    const Vector2 position = GetMousePosition();
    const Vector2 delta = GetMouseDelta();

    // NOLINTBEGIN(*-narrowing-conversions) // Conversion errors tolerated

    // Wrap X
    if (position.x + delta.x < 0)
        SetMousePosition(screen_size.x + position.x + delta.x, position.y);

    if (screen_size.x < position.x + delta.x)
        SetMousePosition(position.x + delta.x - screen_size.x, position.y);

    // Wrap Y
    if (position.y + delta.y < 0)
        SetMousePosition(position.x, screen_size.y + position.y + delta.y);

    if (screen_size.y < position.y + delta.y)
        SetMousePosition(position.x, position.y + delta.y - screen_size.y);

    // NOLINTEND(*-narrowing-conversions)
}

/// Pivots a given vector on a given point according to the camera provided
void CameraRotate(Camera3D * camera, Vector3 * point, const Vector3 * pivot, const float sensitivity)
{
    // Check camera orientation
    const bool upside_up = camera->up.y == 1.0f;
    const float up_sign = upside_up ? 1.0f : -1.0f;

    const Vector2 mouse_delta = GetMouseDelta();
    const Vector2 angle_delta = {
        -mouse_delta.x * 0.4f * DEG2RAD * sensitivity * up_sign, // Reverse x rotation for upside-down camera
        -mouse_delta.y * 0.4f * DEG2RAD * sensitivity
    };

    // Rotate vertically
    const Vector3 orbited_vertical = Vector3RotateByAxisAngle(
        Vector3Subtract(*point, *pivot),
        GetCameraRight(camera),
        angle_delta.y);

    // Rotate horizontally
    const Vector3 orbited_full = Vector3RotateByAxisAngle(
        orbited_vertical,
        GetCameraUp(camera),
        angle_delta.x);

    // Get distance to vertical angles
    const float top_limit = -Vector3Angle(
        GetCameraForward(camera),
        { 0.0f, up_sign * -1.0f, 0.0f });

    const float bot_limit = Vector3Angle(
        GetCameraForward(camera),
        { 0.0f, up_sign * 1.0f, 0.0f });

    // "Unflip" camera when going past vertical angles
    if (angle_delta.y <= top_limit || bot_limit <= angle_delta.y)
        camera->up = Vector3Negate(camera->up);

    // Apply rotation
    *point = Vector3Add(*pivot, orbited_full);
}

/// Turns the camera around, pivoting on the camera target
void CameraOrbit(Camera3D * camera, const float sensitivity)
{
    CameraRotate(camera, &camera->position, &camera->target, sensitivity);
}

/// Turns the camera around, pivoting on the camera location
void CameraLook(Camera3D * camera, const float sensitivity)
{
    CameraRotate(camera, &camera->target, &camera->position, sensitivity);
}

/// Moves the camera forwards or backwards according to some given value
void CameraDolly(Camera3D * camera, const float delta, const float sensitivity)
{
    const float distance = Vector3Distance(camera->position, camera->target);

    CameraMoveToTarget(camera, delta * sensitivity * distance * 0.1f);
}

/// Moves the camera forwards or backwards based on scrolling
void CameraScrollDolly(Camera3D * camera, const float sensitivity)
{
    CameraDolly(camera, -GetMouseWheelMoveV().y, sensitivity);
}

/// Moves the camera forwards or backwards according to mouse input
void CameraMouseDolly(Camera3D * camera, const float sensitivity)
{
    CameraDolly(camera, GetMouseDelta().y / 8.0f, sensitivity);
}

/// Pans the camera according to mouse input
void CameraPan(Camera3D * camera, const float sensitivity)
{
    const Vector2 delta = GetMouseDelta();
    const float distance = Vector3Distance(camera->position, camera->target);
    const Vector2 range = {
        -delta.x * sensitivity * distance * 0.002f,
        delta.y * sensitivity * distance * 0.002f
    };

    const Vector3 camera_right = Vector3Scale(
        Vector3Normalize(GetCameraRight(camera)),
        range.x);

    const Vector3 camera_up = Vector3Scale(
        Vector3Normalize(
            Vector3CrossProduct(
                GetCameraRight(camera),
                GetCameraForward(camera))),
        range.y);

    const Vector3 camera_move = Vector3Add(camera_right, camera_up);
    camera->position = Vector3Add(camera->position, camera_move);
    camera->target = Vector3Add(camera->target, camera_move);
}

/// Repositions the camera target to lay on the ground whenever in range
void UpdateTarget(Camera3D * camera)
{
    const Vector2 center = {
        static_cast<float>(GetScreenWidth()) / 2.0f,
        static_cast<float>(GetScreenHeight()) / 2.0f
    };

    const Ray target_ray = GetMouseRay(center, *camera);

    const Vector3 ground_0 = (Vector3){ -100.0f + camera->position.x, 0.0f, -100.0f + camera->position.z };
    const Vector3 ground_1 = (Vector3){ -100.0f + camera->position.x, 0.0f,  100.0f + camera->position.z };
    const Vector3 ground_2 = (Vector3){  100.0f + camera->position.x, 0.0f,  100.0f + camera->position.z };
    const Vector3 ground_3 = (Vector3){  100.0f + camera->position.x, 0.0f, -100.0f + camera->position.z };

    const RayCollision hit_info = GetRayCollisionQuad(target_ray, ground_0, ground_1, ground_2, ground_3);
    if (hit_info.hit && 0.01f < hit_info.distance && hit_info.distance < 100.0f)
    {
        camera->target = hit_info.point;
    }
}

/// Manages the controls for the camera
void MainCameraControls(Camera3D * camera)
{
    const bool is_shift_down = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
    const bool is_control_down = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
    const bool is_alt_down = IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT);

    const float factor = is_shift_down ? 8.0f : 1.0f;

    CameraScrollDolly(camera, 1.0f * factor);

    if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
    {
        WrapMouse();

        if (!is_alt_down && !is_control_down)
            CameraPan(camera, 1.0f * factor);

        if (is_alt_down && is_control_down)
            CameraMouseDolly(camera, 1.0f * factor);

        if (is_alt_down && !is_control_down)
            CameraOrbit(camera, 1.0f * factor);

        if (!is_alt_down && is_control_down)
            CameraLook(camera, 1.0f * factor);
    }

    UpdateTarget(camera);
}

void CoordsCameraControls(Camera3D * camera)
{
    const bool is_shift_down = IsKeyDown(KEY_LEFT_SHIFT) || IsKeyDown(KEY_RIGHT_SHIFT);
    const bool is_control_down = IsKeyDown(KEY_LEFT_CONTROL) || IsKeyDown(KEY_RIGHT_CONTROL);
    const bool is_alt_down = IsKeyDown(KEY_LEFT_ALT) || IsKeyDown(KEY_RIGHT_ALT);

    const float factor = is_shift_down ? 8.0f : 1.0f;

    if (IsMouseButtonDown(MOUSE_BUTTON_MIDDLE))
    {
        if (is_alt_down != is_control_down)
            CameraOrbit(camera, 1.0f * factor);
    }
}

/// Returns the alhpa value desired for the a given grid line
unsigned char GetGridAlpha(const float pos, const float exponent)
{
    using namespace crane::math;
    const float frac = exponent - std::floor(exponent);

    if (pos == 0.0f)
        return 191;

    if (mod(abs(pos * std::pow(10.0f, -std::floor(exponent))) + 0.001f, 10.0f) < 0.01f)
        return static_cast<unsigned char>(std::lerp(191, 127, frac));

    if (mod(abs(pos * std::pow(10.0f, -std::floor(exponent))) + 0.0001f, 1.0f) < 0.001f)
        return static_cast<unsigned char>(std::lerp(127, 63, frac));

    return static_cast<unsigned char>(std::lerp(63, 0, frac));
}


/// Draws a scalable grid based on the camera position
void DrawCameraGrid(const Camera3D * camera, const int slices, const float exponent)
{
    const float spacing = std::pow(10.0f, std::floor(exponent)) / 10.0f;
    const float slices_f = static_cast<float>(slices);
    const int adjusted_slices = std::floor(slices_f * std::pow(10, exponent - std::floor(exponent)));

    const int half_slices = adjusted_slices / 2;

    const float x = std::trunc(camera->target.x / spacing) * spacing;
    const float z = std::trunc(camera->target.z / spacing) * spacing;

    const float start_x = x + static_cast<float>(-half_slices) * spacing;
    const float end_x = x + static_cast<float>(half_slices) * spacing;

    const float start_z = z + static_cast<float>(-half_slices) * spacing;
    const float end_z = z + static_cast<float>(half_slices) * spacing;

    for (int i = -half_slices; i <= half_slices; ++i)
    {
        const float pos_x = x + static_cast<float>(i) * spacing;
        const float pos_z = z + static_cast<float>(i) * spacing;

        DrawLine3D({pos_x, -0.01, start_z}, {pos_x, -0.01, end_z}, { 127, 127, 127, GetGridAlpha(pos_x, exponent) });
        DrawLine3D({start_x, -0.01, pos_z}, {end_x, -0.01, pos_z}, { 127, 127, 127, GetGridAlpha(pos_z, exponent) });
    }
}

struct Scene
{
    Camera3D camera;
    RayCollision cursor;
    std::vector<BoundingBox> boxes;
};


void SceneDraw(Scene * scene)
{
    if (scene->cursor.hit)
    {
        float distance = Vector3Distance(scene->camera.position, scene->cursor.point);

        DrawCircle3D(
            Vector3Add(scene->cursor.point, Vector3Scale(scene->cursor.normal, 0.001f * distance)),
            distance * 0.015f,
            Vector3CrossProduct({ 0, 0, 1 }, scene->cursor.normal),
            Vector3Angle({ 0, 0, 1 }, scene->cursor.normal) * RAD2DEG,
            WHITE);

        DrawSphereEx(scene->cursor.point, distance * 0.003f, 2, 8, WHITE);
    }
    {
        float distance = Vector3Distance(scene->camera.position, scene->camera.target);

        DrawCircle3D(
            Vector3Add(scene->camera.target, Vector3Scale(scene->cursor.normal, 0.001f * distance)),
            distance * 0.015f,
            Vector3CrossProduct({ 0, 0, 1 }, scene->cursor.normal),
            Vector3Angle({ 0, 0, 1 }, scene->cursor.normal) * RAD2DEG,
            WHITE);

        DrawSphereEx(scene->cursor.point, distance * 0.003f, 2, 8, WHITE);
    }
    for (const auto & box : scene->boxes)
    {
        DrawBoundingBox(box, WHITE);
    }
}


void DrawAxisCross(Camera3D camera)
{
    Camera3D axis_cam {
        .position = Vector3Normalize(Vector3Subtract(camera.position, camera.target)),
        .target = { 0, 0, 0 },
        .up = camera.up,
        .fovy = camera.fovy,
        .projection = camera.projection,
    };

    BeginMode3D(axis_cam);
    {
        DrawSphereEx({0,0,0}, 0.08, 2, 8, WHITE);
        DrawCapsule({0,0,0}, {0.5,0,0}, 0.04, 6, 2, RED);
        DrawCapsule({0,0,0}, {0,0.5,0}, 0.04, 6, 2, GREEN);
        DrawCapsule({0,0,0}, {0,0,0.5}, 0.04, 6, 2, BLUE);
    }
    EndMode3D();
}


RayCollision SceneDetectHit(Scene * scene, const Ray & ray)
{
    float distance = crane::numbers::inf<float>;
    RayCollision hit_info {};
    hit_info.hit = false;

    for (const auto & box : scene->boxes)
    {
        RayCollision info = GetRayCollisionBox(ray, box);
        if (info.hit && info.distance < distance)
        {
            hit_info = info;
            distance = info.distance;
        }
    }

    RayCollision info = GetRayCollisionQuad(
        ray,
        Vector3 { -1000, 0,  1000 },
        Vector3 {  1000, 0,  1000 },
        Vector3 {  1000, 0, -1000 },
        Vector3 { -1000, 0, -1000 }
    );

    if (info.hit && info.distance < distance)
    {
        hit_info = info;
    }

    return hit_info;
}


void SceneUpdate(Scene * scene)
{
    Ray mouse_ray = GetMouseRay(GetMousePosition(), scene->camera);
    scene->cursor = SceneDetectHit(scene, mouse_ray);

    enum { NONE, FLAT, EXTRUDE };
    static int stage = NONE;
    static Vector3 start;
    static float height = 0;
    static float bot = 0;
    static float top = 0;
    static BoundingBox * active_box;

    if (stage == NONE && scene->cursor.hit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        stage = FLAT;
        start = scene->cursor.point;
        scene->boxes.push_back({start, start});
        active_box = &scene->boxes.back();
    }
    else if (stage == FLAT && scene->cursor.hit && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        stage = EXTRUDE;
        height = 0;
    }
    else if (stage == FLAT && scene->cursor.hit)
    {
        active_box->min = Vector3Min(start, scene->cursor.point);
        active_box->max = Vector3Max(start, scene->cursor.point);
        bot = active_box->min.y;
        top = active_box->max.y;
    }
    else if (stage == EXTRUDE && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        stage = NONE;
    }
    else if (stage == EXTRUDE)
    {
        float delta = -GetMouseDelta().y * Vector3Distance(scene->camera.position, scene->camera.target) * 0.001f;
        height += delta;

        if (height < 0)
        {
            active_box->min.y = bot + height;
            active_box->max.y = top;
        }
        else
        {
            active_box->min.y = bot;
            active_box->max.y = top + height;
        }
    }

    if (IsMouseButtonPressed(MOUSE_BUTTON_RIGHT))
    {
        stage = NONE;
    }
}


int main()
{
    InitWindow(1920, 1080, "Crane");
    SetConfigFlags(FLAG_WINDOW_RESIZABLE);
    SetTargetFPS(60);

    Scene scene {};
    scene.camera = {
        .position = Vector3Scale(Vector3Normalize({ 1.0f, 1.0f, 1.0f }), 10.f),
        .target = { 0.0f, 0.0f, 0.0f },
        .up = { 0.0f, 1.0f, 0.0f },
        .fovy = 75,
        .projection = CAMERA_PERSPECTIVE
    };

    RenderTexture scene_view = LoadRenderTexture(GetScreenWidth(), GetScreenHeight());
    RenderTexture coords_view = LoadRenderTexture(80, 80);


    while (!WindowShouldClose())
    {
        //
        // Draw main scene
        // ------------------------------------------------------------------- //

        BeginTextureMode(scene_view);
        {
            ClearBackground({ 31, 31, 31, 255 });
            BeginMode3D(scene.camera);
            {
                float distance_exponent = std::log10(
                    std::abs(
                        Vector3Distance(
                            scene.camera.position,
                            scene.camera.target)));

                SceneDraw(&scene);
                DrawCameraGrid(&scene.camera, 100, distance_exponent);
            }
            EndMode3D();
        }
        EndTextureMode();

        MainCameraControls(&scene.camera);
        SceneUpdate(&scene);

        //
        // Draw axis cross
        // ------------------------------------------------------------------- //
        BeginTextureMode(coords_view);
        {
            ClearBackground({ 0, 0, 0, 0 });
            DrawAxisCross(scene.camera);
        }
        EndTextureMode();

        //
        // Render
        // ------------------------------------------------------------------- //
        BeginDrawing();
        {
            ClearBackground({ 0, 0, 0, 0 });
            const Rectangle area_scene {
                0, 0,
                static_cast<float>(scene_view.texture.width),
                -static_cast<float>(scene_view.texture.height) };

            const Vector2 position_scene { 0, 0 };

            DrawTextureRec(scene_view.texture, area_scene, position_scene, WHITE);

            const Rectangle area_coords {
                0, 0,
                static_cast<float>(coords_view.texture.width),
                -static_cast<float>(coords_view.texture.height) };

            const Vector2 position_coords {
                static_cast<float>(GetScreenWidth() - 90),
                static_cast<float>(GetScreenHeight() - 90) };

            DrawTextureRec(coords_view.texture, area_coords, position_coords, WHITE);
        }
        EndDrawing();
    }
}
