#include "shell.h"
/**
 * valid_exit - Function that manages program termination through the exit
 * command
 * @str: string to validate
 * @num_sequence: prompt sequence number
 * @program_name: program name shell
 * @status: status exit
 * Return: 0 success or status value
 */
int valid_exit(char *str, size_t num_sequence, char *program_name, int *status)
{
	char num_str[12] = {0}, comparator[11] = "2147483647", *str_aux = NULL;
	int length = _strstr(str, "exit"), num_status, i = 0;

	if (_strcmp(str, "exit\n") == 0)
		free(str), num_status = *status, free(status), exit(num_status);
	else if (length > 0 && str[length + 1] == 32)
	{
		str_aux = valid_letters(str, num_str, num_sequence, program_name,
				length + 1, status);
		if (_strcmp(str_aux, "2") == 0)
			return (2);
		if (_strlen2(num_str) == 10 && num_str[0] < 51)
		{
			for (i = 0; num_str[i] != '\0'; i++)
				if (num_str[i] > comparator[i])
				{
					print_exit_error(str, num_sequence, program_name);
					*status = 2;
					return (2);
				}
			if (i == 10)
				num_status = _atoi(num_str), free(str), free(status),
					exit(num_status);
		}
		else if (_strlen2(num_str) <= 9)
			num_status = _atoi(num_str), free(str), free(status),
				exit(num_status);
		else
		{
			print_exit_error(str, num_sequence, program_name);
			*status = 2;
		}
	}
	else
		return (*status);
	return (0);
}
/**
 * valid_letters - Function that searches for letters within the status
 * sent to exit
 * @length: size of array
 * @str: string to parse
 * @num_sequence: prompt sequence number
 * @program_name: program name shell
 * @num_str: array for numbers
 * @status: previos status
 * Return: status 2 if error or previos status
 */
char *valid_letters(char *str, char *num_str, size_t num_sequence,
		char *program_name, int length, int *status)
{
	int i = 0;

		for (; str[length] != '\0'; length++)
		{
			if ((str[length] < 48 || str[length] > 57) && str[length] != 32
					&& str[length] != '\n')
			{
				print_exit_error(str, num_sequence, program_name);
				*status = 2;
				return ("2");
			}
			else if (str[length] > 47 && str[length] < 58)
				num_str[i] = str[length], i++;
		}
		return (num_str);
}
/**
 * print_exit_error - Function that prints an error message along with the
 * wrong argument
 * @arg: argument wrong
 * @num_sequence: prompt sequence number
 * @program_name: program name shell
 */
void print_exit_error(char *arg, size_t num_sequence, char *program_name)
{
	int i = 4;

	writErr(program_name);
	writErr(": ");
	print_num_Error((int)num_sequence);
	writErr(": exit: Illegal number: ");
	for (; arg[i] != '\0'; i++)
	{
		if (arg[i] != ' ' && arg[i] != '\n')
			_putcharE(arg[i]);
	}
	_putcharE('\n');
}
/**
 * exit_prompt - function that prints a message before leaving prompt
 * @str: string to print
 * @status: status exit
 *
 */
void exit_prompt(char *str, int *status)
{
	int num_status;

	if (str != NULL)
		_writ(str);
	num_status = *status, free(status), exit(num_status);
}
