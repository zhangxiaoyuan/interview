
#[C++空类中的默认函数](http://blog.csdn.net/peter_teng/article/details/12041591)
* 空的c++类编译之后会默认生成6个默认函数如下：
 + 默认无参构造函数
 + 默认析构函数
 + 默认拷贝构造函数
 + 默认operator=操作
 + 默认取址运算符
 + 默认const取址运算符
  
* 这些默认函数必须在第一次调用的时候才会被编译器创建，所以这些函数都是inline和public  
* 默认的析构函数都是非虚函数(因此继承时，父类的析构函数要尽量自己声明为虚函数)  
* 默认拷贝构造函数和默认operator=操作符只是单纯的将赋值对象的每一个非静态成员拷贝到待拷贝对象中(静态成员函数不做copy，
  静态成员在各个对象之间共享)  
* 算在一个“内含引用成员”或者“内含const成员”的类内支持赋值操作，就必须定义自己的默认拷贝赋值操作符。
  因为C++本身不允许引用改指不同的对象，也不允许更改const成员。  
* 为了驳回编译器自动提供的技能，可将相应的成员函数声明为private并且不予实现。使用像Uncopyable这样的基类也是一种做法。
 
例如:定义一个空的C++类：     

```c++
class Empty
{
};
```
编译器编译之后就生成如下:  

```c++
class Empty
{
    public:
    Empty(); // 缺省构造函数
    Empty( const Empty& ); // 拷贝构造函数
    ~Empty(); // 析构函数
    Empty& operator=( const Empty& ); // 赋值运算符
    Empty* operator&(); // 取址运算符
    const Empty* operator&() const; // 取址运算符 const
};
```
应用如下:    

```c++
class A
{
public:
    A(){++m_count;}
    ~A(){--m_count; printA();}
    static int m_count;
    void printA(){cout << "m_count " << m_count << endl;}
};

int A::m_count = 0;

A f1(A p_a)//3.a1赋值给形参p_a时调用了默认构造函数，默认构造函数没有m_count++;
{
    p_a.printA();//打印m_count=1;
	   return p_a; //返回时调用析构函数析构p_a，m_count-1,打印m_count=0；
}

int main()
{
    A a1; //1.生成一个类之后调用构造函数m_count+1;
    a1.printA();//2.打印m_count=1
    A a2=f1(a1);//生成类a2时，不是调用构造函数，而是调用了默认=赋值操作，所以没有m_count++
    a2.printA();//打印m_count=0;
    return 1;//返回之后，会析构a1和a2,所以打印m_count=-1,再打印m_count=-2
}
```

> 输出结果：  
 m_count 1  
 m_count 1  
 m_count 0  
 m_count 0  
 m_count -1  
 m_count -2  


###2.In C++, what does "explicit" mean? what does "protected" mean?    
* c++中的explicit关键字用来修饰类的构造函数，表明该构造函数是显式的，在某些情况下，我们要求类的使用者必须显示调用类的构造函数时就需要使用explicit,反之默认类型转换可能会造成无法预期的问题。   
* protected控制的是一个函数对一个类的成员（包括成员变量及成员方法）的访问权限。protected成员只有该类的成员函数及其派生类的成员函数可以访问    

###3.函数模板与类模板有什么区别？
答：函数模板的实例化是由编译程序在处理函数调用时自动完成的，而类模板的实例化必须由程序员在程序中显式地指定。

###4.使用线程是如何防止出现大的波峰。
答：意思是如何防止同时产生大量的线程，方法是使用线程池，线程池具有可以同时提高调度效率和限制资源使用的好处，线程池中的线程达到最大数时，其他线程就会排队等候。

###5.中断：
* 中断函数ISR不能有返回值
* 中断函数ISR不能有参数

###6.一个类有基类、内部有一个其他类的成员对象，构造函数的执行顺序是怎样的。
答：先执行基类的（如果基类当中有虚基类，要先执行虚基类的，其他基类则按照声明派生类时的顺序依次执行），再执行成员对象的，最后执行自己的。

###7.New delete 与malloc free 的区别
答案：用malloc 函数不能初始化对象，new 会调用对象的构造函数。Delete 会调用对象的destructor，而free 不会调用对象的destructor.

###8.有哪几种情况只能用intialization list 而不能用assignment? 
答案：当类中含有const、reference 成员变量；基类的构造函数需要参数；类中含有其他类的成员对象，而该类的构造函数需要参数。

###9.比较一下C++中static_cast 和 dynamic_cast 的区别。
dynamic_casts在帮助你浏览继承层次上是有限制的。它不能被用于缺乏虚函数的类型上，它被用于安全地沿着类的继承关系向下进行类型转换。如你想在没有继承关系的类型中进行转换，你可能想到static_cast.
