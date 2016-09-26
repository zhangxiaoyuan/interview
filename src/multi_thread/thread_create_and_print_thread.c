#include <stdio.h>
#include <pthread.h>
#include <string.h>
#include <strings.h>

void* pthread_proc(void* args)
{
    int* pnum = (int*)args;
    printf("this is %d thread\n", *pnum);
    pthread_exit("thread exit...");
}

int main()
{
    char buff[20];
    int i = 0;
    /*The bzero() function sets the first n bytes of the byte area starting at s to zero (bytes containing '\0').*/
    bzero(buff, 20);
    printf("n = %d\n", strlen(buff));

    int ret = read(0, buff, 100);
    if (ret == -1)
    {
	printf("error\n");
	return -1;
    }
    int num = atoi(&buff);
    printf("num = %d\n\n", num);

    if (num > 0)
    {
  	for (;i < num; i++)
	{
	    pthread_t pt;
	    void* pret;
	    int ret = pthread_create(&pt, NULL, pthread_proc, (void*)&i);
   	    if (ret)
	    {
		printf("create %d thread error\n", i);
		continue;
   	    }
	   
	    /*pthread_join()函数，以阻塞的方式等待thread指定的线程结束。当函数返回时，被等待线程的资源被收回。
  	    如果线程已经结束，那么该函数会立即返回。并且thread指定的线程必须是joinable的*/ 
  	    pthread_join(pt, &pret);
            printf("thread %d return : %s\n\n", i, (char*)pret);	
    	}	
    }
    else
    {
 	printf("input num error\n");
    }

    printf("main thread already create and stop %d nums threads\n", num);

    /*for (i = 0; i < num; i++)
    {
	
    }*/
    return 1;
}
