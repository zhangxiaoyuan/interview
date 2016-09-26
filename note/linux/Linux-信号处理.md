##1.[信号的生命周期](http://www.cnblogs.com/mickole/p/3190783.html)：
信号诞生  
信号在进程中注册  
信号在进程中的注销  
信号处理函数执行  

##2.信号在进程中处理：
在进程PCB中有一个软中断信号域，域中每一位对应一种信号类型，当本进程收到一个信号就在对应域置位  

当前进程的task_struct中有一个未决信号量的结构：struct sigpending   
```c
struct sigpending{
    struct sigqueue *head, *tail;
    sigset_t signal;
};
```
第一二个结构表示“未决信号链”链表的首末指针，第三个参数表示“未决信号集”，每一个sigqueue都表示一个未决信号的信息和下一个:   
```c
struct sigqueue{
    struct sigqueue *next;
    siginfo_t info;
}
```

##3.信号处理过程：
###3.1信号注册：
 信号注册的过程其实就是将信号信息添加到sigpending中，即将信号信息添加到未决信号集sigset_t中，然后将信号信息添加到sigqueue中  
 主要信号在sigset_t中就表明进程已经知道信号的存在，或许在等待处理，或许被进程阻塞。  
 
 实时信号(可靠信号):当进程收到实时信号，不管信号是否注册，都在sigtset_t中重新注册一次，然后将信号信息加到sigqueue中，意味着可以多次
 添加同一个信号,信号值小于SIGRTMIN的信号最多只注册一次(命令Kill -l可以查看所有信号值)     
 
 非实时信号(不可靠信号):当进程收到非实时信号，如果信号已经注册，则丢弃，如果未注册，则添加到sigset_t中和sigqueue中,信号值在SIGRTMIN及SIGRTMAX之间的信号，只要被进程接收到就被注册  
 
###3.2信号执行：
 执行时机:内核处理一个进程收到的软中断信号是在该进程的上下文中，因此，进程必须处于运行状态,因此在其从内核空间返回到用户空间时会检测是否有信号等待处理，如果信号未被进程阻塞，则处理信号  
 
 实时信号：处理实时信号时，先处理一个信号然后删除sigqueue中信息，然后检测同一在信号是否还有sigqueue信息，直到同一信号的所有sigqueue
 全部处理完，才会将信号从sigset_t移除   
 
 非实时信号：处理完sigqueue中信息之后就会将对应的sigset_t中信息移除   
 
###3.3信号安装：
 信号安装主要是注册处理信号值与信号对应处理的映射关系，即进程将要处理哪个信号；该信号被传递给进程时，将执行何种操作  
 
 信号安装有两个函数：signale()和signale_action()。
 + signal():主要针对前32种非实时信号，不支持传递信息
 + signal_action():可以处理实时信号和非实时信号，区别是支持传递信号信息，由两个系统调用sys_signal和sys_rt_sigaction实现
 
###3.4信号发送：
 信号可以通过kill()/raise()/sigqueue()/alarm()/settimer()/abort()函数发送信号  
 + kill(pid, sigid): 通过设置不同的pid，可以给不同的进程发送信号，例如指定pid发送(getpid, getppid)，可以给同一组进程发送(getpgrp)
 + riase(sigid): 给自己进程发送信号。等效于kill(getpid(), sigid)
 + alarm(seconds)：安排内核为进程在特定时间seconds之后发送一个SIGALRM信号。seconds为0则不发送信号，后一次设置将取消前一次设定,每次只发送一个信号
 
###3.5信号集：
 信号集用来描述信号的集合，每个信号占用一位（64位）。Linux所支持的所有信号可以全部或部分的出现在信号集中，主要与信号阻塞相关函数配合使用。   
 使用如下的数据结构：    
```c
typedef struct {
    unsigned long sig[_NSIG_WORDS]；
} sigset_t
```
 - 信号抵达(delivery)：执行信号的处理动作
 - 信号未决(pending)：信号从产生到抵达之间的状态
 - 信号阻塞(block)：进程可以阻塞信号，被阻塞的信号产生时将保持在未决状态，直到进程解除对此信号的阻塞，才执行递达的动作
 
 >
  阻塞和忽略区别：阻塞和忽略是不同的，只要信号被阻塞就不会递达，而忽略是在递达之后可选的一种处理动作
 
信号在内核中有三个集合表示不同的状态：
 * block集（阻塞集、屏蔽集）：一个进程所要屏蔽的信号，在对应要屏蔽的信号位置1
 * pending集（未决信号集）：如果某个信号在进程的阻塞集中，则也在未决集中对应位置1，表示该信号不能被递达，不会被处理
 * handler（信号处理函数集）：表示每个信号所对应的信号处理函数，当信号不在未决集中时，将被调用
 
```c
struct sigaction act;
act.sa_handler = handler;
sigemptyset(&act.sa_mask);
sigaddset(&act.sa_mask, SIGQUIT);
act.sa_flags = 0;

if (sigaction(SIGINT, &act, NULL) < 0)
    ERR_EXIT("sigaction error");
```
安装信号SIGINT时，将SIGQUIT加入到sa_mask阻塞集中，则当SIGINT信号正在执行处理函数时，SIGQUIT信号将被阻塞，只有当SIGINT信号处理函数  
执行完后才解除对SIGQUIT信号的阻塞，由于SIGQUIT是不可靠信号，不支持排队，所以只递达一次

