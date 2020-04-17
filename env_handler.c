#include "shell.h"

/**
 * print_env - function that prints the ENV macro
 *
 */
void print_env(void)
{
	int i = 0;
	list_t *env_l = NULL, *aux = NULL;

	if (ENV == NULL)
	{
		write(STDOUT_FILENO, "nil", 3);
		write(STDOUT_FILENO, "\n", 1);
	}
	else
	{
		env_l = env_list();
		if (env_l == NULL)
			return;
		aux = env_l;
		for (i = 0; aux; i++)
		{
			write(STDOUT_FILENO, aux->str, aux->len);
			write(STDOUT_FILENO, "\n", 1);
			aux = aux->next;
		}
		free_list(env_l);
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
