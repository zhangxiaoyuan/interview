
/*输入两个整数序列，第一个表示栈的压入顺序，判断第二个是否是第一个的弹出顺序*/
/*思路：借助一个辅助的std：：stack，将压栈序列的数往栈中压入*/
bool IsPopStack(const int* pushStack, const int* popStack, int length)
{
    bool isPossible = false;
    
    if (pushStack != NULL && popStack != NULL && length > 0)
    {
        const int* pushNext = pushStack;
        const int* popNext = popStack;
        
        stack<int> dataStack;
        
        while (popNext - popStack < length)
        {
            while(dataStack.empty() || dataStack.top() != *popNext)
            {
                if (pushNext - pushStack == length)
                {
                    break;
                }
                dataStack.push(*pushNext);
                pushNext++;
            }
            
            if (dataStack.top() != *popNext)
            {
                break;
            }
            dataStack.pop();
            popNext++;
        }
        
        if (dataStack.empty() && popNext - popStack == length)
        {
            isPossible = true;
        }
    }
    
    return isPossible;
}

void main(int argc int argvp[])
{
    int push[] = {1,2,3,4,5};
    int pop[] = {4,5,3,1,2};

    bool re = IsPopStack(push, pop, 5);
    
    cout << re << endl;
}
