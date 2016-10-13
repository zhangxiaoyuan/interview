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

map管理节点最少8个，是最多所需节点+2，前后各预留一个，扩充时可用。

pop_back()和pop_front()，将收尾元素拿掉，无论从前还是从后，都需要考虑在某些情况下，将缓冲区释放


##stack:
stack是以deque为原型，将其接口改变，使其符合"先进后出"规律。

由于stack是以底部容器完成其所有工作，具有这种“修改某物接口，形成另一种风貌”的性质，称为adapter适配器,而不能称之为container容器。

stack的push()和pop()采用的是deque的push_back()和pop_back();
```c++
void push(const value_type& x){c.push_back(x);}
void pop(){c.pop_back();}
```
stack不提供走访，功能不提供迭代器，list也可封装为stack，不过STL采用中deque作为stack的数据底层。

##queue:
queue是先进先出的数据结构，不允许遍历。默认以deque为底层容器，也是适配器adapter，不是容器container。也没有迭代器

##priority queue:
优先级队列，允许用户已任何次序将任何元素推入容器中，但是取出时是一定从优先级最高的元素开始取。 底层采用bianry max heap。

##heap:
使用可以array表示tree的方法，叫做隐式表述法，以vector代替array实现数组的自增长。STL使用的max-heap大顶堆。
heap不提供遍历操作，因此没有迭代器，遵循完全二叉树的排列规则。

push_heap()算法实现:
 + 插入新元素时，总是插入到vector的最后end()处位置，然后一级一级调整每一个子树，直到满足二叉堆规律即可。

pop_heap()算法实现：
 + pop_heap()实际是将根元素(最大值)到防止底部容器vector的尾端节点，并没有被移走，只是了调换位置。如果要真实的移走，则可以使用底部容器vector的所的提供pop_back()操作函数。
 
sort_heap()算法实现： 
 + 从pop_heap()实际就可以看出来，每次pop_heap操作都将最大值放到底部容器vector的最尾端，因此只需要循环对整个heap做pop_heap操作就可以看得到一个递增序列。
 
make_heap()算法实现：
 + 这个算法用来将一个现有的vector转化为一个heap.
 ```c++
 #include <algorithm> //堆算法所在头文件
 
 int ia[9] = {0,1,2,3,4,8,9,3,5};
 vector<int> ivec(ia, ia + 9);
 
 make_heap(ivec.begin(), ivec.end());
 print(ivec); //9 5 8 3 4 0 2 3 1
 
 ivec.push_back(7);
 push_heap(ivec.begin(), ivec.end());
 print(ivec); //9 7 8 3 5 0 2 3 1 4
 
 pop_heap(ivec.begin(), ivec.end());
 cout << ivec.back() << endl; //9. 此时9并没有从vector中移除，只是放到了数组的最末尾
 print(ivec); //8 7 4 3 5 0 2 3 1 9
 ivec.pop_back(); //此时就真正的移除了9
 print(ivec);  //8 7 4 3 5 0 2 3 1
 
 sort_heap(ivec.begin(), ivec.end());
 print(ivec);  //0 1 2 3 4 5 7 8
 
  
 ```
