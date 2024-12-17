/* 0. getppid
 * Write a program that prints the PID of the parent process. 
 * Run your program several times within the same shell. 
 * It should be the same. 
 * Does echo $$ print the same value? Why? */


#include <stdio.h>
#include <unistd.h>

int main(void)
{
	pid_t parent_pid;
	parent_pid = getppid();
	printf("Parent PID: %u\n", parent_pid);
       	return (0);
}
