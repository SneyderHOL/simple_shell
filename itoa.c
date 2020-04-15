#include "shell.h"

/**
 * print_num_Error - function that prints any integer positive or negative
 * @n: integer positive or negative
 *
 **/
void print_num_Error(int n)
{

	if ((n < 10 && n > 0) || n == 0)
		_putcharE('0' + n);
	else if (n < 0)
	{
		n = -(n);
		if (n > 0 && n < 10)
		{
		_putcharE('-');
		_putcharE('0' + n);
		}
		else if (n > 9 && n < 100)
		{
			_putcharE('-');
			print_number_2_digits(n);
		}
		else if (n > 99 && n < 1e3)
		{
			_putcharE('-');
			print_number_3_digits(n);
		}
		else if (n > 999 && n < 1e4)
		{
			_putcharE('-');
			print_number_4_digits(n);
		}
	}
	else if (n > 9 && n < 99)
		print_number_2_digits(n);
	else if (n > 99 && n < 1e3)
		print_number_3_digits(n);
	else if (n > 999 && n < 1e4)
		print_number_4_digits(n);
}
/**
 * print_number_4_digits - receives a number for slice and print
 * @number: integer positive or negative
 */
void print_number_4_digits(int number)
{
	int aux = 0;
	int aux2 = 0;

	aux = number / 100;
	_putcharE('0' + (aux / 10));
	aux2 = number % 1000;
	aux2 = aux2 / 10;
	_putcharE('0' + (aux2 / 10));
	_putcharE('0' + (aux2 % 10));
	_putcharE('0' + (number % 10));
}
/**
 * print_number_3_digits - receives a number for slice and print
 * @number: integer positive or negative
 */
void print_number_3_digits(int number)
{
	int aux = 0;

	aux = number / 10;
	_putcharE('0' + (aux / 10));
	_putcharE('0' + (aux % 10));
	_putcharE('0' + (number % 10));
}
/**
 * print_number_2_digits - receives a number for slice and print
 * @number: integer positive or negative
 */
void print_number_2_digits(int number)
{
	_putcharE('0' + (number / 10));
	_putcharE('0' + (number % 10));
}
