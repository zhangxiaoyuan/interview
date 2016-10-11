#include "sortMethod.h"


/*
插入排序:插入一个有序数组中，从后向前比较，如果满足就交换，不满足放在最后
*/
void insertSort(int* pArray, int arrLen)
{
	for (int i = 1; i < arrLen; i++)
	{
		for (int j = i - 1; j >= 0; j--)
		{
			if (pArray[j] > pArray[j + 1])
			{
				swapNum(pArray[j + 1], pArray[j]);
			}
			else
			{
				break;
			}
		}
	}
	
	return;
}

/*改进版:减少交换次数*/
void insertSort1(int* pArray, int arrLen)
{
	int temp;
	int pos;
	for (int i = 1; i < arrLen; i++)
	{
		temp = pArray[i];
		pos = i - 1;
		while(pos >= 0 && temp < pArray[pos])
		{
			pArray[pos+1] = pArray[pos];
			pos--;
		}
		pArray[pos+1]= temp;
	}

}
}



