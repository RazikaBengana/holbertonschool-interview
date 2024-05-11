#include "holberton.h"

/**
 * wildcmp - program that compares two strings and checks if they are
 * identical
 *
 * 's2' may contain the special character '*', which can replace
 * any string (including an empty string);
 * the comparison ignores these wildcards and focuses on the literal
 * characters in both strings
 *
 * @s1: the first string to be compared
 * @s2: the second string to be compared; may include '*' characters
 *      acting as wildcards
 *
 * Return: 1 if the strings can be considered identical, otherwise 0
 */

int wildcmp(char *s1, char *s2)
{
	if (*s1 == '\0' && *s2 == '\0')
	{
		return (1);
	}

	if (*s2 == '*')
	{
		if (wildcmp(s1, s2 + 1))
		{
			return (1);
		}

		if (*s1 && wildcmp(s1 + 1, s2))
		{
			return (1);
		}
	}

	if (*s1 == *s2)
	{
		return (wildcmp(s1 + 1, s2 + 1));
	}

	return (0);
}
