#include "monty.h"

/**
 * pop_function - function that removes the top element of the stack
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void pop_function(sstack_t **stack, unsigned int line_number)
{
        sstack_t *tmp = *stack;

	if (!tmp)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
        if (tmp->next == NULL)
        {
                *stack = NULL;
                free(tmp);
                return;
        }

	while (tmp->next != NULL)
                tmp = tmp->next;
	tmp = tmp->prev;
	free(tmp->next); 
        tmp->next = NULL;
}