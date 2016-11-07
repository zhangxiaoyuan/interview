/*给定一个数组，求出数组中出现次数超过数组总数一半的数并返回*/

#include <iostream>
#include <map>
using namespace std;

int GetMoreThanHalfNum(int* arr, int len)
{
	if (arr == NULL || len < 0)
	{
		return -1;
	}

	int flagCnt = 1;
	int maxNum = arr[0];
	for (int i = 0; i < len; i++)
	{
		if (maxNum == arr[i])
		{
			flagCnt++;
		}
		else
		{
			if (flagCnt >= 0)
			{
				flagCnt--;
			}
			else
			{
				maxNum = arr[i];
				flagCnt = 1;
			}
		}
	}
	
	if (flagCnt > 0)
	{
		return maxNum;
	}

	return -1;
}

int GetMoreThanHalfNum1(int* arr, int len)
{
	if (arr == NULL || len < 0)
	{
		return -1;
	}
 	
	map<int, int> mapCnt; //第一个值是数组中对应的数字，第二个值是这个值出现的次数
	for (int i = 0; i < len; i++)
	{
		map<int ,int>::iterator tor = mapCnt.find(arr[i]);
		if (mapCnt.end() == tor)
		{
			mapCnt[arr[i]] = 1; 
		}
		else
		{
			mapCnt[arr[i]] = ++(tor->second);
		}
	}

	int size = len >> 1;
	map<int, int>::iterator tor = mapCnt.begin();
	while (tor != mapCnt.end())
	{
		if (size <=  tor->second)
		{
			return tor->first;
		}
		++tor;
	}

	return -1;
}
int main(int argc, char* argv[])
{

	int arr[] = {1,1,1,1,1,6,6,6,6,6};

	int num1 = GetMoreThanHalfNum(arr, sizeof(arr)/sizeof(arr[0]));
	int num = GetMoreThanHalfNum1(arr, sizeof(arr)/sizeof(arr[0]));

	cout << num << "  " << num1 << endl;
	return 1;
}
