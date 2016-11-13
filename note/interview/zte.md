1.###判断：
int* func()
{
    int* ptem;
    ptem = 10;
    return ptem;
}

2.###是否输出正常：
int* func()
{
    int arr[] = {1,2,3,4,5};
    return arr;
}

void main()
{
    int parr = func();
    printf("%d\n", parr);
}

3.###输出值是多少：
typedef struct note
{
    int a;
    int b;
    int c;
}t_node;

void main()
{
    t_node node = {3,5,6};
    t_node* pnode = &node;
    
    printf("%d\n", *(int*)pnode);
}

###4.编程题：
输入一个整数，求出这个整数的二进制表示中1的总个数。
