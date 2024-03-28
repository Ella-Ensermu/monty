#include "monty.h"
/**
 * f_pop - prints the top
 * @head: node head
 * @counter: line_number
 * Return: no return
*/
void f_pop(node_t **head, unsigned int counter)
{
	node_t *h;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty node\n", counter);
		fclose(data.file);
		free(data.content);
		free_node(*head);
		exit(EXIT_FAILURE);
	}
	h = *head;
	*head = h->next;
	free(h);
}
