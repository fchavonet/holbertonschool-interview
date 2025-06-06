#ifndef REGEX_H
#define REGEX_H

#include <stdlib.h>

/**
 * regex_match - Checks whether the given pattern matches the given string.
 * @str: the string to scan.
 * @pattern: the regular expression, which may include '.' and '*'.
 *
 * Return: 1 if the pattern matches the string exactly, 0 otherwise.
 */
int regex_match(char const *str, char const *pattern);

#endif /* REGEX_H */
