#include "shell.h"
/**
 * _strncmp - compares n chars in two strings
 * @s1: string1
 * @s2: string2
 * @n: length of char in a string
 * Return: 0 if match or int value of differences
 */
int _strncmp(char *s1, char *s2, int n)
{
int i;
for (i = 0; i < n - 1; i++)
{
if (s1[i] == '\0' || s2[i] == '\0')
break;
if (s1[i] != s2[i])
break;
}
return (s1[i] - s2[i]);
}
/**
 * _strlen - counts char length of string
 * @str: string
 * Return: char length of string
 */
int _strlen(const char *str)
{
int i = 0;
for (i = 0; str[i]; i++)
;
return (i);
}
/**
 * _strcat - concatenates src to dest string
 * @dest: string1
 * @src: string2
 * Return: result string
 */
char *_strcat(char *dest, const char *src)
{
size_t dest_len = _strlen(dest);
size_t i;
for (i = 0; src[i] != '\0'; i++)
dest[dest_len + i] = src[i];
dest[dest_len + i] = '\0';
return (dest);
}
/**
 * _strcpy - copies src to dest string
 * @dest: string1
 * @src: string2
 * Return: result string
 */
char *_strcpy(char *dest, const char *src)
{
size_t i;
for (i = 0; src[i] != '\0'; i++)
dest[i] = src[i];
i++;
dest[i] = '\0';
return (dest);
}
/**
 * _strdup - returns replica string
 * @str: string
 * Return: copied string pointer
 */
char *_strdup(char *str)
{
int i, length;
char *str2;
for (i = 0; *str != '\0'; i++)
str++;
length = i;
str = str - length;
str2 = malloc(sizeof(char) * (length + 1));
if (str2 == NULL)
{
perror("strdup");
return (NULL);
}
for (i = 0; i <= length; i++)
{
*str2 = *str;
str++;
str2++;
}
return (str2 - length - 1);
}
