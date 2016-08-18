
/*
 采用进位方式，先从最低位开始累加到10，然后清零，给上一位进位1，以此类推
*/
bool Increment(char* number)
{
	int len = strlen(number);
	int takeOver = 0;
	bool isFlowOver = false;

	for(int i = len - 1; i >= 0; i--)
	{
	  /*始终对个位数进行累加，然后高位数进位即可*/
		int sum = number[i] - '0' + takeOver;
		if (i == len - 1)
			sum++;

		if (sum >= 10)
		{
			if (i == 0)
			{
				isFlowOver = true;
				break;
			}

			sum -= 10;
			number[i] = '0' + sum;
			takeOver = 1;
		}
		else
		{
			number[i] = '0' + sum;
			break;
		}
	}

	return isFlowOver;
}

void PrintNum(char* number)
{
	bool isPrint = false;
	int len = strlen(number);

	for (int i = 0; i < len; i++)
	{
		if (number[i] != '0' && !isPrint)
		{
			isPrint = true;
		}

		if (isPrint)
		{
			cout << number[i];
		}
	}

	cout << endl;
}


/*输入数组n，按顺序打印出从1到n之间的所有数*/
void Get1ToMax(int n)
{
	if (n < 1)
	{
		return;
	}
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while(!Increment(number))
	{
		PrintNum(number);
	}

	delete[] number;

	return;
}


void print1ToMaxRecursion(char* num, int len, int idx)
{
	if(idx == len - 1)
	{
		PrintNum(num);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		num[idx + 1] = '0' + i;
		print1ToMaxRecursion(num, len, idx + 1);
	}
}
/*采用递归思想，给一位数从0-9循环*/
void Print1ToMaxAnother(int n)
{
	if (n < 1)
		return;
	
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = '0' + i;
		print1ToMaxRecursion(number, n, 0);
	}
	
	delete[] number;
}


void main()
{
	Get1ToMax(10);
	Print1ToMaxAnother(2);
}
