#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>


/************************************************
********************接收端************************
*************************************************/
void sighandler(int signo, siginfo_t *info,void *ctx);
//给自身传递信息
int main(void)
{

    struct sigaction act;
    act.sa_sigaction = sighandler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = SA_SIGINFO;//信息传递开关
    if(sigaction(SIGINT,&act,NULL) == -1){
        perror("sigaction error");
        exit(EXIT_FAILURE);
    }
    for(; ;){
        printf("waiting a SIGINT signal....\n");
        pause();
    }
    return 0;
}

void sighandler(int signo, siginfo_t *info,void *ctx)
{
    //以下两种方式都能获得sigqueue发来的数据
    printf("receive the data from siqueue by info->si_int is %d\n",info->si_int);
    printf("receive the data from siqueue by info->si_value.sival_int is %d\n",info->si_value.sival_int);

}


/************************************************
*******************发送端************************
*************************************************/
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    if(argc != 2){
        fprintf(stderr,"usage:%s pid\n",argv[0]);
        exit(EXIT_FAILURE);
    }
    pid_t pid = atoi(argv[1]);    
    sleep(2);
    union sigval mysigval;
    mysigval.sival_int = 100;
    printf("sending SIGINT signal to %d......\n",pid);
    if(sigqueue(pid,SIGINT,mysigval) == -1){
        perror("sigqueue error");
        exit(EXIT_FAILURE);
    }
    return 0;
}
