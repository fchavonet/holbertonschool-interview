#include "substring.h"

/**
 * match_window - Checks if a window contains all words exactly once.
 * @window: pointer to substring window in s.
 * @words: array of words.
 * @nb_words: number of words.
 * @word_len: length of each word.
 *
 * Return: 1 if match, 0 otherwise.
 */
static int match_window(char const *window, char const **words, int nb_words,
		int word_len)
{
	int i, j;
	int *used;
	int found;

	used = calloc(nb_words, sizeof(int));

	if (!used)
	{
		return (0);
	}

	for (i = 0; i < nb_words; i++)
	{
		found = 0;

		for (j = 0; j < nb_words; j++)
		{
			if (!used[j] &&
					strncmp(window + i * word_len, words[j], word_len) == 0)
			{
				used[j] = 1;
				found = 1;
				break;
			}
		}

		if (!found)
		{
			free(used);
			return (0);
		}
	}

	free(used);
	return (1);
}

/**
 * find_substring - Finds starting indices of concatenated words in s.
 * @s: string to scan.
 * @words: array of words.
 * @nb_words: number of words.
 * @n: pointer to store number of indices found.
 *
 * Return: array of starting indices (malloc'ed) or NULL if none found.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len;
	int word_len;
	int concat_len;
	int i;
	int *indices = NULL;
	int count = 0;

	*n = 0;

	if (!s || !words || nb_words <= 0)
	{
		return (NULL);
	}

	word_len = strlen(words[0]);
	concat_len = word_len * nb_words;
	s_len = strlen(s);

	for (i = 0; i <= s_len - concat_len; i++)
	{
		if (match_window(s + i, words, nb_words, word_len))
		{
			indices = realloc(indices, sizeof(int) * (count + 1));

			if (!indices)
			{
				return (NULL);
			}

			indices[count] = i;
			count++;
		}
	}

	*n = count;
	return (indices);
}
