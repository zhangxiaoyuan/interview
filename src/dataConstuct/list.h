#ifndef __LIST_H__
#define __LIST_H__


using namespace std;

/*数据结构---表的各种实现*/


/*1.线性表的顺序实现--线性表*/
template<class T> 
class LineTable
{
public:
	LineTable(){maxLen = 10; pLine = NULL;}
	~LineTable(){if (pLine != NULL) delete[] pLine;} //需要将申请的内存释放
	int length() const;
	int search(const T& t) const;
	LineTable<T>& deleteNode(int k, T& t);
	LineTable<T>& insertNode(int k ,const T& t);
private:
	int maxLen;
	T* pLine;
};


/*2.线性表的链式实现--单向链表*/
template<class T>
class Node
{
private:
	T data;
	Node<T>* pNext;
};

template<class T>
class ListChain
{
public:
	ListChain(){pFirst = NULL;}
	~ListChain();
	int length() const;
	int search(const T& t) const;
	ListChain<T>& deleteNode(int k, T& t);
	ListChain<T>& insertNode(int k ,const T& t);

private:
	Node<T>* pFirst;
};

/*3.双向链表*/
template<class T1>
class ListNode
{
private:
	T1 data;
	ListNode<T1>* pNext;
	ListNode<T1>* pFront;
};

template<class T1> 
class DoubleListChain
{
public:
	DoubleListChain(){pLeftEnd = pRightEnd = NULL;}
	~DoubleListChain();
	int length() const;
	int search(const T1& t) const;
	DoubleListChain<T1>& deleteNode(int k, T1& t);
	DoubleListChain<T1>& insertNode(int k, T1& t);

private:
	Node<T1>* pLeftEnd;
	Node<T1>* pRightEnd;
};

/*4.单向循环链表*/

/*5.双向循环链表*/

/*6.队列的顺序实现*/
template<class T2>
class Queue
{
public:
	Queue(){rear = front = 0; maxSize = 10; pQueue = NULL;}
	~Queue(){if (pQueue != NULL) delete[] pQueue;}//需要将申请的内存释放
	bool isEmpty() const{return (rear == 0);}
	bool isFull() const{return (rear == (maxSize - 1));}
	T2 getFirst() const;
	T2 getLast() const;
	Queue<T2>& insertNode(const T2& t);
	Queue<T2>& deleteNode(T2& t);
private: 
	int rear;
	int front;
	int maxSize;
	T2* pQueue;
};


/*7.队列的链表实现*/
template<class T3> 
class QueueNode
{
private:
	T3 data;
	QueueNode* pNext;
};

template<class T3>
class ListQueue
{
public:
	ListQueue(){}
	~ListQueue(){} //需要将申请的内存释放
	bool isEmpty() const{return pFirst == NULL;}
	//bool isFull() const;
	T3 getFirst() const;
	T3 getLast() const;
	ListQueue<T3>& insert(const T3& t);
	ListQueue<T3>& deleteNode(T3& t);
private:
	QueueNode<T3>* pFirst;
	QueueNode<T3>* pLast;
};

/*8.栈的顺序实现*/
template<class T4>
class Stack
{
public:
	Stack(){maxSize = 10; topSize = -1; pStack = NULL;}
	~Stack(){if (pStack != NULL) delete[] pStack;}
	bool isEmpty(){return topSize == -1;}
	bool isFull(){return (topSize == maxSize - 1);}
	T4& top() const;
	Stack<T4>& push(const T4& t);
	Stack<T4>& pop(T4& t);

private:
	int maxSize;
	int topSize;
	T4* pStack;
};


/*9.栈的链表实现*/
template<class T5> 
class StatckNode
{
private:
	T5 data;
	StatckNode* pNext;
};

template<class T5>
class ListStack
{
public:
	ListStack(){pStack = NULL;}
	~ListStack(){} //需要将申请的内存释放
	bool isEmpty() const{return pStack == NULL;}
	ListStack<T5>& push(const T5& t);
	ListStack<T5>& popNode(T5& t);
private:
	StatckNode<T5>* pStack;
};



#ifdef __cplusplus
extern"C"
{

}
#endif

#endif
