###1.double或float转为int时，对齐小数位，例：
```c++
	double da = 2.6;
	float db = 3.4;
	int ia = (int)da;   //2
	int ib = (int)db;   //3
```
###2.文件操作函数：   
int fseek(FILE *stream, long offset, int fromwhere);   
 > 函数设置文件指针stream的位置，stream将指向以fromwhere为基准，偏移offset（指针偏移量）个字节的位置，函数返回0   
 
FILE * fopen(const char * path,const char * mode);    
 > 文件顺利打开后，指向该流的文件指针就会被返回   
 
long ftell(FILE *stream);   
 > 用于得到文件位置指针当前位置相对于文件首的偏移字节数。   
 
###3.strcpy(char* pDest, const char* pSrc)实现：
```c++
#include <assert.h>
char* strcpy(char* pDest, const char* pSrc)
{
    assert((pDest != NULL) && (pSrc != NULL));
    char* pAddr = pDest;
    while((*pDest++ = *pSrc++) != '\0')
    return pAddr;
}
```

###4.什么时间需要初始化列表，而不是构造函数中赋值：   
当类中含有const、reference 成员变量；基类的构造函数都需要初始化表。   

###5.New delete 与mallocfree 的联系与区别?    
都是在堆(heap)上进行动态的内存操作。用malloc函数需要指定内存分配的字节数并且不能初始化对象，new 会自动调用对象的构造函数。delete 会调用对象的destructor，而free 不会调用对象的destructor.    

###6.main 函数执行以前，还会执行什么代码？   
全局对象的构造函数会在main 函数之前执行，为malloc分配必要的资源，等等。   

###7.分别写出BOOL,int,float,指针类型的变量a 与“零”的比较语句。
```c++
BOOL : 　if ( !a ) or if(a)
int : 　　if ( a ==0)
float : const EXPRESSION EXP =0.000001;    if ( a < EXP&& a >-EXP)
pointer :　if ( a != NULL) or if(a == NULL)
```

###8.printf输出格式：   
[标志][输出最小宽度][.精度][长度]类型     
 > 前4项表示可选    
  
**标志**：标志字符为 -、+、# 和空格四种    

**最下宽度**：用十进制整数来表示输出的最少位数。若实际位数多于定义的宽度，则按实际位数输出，若实际位数少于定义的宽度则补以空格或0   

**精度**：精度格式符以“.”开头，后跟十进制整数。本项的意义是：如果输出数字，则表示小数的位数；如果输出的是字符，则表示输出字符的个数；若实际位数大于所定义的精度数，则截去超过的部分。 

**长度**：长度格式符为h、l两种，h表示按短整型量输出，l表示按长整型量输出。 

**类型**：d-10进制带符号整数，o-8进制无符号整数，x-16进制无符号整数，u-10进制无符号整数，f-小数单双精度，c-字符，s-字符串   

###9.结构体对齐原则：
+ 1.普通数据成员对齐规则：第一个数据成员放在offset为0的地方，以后每个数据成员存储的起始位置要从该成员大小的整数倍开始（比如int在32位机为４字节，则要从4的整数倍地址开始存储）。

+ 2.结构体成员对齐规则：如果一个结构里有某些结构体成员，则该结构体成员要从其内部最大元素大小的整数倍地址开始存储。（struct a里存有struct b，b里有char，int，double等元素，那b应该从8的整数倍开始存储。）

+ 3.结构体大小对齐规则：结构体大小也就是sizeof的结果，必须是其内部成员中最大的对齐参数的整数倍，不足的要补齐。

###10.#define 和 printf 都不是C语句
可以肯定的是#define和printf都是不是C语言的控制语句，C语言只有九种控制语句    
printf是一个C标准库函数，函数原型定义在stdio.h。从严格意义上来说，库函数不属于C语言。   
#define只是一个预处理命令，用来做替换，在编译的时候被展开罢了。    
