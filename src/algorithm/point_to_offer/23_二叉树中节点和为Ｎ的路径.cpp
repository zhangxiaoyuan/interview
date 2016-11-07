
/*输入一个二叉树和一个整数，打印出二叉树中所有节点值的和为输入整数的所有路径*/
#include <vector>
void FindPath(BTreeNode* pNode, int excptedSum, vector<int>& pathVec, int curSum)
{
	curSum += pNode->m_value;
	pathVec.push_back(pNode->m_value);

	//判断是否为叶节点
	bool isLeaf = (pNode->pLeft == NULL && pNode->pRight == NULL);

	if(isLeaf && curSum == excptedSum)
	{
		int i = 0;
		vector<int> ::iterator ite = pathVec.begin();
		while(ite != pathVec.end())
		{
			cout << *ite << " ";
			++ite;
		}
		cout << endl;
	}

	if (pNode->pLeft != NULL)
	{
		FindPath(pNode->pLeft, excptedSum, pathVec, curSum);
	}
	if (pNode->pRight != NULL)
	{
		FindPath(pNode->pRight, excptedSum, pathVec, curSum);
	}

	curSum -= pNode->m_value;
	pathVec.pop_back();
}

void FindPathBySum(BTreeNode* pRoot, int sum)
{
	if (pRoot == NULL)
	{
		return;
	}

	if (pRoot->m_value > sum)
	{
		return;
	}

	vector<int> pathVec;
	int curSum = 0;

	FindPath(pRoot, sum ,pathVec, curSum);
}


void main()
{
	BTreeNode p31;
	p31.m_value = 4;
	p31.pLeft = NULL;
	p31.pRight = NULL;
	BTreeNode p41;
	p41.m_value = 7;
	p41.pLeft = NULL;
	p41.pRight = NULL;
	BTreeNode p11;
	p11.m_value = 5;
	p11.pLeft = &p31;
	p11.pRight = &p41;
	BTreeNode p21;
	p21.m_value = 12;
	p21.pLeft = NULL;
	p21.pRight = NULL;
	BTreeNode proot1;
	proot1.m_value = 10;
	proot1.pLeft = &p11;
	proot1.pRight = &p21;

	FindPathBySum(&proot1, 22);
	}
