#include "shell.h"
/**
 * prompt1 - prompts user for input
 */
void prompt1(void)
{
print("$ ");
}

/**
 * isinteractive - checks mode of interaction
 * Return: 1 if interactive, 0 if pipe
 */
int isinteractive(void)
{
struct stat filestatus;
if (fstat(0, &filestatus) == -1)
{
perror("fstat");
exit(EXIT_FAILURE);
}
if (S_ISFIFO(filestatus.st_mode))
{/* calling from term in non interactive mode */
return (0);
}
return (1);
}

