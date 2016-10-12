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
从上可以看出，__list显然是个双向链表，而且还是环状双向链表__，因此只需要在尾部添加一个空白节点，就可以用一个指针link_type node表示整个链表的所有节点。  

list不能使用std::sort函数，因为std::sort必须支持随机读取iterator属性，因此只能使用的自带list.sort()函数，__采用的是快排__。

vc++的中list::size是 {return (_Size));  } ，而gcc中的使用SGI STL的中list::size是{ return std::distance(begin(), end()); } ，[一个是O(1),一个是O(N)](http://stackoverflow.com/questions/228908/is-listsize-really-on)。

##deque：
deque没有容量的capacity的概念，因为它是动态的以分段连续空间组合而成，可以增加随时一段新的空间并连接起来，没有vector的重新分配的内存概念。  

采用一块所谓的map作为主控，是map一小块连续空间，其中每个节点的元素是指针指向另一段连续线性空间，称为缓冲区，缓冲区默认为512bytes。   

如果map满载，则重新分配一个map大小，然后将所有缓冲区头指针到copy新的map中。

deque的迭代器很复杂，一个迭代器有4个指针：
```c++
T* cur;   //指一个缓冲区中的当前指向的节点
T* first;  //指一个缓冲区的头节点
T* last;   //指一个缓冲区的尾节点
map_pointer node;  //指向map管控中心
```

deque中如果有元素，则采用两个迭代器start(ite)和finish(ite)。start(ite)的first指向第一个缓冲区的第一个元素，cur也指向第一个缓冲区的第一个元素，
last则指向第一个的缓冲区最后一个节点(是否不论为空)，node指向map中第一个缓冲区的位置；而finish(ite)中的first指向最后一个缓冲区的第一个元素，
last指向最后一个的缓冲区最后一个节点(是否不论为空)，cur指向最后一个缓冲区的中有元素的下一个空节点，node指向最后一个缓冲区在map中位置。

http://blog.csdn.net/v_july_v/article/details/7382693
