####10.1虚析构函数：
* 构造函数为什么不能定义为虚函数？
  虚函数的执行依赖于虚函数表，而虚函数表在构造函数中进行初始化工作，即初始化vptr,让他指向正确的虚函数表，而在构造对象期间，虚函数表还没有初始化，因此  无法进行。

* 析构函数定义为虚函数的原理(在存在继承并且子类有资源需要释放时，父类的析构函数需要定义为虚函数，否则会导致子类的资源不能释放，内存泄漏):  
 + 对于基类，如果有虚函数，那么闲存放虚函数表指针vptr，然后存放自己的数据成员，如果没有虚函数，那么直接存放数据成员  
 + 对于单一继承的类对象，先存放父类的数据拷贝(父类的虚函数指针vptr和数据成员)，然后子类自己的数据成员    
 + 在子类的虚函数表中，如果子类未重载父类的虚函数，那么先存放父类的虚函数，再存放子类的虚函数  
 + 在子类的虚函数表中，如果子类重载了付乐的某些虚函数，那么子类新的虚函数将覆盖自己虚函数表中的父类虚函数(父类的虚函数表不变化)  
 + 对于多重继承，在子类虚函数表中，先存放第一个父类的数据拷贝(包括vprt和数据成员)，然后是第二个父类的数据拷贝，以此类推，如果子类覆盖了某个父类的       虚函数，那么就将相应的父类的vptr指向的虚函数表中的父类的虚函数覆盖，如果子类有自己的虚函数，那么存放在第一个父类的虚函数之后    
   
**如果将基类的析构函数声明为虚函数时，由该基类所派生的所有派生类的析构函数也都自动成为虚函数，即使派生类的析构函数与基类的析构函数名字不相同** 

**如果基类没有定义虚析构函数，派生类的析构函数不能调用到的原因是：因为指针虽然指向的内存是派生类的，但是指针本身是基类，所以用delete时实际析构的是基类，所以调用了基类的析构函数而没有调用派生类的析构函数**   

**如果基类定义了析构函数，派生类的析构函数能调用到的原因是：当基类定义了虚析构函数，那么基类就会生成一个虚函数表指向基类的虚析构函数，当派生类继承了基类的时候，根据上面的定论，派生类的析构函数也会自动变成虚函数，所以派生类也会生成vptr和虚函数表，但是这里非常重要的点《派生类的虚析构函数会重载基类的虚析构函数，所以在派生类的虚函数表中派生类的虚函数会覆盖基类的虚函数》，因此在通过基类指针delete时，因为基类的析构函数已经被派生类的析构函数动态覆盖了，所以就调用到了派生类的析构函数，又因为编译器在构造类的时候，会将基类的析构函数添加在派生类的析构函数之后，所以通过调用派生类的析构函数就可以调用到基类的析构函数。--实际上跟普通的虚函数是一样的，不过有一点差异：《虽然基类和派生类的虚析构函数名字不一样，但是派生类的虚析构函数会覆盖基类的虚析构函数，就像普通虚函数一样，派生类的同名虚函数会覆盖基类的虚函数》**