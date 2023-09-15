#include <stdio.h>
#include <stdlib.h>
#include "../lib/raylib/src/raylib.h"
#include "../include/game_config.h"

int main() 
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(GAME_FPS);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
