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
			if (pArray[j] > pArray[j+1])
			{
				swapNum(pArray[j+1], pArray[j]);
			}
			else
			{
				break;
			}
		}
	}
	
	return;
}



