#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sig_proc(int signo)
{
    printf("proc new process send signal[%d] \n", signo);
}

int main()
{
    pid_t pid = fork();
    if (pid == 0)
    {
	printf("fork new process sucess\n");
	//sleep(1);
  	kill(getppid(), SIGUSR1);
	sleep(1);
     	return 1;
    }

    printf("main process running\n");
    __sighandler_t sh = signal(SIGUSR1, sig_proc);
    if (SIG_ERR == sh)
    {
	printf("signal install error\n");
        return -1;
    }
    
    int n =5;
    while(n > 0)
    {
	printf("left [%d] secds to sleep\n", n);
	n = sleep(n);
    }

    return 1;
}
