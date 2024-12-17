/*2. command line to av
 * Write a function that splits a string and returns an array of each word of the string.*/

#include <stdio.h>
#include <stdlib.h>

char **split_string(char *str);

int main(void)
{
	char input[] = "This is a test string";
	char **words = split_string(input);
	int i = 0;

	for (i = 0; words[i] != '\0'; i++)
	{
		printf("Word %d: %s\n", i + 1, words[i]);
	}
	
	free(words);
	return (0);

}
