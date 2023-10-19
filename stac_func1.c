#include "monty.h"

/**
 * _add_stack - this func adds a new node.
 * @ln: an Interger for line number of the opcode.
 * @new_node: the new node pointer
 *
 */

void _add_stack(stack_t **new_node, __attribute__((unused))unsigned int ln)
{
	stack_t *op_templ;

	if (new_node == NULL || *new_node == NULL)
	exit(EXIT_FAILURE);
	if (head == NULL)
	{
	head = *new_node;
	return;
	}
	op_templ = head;
	head = *new_node;
	head->next = op_templ;
	op_templ->prev = head;
}


/**
 * funcs_node_stack - this func adds a new node to the  stack iunvolv
 * @line_number: the line number of opcode.
 * @stack: the Pointer of a pointer locatin the top node of the stack
 *
 */

void funcs_node_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *op_templ;

	(void) line_number;
	if (stack == NULL)
	exit(EXIT_FAILURE);
	op_templ = *stack;
	while (op_templ != NULL)
	{
	printf("%d\n", op_templ->n);
	op_templ = op_templ->next;
	}
}

/**
 * _pop_ - this func adds a node to the stack.
 * @line_number: Interger of line number of the opcode involved
 * @stack: the pointer of a pointer showing top node of the stack.
 *
 */

void _pop_(stack_t **stack, unsigned int line_number)
{
	stack_t *op_templ;

	if (stack == NULL || *stack == NULL)
	get_seve_ero(7, line_number);

	op_templ = *stack;
	*stack = op_templ->next;
	if (*stack != NULL)
	(*stack)->prev = NULL;
	free(op_templ);
}

/**
 * funcs_print_stack - this func prints all nodes in the top
 * node of the stack.
 * @line_number: the Interger of line number of the opcode.
 * @stack: the pointer of a pointer showin the top node of stack.
 *
 */

void funcs_print_stack(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	get_seve_ero(6, line_number);
	printf("%d\n", (*stack)->n);
}
