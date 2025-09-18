#include "substring.h"

/**
 * main - test program for find_substring
 * @ac: argument count
 * @av: argument values
 *
 * Return: 0 on success, 1 on failure
 */
int main(int ac, char const **av)
{
	char const *s;
	char const **words;
	int nb_words;
	int *indices;
	int n;
	int i;

	if (ac < 2)
	{
		fprintf(stderr, "Usage: %s <string> [word [word2 ...]]\n", av[0]);
		return (EXIT_FAILURE);
	}

	s = av[1];
	words = av + 2;
	nb_words = ac - 2;

	indices = find_substring(s, words, nb_words, &n);

	printf("Indices -> [");
	for (i = 0; i < n; i++)
	{
		if (i)
			printf(", ");
		printf("%d", indices[i]);
	}
	printf("]\n");

	free(indices);
	return (EXIT_SUCCESS);
}
