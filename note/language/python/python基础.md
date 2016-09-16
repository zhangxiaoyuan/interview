#1.基础介绍：
* python是解释性语言，在运行之前不需要进行编译，可以直接运行
* python是强类型，动态类型语言，__不允许隐式类型转换__，**在声明变量时不需要指定变量类型**
* python没有访问权限说明符，例如c++的public／private等，支持继承的方式定义类，因此适合OOP
* 在Python语言中，函数是first-class objects。__这指的是它们可以被指定给变量，函数既能返回函数类型，也可以接受函数作为输入__
* python代码编写快，但是由于没有进行编译，因此导致运行速度比编译型语言慢
* GIL 全局锁：Cpython 实现中，为了保证多线程程序中的线程安全，加入了 GIL 锁，__因此Python并不能实现多线程并行计算__

#2.函数：
##1.通过def关键字定义函数，def func():

```Python
def func_value(x):
    print "before x = ", x, " id = ", id(x)
    x = 2
    print "after x = ", x, "id = ", id(x)
```

例如：

```python
>>> def func_pass_value(x):
...     print "x = ", x, " id = ", id(x)
...     x = 2;
...     x = 2
...     print "after x = ", x, " id = ", id(x)
... 
>>> x=1
>>> func_pass_value(x)
x =  1  id =  140439260780728
after x =  2  id =  140439260780704
>>> x, id(x)
(1, 140439260780728)
>>> 
```

> 注意点：
 + 在函数体中定义的变量和函数外定义的变量重名时，两者没有关系，函数体内定义的，作用域在在定义到块结束之间    
   全局变量调用必须使用global arg
 

##2.通过lambda关键字定义`匿名函数`。所谓匿名，意即不再使用def语句这样标准的形式定义一个函数。
  这种语句在调用时绕过函数的栈分配，可以提高效率

```python
lambda arg1, arg2...: operator
```

例如：

```python
>>> a = lambda x, y: x + y
>>> a( 1, 3 )
4
>>> b = lambda x, y = 2: x + y
>>> b( 1 )
3
>>> b( 1, 3 )
4
>>> c = lambda *z: z
>>> c( 10, 'test')
(10, 'test')
```

##3.文档字符串：docString
相当于c++中的函数头，对函数进行解释，使用 `help(函数名)` 可以可以查看文档信息，按q退出

书写格式：函数def定义下第一行，缩进4空格，然后3个`'''` 或者 `"""`开始，第一个字母大写，一句话描述函数，然后 `.` 结束，
 第二行空行，第三行开始详细描述，以 `'''` 或者 `"""` 作为结束。

例如：
```python
>>> def func():
...     """From a complex number.
...  
...     keyword arg:
...     real--the real part
...     imag-- the imaginary par
...     """
...     print "what is this"
... 
>>> help(func)
```

##4.函数参数：
python中所有的参数传递都是按照类似于c++中引用传递的方式（因为python中一切都是对象，变量全部是对象的引用）。但是具体的对应不同类型的参数有区别（因为对象分为可变对象和不可变对象）。

* 可变对象：列表／字典。   
 函数体类的参数会一直持有该对象的引用，函数对该参数的修改也会影响到函数调用者的变量值，类似于C++函数中的引用传递。但在函数体内发生赋值操作时，也会生成一份新的拷贝作为函数的本地变量，函数对该本地变量的修改不会影响到函数调用者的变量值

```python
def func_pass_value(x):
    print "before: x=", x, " id=", id(x)
    x = 2
    print "after: x=", x, " id=", id(x)
>>> x = 1
>>> func_pass_value(x)
before: x= 1  id= 5363912
after: x= 2  id= 5363888
>>> x, id(x)
(1, 5363912)
```

* 不可变对象：整数／字符串／元祖。    函数体内的参数在被改变之前，会一直持有该对象的引用，但当参数发生改变时，由于该对象为不可变对象，必须生成一份新的拷贝作为函数的本地变量，函数对该本地变量的修改不会影响函数调用者的变量值，这一点有点类似 C++ 函数的值传递

```python
def func_pass_ref1(list):
    print list
    list = [4, 5]
    print list

def func_pass_ref2(list):
    print list
    list += [4, 5]
    print list
>>> al = [1, 2, 3]
>>> func_pass_ref1(al)
[1, 2, 3]
[4, 5]
>>> al
[1, 2, 3]
>>> func_pass_ref2(al)
[1, 2, 3]
[1, 2, 3, 4, 5]
>>> al
[1, 2, 3, 4, 5]
```

##5.函数参数类型：


