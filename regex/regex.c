#include "regex.h"

/**
 * regex_match - Checks if a given pattern matches a given string.
 * @str: The input string to check.
 * @pattern: The regular expression pattern (supports "." and "*").
 *
 * Return: 1 if the pattern matches the string exactly, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern);

/**
 * match_here - Checks if the pattern matches from the current position.
 * @str: Current position in the input string.
 * @pattern: Current position in the pattern.
 *
 * Return: 1 if the remaining pattern matches, 0 otherwise.
 */
static int match_here(char const *str, char const *pattern);

/**
 * match_star - Handles the "*" operator for zero or more occurrences.
 * @c: The character preceding the "*".
 * @str: Current position in the input string.
 * @pattern: Position in the pattern after the "*".
 *
 * Return: 1 if a match is found, 0 otherwise.
 */
static int match_star(char c, char const *str, char const *pattern);

/**
 * regex_match - Implementation of the public API.
 * @str: The input string to check.
 * @pattern: The regular expression pattern.
 *
 * Return: 1 if the pattern matches the string, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern)
{
	if (str == NULL || pattern == NULL)
		return (0);

	return (match_here(str, pattern));
}

/**
 * match_here - Recursive routine that processes one character at a time.
 * @str: Current position in the input string.
 * @pattern: Current position in the pattern.
 *
 * Return: 1 if the pattern matches from this point, 0 otherwise.
 */
static int match_here(char const *str, char const *pattern)
{
	/* If we reached the end of the pattern */
	if (*pattern == "\0")
		return (*str == "\0");

	/* If the next character in pattern is "*" */
	if (*(pattern + 1) == "*")
		return (match_star(*pattern, str, pattern + 2));

	/* Check for match of current char or "." */
	if (*str != "\0" && (*pattern == "." || *pattern == *str))
		return (match_here(str + 1, pattern + 1));

	/* No match */
	return (0);
}

/**
 * match_star - Implements the "*" operator logic.
 * @c: The character before "*".
 * @str: Current position in the input string.
 * @pattern: Position in the pattern after "*".
 *
 * Return: 1 if a valid match is found, 0 otherwise.
 */
static int match_star(char c, char const *str, char const *pattern)
{
	const char *s = str;

	while (*s != "\0" && (c == "." || *s == c))
	{
		if (match_here(s, pattern))
			return (1);
		s++;
	}

	return (match_here(s, pattern));
}
