#include "shell.h"

/**
 * find_path_in_env - function that find the PATH in the ENV macro
 *
 * @args: command to find the PATH list_t
 * @num: number of secuence
 * @program_name: program name shell
 * Return: the path string, or NULL if has been found
 */
char *find_path_in_env(char *args, size_t num, char *program_name)
{
	int i = 0;
	size_t size = 0, j = 0;
	char *word = "PATH", *aux = NULL, *env_variable = NULL;

	if (ENV == NULL)
	{
		failed_env_noexist(args, num, program_name);
		return (NULL);
	}
	size = _strlen(word);
	for (i = 0; ENV[i]; i++)
	{
		aux = ENV[i];
		env_variable = strtok(aux, "=");
		if (size != _strlen(env_variable))
		{
			env_variable = NULL;
			continue;
		}
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
 * @args: command to find the PATH list_t
 * @num: number of secuence
 * @program_name: program name shell
 *
 * Return: a list with all the content found in PATH if any, NULL otherwise
 */
list_t *split_path(char *args, size_t num, char *program_name)
{
	list_t *paths = NULL;
	char *path_content = NULL, *delim = ":";

	path_content = find_path_in_env(args, num, program_name);
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
 * @command_num: number of secuence
 * @program_name: program name shell
 * @statusP: previos status
 *
 * Return: the path of the command if has been found, NULL otherwise
 */

char *handle_path(char *command, size_t command_num, char *program_name,
	int *statusP)
{
	list_t *paths = NULL, *aux = NULL;
	char *found = NULL, *add_slash = NULL;
	int status = -1;

	status = check_for_file(command);
	if (status == 0)
		return (_strdup(command));
	else if (status == 1 || status == 2)
	{
		failed_permissions(command, command_num, program_name),
			*statusP = 126;
		return (NULL);
	}
	if (command[0] == '/')
	{
		failed_command_noexist(command, command_num, program_name),
			*statusP = 127;
		return (NULL);
	}
	paths = split_path(command, command_num, program_name);
	if (paths == NULL)
	{
		failed_command_noexist(command, command_num, program_name),
			*statusP = 127;
		return (NULL);
	}
	aux = paths, add_slash = str_concat("/", command);
	if (add_slash == NULL)
		aux = NULL;
	find_command_in_path(aux, &found, add_slash, &status);
	if (is_command_found(found, command, command_num, program_name, status) < 0)
	{
		failed_command_noexist(command, command_num, program_name),
		free(add_slash), free_list(paths), *statusP = 127;
		return (NULL);
	}
	free(add_slash);
	free_list(paths);
	return (found);
}

/**
 * find_command_in_path - function that finds the route of the command in PATH
 * @aux: node containing a route of PATH
 * @found: route in PATH containing the command
 * @add_slash: command starting with / to search in PATH
 * @status: result if the command is found in PATH
 *
 */
void find_command_in_path(list_t *aux, char **found, char *add_slash,
			int *status)
{
	while (aux != NULL)
	{
		*found = str_concat(aux->str, add_slash);
		if (*found == NULL)
			break;
		*status = check_for_file(*found);
		if (*status > -1)
			break;
		free(*found);
		*found = NULL;
		aux = aux->next;
	}
}
/**
 * is_command_found - function that checks if the command is found in PATH,
 * and checks for the result in status
 * @found: route of the command searched
 * @command: command searched in the PATH
 * @command_num: number of command introduced in the shell
 * @program_name: program name shell
 * @status: result if the command is found
 * Return: 0 success or number of status
 *
 */
int is_command_found(char *found, char *command, size_t command_num,
	char *program_name, int status)
{
	if (status != 0)
	{
		if (status > 0)
		{
			if (found != NULL)
			{
				free(found);
				failed_permissions(command, command_num, program_name);

			}
		}
		else
			return (found = NULL, status);
	}
	return (0);
}
