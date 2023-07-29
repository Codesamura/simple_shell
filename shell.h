#ifndef _SHELL_H_
#define _SHELL_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <limits.h>
#include <fcntl.h>
#include <errno.h>
/* for read/write buffers */
#define READ_BUF_SIZE 1024
#define WRITE_BUF_SIZE 1024
#define BUF_FLUSH -1

/* for command chaining */
#define CMD_NORM	0
#define CMD_OR		1
#define CMD_AND		2
#define CMD_CHAIN	3

/* for convert_number() */
#define CONVERT_LOWERCASE	1
#define CONVERT_UNSIGNED	2

/* 1 if using system getline() */
#define USE_GETLINE 0
#define USE_STRTOK 0

#define HIST_FILE	".simple_shell_history"
#define HIST_MAX	4096

extern char **environ;


/**
 * struct liststr - singly linked list
 * @num: the number field
 * @str: a string
 * @next: points to the next node
 */
typedef struct liststr
{
	int num;
	char *str;
	struct liststr *next;
} list_t;

/**
 *struct passinfo - contains pseudo-arguements to pass into a function,
 *		allowing uniform prototype for function pointer struct
 *@arg: a string generated from getline containing arguements
 *@argv: an array of strings generated from arg
 *@path: a string path for the current command
 *@argc: the argument count
 *@line_count: the error count
 *@err_num: the error code for exit()s
 *@linecount_flag: if on count this line of input
 *@fname: the program filename
 *@env: linked list local copy of environ
 *@environ: custom modified copy of environ from LL env
 *@history: the history node
 *@alias: the alias node
 *@env_changed: on if environ was changed
 *@status: the return status of the last exec'd command
 *@cmd_buf: address of pointer to cmd_buf, on if chaining
 *@cmd_buf_type: CMD_type ||, &&, ;
 *@readfd: the fd from which to read line input
 *@histcount: the history line number count
 */
typedef struct passinfo
{
	char *arg;
	char **argv;
	char *path;
	int argc;
	unsigned int line_count;
	int err_num;
	int linecount_flag;
	char *fname;
	list_t *env;
	list_t *history;
	list_t *alias;
	char **environ;
	int env_changed;
	int status;

	char **cmd_buf; /* pointer to cmd ; chain buffer, for memory mangement */
	int cmd_buf_type; /* CMD_type ||, &&, ; */
	int readfd;
	int histcount;
} info_t;

#define INFO_INIT \
{NULL, NULL, NULL, 0, 0, 0, 0, NULL, NULL, NULL, NULL, NULL, 0, 0, NULL, \
	0, 0, 0}

/**
 *struct builtin - contains a builtin string and related function
 *@type: the builtin command flag
 *@func: the function
 */
typedef struct builtin
{
	char *type;
	int (*func)(info_t *);
} builtin_table;

int is_chain(info_t *info, char *buf, size_t *p)
void check_chain(info_t *info, char *buf, size_t *p, size_t i, size_t len)
int replace_alias(info_t *info)
int replace_vars(info_t *info)
int replace_string(char **old, char *new)
char **strtow(char *str, char *d)
char **strtow2(char *str, char d)
int hsh(info_t *info, char **av)
int find_builtin(info_t *info)
void find_cmd(info_t *info)
void fork_cmd(info_t *info)
int _strlen(char *s)
int _strcmp(char *s1, char *s2)
char *starts_with(const char *haystack, const char *needle)
char *_strcat(char *dest, char *src)
int _atoi(char *s)
int chr_alphabet(int c)
int chr_delimeter(char c, char *delim)
int interact(info_t *info)
int _history(info_t *info)
int str_alias(info_t *info, char *str)
int n_alias(info_t *info, char *str)
int print_alias(list_t *node)
int _alias(info_t *info)
int _erratoi(char *s)
void prnt_err(info_t *info, char *estr)
int pr_dec(int input, int fd)
char *cvnt(long int num, int base, int flags)
void rm_comm(char *buf)
char **get_environ(info_t *info)
int _unsetenv(info_t *info, char *var)
int _setenv(info_t *info, char *var, char *val)
ssize_t ch_buf(info_t *info, char **buf, size_t *len)
int curr_env(info_t *info)
char *get_val_env(info_t *info, const char *name)
int set_env(info_t *info)
int rm_unset(info_t *info)
int fillenv_list(info_t *info)
char *cp_str(char *str_dest, char *src, int n)
char *_strncat(char *str_dest, char *src, int n)
char *_strchr(char *s, char c)
int _help(info_t *info)
int cng_cd(info_t *info)
int exits(info_t *info)
int chr_fd(char c, int fd)
int pr_inputstr(char *str, int fd)
int wr_chr(char c)
void pr_inputs(char *str)
void free_str_add(str_add_t *str_add, int all)
void set_str_add(str_add_t *str_add, char **agv)
void clr_str_add(str_add_t *str_add)
int rd_hs(info_t *info)
char *gth_file(info_t *info
int wr_hs(info_t *info)
int buld_hsl(info_t *info, char *buff, int linecount)
int rnum_hs(info_t *info)
ssize_t gt_i(info_t *info)
ssize_t rd_buff(info_t *info, char *buf, size_t *i)
int _g_line(info_t *info, char **ptr, size_t *length)
void sigintHandler(__attribute__((unused))int sig_num)
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
void ffree(char **pp)
char *_memset(char *pr, char byt, unsigned int n)
char *path_fd(info_t *info, char *ph_str, char *cmd)
int is_cmd(info_t *info, char *path)
char *dup_chars(char *ph_str, int strt, int stp)
int bfree(void **ad_ptr)
ssize_t get_ndindex(list_t *hd_n1, list_t *node)
list_t *ndstarts_with(list_t *node, char *prefix, char c)
size_t pr_ls(const list_t *h)
char **ls_str(list_t *hd_n1)
size_t lli_length(const list_t *h)
list_t *ad_n(list_t **hd_adr, const char *str, int num)
list_t *ad_n_end(list_t **hd_adr, const char *str, int num)
size_t only_str(const list_t *h)
int rm_nindex(list_t **hd_adr, unsigned int index)

