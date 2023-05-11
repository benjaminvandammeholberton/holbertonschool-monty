#include "monty.h"

/**
 * pall_function - function that prints all the values on the stack, starting from the top of the stack.
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void pall_function(sstack_t **stack, unsigned int line_number)
{
        sstack_t **temp;
        (void) line_number;
        if (*stack == NULL)
                return;
        temp = stack;
        while ((*temp)->next)
        {
                *temp = (*temp)->next;
        }
        while ((*temp)->prev)
        {
                printf("%d\n", (*temp)->n);
                *temp = (*temp)->prev;
                
        }
        printf("%d\n", (*temp)->n);
}