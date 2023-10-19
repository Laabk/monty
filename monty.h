#ifndef MONTY_H
#define MONTY_H

#define _GNU_SOURCE
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;/**/
	struct stack_s *next;/*thetail*/
} stack_t;

/**
 * struct instruction_s - opcode and its function name
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void funcs_node_stack(stack_t **, unsigned int);
void _add_stack(stack_t **, unsigned int);
extern stack_t *head;
typedef void (*op_func)(stack_t **, unsigned int);
stack_t *create_a_node(int n);
void _free_(void);
void _rotl_(stack_t **, unsigned int);
void _add_(stack_t **, unsigned int);
void _sub_(stack_t **, unsigned int);
void add_queue(stack_t **, unsigned int);
void funcs_open(char *th_file_name);
int funcs_parse(char *buffer, int line_number, int format);
void funcs_read(FILE *);
int _len(FILE *);
void funcs_finds(char *, char *, int, int);
void op_calls_funcs(op_func, char *, char *, int, int);
void funcs_print_stack(stack_t **, unsigned int);
void _pop_(stack_t **, unsigned int);
void _nop_(stack_t **, unsigned int);
void _swap_(stack_t **, unsigned int);
void func_print_character(stack_t **, unsigned int);
void func_print_str(stack_t **, unsigned int);
void _div_(stack_t **, unsigned int);
void _mul_(stack_t **, unsigned int);
void _mod_(stack_t **, unsigned int);
void get_ero_fun(int error_code, ...);
void get_seve_ero(int error_code, ...);
void ero_str_func(int error_code, ...);
void _rotr_(stack_t **, unsigned int);

#endif
