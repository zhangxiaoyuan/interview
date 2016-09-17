
#1.函数：
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
python函数传递参数类型比较多，按照是否确定参数数目可分为定长参数变长参数，按照是否引入关键字分为普通参数和关键字参，可以从以下五个方面进行介绍：

* 定长普通参数
* 定长关键字参数
* 变长普通参数
* 变长关键字参数
* 复合参数

`定长普通参数`为最常见的参数传递方式，参数传递时要求实参和虚参的个数相同，顺序也必须相同，否则会出现错误。**如果要设置默认参数，默认参数应该放在参数链表的尾部, 否则在函数调用时会给默认参数指定实参，从而使默认参数的设置失去意义**。定长普通参数对`参数位置`要求严格，为了摆脱位置对参数的束缚，python引入了关键字参数。

`定长关键字参数`进行参数传递时，必须设定指定参数的名字，函数调用时将以键值对的方式进行传递，若要给某个参数设定缺省值，在函数定义时直接指定缺省键值对即可，且不受位置的束缚，在函数调用时则不需要设定指定参数的键值对。

```python
    def fun2(Name='Tom', Age=20, Sex="Male"):
        print 'Name:', Name
        print 'Age:', Age
        print 'Sex:', Sex
    if __name__ == "__main__":
        fun2(Name="Alice", Sex="Female")
        fun2(Name="Bob", Age=22)
```

有些情况我们在定义一个函数时，并不能能够确定接受的参数的个数，只是知道需要对所接受的参数依次进行处理，这种情况下需要使用变长参数进行参数传递，python在定义变长参数时引入了`*`，定义变长普通参数时在参数名前面放在 *，如 `*args`，定义变长关键字参数时在参数前面放两个`*`号，如`**kargs`。

`变长普通参数`只需要在参数前面放一个*号即可，在函数体内部把形参当作一个元组来处理。在函数调用时可以把一个元组当作参数，不过需要对元组进行unpack，即在相应参数前面加 * 即可。

```python
    def foo(*args):
        for arg in args:
            print arg
        
    if __name__ == "__main__":
        foo(1, 2, 3, "good")
        arglist = 1, 2, 3, "good"
        foo(*arglist)
```

注意在**函数定义时变长参数（包括后面介绍的变长关键字参数）必须设置在定长参数后面**。

变长关键字长参数类似于变长普通参数，只是变长关键字参数在函数定义时在参数前面加 `**` 号，在函数体内部把参数当作一个参数字典来处理。`在函数调用时可以把一个字典当作参数，不过需要对字典进行unpack，即在字典参数前面加 ** `。

```python
    def foo(**kwargs):
        for k, v in kwargs.items():
            print k, v
    if __name__ == "__main__":
        foo(Name="Jim", Age=22, Sex="Male")
        argDict = {"Name": "Jim", "Age": 22, "Sex": "Male"}
        foo(**argDict)
```

对于变长关键字参数，我们可以任意指定关键字的名字，函数调用的内部会去获取关键字的名字和值。

在实际编程的过程当中，我们可能面临这样一种情况，函数定义时不能够确定会接受到什么样参数，包括参数的数目，参数的类型等，这个时候，我们就会用到这里介绍的复合参数，复合参数及前面介绍的四种参数的混搭形式。

```python
    def foo(firstname, lastname="John", *args, **kwargs):
        print firstname
        print "LastName: ", lastname
        for arg in args:
            print arg
        for k, v in kwargs.items():
            print k, v
    
    if __name__ == "__main__":
        arglist = 1, 2, 3, "good"
        argDict = {"Name": "Jim", "Sex": "Male"}
        foo("Jim", "Jack", *arglist, **argDict)
```

只是在函数定义时对参数的顺序特定的要求：

* 关键字参数必须在普通参数后面
* 变长普通参数必须放在定长参数的后面
* 变长关键字参数必须放在变长普通参数的后面

函数调用时赋值的过程为：

1. 依次为普通参数赋值  
2. 为关键字参数赋值  
3. 将多余出的零散实参打包成一个元组传递给赋给变长普通参数 *args 
4. 将多余的键值对形式的实参打包成一个字典传递给变长关键字参数 **kargs

此外，我们还可以从一个函数传递变长普通参数和变长关键字参数到另一个函数中去，如下：

```python
def f(x, *args, **kwargs):
    ...
    kwargs['width'] = '14.3c'
    ...
    g(x, *args, **kwargs)
``` 

##6.函数闭包：
在计算机科学中，闭包（Closure）是词法闭包（Lexical Closure）的简称，是指引用了自由变量的函数。这个被引用的自由变量将和这个函数一同存在，即使已经离开了创造它的环境也不例外。所以，有另一种说法认为闭包是由函数和与其相关的引用环境组合而成的实体。

Python中如果调用函数A，它返回函数B。这个返回的函数B就叫做闭包，在调用函数A的时候传递的参数就是自由变量

例子：
```python
def func(name):
    def inner_func(age):
        print 'name:', name, 'age:', age
    return inner_func

bb = func('the5fire')
bb(26)  # name: the5fire age: 26
```

这里面调用func的时候就产生了一个闭包——inner_func,并且该闭包持有自由变量——name，因此这也意味着，当函数func的生命周期结束之后，name这个变量依然存在，因为它被闭包引用了，所以不会被回收。（闭包并不是Python中特有的概念，所有把函数作为一等公民的语言均有闭包的概念。)

##7.partial函数封装：
如果需要减少某个函数的参数个数，可以使用 functools.partial() 。 partial() 函数允许给一个或多个参数设置固定的值，减少接下来被调用时的参数个数。假设有下面的函数：

```python
def spam(a, b, c, d):
    print(a, b, c, d)
```

现在使用 partial() 函数来固定某些参数值：

```python
>>> from functools import partial
>>> s1 = partial(spam, 1) # a = 1
>>> s1(2, 3, 4)
1 2 3 4
>>> s2 = partial(spam, d=42) # d = 42
>>> s2(1, 2, 3)
1 2 3 42
>>> s3 = partial(spam, 1, 2, d=42) # a = 1, b = 2, d = 42
>>> s3(3)
1 2 3 42
```

可以看出，partial() 固定某些参数并返回一个新的callable对象。这个新的callable接受未赋值的参数，然后跟之前已经赋值过的参数合并起来，最后将所有参数传递给原始函数。
