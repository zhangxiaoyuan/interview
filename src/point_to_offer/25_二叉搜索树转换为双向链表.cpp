

/*给定一个二叉搜索树，转换成一个递增排序的双向链表*/

void ConvertNode(BTreeNode* pNode ,BTreeNode** pLastNode)
{
	if (pNode == NULL)
	{
		return;
	}

	BTreeNode* pCurrent = pNode;
	if (pCurrent->pLeft != NULL)
	{
		ConvertNode(pCurrent->pLeft, pLastNode);
	}

	pCurrent->pLeft = *pLastNode;
	if (*pLastNode != NULL)
	{
		(*pLastNode)->pRight = pCurrent;
	}

	*pLastNode = pCurrent;
	if (pCurrent->pRight != NULL)
	{
		ConvertNode(pCurrent->pRight, pLastNode);
	}
}

BTreeNode* Convert(BTreeNode* pHead)
{
	BTreeNode* pLastNode = NULL;

	ConvertNode(pHead, &pLastNode);
	
	BTreeNode* pHeadNode = pLastNode;
	while(pHeadNode != NULL && pHeadNode->pLeft != NULL)
	{
		pHeadNode = pLastNode->pLeft;
	}

	return pHeadNode;
}

void main()
{
  BTreeNode p4;
	p4.m_value = 8;
	p4.pLeft = NULL;
	p4.pRight = NULL;
	BTreeNode p7;
	p7.m_value = 16;
	p7.pLeft = NULL;
	p7.pRight = NULL;
	BTreeNode p5;
	p5.m_value = 12;
	p5.pLeft = NULL;
	p5.pRight = NULL;
	BTreeNode p6;
	p6.m_value = 7;
	p6.pLeft = NULL;
	p6.pRight = NULL;
	BTreeNode p3;
	p3.m_value = 4;
	p3.pLeft = NULL;
	p3.pRight = NULL;
	BTreeNode p1;
	p1.m_value = 6;
	p1.pLeft = &p3;
	p1.pRight = &p4;
	BTreeNode p2;
	p2.m_value = 14;
	p2.pLeft = &p5;
	p2.pRight = &p7;
	BTreeNode proot;
	proot.m_value = 10;
	proot.pLeft = &p1;
	proot.pRight = &p2;

	BTreeNode* ptem = Convert(&proot);
}
