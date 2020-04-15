 #include "shell.h"
/**
 * writErr - Function that print string to stdout
 * @str: pointer string
 * Return: system call write
 */
int writErr(char *str)
{
	int len = 0;

	len = _strlen2(str);

	return (write(STDERR_FILENO, str, len));
}
/**
 * _writ - Function that print string to stdout
 * @str: pointer string
 * Return: system call
 */
int _writ(char *str)
{
	int len = _strlen2(str);

	return (write(STDOUT_FILENO, str, len));
}
/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _putcharE - writes the character of error to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putcharE(char c)
{
	return (write(2, &c, 1));
}
