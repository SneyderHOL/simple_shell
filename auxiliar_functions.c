#include "shell.h"
/**
 * eof_validator - function that validate if the string have a end of file char
 * @str: string to operate
 *
 * Return: 0 if strings has eof char, 1 otherwise
 */
int eof_validator(char *str)
{
	int valid = 0, i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i]; i++)
		if (str[i] == '\n')
			return (++valid);
	return (valid);
}
/**
 * check_for_file - function that validate if the command is a
 * executable file and have execution permission.
 * @command: string with the route to a executable file
 *
 * Return: specific number according to a condition
 */
int check_for_file(char *command)
{
	int stat_result = 1;
	struct stat st;

	stat_result = stat(command, &st);
	if (stat_result == 0)
	{
		if (S_ISREG(st.st_mode))
		{
			if (access(command, X_OK) != 0)
				stat_result = 2;
		}
		else
			stat_result = 1;
	}
	return (stat_result);
}
/**
 * execute_command - function that executes exeve system call
 * @child: pid_t to manage fork function
 * @status: integer to manage the wait function
 * @input_line: string capture with get line
 * @command_exist: command found to execute
 * @args: string array with arguments enter by user
 * @command_num: number of command introduced in the shell
 * @program_name: program name shell
 *
 */
void execute_command(pid_t *child, int *status, char *input_line,
char *command_exist, char **args, size_t command_num, char *program_name)
{
	int child_exit = 0;

	*child = fork();
	if (*child == -1)
		failed_fork(command_exist, args, status);
	if (*child == 0)
	{
		if (execve(command_exist, args, NULL) == -1)
			free(status), failed_exec(input_line, command_exist, args,
				command_num, program_name);
	}
	else
		wait(status), free(command_exist), free(args);
	child_exit = WEXITSTATUS(*status);
	if (child_exit != 0)
		*status = child_exit;
}
/**
 * e_exit - function that prints a message before leaving prompt
 * @str: string to print
 * @status: status exit
 * @eof_aux: number of characters
 *
 */
void e_exit(int *eof_aux, char *str, int *status)
{
	int stat;

	if (*eof_aux == 0)
	{
		if (str != NULL)
			_writ(str);
		stat = *status, free(status), exit(stat);
	}
}
/**
 * dot_slash_compare - function that validate if a string have a
 * @command: string to operate
 *
 * Return: 1 if have a special character, 0 otherwise
 */
int dot_slash_compare(char *command)
{
	int aux = 0, len = 0;
	char c = '\0', d = '\0';

	len = _strlen(command);
	c = command[0];
	d = command[1];
	if (len > 2)
	{
		if (c == '/' || (c == '.' && d == '/'))
			aux++;
	}
	else
	{
		if (c == '/')
			aux++;
	}
	return (aux);
}
