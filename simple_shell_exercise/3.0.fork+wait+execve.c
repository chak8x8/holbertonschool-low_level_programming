/* Exercise: fork + wait + execve
 * Write a program that executes the command ls -l /tmp in 5 different child processes. 
 * Each child should be created by the same process (the father). 
 * Wait for a child to exit before creating a new child.*/

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main(void)
{
	pid_t pid;
	int i = 0;
	char *args = {"/bin/ls", "-l", "/tmp", NULL};

	for (i = 0; i < 5; i++)
	{
		pid = fork();

		if (pid == -1)
		{
			perror(fork);
			exit(1);
		}
		else if (pid ==  0)
		{
			printf("Child %d executing ls -l /tmp\n", i + 1);
			if (execve(args[0], args, NULL) == -1)
			{
				peror(execve);
				exit(1);
			}
		}
		else
		{
			wait(NULL);
			printf("Child %d finished\n", i + 1);

		}
	}

	return (0);

}
