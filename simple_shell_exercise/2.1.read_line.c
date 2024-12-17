/* 1. Read line
 * Write a program that prints "$ ", 
 * wait for the user to enter a command, 
 * prints it on the next line. */


#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *line;
	size_t len = 0;
	ssize_t read;

	while (1)
	{
		printf("$ ");
		read = getline(&line, &len, stdin);
		if (read == -1)
		{
			free(line);
			break;
		}
		printf("%s", line);
	}
	return (0);
}
