#include "RayApp.h"

double t = 0.0;
double dt = 0.05;
double currentTime = 0.0;
double accumulator = 0.0;

int main()
{
    auto app{RayApp()};

    app.setup();

    currentTime = GetTime();
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // This part keeps the game running at a fixed timestep
        // independent of frame rate (which may vary).
        const double newTime = GetTime();
        const double frameTime = newTime - currentTime;
        currentTime = newTime;

        accumulator += frameTime;

        while (accumulator >= dt)
        {
            app.update(t, dt);
            accumulator -= dt;
            t += dt;
        }

        // This part draws the game at a possibly variable frame rate.
        BeginDrawing();
        app.draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
