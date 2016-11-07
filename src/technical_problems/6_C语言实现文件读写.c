
#include<stdio.h>
/*用c语言写法实现从文件1中读取数据并写入到文件2中*/

int getNumtoFileWithc()
{
    FILE* fp;
    char ch ;
    fp = fopen("D:\\4OJ\\test1.txt", "rt");
    FILE* fp2;
    fp2 = fopen("D:\\4OJ\\test2.txt", "wt+");

    if (fp == NULL)
    {
        printf("\nCannot open file strike asny key exit!\n");
        return -1;
    }
    
    ch = fgetc(fp);
    while (ch != EOF)
    {
        putchar(ch);     //打印读取的字符
        fputc(ch, fp2);  //写入到指定文件中
        ch=fgetc(fp);    
    }
    fclose(fp);

    /*fgets读取一行中指定长度数据，末尾自动添加‘\0’占一位，如果长度超出会溢出报错*/
    /*FILE *fp;
    char str[7];
    if((fp=fopen("D:\\4OJ\\test1.txt","rt"))==NULL){
        printf("\nCannot open file strike any key exit!");
        return -1;
    }
    fgets(str,20,fp);
    printf("\n%s\n",str);
    fclose(fp);*/

    return 1;
}
