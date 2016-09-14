
#[C++空类中的默认函数](http://blog.csdn.net/peter_teng/article/details/12041591)
* 空的c++类编译之后会默认生成6个默认函数如下：
 + 默认构造函数
 + 默认析构函数
 + 默认赋值构造函数
 + 默认operator=操作
 + 默认取址运算符
 + 默认const取址运算符
 
* 例如:
定义一个空的C++类：

    class Empty
    {
    };

编译器编译之后就生成如下:

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

* 应用如下:

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



