#include "monty.h"

/**
 * exitfpnull - fonction that check if a file exists
 * @argv: an array of strings
 * @fp: a file to check 
 */
void exitfpnull(FILE *fp, char **argv)
{
    if (fp == NULL)
        {
                fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
                exit(EXIT_FAILURE);
        }    
}
