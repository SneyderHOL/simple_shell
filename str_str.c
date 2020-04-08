#include "shell.h"
/**
 * *_strstr - function that locates a substring
 * @str: string
 * @sub_str: substring
 * Return: 0 Success or 1 failed if the substring is not found
 */
int _strstr(char *str, char *sub_str)
{
	int j, aux;
	int i = 0;
	int len_nee = _strlen2(sub_str);

	while (str[i])
	{
		j = 0;
		aux = i;
		while (str[aux] == sub_str[j])
		{
			if (j == len_nee - 1)
			{
				return (j);
			}
			j++;
			aux++;
		}
		i++;
	}
	return (-1);
}
/**
 * _strlen2 - function that returns the length of a string
 * @sub_str: string
 * Return: length of a string
 **/
int _strlen2(char *sub_str)
{
	int i;

	for (i = 0; sub_str[i] != '\0'; i++)
	{}
	return (i);
}
/**
 * _atoi - Function that convert a string to an integer
 * @s:pointer string
 * Return: number positive or negative
 */
int _atoi(char *s)
{
	int i;
	int num, sign;
	unsigned int num1;

	num1 = 0;
	sign = 1;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] == 45)
			sign = sign * -1;
		if (s[i] >= 48 && s[i] <= 57)
		{
			num = s[i];
			num -= 48;
			num1 = (num1 * 10) + num;
		}
		else if (num1 > 0)
			break;
	}
	return (num1 * sign);
}
