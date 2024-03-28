#include "monty.h"
/**
 * func_push - add node to the stack
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_push(stack_t **head, unsigned int counter)
{
	int num, j = 0, flag = 0;

	if (data.arg)
	{
		if (data.arg[0] == '-')
			j++;
		for (; data.arg[j] != '\0'; j++)
		{
			if (data.arg[j] > 57 || bus.arg[j] < 48)
				flag = 1; }
		if (flag == 1)
		{ fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(data.file);
			free(data.content);
			free_stack(*head);
			exit(EXIT_FAILURE); }}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE); }
	num = atoi(data.arg);
	if (data.lifo == 0)
		addnode(head, n);
	else
		addqueue(head, n);
}
