#深度探索C++对象模型
##1.关于对象：

###1.加上封装后的布局成本：
data member直接包含在每一个object对象中，跟C struct情况一样  
member function虽然在zclass中声明，但是却不会出现在每一个object中，只有一个函数体  
inline function则会在其每一个使用者身上产生一个函数实体   

C++布局以及存取时间主要的额外负担是由virtual引起：
> 
 virtual function：用以支持一个有效率的“执行期绑定”（runtime binding）   
 virtual base class：用以实现“多次出现在继承体系中的base class，有一个单一而被共享的实体”
 
###2.c++对象模型：

 + 简单对象模型：
  一个object是一系列slot(实际就是指针)组成，每一个slot指向一个member(不论是member function还是data member，不管是virtual还是no-virtual，不管是static还是non-static).避免“不同member不同类型导致的不同的存储空间”问题。大小很容易计算，指针大小乘以slot个数。
  
 + 表格驱动对象模型：
  将member相关信息抽象出来，放在一个data member table和一个member funcion table，而一个class object本身则包含指向这两个表格的指针，member function table是一系列的slot(实际就是指针)，每一个slot指向一个member function；data member table直接包含data member数据本身。
 
 + 真实c++对象模型：
  由简单对象模型派生而来，对内存空间和存取时间进行了优化。将non-static data member存放于每一个class object中，static data member存放于class object之外，static & non-static member function也存放在所有class objects之外，virtual funcion以vptr和vtbl存放。Vptr的设置和重置都由每一个class的construct、destructor、copy assignment运算符自动完成。
  > 
   虚继承中，base class 不管在继承串链中被派生多少次，永远只会存在一个实体供所有子类共享。     
   class istream : virtual public ios{...};


