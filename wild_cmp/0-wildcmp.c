#include "holberton.h"

/**
 * wildcmp - Compares two strings considering the "*" wildcard.
 * @s1: the input string to be tested.
 * @s2: the pattern string, which may contain '*' characters.
 *
 * Return: 1 if s1 matches s2, otherwise 0.
 */
int wildcmp(char *s1, char *s2)
{
	/* If end of pattern, match only if end of input string. */
	if (*s2 == '\0')
		return (*s1 == '\0');

	/* Wildcard handling. */
	if (*s2 == '*')
	{
		/*
		 * Two cases to consider:
		 * 1) "*"" matches zero characters -> advance in pattern.
		 * 2) "*"" matches at least one character -> advance in input.
		 */
		if (wildcmp(s1, s2 + 1))
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
		return (0);
	}

	/* No wildcard: current characters must match. */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));

	/* Otherwise, no match. */
	return (0);
}
