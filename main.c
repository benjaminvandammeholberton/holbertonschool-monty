#include "monty.h"
/**
 * main - function that executes command from a file
 * @argc: number of arguments
 * @argv: arguments given to the programm -- name of file to open and its
 * arguments
 * Return: 0 if success 
 */
int main (int argc, char **argv)
{
        FILE *fp;
        char *line = NULL;
        size_t len = 0;
        char **command = NULL;
        unsigned int line_number = 0;
        sstack_t *head = NULL;
        int read = 0, a = 0, j = 0;
        instruction_t instructions[] = {
		{"push", push_function},
		{"pall", pall_function},
                {"pint", pint_function},
		{"pop", pop_function},
                {"swap", swap_function},
		{"add", add_function},
                {"nop", nop_function}
	};

        checkargc(argc);
        fp = fopen(argv[1], "r");
        exitfpnull(fp, argv);
        while (1)
          {
                read = getline(&line, &len, fp);
                if (read == -1)
                        break;
                line_number++;
                command = tokenize_line(line);
                argumentPush = command[1];
                if (!command[0])
                {
                        free(command);
                        continue;
                }
                j = 0;
                while (j < 7)
                {
                        a = strcmp(command[0], (instructions[j].opcode));
                        if (a == 0)
                        {
                        instructions[j].f(&head, line_number);
                        free(command);
                        break;
                        } 
                        j++;
                }
                if (a != 0)
                {
                        fprintf(stderr, "L%d: unknown instruction %s\n", line_number, command[0]);
                        free(command);
                        freeandclose(head, line, fp);
                        exit(EXIT_FAILURE);
                }
        }
        freeandclose(head, line, fp);
        exit(EXIT_SUCCESS);
}


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
/**
 * add_function - function that adds the top two elemts of the stack
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void add_function(sstack_t **stack, unsigned int line_number)
{
        (void) stack;
        (void) line_number;
}
/**
 * nop_function - function that doesn't do anything
 * @stack: first element of the double linked list
 * @line_number: the number of the line in the file that orders the command  
 */
void nop_function(sstack_t **stack, unsigned int line_number)
{
        (void) stack;
        (void) line_number;
}

