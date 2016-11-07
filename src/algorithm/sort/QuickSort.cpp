#include "sortMethod.h"

/*挖坑填数，数据交换*/
int swithArray(int* pArray, int firstIdx, int lastIdx)
{
	int i, j, maxNum;
	i = firstIdx; j = lastIdx;
	maxNum = pArray[firstIdx];

	while (i < j)
	{
		while ((i < j) && (pArray[j] >= maxNum))
		{
			j--;
		}
		if (i < j)
		{
			pArray[i++] = pArray[j];
		}

		while ((i < j) && (pArray[i] < maxNum))
		{
			i++;
		}
		if (i < j)
		{
			pArray[j--] = pArray[i];
		}
	}

	pArray[i] = maxNum;
	return i;
}

/*递归序列比较*/
void compareArray(int* pArray, int firstIdx, int lastIdx)
{
	if (firstIdx < lastIdx)
	{
		int midIndex = swithArray(pArray, firstIdx, lastIdx);

		compareArray(pArray, firstIdx, midIndex - 1);
		compareArray(pArray, midIndex + 1, lastIdx);
	}
}


/*
快速排序：采用分治思想，随便取一个基准数，然后从序列开头开始和基准数比较，比它大的放在右边，比它小的放在左边，
然后从左右两边的序列中再重复上述步骤，直到各个分区只有一个数为止
挖坑填数+分治
*/
void quickSort(int* pArray, int arrLen)
{
	compareArray(pArray, 0, arrLen - 1);

	return;
}
