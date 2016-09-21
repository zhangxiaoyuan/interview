* 1.查看进程占用内存：动态 top / pmap -d <PID>   静态 ps -aux
* 2.查看进程的所有线程：pstree -p <PID> / ps -mp <PID / top -H 
* 3.结束后台进程: kill <PID>  终止前台进程 ctrl+c
* 4.启动进程有手动启动和调度启动,调度启动常用命令at / batch / crontab
* 5.swap作用：虚拟内存，当物理内存不够时，将硬盘一部分虚拟成内存使用
* 6.安装linux时，必须有两个分区是：文件系统分区和交换分区(swap)
* 7.内核分为文件管理系统、I/O管理系统、进程调度管理系统、内存管理系统4个子系统
* 8.进程与程序的区别在于其动态性,动态的产生和终止,从产生到终止进程可以具有的基本状态为： 运行态 、 就绪态 和 等待态（阻塞态）
* 9.DNS实际上是分布在internet上的主机信息的数据库,其作用是实现 IP地址和主机名 之间的转换.
* 10.在Linux系统中,用来存放系统所需要的配置文件和子目录的目录是 /etc 
* 11.Links分为 [硬链接和符号链接](http://www.cnblogs.com/itech/archive/2009/04/10/1433052.html) 
* 12.将前一个命令的标准输出作为后一个命令的标准输入,称之为 管道 
* 13.Sendmail邮件系统使用的两个主要协议是： SMTP 和 POP ,前者用来发送邮件,后者用来接收邮件.
* 14. rm命令可删除文件或目录,其主要差别就是是否使用递归开关 -r或-R 
* 15.shell不仅是 用户命令的解释器 ,它同时也是一种功能强大的编程语言. bash是Linux的缺省shell.
* 16.ipcrm:删除对应上面的信息
* 17.cat /proc/cpuinfo: 查询cpu所有信息
* 18.cat /proc/meminfo:查询内存所有信息
* 19.df -lh：查看硬盘信息
* 20.fdisk -l:查看硬盘信息
* 21.cat /proc/scsi/scsi：硬盘详细信息
* 22.dmesg:查看一些外设信息，比如网卡，蓝牙，cpu等
* 23.dmesg |grep eth：查看网卡信息
* 24.uname -a:查询机器的libux版本，机器名等详细信息

####2.常用命令：
* netstat: [显示网络状态](http://www.cnblogs.com/ggjucheng/archive/2012/01/08/2316661.html)
  * 两部分状态：

* * * 
    SZX1000123220:/usr/src # netstat
    Active Internet connections (w/o servers)  //有源TCP连接
    Proto Recv-Q Send-Q Local Address           Foreign Address         State      
    tcp        0      0 SZX1000123220:ssh       10.63.165.179:51154     ESTABLISHED 
    tcp        0      0 localhost:32000         localhost:31000         ESTABLISHED 
    tcp        0      0 localhost:32001         localhost:31001         ESTABLISHED 
    tcp       24      0 SZX1000123220:45099     10.82.138.216%3148:8089 CLOSE_WAIT  

    Active UNIX domain sockets (w/o servers)  //有源UNIX套接字，由于本机通信
    Proto RefCnt Flags       Type       State         I-Node Path
    unix  3      [ ]         STREAM     CONNECTED     10057  /tmp/diskmon.0.3521
    unix  3      [ ]         STREAM     CONNECTED     10072  /tmp/diskmon.0.3520
    unix  2      [ ]         DGRAM                    2945   @/org/kernel/udev/udevd
    unix  2      [ ]         DGRAM                    10033  /var/run/hook-localserver
    
>
 有源TCP连接的详解：
  proto:包括协议类型，TCP/UDP  
  Recv-Q和Send-Q：收发包队列  
  Local Address和Foreign Address：本地连接的ip和端口，对端连接ip和端口  
  state:表示连接状态，TCP的这种连接状态  
  
>
 有源UNIX套接字：
  proto:协议类型  
  RefCnt: 连接到本套接口上的进程号
  Type：套接口类型
  state: 连接状态
  Path： 表示连接到套接口的其它进程使用的路径名


* tcpdump:抓取本机所有网络接口的数据报文头，配置灵活，配置各种抓取规则

* * * 
    SZX1000123220:/usr/src # tcpdump
    tcpdump: verbose output suppressed, use -v or -vv for full protocol decode
    listening on eth0, link-type EN10MB (Ethernet), capture size 96 bytes
    09:39:01.680786 IP SZX1000123220.ssh > 10.63.165.179.51154: P 4084071868:4084072064(196) ack 1275033461 win 73
    09:39:01.681285 IP SZX1000123220.60322 > ns.huawei.com.domain: 61206+ PTR? 179.165.63.10.in-addr.arpa. (44)
    609 packets captured
    610 packets received by filter
    0 packets dropped by kernel

* ipcs:查看进程间通信设施状态

* * *
     SZX1000123220:/usr/src # ipcs
     ------ Shared Memory Segments --------  //共享内存
     key        shmid      owner      perms      bytes      nattch     status      
     0x00000000 32768      gdm        600        393216     2          dest         
     0x00000000 65537      gdm        600        196608     2          dest         
     ------ Semaphore Arrays --------  //信号量数组
     key        semid      owner      perms      nsems     
     ------ Message Queues --------   //消息队列
     key        msqid      owner      perms      used-bytes   messages   

