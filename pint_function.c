#include "monty.h"

/**
 * pint_function - function that prints the value at the top of the stack
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void pint_function(sstack_t **stack, unsigned int line_number)
{
        sstack_t **temp;
        (void) line_number;
        if (*stack == NULL)
        {
                fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
                exit(EXIT_FAILURE);
        }
        temp = stack;
        while ((*temp)->next)
        {
                *temp = (*temp)->next;
        }
        printf("%d\n", (*temp)->n);
}