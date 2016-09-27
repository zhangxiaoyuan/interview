#include <iostream>
#include <unistd.h>
#include <sys/mman.h>
using namespace std;

#define STACK_SIZE 1024*1024*8 //8M

static char a[] = "abc";

int thread_func(void* args)
{
    a[0] = '1';
    cout << "this is child thread : " << getpid() << endl;
    cout << "a add = " << &a << "  a= " << a << endl;
}

int main()
{
    void *pstack = (void *)mmap(NULL,
                                STACK_SIZE,
                                PROT_READ | PROT_WRITE ,
                                MAP_PRIVATE | MAP_ANONYMOUS | MAP_ANON ,//| MAP_GROWSDOWN ,
                                -1,
                                0);

    cout << "hello mutilProcess" << endl;
    
    int ret = clone(thread_func,
                    (void *)((unsigned char *)pstack + STACK_SIZE),
                    CLONE_VM | CLONE_FS  | CLONE_FILES | CLONE_SIGHAND,
                    (void *)NULL);    
 
    if (ret == -1)
    {
	cout << "clone error" << endl;
    }
    else
    {
	cout << "this is parent thread" << " ret = " << ret << endl;
	cout << "a add = " << &a << "  a = " << a << endl;
    }
}
