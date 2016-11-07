/*字符串相关处理函数：http://www.cppblog.com/dawnbreak/archive/2009/08/24/94262.html*/

/*写出strlen函数具体实现*/
int strlen( const char *str ) //输入参数const
{
　assert( strt != NULL ); //断言字符串地址非0
　int len;
　while( (*str++) != '\0' ) 
　{ 
　　len++; 
　} 
　return len;
}



/*写出strcpy函数具体实现*/
char * strcpy( char *strDest, const char *strSrc ) 
{
　assert( (strDest != NULL) && (strSrc != NULL) );
　char *address = strDest; 
　while( (*strDest++ = * strSrc++) != ‘\0’ ); 
　　return address;
}



/*写出strcpy函数具体实现，考虑地址重复的情况*/
char* strcpy_sameaddr(char* strDest, const char* strSrc)
{
   assert((strDest != NULL) && (strSrc != NULL));
   char* pDestStart = strDest;
   char* pDestEnd = strDest + strlen(strDest) - 1;
   char* pSrcStart = strSrc;
   char* pSrcEnd = strSrc + strlen(strSrc) - 1;
   
   if (pDestStart > pSrcStart)
   {
      while(pSrcEnd >= pSrcStart)
      {
         *pDestEnd-- = *pSrcEnd--;
      }
   }
   else
   {
      while(pSrcStart <= pSrcStart)
      {
         *pDestStart++ = *pSrcStart++;
      }
   }
   
   return strDest;
}



/*数字转换为字符串：123---->“123“*/
char* itoa(const int a)
{
   char zm[37]="0123456789abcdefghijklmnopqrstuvwxyz";  
   char aa[100]={0};  
  
   int sum=value;  
   char *cp=string;  
   int i=0;  
      
   if(radix<2||radix>36)//增加了对错误的检测  
   {  
       cout<<"error data!"<<endl;  
       return string;  
   }  
  
   if(value<0)  
   {  
       cout<<"error data!"<<endl;  
       return string;  
   }     
  
   while(sum>0)  
   {  
       aa[i++]=zm[sum%radix];  
       sum/=radix;  
   }  
  
   for(int j=i-1;j>=0;j--)  
   {  
       *cp++=aa[j];  
   }  
   *cp='\0';  
   
   return string;  
}



/*字符串转换为数字: "123"----->123*/
int atoi(const char* pch)
{
   assert(pch != NULL);
   int sum = 0;
   int signed = 1;
   
   /*前面有空格的情况*/
   while(*pch == ' ')
   {
      pch++;
   }
   
   /*对于有负号的数要处理*/
   if (*pch == '-' || *pch == '+')
   {
      signed = ((*pch == '-') ? -1 : 1);
      pch++;
   }
   
   while((*pch <= '9') && (*pch >= '0'))
   {
      sum = sum * 10 + (*pch - '0');
      
      /*要考虑超出int范围的情况*/
      if (s < 0)
      {
         sum = 0x7FFFFFFF;
      }
      pch++;
   }
   
   return signed * sum;
}


/*strcmp(src, dest)，实现两个字符串比较，相等返回0
如果dest > source,则返回值大于0，如果dest = source,则返回值等于0，如果dest  < source ,则返回值小于0.*/
int strcmp(const char *dest, const char *source)
{
   assert((NULL != dest) && (NULL != source));
   while (*dest && *source && (*dest == *source))
   {
       dest ++;
       source ++;
   }
   return *dest - *source;
}
