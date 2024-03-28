#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
/**
 * struct node_s - doubly linked list representation of a stack (or queue)
 * @value: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct node_s
{
    int value;
    struct node_s *prev;
    struct node_s *next;
} node_t;
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
extern data_t data;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
    char *opcode;
    void (*f)(node_t **stack, unsigned int line_number);
} instruction_t;
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char  *clean_line(char *content);
void f_push(node_t **head, unsigned int number);
void f_pall(node_t **head, unsigned int number);
void f_pint(node_t **head, unsigned int number);
int execute(char *content, node_t **head, unsigned int counter, FILE *file);
void free_stack(node_t *head);
void f_pop(node_t **head, unsigned int counter);
void f_swap(node_t **head, unsigned int counter);
void f_add(node_t **head, unsigned int counter);
void f_nop(node_t **head, unsigned int counter);
void f_sub(node_t **head, unsigned int counter);
void f_div(node_t **head, unsigned int counter);
void f_mul(node_t **head, unsigned int counter);
void f_mod(node_t **head, unsigned int counter);
void f_pchar(node_t **head, unsigned int counter);
void f_pstr(node_t **head, unsigned int counter);
void f_rotl(node_t **head, unsigned int counter);
void f_rotr(node_t **head, __attribute__((unused)) unsigned int counter);
void addnode(node_t **head, int n);
void addqueue(node_t **head, int n);
void f_queue(node_t **head, unsigned int counter);
void f_stack(node_t **head, unsigned int counter);
#endif
