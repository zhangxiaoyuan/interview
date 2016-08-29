####22.Linux内核调度：
  * [linux内核调度机制](http://www.cppblog.com/baby-fly/archive/2011/01/27/139436.html)
  * [Linux内核进程调度以及定时器实现机制](http://www.cppblog.com/baby-fly/archive/2011/01/27/139436.html)
  * Linux的进程管理由进程控制块、进程调度、中断处理、任务队列、定时器、bottom half队列、系统调用、进程通信等等部分组成
    * 进程控制块数据结构：
     所有进程（以PCB形式）组成一个双向列表。next_task和prev_task就是链表的前后向指针。链表的头尾都是init_task（init进程）。
     过进程还要根据其进程ID号插入到一个hash表当中，目的是加快进程搜索速度
     Linux系统的进程控制块用数据结构task_struct表示，这个数据结构占用1680个字节,进程运行状态包括如下几个：
     a.TASK_RUNNING  正在运行或在就绪队列run-queue中准备运行的进程，实际参与进程调度。
     b.TASK_INTERRUPTIBLE      处于等待队列中的进程，待资源有效时唤醒，也可由其它进程通过信号或定时中断唤醒后进入就绪队列run-queue。
     c.TASK_UNINTERRUPTIBLE 处于等待队列的进程，待资源有效时唤醒，不可由其它进程通过信号或者定时中断唤醒。
     d.TASK_ZOMBIE     表示进程结束但尚未消亡的一种状态（僵死），此时，进程已经结束运行并且已经释放了大部分资源，但是尚未释放进程控制块。
     e.TASK_STOPPED   进程暂停，通过其它进程的信号才能唤醒。
