/*
 * =====================================================================================
 *
 *       Filename:  solver.h
 *
 *    Description: Prototypes of the solver 
 *
 *        Version:  1.0
 *        Created:  09/14/22 10:08:57
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#ifndef SOLVER
#define SOLVER

// Make a copy of the maze
char ** copy_maze(char ** maze, size_t rows, size_t cols);

// Find the entry of the maze
void find_entry(char ** maze, size_t rows, size_t cols, size_t * row, size_t * col);

// Find the exit of the maze
void find_exit(char ** maze, size_t rows, size_t cols, size_t * row, size_t * col);

// Verify whether the maze has been solved
int is_solved(char ** maze, size_t rows, size_t cols);

// Solver of the maze
char ** solve(char ** maze, size_t rows, size_t cols);

// Solver recursive
char ** solve_rec(char ** maze, size_t rows, size_t cols, size_t row, size_t col);

#endif 

