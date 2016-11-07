#include <stdio.h>
void test(FILE *fread, FILE *fwrite)
{
    char buf[1024] = {0};
    if (!fgets(buf, sizeof(buf), fread))
        return;
    test( fread, fwrite );
    fputs(buf, fwrite);
}


int main(int argc, char** argv) 
{
    FILE *fr = NULL;
    FILE *fw = NULL;
    fr = fopen("D:\\4OJ\\test1.txt", "rb");
    fw = fopen("D:\\4OJ\\test2.txt", "wb");
    test(fr, fw);
    fclose(fr);
    fclose(fw);
    return 0;
}
