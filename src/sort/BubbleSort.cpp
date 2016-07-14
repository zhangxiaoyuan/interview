#include "sortMethod.h"



/*
冒泡排序：相邻两个元素比较，一趟之后冒出一个最值
*/
void bubbleSort(int* pArray, int arrLen)
{
	for (int i = 0; i < arrLen; i++)
	{
		for (int j = 0; j < arrLen - i - 1; j++)
		{
			if (pArray[j] > pArray[j + 1])
			{
				swapNum(pArray[j], pArray[j + 1]);
			}
		}
	}

	return;
}
