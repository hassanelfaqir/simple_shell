#include "shell.h"
/**
 * intToString - Convert an integer to a string.
 * This function converts an integer 'num' to its string representation.
 * @num: The integer to be converted.
 * Return: A dynamically allocated string representing 'num'.
 */
char *intToString(int num)
{
	int temp = num, digits = 0, i;
	char *str;

	while (temp != 0)
	{
		temp /= 10;
		digits++;
	}
	if (num == 0)
	{
		str = (char *)malloc(2 * sizeof(char));

		if (str == NULL)
		{
			perror("Memory allocation error");
			exit(EXIT_FAILURE);
		}
		str[0] = '0';
		str[1] = '\0';
		return (str);
	}
	str = (char *)malloc((digits + 1) * sizeof(char));

	if (str == NULL)
	{
		perror("Memory allocation error");
		exit(EXIT_FAILURE);
	}
	if (num < 0)
	{
		str[0] = '-';
		num = -num;
	}
	str[digits] = '\0';
	for (i = digits - 1; i >= 0; i--)
	{
		str[i] = num % 10 + '0';
		num /= 10;
	}
	return (str);
}
