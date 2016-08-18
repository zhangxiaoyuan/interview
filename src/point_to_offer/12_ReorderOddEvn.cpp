/*给定一个int型数组，调整该数组中的数字顺序，使所有奇数位于所有偶数前面*/

/*
第一种解法，通过使用选择排序的方式，从第二个数开始遍历，遇到偶数就和第一个数交换，然后再从三个数开始遍历，遇到偶数就和第二个数交换，
一直到数组结束
*/
void ReorderOddEvn(int *pData, unsigned int length)
{
	if (NULL == pData || length < 1)
	{
		return;
	}

	for (int i = 0; i < length - 1; i ++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if ((pData[i] % 2 == 0) && (pData[j] % 2 != 0))
			{
				int temp = pData[j];
				pData[j] = pData[i];
				pData[i] = temp;
			}
		}
	}
}

/*第二种解法：用两个指针，指向头和尾，同时移动两个指针，头指针遇到偶数停下来，尾指针遇到奇数停下来，然后互相交换，然后继续移动两个指针*/
void ReorderOddEvn2(int* arr, unsigned int length)
{
	if (NULL == pData || length < 1)
	{
		return;
	}

	int* pHead = arr;
	int* pTail = arr + length - 1;

	while(pHead < pTail)
	{
		/*向后移动头指针，直到它指向偶数*/
		while(pHead < pTail && (*pHead & 0x01) != 0)
		{
			pHead++;
		}

		/*向前移动尾指针，直到它指向奇数*/
		while (pHead < pTail && (*pTail & 0x01) == 0)
		{
			pTail--;
		}

		if (pHead < pTail)
		{
			int temp = *pTail;
			*pTail = *pHead;
			*pHead = temp;
		}
	}
}


void ReorderOddEvn(int *pData, unsigned int length)
{
	if (NULL == pData || length < 1)
	{
		return;
	}

	for (int i = 0; i < length - 1; i ++)
	{
		for (int j = i + 1; j < length; j++)
		{
			if ((pData[i] % 2 == 0) && (pData[j] % 2 != 0))
			{
				int temp = pData[j];
				pData[j] = pData[i];
				pData[i] = temp;
			}
		}
	}
}

/*用函数指针实现判断和前后拆分解耦，可以提高判断条件的扩展性*/
void Reorder(int* arr, int length, bool (*pfun)(int))
{
	if (NULL == arr || length < 1)
	{
		return;
	}

	int* pHead = arr;
	int* pTail = arr + length - 1;

	while(pHead < pTail)
	{
		/*向后移动头指针，直到它指向偶数*/
		while(pHead < pTail && !pfun(*pHead))
		{
			pHead++;
		}

		/*向前移动尾指针，直到它指向奇数*/
		while (pHead < pTail && pfun(*pTail))
		{
			pTail--;
		}

		if (pHead < pTail)
		{
			int temp = *pTail;
			*pTail = *pHead;
			*pHead = temp;
		}
	}
}

bool isEven(int number)
{
	return (number & 0x01) == 0;
}

void ReorderOddEvn3(int* arr, unsigned int length)
{
	Reorder(arr, length, isEven);
}

void main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13};
	ReorderOddEvn2(arr,13);
	for (int i = 0; i <13; i++)
	{
		cout << arr[i] << endl;
	}
