#include "sortMethod.h"

/*选择排序：每次轮训用无序串的第一个数与后面的每一个数比较，
如果满足条件，则交换，交换之后，依然与后面的每一个比较，直到串尾。
轮训一次之后就可以在串首产生一个最值，以此类推，直到最后连个数比较。
*/
void selectSort(int* pArray, int arrLen)
{
	int arrayLen = arrLen;

	for (int i = 0; i < arrayLen - 1; i++) //长度减1表示最后一个元素不用比较
	{
		for (int j = i + 1; j < arrayLen; j++)
		{
			if (pArray[i] > pArray[j])
			{
				swapNum(pArray[i], pArray[j]);
			}
		}
	}

	return;
}




