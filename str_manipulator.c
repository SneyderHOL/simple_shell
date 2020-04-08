#include "shell.h"
/**
 *_strlen - calculate the length of a string
 *@s: char pointer
 *
 *Return: the length of a string
 */
size_t _strlen(char *s)
{
	size_t a;

	for (a = 0; s[a] != 0; a++)
	{
	}
	return (a);
}
/**
* clean - function to clean a string
* @str: string to clean
*
*/
void clean(char *str)
{
	int i;

	for (i = 0; str[i]; i++)
		if (str[i] == 10)
			str[i] = '\0';
}
/**
 * _strdup - returns a pointer to a newly allocated space in memory, which
 * contains a copy of the string given as a parameter
 * @str: char pointer argument
 *
 * Return: char pointer
 */
char *_strdup(char *str)
{
	char *poin = NULL;
	int i, j = 0;

	if (str == NULL)
		return (NULL);
	for (i = 0; *(str + i); i++)
	{
		j++;
	}
	j++;
	poin = malloc(j * sizeof(char));
	if (poin == NULL)
		return (NULL);
	for (i = 0; i < j; i++)
		*(poin + i) = *(str + i);
	return (poin);
}
/**
* _strcmp - function than validate if two strings are equals
* @s1: string 1
* @s2: string 2
*
* Return: 0 if match
**/
int _strcmp(char *s1, char *s2)
{
	for (; (*s1 != '\0' && *s2 != '\0') && *s1 == *s2; s1++)
	{
		s2++;
	}
	return (*s1 - *s2);
}
/**
 * str_concat - concatenates two strings.
 * @s1: string 1 to concatenate
 * @s2: string 1 to concatenate
 *
 * Return: the concatenate string between s1 and s2
 */
char *str_concat(char *s1, char *s2)
{
	char *poin = NULL;
	int s1_len = 0, s2_len = 0, a = 0, b = 0;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";
	s1_len = _strlen(s1);
	s2_len = _strlen(s2);
	poin = malloc((s1_len + s2_len + 1) * sizeof(char));
	if (poin == NULL)
		return (NULL);
	for (a = 0; a < s1_len; a++)
		*(poin + a) = *(s1 + a);
	for (b = 0; b < s2_len; b++, a++)
		*(poin + a) = *(s2 + b);
	*(poin + a) = '\0';
	return (poin);
}
