#泛型编程：
 泛型编程（Generic Programming）最初提出时的动机很简单直接：发明一种语言机制，能够帮助实现一个通用的标准容器库
 + 实现方式：
 除了单根继承之外，另一个实现通用容器的方案就是使用“参数化类型”。一个容器需要能够存放任何类型的对象，那干脆就把这个对象的类型“抽”出来，参数化它。

##泛型编程诞生：
泛型编程最初诞生于C++中，由Alexander Stepanov[2]和David Musser[3]创立。目的是为了实现C++的STL（标准模板库）。其语言支持机制就是模板（Templates）。模板的精神其实很简单：参数化类型。换句话说，把一个原本特定于某个类型的算法或类当中的类型信息抽掉，抽出来做成模板参数T。
 
###STL核心概念：
 + **1.迭代器**：迭代器建模的是内建指针的接口（解引用、递增、递减等）
 + **2.前闭后开区间**：一个简单的数学概念，表示从first（含first）到last（不含last）的区间内的所有元素。
 + __3.仿函数__：仿函数是建模的内建函数的接口，一个仿函数可以是一个内建的函数，也可以是一个重载了operator()的类对象，只要是支持函数调用的语法形式就可成为一  个仿函数。
 
###泛型和多态的差异：
 + **多态**：当具体的类型信息不可得，就必须诉诸运行期多态了   
 
  + 面向对象的多态引入了间接调用。当然，并不是说间接调用不好，有些时候，比如确实需要运行期多态的时候，只能诉诸继承这样的手段
  
  + 基于接口继承的面向对象多态则必须要显式地声明继承自一个接口，这就是所谓的名字一致性（Named Conformance）。
 
 + **泛型**： 当类型信息可得的时候，利用编译期多态能够获得最大的效率和灵活性    
 
  + 模板就是为了消除这样的抽象惩罚。利用模板编写的std::for_each，对于每一个特定的参数类型组合都有一个独立的，最高效的实例化版本，就跟你手写一个特定于这些类型的专门的for_each算法一样[5]。于是抽象惩罚消失了
  
  + 对于每一组参数类型组合实例化一个版本出来的做法增加了代码空间，这是一个典型的以空间换时间的例子，不过对于一门静态并追求效率的语言来说，这个代码空间的开销反正也是必不可少的，因为即便你手动为各种不同的参数类型组合编写特定的算法版本的话，也是付出一样的代码空间开销，而且还顺便违反了DRY原则[6]。此外，由于在抽象的时候不用总想着要建立的接口，所以泛型算法编写起来也更为直观。
  
  + 跟面向对象编程的基于继承和虚函数的运行时多态机制不同，C++模板是非侵入性的。你不需要让你的类继承自某个特定的接口才能用于某个算法，只要支持特定的语法接口就行了（比如只要支持begin()调用）。这也被称为结构一致性（Structural Conformance），意即只要语法结构一致即可。

