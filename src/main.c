/*
 * =====================================================================================
 *
 *       Filename:  main.c
 *
 *    Description:  Main process of the maze generator and solver
 *
 *        Version:  1.0
 *        Created:  09/14/22 10:04:59
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization: 
 *
 *   Error : 0 - Nothing
 *           1 - Argument error
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>

#include "tools/tools.h"
#include "reader/reader.h"
#include "solver/solver.h"

int main(int argc, char *argv[])
{
    if (argc == 1)
    {
        printf("Not available for now\n");
        return EXIT_SUCCESS;
    }
    else if (argc == 2)
    {
        size_t rows = 0;
        size_t cols = 0;

        printf("Reading maze %s ...\n", argv[1]);
        char ** maze = read_file(argv[1], &rows, &cols);
        print_maze(maze, rows, cols);

        printf("Resolving the maze ...\n");
        char ** resolved = solve(maze, rows, cols);
        if (resolved == NULL)
            printf("Unable to find a valid path to resolve this maze\n");
        else
        {
            printf("The maze can be resolved :\n");
            print_maze(resolved, rows, cols);
        }
        
        return EXIT_SUCCESS;
    }
    else 
    {
        printf("Invalid amount of argument (1 or 2) \n");
        return EXIT_FAILURE;
    }
}
