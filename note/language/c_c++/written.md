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
define只是一个预处理命令，用来做替换，在编译的时候被展开罢了。      

###11.字符串与字符指针：
```c++
char str1[] = "abc";
char str2[] = "abc";
const char str3[] = "abc";
const char str4[] = "abc";
const char *str5 = "abc";
const char *str6 = "abc";
char *str7 = "abc";
char *str8 = "abc";
cout << ( str1 == str2 ) << endl;  //0
cout << ( str3 == str4 ) << endl;  //0
cout << ( str5 == str6 ) << endl;  //1
cout << ( str7 == str8 ) << endl;  //1
```
str1,str2,str3,str4是数组变量，它们有各自的内存空间；而str5,str6,str7,str8是指针，它们指向相同的常量区域。

###12.数组操作：
```c++
main()
{ int a[5]={1,2,3,4,5};
  int *ptr=(int *)(&a+1);
  printf("%d,%d",*(a+1),*(ptr-1));//2,5
}
```   
*(a+1）就是a[1]，*(ptr-1)就是a[4],执行结果是2，5；    
&a+1不是首地址+1，系统会认为加一个a数组的偏移，是偏移了一个数组的大小（本例是5个int）int *ptr=(int *)(&a+1); 则ptr实际是&(a[5]),也就是a+5      

原因如下：      
&a是数组指针，其类型为 int (*)[5];而指针加1要根据指针类型加上一定的值，不同类型的指针+1之后增加的大小不同a是长度为5的int数组指针，所以要加 5*sizeof(int)所以ptr实际是a[5]，但是prt与(&a+1)类型是不一样的(这点很重要)，所以prt-1只会减去sizeof(int*)；    

a,&a的地址是一样的，但意思不一样，a是数组首地址，也就是a[0]的地址，&a是对象（数组）首地址，a+1是数组下一元素的地址，即a[1],&a+1是下一个对象的地址，即a[5].  

###13.指针偏移计算：
 偏移指针所指类型的个数即可。
```c++
typedef struct AAA
{
    int a;
    char b[5];
    short c;
    int d;
};
AAA* p = 0x10000000;

p + 10 = 0x1000000a0  //偏移10个AAA结构体大小
(char*)p + 10 = 0x1000000a   //偏移10个char大小
(int*)p + 10 = 0x10000028    //偏移10个int大小
```

###14.指针内存申请释放：
```c++
void GetMemory(char **p,int num)
{
	*p=(char *)malloc(num);
} 

int main()
{
	char *str=NULL;
	GetMemory(&str,100);
	strcpy(str,"hello");
	free(str);
	if(str!=NULL)
	{
		strcpy(str,"world");
	} 
	printf("/n str is %s",str);   //str is world
	getchar();
} 
```
输出str is world。   
free 只是释放的str指向的内存空间,它本身的值还是存在的. 所以free之后，有一个好的习惯就是将str=NULL.    

此时str指向空间的内存已被回收,**如果输出语句之前还存在对分配空间操作的话,这段存储空间是可能被重新分配给其他变量**，   
尽管这段程序确实是存在大大的问题（上面各位已经说得很清楚了），但是通常会打印出world来。   

这是因为，进程中的内存管理一般不是由操作系统完成的，而是由库函数自己完成的。当你malloc一块内存的时候，管理库向操作系统申请一块空间（可能会比你申请的大一些），然后在这块空间中记录一些管理信息（一般是在你申请的内存前面一点），并将可用内存的地址返回。**但是释放内存的时候，管理库通常都不会将内存还给操作系统，因此你是可以继续访问这块地址的**。但是不建议这样操作。

###15.sizeof对普通结构体和位域结构体的计算：
```c++
struct s1
{  
int i: 8;
int j: 4;
int a: 3;
double b;
};

struct s2
{
int i: 8;
int j: 4;
double b;
int a:3;
};

printf("sizeof(s1)= %d/n", sizeof(s1)); //16
printf("sizeof(s2)= %d/n", sizeof(s2)); //24
```
第一个理论上是这样的，首先是i在相对0的位置，占8位一个字节，然后j就在相对一个字节的位置，由于一个位置的字节数是4位的倍数，因此不用对齐，就放在那里了，然后是a，要在3位的倍数关系的位置上，因此要移3位，在15位的位置上放下，目前总共是18位，折算过来是2字节2位的样子，由于double是8字节的，因此要在相对0要是8个字节的位置上放下，因此从18位开始到8个字节之间的位置被忽略，直接放在8字节的位置了，因此，总共是16字节。

第二个最后会对照是不是结构体内最大数据的倍数，不是的话，会补成是最大数据的倍数

###16.编译器位扩展计算问题：
```c++
ypedef struct 
{ 
    int a:2;
    int b:2;
    int c:1;
}test;

test t;
t.a = 1;
t.b = 3;
t.c = 1;

printf("%d",t.a);   //t.a为01,输出就是1
printf("%d",t.b);   //t.b为11，输出就是－1
printf("%d",t.c);   //t.c为1，输出也是-1
```
3个都是有符号数int嘛。编译器进行符号扩展

###17.c语言中string常用函数使用原理：
strlen(str1)：while循环直到遇到'\0'结束，统计个数.        
strcpy(dest, src)：while循环src直到遇到'\0'结束copy，如果str2没有结束符，则会出现copy异常。  
strcmp(dest, src)：while循环判断两个串中的每个字符是否相等。

###18.[数组名与指针的关联和区别](http://wenku.baidu.com/view/efd95e73a417866fb84a8eff.html)：
* 1.数组名的内涵在于其指代实体是一种数据结构，这种数据结构就是数组；     
```c++
    int intArray[10];
    cout << sizeof(intArray) ;  //40
```

* 2.数组名的外延在于其可以转换为指向其指代实体的指针，而且是一个指针常量；    
```c++
    int intArray[10];
    intArray++;  //编译错误，虽然数组名可以转换为指向其指代实体的指针，但是它只能被看作一个指针常量，不能被修改。 
```
 
* 3.指向数组的指针则是另外一种变量类型（指针类型，长度为4），仅仅意味着数组的存放地址！  

* 4.数组名作为函数形参时，在函数体内，其失去了本身的内涵，仅仅只是一个指针；在失去其内涵的同时，它还失去了其常量特性，可以作自增、自减等操作，可以被修改。所以，数组名作为函数形参时，其全面沦落为一个普通指针！它的贵族身份被剥夺，成了一个地地道道的只拥有4个字节的平民。

###19.C语言本身没有输入输出语句，即C语言本身没有保留字用于输入输出功能。都是采用的标准库函数实现输入输出操作。

###20.[C语言关键字总计32个](http://c.biancheng.net/cpp/html/797.html)

###21.C语言运算符优先级：赋值运算符< 逻辑与运算符< 关系运算符< 算术运算符



###[11.c++笔试题集合](http://blog.csdn.net/hackbuteer1/article/details/7926592)
###[12.c++面试笔试题目集合](http://blog.csdn.net/hanlin1985/article/details/2990895/)
