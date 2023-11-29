#include "RayApp.h"

void RayApp::setup() {
    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "raylib [shapes] example - bouncing ball");

    ballPosition = {
        static_cast<float>(GetScreenWidth()) / 2.0f,
        static_cast<float>(GetScreenHeight()) / 2.0f
    };
    ballSpeed = {10.0f, 8.0f};
    ballRadius = 20.0f;

    pause = false;
    framesCounter = 0;

    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    MIDI midi{MIDI()};
}

void RayApp::update(const double t, const double dt) {
    if (IsKeyPressed(KEY_SPACE)) pause = !pause;

    if (!pause) {
        midi.play_next_note(t);
        ballPosition.x += ballSpeed.x;
        ballPosition.y += ballSpeed.y;

        // Check walls collision for bouncing
        if (ballPosition.x >= static_cast<float>(GetScreenWidth()) - ballRadius
            || ballPosition.x <= ballRadius)
            ballSpeed.x *= -1.0f;
        if (ballPosition.y >= static_cast<float>(GetScreenHeight()) - ballRadius
            || ballPosition.y <= ballRadius)
            ballSpeed.y *= -1.0f;
    }
    else framesCounter++;
}

void RayApp::draw() const {
    ClearBackground(RAYWHITE);

    DrawCircleV(ballPosition, ballRadius, MAROON);
    DrawText("PRESS SPACE to PAUSE BALL MOVEMENT", 10, GetScreenHeight() - 25, 20, LIGHTGRAY);

    // On pause, we draw a blinking message
    if (pause && framesCounter / 30 % 2)
        DrawText("PAUSED", 350, 200, 30, GRAY);

    DrawFPS(10, 10);
}
