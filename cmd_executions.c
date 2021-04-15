#include "shell.h"
/**
 * ESC_comments - to escape the comment section
 * @lineptr: pointer to the line
 */
void ESC_comments(char *lineptr)
{
strtok(lineptr, "#");
}
/**
 * exec_builtins - executes a builtin command
 * @cmd: the command input
 * @lineptr: pointer to input line
 * @ env: ptr to ptr of a ptr to env
 * returns 0 if user command is a built-in, 1 otherwise
 */
char exec_builtins(char *cmd, char *lineptr __attribute__ ((unused)), char ***env)
{
int exitn, len_arg;
char *arg = NULL;
if (_strncmp(cmd, "exit", 5) == 0)
{
arg = strtok(NULL, " \n");
if (arg != NULL)
{
len_arg = _strlen(arg);
if (valid_exitarg(arg, len_arg) == 1)
{
exitn = _atoin(arg, len_arg);
free_env(*env);
free(lineptr);
exit(exitn);
}
print("exit: Illegal number\n");
return (0);
}
free(lineptr);
free_env(*env);
exit(EXIT_SUCCESS);
}
if (_strncmp(cmd, "env", 4) == 0)
{
put_grid(*env);
return (0);
}
if (_strncmp(cmd, "help", 5) == 0)
{
ihelp();
return (0);
}
if (_strncmp(cmd, "setenv", 7) == 0)
{
_setenv(env);
return (0);
}
if (_strncmp(cmd, "unsetenv", 9) == 0)
{
_unsetenv(env);
return (0);
}
return (1);
}
/**
 * cmd_executions - executes a builtin command
 * @cmd: the command input
 * @lineptr: pointer to input line
 * @ env: ptr to ptr of a ptr to env
 * Return: 0 on success, returns 1 on error
 */
char cmd_executions(char *cmd, char *lineptr, char ***env)
{
char *cargv[BUF_SIZE], *full_exec_path = NULL;/* child argv */
int i, status;
pid_t pid = fork();
if (pid == -1)
return (1);
if (pid != 0)
{ /* in the parent process locked pid*/
/* waits for a child to terminate. stores status information */
wait(&status);
}
else
{ /* in the child process, fork success*/
cargv[0] = cmd;
for (i = 0; i < BUF_SIZE - 1; i++)
{
if (cargv[i] == NULL)
break;
cargv[i + 1] = strtok(NULL, " \n");
}
/* Get relative path */
if (cmd[0] == '.')
full_exec_path = cmd;
/* Get absolute path */
else
{
full_exec_path = get_cmd_fpath(cmd, *env);
if (full_exec_path == NULL)
{
/* memory error in ~get_fpath()~ */
free(lineptr);
return (1);
}
}
/* Execute a program */
if (execve(full_exec_path, cargv, *env) == -1)
{
free(lineptr);
return (1);
}
}
return (0);
}
