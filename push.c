#include "monty.h"
/**
 * f_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/

void f_push(node_t **head, unsigned int counter)
{
	int value, j = 0, invalid = 0;

	if (data.arg)
	{
		if (data.arg[0] == '-')
			j++;
		for (; data.arg[j] != '\0'; j++)
		{
			if (data.arg[j] > 57 || data.arg[j] < 48)
				invalid = 1; }
		if (invalid == 1)

		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(data.file);
			free(data.content);
			free_node(*head);
			exit(EXIT_FAILURE); }}

	else
	{
		fclose(data.file);
		free(data.content);
		free_node(*head);
		exit(EXIT_FAILURE); }

	}

	value =atoi(data.arg);
	if (bus.lifo == 0)
		addnode(head, value);
	else
		addqueue(head, value);
}

