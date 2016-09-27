#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>


static pthread_mutex_t mutex;
static pthread_cond_t cond;

void* cleanup_proc(void* arg)
{
    free(arg);
    pthread_mutex_unlock(&mutex);
}

void* thread1_proc(void* arg)
{
    printf("this is thread1, %s\n", (char*)arg);
    /*
    pthread_cleanup_push和pthread_cleanup_pop函数作用：
    pthread_cleanup_push注册一个回调函数，如果你的线程在对应的pthread_cleanup_pop之前异常退出(return是正常退出，其他是异常)，
    那么系统就会执行这个回调函数(回调函数要做什么你自己决定)。但是如果在pthread_cleanup_pop之前没有异常退出，pthread_cleanup_pop就把对应的回调函数取消了，
    */
    //pthread_cleanup_push((void*)cleanup_proc, (void*)&mutex);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
 	printf("thread1 applied the cond\n");
    	pthread_mutex_unlock(&mutex);
        sleep(1);		
    }
    //pthread_cleanup_pop(0);

    pthread_exit((char*)"thread1 said bye");
}

void* thread2_proc(void* arg)
{
    printf("this is thread2, %s\n", (char*)arg);
    while(1)
    {
        pthread_mutex_lock(&mutex);
        pthread_cond_wait(&cond, &mutex);
        printf("thread2 applied the condition\n");
        pthread_mutex_unlock(&mutex);
        sleep(4);
    }

    pthread_exit((char*)"thread2 said bye");
}

int main()
{
    pthread_t pt1, pt2;
    int ret;
    void* threadRet1, *threadRet2;
   
    //初始化互斥锁和条件变量
    pthread_mutex_init(&mutex, NULL);
    pthread_cond_init(&cond, NULL);

    ret = pthread_create(&pt1, NULL, thread1_proc, (void*)"hello, thread1");
    if (ret) //创建线程成功返回0，失败返回错误码
    {
	printf("create thread1 fail\n");
	return -1;
    }

    ret = pthread_create(&pt2, NULL, thread2_proc, (void*)"hello, thread2");
    if (ret)
    {
	printf("create thread2 fail\n");
	return -1;
    }

    sleep(1);

    do
    {
	//printf("main thread signal\n");
     	//激活条件变量cond
  	pthread_cond_signal(&cond);
	//sleep(1);
    }while(1);

    sleep(20);
    pthread_exit(0);
	
    
    pthread_join(pt1, &threadRet1);    
    printf("thread1 over and said: %s", (char*)threadRet1);
	
    pthread_join(pt2, &threadRet2);
    printf("thread2 over and said: %s", (char*)threadRet2);
    
    pthred_mutex_destroy(mutex);
    pthred_cond_destroy(cond);
    return 1;
}
