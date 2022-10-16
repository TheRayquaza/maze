#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#include "../tools/tools.h"
#include "generator.h"
#include "wall.h"

// Generate an empty maze
char ** generate_empty_maze(size_t rows, size_t cols)
{
    char ** maze = malloc(0);

    for (size_t row = 0; row < rows; row++)
    {
        maze = realloc(maze, cols * (row+1));
        maze[row] = malloc(sizeof(char) * cols);

        for (size_t col = 0; col < cols; col++)
            maze[row][col] = ' ';
    }

    for (size_t row = 0; row < rows; row++)
        maze[row][0] = '#';
    for (size_t col = 0; col < cols; col++)
        maze[0][col] = '#';
    for (size_t row = 0; row < rows; row++)
        maze[row][cols-1] = '#';
    for (size_t col = 0; col < cols; col++)
        maze[rows-1][col] = '#';

    return maze;
}

// Construct a wall based on maze information
// Give the direction of the wall (vertical or horizontal)
wall * add_wall(char ** maze, size_t rows, size_t cols, size_t row, size_t col, int vertical)
{
    wall * wp = calloc(1, sizeof(wall));
    wp->vertical = vertical;
    // Vertical Wall
    if (wp->vertical)
    {
        // Fixed
        wp->row1 = wp->row2 = row;
        wp->col1 = wp->col2 = col;
        // Browsing 
        while (wp->col1 > 0 && maze[row][wp->col1] == ' ')
            wp->col1--;
        while (wp->col2 < cols && maze[row][wp->col2] == ' ')
            wp->col2++;
    }
    else
    {
        // Fixed
        wp->col1 = wp->col2 = col;
        wp->row1 = wp->row2 = row;
        // Browsing
        while (wp->row1 > 0 && maze[wp->row1][col] == ' ')
            wp->row1--;
        while (wp->row2 < rows && maze[wp->row2][col] == ' ')
            wp->row2++;
    }

    return wp;
}

// Find a random breach on a wall and set the entry
void find_breach(wall * wp)
{
    size_t drow = (size_t) abs((int) (wp->row2 - wp->row1));
    size_t dcol = (size_t) abs((int) (wp->col2 - wp->col1));

    if ((drow <= 2 && wp->vertical == 0) || (dcol <= 2 && wp->vertical == 1))
    {
        printf("Freeing wall %lu,%lu - %lu,%lu\n", wp->row1, wp->col1,
                    wp->row2, wp->col2);
        wp->vertical = 2;
    }
    else
    {
        if (wp->vertical)
        {
            wp->cole = wp->col1 + rand() % wp->col2;
            wp->rowe = wp->row1;
        }
        else
        {
            wp->rowe = wp->row1 + rand() % wp->row2;
            wp->cole = wp->col1;
        }
    }

}

// Split the wall into two walls
void split_wall(wall * w, wall * w1, wall * w2)
{
    // Assume w1 is either at the top or the left
    //        w2 is either at the bottom or the right
    w1->vertical = w->vertical;
    w2->vertical = w->vertical;
    if (w->vertical)
    {
        // Same vertical axis
        w1->row1 = w-> row1;
        w1->row2 = w->row1;
        w2->row1 = w->row1;
        w2->row2 = w->row1;
        // Same far left and far right points
        w1->col1 = w->col1;
        w2->col2 = w->col2;
        // Left wall right index is left to the breach
        w1->col2 = w->cole-1;
        // Right wall left index is right to the breach
        w2->col1 = w->cole+1;
    }
    else
    {
        // Same horizontal axis
        w1->col1 = w->col1;
        w1->col2 = w->col1;
        w2->col1 = w->col1;
        w2->col2 = w->col1;
        // Same bottom and top points
        w1->row1 = w->row2;
        w2->row2 = w->row2;
        // Top wall bottom index is upper to the breach
        w1->row2 = w->rowe-1;
        // Bottom wall top index is down to the breach
        w2->row1 = w->rowe+1;
    }

}

// Apply the rule of a wall
// ie : fill with # character the line given the information retained by the 
// wall
void apply_wall_rule(char ** maze, size_t rows, size_t cols, wall * w)
{
    printf("Applying rule (%lu,%lu)-(%lu,%lu)\n", w->row1, w->col1, w->row2, w->col2);
    // Since the wall is vertical : w->col1 and w->col2 are equals
    if (w->vertical == 0)
        for (size_t row = w->row1; row < rows && row <= w->row2; row++)
            maze[row][w->col1] = '#';
    // Since the wall is horizontal : w->row1 and w->row2 are equals
    else
        for (size_t col = w->col1; col < cols && col <= w->col2; col++)
            maze[w->row1][col] = '#';
    print_maze(maze, rows, cols);
}

// Generate walls
wall ** generate_walls(char ** maze, size_t rows, size_t cols, wall * w)
{
    wall ** wall_list = malloc(0);
    size_t ws = 0;
    printf("Dealing with wall : (%lu, %lu) : (%lu, %lu)\n", w->row1, w->col1,
            w->row2, w->col2);
    
    int i;
    if (w->vertical)
        i = (w->col2 > w->col1) ? w->col2 - w->col1 : w->row1 - w->row2;
    else
        i = (w->row2 > w->row1) ? w->row2 - w->row1 : w->row1 - w->row2; 
    i = 1 + rand() % i;

    printf("Generating %i walls\n", i);
    while (i > 0)
    {
        wall_list = realloc(wall_list, sizeof(wall) * (ws+1));
        if (w->vertical)
            wall_list[ws] = add_wall(maze, rows, cols, w->row1, rand()%cols, 0);
        else
            wall_list[ws] = add_wall(maze, rows, cols, rand()%rows, w->col1, 1);
        ws++;
        i--;
    }

    wall_list = realloc(wall_list, sizeof(wall) * (ws+1));
    wall_list[ws] = NULL;

    return wall_list;
}

// Generate the maze
char ** generate_maze(size_t * rows, size_t * cols)
{
    *rows = 10 + rand() % 50;
    *cols = 10 + rand() % 50;

    char ** maze = generate_empty_maze(*rows, *cols);
    wall * fst_wall = 
        add_wall(maze, *rows, *cols, rand()%*rows, rand()%*cols, rand() % 2);
    recursive_division(maze, *rows, *cols, fst_wall);
    return maze;
}

// Application of the recursive division algorithm on a maze
void recursive_division(char ** maze, size_t rows, size_t cols, wall * wp)
{
    // 1) Finding breach if the wall is sufficient
    find_breach(wp);

    if (wp->vertical != 2)
    {
        printf("Entering the if\n");
        wall * w1 = malloc(sizeof(wall));
        wall * w2 = malloc(sizeof(wall));
        // 2) Splitting walls
        split_wall(wp, w1, w2);
        // 3) Generate walls for w1
        wall ** list_w1 = generate_walls(maze, rows, cols, w1);
        free(w1);
        for (size_t i = 0; list_w1[i] != NULL; i++)
        {
            // 4) Apply rule wall on the constructed wall
            apply_wall_rule(maze, rows, cols, list_w1[i]);
            recursive_division(maze, rows, cols, list_w1[i]);
        }
        // 3) Generate walls for w2
        wall ** list_w2 = generate_walls(maze, rows, cols, w2);
        free(w2);
        for (size_t i = 0; list_w2[i] != NULL; i++)
        {
            // 4) Apply rule on the constructed wall
            apply_wall_rule(maze, rows, cols, list_w2[i]);
            recursive_division(maze, rows, cols, list_w2[i]);
        } 
    }
    else
        printf("Invalid Wall ...\n");
}


