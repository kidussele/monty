#include "monty.h"

void get_func(char *opcd, stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pop", pop},
		{NULL, NULL}
	};
	int i = 0;
	
	while (ops[i].opcode != NULL)
	{
		if (ops[i].opcode == opcd)
		{
			ops[i].f(stack, line_number);
			return;
		}
		i++;
	}
	fprintf(stderr, "L%i: unknown instruction %s\n", opcode);
	exit(EXIT_FAILURE);
	
}
