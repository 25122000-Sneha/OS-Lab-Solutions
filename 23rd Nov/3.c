#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
int main(void)
{
        pid_t pid;
        pid = fork();
        if (pid > 0)
        {       //Parent will sleep
                sleep(20);
        }
        else
        {
                //I am a Child
                exit(0);
        }
        return 0;
}