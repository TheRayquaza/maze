/*
 * =====================================================================================
 *
 *       Filename:  testing_tools.c
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/19/22 12:12:10
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Mateo lelong, 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>
#include "testing_tools.h"

// Convert a char array into a char pointer
char * array2pointer(char array[], size_t col)
{
    char * result = calloc(col, sizeof(char));
    for (size_t i = 0; i < col; i++)
        *(result+i) = array[i];
    return result;
}

// Convert a char array array into a char pointer pointer
char ** maze2mazepointer(char *array[], size_t row, size_t col)
{
    char ** maze = calloc(row, col);
    for (size_t i = 0; i < row; i++)
        maze[i] = array2pointer(array[i], col);
    return maze;
}
