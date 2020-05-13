#include "monty.h"

int code_exit = 0;
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
	if (rf == -1)
		print_error(3, argv[1]);
	read_buf(string, rf, of, size);
	free(string);
	free(of);
	if (code_exit == -1)
		exit(EXIT_FAILURE);
	return 0;
}

void eva_in(int argc)
{
	if (argc != 2)
		print_error(1, NULL);
}

void print_error(int code, char *argv)
{
	if (code == 1)
		printf("USAGE: monty file\n");
	else if (code == 2)
		printf("Error: Can't open file %s\n", argv);
	else if (code == 3)
		printf("Error: Can't read file %s\n", argv);
	else if (code == 4)
		printf("Error: malloc failed\n");
	else if (code == 5)
		
	exit(EXIT_FAILURE);
}

void read_buf(char *string, ssize_t rf, FILE *of, size_t size)
{
	unsigned int line_count = 0;
	stack_t **stack;

	stack = malloc(sizeof(stack_t));
    if (stack == NULL)
        print_error(4, NULL);
	while (rf >= 0)
	{
		/* Increment our line count */
		line_count++;
		separeitor(string, stack, line_count);
		if (code_exit == -1)
			break;
		/* Get the next line */
		rf = getline(&string, &size, of);
	} 
	free_dlistint(stack); 
}

char *global_variable;
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
		{NULL, NULL}
	};
	char delimit[] = " \t\n";
	char *token = strtok(string, delimit);
	int i, bandera = 0;
	char *operator = malloc(sizeof(char) * strlen(token));

	if (operator == NULL)
		print_error(4, NULL);
	strcpy(operator, token);
	token = strtok(NULL, delimit);
	global_variable = token;
	for (i = 0; i < 8; i++)
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
		printf("L%d: unknown instruction %s\n", line_number, operator);
		code_exit = -1;
	}
	free(operator);
}
