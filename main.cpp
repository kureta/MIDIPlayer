#include <raylib.h>
#include "utils.hpp"
#include <thread>


double t = 0.0;
double dt = 0.05;

double currentTime = 0.0;
double accumulator = 0.0;


int main() {
    using namespace std::literals;

    // Application window setup
    SetTraceLogLevel(LOG_ERROR);
    SetTargetFPS(60); // Set our game to run at 60 frames-per-second

    constexpr int screenWidth = 1280;
    constexpr int screenHeight = 720;

    SetConfigFlags(FLAG_MSAA_4X_HINT);
    InitWindow(screenWidth, screenHeight, "MIDI Player");

    // MIDI setup
    libremidi::midi_out midiout;
    chooseMidiPort(midiout);

    // Main loop
    currentTime = GetTime();
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // Note On: 144, 64, 90
        midiout.send_message(144, 64, 90);

        std::this_thread::sleep_for(500ms);

        // Note Off: 128, 64, 40
        midiout.send_message(128, 64, 40);

        /*
        const double newTime = GetTime();
        double frameTime = newTime - currentTime;
        if (frameTime > 0.25)
            frameTime = 0.25;
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt)
        {
            // do time sensitive stuff
            accumulator -= dt;
            t += dt;
        }
        */

        BeginDrawing();
        ClearBackground(RAYWHITE);
        DrawText("Congrats! You created your first window!", 190, 200, 20, LIGHTGRAY);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}
