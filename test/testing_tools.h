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

#ifndef TESTING_TOOLS
#define TESTING_TOOLS

// Convert a char array into a char pointer
char * array2pointer(char array[], size_t col);

// Convert a char array array into a char pointer pointer
char ** maze2mazepointer(char *array[], size_t row, size_t col);

#endif
