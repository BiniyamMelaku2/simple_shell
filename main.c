#include "shell.h"
/**
 * main - Entry point for program execution
 * @argc: length of arg array
 * @argv: arguments array
 * @env: current env variables passed to child processes
 * Return: 0 Success
 */

int main(int argc __attribute__ ((unused)), char *argv[], char **env)
{
FILE *istream = 0;
char *lineptr = NULL, *cmd = NULL;
size_t llen = 0;
ssize_t input = 0;
istream = stdin;
env = current_env(env);
if (signal(SIGINT, interrupt_handler) == SIG_IGN)
signal(SIGINT, SIG_IGN);
while (1)
{
if (isinteractive())
prompt1();
input = getline(&lineptr, &llen, istream);
if (istream == NULL)
{
perror(argv[0]);                  /* failed to open input stream? STDIN */
return (EXIT_FAILURE);
}
if (input == EOF)      /* terminate shell with 'Ctrl + D' */
{
free(lineptr);
free_env(env);
if (errno == 0)
return (EXIT_SUCCESS);
perror(argv[0]);
return (EXIT_FAILURE);
}
ESC_comments(lineptr);
cmd = strtok(lineptr, " \n");
if (cmd != NULL && exec_builtins(cmd, lineptr, &env))
{ /* exit, env, help, setenv,.. builtin cmds get executed */
if (cmd_executions(cmd, lineptr, &env))
{ /* forks child process gets cmd path checks waits program execution */
free_env(env);
perror(argv[0]);
return (EXIT_FAILURE);
}
}
}
return (EXIT_SUCCESS);
}
