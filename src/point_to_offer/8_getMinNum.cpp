
/*
从一个已排序数组的旋转数组中找出最小值
两种方法，一种时采用递归的方式，一种时采用循环的方式
*/
int getNum(int* pstart, int* pend)
{
	int* ptemp = pstart;
	int len = pend - pstart + 1; 
	int midIdx = len / 2;

	if (ptemp == pend || (++ptemp == pend))
	{
		return *pend;
	}

	int midNum = pstart[midIdx];
	if (midNum >= *pstart)
	{
		pstart += midIdx; 
	}

	if (midNum <= *pend)
	{
		pend -= len - midIdx - 1;
	}

	return getNum(pstart, pend);
}

int getMin(int arr[], int len)
{
	if (arr == NULL || len < 1)
	{
		return -1;
	}

	return getNum(arr, arr + len -1);
}

int getMinNum(int arr[], int len)
{
	if (arr == NULL || len < 1)
	{
		return -1;
	}

	int startIdx = 0;
	int endIdx = len - 1;
	int midIdx = startIdx;
	while(arr[startIdx] >= arr[endIdx])
	{

	}

	return 1;
}

void main()
{
	/*
	CQueue<int> queue;
	int a =1;
	int b =2;
	int c =3;
	queue.appendTail(a);
	queue.appendTail(b);
	queue.appendTail(c);

	int d = queue.deleteHead();
	cout << d << endl;*/
	int arr[] = {1,2,3,4,5};

	int ret = getMin(arr, 5);
	cout << ret << endl;
}

#include <iostream>

using namespace std;

int getMinByOrder(int arr[], int start, int end)
{
	int result = arr[start];
	for (int i = start+1; i <= end; i++)
	{
		if (result >= arr[i])
		{
			return arr[i];
		}
	}
	return result;
}


int getMinNum(int arr[], int length)
{
    if (arr == NULL)
	{
		return -1;
	}
	if (length < 1)
	{
		return -1;
	}

    int startIdx = 0;
	int endIdx = length - 1;
	int midIdx = startIdx;//这里赋值为start，是因为有可能只有一个元素的时候
	while(arr[startIdx] >= arr[endIdx])
	{
		if (startIdx + 1 == endIdx)
		{
			midIdx = endIdx;
			break;
		}

		midIdx = (startIdx + endIdx) / 2;
		//三个指针指向位置的值相同的场景,如：1,0,1,1,1
		if (arr[startIdx] == arr[endIdx]
			&& arr[midIdx] == arr[endIdx])
		{
			return getMinByOrder(arr, startIdx, endIdx);
		}

		if (arr[midIdx] >= arr[startIdx])
		{
			startIdx = midIdx;
		}
		else if (arr[midIdx] <= arr[endIdx])
		{			
			endIdx = midIdx;
		}
	}
	
	return arr[midIdx];
}


int main()
{
//    cout << "hello linux ,hello vim" << endl;
	int arr[] = {1};
	cout << getMinNum(arr, 1) << endl;
	//int a = getMinByOrder(arr, 0, 4);
	
    return 0;
}






