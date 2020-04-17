#ifndef _SHELL_H_
#define _SHELL_H_
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <fcntl.h>
#define ENV environ
/* STRUCTS */
/**
 * struct list_s - singly linked list
 * @str: string - (malloc'ed string)
 * @len: lenght of the string
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 * for Holberton project
 */
typedef struct list_s
{
	char *str;
	unsigned int len;
	struct list_s *next;
} list_t;
/**
 * struct opc_help - struct of data type opc_help
 * @array: Arguments for analyze and formatted
 * @function_opc: Functions that print txt
*/
typedef struct opc_help
{
	char *array;
	void (*function_opc)(char *opt, int *status);
} input;
/* PROTOTYPES  */
/* Functions in auxiliar_functions.c file */
int eof_validator(char *str);
int check_for_file(char *command);
void execute_command(pid_t *child, int *status, char *input_line,
	char *command_exist, char **args, size_t command_num, char *program_name);
void e_exit(int *eof_aux, char *str, int *status);
int dot_slash_compare(char *command);
/* Functions in complementary_functions.c file */
int counter_space(char *line, ssize_t lineSize, char *delim);
int is_empty_string(char *line, ssize_t lineSize);
int is_dot(char *line, ssize_t lineSize);
/* Functions in env_handler.c file */
void print_env(void);
void _strenv(char *s1, int *status);
/* Functions in exit_handler.c file */
int valid_exit(char *str, size_t num_sequence, char *program_name,
		int *status);
void print_exit_error(char *arg, size_t num_line, char *program_name);
void exit_prompt(char *str, int *status);
char *valid_letters(char *str, char *num_str, size_t num_sequence,
		char *program_name, int lengt, int *status);
/* Functions in failed_cases.c file */
void failed_getline(char *line);
void failed_fork(char *path, char **args, int *status);
void failed_exec(char *line, char *path, char **args,
		size_t command_num, char *program_name);
/* Functions in itoa.c file */
void print_number_2_digits(int);
void print_number_3_digits(int);
void print_number_4_digits(int);
void print_num_Error(int n);
/* Functions in not_found_cases.c file */
void failed_command_exist(char *args, size_t num, char *program_name);
void failed_permissions(char *args, size_t command_num, char *program_name);
void failed_command_noexist(char *args, size_t num, char *program_name);
void failed_env_noexist(char *args, size_t num, char *program_name);
/* Functions in path_handler.c file */
char *find_path_in_env(char *args, size_t num, char *program_name);
list_t *split_path(char *args, size_t num, char *program_name);
char *handle_path(char *command, size_t command_num, char *program_name,
	int *status);
void find_command_in_path(list_t *aux, char **found, char *add_slash,
			int *status);
int is_command_found(char *found, char *command, size_t command_num,
		char *program_name, int status);
/* Functions in prompt.c file */
void prompt(char *program_name);
int line_checker(ssize_t line_read_char, int *eof_aux, char **input_line,
		int *status);
void print_prompt(void);
/* Functions in signal_handler.c file */
void handle_sigint(int sig);
int stat_ctr_c(int status);
/* Functions in split_in_array.c file */
void free_grid(char **grid, int height);
char **split_a(char *line, ssize_t lineSize, size_t num_line,
	char *program_name, int *status);
int grid_size(char **grid);
void print_array(char **a, int n);
void list_to_array(list_t *head, char **array, size_t size);
/* Functions in split_in_array.c file */
list_t *split_l(char *line, ssize_t lineSize, char *delim);
list_t *add_list(list_t **head, char *str);
void free_list(list_t *head);
size_t print_list(list_t *h);
size_t list_len(list_t *h);
/* Functions in str_manipulator.c file */
size_t _strlen(char *s);
void clean(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
char *str_concat(char *s1, char *s2);
/* Functions in str_str.c file */
int _strstr(char *haystack, char *needle);
int _strlen2(char *s);
int _atoi(char *s);
/* Functions in _write.c file */
int writErr(char *str);
int _writ(char *str);
int _putchar(char c);
int _putcharE(char c);
/* Global variable that contains the environment variables */
extern char **environ;
int counter;
/* Help function */
void _help(char *option, int *status);
void valid_opt_help(char *arg, int *status);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strstr2(char *haystack, char *needle);
#endif /* SHELL */
