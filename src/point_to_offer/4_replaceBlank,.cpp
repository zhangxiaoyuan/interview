/*
将一个字符串中的空格替换成“%20“字符串
有两种方案：一种是在原来的字符串基础上进行修改，不过字符串的空间大小要保证修改后的字符串能够放下
第二种方案，新申请字符串，在新字符串中操作，由调用者保证清除申请内存
*/

int strRepalce(char** pstr);
int strRepalce1(char** pstr);
void main()
{
	char* str = new char[20];
	char* str1 = " we are happy";
	memcpy(str, str1, strlen(str1) + 1);
	/*int re = strRepalce(&str);
	cout << "rest = " << re <<" = "<<str << endl;

	delete[] str;
	str = NULL;*/

	int re = strRepalce1(&str);
	cout << "rest = " << re <<" = "<<str << endl;
	delete []str;
	str = NULL;
}

int strRepalce1(char** pstr)
{
	if (NULL == pstr || NULL == *pstr)
	{
		return -1;
	}

	char* ptemp = *pstr;
	int spaceCnt = 0;
	while(*ptemp != '\0')
	{
		if (*ptemp == ' ')
		{
			spaceCnt++;
		}
		ptemp++;
	}

	char* ptemp2 = ptemp + spaceCnt*2;

	while (ptemp != ptemp2)
	{
		if (*ptemp == ' ')
		{
			*ptemp2-- = '0';
			*ptemp2-- = '2';
			*ptemp2-- = '%';
			ptemp--;
		}
		else
		{
			*ptemp2 = *ptemp;
			*ptemp--;
			*ptemp2--;
		}
	}

	return 0;
}

int strRepalce(char** pstr)
{
	if (NULL == pstr || NULL == *pstr)
	{
		return -1;
	}

	//最大的可能，也可以采用先遍历一遍字符串，获取出空格个数，然后再计算所占空间
	char* pnewstr = new char[strlen(*pstr) * 3 + 1];

	char* ptemstr = *pstr;
	char* ptemNewstr = pnewstr;

	while(*ptemstr != '\0')
	{
		if (' ' == *ptemstr)
		{
			*ptemNewstr++ = '%';
			*ptemNewstr++ = '2';
			*ptemNewstr++ = '0';
			*ptemstr++;
		}
		else
		{
			*ptemNewstr++ = *ptemstr++;
		}
	}

	*ptemNewstr = '\0';
	*pstr = pnewstr;

	return 0;
}
