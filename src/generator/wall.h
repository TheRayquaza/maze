/*
 * =====================================================================================
 *
 *       Filename:  wall.h
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  09/15/22 16:39:36
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdlib.h>

#ifndef WALL
#define WALL

typedef struct wall
{
    size_t row1;
    size_t row2;
    size_t col1;
    size_t col2;

    size_t rowe;
    size_t cole;

    unsigned char vertical;

} wall;

#endif
