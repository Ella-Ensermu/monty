#include "monty.h"
/**
 * f_pint - prints the top
 * @head: node head
 * @counter: line_number
 * Return: no return
*/
void f_pint(node_t **head, unsigned int counter)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, node empty\n", counter);
		fclose(data.file);
		free(data.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
