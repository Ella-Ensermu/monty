#include "monty.h"
/**
f_pall - prints the node
 * @head: node head
 * @counter: no used
 * Return: no return
*/
void f_pall(node_t **head, unsigned int counter)
{
	node_t *h;
	(void)counter;

	h = *head;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
