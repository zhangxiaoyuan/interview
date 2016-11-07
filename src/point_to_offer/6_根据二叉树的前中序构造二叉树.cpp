/*
 给定一个二叉树的前序遍历顺序{1,2,4,7,3,5,6,8},中序遍历顺序{4,7,2,1,5,3,8,6},请构造出这个二叉树并输出节点值
 
 规律：前序遍历中第一个节点就是根节点，但是中序遍历中，根节点值在中间，左子树的节点位于根节点左边，右子树的节点位于根节点的右边
 */

typedef struct _TreeNode
{
	int m_data;
	_TreeNode* m_pleft;
	_TreeNode* m_pright;
}TreeNode;

TreeNode* constructTree(int* frontStart, int* frontend, int* midstart, int* midend);
TreeNode* rebuildBinaryTree(int front[], int middle[], int length);
void printTreeNode(TreeNode* root);

void main()
{
	int front[] = {1,2,4,7,3,5,6,8};
	int mid[] = {4,7,2,1,5,3,8,6};

	TreeNode* root = rebuildBinaryTree(front, mid, 8);
	cout << "end" << endl;
	printTreeNode(root);
}

void printTreeNode(TreeNode* root)
{
	cout << "data :" << root->m_data << endl;
	if(root->m_pleft != NULL)
	{
		cout << root-> m_data << " left child:";
		printTreeNode(root->m_pleft);
	}

	if (root->m_pright != NULL)
	{
		cout <<  root-> m_data << " right child: ";
		printTreeNode(root->m_pright);
	}

	return;
}
/*
二叉树的几种特例树：
1.二叉搜索树：左子节点总是小于等于根节点，右子节点总是大于等于根节点
2.堆:根节点总是大于等于或者小于等于左右子节点，大顶堆和小顶堆
3.平衡二叉树：
4.完全二叉树：
5.满二叉树：
6.二叉查找树:
*/
#include <list>


TreeNode* rebuildBinaryTree(int front[], int middle[], int length)
{
	if (front == NULL || middle == NULL || length <= 0)
	{
		return NULL;
	}

	return constructTree(front, front+ length-1, middle, middle +length-1);
}

TreeNode* constructTree(int* frontStart, int* frontend, int* midstart, int* midend)
{
	TreeNode* pHead = new TreeNode;
	pHead->m_data = frontStart[0];
	pHead->m_pleft = pHead->m_pright = NULL;

	if(frontStart == frontend )
	{
		if (midstart == midend && *frontStart == *frontend)
		{
			return pHead;	
		}
		else
		{
			cout << "input error " <<endl;
			return NULL;
		}
	}

	int* ptemp = midstart;
	while(ptemp != midend && *ptemp != frontStart[0])
	{
		ptemp++;
	}

	if (ptemp == midend && *ptemp != frontStart[0])
	{
		cout << "input error " <<endl;
		return NULL;
	}

	int leftLen = ptemp - midstart;
	int rightLen = midend - ptemp;

	if (leftLen > 0)
	{
		pHead->m_pleft = constructTree(frontStart + 1, frontStart + leftLen, midstart, midstart + leftLen - 1);
	}

	if (leftLen < frontend - frontStart)
	{
		pHead->m_pright = constructTree(frontStart + leftLen + 1, frontend, ptemp + 1, midend);
	}

	return pHead;
}
