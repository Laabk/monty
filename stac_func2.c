#include "monty.h"

/**
 * _swap_ - this func Swaps any top two elements of the stack.
 * @line_number: the Interger of line number of the opcode.
 * @stack:the pointer of pointer showing the top node of the stack.
 *
 */

void _swap_(stack_t **stack, unsigned int line_number)
{
	stack_t *op_templ;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	get_seve_ero(8, line_number, "swap");
	op_templ = (*stack)->next;
	(*stack)->next = op_templ->next;
	if (op_templ->next != NULL)
	op_templ->next->prev = *stack;
	op_templ->next = *stack;
	(*stack)->prev = op_templ;
	op_templ->prev = NULL;
	*stack = op_templ;
}

/**
 * _add_ - this func adds to top two elements of the stack involved
 * @line_number: the interger of line number of the opcode.
 * @stack: the Pointer to pointer showing the top node of stack.
 *
 */

void _add_(stack_t **stack, unsigned int line_number)
{
	int tota;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	get_seve_ero(8, line_number, "add");

	(*stack) = (*stack)->next;
	tota = (*stack)->n + (*stack)->prev->n;
	(*stack)->n = tota;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _sub_ - this func removes to the top two elements of the stack.
 * @line_number: the interger of line number of the opcode.
 * @stack: the pointer of pointer showing the top node of the stack.
 *
 */

void _sub_(stack_t **stack, unsigned int line_number)
{
	int tota;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

	get_seve_ero(8, line_number, "sub");


	(*stack) = (*stack)->next;
	tota = (*stack)->n - (*stack)->prev->n;
	(*stack)->n = tota;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _div_ - this functions adds to the top two elements of the stack.
 * @stack: Pointer to a pointer showing the top node the stack.
 * @line_number: Interger of line number of the opcode.
 *
 */

void _div_(stack_t **stack, unsigned int line_number)
{
	int dvi;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
	get_seve_ero(8, line_number, "div");

	if ((*stack)->n == 0)
	get_seve_ero(9, line_number);
	(*stack) = (*stack)->next;
	dvi = (*stack)->n / (*stack)->prev->n;
	(*stack)->n = dvi;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * _nop_ - this functionn does not change the oprerate
 * @line_number: the interger line number of the opcode.
 * @stack: the pointer of a pointer showing the top node of stack
 *
 */

void _nop_(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
