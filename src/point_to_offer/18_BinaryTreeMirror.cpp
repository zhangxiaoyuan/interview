//  Created by mango on 16/8/19.
//  Copyright © 2016年 mango. All rights reserved.
//

#include <iostream>

using namespace std;


struct BinaryTree
{
    int m_value;
    BinaryTree* m_left;
    BinaryTree* m_right;
};

void BinaryTreeMirror(BinaryTree* pHead)
{
    if (pHead == NULL || (pHead->m_left == NULL  && pHead->m_right == NULL))
    {
        return;
    }
    
    BinaryTree* pTemp = pHead->m_left;
    pHead->m_left = pHead->m_right;
    pHead->m_right= pTemp;
    
    if (pHead->m_left)
        BinaryTreeMirror(pHead->m_left);
    if (pHead->m_right)
        BinaryTreeMirror(pHead->m_right);
}

void PreOrder(BinaryTree* ptree)
{
    if (ptree != NULL)
    {
        cout << ptree->m_value << endl;
        PreOrder(ptree->m_left);
        PreOrder(ptree->m_right);
    }
}

int main(int argc, const char * argv[])
{
    cout << "hello world, hello mac" << endl;
    
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
    
    PreOrder(&root);
    
    BinaryTreeMirror(&root);
    
    cout << "========" << endl;
    
    PreOrder(&root);
    
    return 1;
}
