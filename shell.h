#ifndef SHELL_H
#define SHELL_H

#ifndef BUF_SIZE
#define BUF_SIZE 256
#endif

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h> /* ~wait(2)~ */
#include <string.h>   /* ~strtok(3)~ */
#include <sys/stat.h> /* ~stat(2)~ */
#include <signal.h>   /* signal(2) */

int putch(char ch);
void print(char *str);
void put_grid(char **grid);
void p_error(char *msg);

void prompt1(void);
/*void prompt2(void);*/

void strip_newline(char *str, ssize_t input);
char *get_cmd_fpath(char *cmd, char **env);
void _memset(void *s, int c, size_t n);
int _strncmp(char *s1, char *s2, int n);

int _strlen(const char *str);
char *_strcat(char *dest, const char *src);
char *_strcpy(char *dest, const char *src);
char *_strdup(char *str);

char exec_builtins(char *cmd, char *lineptr, char ***env);
char cmd_executions(char *cmd, char *lineptr, char ***env);

int _atoin(const char *s, int len);
int isinteractive(void);
int valid_exitarg(char *arg, int len);
void ihelp(void);

/* _cstrcmp - cut string compare */
int _cstrcmp(const char *s1, const char *s2);
int _strcmp(const char *s1, const char *s2);
int _max(int n, int m);
int _min(int n, int m);
/* _setenv - set an environment variable */
int _setenv(char ***env);
/* _setenv_func - helper to _setenv */
int _setenv_func(char ***env, char *env_var, char *env_val);
/* grow_env - grow env by one, copy all the present key-value pairs */
char **grow_env(char **env, int env_size);
/* new string with format "variable" + '=' + "value", like in PATH */
char *new_path_str(char *env_var, char *env_val);
/* current_env - duplicate the environment */
char **current_env(char **env);
void free_env(char **env);
void interrupt_handler(int signum);
void ESC_comments(char *lineptr);
int _unsetenv(char ***env);
void shrink_env(char ***env, int del);

#endif
