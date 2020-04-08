#include "shell.h"

/**
 * failed_split - function that exit the program when split function
 * failed
 * @line: string that need to be free before exit
 *
 */
void failed_split(char *line)
{
	free(line);
	write(STDOUT_FILENO, "Error 1\n", 8);
	exit(1);
}
/**
 * failed_getline - function that exit the program when getline failed
 *
 */
void failed_getline(void)
{
	write(STDOUT_FILENO, "Error with getline\n", 19);
	exit(1);
}
/**
 * failed_fork - function that exit the program when fork failed
 * @line: string to free
 * @args: array of string to free
 *
 */
void failed_fork(char *line, char **args)
{
	free(line);
	free_grid(args, grid_size(args));
	write(STDOUT_FILENO, "Error with fork\n", 16);
	exit(1);
}
/**
 * failed_path_exist - function that exit the program when command has
 *  not been found
 *
 */
void failed_path_exist(void)
{
	write(STDOUT_FILENO, "command not found\n", 18);
}
/**
 * failed_exec - function that exit the program when execve failed
 * @line: string to free
 * @path: string to free
 * @args: array of string to free
 *
 */
/*void failed_exec(char *line, char **args)*/
void failed_exec(char *line, char *path, char **args)
{
	write(STDOUT_FILENO, "command not found\n", 18);
	free(args);
	free(path);
	free(line);
	exit(1);
}
