#include "shell.h"
/**
 * counter_space - function to counts the spaces in the string
 * @line: captured string
 * @lineSize: size of line variable
 * @delim: array with the characters to count
 *
 * Return: the amount of spaces that string contains
 */
int counter_space(char *line, ssize_t lineSize, char *delim)
{
	ssize_t i = 0;
	int spaces = 0, last_count = 0;

	for (i = 0; i < lineSize; i++)
	{
		if (i + 1 < lineSize)
		{
			if ((line[i] == delim[0] || line[i] == delim[1]))
			{
				if  (line[i + 1] == delim[0] || line[i + 1] == delim[1])
				{
					last_count = 0;
					continue;
				}
				else
				{
					if (last_count == 0)
						spaces++, last_count = 1;
					last_count = 0;
				}
			}
			else
			{
				if (line[i + 1] == delim[0] || line[i + 1] == delim[1])
				{
					if (last_count == 0)
						spaces++, last_count = 1;
					last_count = 0;
				}
				else
				{
					last_count = 0;
					continue;
				}
			}
		}
	}
	return (spaces);
}
/**
 * is_empty_string - function to check if the string is empty
 * @line: captured string
 * @lineSize: size of line variable
 *
 * Return: 1 if not empty, 0 otherwise
 */
int is_empty_string(char *line, ssize_t lineSize)
{
	ssize_t i = 0;
	int valid = 0, aux = 0;
	char c = 10;

	for (i = 0; i < lineSize; i++)
	{
		c = line[i];
		if (c != 10 && c != 4 && c != 32 && c != 9)
		{
			if (c == 46)
			{
				if (aux == 0)
					aux++;
				else
					return (++valid);
			}
			else
				return (++valid);
		}
	}
	return (valid);
}
/**
 * is_dot - function to check if the string is a dot
 * @line: captured string
 * @lineSize: size of line variable
 *
 * Return: 1 if string is not a dot, 0 otherwise
 */
int is_dot(char *line, ssize_t lineSize)
{
	ssize_t i = 0;
	int aux = 0;
	char c = 0, d = '.';

	for (i = 0; i < lineSize; i++)
	{
		c = line[i];
		if (c == d)
			return (++aux);

	}
	return (aux);
}
