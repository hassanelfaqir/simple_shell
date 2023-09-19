#include "shell.h"

/**
 * custom_strcmp - Compare two strings character by character.
 * @s1: The first string to compare.
 * @s2: The second string to compare.
 *
 * Return: 0 if the strings are equal, a positive value if s1 is greater,
 *         or a negative value if s2 is greater.
 */
int custom_strcmp(const char *s1, const char *s2)
{
	while (*s1 && *s2 && *s1 == *s2)
	{
		s1++;
		s2++;
	}

	return (*s1 - *s2);
}

