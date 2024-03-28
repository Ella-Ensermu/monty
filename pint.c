#include "monty.h"
/**
 * print_top - prints the top element
 * @stack_head: stack head
 * @line_num: line number
 * Return: no return
*/
void print_top(stack_t **stack_head, unsigned int line_num)
{
	if (*stack_head == NULL)
	{
		fprintf(stderr, "L%u: can't print, stack empty\n", line_num);
		fclose(bus.file);
		free(bus.content);
		free_stack(*stack_head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack_head)->n);
}
