#include "monty.h"
/**
 * insertNode - insert node at the beginning of the node
 * @head: head of the node
 * @value: new_value
 * Return: no return
*/
void insertNode(node_t **head, int value)
{

	node_t *newNode, *temp;

	temp = *head;
	newNode = malloc(sizeof(node_t));
	if (newNode == NULL)
	{ printf("Error\n");
		exit(0); }
	if (temp)
		temp->prev = newNode;
	newNode->n = value;
	newNode->next = *head;
	newNode->prev = NULL;
	*head = newNode;
}
