/*
 * =====================================================================================
 *
 *       Filename:  solver_tools.h
 *
 *    Description:  Tools used by solver algorithms
 *
 *        Version:  1.0
 *        Created:  10/16/22 19:48:34
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stddef.h>

#ifndef SOLVER_TOOLS
#define SOLVER_TOOLS

// Make a copy of the maze
char ** copy_maze(char ** maze, size_t rows, size_t cols);

// Free a Maze
void free_maze(char ** maze, size_t rows);

// Find the entry of the maze
void find_entry(char ** maze, size_t rows, size_t cols, size_t * row, size_t * col);

// Find the exit of the maze
void find_exit(char ** maze, size_t rows, size_t cols, size_t * row, size_t * col);

// Verify whether the maze has been solved
int is_solved(char ** maze, size_t rows, size_t cols);

#endif
