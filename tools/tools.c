/*
 * =====================================================================================
 *
 *       Filename:  tools.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/14/22 11:05:29
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo Lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

void print_maze(char ** maze, size_t rows, size_t cols)
{
    for (size_t row = 0; row < rows; row++)
    {
        for (size_t col = 0; col < cols; col++)
            printf("%c%c", maze[row][col], maze[row][col]);
        printf("\n");
    }
}
