#include "shell.h"

/**
 * clr_str_add - initializes str_add_t struct
 * @str_add: struct address
 */
void clr_str_add(str_add_t *str_add)
{
	str_add->arg = NULL;
	str_add->argv = NULL;
	str_add->path = NULL;
	str_add->argc = 0;
}

/**
 * set_str_add - initializes str_add_t struct
 * @str_add: struct address
 * @agv: argument vector
 */
void set_str_add(str_add_t *str_add, char **agv)
{
	int i = 0;

	str_add->fname = agv[0];
	if (str_add->arg)
	{
		str_add->argv = strtow(str_add->arg, " \t");
		if (!str_add->argv)
		{

			str_add->argv = malloc(sizeof(char *) * 2);
			if (str_add->argv)
			{
				str_add->argv[0] = _strdup(str_add->arg);
				str_add->argv[1] = NULL;
			}
		}
		for (i = 0; str_add->argv && str_add->argv[i]; i++)
			;
		str_add->argc = i;

		replace_alias(str_add);
		replace_vars(str_add);
	}
}

/**
 * free_str_add - frees str_add_t struct fields
 * @str_add: struct address
 * @all: true if freeing all fields
 */
void free_str_add(str_add_t *str_add, int all)
{
	ffree(str_add->argv);
	str_add->argv = NULL;
	str_add->path = NULL;
	if (all)
	{
		if (!str_add->cmd_buf)
			free(str_add->arg);
		if (str_add->env)
			free_list(&(str_add->env));
		if (str_add->history)
			free_list(&(str_add->history));
		if (str_add->alias)
			free_list(&(str_add->alias));
		ffree(str_add->environ);
			str_add->environ = NULL;
		bfree((void **)str_add->cmd_buf);
		if (str_add->readfd > 2)
			close(str_add->readfd);
		_putchar(BUF_FLUSH);
	}
}
