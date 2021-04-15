#include "shell.h"
/**
 * current_env - returns current/inherited env variables
 * @env: current env variables
 * Return: pointer to pointer of env variables
 */
char **current_env(char **env)
{
int c = 0, len_env;
char **tmp;
for (c = 0; env[c]; c++)
;
len_env = c;
tmp = malloc(sizeof(char *) * (len_env + 1));
for (c = 0; c < len_env; c++)
{
tmp[c] = _strdup(env[c]);
if (tmp[c] == NULL)
{
perror("strdup");
exit(EXIT_FAILURE);
}
}
tmp[c] = NULL;
return (tmp);
}
/**
 * free_env - frees allocated memory for env variables
 * @env: current env variables
 */
void free_env(char **env)
{
int c;
for (c = 0; env[c]; c++)
free(env[c]);
free(env);
}
/**
 * _memset - initializes memory array, see ~memset(3)
 * @s: memory array
 * @c: value to be initialized with
 * @n: length of memory
 */
void _memset(void *s, int c, size_t n)
{
size_t i;
for (i = 0; i < n; i++)
*((char *) s + i) = c;
}
