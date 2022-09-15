#include <stdlib.h>
#include "wall.h"

#ifndef GENERATOR
#define GENERATOR

// Generate an empty board
// The board will be filled with wall and space
char ** generate_empty_board(size_t rows, size_t cols);

// Create a wall based on a given position and the current board
wall * add_wall(char ** board, size_t rows, size_t cols, size_t col, size_t row
        , int vertical);

// Find a random breach on a wall
// If no breach can be found (ie wp length <= 3), wp is replaced by NULL
void find_breach(wall * wp);

// Split the wall into two other wall using the breach
// Both walls will create sub walls then
void split_wall(wall * w, wall * w1, wall * w2);

// Generate sub walls using a wall
// 
// The number of wall generated is random but stay between 1 and the size
// of the wall divided by 2 so that at least some walls will be created
//
// The list is delimited by a NULL pointer
wall ** generate_walls(char ** board, size_t rows, size_t cols, wall * w);

// Apply the rule of a wall
// ie : fill with # character the line given the information retained by the 
// wall
void apply_wall_rule(char ** board, size_t rows, size_t cols, wall * w);

// Generate a maze using the below algorithm
char ** generate_maze(size_t * rows, size_t * cols);

// Application of the recursive division algorithm on a board
// - Breach the wall given if possible
// - Split the wall into two other walls
// - Construct wall based on the current board's state
void recursive_division(char ** board, size_t rows, size_t cols, wall * wp);


#endif
