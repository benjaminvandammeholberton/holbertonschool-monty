#include "monty.h"

/**
 * push_function - function that pushes an element to the stack.
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void push_function(sstack_t **stack, unsigned int line_number)
{
    	sstack_t *new;
	sstack_t *temp;
        int n = 0, i = 0;

        if (argumentPush == NULL)
                {
                        fprintf (stderr, "L%d: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                }
        while(argumentPush[i] != 0)
        {
                if (argumentPush[i] < 45 || argumentPush[i] > '9' || argumentPush[i] == 46 || argumentPush[i] == 47)
                {
                        fprintf (stderr, "L%d: usage: push integer\n", line_number);
                        exit(EXIT_FAILURE);
                }
                i++;
        }
        n = atoi(argumentPush);
	temp = *stack;
	new = malloc(sizeof(sstack_t));
	if (new == NULL)
        {
                fprintf(stderr, "Error: malloc failed");
		exit (EXIT_FAILURE);
        }
	if (*stack == NULL)
	{
		new->n = n;
		new->prev = NULL;
		new->next = *stack;
		*stack = new;
		return;
	}
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	temp->next = new;
	new->n = n;
	new->prev = temp;
	new->next = NULL;
	new = temp;  
}