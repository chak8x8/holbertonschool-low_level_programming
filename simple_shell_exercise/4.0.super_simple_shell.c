#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char *line = malloc(1024);
	size_t len = 1024;
	size_t i = 0;

	if (line == NULL)
	{
		perror("Unable to allocate buffer");
		free(line);
		return (1);
	}

	printf("$ ");
	getline(&line, &len, stdin);

	for (i = 0; i < len; i++)
	{
		if (len[i] == '\n')
		{
			len[i] = '\0';
			break;
		}
	}

	printf("Buffer after removing newline: %s\n", buffer);

	free(line);
	return (0);
	
}
