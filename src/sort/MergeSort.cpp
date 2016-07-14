#include "sortMethod.h"


/*合并两个有序序列*/
void mergeArray(int* pArray, int firstIdx, int midIdx, int lastIdx, int* pTempArr)
{
	int i, j, k;
	i = firstIdx;
	j = midIdx + 1;
	k = 0;

	while((i <= midIdx) && (j <= lastIdx))
	{
		if (pArray[i] < pArray[j])
		{
			pTempArr[k++] = pArray[i++]; 
		}
		else
		{
			pTempArr[k++] = pArray[j++];
		}
	}

	while (i <= midIdx)
	{
		pTempArr[k++] = pArray[i++];
	}

	while (j <= lastIdx)
	{	
		pTempArr[k++] = pArray[j++];
	}

	for (int m = 0; m < k; m++)
	{
		pArray[firstIdx + m] = pTempArr[m];
	}

	return;
}

/*递归分解无序序列*/
void reduceArray(int* pArray, int firstIdx, int lastIdx, int* pTempArr)
{
	/*分解到子序列中只有一个元素为止*/
	if (firstIdx < lastIdx)
	{
		int midIdx = (firstIdx + lastIdx) / 2;
		reduceArray(pArray, firstIdx, midIdx, pTempArr); 
		reduceArray(pArray, midIdx + 1, lastIdx, pTempArr);

		mergeArray(pArray, firstIdx, midIdx, lastIdx, pTempArr);
	}

	return;
}

/*
归并排序：采用分治思想，将待排序列拆分成很多子序列，然后子序列在进行排序，然后再合并，最后生成一个有序序列
*/
void mergeSort(int* pArray, int arrLen)
{
	//这里申请内存时需要注意是int类型，4个字节
	int* pBackArr = (int*)malloc(arrLen * sizeof(int));
	if (NULL == pBackArr)
	{
		return;
	}
	memset(pBackArr, 0, arrLen * sizeof(int));
	int* pTempArr = pBackArr;

	//先分解无序序列，然后再比较合并
	reduceArray(pArray, 0, arrLen - 1, pTempArr);

	free(pBackArr);
	pBackArr = NULL;
	return;
}

