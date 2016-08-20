
/*
 从跟节点开始，当打印完跟节点之后，将左子树先压入一个队列，然后在将右子树压入队列，然后去将队列中的第一个压入队列的节点递归调用即可
 退出递归的条件：当节点为空时
 */
#include <queue>

queue<BinaryTree*> treeQueue;
void PrintBinaryTreeByWidth(BinaryTree* pTree)
{
    if (!treeQueue.empty())
    {
        treeQueue.pop();
    }
    
    if (pTree != NULL)
    {
        cout << pTree->m_value << endl;
        if (pTree->m_left != NULL)
        {
            treeQueue.push(pTree->m_left);
        }
        if(pTree->m_right != NULL)
        {
            treeQueue.push(pTree->m_right);
        }
        
        PrintBinaryTreeByWidth(treeQueue.front());
    }
}


void PrintBTreeByWidth(BinaryTree* pTree)
{
    if (pTree == NULL)
    {
        return;
    }
    
    queue<BinaryTree*> treeQueue;
    treeQueue.push(pTree);
    
    while(!treeQueue.empty())
    {
        BinaryTree* pTemp = treeQueue.front();
        if (pTemp == NULL)
        {
            break;
        }
        cout << pTemp->m_value << endl;
        treeQueue.pop();
        
        if (pTemp->m_left != NULL)
        {
            treeQueue.push(pTemp->m_left);
        }
        if (pTemp->m_right != NULL)
        {
            treeQueue.push(pTemp->m_right);
        }
    }
}


void main()
{
BinaryTree p5;
    p5.m_value = 9;
    p5.m_left = NULL;
    p5.m_right = NULL;
    
    BinaryTree p6;
    p6.m_value = 11;
    p6.m_left = NULL;
    p6.m_right = NULL;
    
    BinaryTree p7;
    p7.m_value = 3;
    p7.m_left = NULL;
    p7.m_right = NULL;
    
    BinaryTree p3;
    p3.m_value = 5;
    p3.m_left = &p7;
    p3.m_right = NULL;
    
    BinaryTree p4;
    p4.m_value = 7;
    p4.m_left = NULL;
    p4.m_right = NULL;
    
    BinaryTree p1;
    p1.m_value = 6;
    p1.m_left = &p3;
    p1.m_right = &p4;
    
    BinaryTree p2;
    p2.m_value = 10;
    p2.m_left = &p5;
    p2.m_right = &p6;
    
    BinaryTree root;
    root.m_value = 8;
    root.m_left= &p1;
    root.m_right = &p2;

    PrintBinaryTreeByWidth(&root);
    cout << "===" << endl;
    PrintBTreeByWidth(&root);
}
