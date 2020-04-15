#include "shell.h"
/**
 * prompt - function that emulates the prompt in the shell
 * @program_name: program name shell
 * Return: no return
 */
void prompt(char *program_name)
{
	char *input_line = NULL, **args = NULL, *command_exist = NULL;
	int *status = malloc(sizeof(int)), eof_aux = 1;
	size_t len_line = 0, command_num = 0;
	ssize_t line_read_char = 0;
	pid_t child;

	*status = 0, signal(SIGINT, handle_sigint);
	while (1)
	{
		print_prompt();
		line_read_char = getline(&input_line, &len_line, stdin),
					*status = stat_ctr_c(*status), command_num++;
		if (line_checker(line_read_char, &eof_aux, &input_line, status) > 0)
		{
			free(input_line), input_line = NULL;
			if (eof_aux == 0)
				exit_prompt("($)\n", status);
			else
				continue;
		}
		args = split_a(input_line, line_read_char, command_num, program_name,
				status);
		if (args == NULL)
		{
			free(input_line), input_line = NULL,
			e_exit(&eof_aux, "($)\n", status);
			continue;
		}
		command_exist = handle_path(args[0], command_num, program_name, status);
		if (command_exist == NULL)
		{
			free(args), free(input_line), input_line = NULL,
			e_exit(&eof_aux, "($)\n", status);
			continue;
		}
		execute_command(&child, status, input_line, command_exist, args,
				command_num, program_name), free(input_line), input_line = NULL;
		if (eof_aux == 0)
			exit_prompt("($)\n", status);
	}
}

/**
 * line_checker - function that checks for the value of line_read_char variable
 * @line_read_char: variable that is goint to be evaluate
 * @eof_aux: int variable to operate
 * @input_line: string that may need to be free
 * @status: integer in case exit is executed
 *
 * Return: 1 if input_line is empty
 */
int line_checker(ssize_t line_read_char, int *eof_aux, char **input_line,
		int *status)
{
	int stat, aux = 0;

	if (line_read_char == EOF)
	{
		if (isatty(0))
			_putchar('\n');
		free(*input_line), stat = *status, free(status), exit(stat);
	}
	if (line_read_char < 0)
		stat = *status, free(status), failed_getline(*input_line);
	if (line_read_char > 0)
	{

		*eof_aux = eof_validator(*input_line);
		if (*input_line[0] == '\n')
			aux++;
	}
	if (is_empty_string(*input_line, line_read_char) == 0)
	{
		if (*eof_aux == 0)
			if (is_dot(*input_line, line_read_char) == 0)
			{
				_putchar('\n');
				free(*input_line);
				stat = *status;
				free(status);
				exit(stat);
			}
		aux++;
	}
	return (aux);
}
/**
 * print_prompt - print the prompt symbol
 *
 */
void print_prompt(void)
{
	if (isatty(0))
		_writ("($) ");
}
