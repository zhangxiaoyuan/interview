
bool BinaryTreeWide(BTreeNode* pTree1, BTreeNode* pTree2)
{
	if (pTree2 == NULL)
	{
		return true;
	}

	if (pTree1 == NULL)
	{
		return false;
	}
	if (pTree1->m_value != pTree2->m_value)
	{
		return false;
	}

	return BinaryTreeWide(pTree1->pLeft, pTree2->pLeft) && BinaryTreeWide(pTree1->pRight, pTree2->pRight);
}

bool isSubBinaryTree(BTreeNode* pTree1, BTreeNode* pTree2)
{
	if (pTree1 == NULL || pTree2 == NULL)
	{
		return false;
	}
	bool result = false;
	if (pTree1->m_value == pTree2->m_value)
	{
		result = BinaryTreeWide(pTree1, pTree2);
	}
	if(!result)
	{
		result = isSubBinaryTree(pTree1->pLeft, pTree2);
	}
	if (!result)
	{
		result = isSubBinaryTree(pTree1->pRight, pTree2);
	}

	return result;
}

	 

void main()
{

	BTreeNode p4;
	p4.m_value = 5;
	p4.pLeft = NULL;
	p4.pRight = NULL;
	BTreeNode p5;
	p5.m_value = 6;
	p5.pLeft = NULL;
	p5.pRight = NULL;
	BTreeNode p6;
	p6.m_value = 7;
	p6.pLeft = NULL;
	p6.pRight = NULL;
	BTreeNode p3;
	p3.m_value = 4;
	p3.pLeft = &p6;
	p3.pRight = NULL;
	BTreeNode p1;
	p1.m_value = 2;
	p1.pLeft = &p3;
	p1.pRight = &p4;
	BTreeNode p2;
	p2.m_value = 3;
	p2.pLeft = &p5;
	p2.pRight = NULL;
	BTreeNode proot;
	proot.m_value = 1;
	proot.pLeft = &p1;
	proot.pRight = &p2;

	BTreeNode p31;
	p31.m_value = 7;
	p31.pLeft = NULL;
	p31.pRight = NULL;
	BTreeNode p11;
	p11.m_value = 7;
	p11.pLeft = &p31;
	p11.pRight = NULL;
	BTreeNode p21;
	p21.m_value = 5;
	p21.pLeft = NULL;
	p21.pRight = NULL;
	BTreeNode proot1;
	proot1.m_value = 2;
	proot1.pLeft = &p11;
	proot1.pRight = &p21;

	bool re = isSubBinaryTree(&proot, &proot1);
	cout << re << endl;
}
