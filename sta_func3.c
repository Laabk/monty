#include "monty.h"

/**
 * _mul_ - this func adds top two elements of the stack.
 * @line_number: Interger the line number the opcode.
 * @stack: Pointer of another pointer showing top
 * node of stack.
 */

void _mul_(stack_t **stack, unsigned int line_number)
{
	int multi;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		get_seve_ero(8, line_number, "mul");

	(*stack) = (*stack)->next;
	multi = (*stack)->n * (*stack)->prev->n;
	(*stack)->n = multi;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}


/**
 * _mod_ - this func brings to the top two elements of the stack.
 * @stack: the pointer of another pointer showing the top node
 * of the stack.
 * @line_number: An interger of the line number of the opcode involved
 *
 */

void _mod_(stack_t **stack, unsigned int line_number)
{
	int modul;

	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)

	get_seve_ero(8, line_number, "mod");


	if ((*stack)->n == 0)
	get_seve_ero(9, line_number);
	(*stack) = (*stack)->next;
	modul = (*stack)->n % (*stack)->prev->n;
	(*stack)->n = modul;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
