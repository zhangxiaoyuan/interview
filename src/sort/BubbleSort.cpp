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

/*鸡尾酒排序法：对冒泡排序的改进，进行双向冒泡排序，时间复杂度相同，但是某些情况有优势*/
void cockTailSort(int* pArray, int arrLen)
{
	for (int i = 0; i < arrLen;)
	{
		int tail = arrLen -1 ;
		/*第一轮for循环从尾巴开始，将最小值排序到数组最前*/
		for (int j = tail; j > 0; j--)
		{
			if (pArray[j] < pArray[j - 1])
			{
				swapNum(pArray[j], pArray[j - 1]);
			}
		}
		/*在从头开始，在进行冒泡, 一轮循环之后将最大值拍到数组最后*/
		i++;
		for (int j = i; j < tail; j++)
		{
			if (pArray[j] > pArray[j + 1])
			{
				swapNum(pArray[j], pArray[j + 1]);
			}
		}
		/*从后往前冒泡一次，然后再从前往后冒泡一次，双向冒泡，往中间逼近*/
		tail--;
	}
}

