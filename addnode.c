#include "monty.h"
/**
 * insertNode - insert node at the beginning of the stack
 * @head: head of the stack
 * @value: new_value
 * Return: no return
*/
void insertNode(stack_t **head, int value)
{

	stack_t *newNode, *temp;

	temp = *head;
	newNode = malloc(sizeof(stack_t));
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
