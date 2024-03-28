#include "monty.h"
/**
 * custom_print - prints the stack
 * @top: stack top
 * @count: not used
 * Return: no return
*/
void custom_print(stack_t **top, unsigned int count)
{
	stack_t *current;
	(void)count;

	current = *top;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
