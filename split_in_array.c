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
*
* Return: char pointer array with each argument
*/
char **split_a(char *line, ssize_t lineSize)
{
	ssize_t i = 0;
	int spaces = 0;
	char **array = NULL, *aux = NULL, *delim = " ";

	valid_exit(line);
	_strenv(line);
	for (; i < lineSize; i++)
		if (line[i] == *delim)
			spaces++;
	spaces += 2;
	array = malloc((spaces) * sizeof(char *));
	aux = strtok(line, delim);
	for (i = 0; aux; i++)
	{
		array[i] = aux;
		clean(array[i]);
		aux = strtok(NULL, delim);
	}
	array[i] = aux;
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
	printf("%i,", a);
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
		printf("%s,", a[i]);
	printf("\n");
}
