#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <unistd.h>


#define ERR_EXIT(m) \
    do \
    { \
        perror(m); \
        exit(EXIT_FAILURE); \
    } while(0)

void handler(int sig);
int main(int argc, char *argv[])
{
    if (signal(SIGALRM, handler) == SIG_ERR)
        ERR_EXIT("signal error");

    alarm(10);

    for (;;){}
    return 0;
}

void handler(int sig)
{
    printf("recv a sig=%d\n", sig);
    alarm(1);
}
