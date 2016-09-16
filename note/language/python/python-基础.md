#1.基础介绍：
* python是解释性语言，在运行之前不需要进行编译，可以直接运行
* python是强类型，动态类型语言，__不允许隐式类型转换__，**在声明变量时不需要指定变量类型**
* python没有访问权限说明符，例如c++的public／private等，支持继承的方式定义类，因此适合OOP
* 在Python语言中，函数是first-class objects。__这指的是它们可以被指定给变量，函数既能返回函数类型，也可以接受函数作为输入__
* python代码编写快，但是由于没有进行编译，因此导致运行速度比编译型语言慢
* GIL 全局锁：Cpython 实现中，为了保证多线程程序中的线程安全，加入了 GIL 锁，__因此Python并不能实现多线程并行计算__


* 1、_xxx     不能用于’from module import *’   以单下划线开头的表示的是protected类型的变量。即保护类型只能允许其本身与子类进行访问。 

* 2、__xxx    双下划线的表示的是私有类型的变量。只能是允许这个类本身进行访问了。连子类也不可以

* 3、__xxx___ 定义的是特列方法。像__init__之类的

* python保留字：
```python
and	 exec	not
assert	finally	or
break	for	pass
class	from	print
continue	global	raise
def	if	return
del	import	try
elif	in	while
else	is	with
except	lambda	yield
```

* 重要点：
IndentationError: unexpected indent    错误是python编译器是在告诉你"Hi，老兄，你的文件里格式不对了，可能是tab和空格没对齐的问题"，所有python对格式要求非常严格。
如果是 IndentationError: unindent does not match any outer indentation level错误表明，你使用的缩进方式不一致，有的是 tab 键缩进，有的是空格缩进，改为一致即可。  

因此，在Python的代码块中必须使用相同数目的行首缩进空格数。  
建议你在每个缩进层次使用 单个制表符 或 两个空格 或 四个空格 , 切记不能混用   


* Python支持四种不同的数字类型：
 + int（有符号整型）
 + long（长整型[也可以代表八进制和十六进制]）
 + float（浮点型）
 + complex（复数）

* python整形：
 长整型也可以使用小写"L"，但是还是建议您使用大写"L"，避免与数字"1"混淆。Python使用"L"来显示长整型

* python字符串：
 + python的字串列表有2种取值顺序:
 + 从左到右索引默认0开始的，最大范围是字符串长度少1
 + 从右到左索引默认-1开始的，最大范围是字符串开头
 + 如果你的实要取得一段子串的话，可以用到变量[头下标:尾下标]，就可以截取相应的字符串，其中下标是从0开始算起，可以是正数或负数，下标可以为空表示取到头或尾。
 + 字符串：加号（+）是字符串连接运算符，星号（*）是重复操作

* Python列表：
List（列表） 是 Python 中使用最频繁的数据类型。列表是有序的对象结合  
列表可以完成大多数集合类的数据结构实现。它支持字符，数字，字符串甚至可以包含列表（所谓嵌套）。

* Python元组：
元组是另一个数据类型，类似于List（列表）。元祖与类似，是有序的对象结合  
元组用"()"标识。内部元素用逗号隔开。但是元组不能二次赋值，相当于只读列表。  


* Python元字典：
字典(dictionary)是除列表以外python之中最灵活的内置数据结构类型。列表是有序的对象结合，字典是无序的对象集合。  
两者之间的区别在于：字典当中的元素是通过键来存取的，而不是通过偏移存取。  
字典用"{ }"标识。字典由索引(key)和它对应的值value组成。  

* 类型转换：
 + int(x [,base])  将x转换为一个整数
 + long(x [,base] )  将x转换为一个长整数
 + float(x)   将x转换到一个浮点数
 + complex(real [,imag])  创建一个复数
 + str(x)  将对象 x 转换为字符串
 + repr(x)   将对象 x 转换为表达式字符串
 + eval(str)  用来计算在字符串中的有效Python表达式,并返回一个对象
 + tuple(s)  将序列 s 转换为一个元组
 + list(s)   将序列 s 转换为一个列表
 + set(s)  转换为可变集合
 + dict(d)  创建一个字典。d 必须是一个序列 (key,value)元组。
 + frozenset(s)  转换为不可变集合
 + chr(x)  将一个整数转换为一个字符
 + unichr(x)  将一个整数转换为Unicode字符
 + ord(x)  将一个字符转换为它的整数值
 + hex(x)   将一个整数转换为一个十六进制字符串
 + oct(x)   将一个整数转换为一个八进制字符串

* 优先级：
![image]http://github.com/zhangxiaoyuan/pythonStudy/raw/master/images-folder/calcPri.png

* python命名方式：
```python
module_name, package_name, ClassName, 
method_name, ExceptionName, function_name, 
GLOBAL_VAR_NAME, instance_var_name, 
function_parameter_name, local_var_name.
```

* python中的特许循环语句：
for...else, while...else   
在 python 中，for … else 表示这样的意思，for 中的语句和普通的没有区别，else 中的语句会在循环正常执行完（即 for 不是通过 break 跳出而中断的）的情况下执行，while … else 也是一样


* 元组中的元素值是不允许删除的，但我们可以使用del语句来删除整个元组
* 元组中的元素值是不允许修改的，但我们可以对元组进行连接组合
* 任意无符号的对象，以逗号隔开，默认为元组

* 字典特性：
 + 不允许同一个键出现两次。创建时如果同一个键被赋值两次，后一个值会被记住（会直接用后面的值将前面的值覆盖）
 + 键必须不可变，所以可以用数字，字符串或元组充当，所以用列表就不行
