#include "shell.h"
/**
 * main - Entry Point
 * @argc: cuantity of arguments
 * @argv: array of arguments
 *
 * Return: Always 0 (Success)
 */

int main(int argc, char *argv[])
{
	if (argc == 1)
		prompt(argv[0]);
	else
	{
		writErr("Usage: ");
		writErr(argv[0]);
		writErr("\n");
	}
	return (0);
}
