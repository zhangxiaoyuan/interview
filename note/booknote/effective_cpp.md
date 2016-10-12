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

####11.Handle assignment to self in operator=:
手动进行“证同测试”，确保不会删除对象本身自己  
采用copy-and-swap技术，保证异常安全性

####12.Copy all parts of an object:
copying函数要确保复制了“对象内的所有成员变量”，并且必须手工保证，因为编译器不会报错，包括copy构造函数和copy assignment操作符  
在有继承关系时，如果子类要写copying函数，那么必须保证所有父类的成分也得到copy  
```c++
class Derived :  class Base
{
public:
    Derived(const Derived& rhs) : Base(rhs), test(rhs.test){};
    Derived& operator=(const Derived& rhs)
    {
        Base::operator=(rhs);
        test = rhs.test;
        return *this;
    }
private:
    int test;
};
```
不要尝试以某个copying函数实现另一个copying函数，应该将共同的机制放进到第三个函数，并由两个copying函数共同调用  

##3、资源管理
####13.Use objects to manage resources:
以对象管理资源有两个想法：
 + 获得资源后立刻放进管理对象内
 + 管理对象运用析构函数确保资源被释放

两个常用的RAII classes分别是：std::auto_ptr和std::tr1::shared_ptr，通常使用侯后者，因为两者在copy行为上有所差异
因为auto_ptr的copy构造函数和copy assignment操作符会将赋值的对象置为NULL，而是被赋值对象指向赋值对象，但是shared_ptr就可以保证两个对象指向同一对象  
####14.Think carefully about copying behavior in resources-managing classes:
复制RAII(资源取得时机是初始化时机)对象必须一并复制它所管理的资源，所以资源的copying行为决定RAII对象的copying行为

设计一个资源管理器类：
```c++
class autoLock()
{
public:
    autoLock(Mutex* mutex) : mutexPtr(mutex)
    {
        Lock(mutexPtr);
    }
    
    ~autoLock()
    {
        unlock(mutexPtr);
    }
private:
    Mutex* mutexPtr; 
}
```
普通常见的RAII class copying行为：
 + RAII对象被复制是不合理的，__禁止复制__: 将copying操作声明为private，使用条款6中的Uncopyable()继承实现  
 + 对底层资源使用“引用计数法”：保证多个使用者持有同一个资源，类似tr1::shared_ptr。  

####15.Provide access to raw resouces in resouce-managing classes:
往往通过资源管理器访问时需要获取原始资源，所以每一个RAII class 都应该提供搞一个“取得其所管理资源”的办法   
对原始资源的访问可能经由显示转换或隐式转换，一般而言显示转换更安全，单隐式转换更方便  

####16.Using the same form in corresponding uses of new and delete:
new 和 delete 成对，new[] 和 delete[] 成对   

####17.Store newed objects in smart pointer in standalone statements:
以独立语句将newed对象存储于只能指针内，如果不这样，一旦异常被抛出，有可能导致未知错误






