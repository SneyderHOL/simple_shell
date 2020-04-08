#include "shell.h"

/**
 * char_validator - function that validate if the string have a special char
 * @str: string to operate
 *
 * Return: 0 if not special char has been found, and 1 otherwise
 */
int char_validator(char *str)
{
	int valid = 0, i, j;
	char spc_chars[] = {'|', ';', '<', '>', '\0'};

	for (i = 0; str[i]; i++)
		for (j = 0; spc_chars[j]; j++)
			if (str[i] == spc_chars[j])
				return (++valid);
	return (valid);
}
/**
 * print_env - function that prints the ENV macro
 *
 */
void print_env(void)
{
	int i = 0;

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
