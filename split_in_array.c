#include "shell.h"
/**
 * free_grid - frees a 2 dimensional grid created
 * @grid: 2 dimensional integer array argument
 * @height: integer argument
 *
 */
void free_grid(char **grid, int height)
{
	int a = 0;

	for (a = 0; a < height; a++)
		free(grid[a]);
	free(grid);
}
/**
* split_a - function to split the capture line
* @line: captured string
* @lineSize: size of line variable
* @num_line: num times
* @pro_name: program name shell
* @status: status exit
*
* Return: char pointer array with each argument
*/
char **split_a(char *line, ssize_t lineSize, size_t num_line, char *pro_name,
		int *status)
{
	int spaces = 0, i = 0;
	char **array = NULL, *aux = NULL, delim[] = {' ', 9, '\0'};

	_strenv(line, status), valid_opt_help(line, status);
	if (valid_exit(line, num_line, pro_name, status) == 2)
		return (NULL);
	spaces = counter_space(line, lineSize, delim);
	spaces += 2;
	array = malloc(sizeof(char *) * spaces);
	if (array == NULL)
	{
		writErr("failed memory allocator\n");
		return (NULL);
	}
	aux = strtok(line, delim);
	for (i = 0; aux;)
	{
		if (aux[0] == '\n')
		{
			aux = strtok(NULL, delim);
			continue;
		}
		array[i] = aux;
		clean(array[i]);
		i++;
		aux = strtok(NULL, delim);
	}
	array[i] = NULL;
	if (array[0] == NULL)
		free(array), array = NULL;
	return (array);
}
/**
 * grid_size -function that calculates the size of a grid
 *
 * @grid: 2 dimensional integer array argument
 *
 * Return: the size of the grid
 */
int grid_size(char **grid)
{
	int a = 0;

	for (a = 0; grid[a]; a++)
	{
	}
	return (a);
}
/**
 * print_array - prints n elements of an array of strings
 * @a: array of strings to print
 * @n: amount of elements in the array
 *
 */
void print_array(char **a, int n)
{
	int i;

	for (i = 0; i < n; i++)
		_writ(a[i]);
	_putchar(10);
}
