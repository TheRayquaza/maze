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

#ifndef SOLVER_BASIC
#define SOLVER_BASIC

// Solver of the maze
int solve(char ** maze, size_t rows, size_t cols);

// Solver recursive
int solve_rec(char ** maze, size_t rows, size_t cols, size_t row, size_t col);

#endif 

