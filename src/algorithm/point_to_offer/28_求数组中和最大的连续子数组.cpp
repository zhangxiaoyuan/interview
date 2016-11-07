/*
给一个正负数都有的数组，一个或者连续多个数字组成一个子串，求出所有子串中和最大的那个子串

*/
int GetMaxSumSubArray(int* arr, int len, int* subArr, int& subLen)
{
    if (arr == NULL || len < 1 || subArr == NULL)
    {
        return -1;
    }
    
    int sum = 0;
    stack<int> subStack;
    int great = 0x80000000;
    for(int i = 0; i < len; i++)
    {
        if (sum <= 0)
        {
            sum = arr[i];
            while (!subStack.empty())
            {
                subStack.pop();
            }
            
            subStack.push(arr[i]);
        }
        else
        {
            subStack.push(arr[i]);
            sum += arr[i];
        }
        
        if (sum > great)
        {
            great = sum;
        }
        else//这里直接弹出还是有问题，如果字串中有负数也会弹出
        {
            subStack.pop();
        }
    }
 
    while (!subStack.empty())
    {
        subArr[subLen++] = subStack.top();
        subStack.pop();
    }
    
    return great;
}

int main(int argc, const char * argv[])
{
    int arr[] = {1,-2,3,10,-4,7,2,-5,-3,-1};
    int arr2[8] = {0};
    int len = 0;
    
    int num = GetMaxSumSubArray(arr, 10, arr2, len);
    
    cout << num << endl;
    cout << len << endl;
    cout << "====" << endl;
    for (int i =0; i < len; i++)
    {
        cout << arr2[i] << endl;
    }
}
