#include <iostream>
#include <fstream>
#include <stdlib.h>
int getCharFromFileWithcpp()
{
    cout << "this is me" << endl;
    char ch[256];
    ifstream ins("D:\\4OJ\\test1.txt");
    ofstream ofs("D:\\4OJ\\test2.txt");
    if (!ins.is_open())
    {
        cout << "open file failed" << endl;
        return -1;
    }

    while(!ins.eof())
    {
        ins.getline(ch, 100);  //从文件中读取一行到缓冲中
        cout << ch << endl; 
        ofs << ch << endl;    //将缓冲中数据写入到文件中
    }

    ins.close();
    ofs.close();

    return 1;
}
