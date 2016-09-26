#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

void sig_proc(int signo)
{
    printf("catch the signal %d\n", signo);
}

int main()
{
    printf("main is waiting for signal\n");
    if (SIG_ERR == signal(SIGINT, sig_proc))
    {
        perror("signal error\n");
     	return -1;
    }

    for(;;){}

    return 1;
}
