/*
如同进程一样，线程也可以通过信号量来实现通信，虽然是轻量级的。信号量函数的名字都以"sem_"打头。线程使用的基本信号量函数有四个。
信号量初始化。
int sem_init (sem_t *sem , int pshared, unsigned int value);
这是对由sem指定的信号量进行初始化，设置好它的共享选项(linux 只支持为0，即表示它是当前进程的局部信号量)，然后给它一个初始值VALUE。
等待信号量。给信号量减1，然后等待直到信号量的值大于0。
int sem_wait(sem_t *sem);
释放信号量。信号量值加1。并通知其他等待线程。
int sem_post(sem_t *sem);
销毁信号量。我们用完信号量后都它进行清理。归还占有的一切资源。
int sem_destroy(sem_t *sem);
*/

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
