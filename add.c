#include "monty.h"
/**
 * rephrased_add - adds the top two elements of the stack.
 * @top: stack top
 * @line_num: line_number
 * Return: no return
*/
void rephrased_add(stack_t **top, unsigned int line_num)
{
	stack_t *current;
	int length = 0, result;

	current = *top;
	while (current)
	{
		current = current->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*top);
		exit(EXIT_FAILURE);
	}
	current = *top;
	result = current->n + current->next->n;
	current->next->n = result;
	*top = current->next;
	free(current);
}
