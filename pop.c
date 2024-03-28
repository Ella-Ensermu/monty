#include "monty.h"
/**
 * func_pop - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_pop(stack_t **head, unsigned int counter)
{
	stack_t *b;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(data.file);
		free(data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	b = *head;
	*head = b->next;
	free(b);
}
