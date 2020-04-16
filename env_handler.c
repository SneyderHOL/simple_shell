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
	char *env = "env";
	int i = 0, j = 0;

	for (; s1[i] != '\0'; i++)
	{
		if (s1[i] == 'e' || s1[i] == ' ')
		{
			for (j = 0; s1[i] != '\0' && env[j] != '\0' && s1[i] == env[j];)
			{
				if (s1[i] == 'v' && env[j] == 'v')
				{
					if (s1[i + 1] == '\n' || s1[i + 1] == ' ')
						print_env();
				}
				j++, i++;
			}
		}
		else if (s1[i] != 32 || s1[i] != 'e')
			return;
	}
}
