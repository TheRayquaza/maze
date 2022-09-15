#include <stdlib.h>
#include <time.h>
#include "generator.h"

// Generate an empty board
char ** generate_empty_board(size_t rows, size_t cols);
{
    char ** board = malloc(0);
    for (size_t row = 0; row < rows; row++)
    {
        board = realloc(board, cols * (row+1));
        board[row] = malloc(sizeof(char) * cols);
        for (size_t col = 0; col < cols; col++)
            board[row][col] = ' ';
    }
}

// Add a line of wall 
void add_wall(char ** board, size_t row, size_t col)
{

    for (size_t row = 0; row)
}

// Application of the recursive division algorithm on a board
char ** recursive_division(char ** board, size_t min_row, size_t max_row, size_t min_col, size_t max_col, size_t rows, size_t cols);


