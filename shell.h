#ifndef SHELL
#define SHELL
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
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
/* PROTOTYPES  */
int char_validator(char *str);
void print_env(void);

void valid_exit(char *str);

void failed_split(char *line);
void failed_getline(void);
void failed_fork(char *line, char **args);
void failed_path_exist(void);
void failed_exec(char *line, char *path, char **args);

char *find_path_in_env(void);
list_t *split_path(void);
char *handle_path(char *command);

void handle_sigint(int sig);

void free_grid(char **grid, int height);
char **split_a(char *line, ssize_t lineSize);
int grid_size(char **grid);
void print_array(char **a, int n);

list_t *split_l(char *line, ssize_t lineSize, char *delim);
list_t *add_list(list_t **head, char *str);
void free_list(list_t *head);
size_t print_list(list_t *h);

size_t _strlen(char *s);
void clean(char *str);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
void _strenv(char *);
char *str_concat(char *s1, char *s2);
int _strstr(char *haystack, char *needle);
int _strlen2(char *s);
int _atoi(char *s);

void prompt(void);
extern char **environ;
#endif /* SHELL */
