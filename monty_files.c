#include "monty.h"

/**
 * funcs_read - this func reads an involved file
 * @fd: the file pointer
 * Return: nothing
 *
 */

void funcs_read(FILE *fd)
{
	int ln;
	char *buffer = NULL;
	size_t leng;
	int ft;

	leng = 0;
	ft = 0;

	for (ln = 1; getline(&buffer, &leng, fd) != -1; ln++)
	{
		ft = funcs_parse(buffer, ln, ft);
	}
	free(buffer);
}


/**
 * funcs_parse - ensures all lines are tokenised to ensuring the
 * function to call
 * @line_number: lthe ine number invpolved
 * @format: checkes if 0 Nodes will be a stack.
 * @buffer: the line which is in
 * if 1 nodes will be entered as a queue.
 * Return: Returns 0 for opcode is stack. 1 for queue.
 */

int funcs_parse(char *buffer, int line_number, int format)
{
	char *ocod;
	char *vl;
	const char *delim = "\n ";

	if (buffer == NULL)
		get_ero_fun(4);

	ocod = strtok(buffer, delim);
	if (ocod == NULL)
		return (format);
	vl = strtok(NULL, delim);

	if (strcmp(ocod, "stack") == 0)
		return (0);
	if (strcmp(ocod, "queue") == 0)
		return (1);

	funcs_finds(ocod, vl, line_number, format);
	return (format);
}

/**
 * op_calls_funcs - this func calls the required function to exe
 * @func: the function pointer
 * @val: the string of numeric value.
 * @ln: the numeber of line in the code
 * @obt: the string of the opcode.
 * @format: checks if 0 Nodes will be a stack.
 * if 1 nodes will be entered as a queue.
 *
 */

void op_calls_funcs(op_func func, char *obt, char *val, int ln, int format)
{
	stack_t *nod;
	int lg, d;

	lg = 1;
	if (strcmp(obt, "push") == 0)
	{
		if (val != NULL && val[0] == '-')
		{
			val = val + 1;
			lg = -1;
		}
		if (val == NULL)
			get_ero_fun(5, ln);
		for (d = 0; val[d] != '\0'; d++)
		{
			if (isdigit(val[d]) == 0)
				get_ero_fun(5, ln);
		}
		nod = create_a_node(atoi(val) * lg);
		if (format == 0)
			func(&nod, ln);
		if (format == 1)
			add_queue(&nod, ln);
	}
	else
		func(&head, ln);
}

/**
 * funcs_open - this opens a file that is involved
 * @th_file_name: file name
 * Return: nothing
 */

void funcs_open(char *th_file_name)
{
	FILE *fd = fopen(th_file_name, "r");

	if (th_file_name == NULL || fd == NULL)
		get_ero_fun(2, th_file_name);

	funcs_read(fd);
	fclose(fd);
}

/**
 * funcs_finds - searches the right function a an opcode
 * @value: the argument of opcode involved
 * @format: checkes as 0 Nodes will be used as a stack.
 * @opcode: the opcode involved
 * @ln: the line number involved
 * Return: nothing
 *
 */

void funcs_finds(char *opcode, char *value, int ln, int format)
{
	int d;
	int lg;

	instruction_t func_list[] = {
		{"push", _add_stack},
		{"pall", funcs_node_stack},
		{"pint", funcs_print_stack},
		{"pop", _pop_},
		{"nop", _nop_},
		{"swap", _swap_},
		{"add", _add_},
		{"sub", _sub_},
		{"div", _div_},
		{"mul", _mul_},
		{"mod", _mod_},
		{"pchar", func_print_character},
		{"pstr", func_print_str},
		{"rotl", _rotl_},
		{"rotr", _rotr_},
		{NULL, NULL}
	};

	if (opcode[0] == '#')
		return;

	for (lg = 1, d = 0; func_list[d].opcode != NULL; d++)
	{
		if (strcmp(opcode, func_list[d].opcode) == 0)
		{
			op_calls_funcs(func_list[d].f, opcode, value, ln, format);
			lg = 0;
		}
	}
	if (lg == 1)
		get_ero_fun(3, ln, opcode);
}
