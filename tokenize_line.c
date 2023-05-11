#include "monty.h"

/**
 * tokenize_line - function that tokenize the two first elements of a string
 * @line: string to tokenize
 * Return: a 2 elements array of strings
 */
char **tokenize_line (char *line)
{   
        char *token = NULL;
        char **arg = NULL;

        arg = malloc(sizeof(char *) * 2);
        token = strtok(line, "\n ");
        arg[0] = token;
        token = strtok(NULL, ("\n "));
        arg[1] = token;

        return(arg);
}