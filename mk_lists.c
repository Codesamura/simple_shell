#include "shell.h"

/**
 * ad_n - adds a node to the start of the list
 * @hd_adr: address of pointer to hd_adr node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *ad_n(list_t **hd_adr, const char *str, int num)
{
	list_t *new_hd_adr;

	if (!hd_adr)
		return (NULL);
	new_hd_adr = malloc(sizeof(list_t));
	if (!new_hd_adr)
		return (NULL);
	_memset((void *)new_hd_adr, 0, sizeof(list_t));
	new_hd_adr->num = num;
	if (str)
	{
		new_hd_adr->str = _strdup(str);
		if (!new_hd_adr->str)
		{
			free(new_hd_adr);
			return (NULL);
		}
	}
	new_hd_adr->next = *hd_adr;
	*hd_adr = new_hd_adr;
	return (new_hd_adr);
}

/**
 * ad_n_end - adds a node to the end of the list
 * @hd_adr: address of pointer to hd_adr node
 * @str: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *ad_n_end(list_t **hd_adr, const char *str, int num)
{
	list_t *new_node, *node;

	if (!hd_adr)
		return (NULL);

	node = *hd_adr;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = num;
	if (str)
	{
		new_node->str = _strdup(str);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*hd_adr = new_node;
	return (new_node);
}

/**
 * only_str - prints only the str element of a list_t linked list
 * @h: pointer to first node
 *
 * Return: size of list
 */
size_t only_str(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * rm_nindex - deletes node at given index
 * @hd_adr: address of pointer to first node
 * @index: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int rm_nindex(list_t **hd_adr, unsigned int index)
{
	list_t *node, *prev_node;
	unsigned int i = 0;

	if (!hd_adr || !*hd_adr)
		return (0);

	if (!index)
	{
		node = *hd_adr;
		*hd_adr = (*hd_adr)->next;
		free(node->str);
		free(node);
		return (1);
	}
	node = *hd_adr;
	while (node)
	{
		if (i == index)
		{
			prev_node->next = node->next;
			free(node->str);
			free(node);
			return (1);
		}
		i++;
		prev_node = node;
		node = node->next;
	}
	return (0);
}

/**
 * fr_ls - frees all nodes of a list
 * @hd_ptn: address of pointer to hd_adr node
 *
 * Return: void
 */
void fr_ls(list_t **hd_ptn)
{
	list_t *node, *next_node, *hd_adr;

	if (!hd_ptn || !*hd_ptn)
		return;
	hd_adr = *hd_ptn;
	node = hd_adr;
	while (node)
	{
		next_node = node->next;
		free(node->str);
		free(node);
		node = next_node;
	}
	*hd_ptn = NULL;
}
