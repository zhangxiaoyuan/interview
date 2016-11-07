/*输入一个数，求这个10进制数的二级制表示中的1的个数*/

int func （ x ）
{ 
  int countx = 0; 
  while ( x ) 
  { 
    countx ++; 
    x = x&(x-1); 
  } 
  return countx; 
} 
