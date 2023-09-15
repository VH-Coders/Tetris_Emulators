#include "../include/tetromino.h"



void init_game(Game* game)
{
    for (int i = 0; i < GRID_HEIGHT; i++)
        for (int j = 0; j < GRID_HEIGHT; j++)
            game->grid[i][j] = EMPTY;

    game->piece_pos.x = 0.0;
    game->piece_pos.y = 0.0;
}



void draw_grid(Game* game)
{
    const Vector2 start_pos =
    {
        .x = ((float)WINDOW_WIDTH / 2) - ((float)GRID_WIDTH * GRID_SQUARE_SIZE / 2),
        .y = ((float)WINDOW_HEIGHT / 2) - ((float)GRID_HEIGHT * GRID_SQUARE_SIZE / 2)
    };
    Vector2 pos = start_pos;

    for (int i = 0; i < GRID_HEIGHT; i++)
    {
        for (int j = 0; j < GRID_WIDTH; j++)
        {
            draw_grid_square(game->grid[i][j], &pos);
            pos.x += GRID_SQUARE_SIZE;
        }
        pos.y += GRID_SQUARE_SIZE;
        pos.x = start_pos.x;
    }
}



void draw_grid_square(SquareState_t state, Vector2* pos)
{
    const Color grid_color = GRAY;
    const Color filled_square_color = DARKGRAY;

    switch (state)
    {
        case EMPTY:
            DrawLine(pos->x, 
                     pos->y, 
                     pos->x + GRID_SQUARE_SIZE, 
                     pos->y, 
                     grid_color);
            DrawLine(pos->x, 
                     pos->y, 
                     pos->x, 
                     pos->y + GRID_SQUARE_SIZE, 
                     grid_color);
            DrawLine(pos->x + GRID_SQUARE_SIZE, 
                     pos->y, 
                     pos->x + GRID_SQUARE_SIZE, 
                     pos->y + GRID_SQUARE_SIZE, 
                     grid_color);
            DrawLine(pos->x, 
                     pos->y + GRID_SQUARE_SIZE, 
                     pos->x + GRID_SQUARE_SIZE, 
                     pos->y + GRID_SQUARE_SIZE, 
                     grid_color);
            break;

        case FILLED:
            DrawRectangle(pos->x, 
                          pos->y, 
                          GRID_SQUARE_SIZE, 
                          GRID_SQUARE_SIZE, 
                          filled_square_color);
            break;

        default:
            break;
    }
}
