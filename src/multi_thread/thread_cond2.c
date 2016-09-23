/*
初始化条件变量。
静态态初始化，pthread_cond_t cond = PTHREAD_COND_INITIALIER;
动态初始化，int pthread_cond_init(pthread_cond_t *cond, pthread_condattr_t *cond_attr);
等待条件成立。释放锁,同时阻塞等待条件变量为真才行。timewait()设置等待时间,仍未signal,返回ETIMEOUT(加锁保证只有一个线程wait)
int pthread_cond_wait(pthread_cond_t *cond, pthread_mutex_t *mutex);
int pthread_cond_timewait(pthread_cond_t *cond,pthread_mutex *mutex,const timespec *abstime);
激活条件变量。pthread_cond_signal,pthread_cond_broadcast（激活所有等待线程）
int pthread_cond_signal(pthread_cond_t *cond);
int pthread_cond_broadcast(pthread_cond_t *cond); //解除所有线程的阻塞
清除条件变量。无线程等待,否则返回EBUSY
int pthread_cond_destroy(pthread_cond_t *cond);
*/



#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

static pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
static pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

struct node
{
    int n_number;
    struct node *n_next;
}*head = NULL;

static void cleanup_handler(void *arg)
{
    printf("Cleanup handler of second thread./n");
    free(arg);
    (void)pthread_mutex_unlock(&mtx);
}

static void *thread_proc(void *arg)
{
    struct node *p = NULL;
    pthread_cleanup_push(cleanup_handler, p);
    while (1)
    {
        //这个mutex主要是用来保证pthread_cond_wait的并发性
        pthread_mutex_lock(&mtx);
        while (head == NULL)
        {
            //这个while要特别说明一下，单个pthread_cond_wait功能很完善，为何
            //这里要有一个while (head == NULL)呢？因为pthread_cond_wait里的线
            //程可能会被意外唤醒，如果这个时候head != NULL，则不是我们想要的情况。
            //这个时候，应该让线程继续进入pthread_cond_wait
            // pthread_cond_wait会先解除之前的pthread_mutex_lock锁定的mtx，
            //然后阻塞在等待对列里休眠，直到再次被唤醒(大多数情况下是等待的条件成立
            //而被唤醒，唤醒后，该进程会先锁定先pthread_mutex_lock(&mtx);，再读取资源
            //用这个流程是比较清楚的
            pthread_cond_wait(&cond, &mtx);
            p = head;
            head = head->n_next;
            printf("Got %d from front of queue/n", p->n_number);
            free(p);
        }
        pthread_mutex_unlock(&mtx); //临界区数据操作完毕，释放互斥锁
    }
    pthread_cleanup_pop(0);
    return 0;
}

int main()
{
    pthread_t pt; 
    int i;
    struct node* p;

    int ret = pthread_create(&pt, NULL, thread_proc, (char*)"thread1");
    if (ret)
    {
        return -1;
    }

    sleep(1);
    for (i = 0; i < 10; i++)
    {
        p = (struct node*)malloc(sizeof(struct node));
        p->n_number = i;
        pthread_mutex_lock(&mtx); //需要操作head这个临界资源，先加锁，
        p->n_next = head;
        head = p;
        pthread_cond_signal(&cond);
        pthread_mutex_unlock(&mtx); //解锁
        sleep(1);
    }
    printf("thread 1 wanna end the line.So cancel thread 2./n");
    //关于pthread_cancel，有一点额外的说明，它是从外部终止子线程，子线程会在最近的取消点，退出
    //线程，而在我们的代码里，最近的取消点肯定就是pthread_cond_wait()了。
    pthread_cancel(pt);
    pthread_join(pt, NULL);
    printf("All done -- exiting/n");

    return 1;    
}
