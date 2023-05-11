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