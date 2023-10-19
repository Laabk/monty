#include "monty.h"

/**
 * main - the entry point of argmnt
 * @argv: the l ist of arguments involved
 * @argc: the number arguments passed involved
 * Return: 0
 *
 */

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
	fprintf(stderr, "USAGE: monty file\n");
	exit(EXIT_FAILURE);
	}
	funcs_open(argv[1]);
	_free_();
	return (0);
}

/**
 * create_a_node - this function Creates a node.
 * @n: a digit inside the node
 * Return: pointer to node. else NULL.
 *
 */

stack_t *create_a_node(int n)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	get_ero_fun(4);
	node->next = NULL;
	node->prev = NULL;
	node->n = n;
	return (node);
}

/**
 * _free_ - Freeing all nodes involved in the stack.
 */

void _free_(void)
{
	stack_t *op_templ;

	if (head == NULL)
		return;

	while (head != NULL)
	{
	op_templ = head;
	head = head->next;
	free(op_templ);
	}
}


/**
 * add_queue - this func adds a fresh node to the queue of line.
 * @ln: the line number of opcode.
 * @new_node: the new node pointer
 *
 */

void add_queue(stack_t **new_node, __attribute__((unused))unsigned int ln)
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
	while (op_templ->next != NULL)
		op_templ = op_templ->next;

	op_templ->next = *new_node;
	(*new_node)->prev = op_templ;

}
stack_t *head = NULL;
