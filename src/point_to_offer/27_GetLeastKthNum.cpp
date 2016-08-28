/*
输入一个n个数的数组，求出数组中最小的k个数
1.对数组整个排序，然后取出前k个数字即可
2.以k位置的数字为中位数，比k位置上大的数字放到右边，比k位置上小的数字放到左边，最后k位置之前的数字就是需要的最小的k个数字
3.使用set或者堆，从n个数字中取出k个数先放入到set或者堆中，然后排序这k个数字，找出最大值，然后从k+1开始和堆中的最大数比较，
  比他大的就比较下一个，比它小的就置换进set中
*/


int Partition( int* arr, int startIdx, int endIdx)
{
    int targetNum = arr[startIdx];
    
    while (startIdx < endIdx)
    {
        while ((startIdx < endIdx) && (targetNum <= arr[endIdx]))
        {
            endIdx--;
        }
        if (startIdx < endIdx)
        {
            arr[startIdx++]  = arr[endIdx];
        }
        
        while((startIdx < endIdx) && (targetNum >= arr[startIdx]))
        {
            startIdx++;
        }
        if (startIdx < endIdx)
        {
            arr[endIdx--] = arr[startIdx];
        }
    }
    
    arr[startIdx] = targetNum;
    
    return startIdx;
}

void GetLeastNum(int *input, int len, int* output, int k)
{
    if (len < 1 || k < 1
        || input == NULL || output == NULL)
    {
        return;
    }
    
    int startIdx = 0;
    int endIdx = len - 1;
    int index = Partition(input, startIdx, endIdx);
    
    while (index != k - 1)
    {
         if (index > k - 1)
        {
            index = Partition(input, startIdx, index - 1);
        }
        else
        {
            index = Partition(input, index + 1, endIdx);
        }
    }
    
    for (int i = 0; i < k; i++)
    {
        output[i] = input[i];
    }
    
    return;
}

int main(int argc, const char * argv[])
{
    int arr[]  = {4,3,7,6,3,2,1};
    int out[5] = {0};
    
    GetLeastNum(arr, 7, out, 5);
    
    for (int i =0; i < 5; i++)
    {
        cout << out[i] << endl;
    ｝
｝
