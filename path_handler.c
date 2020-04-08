#include "shell.h"

/**
 * find_path_in_env - function that find the PATH in the ENV macro
 *
 * Return: the path string, or NULL if has been found
 */
char *find_path_in_env(void)
{
	int i = 0;
	size_t size = 0, j = 0;
	char *word = "PATH", *aux = NULL;

	size = _strlen(word);
	for (i = 0; ENV[i]; i++)
	{
		aux = ENV[i];
		for (j = 0; j < size; j++)
		{
			if (word[j] != aux[0])
				break;
			aux++;
		}
		if (j == size)
		{
			aux++;
			break;
		}
		aux = NULL;
	}
	if (aux != NULL)
		aux = _strdup(aux);
	return (aux);
}
/**
 * split_path - function that split the PATH environment variable in a list_t
 *
 * Return: a list with all the content found in PATH if any, NULL otherwise
 */
list_t *split_path(void)
{
	list_t *paths = NULL;
	char *path_content = NULL, *delim = ":";

	path_content = find_path_in_env();
	if (path_content != NULL)
	{
		paths = split_l(path_content, _strlen(path_content), delim);
		free(path_content);
	}
	return (paths);
}
/**
 * handle_path - function that handle the PATH environment variable
 * @command: command to find the PATH list_t
 *
 * Return: the path of the command if has been found, NULL otherwise
 */

char *handle_path(char *command)
{
	list_t *paths = NULL, *aux = NULL;
	char *found = NULL, *add_slash = NULL;
	int stat_result = 1;
	struct stat st;

	stat_result = stat(command, &st);
	if (stat_result == 0)
		return (_strdup(command));

	paths = split_path();
	if (paths == NULL)
		return (NULL);
	aux = paths;
	add_slash = str_concat("/", command);
	if (add_slash == NULL)
		aux = NULL;
	while (aux != NULL)
	{
		found = str_concat(aux->str, add_slash);
		if (found == NULL)
			break;
		stat_result = stat(found, &st);
		if (stat_result == 0)
			break;
		free(found);
		found = NULL;
		aux = aux->next;
	}
	if (stat_result != 0)
	{
		free(found);
		found = NULL;
	}
	free(add_slash);
	add_slash = NULL;
	free_list(paths);
	paths = NULL;
	return (found);
}
