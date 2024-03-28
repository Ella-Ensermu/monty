#include "monty.h"
/**
 * divide_top_two - divides the top two elements of the stack.
 * @stack_head: stack head
 * @line_num: line_number
 * Return: no return
*/
void divide_top_two(stack_t **stack_head, unsigned int line_num)
{
	stack_t *current;
	int length = 0, result;

	current = *stack_head;
	while (current)
	{
		current = current->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	current = *stack_head;
	if (current->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	result = current->next->n / current->n;
	current->next->n = result;
	*stack_head = current->next;
	free(current);
}
