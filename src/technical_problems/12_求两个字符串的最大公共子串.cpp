/*给定字符串A和B,输出A和B中的最大公共子串。
比如A="aocdfe" B="pmcdfa" 则输出"cdf"*/

char *commanstring(char shortstring[], char longstring[])
{
	int i, j;

	char *substring=malloc(256);

	if(strstr(longstring, shortstring)!=NULL) //如果……，那么返回shortstring
		return shortstring; 

	for(i=strlen(shortstring)-1;i>0; i--) //否则，开始循环计算
	{
		for(j=0; j<=strlen(shortstring)-i; j++){
			memcpy(substring, &shortstring[j], i);
			substring[i]='/0';
			if(strstr(longstring, substring)!=NULL)
				return substring;
		}
	}
	return NULL;
}
