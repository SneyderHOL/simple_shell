#include "shell.h"
/**
 * valid_exit - Function that manages program termination through the exit
 * command
 * @str: string to validate
 */
void valid_exit(char *str)
{
	char num_str[11] = {0}, comparator[11] = "2147483647";
	int len = _strstr(str, "exit"), num_status, i = 0;

	if (_strcmp(str, "exit\n") == 0)
		free(str), exit(0);
	else if (len > 0 && str[len + 1] == 32)
	{
		len++;
		for (; str[len] != '\0'; len++)
		{
			if ((str[len] < 48 || str[len] > 57) && str[len] != 32 && str[len] != '\n')
			{
				write(STDOUT_FILENO, "exit: Illegal number\n", 21);
				free(str), prompt();
			}
			else if (str[len] > 47 && str[len] < 58)
				num_str[i] = str[len], i++;
		}
		if (_strlen2(num_str) == 10 && num_str[0] < 51)
		{
			for (i = 0; num_str[i] != '\0'; i++)
				if (num_str[i] > comparator[i])
				{
					write(STDOUT_FILENO, "exit: Illegal number\n", 21);
					free(str), prompt();
				}
			if (i == 10)
				num_status = _atoi(num_str), free(str), exit(num_status);
		}
		else if (_strlen2(num_str) <= 9)
			num_status = _atoi(num_str), free(str), exit(num_status);
		else
		{
			write(STDOUT_FILENO, "exit: Illegal number\n", 21);
			free(str), prompt();
		}
	}
	else
		return;
}
