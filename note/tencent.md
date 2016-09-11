 [腾讯后台面试题](http://blog.csdn.net/ibmfahsion/article/details/11992403?utm_source=tuicool&utm_medium=referral)

 [后端开发面试题](https://github.com/monklof/Back-End-Developer-Interview-Questions)

 [BAT面试题](https://github.com/kaiye/kaiye.github.com/issues/3)
 


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

  
