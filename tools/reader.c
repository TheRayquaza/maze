/*
 * =====================================================================================
 *
 *       Filename:  reader.c
 *
 *    Description: Reader helps the game of life game to load a file and play
 *    the game with the generated board (from the file) 
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:30:52
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
#include <string.h>
#include <sys/types.h>
#include <limits.h>

#include "reader.h"


// READER
// Read the file and return its memory representation of int
char ** read_file(char * filename, size_t * rows, size_t * cols)
{
    FILE * fp = fopen(filename, "r");

    if (fp == NULL)
        return NULL;

    char ** maze = get_file_info(rows, cols, fp);
    fclose(fp);

    return maze;
}

// VERIFICATION
// Verify information on a file and return if the format is valid :
// -- the number of character by line
// -- the number of line
char ** get_file_info(size_t * nb_line, size_t * nb_chr_by_line, FILE * fp)
{
    char ** content = 0;
    char * buffer;
    size_t i = 0;
    size_t j = 0;
    char current_chr = '\0';

    *nb_line = 0;
    *nb_chr_by_line = ULONG_MAX;

    while (current_chr != EOF)
    {
        buffer = malloc(0);
        j = 0;
        current_chr = fgetc(fp);
        while (current_chr != EOF && current_chr != '\n')
        {
            buffer = realloc(buffer, sizeof(char) * (j+1));
            buffer[j] = current_chr;
            j++;

            current_chr = fgetc(fp);
        }
        if (*nb_chr_by_line == ULONG_MAX)
            *nb_chr_by_line = j;
        if (j != 0 && current_chr != EOF && j != *nb_chr_by_line)
            return NULL;

        content = (char **) realloc(content, (i+1) * sizeof(*content));
        if (content == NULL)
            return NULL;

        content[i] = (char *) malloc(j * sizeof(char));
        if (content[i] == NULL)
            return NULL;

        for (size_t k = 0; k < j; k++)
            content[i][k] = buffer[k];

        i++;
        free(buffer);
    }
    *nb_line = i-1;
    return content;
}
