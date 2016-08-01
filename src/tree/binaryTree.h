#ifndef __TREE_H_
#define __TREE_H_

#include <iostream>

/*
前序遍历：根节点->左子树->右子树
中序遍历：左子树->根节点->右子树
后序遍历：左子树->右子树->根节点

例如：求下面树的三种遍历

      a
     / \
    b   c
  /  \
 d    f
 \   / 
  e g

 前序遍历：abdefgc
 中序遍历：debgfac
 后序遍历：edgfbca
*/

/*二叉树的三种遍历*/
template<class T>
class BinaryTreeNode{
private:
	T data;
	BinaryTreeNode<T>* pLeftChild;
	BinaryTreeNode<T>* pRightChild;
};

template<class T>
void visit(T& t)
{
	return;
}
/*1.前序遍历：根节点->左子树->右子树*/
template<class T>
void preOrder(BinaryTreeNode<T>* t)
{
	if(t)
	{
		visit(t);
		preOrder(t->pLeftChild);
		preOrder(t->pRightChild);	
	}
}

/*2.中序遍历:左子树->根节点->右子树*/
template<class T>
void InOrder(BinaryTreeNode<T>* t)
{
	if(t)
	{
		InOrder(t->pLeftChild);
		visit(t);
		InOrder(t->pRightChild);	
	}
}

/*3.后序遍历:左子树->右子树->根节点*/
template<class T>
void PostOrder(BinaryTreeNode<T>* t)
{
	if(t)
	{
		PostOrder(t->pLeftChild);
		PostOrder(t->pRightChild);
		visit(t);
	}
}

#ifdef __cplusplus
extern "C"
{

}
#endif
#endif
