#include "substring.h"

/**
 * find_substring - program that finds the starting indices of substrings
 * in 's' that are concatenations of all the 'words' exactly once
 *
 * @s: the string to search within
 * @words: the array of words to form the substring
 * @nb_words: the number of words in the array
 * @n: a pointer to store the number of substrings found
 *
 * Return: the array of starting indices of substrings in 's'
 */

int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int strLen, wordLen, idxWord, idxStr = 0, idxCheck;
	int *startingIndices, *foundWords;

	if (!s)
		return (NULL);

	*n = 0;

	strLen = strlen(s);
	wordLen = strlen(words[0]);

	foundWords = malloc(nb_words * sizeof(int));
	startingIndices = malloc(strLen * sizeof(int));

	while (idxStr <= strLen - nb_words * wordLen)
	{
		for (idxWord = 0; idxWord < nb_words; idxWord++)
			foundWords[idxWord] = 0;

		for (idxWord = 0; idxWord < nb_words; idxWord++)
		{
			for (idxCheck = 0; idxCheck < nb_words; idxCheck++)
			{
				if (foundWords[idxCheck] == 0 &&
				strncmp(s + idxStr + idxWord * wordLen, words[idxCheck], wordLen) == 0)
				{
					foundWords[idxCheck] = 1;
					break;
				}
			}
			if (idxCheck == nb_words)
				break;
		}
		if (idxWord == nb_words)
			startingIndices[(*n)++] = idxStr;
		idxStr++;
	}
	free(foundWords);

	return (startingIndices);
}
