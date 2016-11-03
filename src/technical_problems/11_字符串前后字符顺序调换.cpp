/*用指针的方法，将字符串“ABCD1234efgh”前后对调显示*/
#include <stdio.h>
#include <string.h>
#include <dos.h>
int main()
{
char str[] = "ABCD1234efgh";
int length = strlen(str);
char * p1 = str;
char * p2 = str + length - 1;
while(p1 < p2)
{
char c = *p1;
*p1 = *p2;
*p2 = c;
++p1;
--p2;
}
printf("str now is %s/n",str);
system("pause");
return 0;
}
