#include <iostream>
#include <unistd.h>
#include <stdlib.h>
 
using namespace std;
 
int main()
{
    char a[] = "abc";
    cout << "hello mutiThread" << endl;
    pid_t pid = vfork();
 
    if (pid == 0)
    {
        a[0] = '1';
        cout << "this is child thread" << " pid = "<< pid << endl;
        cout << "a add = " << &a << "  a= " << a << endl;
	// 一定要记得调用exit函数，否则子进程不会结束
        exit(1);
    }
    else
    {
        cout << "this is parent thread" << " pid = " << pid << endl;
        cout << "a add = " << &a << "  a = " << a << endl;
    }
}
