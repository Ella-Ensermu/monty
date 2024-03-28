#include "monty.h"
/**
* perform - executes the operation
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int perform(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t operations[] = {
				{"push", op_push}, {"pall", op_pall}, {"pint", op_pint},
				{"pop", op_pop},
				{"swap", op_swap},
				{"add", op_add},
				{"nop", op_nop},
				{"sub", op_sub},
				{"div", op_div},
				{"mul", op_mul},
				{"mod", op_mod},
				{"pchar", op_pchar},
				{"pstr", op_pstr},
				{"rotl", op_rotl},
				{"rotr", op_rotr},
				{"queue", op_queue},
				{"stack", op_stack},
				{NULL, NULL}
				};
	unsigned int i = 0;
	char *operation;

	operation = strtok(content, " \n\t");
	if (operation && operation[0] == '#')
		return (0);
	bus.arg = strtok(NULL, " \n\t");
	while (operations[i].opcode && operation)
	{
		if (strcmp(operation, operations[i].opcode) == 0)
		{	operations[i].f(stack, counter);
			return (0);
		}
		i++;
	}
	if (operation && operations[i].opcode == NULL)
	{ fprintf(stderr, "L%d: unknown instruction %s\n", counter, operation);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
