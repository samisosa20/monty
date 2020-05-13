#include "monty.h"

char *global_variable;
int code_exit = 0;
/**
 * main - The entry point to the file for the instructions to be executed
 * @argc : The number of arguments received
 * @argv : The arguments
 * Return: 0 or exit on fail (1)
 */

int main(int argc, char *argv[])
{
	FILE *of;
	char *string = NULL;
	size_t size = 0;
	ssize_t rf = 0;

	eva_in(argc);
	of = fopen(argv[1], "r");
	if (of == NULL)
		print_error(2, argv[1]);
	rf = getline(&string, &size, of);
	if (rf != EOF)
		read_buf(string, rf, of, size);
	free(string);
	fclose(of);
	if (code_exit == -1)
		exit(EXIT_FAILURE);
	return (0);
}

/**
 * eva_in - validates that the user input the file
 * @argc : The number of arguments received
*/

void eva_in(int argc)
{
	if (argc != 2)
		print_error(1, NULL);
}

/**
 * print_error - Print the possible errors
 * @argv : The arguments received
 * @code : the code of the error
*/

void print_error(int code, char *argv)
{
	if (code == 1)
		fprintf(stderr, "USAGE: monty file\n");
	else if (code == 2)
		fprintf(stderr, "Error: Can't open file %s\n", argv);
	else if (code == 3)
		fprintf(stderr, "Error: Can't read file %s\n", argv);
	else if (code == 4)
		fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
}

/**
 * read_buf - Read the file line by line
 * @string : The buffer to read
 * @rf : The command to reads
 * @of : The file to read
 * @size : The size of the file
*/

void read_buf(char *string, ssize_t rf, FILE *of, size_t size)
{
	unsigned int line_count = 0;
	stack_t *stack = NULL;

	while (rf >= 0)
	{
		/*printf("rf: %lu -> string: %s\n", rf,string);*/
		/* Increment our line count */
		line_count++;
		separeitor(string, &stack, line_count);
		if (code_exit == -1)
			break;
		/* Get the next line */
		rf = getline(&string, &size, of);
	}
	free_dlistint(stack);
	stack = NULL;
}

/**
 * separeitor - Separates and executes the instructions
 * @string : The buffer to read
 * @stack : The pointer to the instructions
 * @line_number : The line to read
*/

void separeitor(char *string, stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{NULL, NULL}
	};
	char delimit[] = " \t\n";
	char *token = strtok(string, delimit);
	int i, bandera = 0;
	char *operator = token;

	if (operator == NULL)
		return;
	token = strtok(NULL, delimit);
	global_variable = token;
	for (i = 0; i < 10; i++)
	{
		if (strcmp(ops[i].opcode, operator) == 0)
		{
			ops[i].f(stack, line_number);
			bandera = 0;
			break;
		}
		else
			bandera = 1;
		if (code_exit == -1)
			break;
	}
	if (bandera == 1)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, operator);
		code_exit = -1;
	}
}
