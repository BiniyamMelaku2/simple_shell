#include "shell.h"

/**
 * get_cmd_fpath - Looks for executable program in PATH.
 * @cmd: executable program to be searched
 * @env: environment context
 * Return: if program found in PATH, returns a string specifying full path or
 * returns ~cmd~ unchanged (for relative path.). On memory error, returns NULL.
 */
char *get_cmd_fpath(char *cmd, char **env)
{
unsigned long int i = 0, j = 0, full_cmd_len = 0;
char *PATH_value = NULL, *token = NULL, *full_cmd_path = NULL;
unsigned long int PATH_value_len = 0;
struct stat st;
if (cmd[0] == '/')
return (cmd);
for (i = 0; env[i] != NULL ; i++)
{  /* find PATH env var */
if (_strncmp(env[i], "PATH=", 5) == 0)
{
PATH_value_len = _strlen(env[i]) - 4;
PATH_value = malloc(sizeof(char) * PATH_value_len);
if (PATH_value == NULL)
{
perror("malloc");
exit(EXIT_FAILURE);
}
break;
}
}
if (PATH_value == NULL)    /* PATH variable not found */
return (cmd);
for (j = 5; j < PATH_value_len + 5; j++)
PATH_value[j - 5] = env[i][j]; /* copy ~$PATH~ onto ~PATH_value~ */
token = strtok(PATH_value, ":");            /* checking each directory */
while (token != NULL)
{ /* check for path: token + "/" + cmd + '\0' */
full_cmd_len = _strlen(token) + _strlen(cmd) + 2;
full_cmd_path = malloc(sizeof(char) * full_cmd_len);
if (full_cmd_path == NULL)
{     /* memory check */
perror("malloc");
return (NULL);
}
_memset(full_cmd_path, 0, full_cmd_len);
full_cmd_path = _strcat(full_cmd_path, token);  /* concat strings */
full_cmd_path = _strcat(full_cmd_path, "/");
full_cmd_path = _strcat(full_cmd_path, cmd);
if (stat(full_cmd_path, &st) == 0)
{
free(PATH_value);
return (full_cmd_path);
}
free(full_cmd_path);
token = strtok(NULL, ":");
}
free(PATH_value);
return (cmd);
}
