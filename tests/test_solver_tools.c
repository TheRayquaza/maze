/*
 * =====================================================================================
 *
 *       Filename:  test_solver.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/22 10:37:11
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <criterion/criterion.h>
#include <criterion/hooks.h>

#include "../solvers/solver_basic/solver_basic.h"
#include "../solvers/solver_tools.h"
#include "../tools/reader.h"

#define NB_MAZE 5

char files[NB_MAZE][15] =
{
    "samples/maze01",
    "samples/maze02",
    "samples/maze03",
    "samples/maze04",
    "samples/maze05",
};

Test(solver, find_entry)
{
    size_t * rows, * cols, * row, * col;
    char ** maze;
    rows = calloc(1, sizeof(size_t));
    cols = calloc(1, sizeof(size_t));
    row = calloc(1, sizeof(size_t));
    col = calloc(1, sizeof(size_t));

    // Maze 1
    maze = read_file(files[0], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 9);
    cr_assert(*col == 2);
    free_maze(maze,*rows);

    // Maze 2
    maze = read_file(files[1], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 4);
    cr_assert(*col == 1);
    free_maze(maze, *rows);

    // Maze 3
    maze = read_file(files[2], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 16);
    cr_assert(*col == 8);
    free_maze(maze, *rows);

    // Maze 4
    maze = read_file(files[3], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 4);
    cr_assert(*col == 2);
    free_maze(maze,*rows);

    // Maze 4
    maze = read_file(files[4], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 0);
    cr_assert(*col == 1);
    free_maze(maze,*rows);

    // Freeing everything
    free(rows);
    free(cols);
    free(col);
    free(row);

}

Test(solver, is_solved)
{

}

Test(solver, solve)
{

}

