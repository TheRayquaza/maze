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

#include "testing_tools.h"
#include "../src/solver/solver.h"
#include "../src/reader/reader.h"

#define NB_MAZE 4

char files[NB_MAZE][15] =
{
    "samples/maze01",
    "samples/maze02",
    "samples/maze03",
    "samples/maze04",
};

Test(solver, find_entry)
{
    size_t * rows, * cols, * row, * col;
    char ** maze;
    // Maze 1
    rows = calloc(1, sizeof(size_t));
    cols = calloc(1, sizeof(size_t));
    maze = read_file(files[0], rows, cols);
    row = calloc(1, sizeof(size_t));
    col = calloc(1, sizeof(size_t));
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 9);
    cr_assert(*col == 2);
    free(maze);

    // Maze 2
    maze = read_file(files[1], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 4);
    cr_assert(*col == 1);
    free(maze);

    // Maze 3
    maze = read_file(files[2], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 16);
    cr_assert(*col == 8);
    free(maze);

    // Maze 4
    maze = read_file(files[3], rows, cols);
    find_entry(maze, *rows, *cols, row, col);
    cr_assert(*row == 4);
    cr_assert(*col == 2);
    free(maze);

    // Freeing everything
    free(rows);
    free(cols);
    free(col);
    free(row);

}

Test(solver, find_exit)
{
    size_t * rows, * cols, * row, * col;
    char ** maze;
    // Maze 1
    rows = calloc(1, sizeof(size_t));
    cols = calloc(1, sizeof(size_t));
    maze = read_file(files[0], rows, cols);
    row = calloc(1, sizeof(size_t));
    col = calloc(1, sizeof(size_t));
    find_exit(maze, *rows, *cols, row, col);
    cr_assert(*row == 0);
    cr_assert(*col == 5);
    free(maze);

    // Maze 2
    maze = read_file(files[1], rows, cols);
    find_exit(maze, *rows, *cols, row, col);
    cr_assert(*row == 0);
    cr_assert(*col == 2);
    free(maze);

    // Maze 3
    maze = read_file(files[2], rows, cols);
    find_exit(maze, *rows, *cols, row, col);
    cr_assert(*row == 2);
    cr_assert(*col == 15);
    free(maze);

    // Maze 4
    maze = read_file(files[3], rows, cols);
    find_exit(maze, *rows, *cols, row, col);
    cr_assert(*row == 3);
    cr_assert(*col == 14);
    free(maze);

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

