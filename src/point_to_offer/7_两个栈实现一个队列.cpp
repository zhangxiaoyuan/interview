
/*使用两个栈实现队列的先进先出特性*/
#include <stack>
template<typename T> class CQueue
{
public:
	CQueue(void){};
	~CQueue(void){};
	void appendTail(const T& node);
	T deleteHead();
private:
	stack<T> stack1;
	stack<T> stack2;
};

template<typename T> void CQueue<T>::appendTail(const T& node)
{
	stack1.push(node);

	return;
}

template<typename T> T CQueue<T>::deleteHead()
{
	if (stack2.empty())
	{
		while(stack1.size() > 0)
		{
			T t = stack1.top();
			stack2.push(t);
			stack1.pop();
		}
	}

	if (stack2.size() == 0)
	{
		cout << " no data" << endl;
	}

	T data = stack2.top();
	stack2.pop();

	return data;
}

void main()
{
	CQueue<int> queue;
	int a =1;
	int b =2;
	int c =3;
	queue.appendTail(a);
	queue.appendTail(b);
	queue.appendTail(c);

	int d = queue.deleteHead();
	cout << d << endl;
}
