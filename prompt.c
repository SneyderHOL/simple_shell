#include "shell.h"
/**
 * prompt - function that emulates the prompt in the shell
 *
 * Return: no return
 */
void prompt(void)
{
	char *input_line = NULL, **args = NULL, *path_exist = NULL;
	int status = 0;
	size_t len_line = 0;
	ssize_t line_read_char = 0;
	pid_t child;

	signal(SIGINT, handle_sigint);
	while (1)
	{
		write(STDOUT_FILENO, "($) ", 4);
		line_read_char = getline(&input_line, &len_line, stdin);
		if (line_read_char == EOF)
			write(STDOUT_FILENO, "\n", 1), free(input_line), exit(0);
/*		evaluate string line size, evaluate interactive, no interactive */
		if (line_read_char > 0 && input_line[0] != 10)
		{
			args = split_a(input_line, line_read_char);
			if (args == NULL)
				failed_split(input_line);
			path_exist = handle_path(args[0]);
			if (path_exist != NULL)
			{
				child = fork();
				if (child == -1)
					failed_fork(input_line, args);
				if (child == 0)
				{
					if (execve(path_exist, args, NULL) == -1)
						failed_exec(input_line, path_exist, args);
				}
				else
					wait(&status), free(path_exist), free(args);
			}
			else
				failed_path_exist(), free(args);
		}
		free(input_line);
		input_line = NULL;
		len_line = 0;
	}
}
