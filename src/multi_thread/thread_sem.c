#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>


#define MAXSIZE 10

//int size = 0;
int stack[MAXSIZE];
sem_t sem;


void* creater_proc(void* arg);
void* handler_proc(void* arg);

int main()
{
    pthread_t creater, handler;
    int ret;
    void* threadRet1;
    void* threadRet2;
 
    //第二参数:表示是线程间共享还是进程间共享,0表示同一个进程的不同线程共享，非0表示不同线程共享
    //第三个参数：pv操作的初始值
    sem_init(&sem, 0, 0);
	
    ret = pthread_create(&creater, NULL, creater_proc, (void*)"create");
    if (ret)
    {
	printf("create creater thread faile\n");
    }
    
    ret = pthread_create(&handler, NULL, handler_proc, (void*)"handler");
    if (ret)
    {
	printf("create handler thread, faile\n");
    }	

    ret = pthread_join(creater, &threadRet1);
    printf("%s\n", (char*)threadRet1);
    ret = pthread_join(handler, &threadRet2);
    printf("%s\n", (char*)threadRet2);


    sem_destroy(&sem);
  
    return 1;
}


void* creater_proc(void* arg)
{
    printf("i am %s\n", (char*)arg);

    int i;
    for (i=0; i< MAXSIZE; i++) 
    {
        stack[i] = i;
        sem_post(&sem); //为信号量加1
    }

    pthread_exit("creater exit..");
}

void* handler_proc(void* arg)
{
    printf("i am %s \n", (char*)arg);

    int i = 0;
    //while((i = size++) < MAXSIZE) 
    while(i < MAXSIZE)
    {
        sem_wait(&sem);
        printf("乘法: %d X %d = %d\n", stack[i], stack[i], stack[i]*stack[i]);
	i++;
        //sleep(1);
    }
    
    pthread_exit("handler eixt..");
}
