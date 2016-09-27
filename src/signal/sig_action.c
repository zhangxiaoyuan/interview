#include <stdio.h>
#include <unistd.h>
#include <signal.h>


void sig_proc(int signo)
{
    printf("sig proc...signo = %d\n", signo);
}

int main()
{
    struct sigaction act;
    act.sa_handler = sig_proc;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;

    //功能与signal相似，注册信号处理函数，但是sigaction可以处理传递的信息，signal不能传递信息
    if (sigaction(SIGINT, &act, NULL))
    {
	printf("sig action error \n");
	return -1;
    }

    for(;;){}

    return 1;
}
