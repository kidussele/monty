#include "monty.h"

void push(stack_t **stack, unsigned_int line_number)
{
	char *str = strtok(NULL, "\\n\t\r ");
	if (str[0] >= 48 && str[0] <= 57)
	{
		num = atoi(str);
		add_stack(stack, num)
	}
	else
	{
		fprintf(stderr, "L%i: Usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
}

void pall(stack_t **stack, unsigned_int line_number)
{
	stack_t *current = *stack;
	(void)line_number;
	
	if (current != NULL)
	{
		while(current != NULL)
		{
			printf("%i\n", current->n);
			current = current->next;
		}
	}
		
}

void pop(stack_t **stack, unsigned_int line_number)
{
	stack_t *temp = *stack;
	stack_t *current = temp->next;
	
	if (temp == NULL)
	{
		fprintf(stderr, "L%i: Can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	
	free(*stack);
	*stack = current;
}
