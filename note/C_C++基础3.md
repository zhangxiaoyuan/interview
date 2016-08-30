####1.位操作：
[位操作主要用于操作寄存器之类的硬件强相关的或者数据变化使用](http://blog.csdn.net/morewindows/article/details/7354571)
>
* __& 按位与__: 两个位都为1时，结果才为1
* __| 按位或__: 两个位都为0时，结果才为0
* __^ 按位异或:__: 两个位相同为0，相异为1
* __~ 按位取反__: 0变1，1变0
* __<< 左移__: 各二进位全部左移若干位，高位丢弃，低位补0
* __>> 右移__:各二进位全部右移若干位，对无符号数，高位补0，有符号数，各编译器处理方法不一样，有的补符号位（算术右移），有的补0（逻辑右移）

####2.GCC编译四个过程：
* 1）预处理(Pre-processing)
 
>
  在该阶段，编译器将C源代码中的包含的头文件如stdio.h编译进来，用户可以使用gcc的选项”-E”进行查看。
  选项 -E
  用法:#gcc -E hello.c -o hello.i
  作用：将hello.c预处理输出hello.i文件。

* 2)编译阶段(Compiling)

>
  第二步进行的是编译阶段，在这个阶段中，Gcc首先要检查代码的规范性、是否有语法错误等，以确定代码的实际要做的工作，在检查无误后，
  Gcc把代码翻译成汇编语言。用户可以使用”-S”选项来进行查看，该选项只进行编译而不进行汇编，生成汇编代码。
  选项 -S
  用法：[root]# gcc –S hello.i –o hello.s
  作用：将预处理输出文件hello.i汇编成hello.s文件。

* 3)汇编阶段(Assembling)
 
>
  汇编阶段是把编译阶段生成的”.s”文件转成二进制目标代码. 
  选项 -c
  用法：[root]# gcc –c hello.s –o hello.o
  作用：将汇编输出文件test.s编译输出test.o文件。 

* 4）链接阶段(Link)
 
>
  在成功编译之后，就进入了链接阶段。
  无选项链接  
  用法：[root]# gcc hello.o –o hello.exe
  作用：将编译输出文件hello.o链接成最终可执行文件hello.exe。

####3.String类的实现：

     class String
     {
     public:
          String(const char *str = NULL);// 普通构造函数
          String(const String &other);    // 拷贝构造函数
          ~ String(void);    // 析构函数
          String & operate =(const String &other);// 赋值函数
     private:
          char *m_data;// 用于保存字符串
     }; 
     请编写String的上述4个函数。
     
     //普通构造函数
     String::String(const char *str)
     {
             if(str==NULL)
             {
                     m_data = new char[1]; // 得分点：对空字符串自动申请存放结束标志'\0'的//加分点：对m_data加NULL 判断
                     *m_data = '\0';
             }    
             else
             {
              int length = strlen(str);
              m_data = new char[length+1]; // 若能加 NULL 判断则更好
              strcpy(m_data, str);
             }
     } 
     
     // String的析构函数
     String::~String(void)
     {
             delete [] m_data; // 或delete m_data;
     }
     
     //拷贝构造函数
     String::String(const String &other) 　　　// 得分点：输入参数为const型
     {     
             int length = strlen(other.m_data);
             m_data = new char[length+1]; 　　　　//加分点：对m_data加NULL 判断
             strcpy(m_data, other.m_data);    
     } 
     
     //赋值函数
     String & String::operate =(const String &other) // 得分点：输入参数为const型
     {     
             if(this == &other)                  　　//得分点：检查自赋值
                     return *this; delete [] m_data; 　　　　//得分点：释放原有的内存资源
             int length = strlen( other.m_data );      
             m_data = new char[length+1]; 　//加分点：对m_data加NULL 判断
             strcpy( m_data, other.m_data );   
             return *this;     　　　　　　　　//得分点：返回本对象的引用  
     
     }
       
 >当类中包括指针类成员变量时，一定要重载其拷贝构造函数、赋值函数和析构函数，

