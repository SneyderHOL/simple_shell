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
		return;
	}
	else
	{
		for (i = 0; ENV[i]; i++)
		{
			write(STDOUT_FILENO, ENV[i], _strlen(ENV[i]));
			write(STDOUT_FILENO, "\n", 1);
		}
		return;
	}
}
/**
 * _strenv - function than validate if a strings is equals to env and print
 * @s1: string input
 * @status: previos status
 **/
void _strenv(char *s1, int *status)
{
	char *env = "env";
	int i = 0, j = 0;

	for (i = 0; s1[i] != '\0'; i++)
	{
		if (s1[i] == 'e' || s1[i] == ' ')
		{
			for (j = 0; s1[i] != '\0' && env[j] != '\0' && s1[i] == env[j];)
			{
				if (s1[i] == 'v' && env[j] == 'v')
				{
					if (s1[i + 1] == '\n' || s1[i + 1] == ' ')
					{
						print_env();
						free(s1), free(status), prompt("hsh");
					}
				}
				j++, i++;
			}
		}
		else if (s1[i] != 32 || s1[i] != 'e')
			return;
	}
}
/**
 * env_list - function that split the environment variables in a list_t
 *
 * Return: a list with all the environment variables if any, NULL otherwise
 */
list_t *env_list(void)
{
	list_t *head = NULL;
	int i = 0;

	for (i = 0; ENV[i] != NULL; i++)
	{
		head = add_list(&head, ENV[i]);
	}
	return (head);
}
