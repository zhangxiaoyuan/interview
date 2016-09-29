####4.Make sure that objects are initialized before they're used:  
C++对象的成员变量的初始化动作发生在进入构造函数本体之前，在构造函数内的是赋值而不是初始化，只有通过初始化列表赋值才是初始化。  
针对非内置类型，这样使用初始化效率更高，因为初始化列表是直接通过copy 构造函数构造，而赋值是先调用默认构造函数构造，然后再调用copy assign赋值操作符  

####5.Know what functions C++ silently writes and calls:
一个空的C++类经过编译器编译之后会默认生成4个函数：default默认构造函数、copy拷贝构造函数、析构函数、copy assignment操作符   
copy assignment赋值操作符在类中如果包含了引用或者const成员变量时(因为引用和const成员赋初值之后不能修改,所以编译器不知道如何处理)，
因此编译器就默认不生成copy assignment函数，需要手动自己指定  

####6.Explicitly disallow the use of compiler-generated functions you do not want:
为了防止编译器默认生成copy构造函数和copy assignment操作符，可将相应的构造函数声明为private并且不实现，或者使用Uncopyable这样的基类
```c++
class Uncopyable()
{
protected:
    Uncopyable(){}
    ~Uncopyable(){}
private:
    Uncopyable(const Uncopyable&);
    Uncopyalbe& operator=(const Uncopyable&);
}
```

####7.Declare destructors virtual in polymorphic base classes：
多态性质的基类应该声明一个virtual析构函数，如果一个类带有任何一个virtual虚函数，那么析构函数就应该声明为virtual  
如果类的设计不是用于多态或者继承使用，那么此类的析构函数九不应该设计为virtual，因为会无端增加内存开销(生成vprt增加内存开销)   

####8.Prevent exceptions from leaving destructor:
析构函数决绝不能吐出异常，如果一个被析构函数调用的函数可能抛出异常，那么析构函数就应该捕获此异常，然后处理异常   
如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数而非析构函数去处理该操作

####9.Nevel call virtual functions during construction and destruction:
在base class 的构造期间，virtual函数不是virtual函  
在构造和析构期间不要调用virtual函数，因为这类调用从不下降至派生类，

####10.Have assignment operators return a reference to *this:
使赋值函数返回(*this就是本对象)的引用，所有类似的赋值相关运算都可以遵守此约定：=/+=/-+/*=

```c++
Test& opeartor=()
{
    return *this;
}
```





