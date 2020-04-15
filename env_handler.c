#include "shell.h"

/**
 * print_env - function that prints the ENV macro
 *
 */
void print_env(void)
{
	int i = 0;

	if (ENV == NULL)
		return;
/*  Devuelve error, imprime error? */

	for (i = 0; ENV[i]; i++)
	{
		write(STDOUT_FILENO, ENV[i], _strlen(ENV[i]));
		write(STDOUT_FILENO, "\n", 1);
	}
}
/**
 * _strenv - function than validate if a strings is equals to env and print
 * @s1: string input
 **/
void _strenv(char *s1)
{
	char *env = "env\n";

	for (; (*s1 != '\0' && *env != '\0') && *s1 == *env; s1++)
	{
		env++;
	}
	if ((*s1 - *env) != 0)
		return;
	print_env();
}
