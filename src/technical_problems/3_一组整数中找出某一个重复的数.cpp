/*数组a[N]，存放了1至N-1个数，其中某个数重复一次。写一个函数，找出被重复的数字.时间复杂度必须为o（N）函数原型：int do_dup(int a[],int N)*/


/*方法1：如果数就是1－N-1,那么求出a[N]的和，然后减去1－N-1就行了。(确定数字1-N)*/
void main()
{
	S = N * (N-1) / 2;
	int i;
	int s = 0;
	for(i=0;i<N;++i)
	{
		s += a[i];
	}
	int res = s - S;
}

/*方法2: a[]中的某元素a[i]看做是pi[]数组的下标，元素a[i]存储到对应数组下标pi[a[i]]的地址中*/

#include<stdio.h> 
#define N 10 
void main() 
{  
	int a[N]={1,2,3,4,5,6,7,7,8,9}; 
	int pi[N]={0}; 
	int key=0; 
	for(int i=0;i<N;i++) 
	{  
		if(pi[a[i]]==0) 
		pi[a[i]]=a[i]; 
	else  
	{ 
		key=a[i]; 
		break; 
	} 

	printf("多余的数字是%d/n",key); 
}
