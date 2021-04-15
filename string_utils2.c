#include "shell.h"
/**
 * _cstrcmp - compares smaller str part to the larger
 * @s1: first string
 * @s2: second string
 * Return: 0 string parts are equal, > 0 or < 0 greater or lesser,
 */
int _cstrcmp(const char *s1, const char *s2)
{
int i, len_s1, len_s2, len_s;
len_s1 = _strlen(s1);
len_s2 = _strlen(s2);
len_s = _min(len_s1, len_s2);
for (i = 0; i < len_s; i++)
{
if (s1[i] != s2[i])
return (s1[i] - s2[i]);
}
return (0);
}
/**
 * _max - the max of two numbers
 * @n: number1
 * @m: number2
 * Return: maximum number
 */
int _max(int n, int m)
{
if (n > m)
return (n);
return (m);
}
/**
 * _min - the min of two numbers
 * @n: number1
 * @m: number2
 * Return: minimum number
 */
int _min(int n, int m)
{
if (n < m)
return (n);
return (m);
}
/**
 * _strcmp - compare two strings
 * @s1: first string
 * @s2: second string
 * Return: < 0 if s1 < s2, > 0 if s2 > s1, 0 strings match
 */
int _strcmp(const char *s1, const char *s2)
{
int i = 0, j = 0;
for ( ; s1[i] != '\0'; i++)
{
if (s1[j] != s2[j])
break;
j++;
}
return (s1[j] - s2[j]);
}
