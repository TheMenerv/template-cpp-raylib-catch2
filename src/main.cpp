#include <cmath>
#include "raylib.h"



int main()
{
    InitWindow(800, 450, "Pixel Space Program");
    //SetTargetFPS(60);

    auto counter = 0.f;
    auto fps = 0;

    while (!WindowShouldClose())
    {
        const auto deltaTime = GetFrameTime();
        counter += deltaTime;

        if (counter >= 1.f)
        {
            fps = GetFPS();
            counter = 0;
        }

        double result = 0.0;
        for (int i = 0; i < 1000000; i++)
        {
            result += sin(i) * cos(i); // Simulation de calculs
        }


        BeginDrawing();
        ClearBackground(BLACK);

        DrawText(TextFormat("FPS: %i", fps), 10, 10, 20, WHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}