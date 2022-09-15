#ifndef GENERATOR
#define GENERATOR

// Generate an empty board
char ** generate_empty_board(size_t rows, size_t cols);

// Add a line of wall 
void add_wall(char ** board, size_t row, size_t col);

// Application of the recursive division algorithm on a board
char ** recursive_division(char ** board, size_t min_row, size_t max_row, size_t min_col, size_t max_col, size_t rows, size_t cols);


#endif
