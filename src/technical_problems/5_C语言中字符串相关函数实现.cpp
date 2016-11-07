/*字符串相关处理函数：http://www.cppblog.com/dawnbreak/archive/2009/08/24/94262.html*/

/*写出strlen函数具体实现*/
/*写出strcpy函数具体实现*/
char * strcpy( char *strDest, const char *strSrc ) 
{
　assert( (strDest != NULL) && (strSrc != NULL) );
　char *address = strDest; 
　while( (*strDest++ = * strSrc++) != ‘\0’ ); 
　　return address;
}

/*写出strcpy函数具体实现，考虑地址重复的情况*/
/*数字转换为字符串：123---->“123“*/
/*字符串转换为数字: "123"----->123*/

/*strcmp(src, dest)，实现两个字符串比较，相等返回0*/
int strcmp(const char *dest, const char *source)
{
   assert((NULL != dest) && (NULL != source));
   while (*dest && *source && (*dest == *source))
   {
       dest ++;
       source ++;
   }
   return *dest - *source;
/*如果dest > source,则返回值大于0，如果dest = source,则返回值等于0，如果dest  < source ,则返回值小于0。*/
}
