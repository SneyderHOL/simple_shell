#include "shell.h"
/**
* split_l - function to split a string
* @line: captured string to split
* @lineSize: size of line variable
* @delim: string that contains the delimiter use to split
*
* Return: a list_t pointer that contains each word from line variable
*/
list_t *split_l(char *line, ssize_t lineSize, char *delim)
{
	ssize_t i = 0;
	char *aux = NULL;
	list_t *head = NULL;

	if (line == NULL || lineSize <= 0)
		return (NULL);
	aux = strtok(line, delim);
	for (i = 0; aux; i++)
	{
		head = add_list(&head, aux);
		aux = strtok(NULL, delim);
	}
	return (head);
}
/**
* add_list - add a node to the the list
* @head: head of the list
* @str: string to add to the node
*
* Return: a pointer to the head of the list
*/
list_t *add_list(list_t **head, char *str)
{
	unsigned int cont = 0;
	list_t *node = NULL, *aux = *head;

	if (head == NULL)
		return (NULL);
	node = malloc(sizeof(list_t));
	if (node == NULL)
		return (NULL);
	while (str[cont] != '\0')
		cont++;
	node->str = _strdup(str);
/*	clean(node->str); */
	node->len = cont;
	node->next = NULL;
	if (*head == NULL)
	{
		*head = node;
		return (node);
	}
	while (aux->next != NULL)
		aux = aux->next;
	aux->next = node;
	return (*head);
}
/**
 * free_list - function that frees a list_t.
 * @head: pointer to a list_t argument
 *
 * Return: no return
 */
void free_list(list_t *head)
{
	if (head != NULL)
	{
		free(head->str);
		free_list(head->next);
		free(head);
	}
}
/**
 * print_list - function that prints all the elements of a
 * list_t list.
 * @h: list_t pointer argument
 *
 * Return: the number of nodes
 */
size_t print_list(list_t *h)
{
	unsigned int size = 0;
	char *s = NULL;
	const list_t *iter = NULL;

	if (h == NULL)
		return (0);
	iter = h;
	while (iter != NULL)
	{
		s = iter->str;
		if (s == NULL)
			_writ("[0] (nil)\n");
		else
		{
			_writ(s);
			_putchar(10);
		}
		size++;
		iter = iter->next;
	}
	return (size);
}
/**
 * list_len - function that returns the number of elements in a
 * linked list_t list.
 * @h: list_t pointer argument
 *
 * Return: the number of nodes
 */
size_t list_len(list_t *h)
{
	unsigned int size = 0;
	list_t *iter = NULL;

	if (h == NULL)
		return (0);
	iter = h;
	while (iter != NULL)
	{
		size++;
		iter = iter->next;
	}
	return (size);
}
