#include "monty.h"

void add_node(stack_t **top, unsigned int line_num)
{
	int num, i = 0, invalid = 0;

	if (monty_data.argument)
	{
		if (monty_data.argument[0] == '-')
			i++;
		for (; monty_data.argument[i] != '\0'; i++)
		{
			if (monty_data.argument[i] > 57 || monty_data.argument[i] < 48)
				invalid = 1;
		}
		if (invalid == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			fclose(monty_data.file);
			free(monty_data.content);
			free_stack(*top);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		fclose(monty_data.file);
		free(monty_data.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}

	num = atoi(monty_data.argument);

	if (monty_data.lifo == 0)
		add_node_top(top, num);
	else
		add_node_bottom(top, num);
}
