#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <string.h>
#include <unistd.h>


/**
当系统调用的过程中产生中断信号，可以通过配置act.sa_flags=SA_RESTART/0;来对应不同的处理
配置为SA_RESTART时在处理完中断之后返回时重新调用系统调用，配置为0时则在处理完中断之后直接返回系统调用错误
**/
void sig_handler(int signum)
{
    printf("in handler\n");
    sleep(1);
    printf("handler return\n");
}

int main(int argc, char **argv)
{
    char buf[100];
    int ret;
    struct sigaction action, old_action;

    action.sa_handler = sig_handler;
    sigemptyset(&action.sa_mask);
    //action.sa_flags = 0;
    /* 版本1:不设置SA_RESTART属性
     * 版本2:设置SA_RESTART属性 */
    action.sa_flags |= SA_RESTART;

    sigaction(SIGINT, NULL, &old_action);
    if (old_action.sa_handler != SIG_IGN) {
        sigaction(SIGINT, &action, NULL);
    }

    bzero(buf, 100);

    ret = read(0, buf, 100);
    if (ret == -1) {
        perror("read");
    }

    printf("read %d bytes:\n", ret);
    printf("%s\n", buf);

    return 0;
}
