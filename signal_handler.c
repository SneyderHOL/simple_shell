#include "shell.h"
/**
 * handle_sigint - Function that blocked or interrupt the signal
 * when user press ctrl-c
 * @sig: number when the signal is blocked
 */
void handle_sigint(int sig)
{
	counter = 0;
		if (sig == 2)
			counter++, _writ("\n($) ");
}
/**
 *stat_ctr_c - Function than return the status of ctr+C
 *@status: status current
 *Return: status 130 or previos status
 */
int stat_ctr_c(int status)
{
	int aux = 0;

	if (counter == 1)
	{
		counter = 0;
		aux = 130;
	}
	else
		aux = status;
	return (aux);
}
