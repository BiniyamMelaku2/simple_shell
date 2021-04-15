#include <stdio.h>
#include "shell.h"
/**
 * putch - prints a char
 * @ch: character value
 * Return: 0 NoError
 */
int putch(char ch)
{
return (write(1, &ch, 1));
}
/**
 * print - prints a string
 * @str: string value
 */
void print(char *str)
{
while (*str != '\0')
{
putch(*str);
str++;
}
}
/**
 * put_grid - prints in a grid
 * @grid: pointer of pointer to a value
 */
void put_grid(char **grid)
{
int i;
for (i = 0; grid[i] != NULL; i++)
{
print(grid[i]);
putch('\n');
}
}
/**
 * p_error - prints error message to stderr
 * @msg: error message
 */
void p_error(char *msg)
{
while (*msg != '\0')
{
write(STDERR_FILENO, msg, 1);
msg++;
}
}
