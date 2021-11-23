#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(void)
{
        pid_t pid;
        pid = fork();
        if(pid>0)
        {
                printf("\nPARENT -----> PID:%d, PPID:%d\n",getpid(), getppid());
                exit(10);
        }
        else if(pid==0)
        {
                printf("\nCHILD ------> PID:%d, PPID:%d\n",getpid(), getppid());
                sleep(5);
                printf("Child adopted by other parent now:");
                printf("\n\nCHILD ------> PID:%d, PPID:%d",getpid(), getppid());
                        
        }
        else
        {
                printf("Fork Error\n");
                exit(1);
        }
}