##vector:
采用线性连续空间，两个迭代器start/finish分别指向配置得来的连续的空间中已经使用的范围，迭代器end_of_storage指向整块连续的空间尾部   

如果原空间满之后，则实现__重新配置、移动数据、释放原空间__。

所谓动态增加大小，并不是在原空间之后直接分配新空间(因为无法保证原空间之后可以申请到相应空间)，所以是以原大小两倍另外配置一个新的空间，
然后将原内容拷贝过来，然后在拷贝过来的原内容之后构造新元素，然后释放原空间。所以一旦重新分配新空间，迭代器就全部失效。
```c++
const size_type len = old_size != 0 ? 2 * old_size : 1;
```

##list:
list较于vector复杂的多，好处是每次插入或者删除一个元素，就的对应申请或者释放一个元素空间，因此list不会浪费空间。

```c++
template <class T>
struct __list_node{
    typedef void* void_pointer;
    void_pointer prev;
    void_pointer next;
    T data;
}
```
从上可以看出，list显然是个双向链表，而且还是环状双向链表，因此只需要在尾部添加一个空白节点，就可以用一个指针link_type node表示整个链表的所有节点。  


