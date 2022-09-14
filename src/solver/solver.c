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

#include "solver.h"
#include "../tools/tools.h"

// Copy maze
char ** copy_maze(char ** maze, size_t rows, size_t cols)
{
    char ** copied_maze = calloc(rows, cols);
    for (size_t row = 0; row < rows; row++)
    {
        copied_maze[row] = calloc(cols, sizeof(char));
        for (size_t col = 0; col < cols; col++)
            copied_maze[row][col] = maze[row][col];
    }
    return copied_maze;
}

// Find the entry of the maze
void find_entry(char ** maze, size_t rows, size_t cols, size_t * row, size_t * col)
{
    size_t i = 0;
    size_t j = 0;
    int found = 0;

    while (i < rows && !found)
    {
        while (j < cols && !found)
        {
            found = (maze[i][j] == '@');
            j++;
        }
        if (!found)
        {
            i++;
            j = 0;
        }
    }

    if (!found)
        *row = *col = ULONG_MAX;
    else
    {
        *row = i;
        *col = j-1;
    }
}

// Find the exit of the maze
void find_exit(char ** maze, size_t rows, size_t cols, size_t * row, size_t * col)
{
    size_t i = 0;
    size_t j = 0;
    int found = 0;

    while (i < rows && !found)
    {
        while (j < cols && !found)
        {
            found = (maze[i][j] == 'x');
            j++;
        }
        if (!found)
        {
            i++;
            j = 0;
        }
    }

    if (!found)
    {
        *row = ULONG_MAX;
        *col = ULONG_MAX;
    }
    else
    {
        *row = i;
        *col = j-1;
    }
}

// Verify whether the maze has been solved
int is_solved(char ** maze, size_t rows, size_t cols)
{
    size_t exit_i, exit_j, last_i, last_j, i, j;
    int solvable = 1;
    
    find_exit(maze, rows, cols, &exit_i, &exit_j);
    find_entry(maze, rows, cols, &i, &j);
    last_i = i;
    last_j = j;

    while (i != exit_i && j != exit_j && solvable == 1)
    {
        if (i+1 < rows && i+1 != last_i && maze[i+1][j] == 'o')
        {
            last_i = i;
            i++;
        }
        else if (i > 0 && i-1 != last_i && maze[i-1][j] == 'o')
        {
            last_i = i;
            i--;
        }
        else if (j+1 < cols && j+1 != last_j && maze[i][j+1] != 'o')
        {
            last_j = j;
            j++;
        }
        else if (j > 0 && j-1 != last_j && maze[i][j-1] != 'o')
        {
            last_j = j;
            j--;
        }
        else
            solvable = 0;
    }

    return solvable;
}

// Solver of the maze
char ** solve(char ** maze, size_t rows, size_t cols)
{
    size_t entry_row, entry_col;
    find_entry(maze, rows, cols, &entry_row, &entry_col);
    return solve_rec(maze, rows, cols, entry_row, entry_col);
}

char ** solve_rec(char ** maze, size_t rows, size_t cols, size_t row, size_t col)
{
    if (maze[row][col] == 'x')
        return maze;
    else
    {
        if (row+1 < rows && (maze[row+1][col] == ' ' || maze[row+1][col] == 'x'))
        {
            char ** maze_down = copy_maze(maze, rows, cols);
            maze_down[row+1][col] = maze_down[row+1][col] == 'x' ? 'x' : 'o';

            char ** result = solve_rec(maze_down, rows, cols, row+1, col);
            if (result != NULL)
                return result;
            else
                free(maze_down);
        }

        if (row > 0 && (maze[row-1][col] == ' ' || maze[row-1][col] == 'x'))
        {
            char ** maze_up = copy_maze(maze, rows, cols);
            maze_up[row-1][col] = maze_up[row-1][col] == 'x' ? 'x' : 'o';

            char ** result = solve_rec(maze_up, rows, cols, row-1, col);
            if (result != NULL)
                return result;
            else
                free(maze_up);
        }

        if (col+1 < cols && (maze[row][col+1] == ' ' || maze[row][col+1] == 'x'))
        {
            char ** maze_right = copy_maze(maze, rows, cols);
            maze_right[row][col+1] = maze_right[row][col+1] == 'x' ? 'x' : 'o';

            char ** result = solve_rec(maze_right, rows, cols, row, col+1);
            if (result != NULL)
                return result;
            else
                free(maze_right);
        }
        if (col > 0 && (maze[row][col-1] == ' ' || maze[row][col-1] == 'x'))
        {
            char ** maze_left = copy_maze(maze, rows, cols);
            maze_left[row][col-1] = maze_left[row][col-1] == 'x' ? 'x' : 'o';

            char ** result = solve_rec(maze_left, rows, cols, row, col-1);
            if (result != NULL)
                return result;
            else
                free(maze_left);
        }
        
        return NULL;
    }
}

