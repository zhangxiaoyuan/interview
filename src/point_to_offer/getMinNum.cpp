
/*从一个已排序数组的旋转数组中找出最小值*/
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
