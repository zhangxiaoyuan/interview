/*实现一个栈的压入函数push，弹出函数pop，并实现一个函数min随时获取栈中的最小值，要求push，pop，min三个函数的时间复杂O(1)*/


#include <iostrem>
#include <stack>

using namespace std;

template<class T>
class MinStack
{
public:
    void push(const T& t);
    void pop();
    const T& min();
    
private:
    stack<T> m_data;
    stack<T> m_minData;
};

template<class T>
void MinStack<T>::push(const T& t)
{
    m_data.push(t);
    if (m_minData.size() == 0 || m_minData.top() > t)
    {
        m_minData.push(t);
    }
    else
    {
        m_minData.push(m_minData.top());
    }
}

template<class T>
void MinStack<T>::pop()
{
    if (m_data.size() > 0 && m_minData.size() > 0)
    {
        m_data.pop();
        m_minData.pop();
    }
}

template<class T>
const T& MinStack<T>::min()
{
    if (m_minData.size() > 0)
    {
        return m_minData.top();
    }
    
    cout << "error, no data in stack, return -1" << endl;
    return 0;
}

int main(int argc, const char * argv[])
{
    cout << "hello world, hello mac" << endl;
    
    MinStack<int> sta;
    sta.push(3);
    cout << sta.min() << endl;
    sta.push(4);
    cout << sta.min() << endl;
    sta.push(2);
    cout << sta.min() << endl;
    sta.push(1);
    cout << sta.min() << endl;
    sta.pop();
    cout << sta.min() << endl;
    sta.pop();
    cout << sta.min() << endl;
    sta.push(0);
    cout << sta.min() << endl;
    
}
