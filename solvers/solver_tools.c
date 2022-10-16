/*
 * =====================================================================================
 *
 *       Filename:  solver_tools.c
 *
 *    Description: Defintions of tools used by the solvers 
 *
 *        Version:  1.0
 *        Created:  10/16/22 19:51:57
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

#include "solver_tools.h"

// Copy maze
char ** copy_maze(char ** maze, size_t rows, size_t cols)
{
    char ** copied_maze = calloc(rows, sizeof(char*));
    for (size_t row = 0; row < rows; row++)
    {
        copied_maze[row] = calloc(cols, sizeof(char));
        for (size_t col = 0; col < cols; col++)
            copied_maze[row][col] = maze[row][col];
    }
    return copied_maze;
}

// Free a Maze
void free_maze(char ** maze, size_t rows)
{
    for (size_t row = 0; row < rows; row++)
        free(maze[row]);
    free(maze);
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

