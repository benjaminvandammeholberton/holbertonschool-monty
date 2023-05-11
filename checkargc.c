#include "monty.h"

/**
 * checkargc - function that check if an array of strings contains 2 elements
 * @argc: an array of strings 
 */
void checkargc(int argc)
{
         if (argc != 2)
        {
                fprintf(stderr, "USAGE: monty file\n");
                exit (EXIT_FAILURE);
        } 
}