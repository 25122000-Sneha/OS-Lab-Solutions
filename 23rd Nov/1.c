#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
int main(void)
{
	pid_t pid;
	printf("Before fork\n");
	pid = fork();
	if(pid>0)
	{
		sleep(1);
		printf("Parent -- PID: %d PPID: %d, CHILD PID: %d\n", getpid(), getppid(), pid);
	}
	else if(pid == 0)
	{
		printf("CHILD -- PID: %d PPID: %d\n", getpid(), getppid());
	}
	else
	{
		printf("Fork error\n");
                exit(1);
	}
	exit(0);
}