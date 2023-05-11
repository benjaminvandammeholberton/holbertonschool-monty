#include "monty.h"

/**
 * freeandclose - function that frees a double linked list, a string and close a open file.
 * @head: first element of the list
 * @line: a string
 * @fp: a file 
 */
void freeandclose(sstack_t *head, char *line, FILE *fp)
{
	sstack_t *tmp;

	tmp = head;
	while (head != NULL)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
        free(line);
        fclose(fp);
}
