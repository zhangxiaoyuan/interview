#ifndef __COMMON_SORT_H__
#define __COMMON_SORT_H__

#ifdef _cplusplus
extern "C"{
#endif


#include <cstdio>
#include <cstring>
#include <cstdlib>

void swapNum(int& a, int& b);
void quickSort(int* pArray, int arrLen);
void mergeSort(int* pArray, int arrLen);
void heapSort(int* pArray, int arrLen);
void bubbleSort(int* pArray, int arrLen);
void insertSort(int* pArray, int arrLen);
void selectSort(int* pArray, int arrLen);


#ifdef _cplusplus
};
#endif

#endif
