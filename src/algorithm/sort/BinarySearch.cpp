
int ReduceSearch(int* pArr, int firstIdx, int lastIdx, int num)
{
    if (firstIdx > lastIdx)
    {
        return -1;
    }
    
    int midIdx = firstIdx + (lastIdx - firstIdx) / 2;
    
    if (pArr[midIdx] == num)
    {
        return midIdx;
    }
    else if (pArr[midIdx] > num)
    {
        return ReduceSearch(pArr, firstIdx, midIdx - 1, num);
    }
    else
    {
        return ReduceSearch(pArr, midIdx + 1, lastIdx, num);
    }
}


int BinarySearch(int* pArr, int len , int num)
{
    if (pArr == NULL || len < 1)
    {
        return -1;
    }
    
    return ReduceSearch(pArr, 0, len - 1, num);
}

int main(int argc, const char * argv[])
{
    
    int arr[] = {1,2,3,4,5,6,7,8};
    
    int ret = BinarySearch(arr, 8, 8);
    
    cout << ret << endl;
    
    return 1;
}
