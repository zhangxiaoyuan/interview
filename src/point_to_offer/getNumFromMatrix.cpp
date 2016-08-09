/*
从一个有规律的二维数组中查找一个特定的值
二维数组的规律，每一行的数字值递增，每一列的数值也是递增
example:
1   2   8   9
2   4   9   12
4   7   10  13
6   8   11  15
*/

int getNum(int* arr, int rowCnt, int colCnt, int num);
void main()
{
	int arr[4][4] = {1,2,8,9,2,4,9,12,4,7,10,13,6,8,11,15};

	int ret = getNum(&arr[0][0], 4, 4, 14);
	cout << "re = " << ret << endl;
}


int getNum(int* arr, int rowCnt, int colCnt, int num)
{
	if (NULL == arr)
	{
		return -1;
	}
	
	if (*arr > num || *(arr + rowCnt*colCnt - 1) < num)
	{
		cout << "impossible get" << endl;
		return -1;
	}

	int i = colCnt - 1;
	int j = 0;
	for (;i >= 0 && j < rowCnt;)
	{
		int val = *(arr+(j*colCnt+i));
		if (val > num)
		{
			i--;
		}
		else if (val < num)
		{
			j++;
		}
		else
		{
			cout << "row=" << j+1 <<" col=" << i+1 <<endl;
			return 0;
		}
	}

	return -1;
}
