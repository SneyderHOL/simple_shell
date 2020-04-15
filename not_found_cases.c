#include "shell.h"
/**
 * failed_command_exist - function that exit the program when command has
 *  not been found
 * @args: array of string that contains the arguments
 * @num: number of command introduced in the shell
 * @program_name: program name shell
 *
 */
void failed_command_exist(char *args, size_t num, char *program_name)
{
	writErr(program_name);
	writErr(": ");
	print_num_Error((int)num);
	writErr(": ");
	writErr(args);
	writErr(": not found\n");
	free(args);
	args = NULL;
}
/**
 * failed_permissions - function that prints error message when non permissions
 * @args: array of string to free
 * @command_num: number of command introduced in the shell
 * @program_name: program name shell
 *
 */
void failed_permissions(char *args, size_t command_num, char *program_name)
{
	writErr(program_name);
	writErr(": ");
	print_num_Error((int)command_num);
	writErr(": ");
	writErr(args);
	writErr(": Permission denied\n");
}
/**
 * failed_command_noexist - function that exit the program when command has
 *  not been found
 * @args: array of string that contins the arguments
 * @num: number of command introduced in the shell
 * @program_name: program name shell
 */
void failed_command_noexist(char *args, size_t num, char *program_name)
{
	writErr(program_name);
	writErr(": ");
	print_num_Error((int)num);
	writErr(": ");
	writErr(args);
	writErr(": not found\n");
}
/**
 * failed_env_noexist - function that exit the program when command has
 *  not been found
 * @args: array of string that contins the arguments
 * @num: number of command introduced in the shell
 * @program_name: program name shell
 */
void failed_env_noexist(char *args, size_t num, char *program_name)
{
	writErr(program_name);
	writErr(": ");
	print_num_Error((int)num);
	writErr(": ");
	writErr(args);
	writErr(": not found\n");
}
