#include "SortClient.h"


void swapNum(int& a, int& b)
{
	//method1：适用于整形数交换，如果使用引用并且这两个入参指向同一个变量，怎会出现将变量赋0的情况，需要注意
	/*if (a != b)
	{
		a ^= b;
		b ^= a;
		a ^= b;
	}*/

	/*if (a != b)
	{
	a ^= b ^= a;
	}*/

	//method2: 适用于整形和浮点数，但是不能太大，否则会溢出
	/*a += b;
	b = a - b;
	a = a - b;*/

	//method3：适用于整型变量,但是不能太大，否则会溢出
	/*if (b != 0)
	{
		a *= b;
		b = a / b;
		a = a / b;
	}*/

	int c = a;
	a = b;
	b = c;
	
	//printf("a=%d, b =%d\r\n", a , b);

}

void printArr(int* arr, int len, char* pName)
{
	printf("%s:\r\n", pName);
	int length = 10;
	for (int i = 0; i< len; i++)
	{
		printf("%d=[%d]  ", i, *arr++);
	}
}

void main()
{
	int arr[3];
	int arr1[4] = {1,2,3,4};
	int beforeSort1[] = {2,1,4,9,10,8,7,2,38,1,20};
	int beforeSort2[] = {2,1,4,9,10,8,7,2,38,1,20};
	int beforeSort3[] = {2,1,4,9,10,8,7,2,38,1,20};
	int beforeSort4[] = {2,1,4,9,10,8,7,2,38,1,20};
	int beforeSort5[] = {2,1,4,9,10,8,7,2,38,1,20};
	int beforeSort6[] = {2,1,4,9,10,8,7,2,38,1,20};

	memset(arr, 0, sizeof(arr));
	printArr(beforeSort1, (sizeof(beforeSort1)/sizeof(int)),"original data");

	//1.选择排序
	selectSort(beforeSort1, (sizeof(beforeSort1)/sizeof(int)));
    printArr(beforeSort1, (sizeof(beforeSort1)/sizeof(int)), "select sort");

	//2.插入排序
	insertSort(beforeSort2, (sizeof(beforeSort2)/sizeof(int)));
	printArr(beforeSort2, (sizeof(beforeSort2)/sizeof(int)), "insert sort");

	//3.冒泡排序
	bubbleSort(beforeSort3, (sizeof(beforeSort3)/sizeof(int)));
	printArr(beforeSort3, (sizeof(beforeSort3)/sizeof(int)), "bubble sort");

	//4.堆排序
	heapSort(beforeSort4, (sizeof(beforeSort4)/sizeof(int)));
	printArr(beforeSort4, (sizeof(beforeSort4)/sizeof(int)), "heap sort");

	//5.归并排序
	mergeSort(beforeSort5, (sizeof(beforeSort5)/sizeof(int)));
	printArr(beforeSort5, (sizeof(beforeSort5)/sizeof(int)), "merge sort");

	//6.快速排序
	quickSort(beforeSort6, (sizeof(beforeSort6)/sizeof(int)));
	printArr(beforeSort6, (sizeof(beforeSort6)/sizeof(int)), "quick sort");
}
