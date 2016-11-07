/*给定字符串A和B,输出A和B中的最大公共子串。
比如A="aocdfe" B="pmcdfa" 则输出"cdf"*/

/*从短串的最长串开始构造各种可能组合的串，然后比较是否出现在长串中*/
char *commanstring(char shortstring[], char longstring[])
{
	int i, j;

	char *substring=malloc(256);

	if(strstr(longstring, shortstring)!=NULL) //如果短串直接就是长串的子串，那么返回shortstring
	return shortstring; 

	for(i=strlen(shortstring)-1;i>0; i--) //否则，开始循环计算
	{
		for(j=0; j<=strlen(shortstring)-i; j++){
			memcpy(substring, &shortstring[j], i); //从短串的最长串开始组合，组合出各种形式的串，然后去比较是否在长串中
			substring[i]='/0';
			if(strstr(longstring, substring)!=NULL)
				return substring;
		}
	}
	return NULL;
}
