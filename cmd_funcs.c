#include "monty.h"

/**
 * isnumber - checks if the argv[2] is a number
 * @s: a pointer to the 3nd argument
 *
 * Return: 1 on success; otherwise, -1.
 */

int isnumber(char *s)
{
	unsigned int i;

	i = 0;

	if (!s)
		return (-1);

	if (*s == '-' || *s == '+')
	{
		s++;
		i++;
	}
	if (*s == '\0')
		return (-1);

	for (; i < strlen(s); i++)
	{
		if (s[i] < '0' || s[i] > '9')
			return (-1);
	}
	return (1);
}
/**
 * get_instruc_func - a function that reads command string and selects
 * the correct function to perform
 * @s: command string
 *
 * Return: a pointer to the corresponding function
 */
void (*get_instruc_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", _div},
		{"mul", _mul},
		{NULL, NULL}
	};
	int i;

	i = 0;

	while (ops[i].opcode != NULL)
	{
		if (strcmp(s, ops[i].opcode) == 0)
		{
			return (ops[i].f);
		}
		i++;
	}
	exit(-1);
}
/**
 * interpret_command - interprets a string to see if it's a
 * Monty ByteCode command
 * @buf: buffer storing line to parse
 * @line_number: line number in bytecode instruction
 * @fd: file descriptor
 * @fpointer: file pointer
 */
void interpret_command(char *buf, unsigned int line_number,
		       int fd, FILE *fpointer)
{
	char *token;
	int status;

	token = strtok(buf, " \t\n");
	if (token == NULL || *token == '#')
		return;
	status = check_valid_instruc(token, line_number, buf);
	if (status == -1)
	{
		close(fd);
		fclose(fpointer);
		exit(EXIT_FAILURE);
	}
	if (strcmp(token, "push") == 0)
	{
		push(&stack, line_number);
	}
	else
	{
		get_instruc_func(token)(&stack, line_number);
	}
}
