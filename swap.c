#include "monty.h"
/**
 * func_swap - adds the top two elements of the stack.
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *b;
	int len = 0, aux;

	b = *head;
	while (b)
	{
		b = b->nex;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(data.file);
		free(data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	b = *head;
	aux = b->num;
	b->num = b->nex->num;
	b->nex->num = aux;
}
