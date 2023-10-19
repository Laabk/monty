#include "monty.h"

/**
 * _rotr_ - this func brings the last node of stack to the top.
 * @ln: Interger the line number of opcode.
 * @stack: Pointer of another pointer showing top node of a stacks
 *
 */

void _rotr_(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *op_templ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	op_templ = *stack;

	while (op_templ->next != NULL)
	op_templ = op_templ->next;

	op_templ->next = *stack;
	op_templ->prev->next = NULL;
	op_templ->prev = NULL;
	(*stack)->prev = op_templ;
	(*stack) = op_templ;
}


/**
 * func_print_character - this func prints all Ascii value.
 * @line_number: Interger of the line number of opcode involved
 * @stack: Pointer of anothrer pointer which is pointing to
 * top node of a stack.
 *
 */

void func_print_character(stack_t **stack, unsigned int line_number)
{
	int _asc;

	if (stack == NULL || *stack == NULL)
	ero_str_func(11, line_number);

	_asc = (*stack)->n;
	if (_asc < 0 || _asc > 127)
	ero_str_func(10, line_number);
	printf("%c\n", _asc);
}

/**
 * func_print_str - this func Prints the strings in
 * @stack: the Pointer of a pointer pointing to top node of a stack.
 * @ln: Interger of the line number of the opcode involved
 *
 */

void func_print_str(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *op_templ;
	int _asc;

	if (stack == NULL || *stack == NULL)
	{
		printf("\n");
		return;
	}

	op_templ = *stack;
	while (op_templ != NULL)
	{
		_asc = op_templ->n;
		if (_asc <= 0 || _asc > 127)
			break;
		printf("%c", _asc);
		op_templ = op_templ->next;
	}
	printf("\n");
}

/**
 * _rotl_ - changes first node of stack to bottom.
 * @ln: An interger of theline number of of the opcode.
 * @stack: the pointer another pointer showing the top
 * node of the stack.
 *
 */

void _rotl_(stack_t **stack, __attribute__((unused))unsigned int ln)
{
	stack_t *op_templ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	return;

	op_templ = *stack;
	while (op_templ->next != NULL)
	op_templ = op_templ->next;

	op_templ->next = *stack;
	(*stack)->prev = op_templ;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}
