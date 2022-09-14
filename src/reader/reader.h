/*
 * =====================================================================================
 *
 *       Filename:  reader.h
 *
 *    Description:  Read the 2d state of the game of life stored in a
 *    matrix-file
 *
 *        Version:  1.0
 *        Created:  09/10/22 10:19:46
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author: Mateo Lelong
 *   Organization:  
 *
 * =====================================================================================
 */
#include <stdio.h>
#include <stdlib.h>

// READER
// Read the file and return its memory representation of int
char ** read_file(char * filename, size_t * rows, size_t * cols);

// VERIFICATION
// Verify information on a file : 
// -- the number of character by line
// -- the number of line
char ** get_file_info(size_t * nb_line, size_t * nb_chr_by_line, FILE * fp);

