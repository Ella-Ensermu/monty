#include "monty.h"
/**
 * func_pint - prints the top
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_pint(stack_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", counter);
		fclose(data.file);
		free(data.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->num);
}
