#include "shell.h"

/**
 * print_env - function that prints the ENV macro
 *
 */
void print_env(void)
{
	int i = 0;

	if (ENV == NULL)
	{
		write(STDOUT_FILENO, "nil", 3);
		write(STDOUT_FILENO, "\n", 1);
	}
	else
		for (i = 0; ENV[i]; i++)
		{
			write(STDOUT_FILENO, ENV[i], _strlen(ENV[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
}
/**
 * _strenv - function than validate if a strings is equals to env and print
 * @args: array of strings with the arguments
 * @status: int that keeps the error number
 *
 **/
int _strenv(char **args, int *status)
{
	int aux = 0;

	if (args == NULL)
		return (aux);
	if (_strcmp(args[0], "env") == 0)
	{
		if (args[1] == NULL)
		{
			aux++;
			print_env();
		}
		else
		{
			aux++;
			writErr(args[0]);
			writErr(": ");
			writErr(args[1]);
			writErr(": No such file or directory\n");
		}
	}
	return (aux);
}
