#include "shell.h"

/**
 * interrupt_handler - keeps shell alive when key pressed
 * @signum: interrupt key 'Enter', ..
 */
void interrupt_handler(int signum)
{
(void) signum;
print("\n");
prompt1();
}
/**
 * strip_newline - replaces '\n' with '\0'
 * @str: string
 * @input: input stream
 */
void strip_newline(char *str, ssize_t input)
{
if (str[input - 1] == '\n')
str[input - 1] = '\0';
}
/**
 * valid_exitarg - checks valid exit argument is entered , exit 98, 99
 * @arg: argument value
 * @len: number of digits
 * Return: 0 NoError
 */
int valid_exitarg(char *arg, int len)
{
int i;
for (i = 0; i < len; i++)
{
if (arg[i] < '0' || arg[i] > '9')
{
return (0);
}
}
return (1);
}
