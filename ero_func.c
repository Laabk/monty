#include "monty.h"

/**
 * ero_str_func - this func cares for alll the errors in the strings
 * involved
 * (10) = The number inside a node is outside ASCII bounds.
 * @ero_line: error lines present involves the following:
 *
 */

void ero_str_func(int ero_line, ...)
{
	int len;
	va_list agmnt;

	va_start(agmnt, ero_line);
	len = va_arg(agmnt, int);
	switch (ero_line)
	{
		case 10:
			fprintf(stderr, "L%d: can't pchar, value out of range\n", len);
			break;
		case 11:
			fprintf(stderr, "L%d: can't pchar, stack empty\n", len);
			break;
		default:
			break;
	}
	_free_();
	exit(EXIT_FAILURE);
}

/**
 * get_ero_fun - this Prints error messages showed by their error code.
 * (1) = user gives one file to the program
 * (4) = the program is unable to malloc more memory.
 * (5) = the parameter passed to the instruction "push" is not an int.
 * (7) = the stack is an empty for pop.
 * (8) = the stack is too short for operation.
 * @ero_line: The ero line involve the
 *
 */

void get_ero_fun(int ero_line, ...)
{
	int len;
	va_list agmnt;
	char *obt;

	va_start(agmnt, ero_line);
	switch (ero_line)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(agmnt, char *));
			break;
		case 3:
			len = va_arg(agmnt, int);
			obt = va_arg(agmnt, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", len, obt);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(agmnt, int));
			break;
		default:
			break;
	}
	_free_();
	exit(EXIT_FAILURE);
}

/**
 * get_seve_ero - this takes the errors presents into consideratioin
 * (8) = if stack present is short in operation.
 * (9) = there is a dvision by zero int.
 * @ero_line: The error codes are the following:
 *
 */

void get_seve_ero(int ero_line, ...)
{
	int len;
	va_list agmnt;
	char *obt;

	va_start(agmnt, ero_line);
	switch (ero_line)
	{
		case 6:
			fprintf(stderr, "L%d: can't pint, stack empty\n",
				va_arg(agmnt, int));
			break;
		case 7:
			fprintf(stderr, "L%d: can't pop an empty stack\n",
				va_arg(agmnt, int));
			break;
		case 8:
			len = va_arg(agmnt, unsigned int);
			obt = va_arg(agmnt, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", len, obt);
			break;
		case 9:
			fprintf(stderr, "L%d: division by zero\n",
				va_arg(agmnt, unsigned int));
			break;
		default:
			break;
	}
	_free_();
	exit(EXIT_FAILURE);
}
