###1.swap的作用？
交换分区，物理内存不够使用时，将硬盘划分一部分出来模拟内存，将内存中暂时不使用的数据保存到swap空间中。

###2.怎么查看进程的内存占用情况？
ps aux 或者  top －H

###3.怎么查看进程的线程有多少个？
pstree -p

###4.多态的实现方式？
动态多太：继承实现
静态多太：模版 宏

###5.c++内存地址分配状况？
一个进程的虚拟内存占用4G，最高位的1G为内核空间，低位3G为用户空间，用户空间从高到低依次是堆／memory mapping／栈／BSS／数据段／代码段

###6.排序算法和二分查找？
冒泡，插入，选择，堆排，快排，归并。

###7.析构函数的作用？析构函数在什么状况下使用virtual？
析构函数重要作用是对类中分配的资源进行回收，在有继承并且之类中有资源需要释放时，父类析构函数必须申明为virtual

###8.深拷贝和浅拷贝的区别？
资源是否重新分配

###9.vector和map的底层实现机制？
连续空间内存，红黑树

###10.树的遍历方式？
前中后

###11.产品消息通信的机制？
单板之间socket通信

###12.进程间通信机制？
7种，管道，有名管道，共享内存，socket通信，信号，信号量，消息队列

###13.给一个数组，求出数组中出现次数大于n/2的数？
hash_map统计出现次数，或者flag标记出现次数
