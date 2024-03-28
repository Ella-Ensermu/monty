#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct data_s - variables -args, file, line content
 * @arg: value
 * @file: pointer to monty file
 * @content: line content
 * @lifo: flag change stack <-> queue
 * Description: carries values through the program
 */
typedef struct data_s
{
	char *arg;
	FILE *file;
	char *content;
	int lifo;
}  data_t;
extern data_t bus;

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @num: integer
 * @preve: points to the previous element of the stack (or queue)
 * @nex: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int num;
	struct stack_s *preve;
	struct stack_s *nex;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @func: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
        char *opcode;
        void (*func)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void func_push(stack_t **head, unsigned int number);
void func_pall(stack_t **head, unsigned int number);
void func_pint(stack_t **head, unsigned int number);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
void func_pop(stack_t **head, unsigned int counter);
void func_swap(stack_t **head, unsigned int counter);
void func_add(stack_t **head, unsigned int counter);
void func_nop(stack_t **head, unsigned int counter);
void func_sub(stack_t **head, unsigned int counter);
void func_div(stack_t **head, unsigned int counter);
void func_mul(stack_t **head, unsigned int counter);
void func_mod(stack_t **head, unsigned int counter);
void func_pchar(stack_t **head, unsigned int counter);
void func_pstr(stack_t **head, unsigned int counter);
void func_rotl(stack_t **head, unsigned int counter);
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int n);
void addqueue(stack_t **head, int n);
void func_queue(stack_t **head, unsigned int counter);
void func_stack(stack_t **head, unsigned int counter);
#endif
