/* tetromino.h
 *
 * This defines all necessary functions and structs needed for creating, drawing,
 * and manipulating individual tetris pieces
 *
 */
#ifndef TETRIS_TETROMINO_H
#define TETRIS_TETROMINO_H
#include <raylib.h>
#include "../include/game_config.h"

/*  I block  J block    L block     
 *
 *  ####        ####    ####
 *  ####        ####    ####
 *  ####        ####    ####        O block
 *  ####        ####    ####        
 *  ####        ####    ####        ########
 *  ####        ####    ####        ########
 *  ####    ########    ########    ########
 *  ####    ########    ########    ########
 *
 *  S block         T block         Z block
 *
 *      ########    ############    ########
 *      ########    ############    ########
 *  ########            ####            ########
 *  ########            ####            ########
 */


typedef enum PieceShape_t 
{
    I_BLOCK,
    J_BLOCK,
    L_BLOCK,
    O_BLOCK, 
    S_BLOCK,
    T_BLOCK,
    Z_BLOCK
} PieceShape_t;



typedef enum SquareState_t 
{
    EMPTY,
    FILLED,
} SquareState_t;



typedef struct Game
{
    SquareState_t grid[GRID_WIDTH][GRID_HEIGHT];
    Vector2 piece_pos;
} Game;



typedef struct Piece 
{
    PieceShape_t shape;
    Color color;
} Piece;

void init_game(Game* game);

void draw_grid(Game* game);

void draw_grid_square(SquareState_t state, Vector2* pos);

#endif
