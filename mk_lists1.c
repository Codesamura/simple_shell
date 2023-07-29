#include "shell.h"

/**
 * lli_length - determines length of linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t lli_length(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * ls_str - returns an array of strings of the list->str
 * @hd_n1: pointer to first node
 *
 * Return: array of strings
 */
char **ls_str(list_t *hd_n1)
{
	list_t *node = hd_n1;
	size_t i = lli_length(hd_n1), j;
	char **strs;
	char *str;

	if (!hd_n1 || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * pr_ls - prints all elements of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t pr_ls(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * ndstarts_with - returns node whose string starts with prefix
 * @node: pointer to list hd_n1
 * @prefix: string to match
 * @c: the next character after prefix to match
 *
 * Return: match node or null
 */
list_t *ndstarts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_ndindex - gets the index of a node
 * @hd_n1: pointer to list hd_n1
 * @node: pointer to the node
 *
 * Return: index of node or -1
 */
ssize_t get_ndindex(list_t *hd_n1, list_t *node)
{
	size_t i = 0;

	while (hd_n1)
	{
		if (hd_n1 == node)
			return (i);
		hd_n1 = hd_n1->next;
		i++;
	}
	return (-1);
}
