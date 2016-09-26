#include <iostream>
#include <unistd.h>

using namespace std;

int main()
{
    char a[] = "abc";
    cout << "hello mutiThread" << endl;
    
    pid_t pid = clone();
 
    if (pid == 0)
    {
 	a[0] = '1';
    	cout << "this is child thread" << " pid = "<< pid << endl;
	cout << "a add = " << &a << "  a= " << a << endl;
    }
    else
    {
	cout << "this is parent thread" << " pid = " << pid << endl;
	cout << "a add = " << &a << "  a = " << a << endl;
    }
}
