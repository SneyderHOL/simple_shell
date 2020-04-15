#include "shell.h"

/**
 * failed_getline - function that exit the program when getline failed
 * @line: string containing the input line
 */
void failed_getline(char *line)
{
	if (line == NULL)
	{}
	writErr("Error with getline\n");
	exit(1);
}
/**
 * failed_fork - function that exit the program when fork failed
 * @path: string that contains the route of the command
 * @args: array of string that contins the arguments
 * @status: previos status
 *
 */
void failed_fork(char *path, char **args, int *status)
{
	int aux = 0;

	free(path);
	free_grid(args, grid_size(args));
	writErr("Error with fork\n");
	aux = *status, free(status), exit(aux);
}
/**
 * failed_exec - function that exit the program when execve failed
 * @line: string to free
 * @path: string to free
 * @args: array of string to free
 * @command_num: number of command introduced in the shell
 * @program_name: program name shell
 *
 */
void failed_exec(char *line, char *path, char **args,
		size_t command_num, char *program_name)
{
	writErr(program_name);
	writErr(": ");
	print_num_Error((int)command_num);
	writErr(": ");
	writErr(args[0]);
	writErr(": Failed to execute\n");
	free(args);
	free(path);
	free(line);
	exit(1);
}
