
####24.Linux的5种I/O模式：
[Linux的I/O详解](https://segmentfault.com/a/1190000003063859)

  > 缓存I/O又称为标准I/O，Linux的缓存I/O机制中，操作系统会将I/O的数据缓存到文件系统的页缓存(page cache)中，也就是说，
   也就说数据会先被拷贝到操作系统的缓冲区中，然后才会从操作系统的缓冲区拷贝到应用程序进程的地址空间。
   优点：隔离应用程序与实际物理设备；减少读盘次数，提高性能
   缺点：在应用程序地址空间和操作系统页缓存中多次拷贝操作，对CPU和内存的开销非常大

* 当一个read操作发生时，它会经历两个阶段：
 * 1. __等待数据准备 (Waiting for the data to be ready)__
 * 2. __将数据从内核拷贝到进程中 (Copying the data from the kernel to the process)__

__5种I/O模式__：

* __阻塞式I/O__: 默认I/O模式，即open()和socket()创建的I/O都是阻塞I/O，进程处于阻塞模式时，让出CPU，进入休眠状态  

 > 当用户进程调用了recvfrom这个系统调用，kernel就开始了IO的第一个阶段：准备数据（对于网络IO来说，很多时候数据在一开始还没有到达。
  比如，还没有收到一个完整的UDP包。这个时候kernel就要等待足够的数据到来）。这个过程需要等待，也就是说数据被拷贝到操作系统内核的
  缓冲区中是 需要一个过程的。而在用户进程这边，整个进程会被阻塞（当然，是进程自己选择的阻塞）。当kernel一直等到数据准备好了，
  它就会将数据从kernel中拷贝到用户内存，然后kernel返回结果，用户进程才解除block的状态，重新运行起来。

 __所以，blocking IO的特点就是在IO执行的两个阶段都被block了。__
 
* __非阻塞式I/O__: 常用于管道，非阻塞会浪费大量的CPU  
 
 > 当用户进程发出read操作时，如果kernel中的数据还没有准备好，那么它并不会block用户进程，而是立刻返回一个EWOULDBLOC。
   从用户进程角度讲,它发起一个read操作后，并不需要等待，而是马上就得到了一个结果。用户进程判断结果是一个error时，
   它就知道数据还没有准备好，于是它可以再次发送read操作。一旦kernel中的数据准备好了，并且又再次收到了用户进程的
   system call，那么它马上就将数据拷贝到了用户内存，然后返回.

 当一个应用程序使用了非阻塞模式的套接字，它需要使用一个循环来不停的测试是否一个文件描述符有数据可读(称做 polling(轮询))。
 应用程序不停的 polling 内核来检查是否 I/O操作已经就绪。这将是一个极浪费 CPU资源的操作。这种模式使用中不是很普遍。
 
 __所以，nonblocking IO的特点是用户进程需要不断的主动询问kernel数据好了没有。__

* __I/O多路复用__:  

 > I/O多路复用实际就是常说的select()/poll()/epool(),或者称之为event driven I/O，好处就在于一个process可以同时处理多个网络连接的I/O，
  基本原理就是select()/poll()/epoll()会不断的轮训各自所负责的所有socket连接，当其中一个socket中有数据到达时，就通知用户进程处理。
  实际上当用户进程调用select()，那么整个进程就会被bolck,而同时，kernel会监视所有select负责的socket，当任何一个socket中有数据准备好了，
  就会返回oK给用户进程，这时候用户进程在调用read操作将数据从kernel中拷贝到用户进程
 
 在IO multiplexing Model中，实际中，对于每一个socket，一般都设置成为non-blocking，但是，整个用户的process其实是一直被block的。
 只不过process是被select这个函数block，而不是被socket IO给block

 __所以,I/O复用特点就是通过一种机制实现一个用户进程同时等待多个文件描述符(套接字描述符)，当其中一个文件描述符进入读就绪状态，select就返回ok__
 
* __信号I/O__：  

 > 用户进程发起read操作之后，立刻就可以开始去做其它的事。而另一方面，从kernel的角度，当它受到一个asynchronous read之后，
   首先它会立刻返回，所以不会对用户进程产生任何block。然后，kernel会等待数据准备完成，然后将数据拷贝到用户内存，当这一切都完成之后，
   kernel会给用户进程发送一个signal，告诉它read操作完成了。
   一个对信号驱动 I/O 比较实用的方面是NTP（网络时间协议 Network TimeProtocol）服务器，它使用 UDP.

* __异步I/O__:  

 > 当我们运行在异步 I/O 模式下时，我们如果想进行 I/O 操作，只需要告诉内核我们要进行 I/O 操作，然后内核会马上返回。
 具体的 I/O 和数据的拷贝全部由内核来完成，我们的程序可以继续向下执行。当内核完成所有的 I/O 操作和数据拷贝后，内核将通知我们的程序。
 
 * 异步 I/O 和  信号驱动I/O的区别是：
  * 1、信号驱动 I/O 模式下，内核在操作可以被操作的时候通知给我们的应用程序发送SIGIO 消息。
  * 2、异步 I/O 模式下，内核在所有的操作都已经被内核操作结束之后才会通知我们的应用程序。   
 
* * * 

* select()/poll()/epoll()差异：
 * __select__：  
  select 函数监视的文件描述符分3类，分别是writefds、readfds、和exceptfds。调用后select函数会阻塞，直到有描述副就绪
  （有数据 可读、可写、或者有except），或者超时（timeout指定等待时间，如果立即返回设为null即可），函数返回。当select函数返回后，
  可以 通过遍历fdset，来找到就绪的描述符。支持跨平台，缺点是对fd的数量有限制，默认1024

 * __poll__:  
  不同与select使用三个位图来表示三个fdset的方式，poll使用一个 pollfd的指针实现。pollfd结构包含了要监视的event和发生的event，
  不再使用select“参数-值”传递的方式。同时，pollfd并没有最大数量限制（但是数量过大后性能也是会下降）。和select函数一样，poll返回后，
  需要轮询pollfd来获取就绪的描述符。

 * __epoll__:  
  是前两种的加强版，epoll更灵活，没有文件描述符限制，epoll使用一个文件描述符管理多个描述符，将用户关系的文件描述符的事件存放到
    内核的一个事件表中，这样在用户空间和内核空间的copy只需一次。

     > int epoll_create(int size)；//创建一个epoll的句柄，size告诉内核这个监听的数目一共有多大，只是对内核初始分配内部数据结构的一个建议
     int epoll_ctl(int epfd, int op, int fd, struct epoll_event *event)；
     int epoll_wait(int epfd, struct epoll_event * events, int maxevents, int timeout);

* __epool优势__:  
 PPC(process per connection)/TPC(thread per connection):    
   
  > 这两种模型思想类似，就是让每一个到来的连接一边自己做事去，别再来烦我.只是 PPC 是为它开了一个进程，而 TPC 开了一个线程。
   可是别烦我是有代价的，它要时间和空间啊，连接多了之后那么多的进程 / 线程切换，这开销就上来了；
   因此这类模型能接受的最大连接数都不会高，一般在几百个左右

 select/poll:  
   
  > 最大并发数限制 默认1024.select 每次调用都会线性扫描全部的 FD 集合，这样效率就会呈现线性下降,采用内存拷贝传递内核数据
  epoll: 没有最大并发连接的限制,大的优点就在于它只管你“活跃”的连接，而跟连接总数无关，因此在实际的网络环境中，Epoll 的效率就会远远高于select 和 poll, 
   
 Epoll 在这点上使用了“共享内存”，这个内存拷贝也省略了。Epoll不仅会告诉应用程序有I/0事件到来，
 还会告诉应用程序相关的信息，这些信息是应用程序填充的，因此根据这些信息应用程序就能直接定位到事件，而不必遍历整个FD 集合。
   
####25.
