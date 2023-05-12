#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

char *argumentPush = NULL;

/**
 * struct sstack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct sstack_s
{
        int n;
        struct sstack_s *prev;
        struct sstack_s *next;
} sstack_t;


/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*f)(sstack_t **stack, unsigned int line_number);
} instruction_t;


char **tokenize_line (char *line);
void push_function(sstack_t **stack, unsigned int line_number);
void pall_function(sstack_t **stack, unsigned int line_number);
void pop_function(sstack_t **stack, unsigned int line_number);
void swap_function(sstack_t **stack, unsigned int line_number);
void pint_function(sstack_t **stack, unsigned int line_number);
void add_function(sstack_t **stack, unsigned int line_number);
void nop_function(sstack_t **stack, unsigned int line_number);
void sub_function(sstack_t **stack, unsigned int line_number);
void freeandclose(sstack_t *head, char *line, FILE *fp);
void checkargc(int argc);
void exitfpnull(FILE *fp, char **argv);

#endif


