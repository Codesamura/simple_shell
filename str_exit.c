#include "shell.h"

/**
 **cp_str - copies a string
 *@str_dest: the str_destination string to be copied to
 *@src: the source string
 *@n: the amount of characters to be copied
 *Return: the concatenated string
 */
char *cp_str(char *str_dest, char *src, int n)
{
	int i, j;
	char *s = str_dest;

	i = 0;
	while (src[i] != '\0' && i < n - 1)
	{
		str_dest[i] = src[i];
		i++;
	}
	if (i < n)
	{
		j = i;
		while (j < n)
		{
			str_dest[j] = '\0';
			j++;
		}
	}
	return (s);
}

/**
 **_strncat - concatenates two strings
 *@str_dest: the first string
 *@src: the second string
 *@n: the amount of bytes to be maximally used
 *Return: the concatenated string
 */
char *_strncat(char *str_dest, char *src, int n)
{
	int i, j;
	char *s = str_dest;

	i = 0;
	j = 0;
	while (str_dest[i] != '\0')
		i++;
	while (src[j] != '\0' && j < n)
	{
		str_dest[i] = src[j];
		i++;
		j++;
	}
	if (j < n)
		str_dest[i] = '\0';
	return (s);
}

/**
 **_strchr - locates a character in a string
 *@s: the string to be parsed
 *@c: the character to look for
 *Return: (s) a pointer to the memory area s
 */
char *_strchr(char *s, char c)
{
	do {
		if (*s == c)
			return (s);
	} while (*s++ != '\0');

	return (NULL);
}
