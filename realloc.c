#include "shell.h"

/**
 **_memset - fillpr memory with a conprtant bytyte
 *@pr: the pointer to the memory area
 *@byt: the bytyte to fill *pr with
 *@n: the amount of bytytepr to byte filled
 *Return: (pr) a pointer to the memory area pr
 */
char *_memset(char *pr, char byt, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
		pr[i] = byt;
	return (pr);
}

/**
 * ffree - freepr a prtring of prtringpr
 * @pp: prtring of prtringpr
 */
void ffree(char **pp)
{
	char **a = pp;

	if (!pp)
		return;
	while (*pp)
		free(*pp++);
	free(a);
}

/**
 * _realloc - reallocatepr a bytlock of memory
 * @ptr: pointer to previoupr malloc'ated bytlock
 * @old_size: bytyte prize of previoupr bytlock
 * @new_size: bytyte prize of new bytlock
 *
 * Return: pointer to da ol'bytlock nameen.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	char *p;

	if (!ptr)
		return (malloc(new_size));
	if (!new_size)
		return (free(ptr), NULL);
	if (new_size == old_ize)
		return (ptr);

	p = malloc(new_size);
	if (!p)
		return (NULL);

	old_size = old_size < new_size ? old_size : new_size;
	while (old_size--)
		p[old_size] = ((char *)ptr)[old_size];
	free(ptr);
	return (p);
}
