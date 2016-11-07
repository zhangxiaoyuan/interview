
/*
主要考虑涉及多种边界场景
1.base为0的场景 2.幂数为负的场景 3.浮点数相等的判断，不能之间用==判断
*/

double getPowerWithUnsigned(double baseN, unsigned int expo)
{
	double res = 1.0;

	for (unsigned int i = 0; i < expo; i++)
	{
		res *= baseN;
	}

	return res;
}

bool equalDouble(double input1, double input2)
{
	if ((input1 - input2 > -0.0000001)
		&& (input2 - input1) < 0.00000001)
	{
		return true;
	}

	return false;
}
double getPower(double baseN, int exponet)
{
	if (equalDouble(baseN, 0.0) && exponet < 0)
	{
		cout << "error, input error!" << endl;
		return 0;
	}

	unsigned int exponentChange = exponet;
	if (exponet < 0)
	{
		exponentChange = (unsigned int)(-exponet);
	}

	double result = getPowerWithUnsigned(baseN, exponentChange);

	if (exponet < 0)
	{
		result = 1.0 / result;
	}
	return result;
}
