/*
 * =====================================================================================
 *
 *       Filename:  solver.c
 *
 *    Description:  Definition of the solve functions
 *
 *        Version:  1.0
 *        Created:  09/14/22 10:12:50
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <limits.h>

#include "solver_basic.h"
#include "../solver_tools.h"
#include "../../tools/tools.h"


// Solver of the maze
int solve(char ** maze, size_t rows, size_t cols)
{
    size_t entry_row, entry_col;
    find_entry(maze, rows, cols, &entry_row, &entry_col);
    return solve_rec(maze, rows, cols, entry_row, entry_col);
}

// Basic Solver using recursion
int solve_rec(char ** maze, size_t rows, size_t cols, size_t row, size_t col)
{
    if (maze[row][col] == 'x')
        return 1;
    else
    {
        if (row+1 < rows && (maze[row+1][col] == ' ' || maze[row+1][col] == 'x'))
        {
            maze[row+1][col] = maze[row+1][col] == 'x' ? 'x' : 'o';

            if (solve_rec(maze, rows, cols, row+1, col))
                return 1;
            else
                maze[row+1][col] = ' ';
        }

        if (row > 0 && (maze[row-1][col] == ' ' || maze[row-1][col] == 'x'))
        {
            maze[row-1][col] = maze[row-1][col] == 'x' ? 'x' : 'o';

            if(solve_rec(maze, rows, cols, row-1, col))
                return 1;
            else
                maze[row-1][col] = ' ';
        }

        if (col+1 < cols && (maze[row][col+1] == ' ' || maze[row][col+1] == 'x'))
        {
            maze[row][col+1] = maze[row][col+1] == 'x' ? 'x' : 'o';

            if (solve_rec(maze, rows, cols, row, col+1))
                return 1;
            else
                maze[row][col+1] = ' ';
        }
        if (col > 0 && (maze[row][col-1] == ' ' || maze[row][col-1] == 'x'))
        {
            maze[row][col-1] = maze[row][col-1] == 'x' ? 'x' : 'o';

            if (solve_rec(maze, rows, cols, row, col-1))
                return 1;
            else
                maze[row][col-1] = ' ';
        }
        
        return 0;
    }
}

