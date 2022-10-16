/*
 * =====================================================================================
 *
 *       Filename:  solver_brute_force.h
 *
 *    Description: Prototypes of the solver with brute force
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
#include <stddef.h>

#ifndef SOLVER_BRUTE_FORCE
#define SOLVER_BRUTE_FORCE

// Solver of the maze
void solve(char ** maze, size_t rows, size_t cols);

// Solver recursive
void solve_rec(char ** maze, size_t rows, size_t cols, size_t row, size_t col);

// Add maze solution in the mazes (size is given for malloc allocations)
void add_solution(char *** mazes, char ** maze, size_t rows, size_t cols, int size);

// Find best Maze
char ** find_best(char ***mazes, size_t rows, size_t cols);

// Count the number of trace on a maze (nb_max for optimization purpose)
int count_traces(char ** maze, size_t rows, size_t cols, int nb_max);


#endif 

