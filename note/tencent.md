 [腾讯后台面试题](http://blog.csdn.net/ibmfahsion/article/details/11992403?utm_source=tuicool&utm_medium=referral)

 [后端开发面试题](https://github.com/monklof/Back-End-Developer-Interview-Questions)

 [BAT面试题](https://github.com/kaiye/kaiye.github.com/issues/3)
 

####1.linux的文件描述符fd和文件指针flip:
>
  fd是一个整数，在调用open()时返回，起到一个索引的作用，进程通过PCB中的文件描述符表找到该fd所指向的文件指针filp
  文件描述符fd是open()返回的值,内核会在每个进程空间中维护一个文件描述符表表中有fd和flip对应关系，所有打开的文件都将通过此表中的fd
  来引用flip找到对应的文件而流(如: fopen)返回的是一个FILE结构指针,FILE结构是包含有文件描述符fd的，FILE结构可以看作是对fd直接操作
  的系统调用的封装, 它的优点是带有I/O缓存每个进程在PCB（ProcessControlBlock）即进程控制块中都保存着一份文件描述符表，
  表中有fd和flip的关联关系，fd就是这个表的索引，文件描述表中每个表项都有一个指向已打开文件的指针flip,打开的文件在内核中以file_struct的
  结构体表示，flip就指向文件文件结构体。    
  [open()和fopen()的差别](http://blog.csdn.net/hairetz/article/details/4150193)

####2.共享内存:
>
  共享内存是最快的IPC(进程间通信)方式，它允许多个不相关的进程去访问同一片物理内存，共享内存是由IPC分配的一段地址空间，
  所有共享这段地址的进程都可以把这段地址加入到自己进程的地址空间段中，所有的进程就可以同时访问这块内存地址，
  如果一个进程对这段地址的数据了改动，那么其他进程来读取这段地址就可以看到数据的改变，因此共享内存对于共享数据的传输是非常高效的    
  共享内存原理：共享内存是最有用的进程间通信方式之一，也是最快的IPC形式。两个不同进程A、B共享内存的意思是，同一块物理内存被映射到进程A、B各自的进程地址空间中的不同的逻辑地址上。进程A可以即时看到进程B对共享内存中数据的更新，反之亦然。

####3.ELF：
>
__inux Excutable and Linktable Format,ELF标准作为工作在32位INTEL体系上不同操作系统之间可移植的二进制文件格式__
####5.makefile编写：
          makedir mf
          cd mf
          vim makefile.mk
          hello.o:hello.c hello.h
            gcc -c hello.o -Lm
          make  
          ./hello
          预处理-----> 编译 ----> 汇编 ----> 链接 
          #gcc -E hello.c -o hello.i
          #gcc –S hello.i –o hello.s 
          #gcc –c hello.s –o hello.o 
          #gcc hello.o –o hello.exe 
          #./hello.exe
  
####6.GDB:
>
 GNU debugger 安装GDB之后，在生成执行文件时加上-g   如：gcc -g -o hello hello.c
  list / info / break / file / continue / run / step / display / run / quit

####7.静态链接和动态链接：
>
  * 动态链接是指在生成可执行文件时不将所有程序用到的函数链接到一个文件，因为有许多函数在操作系统带的dll文件中，当程序运行时直接从操作系统中，而静态链接就是把所有用到的函数全部链接到exe文件中。
  * 动态链接是只建立一个引用的接口，而真正的代码和数据存放在另外的可执行模块中，在运行时再装入；而静态链接是把所有的代码和数据都复制到本模块中，运行时就不再需要库了

####12.VxWorks相关：
>
  VxWorks是单进程多线程的系统，多任务类似于多线程，一个进程用于申请内存空间和系统资源，任务之间实现内存和资源的共享
  * __二进制信号量__：最常用的，主要用于互斥和同步
  * __互斥信号量__：二进制的特殊情况，主要用于优先级继承、安全删除、递归等
  * __计数信号量__：主要用于保护一个资源的多个实例

  
