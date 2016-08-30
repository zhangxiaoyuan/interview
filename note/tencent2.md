####22.Linux内核调度：
[linux内核调度机制](http://www.cppblog.com/baby-fly/archive/2011/01/27/139436.html)
[Linux内核进程调度以及定时器实现机制](http://www.cppblog.com/baby-fly/archive/2011/01/27/139436.html)

__Linux的进程管理由进程控制块、进程调度、中断处理、任务队列、定时器、bottom half队列、系统调用、进程通信等等部分组成。__

* 1.__进程控制块数据结构__：
   所有进程（以PCB形式）组成一个__双向列表__。__next_task和prev_task就是链表的前后向指针。链表的头尾都是init_task（init进程）__。  
   __进程还要根据其进程ID号插入到一个hash表当中，目的是加快进程搜索速度__
   __Linux系统的进程控制块用数据结构task_struct表示__，这个数据结构占用1680个字节,进程运行状态包括如下几个：

   * __TASK_RUNNIN__:   
       正在运行或在就绪队列run-queue中准备运行的进程，实际参与进程调度。
   * __TASK_INTERRUPTIBLE__:   
       处于等待队列中的进程，待资源有效时唤醒，也可由其它进程通过信号或定时中断唤醒后进入就绪队列run-queue。
   * __TASK_UNINTERRUPTIBLE__:  
       处于等待队列的进程，待资源有效时唤醒，不可由其它进程通过信号或者定时中断唤醒。
   * __TASK_ZOMBIE__ :  
       表示进程结束但尚未消亡的一种状态（僵死），此时，进程已经结束运行并且已经释放了大部分资源，但是尚未释放进程控制块.
   * __TASK_STOPPED__:   
       进程暂停，通过其它进程的信号才能唤醒。
     
* 2.__进程调度__：
  __进程调度是由schedule()执行__，其任务就是去__run_queue__队列中选取一个就绪态的进程
  进程调度分为【__实时进程调度__】和【__非实时进程调度__】，
  某个进程采用何种调度算法是根据__进程控制块中数据结构task_struct的【policy属性__】确定，其值主要为__SCHED_RR/SCHED_FIFO(
  这两种为实时进程调度策略)/SCHED_OTHER(普通进程调度策略)__。

 * 非实时进程调度算法:
    __一律采用动态优先级轮转法RR__，
 * 实时进程调度算法：
    __可以采用基于动态优先级的轮转法（RR），也可以采用先进先出算法（FIFO)__.

  > 用户进程的创建主要通过do_fork()实现， 它是fork()系统调用的执行者，do_fork创建一个子进程，继承父进程的资源，
   初始化进程时钟、信号、 时间等，完成子进程初始化后父进程将其挂到run_queue队列。
   子进程刚创建其状态为TASK_UNINTERRUPTIBLE,当初始化完成后被父进程唤醒置于TASK_RUNNING态，此时子进程进入就绪队列中等待调度

  > 如果进程采用轮转法，当时间片到时（10ms的整数倍），由时钟中断触发timer_interrupt()函数引起新一轮的调度，把当前进程挂到就
    绪队列的 尾部。获得CPU而正在运行的进程若申请不到某个资源，则调用sleep_on( )或interruptible_sleep_on( )睡眠，并进入就绪队列尾。
    状态为TASK_INTERRUPTIBLE的睡眠进程当它申请的资源有效时被唤醒，也可以由信号或者定时中断唤醒，唤醒以后进程状态变为TASK_RUNNING。
   
* 3.__进程上下文切换__：
     它做的事只是__保留正在运行进程的"环境"，并把将要运行的进程的"环境"加载上来，这个环境也叫上下文__。
     __它包括各个进程"公用"的东西，比如寄存器__
     
    > 旧的进程环境保存在那，新的进程环境从哪里来，在i386上，有个tss段，是专用来保存进程运行环境的
      在Linux来说，在结构task_struct中有个类型为struct thread_struct的成员叫tss。
      因为Linux一般并不使用ldt，所以它们一般会指向一个共同的空的ldt段描述符，这样就可能不需要切换ldt了，
      如果进程next和prev是共享内存的话，那么页表的转换也就不必要了（这一般发生在clone时）
     
* 4.__系统调用__：
     Linux系统调用的形式与POSIX兼容，是一套C语言函数名的集合，如fork()/read(()等等共221个。
     __系统调用是通过INT 0X80软中断调用进入内核__。

 * 然后根据系统调用号分门别类的进行服务。
  * 系统调用号：文件include/asm-i386/unistd.h为每一个系统调用规定了唯一的编号，这个编号与真正的响应函数之间的关系是利用系统调用号
     为数组的下标，可以在sys_call_table（系统调用表数组）中查找对应的响应函数的sys_name的入口地址。
  * 系统调用表：系统调用表sys_call_table是一组宏定义，将系统调用的编号和相应的内核系统调用处理函数的入口地址绑定。
  
  > 内核宏定义syscallN( )用于系统调用的格式转换和参数的传递。其中N取0～6之间的任意整数。参数个数为N的系统调用由syscallN负责格式
    转换和参数传递  
    对系统调用的初始化，即是对INT 0x80的初始化。系统启动时，汇编子程序setup_idt准备了256项的idt表。  
    设置0x80号软中断服务程序system_call，这个就是所有系统调用的总入口。  
    当进程需要进行系统调用时，必须以C语言函数的形式写一句系统调用命令。  
    该命令如果已经在某个头文件中由相应的syscallN( )展开，则用户程序必须包含该头文件。当进程执行到系统调用命令时，  
    实际上执行的是syscallN( )展开的函数。系统调用的参数由寄存器传递，然后执行INT 0x80中断，以内核态进入入口地址system_call。  

####23.进程调度策略：

调度程序运行时，会从run_queue队列中选取最值得运行的进程投入运行，那选择进程的依据是什么呢？
就是每个进程的PCB中的task_struct中的四个参数：

 * __policy__：指的是调度策略，用来区分是实时进程还是普通进程
 * __priority__:指进程的静态优先级
 * __counter__:进程剩余的时间片，初始值是priority，可以看做是进程动态优先级
 * __rt_priority__:实时进程特有，用于实时进程间的选择

 > Linux用函数googness()来衡量一个处于可运行状态的进程值得运行的程度，该函数会综合以上4项条件，结合一些其他因素，最终得出一个weight权值， 调度程序以这个权值作为进程调度的唯一依据。
 
 Linux首先根据policy区分是实时进程还是普通进程，因为两种进程的调度是不同，实时进程优先于普通进程，同一种类型的不同进程，采用不同的标准：
 * __实时进程__：   
   采用FIFO或者RR（时间片轮转）算法，因为实时进程具有紧迫性，所以采用比较固定的策略，实时进程的counter只用于记录剩余时   间，不用于衡量进程是否值得运行，因此实时优先级rt_priority才是衡量实时进程的标准
 * __普通进程__：   
   采用动态优先调度，选择进程的依据是进程的counter，进程创建时，counter=priority，0~70之间的一个数，表示进程的时间片，
   priority表示分配给进程时间片，counter表示进程剩余的时间，进程运行过程中，counter不断减小，priority不变，
   以便在counter变为0时重新分配值，当一个进程的counter变为0时，不会马上赋值，只有所有的处于可运行状态的进程的counter都变为0时，
   才会用priority给counter重新赋值，这样普通进程才有了重新调度的机会，这说明，普通进程运行过程中，counter的减小给了其它进程
   得以运行的机会，直至counter减为0时才完全放弃对CPU的使用，这就相对于优先级在动态变化，所以称之为动态优先调度。

  