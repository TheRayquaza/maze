/*
 * =====================================================================================
 *
 *       Filename:  solver_brute_force.c
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
#include <math.h>

#include "../solver_tools.h"
#include "solver_brute_force.h"
#include "../../tools/tools.h"

int maze_size;
size_t maze_index = 0;
size_t nb_mazes = 0;
char *** mazes;

// Solver of the maze
void solve(char ** maze, size_t rows, size_t cols)
{
    maze_size = rows*cols*sizeof(char);
    size_t entry_row, entry_col;
    find_entry(maze, rows, cols, &entry_row, &entry_col);
    
    mazes = malloc(sizeof(char*));

    solve_rec(maze, rows, cols, entry_row, entry_col);
}

void solve_rec(char ** maze, size_t rows, size_t cols, size_t row, size_t col)
{
    if (maze[row][col] == 'x')
        add_solution(mazes, maze, rows, cols, maze_size);
    else
    {
        if (row+1 < rows && (maze[row+1][col] == ' ' || maze[row+1][col] == 'x'))
        {
            char ** tmp = copy_maze(maze,rows, cols);
            tmp[row+1][col] = tmp[row+1][col] == 'x' ? 'x' : 'o';
            solve_rec(tmp, rows, cols, row+1, col);
            free_maze(tmp, rows);
        }

        if (row > 0 && (maze[row-1][col] == ' ' || maze[row-1][col] == 'x'))
        {
            char ** tmp = copy_maze(maze, rows, cols);
            tmp[row-1][col] = tmp[row-1][col] == 'x' ? 'x' : 'o';
            solve_rec(tmp, rows, cols, row-1, col);
            free_maze(tmp, rows);
        }

        if (col+1 < cols && (maze[row][col+1] == ' ' || maze[row][col+1] == 'x'))
        {
            char ** tmp = copy_maze(maze, rows, cols);
            tmp[row][col+1] = tmp[row][col+1] == 'x' ? 'x' : 'o';
            solve_rec(tmp, rows, cols, row, col+1);
            free_maze(tmp, rows);
        }
        if (col > 0 && (maze[row][col-1] == ' ' || maze[row][col-1] == 'x'))
        {
            char ** tmp = copy_maze(maze, rows, cols);
            tmp[row][col-1] = tmp[row][col-1] == 'x' ? 'x' : 'o';
            solve_rec(maze, rows, cols, row, col-1);
            free_maze(tmp, rows);
        }
    }
}


// Add maze solution in the mazes (size is given for malloc allocations)
void add_solution(char *** mazes, char ** maze, size_t rows, size_t cols, int size)
{
    mazes = realloc(mazes, (maze_index+1) * sizeof(char*) * size);
    mazes[maze_index] = copy_maze(maze, rows, cols);
    maze_index++;
}

// Find best Maze
char ** find_best(char *** mazes, size_t rows, size_t cols)
{
    size_t best_maze = 0;
    int best = INT_MAX;
    for (size_t i = 0; i < nb_mazes; i++)
    {
        int tmp = count_traces(mazes[i], rows, cols, best);
        if (tmp < best)
        {
            best = tmp;
            best_maze = i;
        }
    }
    return mazes[best_maze];
}

// Count the number of trace on a maze
int count_traces(char ** maze, size_t rows, size_t cols, int nb_max)
{
    int nb_traces = 0;
    for (size_t row = 0; row < rows; row++)
        for (size_t col = 0; col < cols; col++)
            if (maze[row][col] == 'o')
                nb_traces++;
    return nb_traces;          
}
