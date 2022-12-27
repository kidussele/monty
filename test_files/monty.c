#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[])
{
	FILE *file;
	char *line_buff = NULL;
	size_t len = 0;
	ssize_t nread;
	char *opcode;
	stack_t *stack = NULL;
	size_t line_number = 0;
	
	if (argc != 2)
	{
		fprintf(stderr, "Usage: monty file\n");
		exit(EXIT_FAILURE);
	}
	
	file = fopen(argv[1], "r");
	
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	
	while((nread = getline(&line_buff, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line_buff, "\n\t\r ");
		if (!opcode && opcode[0] != '#')
		{
			get_func(opcode, &stack, line_number);
		}
		
	}
	fclose(file);
	return (0);
}
