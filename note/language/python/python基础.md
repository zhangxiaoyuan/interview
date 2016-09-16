#1.基础介绍：
* python是解释性语言，在运行之前不需要进行编译，可以直接运行
* python是强类型，动态类型语言，__不允许隐式类型转换__，**在声明变量时不需要指定变量类型**
* python没有访问权限说明符，例如c++的public／private等，支持继承的方式定义类，因此适合OOP
* 在Python语言中，函数是first-class objects。__这指的是它们可以被指定给变量，函数既能返回函数类型，也可以接受函数作为输入__
* python代码编写快，但是由于没有进行编译，因此导致运行速度比编译型语言慢
* GIL 全局锁：Cpython 实现中，为了保证多线程程序中的线程安全，加入了 GIL 锁，__因此Python并不能实现多线程并行计算__

#2.函数：
* 通过def关键字定义函数，def func():

```Python
def func_value(x):
    print "before x = ", x, " id = ", id(x)
    x = 2
    print "after x = ", x, "id = ", id(x)
```

* 通过lambda关键字定义`匿名函数`。所谓匿名，意即不再使用def语句这样标准的形式定义一个函数。
  这种语句在调用时绕过函数的栈分配，可以提高效率

```python
lambda arg1, arg2...: operator
```
