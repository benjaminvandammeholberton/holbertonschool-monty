#include "monty.h"

/**
 * swap_function - function that swaps the top two elements of the stack.
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void swap_function(sstack_t **stack, unsigned int line_number)
{
        sstack_t *tmp = *stack;

        if ((*stack)->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        tmp = tmp->next;
        if (tmp->next == NULL)
        {
                fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
                exit(EXIT_FAILURE);
        }
        while (tmp->next)
                tmp = tmp->next;
        tmp->next = tmp->prev;
        tmp->prev->next = NULL;
       // printf("tmp->n-->%d\n", tmp->n);
      //  free(tmp);


}