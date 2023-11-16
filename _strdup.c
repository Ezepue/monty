#include "monty.h"

/**
 *_strdup - Duplicates a string
 *@s: String to duplicate
 *
 *This function dynamically allocates memory for a new string
 *and duplicates the input string into the new string.
 *
 * Return: A pointer to the duplicate string on success,
 * NULL if it fails.
 */
char *_strdup(char *s)
{
	char *dup = NULL;
	int i;
	int len;

	if (s == NULL)
		return (NULL);
	len = strlen(s);
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);

	for (i = 0; i < len; i++)
		dup[i] = s[i];
	dup[i] = '\0';
	return (dup);
}
