#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>


void print_sigset(const sigset_t* sigset)
{
    int i = 1;
    for (; i < NSIG; i++)
    {
    	if (sigismember(sigset, i))
	{
     	    printf("1");
	}
	else
	{ 
 	    printf("0");
	}
    }

    printf("\n");
}


int main()
{
    int ret = 0;
    sigset_t sigset;
    
    ret &= sigemptyset(&sigset);
    ret &= sigfillset(&sigset);

    print_sigset(&sigset);
   
    ret &= sigemptyset(&sigset);
    ret &= sigaddset(&sigset, SIGINT);
    ret &= sigaddset(&sigset, SIGQUIT);
    ret &= sigaddset(&sigset, SIGUSR1);
    ret &= sigaddset(&sigset, SIGUSR2);
    ret &= sigaddset(&sigset, SIGSTOP);

    print_sigset(&sigset);

    ret &= sigdelset(&sigset, SIGSTOP);
    ret &= sigdelset(&sigset, SIGUSR2);

    print_sigset(&sigset);    
 
    return 1;
}
