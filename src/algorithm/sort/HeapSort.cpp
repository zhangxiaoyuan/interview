#include "sortMethod.h"


/*调整堆*/
void adjustHeap(int* pArray, int arrLen, int notLeafIndex)
{
	int lLeaf = notLeafIndex * 2 + 1;
	int rLeaf = notLeafIndex * 2 + 2;
	int parentIdx = notLeafIndex;

	if ((lLeaf < arrLen) && (pArray[lLeaf] > pArray[notLeafIndex]))
	{
		parentIdx = lLeaf;
	}

	if ((rLeaf < arrLen) && (pArray[rLeaf] > pArray[parentIdx]))
	{
		parentIdx = rLeaf;
	}

	//如果此时的父节点的index不等于开始时的index，表示父节点要与子节点进行交换
	if (parentIdx != notLeafIndex)
	{
		swapNum(pArray[parentIdx], pArray[notLeafIndex]);
		//交换之后可能以parentIdx为子节点的顺序被打乱，因此需要在重新对子节点调整一次
		adjustHeap(pArray, arrLen, parentIdx);
	}
}

/*构造堆*/
void buildHeap(int* pArray, int arrLen)
{
	//从最后一个非叶子节点开始调整堆顺序
	int lastNotLeaf = (arrLen / 2) - 1;

	for (int i = lastNotLeaf; i >= 0; i--)
	{
		adjustHeap(pArray, arrLen, i);
	}
}

/*
堆排序：按照二叉堆（平衡二叉树）的规律，父节点总是大于等于或者小于等于左右子节点的值，
先将待排序数组进行构造二叉堆（从最后一个非叶子节点开始进行调整，直到根节点稳定），
然后用根节点和最后一个节点进行选择排序，以此类推
*/
void heapSort(int* pArray, int arrLen)
{
	//1.构造二叉堆
	buildHeap(pArray, arrLen);

	//2.将无序区第一个元素与最后一个元素对换，然后再次构造二叉堆
	for (int i = arrLen - 1; i > 0; i--)
	{
		swapNum(pArray[0], pArray[i]);

		//调整堆顶的顺序
		adjustHeap(pArray, i, 0);
	}

	return;
}
