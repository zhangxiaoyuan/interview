include <stdio.h>
#include <signal.h>

int main()
{
    printf("main is waiting for singla input\n");
    if (SIG_ERR == signal(SIGINT, SIG_DFL))
    {
        printf("signal install error\n");
 	return -1;
    }

    for(;;){}

    return 1;
}
