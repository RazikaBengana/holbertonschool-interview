#include "regex.h"

/**
 * regex_match - program that checks if a string matches a specified pattern
 * using basic regular expressions (regex)
 *
 * this function supports '.' which matches any single character
 * and '*' which matches zero or more of the preceding element
 *
 * @str: the string to check against the pattern
 * @pattern: the pattern to match, which may include '.' and '*'
 *           as special characters
 *
 * Return: 1 if the pattern matches the entire string, 0 otherwise
 */

int regex_match(char const *str, char const *pattern)
{

	if (*pattern == '\0')
		return (*str == '\0');

	if (*(pattern + 1) == '*')
	{
		return (regex_match(str, pattern + 2) ||
		       (*str && (*str == *pattern || *pattern == '.') &&
		       regex_match(str + 1, pattern)));
	}

	if (*str && (*pattern == '.' || *pattern == *str))
	{
		return (regex_match(str + 1, pattern + 1));
	}

	return (0);
}
