#include "../lib/raylib/src/raylib.h"
#include "../include/game_config.h"
#include "../include/tetromino.h"




int main(void) 
{
    InitWindow(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_TITLE);
    SetTargetFPS(GAME_FPS);

    Game game;
    init_game(&game);

    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);

        draw_grid(&game);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}
