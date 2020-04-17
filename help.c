#include "shell.h"
/**
 * _help - program that Read the content of a file and print
 *@status: previos status
 *@option: option of help
 */
void _help(char *option, int *status)
{
	int input;
	char buffer[3000];
	ssize_t num_bytes;

	input = open(option, O_RDONLY);
	if (input == -1)
		writErr("Error: Can't read file\n"), *status = 98;
	num_bytes = read(input, buffer, 3000);
	if (num_bytes == -1)
		writErr("Error: Can't read file\n"), *status = 98;
	write(1, buffer, num_bytes);
	if ((close(input)) == -1)
		writErr("Error: Can't close file\n"), *status = 100;
	free(option), free(status);
	prompt("hsh");
}
/**
 * valid_opt_help - function that produces output according to a format
 * @arg: type help
 * @status: previos status
 */
void valid_opt_help(char *arg, int *status)
{
	char *help = "help";
	int c1 = 0, c2 = 0, c3, c4;
	input opt_help[] = {{"help\n", _help}, {"exit\n", _help}, {"pwd\n", _help},
		{"hsh\n", _help},	{"cd\n", _help}, {NULL, NULL}};

for (; c1 <= 3; c1++)
	if (arg[c1] != help[c1])
		return;
if (c1 == 3)
	c1++;
while (arg[c1] != '\0')
{
if (arg[c1] == '-')
{
	c1++;
for (c2 = 0; c2 < 5; c2++)
{
	if (_strcmp((arg + c1), opt_help[c2].array) == 0)
	{
		for (c3 = 0; ENV[c3]; c3++)
			for (c4 = 0; ENV[c3][c4] != '\0'; c4++)
				if (ENV[c3][c4] == 'P' && ENV[c3][c4 + 1] == 'W')
					if (ENV[c3][c4 - 1] != 'D')
						arg = _strcpy(arg, ENV[c3]);
		arg = _strcat(arg, "/help_");
		arg = _strcat(arg, opt_help[c2].array);
		opt_help[c2].function_opc(arg, status);
	}
}
}
c1++;
}
}
/**
 * *_strcat - function that concatenates two strings
 * @dest: string final
 * @src: string for concatenate
 * Return: pointer with the resulting string dest
 */
char *_strcat(char *dest, char *src)
{
	short i = 0;
	int len = _strlen2(dest);

	while (src[i] != '\n')
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
	return (dest);
}
/**
 * *_strcpy - Function that copies the string pointed to by src,
 * including the terminating null byte (\0), to the buffer pointed to by dest
 * @dest: pointer destination to copy
 * @src: initial string
 * Return: value the pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0, j = 0;

	if (src[0] == 'P' && src[1] == 'W' && src[2] == 'D' &&
			src[3] == '=')
		i = 4;
	for (; src[i] != '\0'; i++, j++)
		dest[j] = src[i];
	dest[j] = '\0';
	return (dest);
}
/**
 * *_strstr2 - function that locates a substring
 * @haystack: string
 * @needle: substring
 * Return: a pointer to the beginning of the located substring, or NULL if the
 * substring is not found.
 */
char *_strstr2(char *haystack, char *needle)
{
	int j, aux;
	int i = 0;
	int len_nee = _strlen2(needle);

	if (needle[0] == '\0')
		return (haystack);
	while (haystack[i])
	{
		j = 0;
		aux = i;
		while (haystack[aux] == needle[j])
		{
			if (j == len_nee - 1)
			{
				return (haystack + i);
			}
			j++;
			aux++;
		}
		i++;
	}
	return (0);
}
