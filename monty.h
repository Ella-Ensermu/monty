#ifndef MONTY_H
#define MONTY_H
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>
 
typedef struct instruction_s
{
    char *op;
    void (*func)(stack_t **stack, unsigned int line_num);
} instruction_t;
 
typedef struct stack_s
{
    int num;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;
 
typedef struct bus_s
{
    char *arg;
    FILE *file;
    char *content;
    int lifi;
} bus_t;
 
extern bus_t bus;
 
char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void push(stack_t **head, unsigned int num);
void pall(stack_t **head, unsigned int num);
void pint(stack_t **head, unsigned int num);
int execute(char *content, stack_t **head, unsigned int counter, FILE *file);
void free_stack(stack_t *head);
 
char **strtow(char *str, char *delims);
char *get_int(int n);
 
int usage_error(void);
int malloc_error(void);
int open_error(char *filename);
int unknown_op_error(char *op, unsigned int line_num);
int no_int_error(unsigned int line_num);
int pop_error(unsigned int line_num);
int pint_error(unsigned int line_num);
int short_stack_error(unsigned int line_num, char *op);
int div_error(unsigned int line_num);
int pchar_error(unsigned int line_num, char *message);
 
void pop(stack_t **head, unsigned int counter);
void swap(stack_t **head, unsigned int counter);
void add(stack_t **head, unsigned int counter);
void nop(stack_t **head, unsigned int counter);
void sub(stack_t **head, unsigned int counter);
void div(stack_t **head, unsigned int counter);
void mul(stack_t **head, unsigned int counter);
void mod(stack_t **head, unsigned int counter);
void pchar(stack_t **head, unsigned int counter);
void pstr(stack_t **head, unsigned int counter);
void rotl(stack_t **head, unsigned int counter);
void rotr(stack_t **head, __attribute__((unused)) unsigned int counter);
void addnode(stack_t **head, int num);
void addqueue(stack_t **head, int num);
void queue(stack_t **head, unsigned int counter);
#endif
