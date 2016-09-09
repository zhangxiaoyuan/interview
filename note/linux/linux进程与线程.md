####1.[线程同步方式](http://blog.csdn.net/iw1210/article/details/8509629)
* 互斥锁mutex:
锁机制是同一时刻只允许一个线程执行一个关键部分的代码。
 * 初始化锁：pthread_mutex_init(锁，锁属性[普通锁、嵌套锁、检测锁、适应锁]);
 * 阻塞加锁/非阻塞加锁：pthread_mutex_lock()/pthread_mutex_trylock(),非阻塞锁在锁被占用时返回EBUSY,而不是挂起等待
 * 解锁：pthread_mutex_unlock();要求锁是lock状态，并且只能由加锁线程解锁
 * 销毁：pthread_mutex_destroy();此时锁必须是unlock状态，否则返回EBUSY;
 
* 条件变量cond：
条件变量是利用线程间共享全局变量进行同步的一种机制，条件变量操作：触发条件(当条件边为true),等待条件，挂起线程直到其他条件触发；
 * 初始化条件变量: pthread_cond_init();
 * 等待条件：
  * 无条件等待：pthread_cond_wait();
  * 计时等待：pthread_Cond-timewait(); 如果在给定时刻前条件没有满足，则返回ETIMEOUT，结束等待
 * 激发条件：
  * 激活一个等待该条件的线程（存在多个等待线程时按入队顺序激活其中一个）：pthread_cond_signal()
  * 激活所有等待线程:pthread_cond_broadcast()
 * 销毁条件变量：只有在没有线程在该条件变量上等待的时候才能销毁这个条件变量，否则返回EBUSY,  pthread_cond_destroy().

* 信号量：
如同进程一样，线程也可以通过信号量来实现通信，虽然是轻量级的。
 * 初始化信号量：sem_init()
 * 信号量加1：sem_post();
 * 信号量减1：sem_wait();
 * 信号量销毁：sem_destroy();


2.[线程私有数据](http://blog.chinaunix.net/uid-8917757-id-2450452.html)
