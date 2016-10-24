1.double或float转为int时，对齐小数位，例：
```c++
	double da = 2.6;
	float db = 3.4;
	int ia = (int)da;   //2
	int ib = (int)db;   //3
```
2.文件操作函数：
int fseek(FILE *stream, long offset, int fromwhere);
 > 函数设置文件指针stream的位置，stream将指向以fromwhere为基准，偏移offset（指针偏移量）个字节的位置，函数返回0
FILE * fopen(const char * path,const char * mode); 
 > 文件顺利打开后，指向该流的文件指针就会被返回
long ftell(FILE *stream);
 > 用于得到文件位置指针当前位置相对于文件首的偏移字节数。
 
3.
