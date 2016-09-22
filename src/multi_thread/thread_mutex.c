
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int sharedi = 0;
void increse_num(void);

//加互斥锁,初始化锁
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

int main(){
    int ret;
    pthread_t thrd1, thrd2, thrd3;

    //初始化mutex
    pthread_mutex_init(&mutex, NULL);

    ret = pthread_create(&thrd1, NULL, (void *)increse_num, NULL);
    ret = pthread_create(&thrd2, NULL, (void *)increse_num, NULL);
    ret = pthread_create(&thrd3, NULL, (void *)increse_num, NULL);

    pthread_join(thrd1, NULL);
    pthread_join(thrd2, NULL);
    pthread_join(thrd3, NULL);

    //互斥锁使用完之后需要销毁
    pthread_mutex_destroy(&mutex);
    printf("sharedi = %d\n", sharedi);


    return 0;

}

void increse_num(void) {
    long i,tmp;
    for(i=0; i<=100000; i++) {
	if (pthread_mutex_lock(&mutex))
	{
	    printf("mutex lock faile\n");
	    pthread_exit("mutex lock faile");
	}
        tmp = sharedi;
        tmp = tmp + 1;
        sharedi = tmp;
	if (pthread_mutex_unlock(&mutex))
	{
 	    printf("mutex unlock faile\n");
	    pthread_exit("mutex unlock faile");
	}
    }

    pthread_exit("thread exit ok");
}

