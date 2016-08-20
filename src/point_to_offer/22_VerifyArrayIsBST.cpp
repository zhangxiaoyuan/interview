
/*
 二叉搜索树：或者是一颗空树，或者具有如下性质：如果他的左子树不空，那么左子树上的所有节点的值均小于它的根节点的值，
 如果右子树不空，则右子树上的所有节点的值均大于它的根节点的值，它的左右子树也分别是二叉搜索树（也叫二叉排序树）*/

/*
 解法：最后一个值是根，前面的数据可以分为两部分，第一部分是左子树的节点，都比根小，第二部分都是右子树的节点，都比根大
 这样就可以从头开始遍历找出左子树节点，然后再找出右子树节点，然后递归判断左右子树是否满足条件
 */
bool VerifyArrayIsBST(int* arr, int length)
{
    if (arr == NULL || length < 1)
    {
        return false;
    }
    
    int root = arr[length - 1];
    int leftIdx = 0;
    /*先求出左子树的所有节点*/
    for (;leftIdx < length - 1; leftIdx++)
    {
        if(arr[leftIdx] > root)
        {
            break;
        }
    }
    
    int rightIdx = leftIdx;
    for (; rightIdx < length - 1; rightIdx++)
    {
        if (arr[rightIdx] < root)
        {
            return false;
        }
    }
    
    bool left = true;
    if (leftIdx > 0)
        left = VerifyArrayIsBST(arr, leftIdx);
    
    bool right = true;
    if (leftIdx + 1 < length)
        right = VerifyArrayIsBST(&arr[leftIdx + 1], length - leftIdx - 1);
    
    return left & right;
}

int main(int argc, const char * argv[])
{
    cout << "hello world, hello mac" << endl;
    //int arr[] = {5,7,6,9,11,10,8};
    int arr[] = {7,4,6,5};
    
    bool re = VerifyArrayIsBST(arr, 4);
    cout << re << endl;
     
     return 1;
}
